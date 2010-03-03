/*
 * (c) Copyright 2010 Christian Gudrian
 *
 * This file is part of normalize_msb.
 *
 * normalize_msb is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * normalize_msb is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 */
#include <vcl.h>
#pragma hdrstop

#include <tchar.h>
#include <assert.h>

#include <list>
#include <memory>

#include "MSXML2_TLB.h"
#include "getopt.h"
#include "version.h"

// ---------------------------------------------------------------------------

#pragma argsused

class ConsoleHelper {
public:
   ConsoleHelper() {
      AllocConsole();
   }

   ~ConsoleHelper() {
      FreeConsole();
   }
};

class COMHelper {
public:
   COMHelper() {
      CoInitialize(0);
   }

   ~COMHelper() {
      CoUninitialize();
   }
};

HANDLE allocHandle() {
   static ConsoleHelper helper;
   return GetStdHandle(STD_OUTPUT_HANDLE);
}

void WriteLn(const String & s) {
   static HANDLE handle = allocHandle();
   String out = s + "\n";
   WriteConsole(handle, out.t_str(), out.Length(), 0, 0);
}

BSTR getAttribute(IXMLDOMNodePtr node, BSTR attrName) {
   return node->attributes->getNamedItem(attrName)->text;
}

BSTR getNodeText(IXMLDOMNodePtr node, BSTR nodeName) {
   return node->selectSingleNode(nodeName)->text;
}

int compareNodes(IXMLDOMNodePtr node1, IXMLDOMNodePtr node2) {
   String name1 = getAttribute(node1, L"Include");
   int order1 = StrToInt(getNodeText(node1, L"BuildOrder"));
   String name2 = getAttribute(node2, L"Include");
   int order2 = StrToInt(getNodeText(node2, L"BuildOrder"));

   if (order1 > order2)
      return 1;
   if (order1 < order2)
      return -1;
   if (name1 > name2)
      return 1;
   if (name1 < name2)
      return -1;

   return 0;
}

void bubbleSortNodes(IXMLDOMNodePtr * nodes, int len) {
   assert(nodes);

   bool swapped;
   do {
      swapped = false;
      for (int i = 0; i < len - 1; i++) {
         IXMLDOMNodePtr node1 = nodes[i];
         IXMLDOMNodePtr node2 = nodes[i + 1];
         if (compareNodes(node1, node2) > 0) {
            nodes[i] = node2;
            nodes[i + 1] = node1;
            swapped = true;
         }
      }
      len--;
   }
   while (swapped && len);
}

IXMLDOMNodePtr * newNodesArray(IXMLDOMNodeListPtr src, int & len) {
   assert(src);
   len = src->length;

   assert(len);
   IXMLDOMNodePtr * result = new IXMLDOMNodePtr[len];
   for (int i = 0; i < len; i++)
      result[i] = src->get_item(i);
   return result;
}

void rewriteNodes(IXMLDOMNodePtr parent, IXMLDOMNodePtr * nodes, int len) {
   for (int i = 0; i < len; i++) {
      parent->removeChild(nodes[i]);
      parent->appendChild(nodes[i]);
   }
}

void normalizeItemGroup(IXMLDOMDocument2Ptr doc) {
   IXMLDOMNodePtr itemGroup = doc->selectSingleNode(L"/Project/ItemGroup");
   IXMLDOMNodeListPtr items = itemGroup->selectNodes(L"*[BuildOrder and @Include]");
   if (items && items->length) {
      int len;
      IXMLDOMNodePtr * nodes = newNodesArray(items, len);
      bubbleSortNodes(nodes, len);
      rewriteNodes(itemGroup, nodes, len);
      delete[]nodes;
   }
}

void fail(const String & error, int code = 1) {
   WriteLn(error);
   exit(code);
}

void normalizeFile(String fileName) {
   IXMLDOMDocument2Ptr doc = CreateOleObject("MSXML2.DOMDocument.3.0");
   doc->load(Variant(fileName));
   if (doc->parseError->errorCode) {
      fail(String("Parse error: ") + doc->parseError->get_reason());
   }
   normalizeItemGroup(doc);
   doc->save(Variant(fileName));
}

