/*
*  libxml test suite
*
* Copyright (c) 2012 Samsung Electronics Co., Ltd. All rights reserved.
*
* Contact: {Maintainer Name} <{Maintainer Email}>
* 
* Licensed under the Apache License, Version 2.0 (the "License");
* you may not use this file except in compliance with the License.
* You may obtain a copy of the License at
*
* http://www.apache.org/licenses/LICENSE-2.0
*
* Unless required by applicable law or agreed to in writing, software
* distributed under the License is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
* See the License for the specific language governing permissions and
* limitations under the License.
*
*/ 

#include "utc_libxml_include.h"
#include "libxml/xmlschemas.h"



static int call_tests = 0;
static xmlDocPtr api_doc = NULL;

//#define gen_nb_const_char_ptr 4
#define gen_nb_const_char_ptr 3

static char *gen_const_char_ptr(int no, int nr ATTRIBUTE_UNUSED) {
#if 0
    if (no == 0) return((char *) "foo");
    if (no == 1) return((char *) "<foo/>");
    if (no == 2) return((char *) HOMEENT2);
#endif
	return((char *) HOMESCHEMA);
    return(NULL);
}
static void des_const_char_ptr(int no ATTRIBUTE_UNUSED, const char *val ATTRIBUTE_UNUSED, int nr ATTRIBUTE_UNUSED) {
}

//#define gen_nb_int 4
#define gen_nb_int 2

static int gen_int(int no, int nr ATTRIBUTE_UNUSED) {
  //  if (no == 0) return(0);
    if (no == 0) return(1);
 //   if (no == 2) return(-1);
    if (no == 1) return(122);
    return(-1);
}
static void desret_int(int val ATTRIBUTE_UNUSED) {
}
static void des_int(int no ATTRIBUTE_UNUSED, int val ATTRIBUTE_UNUSED, int nr ATTRIBUTE_UNUSED) {
}

//#define gen_nb_xmlDocPtr 4
#define gen_nb_xmlDocPtr 2
static xmlDocPtr gen_xmlDocPtr(int no, int nr ATTRIBUTE_UNUSED) {

	if (no == 0) return(xmlNewDoc(BAD_CAST "1.0"));
    if (no == 1) return(xmlReadMemory("<foo/>", 6, "test", NULL, 0));
//  if (no == 2) return(xmlReadMemory("<!DOCTYPE foo []> <foo/>", 24, "test", NULL, 0));
    return(NULL);
	//return (xmlParseFile(HOMESCHEMAXML) );
}
static void des_xmlDocPtr(int no ATTRIBUTE_UNUSED, xmlDocPtr val, int nr ATTRIBUTE_UNUSED) {
    if ((val != NULL) && (val != api_doc) && (val->doc != api_doc))
        xmlFreeDoc(val);
}

#define gen_nb_xmlSchemaValidCtxtPtr 1
static xmlSchemaValidCtxtPtr gen_xmlSchemaValidCtxtPtr(int no ATTRIBUTE_UNUSED, int nr ATTRIBUTE_UNUSED) {
    char * URL;
    xmlSchemaParserCtxtPtr ctxt;
    xmlSchemaPtr sch;
    xmlSchemaValidCtxtPtr ret_val;
	URL = gen_const_char_ptr(0, 0);
	ctxt = xmlSchemaNewParserCtxt((const char *)URL);
	if (ctxt == NULL)
		return(NULL);
	sch = xmlSchemaParse(ctxt);
	if (sch == NULL)
		return(NULL);
	ret_val = xmlSchemaNewValidCtxt(sch);
		return (ret_val);
	return(NULL);
}
static void des_xmlSchemaValidCtxtPtr(int no ATTRIBUTE_UNUSED, xmlSchemaValidCtxtPtr val ATTRIBUTE_UNUSED, int nr ATTRIBUTE_UNUSED) {
}

//#define gen_nb_xmlParserInputBufferPtr 8
#define gen_nb_xmlParserInputBufferPtr 3

