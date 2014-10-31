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

#include <string>
#include <iostream>
#include <vector>

#include <shlwapi.h>
#undef StrToInt

#include "MSXML2_TLB.h"
#include "getopt.h"
#include "version.h"

// ---------------------------------------------------------------------------

#pragma argsused

static bool verbose;

class ConsoleHelper
{
public:
   ConsoleHelper()
   {
      AllocConsole();
   }

   ~ConsoleHelper()
   {
      FreeConsole();
   }
};

class COMHelper
{
public:
   COMHelper()
   {
      CoInitialize (0);
   }

   ~COMHelper()
   {
      CoUninitialize();
   }
};

HANDLE allocHandle()
{
   static ConsoleHelper helper;
   return GetStdHandle (STD_OUTPUT_HANDLE);
}

void WriteLn (const String & s)
{
   static HANDLE handle = allocHandle();
   String out = s + "\n";
   WriteConsoleW(handle, out.c_str(), out.Length(), 0, 0);
}

BSTR getAttribute (IXMLDOMNodePtr node, BSTR attrName)
{
   return node->attributes->getNamedItem (attrName)->text;
}

BSTR getNodeText (IXMLDOMNodePtr node, BSTR nodeName)
{
   IXMLDOMNodePtr s = node->selectSingleNode(nodeName);
   return s ? s->text : 0;
}

int getNodeInt (IXMLDOMNodePtr node, BSTR nodeName, int default_value = -1) 
{
	IXMLDOMNodePtr s = node->selectSingleNode(nodeName);
   return s ? StrToInt(s->text) : default_value;
}

