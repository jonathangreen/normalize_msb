/*
 * This program sorts all items within an ItemGroup of an MSBuild file
 * first by its BuildOrder and then by its file name.  It has primarily been
 * developed to simplify version control of Embarcadero RAD Studio project
 * files.  With every save of the project file RAD Studio permutes the order
 * of the items randomly leading to unnecessary conflicts in case of a merge.
 *
 * This source code comes without any warranty.  Use at your own risk.
 *
 * Questions and comments to: christian.gudrian@gmx.de
 */
#include <vcl.h>
#pragma hdrstop

#include <tchar.h>
#include <assert.h>

#include <list>
#include <memory>

#include "MSXML2_TLB.h"
#include "getopt.h"

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

void fail(const String & error) {
   WriteLn(error);
   exit(1);
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
   for (int i = 0; i < files.Count; i++)
      normalizeFile(files[i]);
}

void addFiles(int argc, _TCHAR * argv[], int startIdx) {
   for (int i = startIdx; i < argc; i++) {
      String file = argv[i];
   }
}

const struct option LONG_OPTIONS[] = { {
      "recursive", no_argument, 0, 'r'
   }, {
      "help", no_argument, 0, 'h'
   }, {
      0, 0, 0, 0
   }
};
const char * SHORT_OPTIONS = "rh";

bool recurse = false;

void showUsage() {
   String progName = ChangeFileExt(ExtractFileName(Application->ExeName), "");
   WriteLn("Usage: " + progName + " [OPTIONS] FILES");
   WriteLn("Valid options:");
   WriteLn("  -h, --help                  Show this information");
   WriteLn("  -r, --recursive             Recurse into subdirectories");
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
      }
   }
}

static COMHelper comHelper;

int _tmain(int argc, _TCHAR* argv[]) {

   processOptions(argc, argv);

   std::auto_ptr<TStringList>sl(new TStringList());
   normalizeFiles(*sl);

   return 0;
}