static xmlParserInputBufferPtr gen_xmlParserInputBufferPtr(int no, int nr ATTRIBUTE_UNUSED) {
    if (no == 0) return(xmlParserInputBufferCreateFilename(HOMEENT2, XML_CHAR_ENCODING_NONE));
    if (no == 1) return(xmlParserInputBufferCreateFilename(HOMERECxml19980210, XML_CHAR_ENCODING_NONE));
    if (no == 2) return(xmlParserInputBufferCreateFilename(HOMEXHTML1STRICTDTD, XML_CHAR_ENCODING_NONE));
    return(NULL);

}
static void des_xmlParserInputBufferPtr(int no ATTRIBUTE_UNUSED, xmlParserInputBufferPtr val, int nr ATTRIBUTE_UNUSED) {
    xmlFreeParserInputBuffer(val);
}


//#define gen_nb_xmlCharEncoding 4
#define gen_nb_xmlCharEncoding 1
static xmlCharEncoding gen_xmlCharEncoding(int no, int nr ATTRIBUTE_UNUSED) {
    if (no == 0) return(XML_CHAR_ENCODING_UTF8);
    if (no == 1) return(XML_CHAR_ENCODING_NONE);
    if (no == 2) return(XML_CHAR_ENCODING_8859_1);
    return(XML_CHAR_ENCODING_ERROR);
}
static void des_xmlCharEncoding(int no ATTRIBUTE_UNUSED, xmlCharEncoding val ATTRIBUTE_UNUSED, int nr ATTRIBUTE_UNUSED) {
}


//#define gen_nb_xmlSAXHandlerPtr 2
#define gen_nb_xmlSAXHandlerPtr 1
static xmlSAXHandlerPtr gen_xmlSAXHandlerPtr(int no, int nr ATTRIBUTE_UNUSED) {
#ifdef LIBXML_SAX1_ENABLED
    if (no == 0) return((xmlSAXHandlerPtr) &xmlDefaultSAXHandler);
#endif
    return(NULL);
}

static void des_xmlSAXHandlerPtr(int no ATTRIBUTE_UNUSED, xmlSAXHandlerPtr val ATTRIBUTE_UNUSED, int nr ATTRIBUTE_UNUSED) {
}

//#define gen_nb_userdata 3
#define gen_nb_userdata 1

static void *gen_userdata(int no, int nr ATTRIBUTE_UNUSED) {
    if (no == 0) return((void *) &call_tests);
  //  if (no == 1) return((void *) -1);
    return(NULL);
}

static void des_userdata(int no ATTRIBUTE_UNUSED, void *val ATTRIBUTE_UNUSED, int nr ATTRIBUTE_UNUSED) {
}

static void desret_xmlSchemaParserCtxtPtr(xmlSchemaParserCtxtPtr val) {
    xmlSchemaFreeParserCtxt(val);
}

static void UTcxmlSchemaNewParserCtxtP01()
{
	xmlSchemaParserCtxtPtr ret_val;
	char * URL; /* the location of the schema */
	int n_URL;

	for (n_URL = 0;n_URL < gen_nb_const_char_ptr;n_URL++) {
		URL = gen_const_char_ptr(n_URL, 0);

		ret_val = xmlSchemaNewParserCtxt((const char *)URL);
		DTS_CHECK_NE_MESSAGE("xmlSchemaNewParserCtxt", (void *)ret_val, (void *)NULL, "xmlSchemaNewParserCtxt Failed");
		
		desret_xmlSchemaParserCtxtPtr(ret_val);
		des_const_char_ptr(n_URL, (const char *)URL, 0);
		xmlResetLastError();
	}
}

static void UTcxmlSchemaNewMemParserCtxtP01()
{
	xmlSchemaParserCtxtPtr ret_val;
	char * buffer; /* a pointer to a char array containing the schemas */
	int n_buffer;
	int size; /* the size of the array */
	int n_size;

	for (n_buffer = 0;n_buffer < gen_nb_const_char_ptr;n_buffer++) {
	for (n_size = 0;n_size < gen_nb_int;n_size++) {
		buffer = gen_const_char_ptr(n_buffer, 0);
		size = gen_int(n_size, 1);

		ret_val = xmlSchemaNewMemParserCtxt((const char *)buffer, size);
		DTS_CHECK_NE_MESSAGE("xmlSchemaNewMemParserCtxt", (void *)ret_val, (void *)NULL, "xmlSchemaNewMemParserCtxt Failed");
		desret_xmlSchemaParserCtxtPtr(ret_val);
		des_const_char_ptr(n_buffer, (const char *)buffer, 0);
		des_int(n_size, size, 1);
		xmlResetLastError();
		}
	}
}

