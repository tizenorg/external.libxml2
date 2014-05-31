// Open Service Platform
// Copyright (c) 2004 Software Center, Samsung Electronics, Inc.
// All right reserved.
//
// This software is the confidential and proprietary information
// of Samsung Electronics, Inc. (¡°Confidential Information¡±). You
// shall not disclose such Confidential Information and shall use
// it only in accordance with the terms of the license agreement
// you entered into with Samsung Electronics.
//
/**
* @file			SUTsXmlWriter.cpp
* @brief		This is the implementation for SUTsXmlModule class.
* @author		Brijesh Singh Mawari(brijesh.sm@partner.samsung.com)
* @version		0.1
*
* This file contains LibXml Tree Operations.
*
*/

/***************************************************************************
* SUTsXmlWriter
***************************************************************************/

#include "utc_libxml_include.h"
#include <libxml/xmlwriter.h>
#include <libxml/xmlreader.h>


#define MY_ENCODING "ISO-8859-1"

//Target

#define	OUTFILE1	UTSHOME"/writer1.res"
#define	OUTFILE2	UTSHOME"/missing.xml"
#define	OUTFILE3	UTSHOME"/test.out"



static xmlDocPtr api_doc = NULL;
static xmlDtdPtr api_dtd = NULL;
static xmlNodePtr api_root = NULL;
static xmlAttrPtr api_attr = NULL;
static xmlNsPtr api_ns = NULL;

static void
free_api_doc(void) {
    xmlFreeDoc(api_doc);
    api_doc = NULL;
    api_dtd = NULL;
    api_root = NULL;
    api_attr = NULL;
    api_ns = NULL;
}

static xmlDocPtr
get_api_doc(void) {
    if (api_doc == NULL) {
        api_doc = xmlReadMemory("<!DOCTYPE root [<!ELEMENT root EMPTY>]><root xmlns:h='http://example.com/' h:foo='bar'/>", 88, "root_test", NULL, 0);
	api_root = NULL;
	api_attr = NULL;
    }
    return(api_doc);
}

static xmlNodePtr
get_api_root(void) {
    if ((api_root == NULL) || (api_root->type != XML_ELEMENT_NODE)) {
        get_api_doc();
	if ((api_doc != NULL) && (api_doc->children != NULL) &&
	    (api_doc->children->next != NULL) &&
	    (api_doc->children->next->type == XML_ELEMENT_NODE))
	    api_root = api_doc->children->next;
    }
    return(api_root);
}
#define gen_nb_xmlOutputBufferPtr 1
static xmlOutputBufferPtr gen_xmlOutputBufferPtr(int no, int nr ATTRIBUTE_UNUSED) {
    if (no == 0) return(xmlOutputBufferCreateFilename(OUTFILE3, NULL, 0));
    return(NULL);
}
static void des_xmlOutputBufferPtr(int no ATTRIBUTE_UNUSED, xmlOutputBufferPtr val, int nr ATTRIBUTE_UNUSED) {
    if (val != NULL) {
        xmlOutputBufferClose(val);
    }
}
static void desret_xmlTextWriterPtr(xmlTextWriterPtr val) {
    xmlFreeTextWriter(val);
}

#define gen_nb_fileoutput 1

static void des_fileoutput(int no ATTRIBUTE_UNUSED, const char *val ATTRIBUTE_UNUSED, int nr ATTRIBUTE_UNUSED) {
}

#define gen_nb_int 1

static int gen_int(int no, int nr ATTRIBUTE_UNUSED) {
    if (no == 0) return(0);
    if (no == 1) return(1);
    if (no == 2) return(-1);
    if (no == 3) return(122);
    return(-1);
}

static void des_int(int no ATTRIBUTE_UNUSED, int val ATTRIBUTE_UNUSED, int nr ATTRIBUTE_UNUSED) {
}

#define gen_nb_xmlBufferPtr 1
static const char *static_buf_content = "a static buffer";
static xmlBufferPtr gen_xmlBufferPtr(int no, int nr ATTRIBUTE_UNUSED) {
    if (no == 0) return(xmlBufferCreate());
    if (no == 1) return(xmlBufferCreateStatic((void *)static_buf_content, 13));
    return(NULL);
}
static void des_xmlBufferPtr(int no ATTRIBUTE_UNUSED, xmlBufferPtr val, int nr ATTRIBUTE_UNUSED) {
    if (val != NULL) {
        xmlBufferFree(val);
    }
}

#define gen_nb_xmlParserCtxtPtr 1
static xmlParserCtxtPtr gen_xmlParserCtxtPtr(int no, int nr ATTRIBUTE_UNUSED) {
    if (no == 0) return(xmlNewParserCtxt());
    //if (no == 1) return(xmlCreateMemoryParserCtxt("<doc/>", 6));
    return(NULL);
}
static void des_xmlParserCtxtPtr(int no ATTRIBUTE_UNUSED, xmlParserCtxtPtr val, int nr ATTRIBUTE_UNUSED) {
    if (val != NULL)
        xmlFreeParserCtxt(val);
}

#define gen_nb_const_char_ptr 2

static char *gen_const_char_ptr(int no, int nr ATTRIBUTE_UNUSED) {
    if (no == 0) return((char *) "foo");
    if (no == 1) return((char *) "<foo/>");
    if (no == 2) return((char *) "test/ent2");
    return(NULL);
}
static void des_const_char_ptr(int no ATTRIBUTE_UNUSED, const char *val ATTRIBUTE_UNUSED, int nr ATTRIBUTE_UNUSED) {
}
#if 0
static void desret_xmlParserCtxtPtr(xmlParserCtxtPtr val) {
    xmlFreeParserCtxt(val);
}
#endif
#define gen_nb_xmlNodePtr 2
static xmlNodePtr gen_xmlNodePtr(int no, int nr ATTRIBUTE_UNUSED) {
    if (no == 0) return(xmlNewPI(BAD_CAST "test", NULL));
    if (no == 1) return(get_api_root());
    return(NULL);
/*     if (no == 2) return((xmlNodePtr) get_api_doc()); */
}

static void des_xmlNodePtr(int no, xmlNodePtr val, int nr ATTRIBUTE_UNUSED) {
    if (no == 1) {
        free_api_doc();
    } else if (val != NULL) {
        xmlUnlinkNode(val);
        xmlFreeNode(val);
    }
}

#define gen_nb_xmlDocPtr 1
static xmlDocPtr gen_xmlDocPtr(int no, int nr ATTRIBUTE_UNUSED) {
    if (no == 0) return(xmlNewDoc(BAD_CAST "1.0"));
    if (no == 1) return(xmlReadMemory("<foo/>", 6, "test", NULL, 0));
    if (no == 2) return(xmlReadMemory("<!DOCTYPE foo []> <foo/>", 24, "test", NULL, 0));
    return(NULL);
}
static void des_xmlDocPtr(int no ATTRIBUTE_UNUSED, xmlDocPtr val, int nr ATTRIBUTE_UNUSED) {
    if ((val != NULL) && (val != api_doc) && (val->doc != api_doc))
        xmlFreeDoc(val);
}
#define gen_nb_xmlTextWriterPtr 1
static xmlTextWriterPtr gen_xmlTextWriterPtr(int no, int nr ATTRIBUTE_UNUSED) {
    if (no == 0) return(xmlNewTextWriterFilename(OUTFILE3, 0));
    return(NULL);
}
static void des_xmlTextWriterPtr(int no ATTRIBUTE_UNUSED, xmlTextWriterPtr val, int nr ATTRIBUTE_UNUSED) {
    if (val != NULL) xmlFreeTextWriter(val);
}

static void desret_int(int val ATTRIBUTE_UNUSED) {
}

#if 0
#define gen_nb_const_xmlChar_ptr_ptr 1
static xmlChar ** gen_const_xmlChar_ptr_ptr(int no ATTRIBUTE_UNUSED, int nr ATTRIBUTE_UNUSED) {
    return(NULL);
}
static void des_const_xmlChar_ptr_ptr(int no ATTRIBUTE_UNUSED, const xmlChar ** val ATTRIBUTE_UNUSED, int nr ATTRIBUTE_UNUSED) {
}
#endif
#define gen_nb_const_xmlChar_ptr 1

static xmlChar *gen_const_xmlChar_ptr(int no, int nr ATTRIBUTE_UNUSED) {
    if (no == 0) return((xmlChar *) "foo");
    if (no == 1) return((xmlChar *) "<foo/>");
    if (no == 2) return((xmlChar *) "n?e");
    if (no == 3) return((xmlChar *) " 2ab ");
    return(NULL);
}
static void des_const_xmlChar_ptr(int no ATTRIBUTE_UNUSED, const xmlChar *val ATTRIBUTE_UNUSED, int nr ATTRIBUTE_UNUSED) {
}

xmlChar *
ConvertInput(const char *in, const char *encoding)
{
char Buff[128] = {0,};
    xmlChar *out;
    int ret;
    int size;
    int out_size;
    int temp;
    xmlCharEncodingHandlerPtr handler;

    if (in == 0)
        return NULL;

    handler = xmlFindCharEncodingHandler(encoding);

    if (!handler) {
	snprintf(Buff, 127, "ConvertInput: no encoding handler found for '%s'\n", encoding ? encoding : "");
//        DTS_PRINT("ConvertInput", Buff );
	return NULL;
    }

    size = (int) strlen(in) + 1;
    out_size = size * 2 - 1;
    out = (unsigned char *) xmlMalloc((size_t) out_size);

    if (out != 0) {
        temp = size - 1;
        ret = handler->input(out, &out_size, (const xmlChar *) in, &temp);
        if ((ret < 0) || (temp - size + 1)) {
            if (ret < 0) {
			DTS_PRINT("ConvertInput", "ConvertInput: conversion wasn't successful.\n" );
            } else {
			snprintf(Buff, 127, "ConvertInput: conversion wasn't successful. converted: %i octets.\n", temp);
			//DTS_PRINT("ConvertInput", Buff );				
            }

            xmlFree(out);
            out = 0;
        } else {
            out = (unsigned char *) xmlRealloc(out, out_size + 1);
            out[out_size] = 0;  /*NULL terminating out */
        }
    } else {
	DTS_PRINT("ConvertInput", "ConvertInput: no mem\n" );				
   }

    return out;
}





static void UTcXmlNewTextWriterP01()
{
	xmlTextWriterPtr ret_val;
	xmlOutputBufferPtr out; /* an xmlOutputBufferPtr */
	int n_out;

	for (n_out = 0;n_out < gen_nb_xmlOutputBufferPtr;n_out++) {
		out = gen_xmlOutputBufferPtr(n_out, 0);
		DTS_CHECK_NE_MESSAGE("xmlNewTextWriter", (void *)out, (void *)NULL, "gen_xmlOutputBufferPtr Failed");
		/**
		* @remarks   input1: [N/A, N/A] @n
		*            {xmlOutputBufferPtr} => { N/A | xmlTextWriterPtr pointer } @n
		*/
		ret_val = xmlNewTextWriter(out);
		DTS_CHECK_NE_MESSAGE("xmlNewTextWriter", (void *)ret_val, (void *)NULL, "xmlNewTextWriter Failed");
		if (ret_val != NULL)
			out = NULL;
		desret_xmlTextWriterPtr(ret_val);
		des_xmlOutputBufferPtr(n_out, out, 0);
		xmlResetLastError();
	}
}

static void
UTcXmlNewTextWriterFilenameP01()
{
	xmlTextWriterPtr ret_val;
	const char * uri; /* the URI of the resource for the output */
	int n_uri;
	int compression; /* compress the output? */
	int n_compression;

	for (n_uri = 0;n_uri < gen_nb_fileoutput;n_uri++) {
		for (n_compression = 0;n_compression < gen_nb_int;n_compression++) {
			uri = gen_fileoutput(n_uri, 0);
			DTS_CHECK_NE_MESSAGE("xmlNewTextWriterFilename", (void *)uri, (void *)NULL, "gen_fileoutput Failed");
			compression = gen_int(n_compression, 1);
			//MT_CHECK_MESSAGE2(0 != compression, "gen_int returned NULL");
			/**
			* @remarks   input1: [N/A, N/A] @n
			*            {(http://localhost/,http:http://http,ftp://localhost/foo) , (0,1,-1,122)}
			*            => { N/A | xmlTextWriterPtr pointer } @n
			*/
			ret_val = xmlNewTextWriterFilename(uri, compression);
			DTS_CHECK_NE_MESSAGE("xmlNewTextWriterFilename", (void *)ret_val, (void *)NULL, "xmlNewTextWriterFilename Failed");
			desret_xmlTextWriterPtr(ret_val);
			des_fileoutput(n_uri, uri, 0);
			des_int(n_compression, compression, 1);
			xmlResetLastError();
		}
	}
}


static void
UTcXmlNewTextWriterMemoryP01()
{
	xmlTextWriterPtr ret_val;
	xmlBufferPtr buf; /* xmlBufferPtr */
	int n_buf;
	int compression; /* compress the output? */
	int n_compression;

	for (n_buf = 0;n_buf < gen_nb_xmlBufferPtr;n_buf++) {
		for (n_compression = 0;n_compression < gen_nb_int;n_compression++) {
			buf = gen_xmlBufferPtr(n_buf, 0);
			DTS_CHECK_NE_MESSAGE("xmlNewTextWriterMemory", (void *)buf, (void *)NULL, "gen_xmlBufferPtr Failed");
			compression = gen_int(n_compression, 1);
			//MT_CHECK_MESSAGE2(0 != compression, "gen_int returned NULL");
			/**
			* @remarks   input1: [N/A, N/A] @n
			*            {xmlBufferPtr pointer , (0,1,-1,122)} => { N/A | xmlTextWriterPtr pointer} @n
			*/
			ret_val = xmlNewTextWriterMemory(buf, compression);
			DTS_CHECK_NE_MESSAGE("xmlNewTextWriterMemory", (void *)ret_val, (void *)NULL, "xmlNewTextWriterMemory Failed");
			desret_xmlTextWriterPtr(ret_val);
			des_xmlBufferPtr(n_buf, buf, 0);
			des_int(n_compression, compression, 1);
			xmlResetLastError();
		}
	}
}
static void
UTcXmlNewTextWriterPushParserP01()
{
	xmlTextWriterPtr ret_val;
	xmlParserCtxtPtr ctxt; /* xmlParserCtxtPtr to hold the new XML document tree */
	int n_ctxt;
	int compression; /* compress the output? */
	int n_compression;

	for (n_ctxt = 0;n_ctxt < gen_nb_xmlParserCtxtPtr;n_ctxt++) {
		for (n_compression = 0;n_compression < gen_nb_int;n_compression++) {
			ctxt = gen_xmlParserCtxtPtr(n_ctxt, 0);
			DTS_CHECK_NE_MESSAGE("xmlNewTextWriterPushParser", (void *)ctxt, (void *)NULL, "gen_xmlParserCtxtPtr Failed");
			compression = gen_int(n_compression, 1);
			//MT_CHECK_MESSAGE2(0 != compression, "gen_int returned NULL");
			/**
			* @remarks   input1: [N/A, N/A] @n
			*            {xmlParserCtxtPtr pointer , (0,1,-1,122)} => { N/A | xmlTextWriterPtr pointer} @n
			*/
			ret_val = xmlNewTextWriterPushParser(ctxt, compression);
			DTS_CHECK_NE_MESSAGE("xmlNewTextWriterPushParser", (void *)ret_val, (void *)NULL, "xmlNewTextWriterPushParser Failed");
			if (ctxt != NULL) {
				xmlFreeDoc(ctxt->myDoc);
				ctxt->myDoc = NULL;
			}
			if (ret_val != NULL)
				ctxt = NULL;
			//desret_xmlTextWriterPtr(ret_val);
			des_xmlParserCtxtPtr(n_ctxt, ctxt, 0);
			des_int(n_compression, compression, 1);
			xmlResetLastError();
		}
	}
}
static void
UTcXmlNewTextWriterDocP01()
{
	xmlTextWriterPtr ret_val;
	xmlDocPtr doc;

	/* Create a new XmlWriter for DOM, with no compression. */
	ret_val = xmlNewTextWriterDoc(&doc, 0);
	DTS_CHECK_NE_MESSAGE("xmlNewTextWriterDoc", (void *)ret_val, (void *)NULL, "xmlNewTextWriterDoc Failed");

	/* Create a new XmlWriter for DOM, with no compression. */
	ret_val = xmlNewTextWriterDoc(&doc, 3);
	DTS_CHECK_NE_MESSAGE("xmlNewTextWriterDoc", (void *)ret_val, (void *)NULL, "xmlNewTextWriterDoc Failed");

	//desret_xmlTextWriterPtr(ret_val);
	xmlFreeTextWriter(ret_val);
	if (doc != NULL)
		xmlFreeDoc(doc);
	xmlResetLastError();
}


static void
UTcXmlNewTextWriterTreeP01()
{
	xmlTextWriterPtr ret_val;
	xmlDocPtr doc; /* xmlDocPtr */
	int n_doc;
	xmlNodePtr node; /* xmlNodePtr or NULL for doc->children */
	int n_node;
	int compression; /* compress the output? */
	int n_compression;

	for (n_doc = 0;n_doc < gen_nb_xmlDocPtr;n_doc++) {
		for (n_node = 0;n_node < gen_nb_xmlNodePtr;n_node++) {
			for (n_compression = 0;n_compression < gen_nb_int;n_compression++) {
				doc = gen_xmlDocPtr(n_doc, 0);
				DTS_CHECK_NE_MESSAGE("xmlNewTextWriterTree", (void *)doc, (void *)NULL, "gen_xmlDocPtr Failed");

				node = gen_xmlNodePtr(n_node, 1);
				DTS_CHECK_NE_MESSAGE("xmlNewTextWriterTree", (void *)node, (void *)NULL, "gen_xmlNodePtr Failed");

				compression = gen_int(n_compression, 2);
				//MT_CHECK_MESSAGE2(0 != compression, "gen_int returned NULL");
				/**
				* @remarks   input1: [N/A, N/A] @n
				*            { xmlDocPtr pointer ,xmlNodePtr pointer , (0,1,-1,122)} =>
				*            { N/A | xmlTextWriterPtr pointer} @n
				*/
				ret_val = xmlNewTextWriterTree(doc, node, compression);
				DTS_CHECK_NE_MESSAGE("xmlNewTextWriterTree", (void *)ret_val, (void *)NULL, "xmlNewTextWriterTree Failed");
				
				desret_xmlTextWriterPtr(ret_val);
				des_xmlDocPtr(n_doc, doc, 0);
				des_xmlNodePtr(n_node, node, 1);
				des_int(n_compression, compression, 2);
				xmlResetLastError();
			}
		}
	}
}

static void
UTcXmlFreeTextWriterP01()
{
	xmlTextWriterPtr ret_val;
	xmlOutputBufferPtr out; /* an xmlOutputBufferPtr */
	int n_out;

	for (n_out = 0;n_out < gen_nb_xmlOutputBufferPtr;n_out++) {
		out = gen_xmlOutputBufferPtr(n_out, 0);
		DTS_CHECK_NE_MESSAGE("xmlNewTextWriter", (void *)out, (void *)NULL, "gen_xmlOutputBufferPtr Failed");
			
		ret_val = xmlNewTextWriter(out);
		DTS_CHECK_NE_MESSAGE("xmlNewTextWriter", (void *)ret_val, (void *)NULL, "xmlNewTextWriter Failed");
		
		if (ret_val != NULL)
			out = NULL;

		/**
		* @remarks   input1: [N/A, N/A] @n
		*            {xmlTextWriterPtr pointer} => { N/A | void } @n
		*/
		xmlFreeTextWriter(ret_val);
		//desret_xmlTextWriterPtr(ret_val);
		des_xmlOutputBufferPtr(n_out, out, 0);
		xmlResetLastError();
	}
}



