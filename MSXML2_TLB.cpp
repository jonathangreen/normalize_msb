/*
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

// ************************************************************************ //
// WARNING                                                                    
// -------                                                                    
// The types declared in this file were generated from data read from a       
// Type Library. If this type library is explicitly or indirectly (via        
// another type library referring to this type library) re-imported, or the   
// 'Refresh' command of the Type Library Editor activated while editing the   
// Type Library, the contents of this file will be regenerated and all        
// manual modifications will be lost.                                         
// ************************************************************************ //

// $Rev: 18756 $
// File generated on 25.02.2010 15:50:12 from Type Library described below.

// ************************************************************************  //
// Type Lib: C:\Windows\System32\msxml6.dll (1)
// LIBID: {F5078F18-C551-11D3-89B9-0000F81FE221}
// LCID: 0
// Helpfile: 
// HelpString: Microsoft XML, v6.0
// DepndLst: 
//   (1) v2.0 stdole, (C:\Windows\system32\stdole2.tlb)
// Errors:
//   Hint: Symbol 'DOMDocument' renamed to 'msDOMDocument'
//   Hint: Symbol 'DOMDocument26' renamed to 'msDOMDocument26'
//   Hint: Symbol 'DOMDocument30' renamed to 'msDOMDocument30'
//   Hint: Symbol 'FreeThreadedDOMDocument' renamed to 'msFreeThreadedDOMDocument'
//   Hint: Symbol 'FreeThreadedDOMDocument26' renamed to 'msFreeThreadedDOMDocument26'
//   Hint: Symbol 'FreeThreadedDOMDocument30' renamed to 'msFreeThreadedDOMDocument30'
//   Hint: Symbol 'XMLSchemaCache' renamed to 'msXMLSchemaCache'
//   Hint: Symbol 'XMLSchemaCache26' renamed to 'msXMLSchemaCache26'
//   Hint: Symbol 'XMLSchemaCache30' renamed to 'msXMLSchemaCache30'
//   Hint: Symbol 'XSLTemplate' renamed to 'msXSLTemplate'
//   Hint: Symbol 'XSLTemplate26' renamed to 'msXSLTemplate26'
//   Hint: Symbol 'XSLTemplate30' renamed to 'msXSLTemplate30'
//   Hint: Symbol 'DSOControl' renamed to 'msDSOControl'
//   Hint: Symbol 'DSOControl26' renamed to 'msDSOControl26'
//   Hint: Symbol 'DSOControl30' renamed to 'msDSOControl30'
//   Hint: Symbol 'XMLHTTP' renamed to 'msXMLHTTP'
//   Hint: Symbol 'XMLHTTP26' renamed to 'msXMLHTTP26'
//   Hint: Symbol 'XMLHTTP30' renamed to 'msXMLHTTP30'
//   Hint: Symbol 'ServerXMLHTTP' renamed to 'msServerXMLHTTP'
//   Hint: Symbol 'ServerXMLHTTP30' renamed to 'msServerXMLHTTP30'
//   Hint: Symbol 'SAXXMLReader' renamed to 'msSAXXMLReader'
//   Hint: Symbol 'SAXXMLReader30' renamed to 'msSAXXMLReader30'
//   Hint: Symbol 'MXXMLWriter' renamed to 'msMXXMLWriter'
//   Hint: Symbol 'MXXMLWriter30' renamed to 'msMXXMLWriter30'
//   Hint: Symbol 'SAXAttributes' renamed to 'msSAXAttributes'
//   Hint: Symbol 'SAXAttributes30' renamed to 'msSAXAttributes30'
// ************************************************************************ //

#include <vcl.h>
#pragma hdrstop

#include "MSXML2_TLB.h"

#if !defined(__PRAGMA_PACKAGE_SMART_INIT)
#define      __PRAGMA_PACKAGE_SMART_INIT
#pragma package(smart_init)
#endif

namespace Msxml2_tlb
{


// *********************************************************************//
// GUIDS declared in the TypeLibrary                                      
// *********************************************************************//
const GUID LIBID_MSXML2 = {0xF5078F18, 0xC551, 0x11D3,{ 0x89, 0xB9, 0x00,0x00, 0xF8, 0x1F,0xE2, 0x21} };
const GUID IID_IXMLDOMImplementation = {0x2933BF8F, 0x7B36, 0x11D2,{ 0xB2, 0x0E, 0x00,0xC0, 0x4F, 0x98,0x3E, 0x60} };
const GUID IID_IXMLDOMNode = {0x2933BF80, 0x7B36, 0x11D2,{ 0xB2, 0x0E, 0x00,0xC0, 0x4F, 0x98,0x3E, 0x60} };
const GUID IID_IXMLDOMNodeList = {0x2933BF82, 0x7B36, 0x11D2,{ 0xB2, 0x0E, 0x00,0xC0, 0x4F, 0x98,0x3E, 0x60} };
const GUID IID_IXMLDOMNamedNodeMap = {0x2933BF83, 0x7B36, 0x11D2,{ 0xB2, 0x0E, 0x00,0xC0, 0x4F, 0x98,0x3E, 0x60} };
const GUID IID_IXMLDOMDocument = {0x2933BF81, 0x7B36, 0x11D2,{ 0xB2, 0x0E, 0x00,0xC0, 0x4F, 0x98,0x3E, 0x60} };
const GUID IID_IXMLDOMDocumentType = {0x2933BF8B, 0x7B36, 0x11D2,{ 0xB2, 0x0E, 0x00,0xC0, 0x4F, 0x98,0x3E, 0x60} };
const GUID IID_IXMLDOMElement = {0x2933BF86, 0x7B36, 0x11D2,{ 0xB2, 0x0E, 0x00,0xC0, 0x4F, 0x98,0x3E, 0x60} };
const GUID IID_IXMLDOMAttribute = {0x2933BF85, 0x7B36, 0x11D2,{ 0xB2, 0x0E, 0x00,0xC0, 0x4F, 0x98,0x3E, 0x60} };
const GUID IID_IXMLDOMDocumentFragment = {0x3EFAA413, 0x272F, 0x11D2,{ 0x83, 0x6F, 0x00,0x00, 0xF8, 0x7A,0x77, 0x82} };
const GUID IID_IXMLDOMText = {0x2933BF87, 0x7B36, 0x11D2,{ 0xB2, 0x0E, 0x00,0xC0, 0x4F, 0x98,0x3E, 0x60} };
const GUID IID_IXMLDOMCharacterData = {0x2933BF84, 0x7B36, 0x11D2,{ 0xB2, 0x0E, 0x00,0xC0, 0x4F, 0x98,0x3E, 0x60} };
const GUID IID_IXMLDOMComment = {0x2933BF88, 0x7B36, 0x11D2,{ 0xB2, 0x0E, 0x00,0xC0, 0x4F, 0x98,0x3E, 0x60} };
const GUID IID_IXMLDOMCDATASection = {0x2933BF8A, 0x7B36, 0x11D2,{ 0xB2, 0x0E, 0x00,0xC0, 0x4F, 0x98,0x3E, 0x60} };
const GUID IID_IXMLDOMProcessingInstruction = {0x2933BF89, 0x7B36, 0x11D2,{ 0xB2, 0x0E, 0x00,0xC0, 0x4F, 0x98,0x3E, 0x60} };
const GUID IID_IXMLDOMEntityReference = {0x2933BF8E, 0x7B36, 0x11D2,{ 0xB2, 0x0E, 0x00,0xC0, 0x4F, 0x98,0x3E, 0x60} };
const GUID IID_IXMLDOMParseError = {0x3EFAA426, 0x272F, 0x11D2,{ 0x83, 0x6F, 0x00,0x00, 0xF8, 0x7A,0x77, 0x82} };
const GUID IID_IXMLDOMDocument2 = {0x2933BF95, 0x7B36, 0x11D2,{ 0xB2, 0x0E, 0x00,0xC0, 0x4F, 0x98,0x3E, 0x60} };
const GUID IID_IXMLDOMSchemaCollection = {0x373984C8, 0xB845, 0x449B,{ 0x91, 0xE7, 0x45,0xAC, 0x83, 0x03,0x6A, 0xDE} };
const GUID IID_IXMLDOMDocument3 = {0x2933BF96, 0x7B36, 0x11D2,{ 0xB2, 0x0E, 0x00,0xC0, 0x4F, 0x98,0x3E, 0x60} };
const GUID IID_IXMLDOMNotation = {0x2933BF8C, 0x7B36, 0x11D2,{ 0xB2, 0x0E, 0x00,0xC0, 0x4F, 0x98,0x3E, 0x60} };
const GUID IID_IXMLDOMEntity = {0x2933BF8D, 0x7B36, 0x11D2,{ 0xB2, 0x0E, 0x00,0xC0, 0x4F, 0x98,0x3E, 0x60} };
const GUID IID_IXMLDOMParseError2 = {0x3EFAA428, 0x272F, 0x11D2,{ 0x83, 0x6F, 0x00,0x00, 0xF8, 0x7A,0x77, 0x82} };
const GUID IID_IXMLDOMParseErrorCollection = {0x3EFAA429, 0x272F, 0x11D2,{ 0x83, 0x6F, 0x00,0x00, 0xF8, 0x7A,0x77, 0x82} };
const GUID IID_IXTLRuntime = {0x3EFAA425, 0x272F, 0x11D2,{ 0x83, 0x6F, 0x00,0x00, 0xF8, 0x7A,0x77, 0x82} };
const GUID IID_IXSLTemplate = {0x2933BF93, 0x7B36, 0x11D2,{ 0xB2, 0x0E, 0x00,0xC0, 0x4F, 0x98,0x3E, 0x60} };
const GUID IID_IXSLProcessor = {0x2933BF92, 0x7B36, 0x11D2,{ 0xB2, 0x0E, 0x00,0xC0, 0x4F, 0x98,0x3E, 0x60} };
const GUID IID_ISAXXMLReader = {0xA4F96ED0, 0xF829, 0x476E,{ 0x81, 0xC0, 0xCD,0xC7, 0xBD, 0x2A,0x08, 0x02} };
const GUID IID_ISAXEntityResolver = {0x99BCA7BD, 0xE8C4, 0x4D5F,{ 0xA0, 0xCF, 0x6D,0x90, 0x79, 0x01,0xFF, 0x07} };
const GUID IID_ISAXContentHandler = {0x1545CDFA, 0x9E4E, 0x4497,{ 0xA8, 0xA4, 0x2B,0xF7, 0xD0, 0x11,0x2C, 0x44} };
const GUID IID_ISAXLocator = {0x9B7E472A, 0x0DE4, 0x4640,{ 0xBF, 0xF3, 0x84,0xD3, 0x8A, 0x05,0x1C, 0x31} };
const GUID IID_ISAXAttributes = {0xF078ABE1, 0x45D2, 0x4832,{ 0x91, 0xEA, 0x44,0x66, 0xCE, 0x2F,0x25, 0xC9} };
const GUID IID_ISAXDTDHandler = {0xE15C1BAF, 0xAFB3, 0x4D60,{ 0x8C, 0x36, 0x19,0xA8, 0xC4, 0x5D,0xEF, 0xED} };
const GUID IID_ISAXErrorHandler = {0xA60511C4, 0xCCF5, 0x479E,{ 0x98, 0xA3, 0xDC,0x8D, 0xC5, 0x45,0xB7, 0xD0} };
const GUID IID_ISAXXMLFilter = {0x70409222, 0xCA09, 0x4475,{ 0xAC, 0xB8, 0x40,0x31, 0x2F, 0xE8,0xD1, 0x45} };
const GUID IID_ISAXLexicalHandler = {0x7F85D5F5, 0x47A8, 0x4497,{ 0xBD, 0xA5, 0x84,0xBA, 0x04, 0x81,0x9E, 0xA6} };
const GUID IID_ISAXDeclHandler = {0x862629AC, 0x771A, 0x47B2,{ 0x83, 0x37, 0x4E,0x68, 0x43, 0xC1,0xBE, 0x90} };
const GUID IID_IVBSAXXMLReader = {0x8C033CAA, 0x6CD6, 0x4F73,{ 0xB7, 0x28, 0x45,0x31, 0xAF, 0x74,0x94, 0x5F} };
const GUID IID_IVBSAXEntityResolver = {0x0C05D096, 0xF45B, 0x4ACA,{ 0xAD, 0x1A, 0xAA,0x0B, 0xC2, 0x55,0x18, 0xDC} };
const GUID IID_IVBSAXContentHandler = {0x2ED7290A, 0x4DD5, 0x4B46,{ 0xBB, 0x26, 0x4E,0x41, 0x55, 0xE7,0x7F, 0xAA} };
const GUID IID_IVBSAXLocator = {0x796E7AC5, 0x5AA2, 0x4EFF,{ 0xAC, 0xAD, 0x3F,0xAA, 0xF0, 0x1A,0x32, 0x88} };
const GUID IID_IVBSAXAttributes = {0x10DC0586, 0x132B, 0x4CAC,{ 0x8B, 0xB3, 0xDB,0x00, 0xAC, 0x8B,0x7E, 0xE0} };
const GUID IID_IVBSAXDTDHandler = {0x24FB3297, 0x302D, 0x4620,{ 0xBA, 0x39, 0x3A,0x73, 0x2D, 0x85,0x05, 0x58} };
const GUID IID_IVBSAXErrorHandler = {0xD963D3FE, 0x173C, 0x4862,{ 0x90, 0x95, 0xB9,0x2F, 0x66, 0x99,0x5F, 0x52} };
const GUID IID_IVBSAXXMLFilter = {0x1299EB1B, 0x5B88, 0x433E,{ 0x82, 0xDE, 0x82,0xCA, 0x75, 0xAD,0x4E, 0x04} };
const GUID IID_IVBSAXLexicalHandler = {0x032AAC35, 0x8C0E, 0x4D9D,{ 0x97, 0x9F, 0xE3,0xB7, 0x02, 0x93,0x55, 0x76} };
const GUID IID_IVBSAXDeclHandler = {0xE8917260, 0x7579, 0x4BE1,{ 0xB5, 0xDD, 0x7A,0xFB, 0xFA, 0x6F,0x07, 0x7B} };
const GUID IID_IMXWriter = {0x4D7FF4BA, 0x1565, 0x4EA8,{ 0x94, 0xE1, 0x6E,0x72, 0x4A, 0x46,0xF9, 0x8D} };
const GUID IID_IMXAttributes = {0xF10D27CC, 0x3EC0, 0x415C,{ 0x8E, 0xD8, 0x77,0xAB, 0x1C, 0x5E,0x72, 0x62} };
const GUID IID_IMXReaderControl = {0x808F4E35, 0x8D5A, 0x4FBE,{ 0x84, 0x66, 0x33,0xA4, 0x12, 0x79,0xED, 0x30} };
const GUID IID_IMXSchemaDeclHandler = {0xFA4BB38C, 0xFAF9, 0x4CCA,{ 0x93, 0x02, 0xD1,0xDD, 0x0F, 0xE5,0x20, 0xDB} };
const GUID IID_ISchemaElement = {0x50EA08B7, 0xDD1B, 0x4664,{ 0x9A, 0x50, 0xC2,0xF4, 0x0F, 0x4B,0xD7, 0x9A} };
const GUID IID_ISchemaParticle = {0x50EA08B5, 0xDD1B, 0x4664,{ 0x9A, 0x50, 0xC2,0xF4, 0x0F, 0x4B,0xD7, 0x9A} };
const GUID IID_ISchemaItem = {0x50EA08B3, 0xDD1B, 0x4664,{ 0x9A, 0x50, 0xC2,0xF4, 0x0F, 0x4B,0xD7, 0x9A} };
const GUID IID_ISchema = {0x50EA08B4, 0xDD1B, 0x4664,{ 0x9A, 0x50, 0xC2,0xF4, 0x0F, 0x4B,0xD7, 0x9A} };
const GUID IID_ISchemaItemCollection = {0x50EA08B2, 0xDD1B, 0x4664,{ 0x9A, 0x50, 0xC2,0xF4, 0x0F, 0x4B,0xD7, 0x9A} };
const GUID IID_ISchemaStringCollection = {0x50EA08B1, 0xDD1B, 0x4664,{ 0x9A, 0x50, 0xC2,0xF4, 0x0F, 0x4B,0xD7, 0x9A} };
const GUID IID_ISchemaType = {0x50EA08B8, 0xDD1B, 0x4664,{ 0x9A, 0x50, 0xC2,0xF4, 0x0F, 0x4B,0xD7, 0x9A} };
const GUID IID_ISchemaComplexType = {0x50EA08B9, 0xDD1B, 0x4664,{ 0x9A, 0x50, 0xC2,0xF4, 0x0F, 0x4B,0xD7, 0x9A} };
const GUID IID_ISchemaAny = {0x50EA08BC, 0xDD1B, 0x4664,{ 0x9A, 0x50, 0xC2,0xF4, 0x0F, 0x4B,0xD7, 0x9A} };
const GUID IID_ISchemaModelGroup = {0x50EA08BB, 0xDD1B, 0x4664,{ 0x9A, 0x50, 0xC2,0xF4, 0x0F, 0x4B,0xD7, 0x9A} };
const GUID IID_IMXXMLFilter = {0xC90352F7, 0x643C, 0x4FBC,{ 0xBB, 0x23, 0xE9,0x96, 0xEB, 0x2D,0x51, 0xFD} };
const GUID IID_IXMLDOMSchemaCollection2 = {0x50EA08B0, 0xDD1B, 0x4664,{ 0x9A, 0x50, 0xC2,0xF4, 0x0F, 0x4B,0xD7, 0x9A} };
const GUID IID_ISchemaAttribute = {0x50EA08B6, 0xDD1B, 0x4664,{ 0x9A, 0x50, 0xC2,0xF4, 0x0F, 0x4B,0xD7, 0x9A} };
const GUID IID_ISchemaAttributeGroup = {0x50EA08BA, 0xDD1B, 0x4664,{ 0x9A, 0x50, 0xC2,0xF4, 0x0F, 0x4B,0xD7, 0x9A} };
const GUID IID_ISchemaIdentityConstraint = {0x50EA08BD, 0xDD1B, 0x4664,{ 0x9A, 0x50, 0xC2,0xF4, 0x0F, 0x4B,0xD7, 0x9A} };
const GUID IID_ISchemaNotation = {0x50EA08BE, 0xDD1B, 0x4664,{ 0x9A, 0x50, 0xC2,0xF4, 0x0F, 0x4B,0xD7, 0x9A} };
const GUID IID_IXMLDOMSelection = {0xAA634FC7, 0x5888, 0x44A7,{ 0xA2, 0x57, 0x3A,0x47, 0x15, 0x0D,0x3A, 0x0E} };
const GUID DIID_XMLDOMDocumentEvents = {0x3EFAA427, 0x272F, 0x11D2,{ 0x83, 0x6F, 0x00,0x00, 0xF8, 0x7A,0x77, 0x82} };
const GUID IID_IDSOControl = {0x310AFA62, 0x0575, 0x11D2,{ 0x9C, 0xA9, 0x00,0x60, 0xB0, 0xEC,0x3D, 0x39} };
const GUID IID_IXMLHTTPRequest = {0xED8C108D, 0x4349, 0x11D2,{ 0x91, 0xA4, 0x00,0xC0, 0x4F, 0x79,0x69, 0xE8} };
const GUID IID_IServerXMLHTTPRequest = {0x2E9196BF, 0x13BA, 0x4DD4,{ 0x91, 0xCA, 0x6C,0x57, 0x1F, 0x28,0x14, 0x95} };
const GUID IID_IServerXMLHTTPRequest2 = {0x2E01311B, 0xC322, 0x4B0A,{ 0xBD, 0x77, 0xB9,0x0C, 0xFD, 0xC8,0xDC, 0xE7} };
const GUID IID_IMXNamespacePrefixes = {0xC90352F4, 0x643C, 0x4FBC,{ 0xBB, 0x23, 0xE9,0x96, 0xEB, 0x2D,0x51, 0xFD} };
const GUID IID_IVBMXNamespaceManager = {0xC90352F5, 0x643C, 0x4FBC,{ 0xBB, 0x23, 0xE9,0x96, 0xEB, 0x2D,0x51, 0xFD} };
const GUID IID_IMXNamespaceManager = {0xC90352F6, 0x643C, 0x4FBC,{ 0xBB, 0x23, 0xE9,0x96, 0xEB, 0x2D,0x51, 0xFD} };
const GUID CLSID_msDOMDocument = {0xF6D90F11, 0x9C73, 0x11D3,{ 0xB3, 0x2E, 0x00,0xC0, 0x4F, 0x99,0x0B, 0xB4} };
const GUID CLSID_msDOMDocument26 = {0xF5078F1B, 0xC551, 0x11D3,{ 0x89, 0xB9, 0x00,0x00, 0xF8, 0x1F,0xE2, 0x21} };
const GUID CLSID_msDOMDocument30 = {0xF5078F32, 0xC551, 0x11D3,{ 0x89, 0xB9, 0x00,0x00, 0xF8, 0x1F,0xE2, 0x21} };
const GUID CLSID_DOMDocument40 = {0x88D969C0, 0xF192, 0x11D4,{ 0xA6, 0x5F, 0x00,0x40, 0x96, 0x32,0x51, 0xE5} };
const GUID CLSID_DOMDocument60 = {0x88D96A05, 0xF192, 0x11D4,{ 0xA6, 0x5F, 0x00,0x40, 0x96, 0x32,0x51, 0xE5} };
const GUID CLSID_msFreeThreadedDOMDocument = {0xF6D90F12, 0x9C73, 0x11D3,{ 0xB3, 0x2E, 0x00,0xC0, 0x4F, 0x99,0x0B, 0xB4} };
const GUID CLSID_msFreeThreadedDOMDocument26 = {0xF5078F1C, 0xC551, 0x11D3,{ 0x89, 0xB9, 0x00,0x00, 0xF8, 0x1F,0xE2, 0x21} };
const GUID CLSID_msFreeThreadedDOMDocument30 = {0xF5078F33, 0xC551, 0x11D3,{ 0x89, 0xB9, 0x00,0x00, 0xF8, 0x1F,0xE2, 0x21} };
const GUID CLSID_FreeThreadedDOMDocument40 = {0x88D969C1, 0xF192, 0x11D4,{ 0xA6, 0x5F, 0x00,0x40, 0x96, 0x32,0x51, 0xE5} };
const GUID CLSID_FreeThreadedDOMDocument60 = {0x88D96A06, 0xF192, 0x11D4,{ 0xA6, 0x5F, 0x00,0x40, 0x96, 0x32,0x51, 0xE5} };
const GUID CLSID_msXMLSchemaCache = {0x373984C9, 0xB845, 0x449B,{ 0x91, 0xE7, 0x45,0xAC, 0x83, 0x03,0x6A, 0xDE} };
const GUID CLSID_msXMLSchemaCache26 = {0xF5078F1D, 0xC551, 0x11D3,{ 0x89, 0xB9, 0x00,0x00, 0xF8, 0x1F,0xE2, 0x21} };
const GUID CLSID_msXMLSchemaCache30 = {0xF5078F34, 0xC551, 0x11D3,{ 0x89, 0xB9, 0x00,0x00, 0xF8, 0x1F,0xE2, 0x21} };
const GUID CLSID_XMLSchemaCache40 = {0x88D969C2, 0xF192, 0x11D4,{ 0xA6, 0x5F, 0x00,0x40, 0x96, 0x32,0x51, 0xE5} };
const GUID CLSID_XMLSchemaCache60 = {0x88D96A07, 0xF192, 0x11D4,{ 0xA6, 0x5F, 0x00,0x40, 0x96, 0x32,0x51, 0xE5} };
const GUID CLSID_msXSLTemplate = {0x2933BF94, 0x7B36, 0x11D2,{ 0xB2, 0x0E, 0x00,0xC0, 0x4F, 0x98,0x3E, 0x60} };
const GUID CLSID_msXSLTemplate26 = {0xF5078F21, 0xC551, 0x11D3,{ 0x89, 0xB9, 0x00,0x00, 0xF8, 0x1F,0xE2, 0x21} };
const GUID CLSID_msXSLTemplate30 = {0xF5078F36, 0xC551, 0x11D3,{ 0x89, 0xB9, 0x00,0x00, 0xF8, 0x1F,0xE2, 0x21} };
const GUID CLSID_XSLTemplate40 = {0x88D969C3, 0xF192, 0x11D4,{ 0xA6, 0x5F, 0x00,0x40, 0x96, 0x32,0x51, 0xE5} };
const GUID CLSID_XSLTemplate60 = {0x88D96A08, 0xF192, 0x11D4,{ 0xA6, 0x5F, 0x00,0x40, 0x96, 0x32,0x51, 0xE5} };
const GUID CLSID_msDSOControl = {0xF6D90F14, 0x9C73, 0x11D3,{ 0xB3, 0x2E, 0x00,0xC0, 0x4F, 0x99,0x0B, 0xB4} };
const GUID CLSID_msDSOControl26 = {0xF5078F1F, 0xC551, 0x11D3,{ 0x89, 0xB9, 0x00,0x00, 0xF8, 0x1F,0xE2, 0x21} };
const GUID CLSID_msDSOControl30 = {0xF5078F39, 0xC551, 0x11D3,{ 0x89, 0xB9, 0x00,0x00, 0xF8, 0x1F,0xE2, 0x21} };
const GUID CLSID_DSOControl40 = {0x88D969C4, 0xF192, 0x11D4,{ 0xA6, 0x5F, 0x00,0x40, 0x96, 0x32,0x51, 0xE5} };
const GUID CLSID_msXMLHTTP = {0xF6D90F16, 0x9C73, 0x11D3,{ 0xB3, 0x2E, 0x00,0xC0, 0x4F, 0x99,0x0B, 0xB4} };
const GUID CLSID_msXMLHTTP26 = {0xF5078F1E, 0xC551, 0x11D3,{ 0x89, 0xB9, 0x00,0x00, 0xF8, 0x1F,0xE2, 0x21} };
const GUID CLSID_msXMLHTTP30 = {0xF5078F35, 0xC551, 0x11D3,{ 0x89, 0xB9, 0x00,0x00, 0xF8, 0x1F,0xE2, 0x21} };
const GUID CLSID_XMLHTTP40 = {0x88D969C5, 0xF192, 0x11D4,{ 0xA6, 0x5F, 0x00,0x40, 0x96, 0x32,0x51, 0xE5} };
const GUID CLSID_XMLHTTP60 = {0x88D96A0A, 0xF192, 0x11D4,{ 0xA6, 0x5F, 0x00,0x40, 0x96, 0x32,0x51, 0xE5} };
const GUID CLSID_msServerXMLHTTP = {0xAFBA6B42, 0x5692, 0x48EA,{ 0x81, 0x41, 0xDC,0x51, 0x7D, 0xCF,0x0E, 0xF1} };
const GUID CLSID_msServerXMLHTTP30 = {0xAFB40FFD, 0xB609, 0x40A3,{ 0x98, 0x28, 0xF8,0x8B, 0xBE, 0x11,0xE4, 0xE3} };
const GUID CLSID_ServerXMLHTTP40 = {0x88D969C6, 0xF192, 0x11D4,{ 0xA6, 0x5F, 0x00,0x40, 0x96, 0x32,0x51, 0xE5} };
const GUID CLSID_ServerXMLHTTP60 = {0x88D96A0B, 0xF192, 0x11D4,{ 0xA6, 0x5F, 0x00,0x40, 0x96, 0x32,0x51, 0xE5} };
const GUID CLSID_msSAXXMLReader = {0x079AA557, 0x4A18, 0x424A,{ 0x8E, 0xEE, 0xE3,0x9F, 0x0A, 0x8D,0x41, 0xB9} };
const GUID CLSID_msSAXXMLReader30 = {0x3124C396, 0xFB13, 0x4836,{ 0xA6, 0xAD, 0x13,0x17, 0xF1, 0x71,0x36, 0x88} };
const GUID CLSID_SAXXMLReader40 = {0x7C6E29BC, 0x8B8B, 0x4C3D,{ 0x85, 0x9E, 0xAF,0x6C, 0xD1, 0x58,0xBE, 0x0F} };
const GUID CLSID_SAXXMLReader60 = {0x88D96A0C, 0xF192, 0x11D4,{ 0xA6, 0x5F, 0x00,0x40, 0x96, 0x32,0x51, 0xE5} };
const GUID CLSID_msMXXMLWriter = {0xFC220AD8, 0xA72A, 0x4EE8,{ 0x92, 0x6E, 0x0B,0x7A, 0xD1, 0x52,0xA0, 0x20} };
const GUID CLSID_msMXXMLWriter30 = {0x3D813DFE, 0x6C91, 0x4A4E,{ 0x8F, 0x41, 0x04,0x34, 0x6A, 0x84,0x1D, 0x9C} };
const GUID CLSID_MXXMLWriter40 = {0x88D969C8, 0xF192, 0x11D4,{ 0xA6, 0x5F, 0x00,0x40, 0x96, 0x32,0x51, 0xE5} };
const GUID CLSID_MXXMLWriter60 = {0x88D96A0F, 0xF192, 0x11D4,{ 0xA6, 0x5F, 0x00,0x40, 0x96, 0x32,0x51, 0xE5} };
const GUID CLSID_MXHTMLWriter = {0xA4C23EC3, 0x6B70, 0x4466,{ 0x91, 0x27, 0x55,0x00, 0x77, 0x23,0x99, 0x78} };
const GUID CLSID_MXHTMLWriter30 = {0x853D1540, 0xC1A7, 0x4AA9,{ 0xA2, 0x26, 0x4D,0x3B, 0xD3, 0x01,0x14, 0x6D} };
const GUID CLSID_MXHTMLWriter40 = {0x88D969C9, 0xF192, 0x11D4,{ 0xA6, 0x5F, 0x00,0x40, 0x96, 0x32,0x51, 0xE5} };
const GUID CLSID_MXHTMLWriter60 = {0x88D96A10, 0xF192, 0x11D4,{ 0xA6, 0x5F, 0x00,0x40, 0x96, 0x32,0x51, 0xE5} };
const GUID CLSID_msSAXAttributes = {0x4DD441AD, 0x526D, 0x4A77,{ 0x9F, 0x1B, 0x98,0x41, 0xED, 0x80,0x2F, 0xB0} };
const GUID CLSID_msSAXAttributes30 = {0x3E784A01, 0xF3AE, 0x4DC0,{ 0x93, 0x54, 0x95,0x26, 0xB9, 0x37,0x0E, 0xBA} };
const GUID CLSID_SAXAttributes40 = {0x88D969CA, 0xF192, 0x11D4,{ 0xA6, 0x5F, 0x00,0x40, 0x96, 0x32,0x51, 0xE5} };
const GUID CLSID_SAXAttributes60 = {0x88D96A0E, 0xF192, 0x11D4,{ 0xA6, 0x5F, 0x00,0x40, 0x96, 0x32,0x51, 0xE5} };
const GUID CLSID_MXNamespaceManager = {0x88D969D5, 0xF192, 0x11D4,{ 0xA6, 0x5F, 0x00,0x40, 0x96, 0x32,0x51, 0xE5} };
const GUID CLSID_MXNamespaceManager40 = {0x88D969D6, 0xF192, 0x11D4,{ 0xA6, 0x5F, 0x00,0x40, 0x96, 0x32,0x51, 0xE5} };
const GUID CLSID_MXNamespaceManager60 = {0x88D96A11, 0xF192, 0x11D4,{ 0xA6, 0x5F, 0x00,0x40, 0x96, 0x32,0x51, 0xE5} };

};     // namespace Msxml2_tlb