static void UTcxmlSchemaNewDocParserCtxtP01()
{
	xmlSchemaParserCtxtPtr ret_val;
	xmlDocPtr doc; /* a preparsed document tree */
	int n_doc;

	for (n_doc = 0;n_doc < gen_nb_xmlDocPtr;n_doc++) {
		doc = gen_xmlDocPtr(n_doc, 0);

		ret_val = xmlSchemaNewDocParserCtxt(doc);
		DTS_CHECK_NE_MESSAGE("xmlSchemaNewDocParserCtxt", (void *)ret_val, (void *)NULL, "xmlSchemaNewDocParserCtxt Failed");
		desret_xmlSchemaParserCtxtPtr(ret_val);
		des_xmlDocPtr(n_doc, doc, 0);
		xmlResetLastError();
	}
}

static void UTcxmlSchemaFreeParserCtxtP01()
{
	xmlSchemaParserCtxtPtr ret_val;
	xmlDocPtr doc; /* a preparsed document tree */
	int n_doc;

	for (n_doc = 0;n_doc < gen_nb_xmlDocPtr;n_doc++) {
		doc = gen_xmlDocPtr(n_doc, 0);

		ret_val = xmlSchemaNewDocParserCtxt(doc);
		DTS_CHECK_NE_MESSAGE("xmlSchemaFreeParserCtxt", (void *)ret_val, (void *)NULL, "xmlSchemaNewDocParserCtxt Failed");
		xmlSchemaFreeParserCtxt(ret_val);
		DTS_CHECK_NE_MESSAGE("xmlSchemaFreeParserCtxt", (void *)ret_val, (void *)NULL, "xmlSchemaFreeParserCtxt Failed");
	}
}	

static void UTcxmlSchemaSetParserErrorsP01()
{
	DTS_CHECK_EQ_MESSAGE("UTcxmlSchemaSetParserErrorsP01", (void *)1, (void *)1, "UTcxmlSchemaSetParserErrorsP01 Failed");
}

static void UTcxmlSchemaSetValidErrorsP01()
{
	DTS_CHECK_EQ_MESSAGE("UTcxmlSchemaSetValidErrorsP01", (void *)1, (void *)1, "UTcxmlSchemaSetValidErrorsP01 Failed");
}

static void UTcxmlSchemaParseP01()
{
	xmlSchemaParserCtxtPtr ctxt;
	xmlSchemaPtr ret_val;
	char * URL; /* the location of the schema */
	int n_URL;

	for (n_URL = 0;n_URL < gen_nb_const_char_ptr;n_URL++) {
		URL = gen_const_char_ptr(n_URL, 0);
		ctxt = xmlSchemaNewParserCtxt((const char *)URL);
		DTS_CHECK_NE_MESSAGE("xmlSchemaParse", (void *)ctxt, (void *)NULL, "xmlSchemaNewParserCtxt Failed");
		ret_val = xmlSchemaParse(ctxt);
		DTS_CHECK_NE_MESSAGE("xmlSchemaParse", (void *)ret_val, (void *)NULL, "xmlSchemaParse Failed");
		xmlSchemaFree(ret_val);
		desret_xmlSchemaParserCtxtPtr(ctxt);
		des_const_char_ptr(n_URL, (const char *)URL, 0);
		xmlResetLastError();
	}
}

static void UTcxmlSchemaFreeP01()
{
	xmlSchemaParserCtxtPtr ctxt;
	xmlSchemaPtr ret_val;
	char * URL; /* the location of the schema */
	int n_URL;

	for (n_URL = 0;n_URL < gen_nb_const_char_ptr;n_URL++) {
		URL = gen_const_char_ptr(n_URL, 0);
		ctxt = xmlSchemaNewParserCtxt((const char *)URL);
		DTS_CHECK_NE_MESSAGE("xmlSchemaFree", (void *)ctxt, (void *)NULL, "xmlSchemaNewParserCtxt Failed");
		ret_val = xmlSchemaParse(ctxt);
		xmlSchemaFree(ret_val);
		DTS_CHECK_NE_MESSAGE("xmlSchemaFree", (void *)ret_val, (void *)NULL, "xmlSchemaFree Failed");
		desret_xmlSchemaParserCtxtPtr(ctxt);
		des_const_char_ptr(n_URL, (const char *)URL, 0);
		xmlResetLastError();
	}
}