static void UTcXmlTextWriterStartDocumentP01()
{
	int ret_val;
	xmlTextWriterPtr writer; /* the xmlTextWriterPtr */
	int n_writer;
	char * version; /* the xml version ("1.0") or NULL for default ("1.0") */
	int n_version;
	char * standalone; /* "yes" or "no" or NULL for default */
	int n_standalone;

	for (n_writer = 0;n_writer < gen_nb_xmlTextWriterPtr;n_writer++) {
		for (n_version = 0;n_version < gen_nb_const_char_ptr;n_version++) {
			for (n_standalone = 0;n_standalone < gen_nb_const_char_ptr;n_standalone++) {
			writer = gen_xmlTextWriterPtr(n_writer, 0);
			DTS_CHECK_NE_MESSAGE("xmlTextWriterStartDocument", (void *)writer, (void *)NULL, "gen_xmlTextWriterPtr Failed");
		
			version = gen_const_char_ptr(n_version, 1);
			DTS_CHECK_NE_MESSAGE("xmlTextWriterStartDocument", (void *)version, (void *)NULL, "gen_const_char_ptr Failed");
			
			standalone = gen_const_char_ptr(n_standalone, 3);
			DTS_CHECK_NE_MESSAGE("xmlTextWriterStartDocument", (void *)standalone, (void *)NULL, "gen_const_char_ptr Failed");
			
			/**
			* @remarks   input1: [N/A, N/A] @n
			*            { xmlTextWriterPtr pointer ,("foo",<foo/>","test/ent2"), ISO-8859-1 ,("foo",<foo/>","test/ent2")} =>
			*            { N/A | int } @n
			*/
			ret_val = xmlTextWriterStartDocument(writer, (const char *)version, MY_ENCODING, (const char *)standalone);
			DTS_CHECK_EQ_MESSAGE("xmlTextWriterStartDocument", (void *)ret_val, (void *)0, "xmlTextWriterStartDocument Failed");
			
			desret_int(ret_val);
			des_xmlTextWriterPtr(n_writer, writer, 0);
			des_const_char_ptr(n_version, (const char *)version, 1);
			des_const_char_ptr(n_standalone, (const char *)standalone, 3);
			xmlResetLastError();
			}
		}
	}
}

static void
UTcXmlTextWriterEndDocumentP01()
{
	int ret_val;
	xmlTextWriterPtr writer; /* the xmlTextWriterPtr */
	int n_writer;

	for (n_writer = 0;n_writer < gen_nb_xmlTextWriterPtr;n_writer++) {
		writer = gen_xmlTextWriterPtr(n_writer, 0);
		DTS_CHECK_NE_MESSAGE("xmlTextWriterEndDocument", (void *)writer, (void *)NULL, "gen_xmlTextWriterPtr Failed");
		
		/**
		* @remarks   input1: [N/A, N/A] @n
		*            { xmlTextWriterPtr pointer} => { N/A | int } @n
		*/
		ret_val = xmlTextWriterEndDocument(writer);
		DTS_CHECK_NE_MESSAGE("xmlTextWriterEndDocument", (void *)ret_val, (void *)-1, "xmlTextWriterEndDocument Failed");
		
		desret_int(ret_val);
		des_xmlTextWriterPtr(n_writer, writer, 0);
		xmlResetLastError();
	}
}

static void
UTcXmlTextWriterStartElementP01()
{
    int ret_val;
    xmlTextWriterPtr writer; /* the xmlTextWriterPtr */
    int n_writer;
    xmlChar * name; /* element name */
    int n_name;

    for (n_writer = 0;n_writer < gen_nb_xmlTextWriterPtr;n_writer++) {
		for (n_name = 0;n_name < gen_nb_const_xmlChar_ptr;n_name++) {
			writer = gen_xmlTextWriterPtr(n_writer, 0);
			DTS_CHECK_NE_MESSAGE("xmlTextWriterStartElement", (void *)writer, (void *)NULL, "gen_xmlTextWriterPtr Failed");
			
			name = gen_const_xmlChar_ptr(n_name, 1);
			DTS_CHECK_NE_MESSAGE("xmlTextWriterStartElement", (void *)name, (void *)NULL, "gen_const_xmlChar_ptr Failed");
			
			/**
			* @remarks   input1: [N/A, N/A] @n
			*            { xmlTextWriterPtr pointer} =>
			*            { N/A | int } @n
			*/
			ret_val = xmlTextWriterStartElement(writer, (const xmlChar *)name);
			DTS_CHECK_EQ_MESSAGE("xmlTextWriterStartElement", (void *)ret_val, (void *)0, "xmlTextWriterStartElement Failed");
			
			desret_int(ret_val);
			des_xmlTextWriterPtr(n_writer, writer, 0);
			des_const_xmlChar_ptr(n_name, (const xmlChar *)name, 1);
			xmlResetLastError();
		}
    }
}

static void
UTcXmlTextWriterStartElementNSP01()
{
	int ret_val;
	xmlTextWriterPtr writer; /* the xmlTextWriterPtr */
	int n_writer;
	xmlChar * prefix; /* namespace prefix or NULL */
	int n_prefix;
	xmlChar * name; /* element local name */
	int n_name;
	xmlChar * namespaceURI; /* namespace URI or NULL */
	int n_namespaceURI;

	for (n_writer = 0;n_writer < gen_nb_xmlTextWriterPtr;n_writer++) {
		for (n_prefix = 0;n_prefix < gen_nb_const_xmlChar_ptr;n_prefix++) {
			for (n_name = 0;n_name < gen_nb_const_xmlChar_ptr;n_name++) {
				for (n_namespaceURI = 0;n_namespaceURI < gen_nb_const_xmlChar_ptr;n_namespaceURI++) {
				writer = gen_xmlTextWriterPtr(n_writer, 0);
				DTS_CHECK_NE_MESSAGE("xmlTextWriterStartElementNS", (void *)writer, (void *)NULL, "gen_xmlTextWriterPtr Failed");

				prefix = gen_const_xmlChar_ptr(n_prefix, 1);
				DTS_CHECK_NE_MESSAGE("xmlTextWriterStartElementNS", (void *)prefix, (void *)NULL, "gen_const_xmlChar_ptr Failed");

				name = gen_const_xmlChar_ptr(n_name, 2);
				DTS_CHECK_NE_MESSAGE("xmlTextWriterStartElementNS", (void *)name, (void *)NULL, "gen_const_xmlChar_ptr Failed");
				
				namespaceURI = gen_const_xmlChar_ptr(n_namespaceURI, 3);
				DTS_CHECK_NE_MESSAGE("xmlTextWriterStartElementNS", (void *)namespaceURI, (void *)NULL, "gen_const_xmlChar_ptr Failed");
				
				/**
				* @remarks   input1: [N/A, N/A] @n
				*            { xmlTextWriterPtr pointer, xmlChar pointer, xmlChar pointer, xmlChar pointer} =>
				*            { N/A | int } @n
				*/
				ret_val = xmlTextWriterStartElementNS(writer, (const xmlChar *)prefix, (const xmlChar *)name, (const xmlChar *)namespaceURI);
				DTS_CHECK_EQ_MESSAGE("xmlTextWriterStartElementNS", (void *)ret_val, (void *)0, "xmlTextWriterStartElementNS Failed");
				
				desret_int(ret_val);
				des_xmlTextWriterPtr(n_writer, writer, 0);
				des_const_xmlChar_ptr(n_prefix, (const xmlChar *)prefix, 1);
				des_const_xmlChar_ptr(n_name, (const xmlChar *)name, 2);
				des_const_xmlChar_ptr(n_namespaceURI, (const xmlChar *)namespaceURI, 3);
				xmlResetLastError();
				}
			}
		}
	}
}

static void
UTcXmlTextWriterEndElementP01()
{
	int ret_val;
	xmlTextWriterPtr writer; /* the xmlTextWriterPtr */
	int n_writer;

	for (n_writer = 0;n_writer < gen_nb_xmlTextWriterPtr;n_writer++) {
		writer = gen_xmlTextWriterPtr(n_writer, 0);
		DTS_CHECK_NE_MESSAGE("xmlTextWriterEndElement", (void *)writer, (void *)NULL, "gen_xmlTextWriterPtr Failed");

		/**
		* @remarks   input1: [N/A, N/A] @n
		*            { xmlTextWriterPtr pointer} => { N/A | int } @n
		*/
		ret_val = xmlTextWriterEndElement(writer);
		DTS_CHECK_EQ_MESSAGE("xmlTextWriterEndElement", (void *)ret_val, (void *)-1, "xmlTextWriterEndElement Failed");

		desret_int(ret_val);
		des_xmlTextWriterPtr(n_writer, writer, 0);
		xmlResetLastError();
	}
}

static void
UTcXmlTextWriterFullEndElementP01()
{
   	int ret_val;
	xmlTextWriterPtr writer; /* the xmlTextWriterPtr*/
	xmlChar *tmp;

	/**
	 * @pre		1) Create a new xmlNewTextWriter.\n
	 * 			2) Start a Document.\n
	 * 			3) Write a Element and Attribute. \n
	 */

	writer = xmlNewTextWriterFilename(OUTFILE1, 0);
	DTS_CHECK_NE_MESSAGE("xmlTextWriterFullEndElement", (void *)writer, (void *)NULL, "xmlNewTextWriterFilename Failed");

	ret_val = xmlTextWriterStartDocument(writer, NULL, MY_ENCODING, NULL);
	DTS_CHECK_EQ_MESSAGE("xmlTextWriterFullEndElement", (void *)ret_val, (void *)0, "xmlTextWriterStartDocument Failed");

	ret_val = xmlTextWriterStartElement(writer, BAD_CAST "EXAMPLE");
	DTS_CHECK_EQ_MESSAGE("xmlTextWriterFullEndElement", (void *)ret_val, (void *)0, "xmlTextWriterStartElement Failed");

	tmp = ConvertInput("This is a comment with special chars: <äö?",MY_ENCODING);
	ret_val = xmlTextWriterWriteComment(writer, tmp);
	DTS_CHECK_EQ_MESSAGE("xmlTextWriterFullEndElement", (void *)ret_val, (void *)0, "xmlTextWriterWriteComment Failed");
	
	if (tmp != NULL) 
		xmlFree(tmp);

	ret_val = xmlTextWriterStartElement(writer, BAD_CAST "ORDER");
	DTS_CHECK_EQ_MESSAGE("xmlTextWriterFullEndElement", (void *)ret_val, (void *)0, "xmlTextWriterStartElement Failed");

	ret_val = xmlTextWriterStartAttribute(writer ,BAD_CAST "X_ORDER_ID");
	DTS_CHECK_EQ_MESSAGE("xmlTextWriterFullEndElement", (void *)ret_val, (void *)0, "xmlTextWriterStartAttribute Failed");

	ret_val = xmlTextWriterEndAttribute(writer);
	DTS_CHECK_EQ_MESSAGE("xmlTextWriterFullEndElement", (void *)ret_val, (void *)0, "xmlTextWriterEndAttribute Failed");

	ret_val = xmlTextWriterEndElement(writer);
	DTS_CHECK_EQ_MESSAGE("xmlTextWriterFullEndElement", (void *)ret_val, (void *)0, "xmlTextWriterEndElement Failed");

	/**
	* @remarks   input1: [N/A, N/A] @n
	*            { xmlTextWriterPtr pointer} => { N/A | int } @n
	*/
	ret_val = xmlTextWriterFullEndElement(writer);
	DTS_CHECK_EQ_MESSAGE("xmlTextWriterFullEndElement", (void *)ret_val, (void *)0, "xmlTextWriterFullEndElement Failed");
	
	if (writer != NULL)
		xmlFreeTextWriter(writer);
	/**
	 * @post	Free xmlNewTextWriter pointer
	 */
	xmlResetLastError();
}

static void
UTcXmlTextWriterStartCommentP01()
{
	int ret_val;
	xmlTextWriterPtr writer; /* the xmlTextWriterPtr */
	int n_writer;

	for (n_writer = 0;n_writer < gen_nb_xmlTextWriterPtr;n_writer++) {
		writer = gen_xmlTextWriterPtr(n_writer, 0);
		DTS_CHECK_NE_MESSAGE("xmlTextWriterStartComment", (void *)writer, (void *)NULL, "gen_xmlTextWriterPtr Failed");
		/**
		* @remarks   input1: [N/A, N/A] @n
		*            { xmlTextWriterPtr pointer} => { N/A | int } @n
		*/
		ret_val = xmlTextWriterStartComment(writer);
		DTS_CHECK_EQ_MESSAGE("xmlTextWriterStartComment", (void *)ret_val, (void *)NULL, "xmlTextWriterStartComment Failed");
		
		desret_int(ret_val);
		des_xmlTextWriterPtr(n_writer, writer, 0);
		xmlResetLastError();
	}
}

static void
UTcXmlTextWriterEndCommentP01()
{
	int ret_val;
	xmlTextWriterPtr writer; /* the xmlTextWriterPtr */
	xmlDocPtr doc;
	/**
	 * @pre		1) Create a new Document.\n
	 * 			2) Start a Document.\n
	 * 			3) Write a Comment. \n
	 */
	writer = xmlNewTextWriterDoc(&doc, 0);
	DTS_CHECK_NE_MESSAGE("xmlTextWriterEndComment", (void *)writer, (void *)NULL, "xmlNewTextWriterDoc Failed");

	ret_val = xmlTextWriterStartDocument(writer, NULL, NULL, NULL);
	DTS_CHECK_EQ_MESSAGE("xmlTextWriterEndComment", (void *)ret_val, (void *)0, "xmlTextWriterStartDocument Failed");

	ret_val = xmlTextWriterStartComment(writer);
	DTS_CHECK_EQ_MESSAGE("xmlTextWriterEndComment", (void *)ret_val, (void *)0, "xmlTextWriterStartComment Failed");

	/**
	* @remarks   input1: [N/A, N/A] @n
	*            { xmlTextWriterPtr pointer} => { N/A | int } @n
	*/
	ret_val = xmlTextWriterEndComment(writer);
	DTS_CHECK_EQ_MESSAGE("xmlTextWriterEndComment", (void *)ret_val, (void *)0, "xmlTextWriterEndComment Failed");

	xmlTextWriterEndDocument(writer);
	xmlFreeTextWriter(writer);
	/**
	 * @post	1) Close the Document. \n
	 * 			2) Free xmlNewTextWriter pointer. \n
	 */
	xmlResetLastError();
}


static void
UTcXmlTextWriterWriteVFormatCommentP01()
{
	//TC have to be written
	DTS_CHECK_EQ_MESSAGE("UTcXmlTextWriterWriteVFormatCommentP01", (void *)1, (void *)1, "UTcXmlTextWriterWriteVFormatCommentP01 Failed");
}

static void
UTcXmlTextWriterWriteCommentP01()
{
	int ret_val;
	xmlTextWriterPtr writer; /* the xmlTextWriterPtr */
	int n_writer;
	xmlChar * content; /* comment string */
	int n_content;

	for (n_writer = 0;n_writer < gen_nb_xmlTextWriterPtr;n_writer++) {
		for (n_content = 0;n_content < gen_nb_const_xmlChar_ptr;n_content++) {
			writer = gen_xmlTextWriterPtr(n_writer, 0);
			DTS_CHECK_NE_MESSAGE("xmlTextWriterWriteComment", (void *)writer, (void *)NULL, "gen_xmlTextWriterPtr Failed");
			
			content = gen_const_xmlChar_ptr(n_content, 1);
			DTS_CHECK_NE_MESSAGE("xmlTextWriterWriteComment", (void *)content, (void *)NULL, "gen_const_xmlChar_ptr Failed");
			
			/**
			* @remarks   input1: [N/A, N/A] @n
			*            { xmlTextWriterPtr pointer , xmlChar pointer} => { N/A | int } @n
			*/
			ret_val = xmlTextWriterWriteComment(writer, (const xmlChar *)content);
			DTS_CHECK_EQ_MESSAGE("xmlTextWriterWriteComment", (void *)ret_val, (void *)0, "xmlTextWriterWriteComment Failed");
			
			desret_int(ret_val);
			des_xmlTextWriterPtr(n_writer, writer, 0);
			des_const_xmlChar_ptr(n_content, (const xmlChar *)content, 1);
			xmlResetLastError();
		}
	}
}

static void
UTcXmlTextWriterStartAttributeP01()
{
	int ret_val;
	xmlTextWriterPtr writer; /* the xmlTextWriterPtr*/
//	int n_writer;
	/**
	 * @pre		1) Create a new Document.\n
	 * 			2) Write a Element. \n
	 */
	writer = xmlNewTextWriterFilename(OUTFILE1, 0);
	DTS_CHECK_NE_MESSAGE("xmlTextWriterStartAttribute", (void *)writer, (void *)NULL, "xmlNewTextWriterFilename Failed");

	ret_val = xmlTextWriterStartElement(writer, BAD_CAST "ORDER");
	DTS_CHECK_EQ_MESSAGE("xmlTextWriterStartAttribute", (void *)ret_val, (void *)0, "xmlTextWriterStartElement Failed");
	
	/**
	* @remarks   input1: [N/A, N/A] @n
	*            { xmlTextWriterPtr pointer ,BAD_CAST "X_ORDER_ID"} => { N/A | int } @n
	*/
	ret_val = xmlTextWriterStartAttribute(writer ,BAD_CAST "X_ORDER_ID");
	DTS_CHECK_EQ_MESSAGE("xmlTextWriterStartAttribute", (void *)ret_val, (void *)0, "xmlTextWriterStartAttribute Failed");

	ret_val = xmlTextWriterEndElement(writer);
	DTS_CHECK_EQ_MESSAGE("xmlTextWriterStartAttribute", (void *)ret_val, (void *)0, "xmlTextWriterEndElement Failed");

	if (writer != NULL)
	xmlFreeTextWriter(writer);
	/**
	 * @post	1) Free xmlNewTextWriter pointer. \n
	 */
	xmlResetLastError();
}