int compareNodes (IXMLDOMNodePtr node1, IXMLDOMNodePtr node2)
{
   String name1 = getAttribute (node1, L"Include");
   int order1 = getNodeInt(node1, L"BuildOrder");
   String name2 = getAttribute (node2, L"Include");
   int order2 = getNodeInt(node2, L"BuildOrder");

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

void bubbleSortNodes (IXMLDOMNodePtr * nodes, int len)
{
   assert (nodes);

   bool swapped;
   do
   {
      swapped = false;
      for (int i = 0; i < len - 1; i++)
      {
         IXMLDOMNodePtr node1 = nodes[i];
         IXMLDOMNodePtr node2 = nodes[i + 1];
         if (compareNodes (node1, node2) > 0)
         {
            nodes[i] = node2;
            nodes[i + 1] = node1;
            swapped = true;
         }
      }
      len--;
   }
   while (swapped && len);
}

String makeRelativePath (String path)
{
   wchar_t buffer[MAX_PATH] = 
   {
      0
   };
   if (PathRelativePathToW(buffer, GetCurrentDir().c_str(), FILE_ATTRIBUTE_DIRECTORY, path.c_str(), 0))
      return String (buffer);
   else
      return path;
}

IXMLDOMNodePtr * newNodesArray (IXMLDOMNodeListPtr src, int & len)
{
   assert (src);
   len = src->length;

   assert (len);
   IXMLDOMNodePtr * result = new IXMLDOMNodePtr[len];
   for (int i = 0; i < len; i++)
      result[i] = src->get_item (i);
   return result;
}

void rewriteNodes (IXMLDOMNodePtr parent, IXMLDOMNodePtr * nodes, int len)
{
   for (int i = 0; i < len; i++)
   {
      parent->removeChild (nodes[i]);
      parent->appendChild (nodes[i]);
   }
}

void normalizeItemGroup (IXMLDOMDocument2Ptr doc)
{
   IXMLDOMNodePtr itemGroup = doc->selectSingleNode (L"/Project/ItemGroup");
   IXMLDOMNodeListPtr items = itemGroup->selectNodes (L"*[@Include]");
   if (items && items->length)
   {
      int len;
      IXMLDOMNodePtr * nodes = newNodesArray (items, len);
      bubbleSortNodes (nodes, len);
      rewriteNodes (itemGroup, nodes, len);
      delete[]nodes;
   }
}

void fail (const String & error, int code = 1)
{
   WriteLn (error);
   exit (code);
}

void normalizeDoc (IXMLDOMDocument2Ptr doc)
{
   if (doc->parseError->errorCode)
   {
      fail (String ("Parse error: ") + doc->parseError->get_reason());
   }
   normalizeItemGroup (doc);
}

void normalizeFile (String fileName)
{
   IXMLDOMDocument2Ptr doc = CreateOleObject ("MSXML2.DOMDocument.3.0");
   doc->load (Variant (fileName));
   normalizeDoc(doc);
   doc->save (Variant (fileName));
}

void normalizeFiles (TStringList & files)
{
   if (files.Count == 0)
   {
      fail ("No files found", 2);
   }

   for (int i = 0; i < files.Count; i++)
   {
      String file = files[i];
      WriteLn (makeRelativePath (file));
      normalizeFile (files[i]);
   }
}

void normalizeStdin (void)
{
   std::istreambuf_iterator<wchar_t> eos;
   std::istreambuf_iterator<wchar_t> iit (std::wcin);

   std::vector<wchar_t> input(iit, eos);
   input.push_back('\0');

   if (verbose)
   {
      WriteLn("Input Received:");
      WriteLn(&input[0]);
   }

   // check for and remove UTF-8 BOM
   if (input.size() > 3 && input[0] == 0xEF && input[1] == 0xBB && input[2] == 0xBF)
      input.erase(input.begin(), input.begin()+3);

   IXMLDOMDocument2Ptr doc = CreateOleObject ("MSXML2.DOMDocument.3.0");
   doc->loadXML(&input[0]);
   normalizeDoc(doc);
   std::wcout << doc->xml;
}

std::unique_ptr<TStringList>filesFromCommandLine (new TStringList);

void addFiles (int argc, _TCHAR * argv[], int startIdx)
{
   for (int i = startIdx; i < argc; i++)
   {
      String file = argv[i];
      filesFromCommandLine->Add (file);
   }
}

void findFilesInFolder (const String & folder, const String & mask, TStringList & list)
{
   int attr = faAnyFile;
   TSearchRec sr;
   memset (&sr, 0, sizeof (sr));
   String dir = IncludeTrailingBackslash (folder);
   if (FindFirst (dir + mask, attr, sr) == 0)
   {
      do
      {
         if ( (sr.Attr & attr) == sr.Attr)
         {
            list.Add (dir + sr.Name);
         }
      }
      while (FindNext (sr) == 0);
      FindClose (sr);
   }
}

void findFilesRecursively (const String & rootFolder, const String & mask, TStringList & list)
{
   String baseFolder = IncludeTrailingBackslash (rootFolder);
   findFilesInFolder (baseFolder, mask, list);

   int attr = faDirectory | faReadOnly;
   TSearchRec sr;
   memset (&sr, 0, sizeof (sr));
   if (FindFirst (baseFolder + "*", attr, sr) == 0)
   {
      do
      {
         if ( (sr.Attr & attr) == sr.Attr)
         {
            String subFolder = sr.Name;
            if (subFolder != "." && subFolder != "..")
               findFilesRecursively (baseFolder + subFolder, mask, list);
         }
      }
      while (FindNext (sr) == 0);
      FindClose (sr);
   }
}

void findFiles (const String & folder, const String & mask, TStringList & list, bool recurse)
{
   if (recurse)
   {
      findFilesRecursively (folder, mask, list);
   }
   else
   {
      findFilesInFolder (folder, mask, list);
   }
}

void gatherFiles (TStringList & files, bool recurse)
{
   for (int i = 0; i < filesFromCommandLine->Count; i++)
   {
      String path = (*filesFromCommandLine) [i];
      String folder = ExtractFilePath (path);
      if (folder.Length() == 0)
         folder = GetCurrentDir();
      String file = ExtractFileName (path);
      if (verbose)
      {
         if (recurse)
            WriteLn ("Searching recursively for files matching " + file + " starting in directory " + folder);
         else
            WriteLn ("Searching for files matching " + file + " in directory " + folder);
      }
      findFiles (folder, file, files, recurse);
   }
}

const struct option LONG_OPTIONS[] = { {
      "version", no_argument, 0, 'v'
   }, {
      "recursive", no_argument, 0, 'r'
   }, {
      "help", no_argument, 0, 'h'
   }, {
      "filter", no_argument, 0, 'f'
   }, {
      "verbose", no_argument, 0, 'V'
   }, {
      0, 0, 0, 0
   }
};

const char * SHORT_OPTIONS = "rhvfV";

bool recurse = false;

bool filter = false;

String getProgName()
{
   return ChangeFileExt (ExtractFileName (Application->ExeName), "");
}

void showUsage()
{
   WriteLn ("Usage: " + getProgName() + " [OPTIONS] FILES");
   WriteLn ("Valid options:");
   WriteLn ("  -h, --help                  Show this information and exit");
   WriteLn ("  -r, --recursive             Recurse into subdirectories");
   WriteLn ("  -f, --filter                Read input from stdin and write to stdout");
   WriteLn ("  -v, --version               Show version information and exit");
   WriteLn ("  -V, --verbose               Show more output during processing");
}

void showVersion()
{
   WriteLn (getProgName() + " version " + VERSION);
   exit (0);
}

void processOptions (int argc, _TCHAR * argv[])
{
   int idx = 0;
   int c = 0;
   while (c >= 0)
   {
      c = getopt_long (argc, argv, SHORT_OPTIONS, LONG_OPTIONS, &idx);
      switch (c)
      {
         case -1:
            if (!filter)
               addFiles (argc, argv, optind);
            break;
         case 'f':
            filter = true;
            break;
         case 'r':
            recurse = true;
            break;
         case 'h':
            showUsage();
            exit (0);
         case 'v':
            showVersion();
            exit (0);
         case 'V':
            verbose = true;
            break;
      }
   }
}

static COMHelper comHelper;

int _tmain (int argc, _TCHAR * argv[])
{
   processOptions (argc, argv);

   if(filter && recurse)
      fail("Cannot specify both recursive and filter.");

   if(!filter)
   {
	  std::unique_ptr<TStringList>filesToNormalize (new TStringList);
	  gatherFiles (*filesToNormalize, recurse);
	  normalizeFiles (*filesToNormalize);
   }
   else
   {
      normalizeStdin();
   }

   return 0;
}