static void UTcxmlSchemaNewValidCtxtP01()
{
	xmlSchemaParserCtxtPtr ctxt;
	xmlSchemaPtr sch;
	xmlSchemaValidCtxtPtr ret_val;
	char * URL; /* the location of the schema */
	int n_URL;

	for (n_URL = 0;n_URL < gen_nb_const_char_ptr;n_URL++) {
		URL = gen_const_char_ptr(n_URL, 0);
		ctxt = xmlSchemaNewParserCtxt((const char *)URL);
		DTS_CHECK_NE_MESSAGE("xmlSchemaNewValidCtxt", (void *)ctxt, (void *)NULL, "xmlSchemaNewParserCtxt Failed");
		
		sch = xmlSchemaParse(ctxt);
		DTS_CHECK_NE_MESSAGE("xmlSchemaNewValidCtxt", (void *)sch, (void *)NULL, "xmlSchemaParse Failed");
		
		ret_val = xmlSchemaNewValidCtxt(sch);
		DTS_CHECK_NE_MESSAGE("xmlSchemaNewValidCtxt", (void *)ret_val, (void *)NULL, "xmlSchemaNewValidCtxt Failed");
		
		xmlSchemaFreeValidCtxt(ret_val);
		xmlSchemaFree(sch);
		desret_xmlSchemaParserCtxtPtr(ctxt);
		des_const_char_ptr(n_URL, (const char *)URL, 0);
		xmlResetLastError();
	}
}

static void UTcxmlSchemaFreeValidCtxtP01()
{
	xmlSchemaParserCtxtPtr ctxt;
	xmlSchemaPtr sch;
	xmlSchemaValidCtxtPtr ret_val;
	char * URL; /* the location of the schema */
	int n_URL;

	for (n_URL = 0;n_URL < gen_nb_const_char_ptr;n_URL++) {
		URL = gen_const_char_ptr(n_URL, 0);
		ctxt = xmlSchemaNewParserCtxt((const char *)URL);
		DTS_CHECK_NE_MESSAGE("xmlSchemaFreeValidCtxt", (void *)ctxt, (void *)NULL, "xmlSchemaNewValidCtxt Failed");
		
		sch = xmlSchemaParse(ctxt);
		DTS_CHECK_NE_MESSAGE("xmlSchemaFreeValidCtxt", (void *)sch, (void *)NULL, "xmlSchemaParse Failed");
		
		ret_val = xmlSchemaNewValidCtxt(sch);
		xmlSchemaFreeValidCtxt(ret_val);
		DTS_CHECK_NE_MESSAGE("xmlSchemaFreeValidCtxt", (void *)ret_val, (void *)NULL, "xmlSchemaFreeValidCtxt Failed");
		
		xmlSchemaFree(sch);
		desret_xmlSchemaParserCtxtPtr(ctxt);
		des_const_char_ptr(n_URL, (const char *)URL, 0);
		xmlResetLastError();
	}
}

static void UTcxmlSchemaValidateDocP01()
{
	int ret_val;
	xmlSchemaValidCtxtPtr ctxt; /* a schema validation context */
	int n_ctxt;
	xmlDocPtr doc; /* a parsed document tree */
	int n_doc;

	for (n_ctxt = 0;n_ctxt < gen_nb_xmlSchemaValidCtxtPtr;n_ctxt++) {
	for (n_doc = 0;n_doc < gen_nb_xmlDocPtr;n_doc++) {
		ctxt = gen_xmlSchemaValidCtxtPtr(n_ctxt, 0);
		//doc = gen_xmlDocPtr(n_doc, 1);
		doc = xmlParseFile(HOMESCHEMAXML);
		ret_val = xmlSchemaValidateDoc(ctxt, doc);
		DTS_CHECK_EQ_MESSAGE("xmlSchemaValidateDoc", (void *)ret_val, (void *)0, "xmlSchemaValidateDoc Failed");
		desret_int(ret_val);
		des_xmlSchemaValidCtxtPtr(n_ctxt, ctxt, 0);
		des_xmlDocPtr(n_doc, doc, 1);
		xmlResetLastError();
		}
	}
}