static void
UTcXmlTextWriterStartAttributeNSP01()
{
	int ret_val;
	xmlTextWriterPtr writer; /* the xmlTextWriterPtr */
	xmlChar *tmp;
	/**
	 * @pre		1) Create a new Document.\n
	 * 			2) Start a Document.\n
	 * 			3) Write a Element. \n
	 */
	writer = xmlNewTextWriterFilename(OUTFILE1, 0);
	DTS_CHECK_NE_MESSAGE("xmlTextWriterStartAttributeNS", (void *)writer, (void *)NULL, "xmlNewTextWriterFilename Failed");

	ret_val = xmlTextWriterStartDocument(writer, NULL, MY_ENCODING, NULL);
	DTS_CHECK_EQ_MESSAGE("xmlTextWriterStartAttributeNS", (void *)ret_val, (void *)0, "xmlTextWriterStartDocument Failed");

	ret_val = xmlTextWriterStartElement(writer, BAD_CAST "EXAMPLE");
	DTS_CHECK_EQ_MESSAGE("xmlTextWriterStartAttributeNS", (void *)ret_val, (void *)0, "xmlTextWriterStartElement Failed");

	tmp = ConvertInput("This is a comment with special chars: <äö?",MY_ENCODING);
	ret_val = xmlTextWriterWriteComment(writer, tmp);
	DTS_CHECK_EQ_MESSAGE("xmlTextWriterStartAttributeNS", (void *)ret_val, (void *)0, "xmlTextWriterWriteComment Failed");
	
	if (tmp != NULL) xmlFree(tmp);

	ret_val = xmlTextWriterStartElement(writer, BAD_CAST "ORDER");
	DTS_CHECK_EQ_MESSAGE("xmlTextWriterStartAttributeNS", (void *)ret_val, (void *)0, "xmlTextWriterStartElement Failed");

	/**
	* @remarks   input1: [N/A, N/A] @n
	*            { xmlTextWriterPtr pointer ,BAD_CAST "X_ORDER_ID", xmlChar pointer } => { N/A | int } @n
	*/
	ret_val = xmlTextWriterStartAttributeNS(writer, NULL, BAD_CAST "version",NULL);
	DTS_CHECK_EQ_MESSAGE("xmlTextWriterStartAttributeNS", (void *)ret_val, (void *)0, "xmlTextWriterStartAttributeNS Failed");

	ret_val = xmlTextWriterEndElement(writer);
	DTS_CHECK_EQ_MESSAGE("xmlTextWriterStartAttributeNS", (void *)ret_val, (void *)0, "xmlTextWriterEndElement Failed");

	ret_val = xmlTextWriterEndDocument(writer);
	DTS_CHECK_NE_MESSAGE("xmlTextWriterStartAttributeNS", (void *)ret_val, (void *)-1, "xmlTextWriterEndDocument Failed");

	xmlFreeTextWriter(writer);
	/**
	 * @post	1) Close the Document. \n
	 * 			2) Free xmlNewTextWriter pointer. \n
	 */
	xmlResetLastError();
}

static void
UTcXmlTextWriterEndAttributeP01()
{
	int ret_val;
	xmlTextWriterPtr writer; /* the xmlTextWriterPtr*/
	xmlChar *tmp;
	/**
	 * @pre		1) Create a new File.\n
	 * 			2) Start a Document.\n
	 * 			3) Write a Element and Attribute. \n
	 */
	writer = xmlNewTextWriterFilename(OUTFILE1, 0);
	DTS_CHECK_NE_MESSAGE("xmlTextWriterEndAttribute", (void *)writer, (void *)NULL, "xmlNewTextWriterFilename Failed");

	ret_val = xmlTextWriterStartDocument(writer, NULL, MY_ENCODING, NULL);
	DTS_CHECK_EQ_MESSAGE("xmlTextWriterEndAttribute", (void *)ret_val, (void *)0, "xmlTextWriterStartDocument Failed");

	ret_val = xmlTextWriterStartElement(writer, BAD_CAST "EXAMPLE");
	DTS_CHECK_EQ_MESSAGE("xmlTextWriterEndAttribute", (void *)ret_val, (void *)0, "xmlTextWriterStartElement Failed");

	tmp = ConvertInput("This is a comment with special chars: <äö?",MY_ENCODING);
	ret_val = xmlTextWriterWriteComment(writer, tmp);
	DTS_CHECK_EQ_MESSAGE("xmlTextWriterEndAttribute", (void *)ret_val, (void *)0, "xmlTextWriterWriteComment Failed");
	
	if (tmp != NULL) 
		xmlFree(tmp);

	ret_val = xmlTextWriterStartElement(writer, BAD_CAST "ORDER");
	DTS_CHECK_EQ_MESSAGE("xmlTextWriterEndAttribute", (void *)ret_val, (void *)0, "xmlTextWriterStartElement Failed");

	ret_val = xmlTextWriterStartAttribute(writer ,BAD_CAST "X_ORDER_ID");
	DTS_CHECK_EQ_MESSAGE("xmlTextWriterEndAttribute", (void *)ret_val, (void *)0, "xmlTextWriterStartAttribute Failed");

	/**
	 * @remarks   input1: [N/A, N/A] @n
	 *            { xmlTextWriterPtr pointer}
	 *             => { N/A | int } @n
	 */
	ret_val = xmlTextWriterEndAttribute(writer);
	DTS_CHECK_EQ_MESSAGE("xmlTextWriterEndAttribute", (void *)ret_val, (void *)0, "xmlTextWriterEndAttribute Failed");

	ret_val = xmlTextWriterEndElement(writer);
	DTS_CHECK_EQ_MESSAGE("xmlTextWriterEndAttribute", (void *)ret_val, (void *)0, "xmlTextWriterEndElement Failed");

	xmlFreeTextWriter(writer);
	/**
	 * @post	1) Free xmlNewTextWriter pointer. \n
	 */
	xmlResetLastError();
}
static void
UTcXmlTextWriterStartPIP01()
{
	 int ret_val;
	 xmlTextWriterPtr writer; /* the xmlTextWriterPtr */
	 int n_writer;
	 xmlChar * target; /* PI target */
	 int n_target;

	 for (n_writer = 0;n_writer < gen_nb_xmlTextWriterPtr;n_writer++) {
		 for (n_target = 0;n_target < gen_nb_const_xmlChar_ptr;n_target++) {
			 writer = gen_xmlTextWriterPtr(n_writer, 0);
			DTS_CHECK_NE_MESSAGE("xmlTextWriterStartPI", (void *)writer, (void *)NULL, "gen_xmlTextWriterPtr Failed");

			 target = gen_const_xmlChar_ptr(n_target, 1);
			DTS_CHECK_NE_MESSAGE("xmlTextWriterStartPI", (void *)target, (void *)NULL, "gen_const_xmlChar_ptr Failed");
			
			 /**
			 * @remarks   input1: [N/A, N/A] @n
			 *            { xmlTextWriterPtr pointer ,xmlChar pointer} => { N/A | int } @n
			 */
			 ret_val = xmlTextWriterStartPI(writer, (const xmlChar *)target);
			DTS_CHECK_EQ_MESSAGE("xmlTextWriterStartPI", (void *)ret_val, (void *)0, "xmlTextWriterStartPI Failed");
			
			 desret_int(ret_val);
			 des_xmlTextWriterPtr(n_writer, writer, 0);
			 des_const_xmlChar_ptr(n_target, (const xmlChar *)target, 1);
			 xmlResetLastError();
		 }
	 }
}

static void
UTcXmlTextWriterEndPIP01()
{
	int ret_val;
	xmlTextWriterPtr writer; /* the xmlTextWriterPtr */
	int n_writer;

	for (n_writer = 0;n_writer < gen_nb_xmlTextWriterPtr;n_writer++) {
		writer = gen_xmlTextWriterPtr(n_writer, 0);
		DTS_CHECK_NE_MESSAGE("xmlTextWriterEndPI", (void *)writer, (void *)NULL, "gen_xmlTextWriterPtr Failed");
		/**
		 * @remarks   input1: [N/A, N/A] @n
		 *            { xmlTextWriterPtr pointer} => { N/A | int } @n
		 */
		ret_val = xmlTextWriterEndPI(writer);
		DTS_CHECK_EQ_MESSAGE("xmlTextWriterEndPI", (void *)ret_val, (void *)0, "xmlTextWriterEndPI Failed");
		
		desret_int(ret_val);
		des_xmlTextWriterPtr(n_writer, writer, 0);
		xmlResetLastError();
	}
}

static void
UTcXmlTextWriterStartCDATAP01()
{
	int ret_val;
	xmlTextWriterPtr writer; /* the xmlTextWriterPtr */
	int n_writer;

	for (n_writer = 0;n_writer < gen_nb_xmlTextWriterPtr;n_writer++) {
		writer = gen_xmlTextWriterPtr(n_writer, 0);
		DTS_CHECK_NE_MESSAGE("xmlTextWriterStartCDATA", (void *)writer, (void *)NULL, "gen_xmlTextWriterPtr Failed");
		/**
		 * @remarks   input1: [N/A, N/A] @n
		 *            { xmlTextWriterPtr pointer} => { N/A | int } @n
		 */
		ret_val = xmlTextWriterStartCDATA(writer);
		DTS_CHECK_EQ_MESSAGE("xmlTextWriterStartCDATA", (void *)ret_val, (void *)0, "xmlTextWriterStartCDATA Failed");
		
		desret_int(ret_val);
		des_xmlTextWriterPtr(n_writer, writer, 0);
		xmlResetLastError();
	}
}

static void
UTcXmlTextWriterEndCDATAP01()
{
	int ret_val;
	xmlTextWriterPtr writer; /* the xmlTextWriterPtr */
	xmlDocPtr doc;
	/**
	 * @pre		1) Create a new Document.\n
	 * 			2) Start a Document.\n
	 * 			3) Write CDATA. \n
	 */
	writer = xmlNewTextWriterDoc(&doc, 0);
	DTS_CHECK_NE_MESSAGE("xmlTextWriterEndCDATA", (void *)writer, (void *)NULL, "xmlNewTextWriterDoc Failed");

	ret_val = xmlTextWriterStartDocument(writer, NULL, NULL, NULL);
	DTS_CHECK_EQ_MESSAGE("xmlTextWriterEndCDATA", (void *)ret_val, (void *)0, "xmlTextWriterStartDocument Failed");

	ret_val = xmlTextWriterStartCDATA(writer);
	DTS_CHECK_EQ_MESSAGE("xmlTextWriterEndCDATA", (void *)ret_val, (void *)0, "xmlTextWriterStartCDATA Failed");
	/**
	 * @remarks   input1: [N/A, N/A] @n
	 *            { xmlTextWriterPtr pointer} => { N/A | int } @n
	 */
	ret_val = xmlTextWriterEndCDATA(writer);
	DTS_CHECK_EQ_MESSAGE("xmlTextWriterEndCDATA", (void *)ret_val, (void *)0, "xmlTextWriterStartDocument Failed");

	/**
	 * @post	1) Close the Document. \n
	 * 			2) Free xmlNewTextWriter pointer. \n
	 */
	xmlTextWriterEndDocument(writer);
	xmlFreeTextWriter(writer);
	xmlResetLastError();
}


static void
UTcXmlTextWriterStartDTDP01()
{
	int ret_val;
	xmlTextWriterPtr writer; /* the xmlTextWriterPtr */
	int n_writer;
	xmlChar * name; /* the name of the DTD */
	int n_name;
	xmlChar * pubid; /* the public identifier, which is an alternative to the system identifier */
	int n_pubid;
	xmlChar * sysid; /* the system identifier, which is the URI of the DTD */
	int n_sysid;

	for (n_writer = 0;n_writer < gen_nb_xmlTextWriterPtr;n_writer++) {
		for (n_name = 0;n_name < gen_nb_const_xmlChar_ptr;n_name++) {
			for (n_pubid = 0;n_pubid < gen_nb_const_xmlChar_ptr;n_pubid++) {
				for (n_sysid = 0;n_sysid < gen_nb_const_xmlChar_ptr;n_sysid++) {
					writer = gen_xmlTextWriterPtr(n_writer, 0);
					DTS_CHECK_NE_MESSAGE("xmlTextWriterStartDTD", (void *)writer, (void *)NULL, "gen_xmlTextWriterPtr Failed");
					
					name = gen_const_xmlChar_ptr(n_name, 1);
					DTS_CHECK_NE_MESSAGE("xmlTextWriterStartDTD", (void *)name, (void *)NULL, "gen_const_xmlChar_ptr Failed");
					
					pubid = gen_const_xmlChar_ptr(n_pubid, 2);
					DTS_CHECK_NE_MESSAGE("xmlTextWriterStartDTD", (void *)pubid, (void *)NULL, "gen_const_xmlChar_ptr Failed");
					
					sysid = gen_const_xmlChar_ptr(n_sysid, 3);
					DTS_CHECK_NE_MESSAGE("xmlTextWriterStartDTD", (void *)sysid, (void *)NULL, "gen_const_xmlChar_ptr Failed");
					
					/**
					 * @remarks   input1: [N/A, N/A] @n
					 *            { xmlTextWriterPtr pointer ,xmlChar pointer ,xmlChar pointer ,xmlChar pointer}
					 *             => { N/A | int } @n
					 */
					ret_val = xmlTextWriterStartDTD(writer, (const xmlChar *)name, (const xmlChar *)pubid, (const xmlChar *)sysid);
					DTS_CHECK_EQ_MESSAGE("xmlTextWriterStartDTD", (void *)ret_val, (void *)0, "xmlTextWriterStartDTD Failed");
					
					desret_int(ret_val);
					des_xmlTextWriterPtr(n_writer, writer, 0);
					des_const_xmlChar_ptr(n_name, (const xmlChar *)name, 1);
					des_const_xmlChar_ptr(n_pubid, (const xmlChar *)pubid, 2);
					des_const_xmlChar_ptr(n_sysid, (const xmlChar *)sysid, 3);
					xmlResetLastError();
				}
			}
		}
	}
}

static void
UTcXmlTextWriterEndDTDP01()
{
	int ret_val;
	xmlTextWriterPtr writer; /* the xmlTextWriterPtr */
	int n_writer;

	for (n_writer = 0;n_writer < gen_nb_xmlTextWriterPtr;n_writer++) {
		writer = gen_xmlTextWriterPtr(n_writer, 0);
		DTS_CHECK_NE_MESSAGE("xmlTextWriterEndDTD", (void *)writer, (void *)NULL, "gen_xmlTextWriterPtr Failed");
					
		/**
		 * @remarks   input1: [N/A, N/A] @n
		 *            { xmlTextWriterPtr pointer ,xmlChar pointer ,xmlChar pointer ,xmlChar pointer}
		 *             => { N/A | int } @n
		 */
		ret_val = xmlTextWriterEndDTD(writer);
		DTS_CHECK_EQ_MESSAGE("xmlTextWriterEndDTD", (void *)ret_val, (void *)NULL, "xmlTextWriterEndDTD Failed");
		
		desret_int(ret_val);
		des_xmlTextWriterPtr(n_writer, writer, 0);
		xmlResetLastError();
	}
}

static void
UTcXmlTextWriterStartDTDElementP01()
{
	int ret_val;
	xmlTextWriterPtr writer; /* the xmlTextWriterPtr */
	int n_writer;
	xmlChar * name; /* the name of the DTD element */
	int n_name;

	for (n_writer = 0;n_writer < gen_nb_xmlTextWriterPtr;n_writer++) {
		for (n_name = 0;n_name < gen_nb_const_xmlChar_ptr;n_name++) {
			writer = gen_xmlTextWriterPtr(n_writer, 0);
			DTS_CHECK_NE_MESSAGE("xmlTextWriterStartDTDElement", (void *)writer, (void *)NULL, "gen_xmlTextWriterPtr Failed");

			name = gen_const_xmlChar_ptr(n_name, 1);
			DTS_CHECK_NE_MESSAGE("xmlTextWriterStartDTDElement", (void *)name, (void *)NULL, "gen_const_xmlChar_ptr Failed");
			/**
			 * @remarks   input1: [N/A, N/A] @n
			 *            { xmlTextWriterPtr pointer ,xmlChar pointer}
			 *             => { N/A | int } @n
			 */
			ret_val = xmlTextWriterStartDTDElement(writer, (const xmlChar *)name);
			DTS_CHECK_EQ_MESSAGE("xmlTextWriterStartDTDElement", (void *)ret_val, (void *)0, "xmlTextWriterStartDTDElement Failed");
			
			desret_int(ret_val);
			des_xmlTextWriterPtr(n_writer, writer, 0);
			des_const_xmlChar_ptr(n_name, (const xmlChar *)name, 1);
			xmlResetLastError();
		}
	}
}

static void
UTcXmlTextWriterEndDTDElementP01()
{
	int ret_val;
	xmlTextWriterPtr writer; /* the xmlTextWriterPtr */
	xmlDocPtr doc;
	/**
	 * @pre		1) Create a new Document.\n
	 * 			2) Start a Document.\n
	 * 			3) Write DTD Element. \n
	 */
	writer = xmlNewTextWriterDoc(&doc, 0);
	DTS_CHECK_NE_MESSAGE("xmlTextWriterEndDTDElement", (void *)writer, (void *)NULL, "xmlNewTextWriterDoc Failed");

	ret_val = xmlTextWriterStartDocument(writer, NULL, NULL, NULL);
	DTS_CHECK_EQ_MESSAGE("xmlTextWriterEndDTDElement", (void *)ret_val, (void *)0, "xmlTextWriterStartDocument Failed");

	ret_val = xmlTextWriterWriteDTD(writer, (xmlChar *)"fieldconf", NULL,(xmlChar *)UTSXMLHOME"/mfield.dtd", NULL);
	DTS_CHECK_EQ_MESSAGE("xmlTextWriterEndDTDElement", (void *)ret_val, (void *)0, "xmlTextWriterWriteDTD Failed");

	ret_val = xmlTextWriterStartDTDElement(writer, BAD_CAST "version");
	DTS_CHECK_EQ_MESSAGE("xmlTextWriterEndDTDElement", (void *)ret_val, (void *)0, "xmlTextWriterStartDTDElement Failed");

	/**
	 * @remarks   input1: [N/A, N/A] @n
	 *            { xmlTextWriterPtr pointer ,xmlChar pointer}
	 *             => { N/A | int } @n
	 */
	ret_val = xmlTextWriterEndDTDElement(writer);
	DTS_CHECK_EQ_MESSAGE("xmlTextWriterEndDTDElement", (void *)ret_val, (void *)0, "xmlTextWriterEndDTDElement Failed");

	/**
	 * @post	1) Close the Document. \n
	 * 			2) Free xmlNewTextWriter pointer. \n
	 */
	xmlTextWriterEndDocument(writer);
	xmlFreeTextWriter(writer);
	xmlResetLastError();
}


static void
UTcXmlTextWriterStartDTDAttlistP01()
{
	int ret_val;
	xmlTextWriterPtr writer; /* the xmlTextWriterPtr */
	int n_writer;
	xmlChar * name; /* the name of the DTD ATTLIST */
	int n_name;

	for (n_writer = 0;n_writer < gen_nb_xmlTextWriterPtr;n_writer++) {
		for (n_name = 0;n_name < gen_nb_const_xmlChar_ptr;n_name++) {
			writer = gen_xmlTextWriterPtr(n_writer, 0);
			DTS_CHECK_NE_MESSAGE("xmlTextWriterStartDTDAttlist", (void *)writer, (void *)NULL, "gen_xmlTextWriterPtr Failed");

			name = gen_const_xmlChar_ptr(n_name, 1);
			DTS_CHECK_NE_MESSAGE("xmlTextWriterStartDTDAttlist", (void *)name, (void *)NULL, "gen_const_xmlChar_ptr Failed");

			/**
			 * @remarks   input1: [N/A, N/A] @n
			 *            { xmlTextWriterPtr pointer ,xmlChar pointer}
			 *             => { N/A | int } @n
			 */
			ret_val = xmlTextWriterStartDTDAttlist(writer, (const xmlChar *)name);
			DTS_CHECK_EQ_MESSAGE("xmlTextWriterStartDTDAttlist", (void *)ret_val, (void *)0, "xmlTextWriterStartDTDAttlist Failed");
			
			desret_int(ret_val);
			des_xmlTextWriterPtr(n_writer, writer, 0);
			des_const_xmlChar_ptr(n_name, (const xmlChar *)name, 1);
			xmlResetLastError();
		}
	}
}