void normalizeFiles(TStringList & files) {
   if (files.Count == 0) {
      fail("No files found", 2);
   }

   for (int i = 0; i < files.Count; i++) {
      String file = files[i];
      WriteLn(file);
      normalizeFile(files[i]);
   }
}

std::auto_ptr<TStringList>filesFromCommandLine(new TStringList());

void addFiles(int argc, _TCHAR * argv[], int startIdx) {
   for (int i = startIdx; i < argc; i++) {
      String file = argv[i];
      filesFromCommandLine->Add(file);
   }
}

void findFilesInFolder(const String & folder, const String & mask, TStringList & list) {
   int attr = faAnyFile;
   TSearchRec sr;
   memset(&sr, 0, sizeof(sr));
   String dir = IncludeTrailingBackslash(folder);
   if (FindFirst(dir + mask, attr, sr) == 0) {
      do {
         if ((sr.Attr & attr) == sr.Attr) {
            list.Add(dir + sr.Name);
         }
      }
      while (FindNext(sr) == 0);
      FindClose(sr);
   }
}

void findFilesRecursively(const String & rootFolder, const String & mask, TStringList & list) {
   String baseFolder = IncludeTrailingBackslash(rootFolder);
   findFilesInFolder(baseFolder, mask, list);

   int attr = faDirectory | faReadOnly;
   TSearchRec sr;
   memset(&sr, 0, sizeof(sr));
   if (FindFirst(baseFolder + "*", attr, sr) == 0) {
      do {
         if ((sr.Attr & attr) == sr.Attr) {
            String subFolder = sr.Name;
            if (subFolder != "." && subFolder != "..")
               findFilesRecursively(baseFolder + subFolder, mask, list);
         }
      }
      while (FindNext(sr) == 0);
      FindClose(sr);
   }
}

void findFiles(const String & folder, const String & mask, TStringList & list, bool recurse) {
   if (recurse) {
      findFilesRecursively(folder, mask, list);
   } else {
      findFilesInFolder(folder, mask, list);
   }
}

void gatherFiles(TStringList & files, bool recurse) {
   for (int i = 0; i < filesFromCommandLine->Count; i++) {
      String path = (*filesFromCommandLine)[i];
      String folder = ExtractFilePath(path);
      if (folder.Length() == 0)
         folder = GetCurrentDir();
      String file = ExtractFileName(path);
      findFiles(folder, file, files, recurse);
   }
}

const struct option LONG_OPTIONS[] = { {
      "version", no_argument, 0, 'v'
   }, {
      "recursive", no_argument, 0, 'r'
   }, {
      "help", no_argument, 0, 'h'
   }, {
      0, 0, 0, 0
   }
};

const char * SHORT_OPTIONS = "rhv";

bool recurse = false;

String getProgName() {
   return ChangeFileExt(ExtractFileName(Application->ExeName), "");
}

void showUsage() {
   WriteLn("Usage: " + getProgName() + " [OPTIONS] FILES");
   WriteLn("Valid options:");
   WriteLn("  -h, --help                  Show this information and exit");
   WriteLn("  -r, --recursive             Recurse into subdirectories");
   WriteLn("  -v, --version               Show version information and exit");
}

void showVersion() {
   WriteLn(getProgName() + " version " + VERSION);
   exit(0);
}

void processOptions(int argc, _TCHAR * argv[]) {
   int idx = 0;
   int c = 0;
   while (c >= 0) {
      c = getopt_long(argc, argv, SHORT_OPTIONS, LONG_OPTIONS, &idx);
      switch(c) {
      case -1
         : addFiles(argc, argv, optind);
         break;
      case 'r':
         recurse = true;
         break;
      case 'h':
         showUsage();
         exit(0);
      case 'v':
         showVersion();
         exit(0);
      }
   }
}

static COMHelper comHelper;

int _tmain(int argc, _TCHAR* argv[]) {

   processOptions(argc, argv);

   std::auto_ptr<TStringList>filesToNormalize(new TStringList());
   gatherFiles(*filesToNormalize, recurse);
   normalizeFiles(*filesToNormalize);

   return 0;
}