static void UTcxmlSchemaValidateStreamP01()
{
	int ret_val;
	xmlSchemaValidCtxtPtr ctxt; /* a schema validation context */
	int n_ctxt;
	xmlParserInputBufferPtr input; /* the input to use for reading the data */
	int n_input;
	xmlCharEncoding enc; /* an optional encoding information */
	int n_enc;
	xmlSAXHandlerPtr sax; /* a SAX handler for the resulting events */
	int n_sax;
	void * user_data; /* the context to provide to the SAX handler. */
	int n_user_data;

	for (n_ctxt = 0;n_ctxt < gen_nb_xmlSchemaValidCtxtPtr;n_ctxt++) {
	for (n_input = 0;n_input < gen_nb_xmlParserInputBufferPtr;n_input++) {
	for (n_enc = 0;n_enc < gen_nb_xmlCharEncoding;n_enc++) {
	for (n_sax = 0;n_sax < gen_nb_xmlSAXHandlerPtr;n_sax++) {
	for (n_user_data = 0;n_user_data < gen_nb_userdata;n_user_data++) {
		ctxt = gen_xmlSchemaValidCtxtPtr(n_ctxt, 0);
		//input = gen_xmlParserInputBufferPtr(n_input, 1);
		DTS_CHECK_NE_MESSAGE("xmlSchemaValidateStream", (void *)ctxt, (void *)0, "gen_xmlSchemaValidCtxtPtr Failed");
		input = xmlParserInputBufferCreateFilename(HOMESCHEMAXML, XML_CHAR_ENCODING_NONE);
		DTS_CHECK_NE_MESSAGE("xmlSchemaValidateStream", (void *)input, (void *)0, "xmlParserInputBufferCreateFilename Failed");
		enc = gen_xmlCharEncoding(n_enc, 2);
		DTS_CHECK_NE_MESSAGE("xmlSchemaValidateStream", (void *)enc, (void *)0, "gen_xmlCharEncoding Failed");
		sax = gen_xmlSAXHandlerPtr(n_sax, 3);
		DTS_CHECK_NE_MESSAGE("xmlSchemaValidateStream", (void *)sax , (void *)0, "gen_xmlSAXHandlerPtr Failed");
		user_data = gen_userdata(n_user_data, 4);
		DTS_CHECK_NE_MESSAGE("xmlSchemaValidateStream", (void *)user_data , (void *)0, "gen_userdata Failed");
		DTS_PRINT("xmlSchemaValidateStream", "Loop");
		ret_val = xmlSchemaValidateStream(ctxt, input, enc, sax, user_data);
		DTS_CHECK_NE_MESSAGE("xmlSchemaValidateStream", (void *)ret_val, (void *)-1, "xmlSchemaValidateStream Failed");
		desret_int(ret_val);
		#if 0
		des_xmlSchemaValidCtxtPtr(n_ctxt, ctxt, 0);
		des_xmlParserInputBufferPtr(n_input, input, 1);
		des_xmlCharEncoding(n_enc, enc, 2);
		des_xmlSAXHandlerPtr(n_sax, sax, 3);
		des_userdata(n_user_data, user_data, 4);
		#endif
		xmlResetLastError();
			}
		  }
		}
	  }
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
	{UTcxmlSchemaNewParserCtxtP01,1},
	{UTcxmlSchemaNewMemParserCtxtP01,2},
	{UTcxmlSchemaNewDocParserCtxtP01,3},
	{UTcxmlSchemaFreeParserCtxtP01,4},
	{UTcxmlSchemaParseP01,5},
	{UTcxmlSchemaFreeP01,6},
	{UTcxmlSchemaNewValidCtxtP01,7},
	{UTcxmlSchemaFreeValidCtxtP01,8},
	{UTcxmlSchemaValidateDocP01,9},
	//{UTcxmlSchemaValidateStreamP01,10},
	{UTcxmlSchemaSetParserErrorsP01,11},
	{UTcxmlSchemaSetValidErrorsP01,12},
	{ NULL, 0 },
	
};