static void
UTcXmlTextWriterEndDTDAttlistP01()
{
	int ret_val;
	xmlTextWriterPtr writer; /* the xmlTextWriterPtr */
	xmlDocPtr doc;
	/**
	 * @pre		1) Create a new Document.\n
	 * 			2) Start a Document.\n
	 * 			3) Write DTD Attlist. \n
	 */
	writer = xmlNewTextWriterDoc(&doc, 0);
	DTS_CHECK_NE_MESSAGE("xmlTextWriterEndDTDAttlist", (void *)writer, (void *)NULL, "xmlNewTextWriterDoc Failed");

	ret_val = xmlTextWriterStartDocument(writer, NULL, NULL, NULL);
	DTS_CHECK_EQ_MESSAGE("xmlTextWriterEndDTDAttlist", (void *)ret_val, (void *)0, "xmlTextWriterStartDocument Failed");

	ret_val = xmlTextWriterStartDTDAttlist(writer ,BAD_CAST "version");
	DTS_CHECK_EQ_MESSAGE("xmlTextWriterEndDTDAttlist", (void *)ret_val, (void *)NULL, "xmlTextWriterStartDTDAttlist Failed");
	
	/**
	 * @remarks   input1: [N/A, N/A] @n
	 *            { xmlTextWriterPtr pointer}
	 *             => { N/A | int } @n
	 */
	ret_val = xmlTextWriterEndDTDAttlist(writer);
	DTS_CHECK_EQ_MESSAGE("xmlTextWriterEndDTDAttlist", (void *)ret_val, (void *)0, "xmlTextWriterEndDTDAttlist Failed");

	/**
	 * @post	1) Close the Document. \n
	 * 			2) Free xmlNewTextWriter pointer. \n
	 */
	xmlTextWriterEndDocument(writer);
	xmlFreeTextWriter(writer);
	xmlResetLastError();

}

static void
UTcXmlTextWriterStartDTDEntityP01()
{
	int ret_val;
	xmlTextWriterPtr writer; /* the xmlTextWriterPtr */
	int n_writer;
	int pe; /* TRUE if this is a parameter entity, FALSE if not */
	int n_pe;
	xmlChar * name; /* the name of the DTD ATTLIST */
	int n_name;

	for (n_writer = 0;n_writer < gen_nb_xmlTextWriterPtr;n_writer++) {
		for (n_pe = 0;n_pe < gen_nb_int;n_pe++) {
			for (n_name = 0;n_name < gen_nb_const_xmlChar_ptr;n_name++) {
				writer = gen_xmlTextWriterPtr(n_writer, 0);
				DTS_CHECK_NE_MESSAGE("xmlTextWriterStartDTDEntity", (void *)writer, (void *)NULL, "gen_xmlTextWriterPtr Failed");
				
				pe = gen_int(n_pe, 1);
				//MT_CHECK_MESSAGE2(0 != pe, "gen_int returned NULL");
				name = gen_const_xmlChar_ptr(n_name, 2);
				DTS_CHECK_NE_MESSAGE("xmlTextWriterStartDTDEntity", (void *)name, (void *)NULL, "gen_const_xmlChar_ptr Failed");
				
				/**
				 * @remarks   input1: [N/A, N/A] @n
				 *            { xmlTextWriterPtr pointer ,(0,1,-1,122) ,xmlChar pointer}
				 *             => { N/A | int } @n
				 */
				ret_val = xmlTextWriterStartDTDEntity(writer, pe, (const xmlChar *)name);
				DTS_CHECK_EQ_MESSAGE("xmlTextWriterStartDTDEntity", (void *)ret_val, (void *)0, "xmlTextWriterStartDTDEntity Failed");
				
				desret_int(ret_val);
				des_xmlTextWriterPtr(n_writer, writer, 0);
				des_int(n_pe, pe, 1);
				des_const_xmlChar_ptr(n_name, (const xmlChar *)name, 2);
				xmlResetLastError();
			}
		}
	}
}

static void
UTcXmlTextWriterEndDTDEntityP01()
{
	int ret_val;
	xmlTextWriterPtr writer; /* the xmlTextWriterPtr*/
//	xmlChar *tmp;
	xmlDocPtr doc;
	/**
	 * @pre		1) Create a new Document.\n
	 * 			2) Start a Document.\n
	 * 			3) Write DTD Entity. \n
	 */
	writer = xmlNewTextWriterDoc(&doc, 0);
	DTS_CHECK_NE_MESSAGE("xmlTextWriterEndDTDEntity", (void *)writer, (void *)NULL, "xmlNewTextWriterDoc Failed");

	ret_val = xmlTextWriterStartDocument(writer, NULL, NULL, NULL);
	DTS_CHECK_EQ_MESSAGE("xmlTextWriterEndDTDEntity", (void *)ret_val, (void *)0, "xmlTextWriterStartDocument Failed");

	ret_val = xmlTextWriterWriteDTD(writer, (xmlChar *)"fieldconf", NULL,(xmlChar *)UTSXMLHOME"/mfield.dtd", NULL);
	DTS_CHECK_EQ_MESSAGE("xmlTextWriterEndDTDEntity", (void *)ret_val, (void *)0, "xmlTextWriterWriteDTD Failed");

	ret_val = xmlTextWriterStartDTDEntity(writer, 1, BAD_CAST "version");
	DTS_CHECK_EQ_MESSAGE("xmlTextWriterEndDTDEntity", (void *)ret_val, (void *)0, "xmlTextWriterStartDTDEntity Failed");

	/**
	 * @remarks   input1: [N/A, N/A] @n
	 *            { xmlTextWriterPtr pointer"}
	 *             => { N/A | int } @n
	 */
	ret_val = xmlTextWriterEndDTDEntity(writer);
	DTS_CHECK_EQ_MESSAGE("xmlTextWriterEndDTDEntity", (void *)ret_val, (void *)0, "xmlTextWriterEndDTDEntity Failed");

	/**
	 * @post	1) Close the Document. \n
	 * 			2) Free xmlNewTextWriter pointer. \n
	 */
	xmlTextWriterEndDocument(writer);
	xmlFreeTextWriter(writer);
	xmlResetLastError();
}
static void
UTcXmlTextWriterWriteDTDNotationP01()
{
	int ret_val;
	xmlTextWriterPtr writer; /* the xmlTextWriterPtr */
	int n_writer;
	xmlChar * name; /* the name of the xml notation */
	int n_name;
	xmlChar * pubid; /* the public identifier, which is an alternative to the system identifier */
	int n_pubid;
	xmlChar * sysid; /* the system identifier, which is the URI of the DTD */
	int n_sysid;

	for (n_writer = 0;n_writer < gen_nb_xmlTextWriterPtr;n_writer++) {
		for (n_name = 0;n_name < gen_nb_const_xmlChar_ptr;n_name++) {
			for (n_pubid = 0;n_pubid < gen_nb_const_xmlChar_ptr;n_pubid++) {
				for (n_sysid = 0;n_sysid < gen_nb_const_xmlChar_ptr;n_sysid++) {
					writer = gen_xmlTextWriterPtr(n_writer, 0);
					DTS_CHECK_NE_MESSAGE("xmlTextWriterWriteDTDNotation", (void *)writer, (void *)NULL, "gen_xmlTextWriterPtr Failed");
					
					name = gen_const_xmlChar_ptr(n_name, 1);
					DTS_CHECK_NE_MESSAGE("xmlTextWriterWriteDTDNotation", (void *)name, (void *)NULL, "gen_const_xmlChar_ptr Failed");
					
					pubid = gen_const_xmlChar_ptr(n_pubid, 2);
					DTS_CHECK_NE_MESSAGE("xmlTextWriterWriteDTDNotation", (void *)pubid, (void *)NULL, "gen_const_xmlChar_ptr Failed");
					
					sysid = gen_const_xmlChar_ptr(n_sysid, 3);
					DTS_CHECK_NE_MESSAGE("xmlTextWriterWriteDTDNotation", (void *)sysid, (void *)NULL, "gen_const_xmlChar_ptr Failed");
					
					/**
					 * @remarks   input1: [N/A, N/A] @n
					 *            { xmlTextWriterPtr pointer ,xmlChar pointer ,xmlChar pointer ,xmlChar pointer}
					 *             => { N/A | int } @n
					 */
					ret_val = xmlTextWriterWriteDTDNotation(writer, (const xmlChar *)name, (const xmlChar *)pubid, (const xmlChar *)sysid);
					DTS_CHECK_EQ_MESSAGE("xmlTextWriterWriteDTDNotation", (void *)ret_val, (void *)0, "xmlTextWriterWriteDTDNotation Failed");
					
					desret_int(ret_val);
					des_xmlTextWriterPtr(n_writer, writer, 0);
					des_const_xmlChar_ptr(n_name, (const xmlChar *)name, 1);
					des_const_xmlChar_ptr(n_pubid, (const xmlChar *)pubid, 2);
					des_const_xmlChar_ptr(n_sysid, (const xmlChar *)sysid, 3);
					xmlResetLastError();
				}
			}
		}
	}
}

static void
UTcXmlTextWriterSetIndentP01()
{
	int ret_val;
	xmlTextWriterPtr writer; /* the xmlTextWriterPtr */
	int n_writer;
	int indent; /* do indentation? */
	int n_indent;

	for (n_writer = 0;n_writer < gen_nb_xmlTextWriterPtr;n_writer++) {
		for (n_indent = 0;n_indent < gen_nb_int;n_indent++) {
			writer = gen_xmlTextWriterPtr(n_writer, 0);
			DTS_CHECK_NE_MESSAGE("xmlTextWriterSetIndent", (void *)writer, (void *)NULL, "gen_xmlTextWriterPtr Failed");
			
			indent = gen_int(n_indent, 1);
			/**
			 * @remarks   input1: [N/A, N/A] @n
			 *            { xmlTextWriterPtr pointer ,(0,1,-1,122)} => { N/A | int } @n
			 */
			ret_val = xmlTextWriterSetIndent(writer, indent);
			DTS_CHECK_EQ_MESSAGE("xmlTextWriterSetIndent", (void *)ret_val, (void *)0, "xmlTextWriterSetIndent Failed");
			
			desret_int(ret_val);
			des_xmlTextWriterPtr(n_writer, writer, 0);
			des_int(n_indent, indent, 1);
			xmlResetLastError();
		}
	}
}

static void
UTcXmlTextWriterSetIndentStringP01()
{
	int ret_val;
	xmlTextWriterPtr writer; /* the xmlTextWriterPtr */
	int n_writer;
	xmlChar * str; /* the xmlChar string */
	int n_str;

	for (n_writer = 0;n_writer < gen_nb_xmlTextWriterPtr;n_writer++) {
		for (n_str = 0;n_str < gen_nb_const_xmlChar_ptr;n_str++) {
			writer = gen_xmlTextWriterPtr(n_writer, 0);
			DTS_CHECK_NE_MESSAGE("xmlTextWriterSetIndentString", (void *)writer, (void *)NULL, "gen_xmlTextWriterPtr Failed");
			
			str = gen_const_xmlChar_ptr(n_str, 1);
			DTS_CHECK_NE_MESSAGE("xmlTextWriterSetIndentString", (void *)str, (void *)NULL, "gen_const_xmlChar_ptr Failed");
			
			/**
			 * @remarks   input1: [N/A, N/A] @n
			 *            { xmlTextWriterPtr pointer ,xmlChar pointer} => { N/A | int } @n
			 */
			ret_val = xmlTextWriterSetIndentString(writer, (const xmlChar *)str);
			DTS_CHECK_EQ_MESSAGE("xmlTextWriterSetIndentString", (void *)ret_val, (void *)0, "xmlTextWriterSetIndentString Failed");
			
			desret_int(ret_val);
			des_xmlTextWriterPtr(n_writer, writer, 0);
			des_const_xmlChar_ptr(n_str, (const xmlChar *)str, 1);
			xmlResetLastError();
		}
	}
}

static void
UTcXmlTextWriterFlushP01()
{
	int ret_val;
	xmlTextWriterPtr writer; /* the xmlTextWriterPtr */
	int n_writer;

	for (n_writer = 0;n_writer < gen_nb_xmlTextWriterPtr;n_writer++) {
		writer = gen_xmlTextWriterPtr(n_writer, 0);
		DTS_CHECK_NE_MESSAGE("xmlTextWriterFlush", (void *)writer, (void *)NULL, "gen_xmlTextWriterPtr Failed");
			
		/**
		 * @remarks   input1: [N/A, N/A] @n
		 *            { xmlTextWriterPtr pointer} => { N/A | int } @n
		 */
		ret_val = xmlTextWriterFlush(writer);
		DTS_CHECK_EQ_MESSAGE("xmlTextWriterFlush", (void *)ret_val, (void *)0, "xmlTextWriterFlush Failed");
		
		desret_int(ret_val);
		des_xmlTextWriterPtr(n_writer, writer, 0);
		xmlResetLastError();
	}
}

static void
UTcXmlTextWriterWriteElementP01()
{
	int ret_val;
	xmlTextWriterPtr writer; /* the xmlTextWriterPtr */
	int n_writer;
	xmlChar * name; /* element name */
	int n_name;
	xmlChar * content; /* element content */
	int n_content;

	for (n_writer = 0;n_writer < gen_nb_xmlTextWriterPtr;n_writer++) {
		for (n_name = 0;n_name < gen_nb_const_xmlChar_ptr;n_name++) {
			for (n_content = 0;n_content < gen_nb_const_xmlChar_ptr;n_content++) {
				writer = gen_xmlTextWriterPtr(n_writer, 0);
				DTS_CHECK_NE_MESSAGE("xmlTextWriterWriteElement", (void *)writer, (void *)NULL, "gen_xmlTextWriterPtr Failed");

				name = gen_const_xmlChar_ptr(n_name, 1);
				DTS_CHECK_NE_MESSAGE("xmlTextWriterWriteElement", (void *)name, (void *)NULL, "gen_const_xmlChar_ptr Failed");
				
				content = gen_const_xmlChar_ptr(n_content, 2);
				DTS_CHECK_NE_MESSAGE("xmlTextWriterWriteElement", (void *)content, (void *)NULL, "gen_const_xmlChar_ptr Failed");
				
				/**
				 * @remarks   input1: [N/A, N/A] @n
				 *            { xmlTextWriterPtr pointer ,xmlChar pointer ,xmlChar pointer}
				 *             => { N/A | int } @n
				 */
				ret_val = xmlTextWriterWriteElement(writer, (const xmlChar *)name, (const xmlChar *)content);
				DTS_CHECK_EQ_MESSAGE("xmlTextWriterWriteElement", (void *)ret_val, (void *)0, "xmlTextWriterWriteElement Failed");
				
				desret_int(ret_val);
				des_xmlTextWriterPtr(n_writer, writer, 0);
				des_const_xmlChar_ptr(n_name, (const xmlChar *)name, 1);
				des_const_xmlChar_ptr(n_content, (const xmlChar *)content, 2);
				xmlResetLastError();
			}
		}
	}
}

static void
UTcXmlTextWriterWriteElementNSP01()
{
	int ret_val;
	xmlTextWriterPtr writer; /* the xmlTextWriterPtr */
	int n_writer;
	xmlChar * prefix; /* namespace prefix */
	int n_prefix;
	xmlChar * name; /* element local name */
	int n_name;
	xmlChar * namespaceURI; /* namespace URI */
	int n_namespaceURI;
	xmlChar * content; /* element content */
	int n_content;

	for (n_writer = 0;n_writer < gen_nb_xmlTextWriterPtr;n_writer++) {
		for (n_prefix = 0;n_prefix < gen_nb_const_xmlChar_ptr;n_prefix++) {
			for (n_name = 0;n_name < gen_nb_const_xmlChar_ptr;n_name++) {
				for (n_namespaceURI = 0;n_namespaceURI < gen_nb_const_xmlChar_ptr;n_namespaceURI++) {
					for (n_content = 0;n_content < gen_nb_const_xmlChar_ptr;n_content++) {
						writer = gen_xmlTextWriterPtr(n_writer, 0);
						DTS_CHECK_NE_MESSAGE("xmlTextWriterWriteElementNS", (void *)writer, (void *)NULL, "gen_xmlTextWriterPtr Failed");
				
						prefix = gen_const_xmlChar_ptr(n_prefix, 1);
						DTS_CHECK_NE_MESSAGE("xmlTextWriterWriteElementNS", (void *)prefix, (void *)NULL, "gen_const_xmlChar_ptr Failed");
						
						name = gen_const_xmlChar_ptr(n_name, 2);
						DTS_CHECK_NE_MESSAGE("xmlTextWriterWriteElementNS", (void *)name, (void *)NULL, "gen_const_xmlChar_ptr Failed");
						
						namespaceURI = gen_const_xmlChar_ptr(n_namespaceURI, 3);
						DTS_CHECK_NE_MESSAGE("xmlTextWriterWriteElementNS", (void *)namespaceURI, (void *)NULL, "gen_const_xmlChar_ptr Failed");
						
						content = gen_const_xmlChar_ptr(n_content, 4);
						DTS_CHECK_NE_MESSAGE("xmlTextWriterWriteElementNS", (void *)content, (void *)NULL, "gen_const_xmlChar_ptr Failed");
						
						/**
						 * @remarks   input1: [N/A, N/A] @n
						 *            { xmlTextWriterPtr pointer ,xmlChar pointer ,xmlChar pointer ,xmlChar pointer ,xmlChar pointer}
						 *             => { N/A | int } @n
						 */
						ret_val = xmlTextWriterWriteElementNS(writer, (const xmlChar *)prefix, (const xmlChar *)name, (const xmlChar *)namespaceURI, (const xmlChar *)content);
						DTS_CHECK_EQ_MESSAGE("xmlTextWriterWriteElementNS", (void *)ret_val, (void *)0, "xmlTextWriterWriteElementNS Failed");
						
						desret_int(ret_val);
						des_xmlTextWriterPtr(n_writer, writer, 0);
						des_const_xmlChar_ptr(n_prefix, (const xmlChar *)prefix, 1);
						des_const_xmlChar_ptr(n_name, (const xmlChar *)name, 2);
						des_const_xmlChar_ptr(n_namespaceURI, (const xmlChar *)namespaceURI, 3);
						des_const_xmlChar_ptr(n_content, (const xmlChar *)content, 4);
						xmlResetLastError();
					}
				}
			}
		}
	}
}

static void
UTcXmlTextWriterWriteRawLenP01()
{
	int ret_val;
	xmlTextWriterPtr writer; /* the xmlTextWriterPtr */
	int n_writer;
	xmlChar * content; /* text string */
	int n_content;
	int len; /* length of the text string */
	int n_len;

	for (n_writer = 0;n_writer < gen_nb_xmlTextWriterPtr;n_writer++) {
		for (n_content = 0;n_content < gen_nb_const_xmlChar_ptr;n_content++) {
			for (n_len = 0;n_len < gen_nb_int;n_len++) {
				writer = gen_xmlTextWriterPtr(n_writer, 0);
				DTS_CHECK_NE_MESSAGE("xmlTextWriterWriteRawLen", (void *)writer, (void *)NULL, "gen_xmlTextWriterPtr Failed");
						
				content = gen_const_xmlChar_ptr(n_content, 1);
				DTS_CHECK_NE_MESSAGE("xmlTextWriterWriteRawLen", (void *)content, (void *)NULL, "gen_const_xmlChar_ptr Failed");
				
				len = gen_int(n_len, 2);
				//MT_CHECK_MESSAGE2(0 != len, "gen_int returned NULL");
				/**
				 * @remarks   input1: [N/A, N/A] @n
				 *            { xmlTextWriterPtr pointer ,xmlChar pointer ,(0,1,-1,122)}
				 *            => { N/A | int } @n
				 */
				ret_val = xmlTextWriterWriteRawLen(writer, (const xmlChar *)content, len);
				DTS_CHECK_EQ_MESSAGE("xmlTextWriterWriteRawLen", (void *)ret_val, (void *)0, "xmlTextWriterWriteRawLen Failed");
				
				desret_int(ret_val);
				des_xmlTextWriterPtr(n_writer, writer, 0);
				des_const_xmlChar_ptr(n_content, (const xmlChar *)content, 1);
				des_int(n_len, len, 2);
				xmlResetLastError();
			}
		}
	}
}

