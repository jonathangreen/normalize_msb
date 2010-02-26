#include <vcl.h>
#pragma hdrstop

#include <tchar.h>
#include <assert.h>

#include <list>

#include "MSXML2_TLB.h"

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
   WriteConsole(handle, out.c_str(), out.Length(), 0, 0);
}

int compareNodes(IXMLDOMNodePtr node1, IXMLDOMNodePtr node2) {
   String name1 = node1->attributes->getNamedItem(L"Include")->text;
   int order1 = StrToInt(node1->selectSingleNode(L"BuildOrder")->text);
   String name2 = node2->attributes->getNamedItem(L"Include")->text;
   int order2 = StrToInt(node2->selectSingleNode(L"BuildOrder")->text);

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

static COMHelper comHelper;

int _tmain(int argc, _TCHAR* argv[]) {
   if (argc == 1) {
      WriteLn(String("Usage: ") + ExtractFileName(Application->ExeName) + " FILENAME");
      return 1;
   }

#if 0
   TStringList * files = new TStringList();
   gatherFiles(*files, argv[1]);
   normalizeFiles(*files);
   delete files;
#else
   normalizeFile(argv[1]);
#endif

   return 0;
}