static void
UTcXmlTextWriterWriteRawP01()
{
	int ret_val;
	xmlTextWriterPtr writer; /* the xmlTextWriterPtr */
	int n_writer;
	xmlChar * content; /* text string */
	int n_content;

	for (n_writer = 0;n_writer < gen_nb_xmlTextWriterPtr;n_writer++) {
		for (n_content = 0;n_content < gen_nb_const_xmlChar_ptr;n_content++) {
			writer = gen_xmlTextWriterPtr(n_writer, 0);
			DTS_CHECK_NE_MESSAGE("xmlTextWriterWriteRaw", (void *)writer, (void *)NULL, "gen_xmlTextWriterPtr Failed");
				
			content = gen_const_xmlChar_ptr(n_content, 1);
			DTS_CHECK_NE_MESSAGE("xmlTextWriterWriteRaw", (void *)content, (void *)NULL, "gen_const_xmlChar_ptr Failed");
			
			/**
			 * @remarks   input1: [N/A, N/A] @n
			 *            { xmlTextWriterPtr pointer ,xmlChar pointer}
			 *            => { N/A | int } @n
			 */
			ret_val = xmlTextWriterWriteRaw(writer, (const xmlChar *)content);
			DTS_CHECK_EQ_MESSAGE("xmlTextWriterWriteRaw", (void *)ret_val, (void *)0, "xmlTextWriterWriteRaw Failed");
			
			desret_int(ret_val);
			des_xmlTextWriterPtr(n_writer, writer, 0);
			des_const_xmlChar_ptr(n_content, (const xmlChar *)content, 1);
			xmlResetLastError();
		}
	}
}


static void
UTcXmlTextWriterWriteStringP01()
{
	int ret_val;
	xmlTextWriterPtr writer; /* the xmlTextWriterPtr */
	int n_writer;
	xmlChar * content; /* text string */
	int n_content;

	for (n_writer = 0;n_writer < gen_nb_xmlTextWriterPtr;n_writer++) {
		for (n_content = 0;n_content < gen_nb_const_xmlChar_ptr;n_content++) {
			writer = gen_xmlTextWriterPtr(n_writer, 0);
			DTS_CHECK_NE_MESSAGE("xmlTextWriterWriteString", (void *)writer, (void *)NULL, "gen_xmlTextWriterPtr Failed");
			
			content = gen_const_xmlChar_ptr(n_content, 1);
			DTS_CHECK_NE_MESSAGE("xmlTextWriterWriteString", (void *)content, (void *)NULL, "gen_const_xmlChar_ptr Failed");
			
			/**
			 * @remarks   input1: [N/A, N/A] @n
			 *            { xmlTextWriterPtr pointer ,xmlChar pointer}
			 *            => { N/A | int } @n
			 */
			ret_val = xmlTextWriterWriteString(writer, (const xmlChar *)content);
			DTS_CHECK_EQ_MESSAGE("xmlTextWriterWriteString", (void *)ret_val, (void *)NULL, "xmlTextWriterWriteString Failed");
			
			desret_int(ret_val);
			des_xmlTextWriterPtr(n_writer, writer, 0);
			des_const_xmlChar_ptr(n_content, (const xmlChar *)content, 1);
			xmlResetLastError();
		}
	}
}

static void
UTcXmlTextWriterWriteBase64P01()
{
	int ret_val;
	xmlTextWriterPtr writer; /* the xmlTextWriterPtr */
	int n_writer;
	char * data; /* binary data */
	int n_data;
	int start; /* the position within the data of the first byte to encode */
	int n_start;
	int len; /* the number of bytes to encode */
	int n_len;

	for (n_writer = 0;n_writer < gen_nb_xmlTextWriterPtr;n_writer++) {
		for (n_data = 0;n_data < gen_nb_const_char_ptr;n_data++) {
			for (n_start = 0;n_start < gen_nb_int;n_start++) {
				for (n_len = 0;n_len < gen_nb_int;n_len++) {
					writer = gen_xmlTextWriterPtr(n_writer, 0);
					DTS_CHECK_NE_MESSAGE("xmlTextWriterWriteBase64", (void *)writer, (void *)NULL, "gen_xmlTextWriterPtr Failed");
			
					data = gen_const_char_ptr(n_data, 1);
					DTS_CHECK_NE_MESSAGE("xmlTextWriterWriteBase64", (void *)data, (void *)NULL, "gen_const_char_ptr Failed");
			
					start = gen_int(n_start, 2);
					//MT_CHECK_MESSAGE2(0 != start, "gen_int returned NULL");
					len = gen_int(n_len, 3);
					//MT_CHECK_MESSAGE2(0 != len, "gen_int returned NULL");
					/**
					 * @remarks   input1: [N/A, N/A] @n
					 *            { xmlTextWriterPtr pointer ,("foo",<foo/>","test/ent2") ,(0,1,-1,122) ,(0,1,-1,122)}
					 *             => { N/A | int } @n
					 */
					ret_val = xmlTextWriterWriteBase64(writer, (const char *)data, start, len);
					DTS_CHECK_EQ_MESSAGE("xmlTextWriterWriteBase64", (void *)ret_val, (void *)0, "xmlTextWriterWriteBase64 Failed");
					
					desret_int(ret_val);
					des_xmlTextWriterPtr(n_writer, writer, 0);
					des_const_char_ptr(n_data, (const char *)data, 1);
					des_int(n_start, start, 2);
					des_int(n_len, len, 3);
					xmlResetLastError();
				}
			}
		}
	}
}

static void
UTcXmlTextWriterWriteBinHexP01()
{
	int ret_val;
	xmlTextWriterPtr writer; /* the xmlTextWriterPtr */
	int n_writer;
	char * data; /* binary data */
	int n_data;
	int start; /* the position within the data of the first byte to encode */
	int n_start;
	int len; /* the number of bytes to encode */
	int n_len;

	for (n_writer = 0;n_writer < gen_nb_xmlTextWriterPtr;n_writer++) {
		for (n_data = 0;n_data < gen_nb_const_char_ptr;n_data++) {
			for (n_start = 0;n_start < gen_nb_int;n_start++) {
				for (n_len = 0;n_len < gen_nb_int;n_len++) {
					writer = gen_xmlTextWriterPtr(n_writer, 0);
					DTS_CHECK_NE_MESSAGE("xmlTextWriterWriteBinHex", (void *)writer, (void *)NULL, "gen_xmlTextWriterPtr Failed");
					
					data = gen_const_char_ptr(n_data, 1);
					DTS_CHECK_NE_MESSAGE("xmlTextWriterWriteBinHex", (void *)data, (void *)NULL, "gen_const_char_ptr Failed");
					
					start = gen_int(n_start, 2);
					//MT_CHECK_MESSAGE2(0 != start, "gen_int returned NULL");
					len = gen_int(n_len, 3);
					//MT_CHECK_MESSAGE2(0 != len, "gen_int returned NULL");
					/**
					 * @remarks   input1: [N/A, N/A] @n
					 *            { xmlTextWriterPtr pointer ,("foo",<foo/>","test/ent2") ,(0,1,-1,122) ,(0,1,-1,122)}
					 *             => { N/A | int } @n
					 */
					ret_val = xmlTextWriterWriteBinHex(writer, (const char *)data, start, len);
					DTS_CHECK_EQ_MESSAGE("xmlTextWriterWriteBinHex", (void *)ret_val, (void *)0, "xmlTextWriterWriteBinHex Failed");
					
					desret_int(ret_val);
					des_xmlTextWriterPtr(n_writer, writer, 0);
					des_const_char_ptr(n_data, (const char *)data, 1);
					des_int(n_start, start, 2);
					des_int(n_len, len, 3);
					xmlResetLastError();
				}
			}
		}
	}
}

static void
UTcXmlTextWriterWriteAttributeP01()
{
	int ret_val;
	xmlTextWriterPtr writer; /* the xmlTextWriterPtr */
	xmlChar *tmp;
	/**
	 * @pre		1) Create a new Document.\n
	 * 			2) Start a Document.\n
	 * 			3) Write Element. \n
	 */
	writer = xmlNewTextWriterFilename(OUTFILE1, 0);
	DTS_CHECK_NE_MESSAGE("xmlTextWriterWriteAttribute", (void *)writer, (void *)NULL, "xmlNewTextWriterFilename Failed");

	ret_val = xmlTextWriterStartDocument(writer, NULL, MY_ENCODING, NULL);
	DTS_CHECK_EQ_MESSAGE("xmlTextWriterWriteAttribute", (void *)ret_val, (void *)0, "xmlTextWriterStartDocument Failed");

	ret_val = xmlTextWriterStartElement(writer, BAD_CAST "EXAMPLE");
	DTS_CHECK_EQ_MESSAGE("xmlTextWriterWriteAttribute", (void *)ret_val, (void *)0, "xmlTextWriterStartElement Failed");

	tmp = ConvertInput("This is a comment with special chars: <äö?",MY_ENCODING);
	ret_val = xmlTextWriterWriteComment(writer, tmp);
	DTS_CHECK_EQ_MESSAGE("xmlTextWriterWriteAttribute", (void *)ret_val, (void *)0, "xmlTextWriterWriteComment Failed");
	
	if (tmp != NULL) xmlFree(tmp);

	ret_val = xmlTextWriterStartElement(writer, BAD_CAST "ORDER");
	DTS_CHECK_EQ_MESSAGE("xmlTextWriterWriteAttribute", (void *)ret_val, (void *)0, "xmlTextWriterStartElement Failed");

	/**
	* @remarks   input1: [N/A, N/A] @n
	*            { xmlTextWriterPtr pointer ,BAD_CAST "X_ORDER_ID", xmlChar pointer } => { N/A | int } @n
	*/
	ret_val = xmlTextWriterWriteAttribute(writer, BAD_CAST "version",BAD_CAST "1.0");
	DTS_CHECK_EQ_MESSAGE("xmlTextWriterWriteAttribute", (void *)ret_val, (void *)0, "xmlTextWriterWriteAttribute Failed");

	ret_val = xmlTextWriterEndElement(writer);
	DTS_CHECK_EQ_MESSAGE("xmlTextWriterWriteAttribute", (void *)ret_val, (void *)0, "xmlTextWriterEndElement Failed");

	ret_val = xmlTextWriterEndDocument(writer);
	DTS_CHECK_NE_MESSAGE("xmlTextWriterWriteAttribute", (void *)ret_val, (void *)-1, "xmlTextWriterEndDocument Failed");
	/**
	 * @post 1) Close the Document. \n
	 *       2) Free  xmlTextWriter pointer. \n
	 */
	xmlFreeTextWriter(writer);
	xmlResetLastError();
}

static void
UTcXmlTextWriterWriteAttributeNSP01()
{
	int ret_val;
	xmlTextWriterPtr writer; /* the xmlTextWriterPtr*/
	xmlChar *tmp;
	/**
	 * @pre		1) Create a new Document.\n
	 * 			2) Start a Document.\n
	 * 			3) Write Element. \n
	 */

	writer = xmlNewTextWriterFilename(OUTFILE1, 0);
	DTS_CHECK_NE_MESSAGE("xmlTextWriterWriteAttributeNS", (void *)writer, (void *)NULL, "xmlNewTextWriterFilename Failed");

	ret_val = xmlTextWriterStartDocument(writer, NULL, MY_ENCODING, NULL);
	DTS_CHECK_EQ_MESSAGE("xmlTextWriterWriteAttributeNS", (void *)ret_val, (void *)0, "xmlTextWriterStartDocument Failed");

	ret_val = xmlTextWriterStartElement(writer, BAD_CAST "EXAMPLE");
	DTS_CHECK_EQ_MESSAGE("xmlTextWriterWriteAttributeNS", (void *)ret_val, (void *)0, "xmlTextWriterStartElement Failed");

	tmp = ConvertInput("This is a comment with special chars: <äö?",MY_ENCODING);
	ret_val = xmlTextWriterWriteComment(writer, tmp);
	DTS_CHECK_EQ_MESSAGE("xmlTextWriterWriteAttributeNS", (void *)ret_val, (void *)0, "xmlTextWriterWriteComment Failed");
	
	if (tmp != NULL) 
		xmlFree(tmp);

	ret_val = xmlTextWriterStartElement(writer, BAD_CAST "ORDER");
	DTS_CHECK_EQ_MESSAGE("xmlTextWriterWriteAttributeNS", (void *)ret_val, (void *)0, "xmlTextWriterStartElement Failed");

	ret_val = xmlTextWriterWriteAttributeNS(writer, NULL, BAD_CAST "version", NULL , BAD_CAST "1.0");
	DTS_CHECK_EQ_MESSAGE("xmlTextWriterWriteAttributeNS", (void *)ret_val, (void *)0, "xmlTextWriterWriteAttributeNS Failed");

	ret_val = xmlTextWriterEndElement(writer);
	DTS_CHECK_EQ_MESSAGE("xmlTextWriterWriteAttributeNS", (void *)ret_val, (void *)0, "xmlTextWriterEndElement Failed");

	ret_val = xmlTextWriterEndDocument(writer);
	DTS_CHECK_NE_MESSAGE("xmlTextWriterWriteAttributeNS", (void *)ret_val, (void *)-1, "xmlTextWriterEndDocument Failed");

	/**
	 * @post 1) Close the Document. \n
	 *       2) Free  xmlTextWriter pointer. \n
	 */
	xmlFreeTextWriter(writer);
	xmlResetLastError();
}

static void
UTcXmlTextWriterWritePIP01()
{
    int ret_val;
    xmlTextWriterPtr writer; /* the xmlTextWriterPtr */
    int n_writer;
    xmlChar * target; /* PI target */
    int n_target;
    xmlChar * content; /* PI content */
    int n_content;

    for (n_writer = 0;n_writer < gen_nb_xmlTextWriterPtr;n_writer++) {
		for (n_target = 0;n_target < gen_nb_const_xmlChar_ptr;n_target++) {
			for (n_content = 0;n_content < gen_nb_const_xmlChar_ptr;n_content++) {
				writer = gen_xmlTextWriterPtr(n_writer, 0);
				DTS_CHECK_NE_MESSAGE("xmlTextWriterWritePI", (void *)writer, (void *)NULL, "gen_xmlTextWriterPtr Failed");
	
				target = gen_const_xmlChar_ptr(n_target, 1);
				DTS_CHECK_NE_MESSAGE("xmlTextWriterWritePI", (void *)target, (void *)NULL, "gen_const_xmlChar_ptr Failed");
				
				content = gen_const_xmlChar_ptr(n_content, 2);
				DTS_CHECK_NE_MESSAGE("xmlTextWriterWritePI", (void *)content, (void *)NULL, "gen_const_xmlChar_ptr Failed");
				
				/**
				 * @remarks   input1: [N/A, N/A] @n
				 *            { xmlTextWriterPtr pointer ,xmlChar pointer ,xmlChar pointer}
				 *             => { N/A | int } @n
				 */
				ret_val = xmlTextWriterWritePI(writer, (const xmlChar *)target, (const xmlChar *)content);
				DTS_CHECK_EQ_MESSAGE("xmlTextWriterWritePI", (void *)ret_val, (void *)0, "xmlTextWriterWritePI Failed");
				
				desret_int(ret_val);
				des_xmlTextWriterPtr(n_writer, writer, 0);
				des_const_xmlChar_ptr(n_target, (const xmlChar *)target, 1);
				des_const_xmlChar_ptr(n_content, (const xmlChar *)content, 2);
				xmlResetLastError();
			}
		}
    }
}

static void
UTcXmlTextWriterWriteCDATAP01()
{
    int ret_val;
    xmlTextWriterPtr writer; /* the xmlTextWriterPtr */
    int n_writer;
    xmlChar * content; /* CDATA content */
    int n_content;

    for (n_writer = 0;n_writer < gen_nb_xmlTextWriterPtr;n_writer++) {
		for (n_content = 0;n_content < gen_nb_const_xmlChar_ptr;n_content++) {
			writer = gen_xmlTextWriterPtr(n_writer, 0);
			DTS_CHECK_NE_MESSAGE("xmlTextWriterWriteCDATA", (void *)writer, (void *)NULL, "gen_xmlTextWriterPtr Failed");
			
			content = gen_const_xmlChar_ptr(n_content, 1);
			DTS_CHECK_NE_MESSAGE("xmlTextWriterWritePI", (void *)content, (void *)NULL, "gen_const_xmlChar_ptr Failed");
				
			/**
			 * @remarks   input1: [N/A, N/A] @n
			 *            { xmlTextWriterPtr pointer ,xmlChar pointer}
			 *             => { N/A | int } @n
			 */
			ret_val = xmlTextWriterWriteCDATA(writer, (const xmlChar *)content);
			DTS_CHECK_EQ_MESSAGE("xmlTextWriterWritePI", (void *)ret_val, (void *)0, "xmlTextWriterWriteCDATA Failed");
			
			desret_int(ret_val);
			des_xmlTextWriterPtr(n_writer, writer, 0);
			des_const_xmlChar_ptr(n_content, (const xmlChar *)content, 1);
			xmlResetLastError();
		}
    }
}

static void
UTcXmlTextWriterWriteDTDP01()
{
    int ret_val;
    xmlTextWriterPtr writer; /* the xmlTextWriterPtr */
    int n_writer;
    xmlChar * name; /* the name of the DTD */
    int n_name;
    xmlChar * pubid; /* the public identifier, which is an alternative to the system identifier */
    int n_pubid;
    xmlChar * sysid; /* the system identifier, which is the URI of the DTD */
    int n_sysid;
    xmlChar * subset; /* string content of the DTD */
    int n_subset;

    for (n_writer = 0;n_writer < gen_nb_xmlTextWriterPtr;n_writer++) {
		for (n_name = 0;n_name < gen_nb_const_xmlChar_ptr;n_name++) {
			for (n_pubid = 0;n_pubid < gen_nb_const_xmlChar_ptr;n_pubid++) {
				for (n_sysid = 0;n_sysid < gen_nb_const_xmlChar_ptr;n_sysid++) {
					for (n_subset = 0;n_subset < gen_nb_const_xmlChar_ptr;n_subset++) {
						writer = gen_xmlTextWriterPtr(n_writer, 0);
						DTS_CHECK_NE_MESSAGE("xmlTextWriterWriteDTD", (void *)writer, (void *)NULL, "gen_xmlTextWriterPtr Failed");
						
						name = gen_const_xmlChar_ptr(n_name, 1);
						DTS_CHECK_NE_MESSAGE("xmlTextWriterWriteDTD", (void *)writer, (void *)NULL, "gen_const_xmlChar_ptr Failed");
						
						pubid = gen_const_xmlChar_ptr(n_pubid, 2);
						DTS_CHECK_NE_MESSAGE("xmlTextWriterWriteDTD", (void *)pubid, (void *)NULL, "gen_const_xmlChar_ptr Failed");
						
						sysid = gen_const_xmlChar_ptr(n_sysid, 3);
						DTS_CHECK_NE_MESSAGE("xmlTextWriterWriteDTD", (void *)sysid, (void *)NULL, "gen_const_xmlChar_ptr Failed");
						
						subset = gen_const_xmlChar_ptr(n_subset, 4);
						DTS_CHECK_NE_MESSAGE("xmlTextWriterWriteDTD", (void *)subset, (void *)NULL, "gen_const_xmlChar_ptr Failed");
						
						/**
						 * @remarks   input1: [N/A, N/A] @n
						 *            { xmlTextWriterPtr pointer ,xmlChar pointer ,xmlChar pointer ,xmlChar pointer ,xmlChar pointer}
						 *             => { N/A | int } @n
						 */
						ret_val = xmlTextWriterWriteDTD(writer, (const xmlChar *)name, (const xmlChar *)pubid, (const xmlChar *)sysid, (const xmlChar *)subset);
						DTS_CHECK_EQ_MESSAGE("xmlTextWriterWriteDTD", (void *)ret_val, (void *)0, "xmlTextWriterWriteDTD Failed");
						
						desret_int(ret_val);
						des_xmlTextWriterPtr(n_writer, writer, 0);
						des_const_xmlChar_ptr(n_name, (const xmlChar *)name, 1);
						des_const_xmlChar_ptr(n_pubid, (const xmlChar *)pubid, 2);
						des_const_xmlChar_ptr(n_sysid, (const xmlChar *)sysid, 3);
						des_const_xmlChar_ptr(n_subset, (const xmlChar *)subset, 4);
						xmlResetLastError();
					}
				}
			}
		}
    }
}


static void
UTcXmlTextWriterWriteDTDElementP01()
{
    int ret_val;
    xmlTextWriterPtr writer; /* the xmlTextWriterPtr */
    int n_writer;
    xmlChar * name; /* the name of the DTD element */
    int n_name;
    xmlChar * content; /* content of the element */
    int n_content;

    for (n_writer = 0;n_writer < gen_nb_xmlTextWriterPtr;n_writer++) {
		for (n_name = 0;n_name < gen_nb_const_xmlChar_ptr;n_name++) {
			for (n_content = 0;n_content < gen_nb_const_xmlChar_ptr;n_content++) {
				writer = gen_xmlTextWriterPtr(n_writer, 0);
				DTS_CHECK_NE_MESSAGE("xmlTextWriterWriteDTDElement", (void *)writer, (void *)NULL, "gen_xmlTextWriterPtr Failed");
						
				name = gen_const_xmlChar_ptr(n_name, 1);
				DTS_CHECK_NE_MESSAGE("xmlTextWriterWriteDTDElement", (void *)name, (void *)NULL, "gen_const_xmlChar_ptr Failed");
				
				content = gen_const_xmlChar_ptr(n_content, 2);
				DTS_CHECK_NE_MESSAGE("xmlTextWriterWriteDTDElement", (void *)content, (void *)NULL, "gen_const_xmlChar_ptr Failed");
				
				/**
				 * @remarks   input1: [N/A, N/A] @n
				 *            { xmlTextWriterPtr pointer ,xmlChar pointer ,xmlChar pointer}
				 *             => { N/A | int } @n
				 */
				ret_val = xmlTextWriterWriteDTDElement(writer, (const xmlChar *)name, (const xmlChar *)content);
				DTS_CHECK_EQ_MESSAGE("xmlTextWriterWriteDTDElement", (void *)ret_val, (void *)0, "xmlTextWriterWriteDTDElement Failed");
				
				desret_int(ret_val);
				des_xmlTextWriterPtr(n_writer, writer, 0);
				des_const_xmlChar_ptr(n_name, (const xmlChar *)name, 1);
				des_const_xmlChar_ptr(n_content, (const xmlChar *)content, 2);
				xmlResetLastError();
			}
		}
    }
}

static void
UTcXmlTextWriterWriteDTDAttlistP01()
{
    int ret_val;
    xmlTextWriterPtr writer; /* the xmlTextWriterPtr */
    int n_writer;
    xmlChar * name; /* the name of the DTD ATTLIST */
    int n_name;
    xmlChar * content; /* content of the ATTLIST */
    int n_content;

    for (n_writer = 0;n_writer < gen_nb_xmlTextWriterPtr;n_writer++) {
		for (n_name = 0;n_name < gen_nb_const_xmlChar_ptr;n_name++) {
			for (n_content = 0;n_content < gen_nb_const_xmlChar_ptr;n_content++) {
				writer = gen_xmlTextWriterPtr(n_writer, 0);
				DTS_CHECK_NE_MESSAGE("xmlTextWriterWriteDTDAttlist", (void *)writer, (void *)NULL, "gen_xmlTextWriterPtr Failed");
				
				name = gen_const_xmlChar_ptr(n_name, 1);
				DTS_CHECK_NE_MESSAGE("xmlTextWriterWriteDTDAttlist", (void *)name, (void *)NULL, "gen_const_xmlChar_ptr Failed");
				
				content = gen_const_xmlChar_ptr(n_content, 2);
				DTS_CHECK_NE_MESSAGE("xmlTextWriterWriteDTDAttlist", (void *)content, (void *)NULL, "gen_const_xmlChar_ptr Failed");
				
				/**
				 * @remarks   input1: [N/A, N/A] @n
				 *            { xmlTextWriterPtr pointer ,xmlChar pointer ,xmlChar pointer}
				 *             => { N/A | int } @n
				 */
				ret_val = xmlTextWriterWriteDTDAttlist(writer, (const xmlChar *)name, (const xmlChar *)content);
				DTS_CHECK_EQ_MESSAGE("xmlTextWriterWriteDTDAttlist", (void *)ret_val, (void *)0, "xmlTextWriterWriteDTDAttlist Failed");
				
				desret_int(ret_val);
				des_xmlTextWriterPtr(n_writer, writer, 0);
				des_const_xmlChar_ptr(n_name, (const xmlChar *)name, 1);
				des_const_xmlChar_ptr(n_content, (const xmlChar *)content, 2);
				xmlResetLastError();
			}
		}
    }
}

static void
UTcXmlTextWriterWriteDTDInternalEntityP01()
{
    int ret_val;
    xmlTextWriterPtr writer; /* the xmlTextWriterPtr */
    int n_writer;
    int pe; /* TRUE if this is a parameter entity, FALSE if not */
    int n_pe;
    xmlChar * name; /* the name of the DTD entity */
    int n_name;
    xmlChar * content; /* content of the entity */
    int n_content;

    for (n_writer = 0;n_writer < gen_nb_xmlTextWriterPtr;n_writer++) {
		for (n_pe = 0;n_pe < gen_nb_int;n_pe++) {
			for (n_name = 0;n_name < gen_nb_const_xmlChar_ptr;n_name++) {
				for (n_content = 0;n_content < gen_nb_const_xmlChar_ptr;n_content++) {
					writer = gen_xmlTextWriterPtr(n_writer, 0);
					DTS_CHECK_NE_MESSAGE("xmlTextWriterWriteDTDInternalEntity", (void *)writer, (void *)NULL, "gen_xmlTextWriterPtr Failed");
				
					pe = gen_int(n_pe, 1);
					name = gen_const_xmlChar_ptr(n_name, 2);
					DTS_CHECK_NE_MESSAGE("xmlTextWriterWriteDTDInternalEntity", (void *)name, (void *)NULL, "gen_const_xmlChar_ptr Failed");
					
					content = gen_const_xmlChar_ptr(n_content, 3);
					DTS_CHECK_NE_MESSAGE("xmlTextWriterWriteDTDInternalEntity", (void *)content, (void *)NULL, "gen_const_xmlChar_ptr Failed");
					
					/**
					 * @remarks   input1: [N/A, N/A] @n
					 *            { xmlTextWriterPtr pointer ,(0,1,-1,122) ,xmlChar pointer ,xmlChar pointer}
					 *             => { N/A | int } @n
					 */
					ret_val = xmlTextWriterWriteDTDInternalEntity(writer, pe, (const xmlChar *)name, (const xmlChar *)content);
					DTS_CHECK_EQ_MESSAGE("xmlTextWriterWriteDTDInternalEntity", (void *)ret_val, (void *)0, "xmlTextWriterWriteDTDInternalEntity Failed");
					
					desret_int(ret_val);
					des_xmlTextWriterPtr(n_writer, writer, 0);
					des_int(n_pe, pe, 1);
					des_const_xmlChar_ptr(n_name, (const xmlChar *)name, 2);
					des_const_xmlChar_ptr(n_content, (const xmlChar *)content, 3);
					xmlResetLastError();
				}
			}
		}
    }
}

static void
UTcXmlTextWriterWriteDTDExternalEntityP01()
{
    int ret_val;
    xmlTextWriterPtr writer; /* the xmlTextWriterPtr */
    int n_writer;
    int pe; /* TRUE if this is a parameter entity, FALSE if not */
    int n_pe;
    xmlChar * name; /* the name of the DTD entity */
    int n_name;
    xmlChar * pubid; /* the public identifier, which is an alternative to the system identifier */
    int n_pubid;
    xmlChar * sysid; /* the system identifier, which is the URI of the DTD */
    int n_sysid;
    xmlChar * ndataid; /* the xml notation name. */
    int n_ndataid;

    for (n_writer = 0;n_writer < gen_nb_xmlTextWriterPtr;n_writer++) {
		for (n_pe = 0;n_pe < gen_nb_int;n_pe++) {
			for (n_name = 0;n_name < gen_nb_const_xmlChar_ptr;n_name++) {
				for (n_pubid = 0;n_pubid < gen_nb_const_xmlChar_ptr;n_pubid++) {
					for (n_sysid = 0;n_sysid < gen_nb_const_xmlChar_ptr;n_sysid++) {
						for (n_ndataid = 0;n_ndataid < gen_nb_const_xmlChar_ptr;n_ndataid++) {
							writer = gen_xmlTextWriterPtr(n_writer, 0);
							DTS_CHECK_NE_MESSAGE("xmlTextWriterWriteDTDExternalEntity", (void *)writer, (void *)NULL, "gen_xmlTextWriterPtr Failed");
							
							pe = gen_int(n_pe, 1);
							//MT_CHECK_MESSAGE2(0 != pe, "gen_int returned NULL");
							name = gen_const_xmlChar_ptr(n_name, 2);
							DTS_CHECK_NE_MESSAGE("xmlTextWriterWriteDTDExternalEntity", (void *)name, (void *)NULL, "gen_const_xmlChar_ptr 1 Failed");
							
							pubid = gen_const_xmlChar_ptr(n_pubid, 3);
							DTS_CHECK_NE_MESSAGE("xmlTextWriterWriteDTDExternalEntity", (void *)pubid, (void *)NULL, "gen_const_xmlChar_ptr 2 Failed");
							
							sysid = gen_const_xmlChar_ptr(n_sysid, 4);
							DTS_CHECK_NE_MESSAGE("xmlTextWriterWriteDTDExternalEntity", (void *)sysid, (void *)NULL, "gen_const_xmlChar_ptr 3 Failed");
							
							ndataid = gen_const_xmlChar_ptr(n_ndataid, 5);
							DTS_CHECK_NE_MESSAGE("xmlTextWriterWriteDTDExternalEntity", (void *)ndataid, (void *)NULL, "gen_const_xmlChar_ptr 4 Failed");
							
							/**
							 * @remarks   input1: [N/A, N/A] @n
							 *            { xmlTextWriterPtr pointer ,(0,1,-1,122) ,xmlChar pointer ,xmlChar pointer ,xmlChar pointer ,xmlChar pointer}
							 *             => { N/A | int } @n
							 */
							ret_val = xmlTextWriterWriteDTDExternalEntity(writer, pe, (const xmlChar *)name, (const xmlChar *)pubid, (const xmlChar *)sysid, (const xmlChar *)ndataid);
							DTS_CHECK_EQ_MESSAGE("xmlTextWriterWriteDTDExternalEntity", (void *)ret_val, (void *)0, "xmlTextWriterWriteDTDExternalEntity Failed");
							
							desret_int(ret_val);
							des_xmlTextWriterPtr(n_writer, writer, 0);
							des_int(n_pe, pe, 1);
							des_const_xmlChar_ptr(n_name, (const xmlChar *)name, 2);
							des_const_xmlChar_ptr(n_pubid, (const xmlChar *)pubid, 3);
							des_const_xmlChar_ptr(n_sysid, (const xmlChar *)sysid, 4);
							des_const_xmlChar_ptr(n_ndataid, (const xmlChar *)ndataid, 5);
							xmlResetLastError();
						}
					}
				}
			}
		}
    }
}

static void
UTcXmlTextWriterWriteDTDExternalEntityContentsP01()
{
	int ret_val;
	xmlTextWriterPtr writer; /* the xmlTextWriterPtr*/
//	xmlChar *tmp;
	xmlDocPtr doc;
	//xmlChar * pid;
	/**
	 * @pre		1) Create a new Document.\n
	 * 			2) Start a Document.\n
	 * 			3) Write DTD Entity. \n
	 */
	writer = xmlNewTextWriterDoc(&doc, 0);
	DTS_CHECK_NE_MESSAGE("xmlTextWriterWriteDTDExternalEntityContents", (void *)writer, (void *)NULL, "xmlNewTextWriterDoc Failed");

	ret_val = xmlTextWriterStartDocument(writer, NULL, NULL, NULL);
	DTS_CHECK_EQ_MESSAGE("xmlTextWriterWriteDTDExternalEntityContents", (void *)ret_val, (void *)0, "xmlTextWriterStartDocument Failed");

	ret_val = xmlTextWriterWriteDTD(writer, (xmlChar *)"fieldconf", NULL,(xmlChar *)UTSXMLHOME"/mfield.dtd", NULL);
	DTS_CHECK_EQ_MESSAGE("xmlTextWriterWriteDTDExternalEntityContents", (void *)ret_val, (void *)0, "xmlTextWriterWriteDTD Failed");

	ret_val = xmlTextWriterStartDTDEntity(writer, 1, BAD_CAST "version");
	DTS_CHECK_EQ_MESSAGE("xmlTextWriterWriteDTDExternalEntityContents", (void *)ret_val, (void *)0, "xmlTextWriterStartDTDEntity Failed");

	/**
	 * @remarks   input1: [N/A, N/A] @n
	 *            { xmlTextWriterPtr pointer ,xmlChar pointer ,xmlChar pointer ,xmlChar pointer}
	 *             => { N/A | int } @n
	 */
	ret_val = xmlTextWriterWriteDTDExternalEntityContents(writer, NULL , (xmlChar *)"http://www.xml101.com/entities/entities.dtd" , NULL);
	DTS_CHECK_EQ_MESSAGE("xmlTextWriterWriteDTDExternalEntityContents", (void *)ret_val, (void *)0, "xmlTextWriterWriteDTDExternalEntityContents Failed");

	ret_val = xmlTextWriterEndDTDEntity(writer);
	DTS_CHECK_EQ_MESSAGE("xmlTextWriterWriteDTDExternalEntityContents", (void *)ret_val, (void *)0, "xmlTextWriterEndDTDEntity Failed");

	ret_val = xmlTextWriterEndDocument(writer);
	DTS_CHECK_EQ_MESSAGE("xmlTextWriterWriteDTDExternalEntityContents", (void *)ret_val, (void *)-1, "xmlTextWriterEndDocument Failed");
	
	/**
	 * @post 1) Close the Document. \n
	 *       2) Free  xmlTextWriter pointer. \n
	 */
	xmlFreeTextWriter(writer);
	xmlResetLastError();
}

static void
UTcXmlTextWriterWriteDTDEntityP01()
{
    int ret_val;
    xmlTextWriterPtr writer; /* the xmlTextWriterPtr */
    int n_writer;
    int pe; /* TRUE if this is a parameter entity, FALSE if not */
    int n_pe;
    xmlChar * name; /* the name of the DTD entity */
    int n_name;
    xmlChar * pubid; /* the public identifier, which is an alternative to the system identifier */
    int n_pubid;
    xmlChar * sysid; /* the system identifier, which is the URI of the DTD */
    int n_sysid;
    xmlChar * ndataid; /* the xml notation name. */
    int n_ndataid;
    xmlChar * content; /* content of the entity */
    int n_content;

    for (n_writer = 0;n_writer < gen_nb_xmlTextWriterPtr;n_writer++) {
		for (n_pe = 0;n_pe < gen_nb_int;n_pe++) {
			for (n_name = 0;n_name < gen_nb_const_xmlChar_ptr;n_name++) {
				for (n_pubid = 0;n_pubid < gen_nb_const_xmlChar_ptr;n_pubid++) {
					for (n_sysid = 0;n_sysid < gen_nb_const_xmlChar_ptr;n_sysid++) {
						for (n_ndataid = 0;n_ndataid < gen_nb_const_xmlChar_ptr;n_ndataid++) {
							for (n_content = 0;n_content < gen_nb_const_xmlChar_ptr;n_content++) {
								writer = gen_xmlTextWriterPtr(n_writer, 0);
								DTS_CHECK_NE_MESSAGE("xmlTextWriterWriteDTDEntity", (void *)writer, (void *)NULL, "gen_xmlTextWriterPtr Failed");
								
								pe = gen_int(n_pe, 1);
								//MT_CHECK_MESSAGE2(0 != pe, "gen_int returned NULL");
								name = gen_const_xmlChar_ptr(n_name, 2);
								DTS_CHECK_NE_MESSAGE("xmlTextWriterWriteDTDEntity", (void *)name, (void *)NULL, "gen_const_xmlChar_ptr Failed");
								
								pubid = gen_const_xmlChar_ptr(n_pubid, 3);
								DTS_CHECK_NE_MESSAGE("xmlTextWriterWriteDTDEntity", (void *)pubid, (void *)NULL, "gen_const_xmlChar_ptr Failed");
								
								sysid = gen_const_xmlChar_ptr(n_sysid, 4);
								DTS_CHECK_NE_MESSAGE("xmlTextWriterWriteDTDEntity", (void *)sysid, (void *)NULL, "gen_const_xmlChar_ptr Failed");
								
								ndataid = gen_const_xmlChar_ptr(n_ndataid, 5);
								DTS_CHECK_NE_MESSAGE("xmlTextWriterWriteDTDEntity", (void *)ndataid, (void *)NULL, "gen_const_xmlChar_ptr Failed");
								
								content = gen_const_xmlChar_ptr(n_content, 6);
								DTS_CHECK_NE_MESSAGE("xmlTextWriterWriteDTDEntity", (void *)content, (void *)NULL, "gen_const_xmlChar_ptr Failed");
								
								/**
								 * @remarks   input1: [N/A, N/A] @n
								 *            { xmlTextWriterPtr pointer ,(0,1,-1,122) ,xmlChar pointer ,xmlChar pointer ,xmlChar pointer ,xmlChar pointer ,xmlChar pointer}
								 *             => { N/A | int } @n
								 */
								ret_val = xmlTextWriterWriteDTDEntity(writer, pe, (const xmlChar *)name, (const xmlChar *)pubid, (const xmlChar *)sysid, (const xmlChar *)ndataid, (const xmlChar *)content);
								DTS_CHECK_EQ_MESSAGE("xmlTextWriterWriteDTDEntity", (void *)ret_val, (void *)0, "xmlTextWriterWriteDTDEntity Failed");
								
								desret_int(ret_val);
								des_xmlTextWriterPtr(n_writer, writer, 0);
								des_int(n_pe, pe, 1);
								des_const_xmlChar_ptr(n_name, (const xmlChar *)name, 2);
								des_const_xmlChar_ptr(n_pubid, (const xmlChar *)pubid, 3);
								des_const_xmlChar_ptr(n_sysid, (const xmlChar *)sysid, 4);
								des_const_xmlChar_ptr(n_ndataid, (const xmlChar *)ndataid, 5);
								des_const_xmlChar_ptr(n_content, (const xmlChar *)content, 6);
								xmlResetLastError();
							}
						}
					}
				}
			}
		}
    }
}

static void
UTcXmlTextWriterWriteFormatElementP01()
{
	int ret_val;
	xmlTextWriterPtr writer; /* the xmlTextWriterPtr */
	int n_writer;

	for (n_writer = 0;n_writer < gen_nb_xmlTextWriterPtr;n_writer++) {
		writer = gen_xmlTextWriterPtr(n_writer, 0);
		DTS_CHECK_NE_MESSAGE("xmlTextWriterWriteFormatElement", (void *)writer, (void *)NULL, "gen_xmlTextWriterPtr Failed");

		/**
		* @remarks   input1: [N/A, N/A] @n
		*            { xmlTextWriterPtr pointer ,BAD_CAST "X_ORDER_ID" ,"%010d", 53535L } => { N/A | int } @n
		*/
		ret_val = xmlTextWriterWriteFormatElement(writer, BAD_CAST "X_ORDER_ID", "%010d", 53535L);
		DTS_CHECK_EQ_MESSAGE("xmlTextWriterWriteFormatElement", (void *)ret_val, (void *)0, "xmlTextWriterWriteFormatElement Failed");
		
		desret_int(ret_val);
		des_xmlTextWriterPtr(n_writer, writer, 0);
		xmlResetLastError();
	}
}

static void
UTcXmlTextWriterWriteFormatDTDAttlistP01()
{
	int ret_val;
	xmlTextWriterPtr writer; /* the xmlTextWriterPtr */
	int n_writer;

	for (n_writer = 0;n_writer < gen_nb_xmlTextWriterPtr;n_writer++) {
		writer = gen_xmlTextWriterPtr(n_writer, 0);
		DTS_CHECK_NE_MESSAGE("xmlTextWriterWriteFormatDTDAttlist", (void *)writer, (void *)NULL, "gen_xmlTextWriterPtr Failed");

		/**
		* @remarks   input1: [N/A, N/A] @n
		*            { xmlTextWriterPtr pointer ,BAD_CAST "X_ORDER_ID" ,"%010d", 53535L } => { N/A | int } @n
		*/
		ret_val = xmlTextWriterWriteFormatDTDAttlist(writer, BAD_CAST "X_ORDER_ID", "%010d", 53535L);
		DTS_CHECK_EQ_MESSAGE("xmlTextWriterWriteFormatDTDAttlist", (void *)ret_val, (void *)0, "xmlTextWriterWriteFormatDTDAttlist Failed");
		
		desret_int(ret_val);
		des_xmlTextWriterPtr(n_writer, writer, 0);
		xmlResetLastError();
	}
}

static void
UTcXmlTextWriterWriteFormatDTDElementP01()
{
	int ret_val;
	xmlTextWriterPtr writer; /* the xmlTextWriterPtr */
	int n_writer;

	for (n_writer = 0;n_writer < gen_nb_xmlTextWriterPtr;n_writer++) {
		writer = gen_xmlTextWriterPtr(n_writer, 0);
		DTS_CHECK_NE_MESSAGE("xmlTextWriterWriteFormatDTDElement", (void *)writer, (void *)NULL, "gen_xmlTextWriterPtr Failed");

		/**
		* @remarks   input1: [N/A, N/A] @n
		*            { xmlTextWriterPtr pointer ,BAD_CAST "X_ORDER_ID", "%010d", 53535L } => { N/A | int } @n
		*/
		ret_val = xmlTextWriterWriteFormatDTDElement(writer, BAD_CAST "X_ORDER_ID", "%010d", 53535L);
		DTS_CHECK_EQ_MESSAGE("xmlTextWriterWriteFormatDTDElement", (void *)ret_val, (void *)NULL, "xmlTextWriterWriteFormatDTDElement Failed");
		
		desret_int(ret_val);
		des_xmlTextWriterPtr(n_writer, writer, 0);
		xmlResetLastError();
	}
}

static void
UTcXmlTextWriterWriteFormatCDATAP01()
{
	int ret_val;
	xmlTextWriterPtr writer; /* the xmlTextWriterPtr */
	int n_writer;

	for (n_writer = 0;n_writer < gen_nb_xmlTextWriterPtr;n_writer++) {
		writer = gen_xmlTextWriterPtr(n_writer, 0);
		DTS_CHECK_NE_MESSAGE("xmlTextWriterWriteFormatCDATA", (void *)writer, (void *)NULL, "gen_xmlTextWriterPtr Failed");

		/**
		* @remarks   input1: [N/A, N/A] @n
		*            { xmlTextWriterPtr pointer , "%010d", 53535L } => { N/A | int } @n
		*/
		ret_val = xmlTextWriterWriteFormatCDATA(writer, "%010d", 53535L);
		DTS_CHECK_EQ_MESSAGE("xmlTextWriterWriteFormatCDATA", (void *)ret_val, (void *)NULL, "xmlTextWriterWriteFormatCDATA Failed");
		
		desret_int(ret_val);
		des_xmlTextWriterPtr(n_writer, writer, 0);
		xmlResetLastError();
	}
}

static void
UTcXmlTextWriterWriteFormatDTDInternalEntityP01()
{
	int ret_val;
	xmlTextWriterPtr writer; /* the xmlTextWriterPtr */
	int n_writer;
	int pe; /* TRUE if this is a parameter entity, FALSE if not */
	int n_pe;

	for (n_writer = 0;n_writer < gen_nb_xmlTextWriterPtr;n_writer++) {
		for (n_pe = 0;n_pe < gen_nb_int;n_pe++) {
			writer = gen_xmlTextWriterPtr(n_writer, 0);
			DTS_CHECK_NE_MESSAGE("xmlTextWriterWriteFormatDTDInternalEntity", (void *)writer, (void *)NULL, "gen_xmlTextWriterPtr Failed");
		
			pe = gen_int(n_pe, 1);
			/**
			* @remarks   input1: [N/A, N/A] @n
			*            { xmlTextWriterPtr pointer ,(0,1,-1,122) ,BAD_CAST "X_ORDER_ID" ,"%010d", 53535L } => { N/A | int } @n
			*/
			ret_val = xmlTextWriterWriteFormatDTDInternalEntity(writer ,pe ,BAD_CAST "X_ORDER_ID", "%010d", 53535L);
			DTS_CHECK_EQ_MESSAGE("xmlTextWriterWriteFormatDTDInternalEntity", (void *)ret_val, (void *)NULL, "xmlTextWriterWriteFormatDTDInternalEntity Failed");
		
			desret_int(ret_val);
			des_xmlTextWriterPtr(n_writer, writer, 0);
			xmlResetLastError();
		}
	}
}

static void
UTcXmlTextWriterWriteFormatDTDP01()
{
    int ret_val;
    xmlTextWriterPtr writer; /* the xmlTextWriterPtr */
    int n_writer;
//    xmlChar * name; /* the name of the DTD */
//    int n_name;
    xmlChar * pubid; /* the public identifier, which is an alternative to the system identifier */
    int n_pubid;
    xmlChar * sysid; /* the system identifier, which is the URI of the DTD */
    int n_sysid;
 //   xmlChar * subset; /* string content of the DTD */
//    int n_subset;

    for (n_writer = 0;n_writer < gen_nb_xmlTextWriterPtr;n_writer++) {
		for (n_pubid = 0;n_pubid < gen_nb_const_xmlChar_ptr;n_pubid++) {
			for (n_sysid = 0;n_sysid < gen_nb_const_xmlChar_ptr;n_sysid++) {
				writer = gen_xmlTextWriterPtr(n_writer, 0);
				DTS_CHECK_NE_MESSAGE("xmlTextWriterWriteFormatDTD", (void *)writer, (void *)NULL, "gen_xmlTextWriterPtr Failed");
				
				pubid = gen_const_xmlChar_ptr(n_pubid, 2);
				DTS_CHECK_NE_MESSAGE("xmlTextWriterWriteFormatDTD", (void *)pubid, (void *)NULL, "gen_const_xmlChar_ptr Failed");
			
				sysid = gen_const_xmlChar_ptr(n_sysid, 3);
				DTS_CHECK_NE_MESSAGE("xmlTextWriterWriteFormatDTD", (void *)sysid, (void *)NULL, "gen_const_xmlChar_ptr Failed");
				
				/**
				 * @remarks   input1: [N/A, N/A] @n
				 *            { xmlTextWriterPtr pointer ,xmlChar pointer ,xmlChar pointer ,xmlChar pointer ,"%010d", 53535L }
				 *             => { N/A | int } @n
				 */
				ret_val = xmlTextWriterWriteFormatDTD(writer, BAD_CAST "X_ORDER_ID", (const xmlChar *)pubid, (const xmlChar *)sysid, "%010d", 53535L );
				DTS_CHECK_EQ_MESSAGE("xmlTextWriterWriteFormatDTD", (void *)ret_val, (void *)0, "xmlTextWriterWriteFormatDTD Failed");
				
				desret_int(ret_val);
				des_xmlTextWriterPtr(n_writer, writer, 0);
				des_const_xmlChar_ptr(n_pubid, (const xmlChar *)pubid, 2);
				des_const_xmlChar_ptr(n_sysid, (const xmlChar *)sysid, 3);
				xmlResetLastError();
			}
		}
    }
}

static void
UTcXmlTextWriterWriteFormatPIP01()
{
    int ret_val;
    xmlTextWriterPtr writer; /* the xmlTextWriterPtr */
    int n_writer;
    xmlChar * target; /* PI target */
    int n_target;

    for (n_writer = 0;n_writer < gen_nb_xmlTextWriterPtr;n_writer++) {
		for (n_target = 0;n_target < gen_nb_const_xmlChar_ptr;n_target++) {
			writer = gen_xmlTextWriterPtr(n_writer, 0);
			DTS_CHECK_NE_MESSAGE("xmlTextWriterWriteFormatPI", (void *)writer, (void *)NULL, "gen_xmlTextWriterPtr Failed");
				
			target = gen_const_xmlChar_ptr(n_target, 1);
			DTS_CHECK_NE_MESSAGE("xmlTextWriterWriteFormatPI", (void *)target, (void *)NULL, "gen_const_xmlChar_ptr Failed");
				
			/**
			 * @remarks   input1: [N/A, N/A] @n
			 *            { xmlTextWriterPtr pointer ,xmlChar pointer ,"%010d", 53535L }
			 *             => { N/A | int } @n
			 */
			ret_val = xmlTextWriterWriteFormatPI(writer, (const xmlChar *)target, "%010d", 53535L );
			DTS_CHECK_EQ_MESSAGE("xmlTextWriterWriteFormatPI", (void *)ret_val, (void *)0, "xmlTextWriterWriteFormatPI Failed");
			
			desret_int(ret_val);
			des_xmlTextWriterPtr(n_writer, writer, 0);
			des_const_xmlChar_ptr(n_target, (const xmlChar *)target, 1);
			xmlResetLastError();
		}
    }
}

static void
UTcXmlTextWriterWriteFormatAttributeP01()
{
	int ret_val;
	xmlTextWriterPtr writer; /* the xmlTextWriterPtr*/
	xmlChar *tmp;
	/**
	 * @pre		1) Create a new Document.\n
	 * 			2) Start a Document.\n
	 * 			3) Write Element. \n
	 */
	writer = xmlNewTextWriterFilename(OUTFILE1, 0);
	DTS_CHECK_NE_MESSAGE("xmlTextWriterWriteFormatAttribute", (void *)writer, (void *)NULL, "xmlNewTextWriterFilename Failed");

	ret_val = xmlTextWriterStartDocument(writer, NULL, MY_ENCODING, NULL);
	DTS_CHECK_EQ_MESSAGE("xmlTextWriterWriteFormatAttribute", (void *)ret_val, (void *)NULL, "xmlTextWriterStartDocument Failed");

	//ret_val = xmlTextWriterStartElement(writer, BAD_CAST "EXAMPLE");
	//MT_CHECK_MESSAGE2(0 == ret_val, "API return value: %d", ret_val);

	tmp = ConvertInput("This is a comment with special chars: <äö?",MY_ENCODING);
	ret_val = xmlTextWriterWriteComment(writer, tmp);
	DTS_CHECK_EQ_MESSAGE("xmlTextWriterWriteFormatAttribute", (void *)ret_val, (void *)0, "xmlTextWriterWriteComment Failed");
	
	if (tmp != NULL) 
		xmlFree(tmp);

	ret_val = xmlTextWriterStartElement(writer, BAD_CAST "ORDER");
	DTS_CHECK_EQ_MESSAGE("xmlTextWriterWriteFormatAttribute", (void *)ret_val, (void *)0, "xmlTextWriterStartElement Failed");
	
	/**
	 * @remarks   input1: [N/A, N/A] @n
	 *            { xmlTextWriterPtr pointer ,BAD_CAST "version" , "%010d", 53535L }
	 *             => { N/A | int } @n
	 */
	ret_val = xmlTextWriterWriteFormatAttribute(writer, BAD_CAST "version", "%010d", 53535L );
	DTS_CHECK_EQ_MESSAGE("xmlTextWriterWriteFormatAttribute", (void *)ret_val, (void *)0, "xmlTextWriterWriteFormatAttribute Failed");

	ret_val = xmlTextWriterEndElement(writer);
	DTS_CHECK_EQ_MESSAGE("xmlTextWriterWriteFormatAttribute", (void *)ret_val, (void *)0, "xmlTextWriterEndElement Failed");

	ret_val = xmlTextWriterEndDocument(writer);
	DTS_CHECK_NE_MESSAGE("xmlTextWriterWriteFormatAttribute", (void *)ret_val, (void *)-1, "xmlTextWriterEndDocument Failed");
	
	/**
	 * @post 1) Close the Document. \n
	 *       2) Free  xmlTextWriter pointer. \n
	 */
	xmlFreeTextWriter(writer);
	xmlResetLastError();

}
static void
UTcXmlTextWriterWriteFormatRawP01()
{
	int ret_val;
	xmlTextWriterPtr writer; /* the xmlTextWriterPtr */
	int n_writer;

	for (n_writer = 0;n_writer < gen_nb_xmlTextWriterPtr;n_writer++) {
		writer = gen_xmlTextWriterPtr(n_writer, 0);
		DTS_CHECK_NE_MESSAGE("xmlTextWriterWriteFormatRaw", (void *)writer, (void *)NULL, "gen_xmlTextWriterPtr Failed");

		/**
		* @remarks   input1: [N/A, N/A] @n
		*            { xmlTextWriterPtr pointer , "%010d", 53535L } => { N/A | int } @n
		*/
		ret_val = xmlTextWriterWriteFormatRaw(writer, "%010d", 53535L);
		DTS_CHECK_EQ_MESSAGE("xmlTextWriterWriteFormatRaw", (void *)ret_val, (void *)NULL, "xmlTextWriterWriteFormatRaw Failed");

		desret_int(ret_val);
		des_xmlTextWriterPtr(n_writer, writer, 0);
		xmlResetLastError();
	}
}

static void
UTcXmlTextWriterWriteFormatElementNSP01()
{
	int ret_val;
	xmlTextWriterPtr writer; /* the xmlTextWriterPtr */
	int n_writer;
	xmlChar * prefix; /* namespace prefix */
	int n_prefix;
	xmlChar * name; /* element local name */
	int n_name;
	xmlChar * namespaceURI; /* namespace URI */
	int n_namespaceURI;

	for (n_writer = 0;n_writer < gen_nb_xmlTextWriterPtr;n_writer++) {
		for (n_prefix = 0;n_prefix < gen_nb_const_xmlChar_ptr;n_prefix++) {
			for (n_name = 0;n_name < gen_nb_const_xmlChar_ptr;n_name++) {
				for (n_namespaceURI = 0;n_namespaceURI < gen_nb_const_xmlChar_ptr;n_namespaceURI++) {
					writer = gen_xmlTextWriterPtr(n_writer, 0);
					DTS_CHECK_NE_MESSAGE("xmlTextWriterWriteFormatElementNS", (void *)writer, (void *)NULL, "gen_xmlTextWriterPtr Failed");
		
					prefix = gen_const_xmlChar_ptr(n_prefix, 1);
					DTS_CHECK_NE_MESSAGE("xmlTextWriterWriteFormatElementNS", (void *)prefix, (void *)NULL, "gen_const_xmlChar_ptr Failed");
					
					name = gen_const_xmlChar_ptr(n_name, 2);
					DTS_CHECK_NE_MESSAGE("xmlTextWriterWriteFormatElementNS", (void *)name, (void *)NULL, "gen_const_xmlChar_ptr Failed");
					
					namespaceURI = gen_const_xmlChar_ptr(n_namespaceURI, 3);
					DTS_CHECK_NE_MESSAGE("xmlTextWriterWriteFormatElementNS", (void *)namespaceURI, (void *)NULL, "gen_const_xmlChar_ptr Failed");

					/**
					 * @remarks   input1: [N/A, N/A] @n
					 *            { xmlTextWriterPtr pointer ,xmlChar pointer ,xmlChar pointer ,xmlChar pointer ,"%010d", 53535L}
					 *             => { N/A | int } @n
					 */
					ret_val = xmlTextWriterWriteFormatElementNS(writer, (const xmlChar *)prefix, (const xmlChar *)name, (const xmlChar *)namespaceURI, "%010d", 53535L);
					DTS_CHECK_EQ_MESSAGE("xmlTextWriterWriteFormatElementNS", (void *)ret_val, (void *)0, "xmlTextWriterWriteFormatElementNS Failed");
					
					desret_int(ret_val);
					des_xmlTextWriterPtr(n_writer, writer, 0);
					des_const_xmlChar_ptr(n_prefix, (const xmlChar *)prefix, 1);
					des_const_xmlChar_ptr(n_name, (const xmlChar *)name, 2);
					des_const_xmlChar_ptr(n_namespaceURI, (const xmlChar *)namespaceURI, 3);
					xmlResetLastError();
				}
			}
		}
	}
}
 
static void
UTcXmlTextWriterWriteElementP02()
{
    int ret_val=-1;
    xmlTextWriterPtr writer;
    xmlChar *tmp;

    /* Create a new XmlWriter for uri, with no compression. */
    writer = xmlNewTextWriterFilename(OUTFILE2, 0);
    DTS_CHECK_NE_MESSAGE("xmlTextWriterWriteComment", (void *)writer, (void *)NULL, "xmlNewTextWriterFilename Failed");

    /* Start the document with the xml default for the version,
     * encoding ISO 8859-1 and the default for the standalone
     * declaration. */
    ret_val = xmlTextWriterStartDocument(writer, NULL, MY_ENCODING, NULL);
    DTS_CHECK_EQ_MESSAGE("xmlTextWriterWriteComment", (void *)ret_val, (void *)0, "xmlTextWriterStartDocument Failed");

    /* Start an element named "EXAMPLE". Since thist is the first
     * element, this will be the root element of the document. */
    ret_val = xmlTextWriterStartElement(writer, BAD_CAST "EXAMPLE");
    DTS_CHECK_EQ_MESSAGE("xmlTextWriterWriteComment", (void *)ret_val, (void *)0, "xmlTextWriterStartElement Failed");

    /* Write a comment as child of EXAMPLE.
     * Please observe, that the input to the xmlTextWriter functions
     * HAS to be in UTF-8, even if the output XML is encoded
     * in iso-8859-1 */
    tmp = ConvertInput("This is a comment with special chars: <äö?",MY_ENCODING);
    ret_val = xmlTextWriterWriteComment(writer, tmp);
    DTS_CHECK_EQ_MESSAGE("xmlTextWriterWriteComment", (void *)ret_val, (void *)0, "xmlTextWriterWriteComment Failed");

    if (tmp != NULL) 
		xmlFree(tmp);

    /* Start an element named "ORDER" as child of EXAMPLE. */
    ret_val = xmlTextWriterStartElement(writer, BAD_CAST "ORDER");
    DTS_CHECK_EQ_MESSAGE("xmlTextWriterWriteComment", (void *)ret_val, (void *)0, "xmlTextWriterStartElement Failed");

    /* Add an attribute with name "version" and value "1.0" to ORDER. */
    ret_val = xmlTextWriterWriteAttribute(writer, BAD_CAST "version",BAD_CAST "1.0");
    DTS_CHECK_EQ_MESSAGE("xmlTextWriterWriteComment", (void *)ret_val, (void *)0, "xmlTextWriterWriteAttribute Failed");

    /* Add an attribute with name "xml:lang" and value "de" to ORDER. */
    ret_val = xmlTextWriterWriteAttribute(writer, BAD_CAST "xml:lang",BAD_CAST "de");
    DTS_CHECK_EQ_MESSAGE("xmlTextWriterWriteComment", (void *)ret_val, (void *)0, "xmlTextWriterWriteAttribute Failed");

    /* Write a comment as child of ORDER */
    tmp = ConvertInput("<äö?", MY_ENCODING);
    ret_val = xmlTextWriterWriteFormatComment(writer,
		     "This is another comment with special chars: %s",
		     tmp);
    DTS_CHECK_EQ_MESSAGE("xmlTextWriterWriteComment", (void *)ret_val, (void *)0, "xmlTextWriterWriteFormatComment Failed");

    if (tmp != NULL) xmlFree(tmp);

    /* Start an element named "HEADER" as child of ORDER. */
    ret_val = xmlTextWriterStartElement(writer, BAD_CAST "HEADER");
    DTS_CHECK_EQ_MESSAGE("xmlTextWriterWriteComment", (void *)ret_val, (void *)0, "xmlTextWriterStartElement Failed");

    /* Write an element named "X_ORDER_ID" as child of HEADER. */
    ret_val = xmlTextWriterWriteFormatElement(writer, BAD_CAST "X_ORDER_ID", "%010d", 53535L);
    DTS_CHECK_EQ_MESSAGE("xmlTextWriterWriteComment", (void *)ret_val, (void *)0, "xmlTextWriterWriteFormatElement Failed");

    /* Write an element named "CUSTOMER_ID" as child of HEADER. */
    ret_val = xmlTextWriterWriteFormatElement(writer, BAD_CAST "CUSTOMER_ID", "%d", 1010);
    DTS_CHECK_EQ_MESSAGE("xmlTextWriterWriteComment", (void *)ret_val, (void *)0, "xmlTextWriterWriteFormatElement Failed");

    /* Write an element named "NAME_1" as child of HEADER. */
    tmp = ConvertInput("M?ler", MY_ENCODING);
    ret_val = xmlTextWriterWriteElement(writer, BAD_CAST "NAME_1", tmp);
    DTS_CHECK_EQ_MESSAGE("xmlTextWriterWriteComment", (void *)ret_val, (void *)0, "xmlTextWriterWriteElement Failed");

    if (tmp != NULL) xmlFree(tmp);

    /* Write an element named "NAME_2" as child of HEADER. */
    tmp = ConvertInput("J?g", MY_ENCODING);
    ret_val = xmlTextWriterWriteElement(writer, BAD_CAST "NAME_2", tmp);
    DTS_CHECK_EQ_MESSAGE("xmlTextWriterWriteComment", (void *)ret_val, (void *)0, "xmlTextWriterWriteElement Failed");

    if (tmp != NULL) xmlFree(tmp);

    /* Close the element named HEADER. */
    ret_val = xmlTextWriterEndElement(writer);
    DTS_CHECK_EQ_MESSAGE("xmlTextWriterWriteComment", (void *)ret_val, (void *)0, "xmlTextWriterEndElement Failed");

    /* Start an element named "ENTRIES" as child of ORDER. */
    ret_val = xmlTextWriterStartElement(writer, BAD_CAST "ENTRIES");
    DTS_CHECK_EQ_MESSAGE("xmlTextWriterWriteComment", (void *)ret_val, (void *)0, "xmlTextWriterStartElement Failed");

    /* Start an element named "ENTRY" as child of ENTRIES. */
    ret_val = xmlTextWriterStartElement(writer, BAD_CAST "ENTRY");
    DTS_CHECK_EQ_MESSAGE("xmlTextWriterWriteComment", (void *)ret_val, (void *)0, "xmlTextWriterStartElement Failed");

    /* Write an element named "ARTICLE" as child of ENTRY. */
    ret_val = xmlTextWriterWriteElement(writer, BAD_CAST "ARTICLE",BAD_CAST "<Test>");
    DTS_CHECK_EQ_MESSAGE("xmlTextWriterWriteComment", (void *)ret_val, (void *)0, "xmlTextWriterWriteElement Failed");

    /* Write an element named "ENTRY_NO" as child of ENTRY. */
    ret_val = xmlTextWriterWriteFormatElement(writer, BAD_CAST "ENTRY_NO", "%d",10);
    DTS_CHECK_EQ_MESSAGE("xmlTextWriterWriteComment", (void *)ret_val, (void *)0, "xmlTextWriterWriteFormatElement Failed");

    /* Close the element named ENTRY. */
    ret_val = xmlTextWriterEndElement(writer);
    DTS_CHECK_EQ_MESSAGE("xmlTextWriterWriteComment", (void *)ret_val, (void *)0, "xmlTextWriterEndElement Failed");

    /* Start an element named "ENTRY" as child of ENTRIES. */
    ret_val = xmlTextWriterStartElement(writer, BAD_CAST "ENTRY");
    DTS_CHECK_EQ_MESSAGE("xmlTextWriterWriteComment", (void *)ret_val, (void *)0, "xmlTextWriterStartElement Failed");

    /* Write an element named "ARTICLE" as child of ENTRY. */
    ret_val = xmlTextWriterWriteElement(writer, BAD_CAST "ARTICLE",BAD_CAST "<Test 2>");
    DTS_CHECK_EQ_MESSAGE("xmlTextWriterWriteComment", (void *)ret_val, (void *)0, "xmlTextWriterWriteElement Failed");

    /* Write an element named "ENTRY_NO" as child of ENTRY. */
    ret_val = xmlTextWriterWriteFormatElement(writer, BAD_CAST "ENTRY_NO", "%d",20);
    DTS_CHECK_EQ_MESSAGE("xmlTextWriterWriteComment", (void *)ret_val, (void *)0, "xmlTextWriterWriteFormatElement Failed");

    /* Close the element named ENTRY. */
    ret_val = xmlTextWriterEndElement(writer);
    DTS_CHECK_EQ_MESSAGE("xmlTextWriterWriteComment", (void *)ret_val, (void *)0, "xmlTextWriterEndElement Failed");

    /* Close the element named ENTRIES. */
    ret_val = xmlTextWriterEndElement(writer);
    DTS_CHECK_EQ_MESSAGE("xmlTextWriterWriteComment", (void *)ret_val, (void *)0, "xmlTextWriterEndElement Failed");

    /* Start an element named "FOOTER" as child of ORDER. */
    ret_val = xmlTextWriterStartElement(writer, BAD_CAST "FOOTER");
    DTS_CHECK_EQ_MESSAGE("xmlTextWriterWriteComment", (void *)ret_val, (void *)0, "xmlTextWriterStartElement Failed");

    /* Write an element named "TEXT" as child of FOOTER. */
    ret_val = xmlTextWriterWriteElement(writer, BAD_CAST "TEXT",BAD_CAST "This is a text.");
    DTS_CHECK_EQ_MESSAGE("xmlTextWriterWriteComment", (void *)ret_val, (void *)0, "xmlTextWriterWriteElement Failed");

    /* Close the element named FOOTER. */
    ret_val = xmlTextWriterEndElement(writer);
    DTS_CHECK_EQ_MESSAGE("xmlTextWriterWriteComment", (void *)ret_val, (void *)0, "xmlTextWriterEndElement Failed");

    /* Here we could close the elements ORDER and EXAMPLE using the
     * function xmlTextWriterEndElement, but since we do not want to
     * write any other elements, we simply call xmlTextWriterEndDocument,
     * which will do all the work. */
    ret_val = xmlTextWriterEndDocument(writer);
    DTS_CHECK_NE_MESSAGE("xmlTextWriterWriteComment", (void *)ret_val, (void *)-1, "xmlTextWriterEndDocument Failed");

    xmlFreeTextWriter(writer);
}

static void
UTcXmlTextWriterWriteFormatAttributeNSP01()
{
	int ret_val;
	xmlTextWriterPtr writer; /* the xmlTextWriterPtr*/
	xmlChar *tmp;
	/**
	 * @pre		1) Create a new Document.\n
	 * 			2) Start a Document.\n
	 * 			3) Write Element. \n
	 */
	writer = xmlNewTextWriterFilename(OUTFILE1, 0);
	DTS_CHECK_NE_MESSAGE("xmlTextWriterWriteFormatAttributeNS", (void *)writer, (void *)NULL, "xmlNewTextWriterFilename Failed");

	ret_val = xmlTextWriterStartDocument(writer, NULL, MY_ENCODING, NULL);
	DTS_CHECK_EQ_MESSAGE("xmlTextWriterWriteFormatAttributeNS", (void *)ret_val, (void *)0, "xmlTextWriterStartDocument Failed");

	//ret_val = xmlTextWriterStartElement(writer, BAD_CAST "EXAMPLE");
	//MT_CHECK_MESSAGE2(0 == ret_val, "API return value: %d", ret_val);

	tmp = ConvertInput("This is a comment with special chars: <äö?",MY_ENCODING);
	ret_val = xmlTextWriterWriteComment(writer, tmp);
	DTS_CHECK_EQ_MESSAGE("xmlTextWriterWriteFormatAttributeNS", (void *)ret_val, (void *)0, "xmlTextWriterWriteComment Failed");
	
	if (tmp != NULL) 
		xmlFree(tmp);

	ret_val = xmlTextWriterStartElement(writer, BAD_CAST "ORDER");
	DTS_CHECK_EQ_MESSAGE("xmlTextWriterWriteFormatAttributeNS", (void *)ret_val, (void *)0, "xmlTextWriterStartElement Failed");
	
	/**
	 * @remarks   input1: [N/A, N/A] @n
	 *            { xmlTextWriterPtr pointer ,xmlChar pointer ,BAD_CAST "X_ORDER_ID" ,xmlChar pointer , "%010d", 53535L }
	 *             => { N/A | int } @n
	 */
	ret_val = xmlTextWriterWriteFormatAttributeNS(writer, NULL, BAD_CAST "version", NULL , "%010d", 53535L );
	DTS_CHECK_EQ_MESSAGE("xmlTextWriterWriteFormatAttributeNS", (void *)ret_val, (void *)0, "xmlTextWriterWriteFormatAttributeNS Failed");

	ret_val = xmlTextWriterEndElement(writer);
	DTS_CHECK_EQ_MESSAGE("xmlTextWriterWriteFormatAttributeNS", (void *)ret_val, (void *)0, "xmlTextWriterEndElement Failed");

	ret_val = xmlTextWriterEndDocument(writer);
	DTS_CHECK_NE_MESSAGE("xmlTextWriterWriteFormatAttributeNS", (void *)ret_val, (void *)-1, "xmlTextWriterEndDocument Failed");
	
	/**
	 * @post 1) Close the Document. \n
	 *       2) Free  xmlTextWriter pointer. \n
	 */
	xmlFreeTextWriter(writer);
	xmlResetLastError();

}

static void
UTcXmlTextWriterWriteFormatStringP01()
{
	int ret_val;
	xmlTextWriterPtr writer; /* the xmlTextWriterPtr */
	int n_writer;

	for (n_writer = 0;n_writer < gen_nb_xmlTextWriterPtr;n_writer++) {
		writer = gen_xmlTextWriterPtr(n_writer, 0);
		DTS_CHECK_NE_MESSAGE("xmlTextWriterWriteFormatString", (void *)writer, (void *)NULL, "gen_xmlTextWriterPtr Failed");

		/**
		* @remarks   input1: [N/A, N/A] @n
		*            { xmlTextWriterPtr pointer , "%010d", 53535L } => { N/A | int } @n
		*/
		ret_val = xmlTextWriterWriteFormatString(writer, "%010d", 53535L);
		DTS_CHECK_EQ_MESSAGE("xmlTextWriterWriteFormatString", (void *)ret_val, (void *)NULL, "xmlTextWriterWriteFormatString Failed");
		
		desret_int(ret_val);
		des_xmlTextWriterPtr(n_writer, writer, 0);
		xmlResetLastError();
	}
}

static void
UTcXmlTextWriterWriteFormatCommentP01()
{
	int ret_val;
	xmlTextWriterPtr writer; /* the xmlTextWriterPtr */
	int n_writer;

	for (n_writer = 0;n_writer < gen_nb_xmlTextWriterPtr;n_writer++) {
		writer = gen_xmlTextWriterPtr(n_writer, 0);
		DTS_CHECK_NE_MESSAGE("xmlTextWriterWriteFormatComment", (void *)writer, (void *)NULL, "gen_xmlTextWriterPtr Failed");

		/**
		* @remarks   input1: [N/A, N/A] @n
		*            { xmlTextWriterPtr pointer , "%010d", 53535L } => { N/A | int } @n
		*/
		ret_val = xmlTextWriterWriteFormatComment(writer, "%010d", 53535L);
		DTS_CHECK_EQ_MESSAGE("xmlTextWriterWriteFormatComment", (void *)ret_val, (void *)NULL, "xmlTextWriterWriteFormatComment Failed");
		
		desret_int(ret_val);
		des_xmlTextWriterPtr(n_writer, writer, 0);
		xmlResetLastError();
	}
}


static void startup( void);
static void cleanup( void);

void (*tet_startup)( void) = startup;
void (*tet_cleanup)( void) = cleanup;

static void startup( void)
{
        /* start of TC */
        tet_printf("TC starts.");
}

static void cleanup( void)
{
        /* end of TC */
        tet_printf("TC ends.");
}

struct tet_testlist tet_testlist[] = {
	// Handling of out of context errors
	{UTcXmlTextWriterWriteFormatDTDElementP01,1},
	{UTcXmlTextWriterWriteFormatPIP01,2},
	{UTcXmlTextWriterWriteFormatAttributeP01,3},
	{UTcXmlTextWriterWriteFormatAttributeNSP01,4},
	{UTcXmlTextWriterWriteFormatRawP01,5},
	{UTcXmlTextWriterWriteFormatElementNSP01,6},
	{UTcXmlTextWriterWriteFormatStringP01,7},
	{UTcXmlNewTextWriterP01,8},
	{UTcXmlNewTextWriterFilenameP01,9},
	{UTcXmlNewTextWriterMemoryP01,10},
	
	{UTcXmlNewTextWriterPushParserP01,11},
	{UTcXmlNewTextWriterDocP01,12},
	{UTcXmlNewTextWriterTreeP01,13},
	{UTcXmlFreeTextWriterP01,14},
	{UTcXmlTextWriterStartDocumentP01,15},
	{UTcXmlTextWriterEndDocumentP01,16},
	{UTcXmlTextWriterStartElementP01,17},
	{UTcXmlTextWriterStartElementNSP01,18},
	{UTcXmlTextWriterFullEndElementP01,19},
	{UTcXmlTextWriterStartCommentP01,20},

	{UTcXmlTextWriterEndCommentP01,21},
	{UTcXmlTextWriterWriteFormatCommentP01,22},
	{UTcXmlTextWriterWriteVFormatCommentP01,23},
	{UTcXmlTextWriterWriteCommentP01,24},
	{UTcXmlTextWriterStartAttributeP01,25},
	{UTcXmlTextWriterStartAttributeNSP01,26},
	{UTcXmlTextWriterEndAttributeP01,27},
	{UTcXmlTextWriterStartPIP01,28},
	{UTcXmlTextWriterEndPIP01,29},
	{UTcXmlTextWriterStartCDATAP01,30},
	
	{UTcXmlTextWriterEndCDATAP01,31},
	{UTcXmlTextWriterStartDTDP01,32},
	{UTcXmlTextWriterEndDTDP01,33},
	{UTcXmlTextWriterStartDTDElementP01,34},
	{UTcXmlTextWriterEndDTDElementP01,35},
	{UTcXmlTextWriterStartDTDAttlistP01,36},
	{UTcXmlTextWriterEndDTDAttlistP01,37},
	{UTcXmlTextWriterStartDTDEntityP01,38},
	{UTcXmlTextWriterEndDTDEntityP01,39},
	{UTcXmlTextWriterWriteDTDNotationP01,40},
	
	{UTcXmlTextWriterSetIndentP01,41},
	{UTcXmlTextWriterSetIndentStringP01,42},
	{UTcXmlTextWriterFlushP01,43},
	{UTcXmlTextWriterWriteElementP01,44},
	{UTcXmlTextWriterWriteElementNSP01,45},
	{UTcXmlTextWriterWriteStringP01,46},
	{UTcXmlTextWriterWriteBase64P01,47},
	{UTcXmlTextWriterWriteBinHexP01,48},
	{UTcXmlTextWriterWriteAttributeP01,49},
	{UTcXmlTextWriterWriteAttributeNSP01,50},
	
	{UTcXmlTextWriterWritePIP01,51},
	{UTcXmlTextWriterWriteCDATAP01,52},
	{UTcXmlTextWriterWriteDTDP01,53},
	{UTcXmlTextWriterWriteDTDAttlistP01,54},
	{UTcXmlTextWriterWriteDTDElementP01,55},
	{UTcXmlTextWriterWriteDTDInternalEntityP01,56},
	{UTcXmlTextWriterWriteDTDExternalEntityP01,57},
	{UTcXmlTextWriterWriteDTDEntityP01,58},
	{UTcXmlTextWriterWriteFormatElementP01,59},
	{UTcXmlTextWriterWriteFormatDTDInternalEntityP01,60},
	
	{UTcXmlTextWriterWriteFormatDTDAttlistP01,61},
	{UTcXmlTextWriterWriteFormatDTDP01,62},
	{UTcXmlTextWriterWriteFormatCDATAP01,63},
	{UTcXmlTextWriterWriteElementP02,64},
	{UTcXmlTextWriterEndElementP01,65},
	{UTcXmlTextWriterWriteRawLenP01,66},
	{UTcXmlTextWriterWriteRawP01,67},
	{UTcXmlTextWriterWriteDTDExternalEntityContentsP01,68},
	
	{ NULL, 0 },
	
};
