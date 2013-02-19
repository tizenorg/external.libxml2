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
#include <libxml/xmlwriter.h>
#include <libxml/xmlreader.h>




/***************************************************************************
* SUTsXmlReader
***************************************************************************/
#define MY_ENCODING "ISO-8859-1"

#define	OUTFILE1	"/Home/writer1.res"
#define	OUTFILE2	"/Home/missing.xml"
#define	OUTFILE3	"/Home/test.out"

#define gen_nb_xmlTextReaderLocatorPtr 1
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
//#if 0
static xmlNodePtr
get_api_root_1(void) {
    if ((api_root == NULL) || (api_root->type != XML_ELEMENT_NODE)) {
        get_api_doc();
	if ((api_doc != NULL) && (api_doc->children != NULL) &&
	    (api_doc->children->next != NULL) &&
	    (api_doc->children->next->type == XML_ELEMENT_NODE))
	    api_root = api_doc->children->next;
    }
    api_root->type = XML_NAMESPACE_DECL;
    return(api_root);
}
//#endif

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

static int gen_int_ReaderForMemory(int no, int nr ATTRIBUTE_UNUSED) {
    if (no == 0) return(5);
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
    if (no == 2) return((char *) ENT2);
    return(NULL);
}
static void des_const_char_ptr(int no ATTRIBUTE_UNUSED, const char *val ATTRIBUTE_UNUSED, int nr ATTRIBUTE_UNUSED) {
}

static void desret_xmlParserCtxtPtr(xmlParserCtxtPtr val) {
    xmlFreeParserCtxt(val);
}

#define gen_nb_xmlNodePtr 2
static xmlNodePtr gen_xmlNodePtr(int no, int nr ATTRIBUTE_UNUSED) {
    if (no == 0) return(xmlNewPI(BAD_CAST UTSXMLHOME"/valid", NULL));
    if (no == 1) return(get_api_root());
    return(NULL);
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

#define gen_nb_const_xmlChar_ptr_ptr 1
static xmlChar ** gen_const_xmlChar_ptr_ptr(int no ATTRIBUTE_UNUSED, int nr ATTRIBUTE_UNUSED) {
    return(NULL);
}
static void des_const_xmlChar_ptr_ptr(int no ATTRIBUTE_UNUSED, const xmlChar ** val ATTRIBUTE_UNUSED, int nr ATTRIBUTE_UNUSED) {
}

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

/***************************************************************************/
/***************************************************************************/
#define gen_nb_filepath 8
#define gen_nb_parseroptions 5
#define gen_nb_xmlTextReaderPtr 4
/**************************************************************************/
/**************************************************************************/
static const char *gen_filepath(int no, int nr ATTRIBUTE_UNUSED) {
    if (no == 0) return(MISSINGXML);
    if (no == 1) return("<foo/>");
    if (no == 2) return(ENT2);
    if (no == 3) return(RECxml19980210);
    if (no == 4) return(XHTML1STRICTDTD);
    if (no == 5) return(REMOTE1GOOD);
    if (no == 6) return(REMOTE1BAD);
    return(NULL);
}

static void des_filepath(int no ATTRIBUTE_UNUSED, const char *val ATTRIBUTE_UNUSED, int nr ATTRIBUTE_UNUSED) {
}
static void desret_xmlTextReaderPtr(xmlTextReaderPtr val) {
    xmlFreeTextReader(val);
}


static int gen_parseroptions(int no, int nr ATTRIBUTE_UNUSED) {
    if (no == 0) return(XML_PARSE_NOBLANKS | XML_PARSE_RECOVER);
    if (no == 1) return(XML_PARSE_NOENT | XML_PARSE_DTDLOAD | XML_PARSE_DTDATTR | XML_PARSE_DTDVALID | XML_PARSE_NOCDATA);
    if (no == 2) return(XML_PARSE_XINCLUDE | XML_PARSE_NSCLEAN);
    if (no == 3) return(XML_PARSE_XINCLUDE | XML_PARSE_NODICT);
    return(XML_PARSE_SAX1);
}

static void des_parseroptions(int no ATTRIBUTE_UNUSED, int val ATTRIBUTE_UNUSED, int nr ATTRIBUTE_UNUSED) {
}


static xmlTextReaderPtr gen_xmlTextReaderPtr(int no, int nr ATTRIBUTE_UNUSED) {
    if (no == 0) return(xmlNewTextReaderFilename(ENT2));
    if (no == 1) return(xmlNewTextReaderFilename(RECxml19980210));
    if (no == 2) return(xmlNewTextReaderFilename(XHTML1STRICTDTD));
    return(NULL);
}

static xmlTextReaderPtr gen_xmlTextReaderPtr_TextReaderBase(int no, int nr ATTRIBUTE_UNUSED) {
    if (no == 0) return(xmlNewTextReaderFilename(ENT2));
    if (no == 1) return(xmlNewTextReaderFilename(RECxml19980210));
    if(no == 2)
    {
    	xmlTextReaderPtr txtredptr;

      	txtredptr = xmlNewTextReaderFilename(RECxml19980210);
    	xmlTextReaderRead(txtredptr);
    	return(txtredptr);
     }
    return(NULL);
}

static xmlTextReaderPtr gen_xmlTextReaderPtr_1(int no, int nr ATTRIBUTE_UNUSED) {
    if (no == 0) return(xmlNewTextReaderFilename(ENT2));
    if (no == 1) return(xmlNewTextReaderFilename(RECxml19980210));
    if(no == 2)
    {
    	xmlTextReaderPtr txtredptr;
    	xmlNodePtr xmlnodeptr;
      	txtredptr = xmlNewTextReaderFilename(TESTXML);
    	xmlnodeptr = get_api_root_1();
    	return(txtredptr);
     }
    return(NULL);
}
static void des_xmlTextReaderPtr(int no ATTRIBUTE_UNUSED, xmlTextReaderPtr val, int nr ATTRIBUTE_UNUSED) {
    if (val != NULL) xmlFreeTextReader(val);
}

static void desret_xmlChar_ptr(xmlChar *val) {
    if (val != NULL)
      xmlFree(val);
}

static void desret_const_xmlChar_ptr(const xmlChar *val ATTRIBUTE_UNUSED) {
}

static void desret_xmlDocPtr(xmlDocPtr val) {
    if (val != api_doc)
      xmlFreeDoc(val);
}
/***************************************************************************/
/***************************************************************************/

	/**    
	* @test			UTcXmlNewTextReaderFilenameP01
	* @brief		xmlTextReaderPtr xmlNewTextReaderFilename(const char *URI)
	* @desc			Positive Test for xmlNewTextReaderFilename
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Michel Anthony (michelj@samsung.com)
	* @return		void
	* @see			none
	* @remarks		input1: [N/A, N/A] @n
	*   			{const char*(URI)} => {N/A | xmlTextReaderPtr(!=NULL)} @n
	* @b priority	Middle
	* @b etc		none
	*/
static void UTcXmlNewTextReaderFilenameP01()
{
	xmlTextReaderPtr ret_val;
	const char * URI; /* the URI of the resource to process */
	int n_URI;

	for (n_URI = 0;n_URI < gen_nb_filepath;n_URI++) {
		URI = gen_filepath(n_URI, 0);

		ret_val = xmlNewTextReaderFilename(URI);
		if(ret_val == NULL && URI == NULL)
		{
			//Negative test
			DTS_CHECK_EQ_MESSAGE("xmlNewTextReaderFilename", (void *)ret_val, (void *)NULL, "xmlNewTextReaderFilename Failed");

		}
		if(ret_val != NULL && URI != NULL)
		{
			//Positive test
			DTS_CHECK_NE_MESSAGE("xmlNewTextReaderFilename", (void *)ret_val, (void *)NULL, "xmlNewTextReaderFilename Failed");
		}
		desret_xmlTextReaderPtr(ret_val);
		des_filepath(n_URI, URI, 0);
		xmlResetLastError();
	}
}

	/**
	* @test			UTcXmlReaderForDocP01
	* @brief		xmlTextReaderPtr xmlReaderForDoc(const xmlChar * cur, const char *URL,
	*                   const char *encoding, int options)
	* @desc			Positive Test for xmlReaderForDoc
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Michel Anthony (michelj@samsung.com)
	* @return		void
	* @see			none
	* @remarks		input1: [N/A, N/A] @n
	*   			{const xmlChar* (cur), const char *(URL),const char*(encoding), int(options)} => {N/A | xmlTextReaderPtr(!=NULL)} @n
	* @b priority	Middle
	* @b etc		none
	*/
static void UTcXmlReaderForDocP01()
{
	xmlTextReaderPtr ret_val;
	xmlChar * cur; /* a pointer to a zero terminated string */
	int n_cur;
	const char * URL; /* the base URL to use for the document */
	int n_URL;
	char * encoding; /* the document encoding, or NULL */
	int n_encoding;
	int options; /* a combination of xmlParserOption */
	int n_options;

	for (n_cur = 0;n_cur < gen_nb_const_xmlChar_ptr;n_cur++) {
	for (n_URL = 0;n_URL < gen_nb_filepath;n_URL++) {
	for (n_encoding = 0;n_encoding < gen_nb_const_char_ptr;n_encoding++) {
	for (n_options = 0;n_options < gen_nb_parseroptions;n_options++) {
		cur = gen_const_xmlChar_ptr(n_cur, 0);
		URL = gen_filepath(n_URL, 1);
		encoding = gen_const_char_ptr(n_encoding, 2);
		options = gen_parseroptions(n_options, 3);

		/* @remarks		input1: [N/A, N/A] @n
		*   			{const xmlChar* (cur), const char *(URL),const char*(encoding), int(options)} => {N/A | xmlTextReaderPtr(!=NULL)} @n
		*/
		ret_val = xmlReaderForDoc((const xmlChar *)cur, URL, (const char *)encoding, options);

		if(ret_val != NULL && cur != NULL)
		{
			//Positive test
			DTS_CHECK_NE_MESSAGE("xmlReaderForDoc", (void *)ret_val, (void *)NULL, "xmlReaderForDoc Failed");

			if(cur != NULL)
			{
				cur = NULL;
				ret_val = xmlReaderForDoc((const xmlChar *)cur, URL, (const char *)encoding, options);
			//Negative test
				DTS_CHECK_EQ_MESSAGE("xmlReaderForDoc", (void *)ret_val, (void *)NULL, "xmlReaderForDoc Failed");
			}
		}
		desret_xmlTextReaderPtr(ret_val);
		des_const_xmlChar_ptr(n_cur, (const xmlChar *)cur, 0);
		des_filepath(n_URL, URL, 1);
		des_const_char_ptr(n_encoding, (const char *)encoding, 2);
		des_parseroptions(n_options, options, 3);
		xmlResetLastError();
	}
	}
	}
	}
}
	/**
	* @test			UTcXmlReaderForFileP01
	* @brief		xmlTextReaderPtr xmlReaderForFile(const char *filename, const char *encoding, int options)
	* @desc			Positive Test for xmlReaderForFile
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Michel Anthony (michelj@samsung.com)
	* @return		void
	* @see			none
	* @remarks		input1: [N/A, N/A] @n
	*   			{const char *(filename), const char *(encoding), int (options)} => {N/A | xmlTextReaderPtr(!=NULL)} @n
	* @b priority	Middle
	* @b etc		none
	*/
static void UTcXmlReaderForFileP01()
{
	xmlTextReaderPtr ret_val;
	const char * filename; /* a file or URL */
	int n_filename;
	char * encoding; /* the document encoding, or NULL */
	int n_encoding;
	int options; /* a combination of xmlParserOption */
	int n_options;

	for (n_filename = 0;n_filename < gen_nb_filepath;n_filename++) {
	for (n_encoding = 0;n_encoding < gen_nb_const_char_ptr;n_encoding++) {
	for (n_options = 0;n_options < gen_nb_parseroptions;n_options++) {
		filename = gen_filepath(n_filename, 0);
		encoding = gen_const_char_ptr(n_encoding, 1);
		options = gen_parseroptions(n_options, 2);

   /* @remarks	input1: [N/A, N/A] @n
	*   		{const char *(filename), const char *(encoding), int (options)} => {N/A | xmlTextReaderPtr(!=NULL)} @n
  */
	 ret_val = xmlReaderForFile(filename, (const char *)encoding, options);
	  if(ret_val == NULL && filename == NULL)
	  {
		  //Negative test
		  DTS_CHECK_EQ_MESSAGE("xmlReaderForFile", (void *)ret_val, (void *)NULL, "xmlReaderForFile Failed");
	  }

	  if(ret_val != NULL && filename != NULL)
	  {
		  //Positive test
		  DTS_CHECK_NE_MESSAGE("xmlReaderForFile", (void *)ret_val, (void *)NULL, "xmlReaderForFile Failed");
	  }

		desret_xmlTextReaderPtr(ret_val);
		des_filepath(n_filename, filename, 0);
		des_const_char_ptr(n_encoding, (const char *)encoding, 1);
		des_parseroptions(n_options, options, 2);
		xmlResetLastError();
	}
	}
	}
}
	/**
	* @test			UTcXmlReaderForMemoryP01
	* @brief		xmlTextReaderPtr xmlReaderForMemory(const char *buffer, int size, const char *URL,
                   const char *encoding, int options)
	* @desc			Positive Test for xmlReaderForMemory
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Michel Anthony (michelj@samsung.com)
	* @return		void
	* @see			none
	* @remarks		input1: [N/A, N/A] @n
	*   			{const char *(buffer), int (size), const char *(URL),const char *(encoding), int (options)} => {N/A | xmlTextReaderPtr(!=NULL)} @n
	* @b priority	Middle
	* @b etc		none
	*/
static void UTcXmlReaderForMemoryP01()
{
	xmlTextReaderPtr ret_val;
	char * buffer; /* a pointer to a char array */
	int n_buffer;
	int size; /* the size of the array */
	int n_size;
	const char * URL; /* the base URL to use for the document */
	int n_URL;
	char * encoding; /* the document encoding, or NULL */
	int n_encoding;
	int options; /* a combination of xmlParserOption */
	int n_options;

	for (n_buffer = 0;n_buffer < gen_nb_const_char_ptr;n_buffer++) {
	for (n_size = 0;n_size < gen_nb_int;n_size++) {
	for (n_URL = 0;n_URL < gen_nb_filepath;n_URL++) {
	for (n_encoding = 0;n_encoding < gen_nb_const_char_ptr;n_encoding++) {
	for (n_options = 0;n_options < gen_nb_parseroptions;n_options++) {
		buffer = gen_const_char_ptr(n_buffer, 0);
		size = gen_int(n_size, 1);
		URL = gen_filepath(n_URL, 2);
		encoding = gen_const_char_ptr(n_encoding, 3);
		options = gen_parseroptions(n_options, 4);

		/* @remarks		input1: [N/A, N/A] @n
		*   			{const char *(buffer), int (size), const char *(URL),const char *(encoding), int (options)} => {N/A | xmlTextReaderPtr(!=NULL)} @n
		*/
		ret_val = xmlReaderForMemory((const char *)buffer, size, URL, (const char *)encoding, options);
		if(ret_val == NULL && size == 0)
		{
			//Negative test
			DTS_CHECK_EQ_MESSAGE("xmlReaderForMemory", (void *)ret_val, (void *)NULL, "xmlReaderForMemory Failed");

			size = gen_int_ReaderForMemory(n_size, 1);

			ret_val = xmlReaderForMemory((const char *)buffer, size, URL, (const char *)encoding, options);
			if(ret_val != NULL && size > 0)
			{
			   //Positive test
			   DTS_CHECK_NE_MESSAGE("xmlReaderForMemory", (void *)ret_val, (void *)NULL, "xmlReaderForMemory Failed");
			}
		}


		desret_xmlTextReaderPtr(ret_val);
		des_const_char_ptr(n_buffer, (const char *)buffer, 0);
		des_int(n_size, size, 1);
		des_filepath(n_URL, URL, 2);
		des_const_char_ptr(n_encoding, (const char *)encoding, 3);
		des_parseroptions(n_options, options, 4);
		xmlResetLastError();
	}
	}
	}
	}
	}
}
	/**
	* @test			UTcXmlReaderNewDocP01
	* @brief		int xmlReaderNewDoc(xmlTextReaderPtr reader, const xmlChar * cur,
                       const char *URL, const char *encoding, int options)
	* @desc			Positive Test for xmlReaderNewDoc
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Michel Anthony (michelj@samsung.com)
	* @return		void
	* @see			none
	* @remarks		input1: [N/A, N/A] @n
	*   			{xmlTextReaderPtr(reader), const xmlChar*(cur),const char*(URL), const char*(encoding), int(options)} => {N/A | int(0)} @n
	* @b priority	Middle
	* @b etc		none
	*/
static void UTcXmlReaderNewDocP01()
{
    int ret_val;
    xmlTextReaderPtr reader; /* an XML reader */
    int n_reader;
    xmlChar * cur; /* a pointer to a zero terminated string */
    int n_cur;
    const char * URL; /* the base URL to use for the document */
    int n_URL;
    char * encoding; /* the document encoding, or NULL */
    int n_encoding;
    int options; /* a combination of xmlParserOption */
    int n_options;

    for (n_reader = 0;n_reader < gen_nb_xmlTextReaderPtr;n_reader++) {
    for (n_cur = 0;n_cur < gen_nb_const_xmlChar_ptr;n_cur++) {
    for (n_URL = 0;n_URL < gen_nb_filepath;n_URL++) {
    for (n_encoding = 0;n_encoding < gen_nb_const_char_ptr;n_encoding++) {
    for (n_options = 0;n_options < gen_nb_parseroptions;n_options++) {
     //   mem_base = xmlMemBlocks();
        reader = gen_xmlTextReaderPtr(n_reader, 0);
        cur = gen_const_xmlChar_ptr(n_cur, 1);
        URL = gen_filepath(n_URL, 2);
        encoding = gen_const_char_ptr(n_encoding, 3);
        options = gen_parseroptions(n_options, 4);
        /* @remarks		input1: [N/A, N/A] @n
        *   	{xmlTextReaderPtr(reader), const xmlChar*(cur),const char*(URL), const char*(encoding), int(options)} => {N/A | int(!=NULL)} @n
        */
        ret_val = xmlReaderNewDoc(reader, (const xmlChar *)cur, URL, (const char *)encoding, options);
        if(ret_val == 0 && n_reader < 3 && cur != NULL)
        {
        	//Positive test
		 DTS_CHECK_EQ_MESSAGE("xmlReaderNewDoc", (void *)ret_val, (void *)NULL, "xmlReaderNewDoc Failed");
        }

        if(ret_val == -1 && n_reader == 3)
        {
        	//Positive test
		DTS_CHECK_EQ_MESSAGE("xmlReaderNewDoc", (void *)ret_val, (void *)-1, "xmlReaderNewDoc Failed");
        }
        desret_int(ret_val);
        des_xmlTextReaderPtr(n_reader, reader, 0);
        des_const_xmlChar_ptr(n_cur, (const xmlChar *)cur, 1);
        des_filepath(n_URL, URL, 2);
        des_const_char_ptr(n_encoding, (const char *)encoding, 3);
        des_parseroptions(n_options, options, 4);
        xmlResetLastError();
    }
    }
    }
    }
    }
}
	/**
	* @test			UTcXmlReaderNewFileP01
	* @brief		int xmlReaderNewFile(xmlTextReaderPtr reader, const char *filename,
                                            const char *encoding, int options)
	* @desc			Positive Test for xmlReaderNewFile
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Michel Anthony (michelj@samsung.com)
	* @return		void
	* @see			none
	* @remarks		input1: [N/A, N/A] @n
	*   			{xmlTextReaderPtr(reader), const char*(filename),const char*(encoding), int(options)} => {N/A | int(0)} @n
	* @b priority	Middle
	* @b etc		none
	*/
static void UTcXmlReaderNewFileP01()
{
    int ret_val;
    xmlTextReaderPtr reader; /* an XML reader */
    int n_reader;
    const char * filename; /* a file or URL */
    int n_filename;
    char * encoding; /* the document encoding, or NULL */
    int n_encoding;
    int options; /* a combination of xmlParserOption */
    int n_options;

    for (n_reader = 0;n_reader < gen_nb_xmlTextReaderPtr;n_reader++) {
    for (n_filename = 0;n_filename < gen_nb_filepath;n_filename++) {
    for (n_encoding = 0;n_encoding < gen_nb_const_char_ptr;n_encoding++) {
    for (n_options = 0;n_options < gen_nb_parseroptions;n_options++) {
        reader = gen_xmlTextReaderPtr(n_reader, 0);
        filename = gen_filepath(n_filename, 1);
        encoding = gen_const_char_ptr(n_encoding, 2);
        options = gen_parseroptions(n_options, 3);

    	/* @remarks		input1: [N/A, N/A] @n
    	*   			{xmlTextReaderPtr(reader), const char*(filename),const char*(encoding), int(options)} => {N/A | int(0)} @n
       */
        ret_val = xmlReaderNewFile(reader, filename, (const char *)encoding, options);
       if(ret_val == 0 && n_reader < 3)
       {
    	   //Positive Test
		   DTS_CHECK_EQ_MESSAGE("xmlReaderNewFile", (void *)ret_val, (void *)0, "xmlReaderNewFile Failed");
       }

       if(ret_val == -1 && n_reader == 3)
       {
    	   //Negative test
		   DTS_CHECK_EQ_MESSAGE("xmlReaderNewFile", (void *)ret_val, (void *)-1, "xmlReaderNewFile Failed");
       }
        desret_int(ret_val);
        des_xmlTextReaderPtr(n_reader, reader, 0);
        des_filepath(n_filename, filename, 1);
        des_const_char_ptr(n_encoding, (const char *)encoding, 2);
        des_parseroptions(n_options, options, 3);
        xmlResetLastError();
    }
    }
    }
    }
}
	/**
	* @test			UTcXmlReaderNewMemoryP01
	* @brief		int xmlReaderNewMemory(xmlTextReaderPtr reader, const char *buffer, int size,
                   const char *URL, const char *encoding, int options)
	* @desc			Positive Test for xmlReaderNewMemory
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Michel Anthony (michelj@samsung.com)
	* @return		void
	* @see			none
	* @remarks		input1: [N/A, N/A] @n
	*   			{xmlTextReaderPtr(reader),const char*(buffer), int(size),const char*(URL), const char*(encoding), int(options)} => {N/A | int(0)} @n
	* @b priority	Middle
	* @b etc		none
	*/
static void UTcXmlReaderNewMemoryP01()
{
	int ret_val;
	xmlTextReaderPtr reader; /* an XML reader */
	int n_reader;
	char * buffer; /* a pointer to a char array */
	int n_buffer;
	int size; /* the size of the array */
	int n_size;
	const char * URL; /* the base URL to use for the document */
	int n_URL;
	char * encoding; /* the document encoding, or NULL */
	int n_encoding;
	int options; /* a combination of xmlParserOption */
	int n_options;

	for (n_reader = 0;n_reader < gen_nb_xmlTextReaderPtr;n_reader++) {
	for (n_buffer = 0;n_buffer < gen_nb_const_char_ptr;n_buffer++) {
	for (n_size = 0;n_size < gen_nb_int;n_size++) {
	for (n_URL = 0;n_URL < gen_nb_filepath;n_URL++) {
	for (n_encoding = 0;n_encoding < gen_nb_const_char_ptr;n_encoding++) {
	for (n_options = 0;n_options < gen_nb_parseroptions;n_options++) {
		reader = gen_xmlTextReaderPtr(n_reader, 0);
		buffer = gen_const_char_ptr(n_buffer, 1);
		size = gen_int(n_size, 2);
		URL = gen_filepath(n_URL, 3);
		encoding = gen_const_char_ptr(n_encoding, 4);
		options = gen_parseroptions(n_options, 5);

	/* @remarks	input1: [N/A, N/A] @n
	 *   		{xmlTextReaderPtr(reader),const char*(buffer), int(size),const char*(URL), const char*(encoding), int(options)} => {N/A | int(0)} @n
	*/
		ret_val = xmlReaderNewMemory(reader, (const char *)buffer, size, URL, (const char *)encoding, options);

		if(ret_val == -1 && size == 0)
		{
			//Negative test
			DTS_CHECK_EQ_MESSAGE("xmlReaderNewMemory", (void *)ret_val, (void *)-1, "xmlReaderNewMemory Failed");
			if(size == 0)
			{
				size = gen_int_ReaderForMemory(n_size, 2);
				ret_val = xmlReaderNewMemory(reader, (const char *)buffer, size, URL, (const char *)encoding, options);
				if(size != 0 && ret_val == 0)
				{
					//Positive test
					DTS_CHECK_EQ_MESSAGE("xmlReaderNewMemory", (void *)ret_val, (void *)0, "xmlReaderNewMemory Failed");
				}
			}
		}
		desret_int(ret_val);
		des_xmlTextReaderPtr(n_reader, reader, 0);
		des_const_char_ptr(n_buffer, (const char *)buffer, 1);
		des_int(n_size, size, 2);
		des_filepath(n_URL, URL, 3);
		des_const_char_ptr(n_encoding, (const char *)encoding, 4);
		des_parseroptions(n_options, options, 5);
		xmlResetLastError();
	}
	}
	}
	}
	}
	}
}
	/**
	* @test			UTcXmlReaderNewWalkerP01
	* @brief		int xmlReaderNewWalker(xmlTextReaderPtr reader, xmlDocPtr doc)
	* @desc			Positive Test for xmlReaderNewWalker
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Michel Anthony (michelj@samsung.com)
	* @return		void
	* @see			none
	* @remarks		input1: [N/A, N/A] @n
	*   			{xmlTextReaderPtr(reader), xmlDocPtr(doc)} => {N/A | int(0)} @n
	* @b priority	Middle
	* @b etc		none
	*/
static void UTcXmlReaderNewWalkerP01()
{
	int ret_val;
	xmlTextReaderPtr reader; /* an XML reader */
	int n_reader;
	xmlDocPtr doc; /* a preparsed document */
	int n_doc;

	for (n_reader = 0;n_reader < gen_nb_xmlTextReaderPtr;n_reader++) {
	for (n_doc = 0;n_doc < gen_nb_xmlDocPtr;n_doc++) {
		reader = gen_xmlTextReaderPtr(n_reader, 0);
		doc = gen_xmlDocPtr(n_doc, 1);

		ret_val = xmlReaderNewWalker(reader, doc);
		if(ret_val == 0 && n_reader < 3)
		{
			//Positive test
			DTS_CHECK_EQ_MESSAGE("xmlReaderNewWalker", (void *)ret_val, (void *)0, "xmlReaderNewWalker Failed");
		}

		if(ret_val == -1 && n_reader ==3)
		{
			//Negative test
			DTS_CHECK_EQ_MESSAGE("xmlReaderNewWalker", (void *)ret_val, (void *)-1, "xmlReaderNewWalker Failed");
		}
		desret_int(ret_val);
		des_xmlTextReaderPtr(n_reader, reader, 0);
		des_xmlDocPtr(n_doc, doc, 1);
		xmlResetLastError();
	}
	}
}
	/**
	* @test			UTcXmlReaderWalkerP01
	* @brief		xmlTextReaderPtr xmlReaderWalker(xmlDocPtr doc)
	* @desc			Positive Test for xmlReaderWalker
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Michel Anthony (michelj@samsung.com)
	* @return		void
	* @see			none
	* @remarks		input1: [N/A, N/A] @n
	*   			{xmlDocPtr (doc)} => {N/A | xmlTextReaderPtr(ret_val)} @n
	* @b priority	Middle
	* @b etc		none
	*/
static void UTcXmlReaderWalkerP01()
{
    xmlTextReaderPtr ret_val;
    xmlDocPtr doc; /* a preparsed document */
    int n_doc;

    for (n_doc = 0;n_doc < gen_nb_xmlDocPtr;n_doc++) {
        doc = gen_xmlDocPtr(n_doc, 0);

    /* @remarks		input1: [N/A, N/A] @n
     *   			{xmlDocPtr (doc!=NULL)} => {N/A | xmlTextReaderPtr(!=NULL)} @n
     */
        ret_val = xmlReaderWalker(doc);

        if(ret_val != NULL && doc != NULL)
        {
        	//Positive test
		DTS_CHECK_NE_MESSAGE("xmlReaderWalker", (void *)ret_val, (void *)NULL, "xmlReaderWalker Failed");
            if(doc != NULL)
            {
            	//Negative test
            	/* @remarks	input1: [N/A, N/A] @n
            	 *   		{xmlDocPtr (doc=NULL)} => {N/A | xmlTextReaderPtr(!=NULL)} @n
            	*/
            	doc = NULL;
            	ret_val = xmlReaderWalker(doc);
		DTS_CHECK_EQ_MESSAGE("xmlReaderWalker", (void *)ret_val, (void *)NULL, "xmlReaderWalker Failed");
            }
        }

        desret_xmlTextReaderPtr(ret_val);
        des_xmlDocPtr(n_doc, doc, 0);
        xmlResetLastError();
    }
}

	/**
	* @test			UTcXmlTextReaderAttributeCountP01
	* @brief		int xmlTextReaderAttributeCount(xmlTextReaderPtr reader)
	* @desc			Positive Test for xmlTextReaderAttributeCount
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Michel Anthony (michelj@samsung.com)
	* @return		void
	* @see			none
	* @remarks		input1: [N/A, N/A] @n
	*   			{xmlTextReaderPtr(reader)} => {N/A | int(0)} @n
	* @b priority	Middle
	* @b etc		none
	*/
static void UTcXmlTextReaderAttributeCountP01()
{
    int ret_val;
    xmlTextReaderPtr reader; /* the xmlTextReaderPtr used */
    int n_reader;

    for (n_reader = 0;n_reader < gen_nb_xmlTextReaderPtr;n_reader++) {
        reader = gen_xmlTextReaderPtr(n_reader, 0);

        ret_val = xmlTextReaderAttributeCount(reader);
      if(ret_val == 0 && n_reader < 3)
      {
    	  //Positive test
		  DTS_CHECK_EQ_MESSAGE("xmlTextReaderAttributeCount", (void *)ret_val, (void *)0, "xmlTextReaderAttributeCount Failed");
      }
      if(ret_val == -1 && n_reader == 3)
      {
    	  //Negative test
		  DTS_CHECK_EQ_MESSAGE("xmlTextReaderAttributeCount", (void *)ret_val, (void *)-1, "xmlTextReaderAttributeCount Failed");
      }
        desret_int(ret_val);
        des_xmlTextReaderPtr(n_reader, reader, 0);
        xmlResetLastError();
    }
}
	/**
	* @test			UTcXmlTextReaderBaseUriP01
	* @brief		xmlChar *xmlTextReaderBaseUri(xmlTextReaderPtr reader)
	* @desc			Positive Test for xmlTextReaderBaseUri
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Michel Anthony (michelj@samsung.com)
	* @return		void
	* @see			none
	* @remarks		input1: [N/A, N/A] @n
	*   			{xmlTextReaderPtr (reader)} => {N/A | xmlChar *(ret_val)} @n
	* @b priority	Middle
	* @b etc		none
	*/
static void UTcXmlTextReaderBaseUriP01()
{
	xmlChar * ret_val;
	xmlTextReaderPtr reader; /* the xmlTextReaderPtr used */
	int n_reader;
	for (n_reader = 0;n_reader < gen_nb_xmlTextReaderPtr;n_reader++) {
		reader = gen_xmlTextReaderPtr_TextReaderBase(n_reader, 0);

	/* * @remarks
	 * 			Negative Test Case:
	 * 			input1: [Get the reader by reading the file "/Home/SUTstest/valid/ent2" using xmlNewTextReaderFilename() and n_reader == 0,
	 * 						Call "desret_const_xmlChar_ptr()" to free xmlChar pointer(ret_val) and Call "des_xmlTextReaderPtr()" to free reader pointer(reader) ] @n
	 *   		{xmlTextReaderPtr (reader)} => {N/A | const xmlChar(==NULL)} @n
	 *
	 *			Negative Test Case:
	 *   		input2: [Get the reader by reading the file ""/Home/SUTstest/valid/REC-xml-19980210.xml" using xmlNewTextReaderFilename() and n_reader == 1,
	 *   					Call "desret_const_xmlChar_ptr()" to free xmlChar pointer(ret_val) and Call "des_xmlTextReaderPtr()" to free reader pointer(reader)] @n
	 *   		{xmlTextReaderPtr (reader)} => {N/A | const xmlChar(==NULL)} @n
	 *
	 *			Positive Test Case:
	 *   		input3: [Get the reader pointer txtredptr by reading the file "/Home/SUTstest/valid/REC-xml-19980210.xml" using xmlNewTextReaderFilename() and n_reader == 2,
	 *   					Call xmlTextReaderRead(txtredptr) to return reader, Call "desret_const_xmlChar_ptr()" to free xmlChar pointer(ret_val) and Call "des_xmlTextReaderPtr()" to free reader pointer(reader)] @n
	 *   		{xmlTextReaderPtr (reader)} => {N/A | const xmlChar(!=NULL)} @n
	 *
	 *			Negative Test Case:
	 *   		input4: [Get reader pointer as NULL for n_reader > 2, Call "desret_const_xmlChar_ptr()" to free xmlChar pointer(ret_val) and Call "des_xmlTextReaderPtr()" to free reader pointer(reader)] @n
	 *   		{xmlTextReaderPtr (reader)} => {N/A | const xmlChar(==NULL)} @n

	*/
		ret_val = xmlTextReaderBaseUri(reader);

		if(ret_val != NULL && n_reader == 2)
		{
			//Positive test
			DTS_CHECK_NE_MESSAGE("xmlTextReaderBaseUri", (void *)ret_val, (void *)NULL, "xmlTextReaderBaseUri Failed");
		}
		if(ret_val == NULL && n_reader != 2)
		{
			//Negative test
			DTS_CHECK_EQ_MESSAGE("xmlTextReaderBaseUri", (void *)ret_val, (void *)0, "xmlTextReaderBaseUri Failed");
		}
		desret_xmlChar_ptr(ret_val);
		des_xmlTextReaderPtr(n_reader, reader, 0);
		xmlResetLastError();
	}
}

	/**
	* @test			UTcXmlTextReaderCloseP01
	* @brief		int xmlTextReaderClose(xmlTextReaderPtr reader)
	* @desc			Positive Test for xmlTextReaderClose
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Michel Anthony (michelj@samsung.com)
	* @return		void
	* @see			none
	* @remarks		input1: [N/A, N/A] @n
	*   			{xmlTextReaderPtr (reader)} => {N/A | int(0)} @n
	* @b priority	Middle
	* @b etc		none
	*/
static void UTcXmlTextReaderCloseP01()
{
    int ret_val;
    xmlTextReaderPtr reader; /* the xmlTextReaderPtr used */
    int n_reader;

    for (n_reader = 0;n_reader < gen_nb_xmlTextReaderPtr;n_reader++) {
        reader = gen_xmlTextReaderPtr(n_reader, 0);

        ret_val = xmlTextReaderClose(reader);

    	/* @remarks		input1: [N/A, N/A] @n
    	*   			{xmlTextReaderPtr (reader)} => {N/A | int(0)} @n
        */
        if(ret_val == 0 && n_reader < 3)
        {
        	//Positive Test
		DTS_CHECK_EQ_MESSAGE("xmlTextReaderClose", (void *)ret_val, (void *)0, "xmlTextReaderClose Failed");
        }

        if(ret_val == -1 && n_reader == 3)
        {
        	//Negative Test
		DTS_CHECK_EQ_MESSAGE("xmlTextReaderClose", (void *)ret_val, (void *)-1, "xmlTextReaderClose Failed");
        }
        desret_int(ret_val);
        des_xmlTextReaderPtr(n_reader, reader, 0);
        xmlResetLastError();
    }
}
	/**
	* @test			UTcXmlTextReaderConstBaseUriP01
	* @brief		const xmlChar *xmlTextReaderConstBaseUri(xmlTextReaderPtr reader)
	* @desc			Positive Test for xmlTextReaderConstBaseUri
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Michel Anthony (michelj@samsung.com)
	* @return		void
	* @see			none
	* @remarks		input1: [N/A, N/A] @n
	*   			{xmlTextReaderPtr (reader)} => {N/A | const xmlChar(!=NULL)} @n
	* @b priority	Middle
	* @b etc		none
	*/
static void UTcXmlTextReaderConstBaseUriP01()
{
    const xmlChar * ret_val;
    xmlTextReaderPtr reader; /* the xmlTextReaderPtr used */
    int n_reader;

    for (n_reader = 0;n_reader < gen_nb_xmlTextReaderPtr;n_reader++) {
        reader = gen_xmlTextReaderPtr_TextReaderBase(n_reader, 0);

        /* * @remarks
        * 					Negative Test Case:
        * 					input1: [Get the reader by reading the file "/Home/SUTstest/valid/ent2" using xmlNewTextReaderFilename() and n_reader == 0,
        * 								Call "desret_const_xmlChar_ptr()" to free xmlChar pointer(ret_val) and Call "des_xmlTextReaderPtr()" to free reader pointer(reader) ] @n
        *   				{xmlTextReaderPtr (reader)} => {N/A | const xmlChar(==NULL)} @n
        *
        *					Negative Test Case:
        *   				input2: [Get the reader by reading the file ""/Home/SUTstest/valid/REC-xml-19980210.xml" using xmlNewTextReaderFilename() and n_reader == 1,
        *   							Call "desret_const_xmlChar_ptr()" to free xmlChar pointer(ret_val) and Call "des_xmlTextReaderPtr()" to free reader pointer(reader)] @n
        *   				{xmlTextReaderPtr (reader)} => {N/A | const xmlChar(==NULL)} @n
        *
        *					Positive Test Case:
        *   				input3: [Get the reader pointer txtredptr by reading the file "/Home/SUTstest/valid/REC-xml-19980210.xml" using xmlNewTextReaderFilename() and n_reader == 2,
        *   						 Call xmlTextReaderRead(txtredptr) to return reader, Call "desret_const_xmlChar_ptr()" to free xmlChar pointer(ret_val) and Call "des_xmlTextReaderPtr()" to free reader pointer(reader)] @n
        *   				{xmlTextReaderPtr (reader)} => {N/A | const xmlChar(!=NULL)} @n
        *
        *					Negative Test Case:
        *   				input4: [Get reader pointer as NULL for n_reader > 2, Call "desret_const_xmlChar_ptr()" to free xmlChar pointer(ret_val) and Call "des_xmlTextReaderPtr()" to free reader pointer(reader)] @n
        *   				{xmlTextReaderPtr (reader)} => {N/A | const xmlChar(==NULL)} @n

        */
        ret_val = xmlTextReaderConstBaseUri(reader);

        if(ret_val != NULL && n_reader == 2)
        {
        	//Positive test
		DTS_CHECK_NE_MESSAGE("xmlTextReaderConstBaseUri", (void *)ret_val, (void *)NULL, "xmlTextReaderConstBaseUri Failed");
        }

        if(ret_val == NULL && n_reader != 2)
        {
        	//Negative test
		DTS_CHECK_EQ_MESSAGE("xmlTextReaderConstBaseUri", (void *)ret_val, (void *)NULL, "xmlTextReaderConstBaseUri Failed");
        }
        desret_const_xmlChar_ptr(ret_val);
        des_xmlTextReaderPtr(n_reader, reader, 0);
        xmlResetLastError();
    }
}

	/**
	* @test			UTcXmlTextReaderConstLocalNameP01
	* @brief		const xmlChar *xmlTextReaderConstLocalName(xmlTextReaderPtr reader)
	* @desc			Positive Test for xmlTextReaderConstLocalName
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Michel Anthony (michelj@samsung.com)
	* @return		void
	* @see			none
    * @remarks
	   * 		Negative Test Case:
	   * 		input1: [Get the reader by reading the file "/Home/SUTstest/valid/ent2" using xmlNewTextReaderFilename() and n_reader == 0,
	   * 					Call "desret_const_xmlChar_ptr()" to free xmlChar pointer(ret_val) and Call "des_xmlTextReaderPtr()" to free reader pointer(reader) ] @n
	   *   	{xmlTextReaderPtr (reader)} => {N/A | const xmlChar(==NULL)} @n
	   *
	   *		Negative Test Case:
	   *   	input2: [Get the reader by reading the file ""/Home/SUTstest/valid/REC-xml-19980210.xml" using xmlNewTextReaderFilename() and n_reader == 1,
	   *   					Call "desret_const_xmlChar_ptr()" to free xmlChar pointer(ret_val) and Call "des_xmlTextReaderPtr()" to free reader pointer(reader)] @n
	   *   			{xmlTextReaderPtr (reader)} => {N/A | const xmlChar(==NULL)} @n
	   *
	   *		Positive Test Case:
	   *   	input3: [Get the reader pointer txtredptr by reading the file "/Home/SUTstest/valid/REC-xml-19980210.xml" using xmlNewTextReaderFilename() and n_reader == 2,
	   *   					Call xmlTextReaderRead(txtredptr) to return reader, Call "desret_const_xmlChar_ptr()" to free xmlChar pointer(ret_val) and Call "des_xmlTextReaderPtr()" to free reader pointer(reader)] @n
	   *   			{xmlTextReaderPtr (reader)} => {N/A | const xmlChar(!=NULL)} @n
	   *
	   *		Negative Test Case:
	   *   	input4: [Get reader pointer as NULL for n_reader > 2, Call "desret_const_xmlChar_ptr()" to free xmlChar pointer(ret_val) and Call "des_xmlTextReaderPtr()" to free reader pointer(reader)] @n
	   *   	{xmlTextReaderPtr (reader)} => {N/A | const xmlChar(==NULL)} @n

	* @b priority	Middle
	* @b etc		none
	*/
static void UTcXmlTextReaderConstLocalNameP01()
{
    const xmlChar * ret_val;
    xmlTextReaderPtr reader; /* the xmlTextReaderPtr used */
    int n_reader;

    for (n_reader = 0;n_reader < gen_nb_xmlTextReaderPtr;n_reader++) {
        reader = gen_xmlTextReaderPtr_TextReaderBase(n_reader, 0);
      //  MT_CHECK_MESSAGE2(1 == 1, "reader=: %d", reader);
        /* * @remarks
         * 		Negative Test Case:
         * 		input1: [Get the reader by reading the file "/Home/SUTstest/valid/ent2" using xmlNewTextReaderFilename() and n_reader == 0,
         * 					Call "desret_const_xmlChar_ptr()" to free xmlChar pointer(ret_val) and Call "des_xmlTextReaderPtr()" to free reader pointer(reader) ] @n
         *   	{xmlTextReaderPtr (reader)} => {N/A | const xmlChar(==NULL)} @n
         *
         *		Negative Test Case:
         *   	input2: [Get the reader by reading the file ""/Home/SUTstest/valid/REC-xml-19980210.xml" using xmlNewTextReaderFilename() and n_reader == 1,
         *   					Call "desret_const_xmlChar_ptr()" to free xmlChar pointer(ret_val) and Call "des_xmlTextReaderPtr()" to free reader pointer(reader)] @n
         *   			{xmlTextReaderPtr (reader)} => {N/A | const xmlChar(==NULL)} @n
         *
         *		Positive Test Case:
         *   	input3: [Get the reader pointer txtredptr by reading the file "/Home/SUTstest/valid/REC-xml-19980210.xml" using xmlNewTextReaderFilename() and n_reader == 2,
         *   					Call xmlTextReaderRead(txtredptr) to return reader, Call "desret_const_xmlChar_ptr()" to free xmlChar pointer(ret_val) and Call "des_xmlTextReaderPtr()" to free reader pointer(reader)] @n
         *   			{xmlTextReaderPtr (reader)} => {N/A | const xmlChar(!=NULL)} @n
         *
         *		Negative Test Case:
         *   	input4: [Get reader pointer as NULL for n_reader > 2, Call "desret_const_xmlChar_ptr()" to free xmlChar pointer(ret_val) and Call "des_xmlTextReaderPtr()" to free reader pointer(reader)] @n
         *   	{xmlTextReaderPtr (reader)} => {N/A | const xmlChar(==NULL)} @n

         */

        ret_val = xmlTextReaderConstLocalName(reader);
        if(ret_val != NULL && n_reader == 2)
        {
        	//Positive Test
		DTS_CHECK_NE_MESSAGE("xmlTextReaderConstLocalName", (void *)ret_val, (void *)NULL, "xmlTextReaderConstLocalName Failed");
        }
        if(ret_val == NULL && n_reader != 2)
        {
        	//Negative Test
		DTS_CHECK_EQ_MESSAGE("xmlTextReaderConstLocalName", (void *)ret_val, (void *)NULL, "xmlTextReaderConstLocalName Failed");
        }
        desret_const_xmlChar_ptr(ret_val);
        des_xmlTextReaderPtr(n_reader, reader, 0);
        xmlResetLastError();
    }
}
	/**
	* @test			UTcXmlTextReaderConstNameP01
	* @brief		const xmlChar *xmlTextReaderConstName(xmlTextReaderPtr reader)
	* @desc			Positive Test for xmlTextReaderConstName
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Michel Anthony (michelj@samsung.com)
	* @return		void
	* @see			none
	* @remarks
	* 		Negative Test Case:
	* 		input1: [Get the reader by reading the file "/Home/SUTstest/valid/ent2" using xmlNewTextReaderFilename() and n_reader == 0,
	* 					Call "desret_const_xmlChar_ptr()" to free xmlChar pointer(ret_val) and Call "des_xmlTextReaderPtr()" to free reader pointer(reader) ] @n
	*   	{xmlTextReaderPtr (reader)} => {N/A | const xmlChar(==NULL)} @n
	*
	*		Negative Test Case:
	*   	input2: [Get the reader by reading the file ""/Home/SUTstest/valid/REC-xml-19980210.xml" using xmlNewTextReaderFilename() and n_reader == 1,
	*   					Call "desret_const_xmlChar_ptr()" to free xmlChar pointer(ret_val) and Call "des_xmlTextReaderPtr()" to free reader pointer(reader)] @n
	*   			{xmlTextReaderPtr (reader)} => {N/A | const xmlChar(==NULL)} @n
	*
	*		Positive Test Case:
	*   	input3: [Get the reader pointer txtredptr by reading the file "/Home/SUTstest/valid/REC-xml-19980210.xml" using xmlNewTextReaderFilename() and n_reader == 2,
	*   					Call xmlTextReaderRead(txtredptr) to return reader, Call "desret_const_xmlChar_ptr()" to free xmlChar pointer(ret_val) and Call "des_xmlTextReaderPtr()" to free reader pointer(reader)] @n
	*   			{xmlTextReaderPtr (reader)} => {N/A | const xmlChar(!=NULL)} @n
	*
	*		Negative Test Case:
	*   	input4: [Get reader pointer as NULL for n_reader > 2, Call "desret_const_xmlChar_ptr()" to free xmlChar pointer(ret_val) and Call "des_xmlTextReaderPtr()" to free reader pointer(reader)] @n
	*   	{xmlTextReaderPtr (reader)} => {N/A | const xmlChar(==NULL)} @n

	* @b priority	Middle
	* @b etc		none
	*/

static void UTcXmlTextReaderConstNameP01()
{
	const xmlChar * ret_val;
	xmlTextReaderPtr reader; /* the xmlTextReaderPtr used */
	int n_reader;

	for (n_reader = 0;n_reader < gen_nb_xmlTextReaderPtr;n_reader++) {

		reader = gen_xmlTextReaderPtr_TextReaderBase(n_reader, 0);

		ret_val = xmlTextReaderConstName(reader);
		if(ret_val != NULL && n_reader == 2)
		{
		  //Positive Test
		  DTS_CHECK_NE_MESSAGE("xmlTextReaderConstName", (void *)ret_val, (void *)NULL, "xmlTextReaderConstName Failed");
		}

		if(ret_val == NULL && n_reader != 2)
		{
		  //Negative test
		  DTS_CHECK_EQ_MESSAGE("xmlTextReaderConstName", (void *)ret_val, (void *)NULL, "xmlTextReaderConstName Failed");
		}
		desret_const_xmlChar_ptr(ret_val);
		des_xmlTextReaderPtr(n_reader, reader, 0);
		xmlResetLastError();
	}
}

	/**
	* @test			UTcXmlTextReaderConstNamespaceUriP01
	* @brief		const xmlChar *xmlTextReaderConstNamespaceUri(xmlTextReaderPtr reader)
	* @desc			Positive Test for xmlTextReaderConstNamespaceUri
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Michel Anthony (michelj@samsung.com)
	* @return		void
	* @see			none
	* @remarks
     * 	Negative Test Case:
    * 	input1: [Get the reader by reading the file "/Home/SUTstest/valid/ent2" using xmlNewTextReaderFilename() and n_reader == 0,
    * 				Call "desret_const_xmlChar_ptr()" to free xmlChar pointer(ret_val) and Call "des_xmlTextReaderPtr()" to free reader pointer(reader) ] @n
    *   	        {xmlTextReaderPtr (reader)} => {N/A | const xmlChar(==NULL)} @n
    *
    *	Negative Test Case:
    *   input2: [Get the reader by reading the file ""/Home/SUTstest/valid/REC-xml-19980210.xml" using xmlNewTextReaderFilename() and n_reader == 1,
    *   			Call "desret_const_xmlChar_ptr()" to free xmlChar pointer(ret_val) and Call "des_xmlTextReaderPtr()" to free reader pointer(reader)] @n
    *   			{xmlTextReaderPtr (reader)} => {N/A | const xmlChar(==NULL)} @n
    *
    *	Positive Test Case:
    *   input3: [Get the reader pointer txtredptr by reading the file "/Home/SUTstest/valid/REC-xml-19980210.xml" using xmlNewTextReaderFilename() and n_reader == 2,
    *   			Call xmlTextReaderRead(txtredptr) to return reader, Call "desret_const_xmlChar_ptr()" to free xmlChar pointer(ret_val) and Call "des_xmlTextReaderPtr()" to free reader pointer(reader)] @n
    *   			{xmlTextReaderPtr (reader)} => {N/A | const xmlChar(!=NULL)} @n
    *
    *	Negative Test Case:
    *   	input4: [Get reader pointer as NULL for n_reader > 2, Call "desret_const_xmlChar_ptr()" to free xmlChar pointer(ret_val) and Call "des_xmlTextReaderPtr()" to free reader pointer(reader)] @n
    *   	{xmlTextReaderPtr (reader)} => {N/A | const xmlChar(==NULL)} @n


	* @b priority	Middle
	* @b etc		none
	*/
static void UTcXmlTextReaderConstNamespaceUriP01()
{
    const xmlChar * ret_val;
    xmlTextReaderPtr reader; /* the xmlTextReaderPtr used */
    int n_reader;

    for (n_reader = 0;n_reader < gen_nb_xmlTextReaderPtr;n_reader++) {
    	reader = gen_xmlTextReaderPtr_1(n_reader, 0);

        ret_val = xmlTextReaderConstNamespaceUri(reader);

        if(ret_val != NULL)
        {
        	//Positive Test
		DTS_CHECK_NE_MESSAGE("xmlTextReaderConstNamespaceUri", (void *)ret_val, (void *)NULL, "xmlTextReaderConstNamespaceUri Failed");
        }

        if(ret_val == NULL)
        {
        	//Negative Test
		DTS_CHECK_EQ_MESSAGE("xmlTextReaderConstNamespaceUri", (void *)ret_val, (void *)NULL, "xmlTextReaderConstNamespaceUri Failed");
        }
        desret_const_xmlChar_ptr(ret_val);
        des_xmlTextReaderPtr(n_reader, reader, 0);
        xmlResetLastError();
    }
}

	/**
	* @test			UTcXmlTextReaderConstPrefixP01
	* @brief		const xmlChar * xmlTextReaderConstPrefix(xmlTextReaderPtr reader)
	* @desc			Positive Test for xmlTextReaderConstPrefix
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Michel Anthony (michelj@samsung.com)
	* @return		void
	* @see			none
	* @remarks
	* 	Negative Test Case:
	* 	input1: [Get the reader by reading the file "/Home/SUTstest/valid/ent2" using xmlNewTextReaderFilename() and n_reader == 0,
	* 				Call "desret_const_xmlChar_ptr()" to free xmlChar pointer(ret_val) and Call "des_xmlTextReaderPtr()" to free reader pointer(reader) ] @n
	*   	        {xmlTextReaderPtr (reader)} => {N/A | const xmlChar(==NULL)} @n
	*
	*	Negative Test Case:
	*   input2: [Get the reader by reading the file ""/Home/SUTstest/valid/REC-xml-19980210.xml" using xmlNewTextReaderFilename() and n_reader == 1,
	*   			Call "desret_const_xmlChar_ptr()" to free xmlChar pointer(ret_val) and Call "des_xmlTextReaderPtr()" to free reader pointer(reader)] @n
	*   			{xmlTextReaderPtr (reader)} => {N/A | const xmlChar(==NULL)} @n
	*
	*	Positive Test Case:
	*   input3: [Get the reader pointer txtredptr by reading the file "/Home/SUTstest/valid/REC-xml-19980210.xml" using xmlNewTextReaderFilename() and n_reader == 2,
	*   			Call xmlTextReaderRead(txtredptr) to return reader, Call "desret_const_xmlChar_ptr()" to free xmlChar pointer(ret_val) and Call "des_xmlTextReaderPtr()" to free reader pointer(reader)] @n
	*   			{xmlTextReaderPtr (reader)} => {N/A | const xmlChar(!=NULL)} @n
	*
	*	Negative Test Case:
	*   	input4: [Get reader pointer as NULL for n_reader > 2, Call "desret_const_xmlChar_ptr()" to free xmlChar pointer(ret_val) and Call "des_xmlTextReaderPtr()" to free reader pointer(reader)] @n
	*   	{xmlTextReaderPtr (reader)} => {N/A | const xmlChar(==NULL)} @n


	* @b priority	Middle
	* @b etc		none
	*/
static void UTcXmlTextReaderConstPrefixP01()
{
	const xmlChar * ret_val;
    xmlTextReaderPtr reader; /* the xmlTextReaderPtr used */
    int n_reader;

    for (n_reader = 0;n_reader < gen_nb_xmlTextReaderPtr;n_reader++) {
    	reader = gen_xmlTextReaderPtr_TextReaderBase(n_reader, 0);
    	ret_val = xmlTextReaderConstPrefix(reader);
        if(ret_val == NULL)
        {
        	//Negative test
		DTS_CHECK_EQ_MESSAGE("xmlTextReaderConstPrefix", (void *)ret_val, (void *)NULL, "xmlTextReaderConstPrefix Failed");
        }

        if(ret_val != NULL)
        {
        	//Positive test
		DTS_CHECK_NE_MESSAGE("xmlTextReaderConstPrefix", (void *)ret_val, (void *)NULL, "xmlTextReaderConstPrefix Failed");
        }
        desret_const_xmlChar_ptr(ret_val);
        des_xmlTextReaderPtr(n_reader, reader, 0);
        xmlResetLastError();
    }
}
	/**
	* @test			UTcXmlTextReaderConstStringP01
	* @brief		const xmlChar *xmlTextReaderConstString(xmlTextReaderPtr reader, const xmlChar *str)
	* @desc			Positive Test for xmlTextReaderConstString
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Michel Anthony (michelj@samsung.com)
	* @return		void
	* @see			none
	* @remarks
	* 	positive Test Case:
	* 	input1: [Get the reader by reading the file "/Home/SUTstest/valid/ent2" using xmlNewTextReaderFilename() and n_reader == 0,
	* 				Call "desret_const_xmlChar_ptr()" to free xmlChar pointer(ret_val), Call "des_xmlTextReaderPtr()" to free reader pointer(reader) and Call "des_const_xmlChar_ptr" to free xmlchar pointer  ] @n
	*   	        {xmlTextReaderPtr (reader),const xmlChar*(str) } => {N/A | const xmlChar(==NULL)} @n
	*
	*	positive Test Case:
	* 	input1: [Get the reader by reading the file ""/Home/SUTstest/valid/REC-xml-19980210.xml" using xmlNewTextReaderFilename() and n_reader == 0,
	* 				Call "desret_const_xmlChar_ptr()" to free xmlChar pointer(ret_val), Call "des_xmlTextReaderPtr()" to free reader pointer(reader) and Call "des_const_xmlChar_ptr" to free xmlchar pointer  ] @n
	*   	        {xmlTextReaderPtr (reader),const xmlChar*(str) } => {N/A | const xmlChar(==NULL)} @n
	*
	*	positive Test Case:
	* 	input1: [Get the reader by reading the file "/Home/SUTstest/valid/xhtml1-strict.dtd" using xmlNewTextReaderFilename() and n_reader == 0,
	* 				Call "desret_const_xmlChar_ptr()" to free xmlChar pointer(ret_val), Call "des_xmlTextReaderPtr()" to free reader pointer(reader) and Call "des_const_xmlChar_ptr" to free xmlchar pointer  ] @n
	*   	        {xmlTextReaderPtr (reader),const xmlChar*(str) } => {N/A | const xmlChar(==NULL)} @n
	*
	*	Negative Test Case:
	* 	input1: [Get the reader as NULL.using xmlNewTextReaderFilename() and n_reader == 3,
	* 				Call "desret_const_xmlChar_ptr()" to free xmlChar pointer(ret_val), Call "des_xmlTextReaderPtr()" to free reader pointer(reader) and Call "des_const_xmlChar_ptr" to free xmlchar pointer  ] @n
	*   	        {xmlTextReaderPtr (reader),const xmlChar*(str) } => {N/A | const xmlChar(==NULL)} @n


	* @b priority	Middle
	* @b etc		none
	*/

static void UTcXmlTextReaderConstStringP01()
{
	const xmlChar * ret_val;
	xmlTextReaderPtr reader; /* the xmlTextReaderPtr used */
	int n_reader;
	xmlChar * str; /* the string to intern. */
	int n_str;

	for (n_reader = 0;n_reader < gen_nb_xmlTextReaderPtr;n_reader++) {
	for (n_str = 0;n_str < gen_nb_const_xmlChar_ptr;n_str++) {
		reader = gen_xmlTextReaderPtr(n_reader, 0);
		str = gen_const_xmlChar_ptr(n_str, 1);
		ret_val = xmlTextReaderConstString(reader, (const xmlChar *)str);
	   if(ret_val != NULL && n_reader < 3)
	   {
		   //Positive test
		   DTS_CHECK_NE_MESSAGE("xmlTextReaderConstString", (void *)ret_val, (void *)NULL, "xmlTextReaderConstString Failed");
	   }

	   if(ret_val == NULL && n_reader == 3)
	   {
		   //Negative test
		  DTS_CHECK_EQ_MESSAGE("xmlTextReaderConstString", (void *)ret_val, (void *)NULL, "xmlTextReaderConstString Failed");
	   }
		desret_const_xmlChar_ptr(ret_val);
		des_xmlTextReaderPtr(n_reader, reader, 0);
		des_const_xmlChar_ptr(n_str, (const xmlChar *)str, 1);
		xmlResetLastError();
	}
	}
}
	/**
	* @test			UTcXmlTextReaderConstValueP01
	* @brief		const xmlChar * xmlTextReaderConstValue(xmlTextReaderPtr reader)
	* @desc			Positive Test for xmlTextReaderConstValue
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Michel Anthony (michelj@samsung.com)
	* @return		void
	* @see			none
	* @remarks
	* 	positive Test Case:
	* 	input1: [Get the reader by reading the file "/Home/SUTstest/valid/ent2" using xmlNewTextReaderFilename() and n_reader == 0,
	* 				Call "desret_const_xmlChar_ptr()" to free xmlChar pointer(ret_val), Call "des_xmlTextReaderPtr()" to free reader pointer(reader) and Call "des_const_xmlChar_ptr" to free xmlchar pointer  ] @n
	*   	        {xmlTextReaderPtr (reader),const xmlChar*(str) } => {N/A | const xmlChar(==NULL)} @n
	*
	*	positive Test Case:
	* 	input1: [Get the reader by reading the file ""/Home/SUTstest/valid/REC-xml-19980210.xml" using xmlNewTextReaderFilename() and n_reader == 0,
	* 				Call "desret_const_xmlChar_ptr()" to free xmlChar pointer(ret_val), Call "des_xmlTextReaderPtr()" to free reader pointer(reader) and Call "des_const_xmlChar_ptr" to free xmlchar pointer  ] @n
	*   	        {xmlTextReaderPtr (reader),const xmlChar*(str) } => {N/A | const xmlChar(==NULL)} @n
	*
	*	positive Test Case:
	* 	input1: [Get the reader by reading the file "/Home/SUTstest/valid/xhtml1-strict.dtd" using xmlNewTextReaderFilename() and n_reader == 0,
	* 				Call "desret_const_xmlChar_ptr()" to free xmlChar pointer(ret_val), Call "des_xmlTextReaderPtr()" to free reader pointer(reader) and Call "des_const_xmlChar_ptr" to free xmlchar pointer  ] @n
	*   	        {xmlTextReaderPtr (reader),const xmlChar*(str) } => {N/A | const xmlChar(==NULL)} @n
	*
	*	Negative Test Case:
	* 	input1: [Get the reader as NULL.using xmlNewTextReaderFilename() and n_reader == 3,
	* 				Call "desret_const_xmlChar_ptr()" to free xmlChar pointer(ret_val), Call "des_xmlTextReaderPtr()" to free reader pointer(reader) and Call "des_const_xmlChar_ptr" to free xmlchar pointer  ] @n
	*   	        {xmlTextReaderPtr (reader),const xmlChar*(str) } => {N/A | const xmlChar(==NULL)} @n


	* @b priority	Middle
	* @ etc		none
	*/
void UTcXmlTextReaderConstValueP01()
{
	const xmlChar * ret_val;
	xmlTextReaderPtr reader; /* the xmlTextReaderPtr used */
	int n_reader;

	for (n_reader = 0;n_reader < gen_nb_xmlTextReaderPtr;n_reader++) {
		reader = gen_xmlTextReaderPtr(n_reader, 0);
		ret_val = xmlTextReaderConstValue(reader);

		if(ret_val != NULL)
		{
			//Positive Test
			DTS_CHECK_NE_MESSAGE("xmlTextReaderConstValue", (void *)ret_val, (void *)NULL, "xmlTextReaderConstValue Failed");
		}

		if(ret_val == NULL)
		{
			//Negative test
			DTS_CHECK_EQ_MESSAGE("xmlTextReaderConstValue", (void *)ret_val, (void *)NULL, "xmlTextReaderConstValue Failed");
		}
		desret_const_xmlChar_ptr(ret_val);
		des_xmlTextReaderPtr(n_reader, reader, 0);
		xmlResetLastError();
	}
}
	/**
			* @test			UTcXmlTextReaderConstXmlLangP01
			* @brief		const xmlChar *xmlTextReaderConstXmlLang(xmlTextReaderPtr reader)
			* @desc			Positive Test for xmlTextReaderConstXmlLang
			* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
			* @b tester		Michel Anthony (michelj@samsung.com)
			* @return		void
			* @see			none
			* @remarks
			* 	positive Test Case:
			* 	input1: [Get the reader by reading the file "/Home/SUTstest/valid/ent2" using xmlNewTextReaderFilename() and n_reader == 0,
			* 				Call "desret_const_xmlChar_ptr()" to free xmlChar pointer(ret_val), Call "des_xmlTextReaderPtr()" to free reader pointer(reader) and Call "des_const_xmlChar_ptr" to free xmlchar pointer  ] @n
			*   	        {xmlTextReaderPtr (reader),const xmlChar*(str) } => {N/A | const xmlChar(==NULL)} @n
			*
			*	positive Test Case:
			* 	input1: [Get the reader by reading the file ""/Home/SUTstest/valid/REC-xml-19980210.xml" using xmlNewTextReaderFilename() and n_reader == 0,
			* 				Call "desret_const_xmlChar_ptr()" to free xmlChar pointer(ret_val), Call "des_xmlTextReaderPtr()" to free reader pointer(reader) and Call "des_const_xmlChar_ptr" to free xmlchar pointer  ] @n
			*   	        {xmlTextReaderPtr (reader),const xmlChar*(str) } => {N/A | const xmlChar(==NULL)} @n
			*
			*	positive Test Case:
			* 	input1: [Get the reader by reading the file "/Home/SUTstest/valid/xhtml1-strict.dtd" using xmlNewTextReaderFilename() and n_reader == 0,
			* 				Call "desret_const_xmlChar_ptr()" to free xmlChar pointer(ret_val), Call "des_xmlTextReaderPtr()" to free reader pointer(reader) and Call "des_const_xmlChar_ptr" to free xmlchar pointer  ] @n
			*   	        {xmlTextReaderPtr (reader),const xmlChar*(str) } => {N/A | const xmlChar(==NULL)} @n
			*
			*	Negative Test Case:
			* 	input1: [Get the reader as NULL.using xmlNewTextReaderFilename() and n_reader == 3,
			* 				Call "desret_const_xmlChar_ptr()" to free xmlChar pointer(ret_val), Call "des_xmlTextReaderPtr()" to free reader pointer(reader) and Call "des_const_xmlChar_ptr" to free xmlchar pointer  ] @n
			*   	        {xmlTextReaderPtr (reader),const xmlChar*(str) } => {N/A | const xmlChar(==NULL)} @n


			* @b priority	Middle
			* @ etc		none
			*/
static void UTcXmlTextReaderConstXmlLangP01()
{
	const xmlChar * ret_val;
	xmlTextReaderPtr reader; /* the xmlTextReaderPtr used */
	int n_reader;

	for (n_reader = 0;n_reader < gen_nb_xmlTextReaderPtr;n_reader++) {
		reader = gen_xmlTextReaderPtr_TextReaderBase(n_reader, 0);

		ret_val = xmlTextReaderConstXmlLang(reader);

		if(ret_val != NULL)
		{
			//Positive Test
			DTS_CHECK_NE_MESSAGE("xmlTextReaderConstXmlLang", (void *)ret_val, (void *)NULL, "xmlTextReaderConstXmlLang Failed");
		}

		if(ret_val == NULL)
		{
			//negative Test
			DTS_CHECK_EQ_MESSAGE("xmlTextReaderConstXmlLang", (void *)ret_val, (void *)NULL, "xmlTextReaderConstXmlLang Failed");
		}

		desret_const_xmlChar_ptr(ret_val);
		des_xmlTextReaderPtr(n_reader, reader, 0);
		xmlResetLastError();
	}
}
	/**
	* @test			UTcXmlTextReaderCurrentDocP01
	* @brief		xmlDocPtr xmlTextReaderCurrentDoc(xmlTextReaderPtr reader)
	* @desc			Positive Test for xmlTextReaderCurrentDoc
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Michel Anthony (michelj@samsung.com)
	* @return		void
	* @see			none
	* @remarks
	* 	Negative Test Case:
	* 	input1: [Get the reader by reading the file "/Home/SUTstest/valid/ent2" using xmlNewTextReaderFilename() and n_reader == 0,
	* 				Call "desret_xmlDocPtr()" to free  xmlDocPtr pointer, Call "des_xmlTextReaderPtr()" to free reader pointer(reader)] @n
	*   	        {xmlTextReaderPtr (reader) } => {N/A | xmlDocPtr(==NULL)} @n
	*
	*	negative Test Case:
	* 	input1: [Get the reader by reading the file ""/Home/SUTstest/valid/REC-xml-19980210.xml" using xmlNewTextReaderFilename() and n_reader == 1,
	* 				Call "desret_xmlDocPtr()" to free  xmlDocPtr pointer, Call "des_xmlTextReaderPtr()" to free reader pointer(reader)] @n
	*   	        {xmlTextReaderPtr (reader) } => {N/A | xmlDocPtr(==NULL)} @n
	*
	*	positive Test Case:
	* 	input1: [Get the reader by reading the file "/Home/SUTstest/valid/xhtml1-strict.dtd" using xmlNewTextReaderFilename() and n_reader == 2,
	* 				Call "desret_xmlDocPtr()" to free  xmlDocPtr pointer, Call "des_xmlTextReaderPtr()" to free reader pointer(reader)] @n
	*   	        {xmlTextReaderPtr (reader) } => {N/A | xmlDocPtr(!=NULL)} @n
	*
	*	Negative Test Case:
	* 	input1: [Get the reader as NULL.using xmlNewTextReaderFilename() and n_reader == 3,
	* 				Call "desret_xmlDocPtr()" to free  xmlDocPtr pointer, Call "des_xmlTextReaderPtr()" to free reader pointer(reader)] @n
	*   	        {xmlTextReaderPtr (reader)} => {N/A | xmlDocPtr(==NULL)} @n


	* @b priority	Middle
	* @ etc		none
	*/
static void UTcXmlTextReaderCurrentDocP01()
{
    xmlDocPtr ret_val;
    xmlTextReaderPtr reader; /* the xmlTextReaderPtr used */
    int n_reader;

    for (n_reader = 0;n_reader < gen_nb_xmlTextReaderPtr;n_reader++) {

        reader = gen_xmlTextReaderPtr_TextReaderBase(n_reader, 0);
        ret_val = xmlTextReaderCurrentDoc(reader);

        if(ret_val != NULL && n_reader == 2)
        {
        	//Positive test
		DTS_CHECK_NE_MESSAGE("xmlTextReaderCurrentDoc", (void *)ret_val, (void *)NULL, "xmlTextReaderCurrentDoc positive Failed");
        }

        if(ret_val == NULL && (n_reader == 0 || n_reader == 1 || n_reader == 3))
        {
        	//Negative test
		DTS_CHECK_EQ_MESSAGE("xmlTextReaderCurrentDoc", (void *)ret_val, (void *)NULL, "xmlTextReaderCurrentDoc negative Failed");
        }
        desret_xmlDocPtr(ret_val);
        des_xmlTextReaderPtr(n_reader, reader, 0);
        xmlResetLastError();
    }
}
	/**    
	* @test			UTcxmlTextReaderIsDefault01
	* @brief		int xmlTextReaderIsDefault(xmlTextReaderPtr reader)
	* @desc         +ve and _ve TCs for xmlTextReaderIsDefault
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Sathish Kumar (satish.k4@samsung.com)
	* @return		void
	* @see			none
	* @remarks
	*
	* @b priority
	* @b etc		none
	*/
static void UTcxmlTextReaderIsDefault01()
{
#if defined(LIBXML_READER_ENABLED)
	int ret_val;
	xmlTextReaderPtr reader; /* the xmlTextReaderPtr used */
	int n_reader;

	for (n_reader = 0;n_reader < gen_nb_xmlTextReaderPtr;n_reader++) {
		reader = gen_xmlTextReaderPtr(n_reader, 0);

		ret_val = xmlTextReaderIsDefault(reader);
		if(reader)
			{
				DTS_CHECK_NE_MESSAGE("xmlTextReaderIsDefault", (void *)ret_val, (void *)-1, "xmlTextReaderIsDefault Failed");
			}
		else
			{
				DTS_CHECK_EQ_MESSAGE("xmlTextReaderIsDefault", (void *)ret_val, (void *)-1, "xmlTextReaderIsDefault Failed");
			}
		//AppLog("UTcxmlTextReaderIsDefaultP01 reader [%u] ret_val [%d]",reader,ret_val);
		desret_int(ret_val);
		des_xmlTextReaderPtr(n_reader, reader, 0);
		xmlResetLastError();
	}
#endif
}
	/**
	* @test			UTcxmlTextReaderIsEmptyElement01
	* @brief		int xmlTextReaderIsEmptyElement(xmlTextReaderPtr reader)
	* @desc         +ve and _ve TCs for xmlTextReaderIsEmptyElement
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Sathish Kumar (satish.k4@samsung.com)
	* @return		void
	* @see			none
	* @remarks
	*
	* @b priority
	* @b etc		none
	*/
static void UTcxmlTextReaderIsEmptyElement01()
{
 

#if defined(LIBXML_READER_ENABLED)
	int ret_val;
	xmlTextReaderPtr reader; /* the xmlTextReaderPtr used */
	int n_reader;
	int ret = 0;
	for (n_reader = 0;n_reader < gen_nb_xmlTextReaderPtr;n_reader++) {
		reader = gen_xmlTextReaderPtr(n_reader, 0);
		ret = xmlTextReaderRead(reader);
		while (ret == 1)
		{
			ret_val = xmlTextReaderIsEmptyElement(reader);
			ret = xmlTextReaderRead(reader);
		}

		DTS_CHECK_NE_MESSAGE("xmlTextReaderRead", (void *)ret_val, (void *)-1, "xmlTextReaderRead Failed");
		desret_int(ret_val);
		des_xmlTextReaderPtr(n_reader, reader, 0);
		xmlResetLastError();
		}
#endif
}
	/**
	* @test			UTcxmlTextReaderIsValid01
	* @brief		int xmlTextReaderIsValid(xmlTextReaderPtr reader)
	* @desc         +ve and _ve TCs for xmlTextReaderIsValid
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Sathish Kumar (satish.k4@samsung.com)
	* @return		void
	* @see			none
	* @remarks
	*
	* @b priority
	* @b etc		none
	*/
static void UTcxmlTextReaderIsValid01()
{
#if defined(LIBXML_READER_ENABLED)
	int ret_val;
	xmlTextReaderPtr reader; /* the xmlTextReaderPtr used */
	int n_reader;
	int ret = 0;
	for (n_reader = 0;n_reader < gen_nb_xmlTextReaderPtr;n_reader++) {
		reader = gen_xmlTextReaderPtr(n_reader, 0);
		ret = xmlTextReaderRead(reader);
		while (ret == 1)
		{
			ret_val = xmlTextReaderIsValid(reader);
			ret = xmlTextReaderRead(reader);
		}

		DTS_CHECK_NE_MESSAGE("xmlTextReaderRead", (void *)ret_val, (void *)-1, "xmlTextReaderRead Failed");
		desret_int(ret_val);
		des_xmlTextReaderPtr(n_reader, reader, 0);
		xmlResetLastError();
	}
#endif
}
	/**
	* @test			UTcxmlTextReaderLocalName01
	* @brief		xmlChar *xmlTextReaderLocalName(xmlTextReaderPtr reader)
	* @desc         +ve and _ve TCs for xmlTextReaderLocalName
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Sathish Kumar (satish.k4@samsung.com)
	* @return		void
	* @see			none
	* @remarks
	*
	* @b priority
	* @b etc		none
	*/
static void UTcxmlTextReaderLocalName01()
{
#if defined(LIBXML_READER_ENABLED)
	xmlChar * ret_val;
	xmlTextReaderPtr reader; /* the xmlTextReaderPtr used */
	int n_reader;
	int ret = 0;
	for (n_reader = 0;n_reader < gen_nb_xmlTextReaderPtr;n_reader++) {
		reader = gen_xmlTextReaderPtr(n_reader, 0);
		ret = xmlTextReaderRead(reader);
		while (ret == 1)
		{
			ret_val = xmlTextReaderLocalName(reader);
			ret = xmlTextReaderRead(reader);
		}

		DTS_CHECK_NE_MESSAGE("xmlTextReaderRead", (void *)ret_val, (void *)-1, "xmlTextReaderRead Failed");
		//desret_xmlChar_ptr(ret_val);
//		des_xmlTextReaderPtr(n_reader, reader, 0);
		xmlResetLastError();
	}
#endif
}

static void des_xmlTextReaderLocatorPtr(int no ATTRIBUTE_UNUSED, xmlTextReaderLocatorPtr val ATTRIBUTE_UNUSED, int nr ATTRIBUTE_UNUSED)
{

}

static xmlTextReaderLocatorPtr gen_xmlTextReaderLocatorPtr(int no ATTRIBUTE_UNUSED, int nr ATTRIBUTE_UNUSED)
{
    return(NULL);
}
	/**
	* @test			UTcxmlTextReaderLocatorBaseURI01
	* @brief		xmlChar *xmlTextReaderLocatorBaseURI(xmlTextReaderLocatorPtr locator)
	* @desc         +ve and _ve TCs for xmlTextReaderLocatorBaseURI
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Sathish Kumar (satish.k4@samsung.com)
	* @return		void
	* @see			none
	* @remarks      input1: [N/A, N/A] @n
	     		    {xmlTextReaderLocatorPtr(NULL)} => {N/A | int(NULL)} @n
	* @b priority
	* @b etc		none
	*/
static void UTcxmlTextReaderLocatorBaseURI01()
{
#if defined(LIBXML_READER_ENABLED)
	xmlChar * ret_val;
	xmlTextReaderLocatorPtr locator; /* the xmlTextReaderLocatorPtr used */
	int n_locator;

	for (n_locator = 0;n_locator < gen_nb_xmlTextReaderLocatorPtr;n_locator++) {
		locator = gen_xmlTextReaderLocatorPtr(n_locator, 0);
		ret_val = xmlTextReaderLocatorBaseURI(locator);
		if( locator )
			{
			DTS_CHECK_NE_MESSAGE("xmlTextReaderLocatorBaseURI", (void *)ret_val, (void *)NULL, "xmlTextReaderLocatorBaseURI Failed");
			}
		else
			{
				DTS_CHECK_EQ_MESSAGE("xmlTextReaderLocatorBaseURI", (void *)ret_val, (void *)NULL, "xmlTextReaderLocatorBaseURI Failed");
			}
		desret_xmlChar_ptr(ret_val);
		des_xmlTextReaderLocatorPtr(n_locator, locator, 0);
		xmlResetLastError();
	}   
#endif
}
	/**
	* @test			UTcxmlTextReaderLocatorLineNumber01
	* @brief		int xmlTextReaderLocatorLineNumber(xmlTextReaderLocatorPtr locator)
	* @desc         +ve and _ve TCs for xmlTextReaderLocatorLineNumber
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Sathish Kumar (satish.k4@samsung.com)
	* @return		void
	* @see			none
	* @remarks      input1: [N/A, N/A] @n
	     		    {xmlTextReaderLocatorPtr(NULL)} => {N/A | int(-1)} @n
	* @b priority
	* @b etc		none
	*/
static void UTcxmlTextReaderLocatorLineNumber01()
{
 

#if defined(LIBXML_READER_ENABLED)
    
    int ret_val;
    xmlTextReaderLocatorPtr locator; /* the xmlTextReaderLocatorPtr used */
    int n_locator;

    for (n_locator = 0;n_locator < gen_nb_xmlTextReaderLocatorPtr;n_locator++) {
        
        locator = gen_xmlTextReaderLocatorPtr(n_locator, 0);

		// @remarks   input1: [N/A, N/A] @n
	    //  		  {xmlTextReaderLocatorPtr(NULL)} => {N/A | int(-1)} @n
        ret_val = xmlTextReaderLocatorLineNumber(NULL);//-ve
	DTS_CHECK_EQ_MESSAGE("xmlTextReaderLocatorLineNumber", (void *)ret_val, (void *)-1, "xmlTextReaderLocatorLineNumber Failed");

        desret_int(ret_val);
        des_xmlTextReaderLocatorPtr(n_locator, locator, 0);
        xmlResetLastError();
    }
    
#endif
}
	/**
	* @test			UTcxmlTextReaderLookupNamespace01
	* @brief		xmlChar *xmlTextReaderLookupNamespace(xmlTextReaderPtr reader, const xmlChar *prefix)
	* @desc         +ve and _ve TCs for xmlTextReaderLookupNamespace
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Sathish Kumar (satish.k4@samsung.com)
	* @return		void
	* @see			none
	* @remarks      input1: [N/A, N/A] @n
	            	{xmlTextReaderPtr(valid ptr), xmlChar(valid ptr)} => {N/A | xmlChar(xmlChar)} @n
	            	input2: [N/A, N/A] @n
        		    {xmlTextReaderPtr(NULL), xmlChar(valid ptr)} => {N/A | N/A} @n
	* @b priority
	* @b etc		none
	*/
static void UTcxmlTextReaderLookupNamespace01()
{
 

#if defined(LIBXML_READER_ENABLED)
	xmlChar * ret_val;
	xmlTextReaderPtr reader; /* the xmlTextReaderPtr used */
	int n_reader;
	xmlChar * prefix; /* the prefix whose namespace URI is to be resolved. To return the default namespace, specify NULL */
	int n_prefix;
	int ret = 0;
	for (n_reader = 0;n_reader < gen_nb_xmlTextReaderPtr;n_reader++) {
		for (n_prefix = 0;n_prefix < gen_nb_const_xmlChar_ptr;n_prefix++) {
			reader = gen_xmlTextReaderPtr(0, 0);
			prefix = gen_const_xmlChar_ptr(n_prefix, 1);

			ret = xmlTextReaderRead(reader);
			while (ret == 1)
			{
				ret_val = xmlTextReaderLookupNamespace(reader, (const xmlChar *)prefix);
				ret = xmlTextReaderRead(reader);
			}

			DTS_CHECK_NE_MESSAGE("xmlTextReaderRead", (void *)ret_val, (void *)NULL, "xmlTextReaderRead Failed");
			desret_xmlChar_ptr(ret_val);
			des_xmlTextReaderPtr(n_reader, reader, 0);
			des_const_xmlChar_ptr(n_prefix, (const xmlChar *)prefix, 1);
			xmlResetLastError();
		}
	}   
#endif
}
	/**
	* @test			UTcxmlTextReaderMoveToAttributeNo01
	* @brief		int xmlTextReaderMoveToAttributeNo(xmlTextReaderPtr reader, int no)
	* @desc         +ve and _ve TCs for xmlTextReaderMoveToAttributeNo
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Sathish Kumar (satish.k4@samsung.com)
	* @return		void
	* @see			none
	* @remarks      input1: [N/A, N/A] @n
          	    	{xmlTextReaderPtr(NULL), int(valid)} => {N/A | N/A} @n
          	    	input2: [N/A, N/A] @n
          		    {xmlTextReaderPtr(reader), int(valid)} => {N/A | N/A} @n
	*
	* @b priority
	* @b etc		none
	*/
static void UTcxmlTextReaderMoveToAttributeNo01()
{
 

#if defined(LIBXML_READER_ENABLED)
    
    int ret_val;
    xmlTextReaderPtr reader; /* the xmlTextReaderPtr used */
    int n_reader;
    int no; /* the zero-based index of the attribute relative to the containing element. */
    int n_no;

    for (n_reader = 0;n_reader < gen_nb_xmlTextReaderPtr;n_reader++) {
    for (n_no = 0;n_no < gen_nb_int;n_no++) {
        
        reader = gen_xmlTextReaderPtr(n_reader, 0);
        no = gen_int(n_no, 1);

    	// @remarks   input1: [N/A, N/A] @n
        //  		  {xmlTextReaderPtr(NULL), int(valid)} => {N/A | N/A} @n
        ret_val = xmlTextReaderMoveToAttributeNo(NULL, no);
	DTS_CHECK_EQ_MESSAGE("xmlTextReaderMoveToAttributeNo", (void *)ret_val, (void *)-1, "xmlTextReaderMoveToAttributeNo Failed");
		

    	// @remarks   input2: [N/A, N/A] @n
        //  		  {xmlTextReaderPtr(reader), int(valid)} => {N/A | N/A} @n
        if(n_reader)
        {
			ret_val = xmlTextReaderMoveToAttributeNo(reader, no);
			DTS_CHECK_NE_MESSAGE("xmlTextReaderMoveToAttributeNo", (void *)ret_val, (void *)NULL, "xmlTextReaderMoveToAttributeNo Failed");
			
        }

        desret_int(ret_val);
        des_xmlTextReaderPtr(n_reader, reader, 0);
        des_int(n_no, no, 1);
        xmlResetLastError();
    }
    }
    
#endif
}
	/**
	* @test			UTcxmlTextReaderMoveToAttributeNs01
	* @brief		int xmlTextReaderMoveToAttributeNs(xmlTextReaderPtr reader,
	                                                   const xmlChar *localName,
	                                                   const xmlChar *namespaceURI)
	* @desc         +ve and _ve TCs for xmlTextReaderMoveToAttributeNs
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Sathish Kumar (satish.k4@samsung.com)
	* @return		void
	* @see			none
	* @remarks      input1: [N/A, N/A] @n
          		    {xmlTextReaderPtr(reader), xmlChar(localName), xmlChar(namespaceURI)} => {N/A | ret_val(valid ptr)} @n
          		    input2: [N/A, N/A] @n
          		    {xmlTextReaderPtr(NULL), xmlChar(localName), xmlChar(namespaceURI)} => {N/A | ret_val(NULL)} @n
          		    input3: [N/A, N/A] @n
            		{xmlTextReaderPtr(reader), xmlChar(NULL), xmlChar(namespaceURI)} => {N/A | ret_val(NULL)} @n
            		input4: [N/A, N/A] @n
          	    	{xmlTextReaderPtr(reader), xmlChar(localName), xmlChar(NULL)} => {N/A | ret_val(NULL)} @n
	*
	* @b priority
	* @b etc		none
	*/

static void UTcxmlTextReaderMoveToAttributeNs01()
{
 

#if defined(LIBXML_READER_ENABLED)
    
    int ret_val;
    xmlTextReaderPtr reader; /* the xmlTextReaderPtr used */
    int n_reader;
    xmlChar * localName; /* the local name of the attribute. */
    int n_localName;
    xmlChar * namespaceURI; /* the namespace URI of the attribute. */
    int n_namespaceURI;

    for (n_reader = 0;n_reader < gen_nb_xmlTextReaderPtr;n_reader++) {
    for (n_localName = 0;n_localName < gen_nb_const_xmlChar_ptr;n_localName++) {
    for (n_namespaceURI = 0;n_namespaceURI < gen_nb_const_xmlChar_ptr;n_namespaceURI++) {
        
        reader = gen_xmlTextReaderPtr(n_reader, 0);
        localName = gen_const_xmlChar_ptr(n_localName, 1);
        namespaceURI = gen_const_xmlChar_ptr(n_namespaceURI, 2);

    	// @remarks   input1: [N/A, N/A] @n
        //  		  {xmlTextReaderPtr(reader), xmlChar(localName), xmlChar(namespaceURI)} => {N/A | ret_val(valid ptr)} @n

        ret_val = xmlTextReaderMoveToAttributeNs(reader, (const xmlChar *)localName, (const xmlChar *)namespaceURI);
		DTS_CHECK_NE_MESSAGE("xmlTextReaderMoveToAttributeNs", (void *)ret_val, (void *)NULL, "xmlTextReaderMoveToAttributeNs Failed");

    	// @remarks   input2: [N/A, N/A] @n
        //  		  {xmlTextReaderPtr(NULL), xmlChar(localName), xmlChar(namespaceURI)} => {N/A | ret_val(NULL)} @n
		ret_val = xmlTextReaderMoveToAttributeNs(NULL, (const xmlChar *)localName, (const xmlChar *)namespaceURI);
		DTS_CHECK_EQ_MESSAGE("xmlTextReaderMoveToAttributeNs", (void *)ret_val, (void *)-1, "xmlTextReaderMoveToAttributeNs Failed");

    	// @remarks   input3: [N/A, N/A] @n
        //  		  {xmlTextReaderPtr(reader), xmlChar(NULL), xmlChar(namespaceURI)} => {N/A | ret_val(NULL)} @n
		ret_val = xmlTextReaderMoveToAttributeNs(reader, NULL, (const xmlChar *)namespaceURI);
		DTS_CHECK_EQ_MESSAGE("xmlTextReaderMoveToAttributeNs", (void *)ret_val, (void *)-1, "xmlTextReaderMoveToAttributeNs Failed");

    	// @remarks   input4: [N/A, N/A] @n
        //  		  {xmlTextReaderPtr(reader), xmlChar(localName), xmlChar(NULL)} => {N/A | ret_val(NULL)} @n
		ret_val = xmlTextReaderMoveToAttributeNs(reader, (const xmlChar *)localName, NULL);
		DTS_CHECK_EQ_MESSAGE("xmlTextReaderMoveToAttributeNs", (void *)ret_val, (void *)-1, "xmlTextReaderMoveToAttributeNs Failed");

        desret_int(ret_val);
        des_xmlTextReaderPtr(n_reader, reader, 0);
        des_const_xmlChar_ptr(n_localName, (const xmlChar *)localName, 1);
        des_const_xmlChar_ptr(n_namespaceURI, (const xmlChar *)namespaceURI, 2);
        xmlResetLastError();
    }
    }
    }
    
#endif
}
	/**
	* @test			UTcxmlTextReaderMoveToElement01
	* @brief		int xmlTextReaderMoveToElement(xmlTextReaderPtr reader)
	* @desc         +ve and _ve TCs for xmlTextReaderMoveToElement
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Sathish Kumar (satish.k4@samsung.com)
	* @return		void
	* @see			none
	* @remarks      input1: [N/A, N/A] @n
             		{xmlTextReaderPtr(reader)} => {N/A | int(0)} @n
	*
	* @b priority
	* @b etc		none
	*/
static void UTcxmlTextReaderMoveToElement01()
{
#if defined(LIBXML_READER_ENABLED)
	int ret_val;
	xmlTextReaderPtr reader; /* the xmlTextReaderPtr used */
	int n_reader;
	int ret = 0;
	for (n_reader = 0;n_reader < gen_nb_xmlTextReaderPtr;n_reader++) {
		//reader = gen_xmlTextReaderPtr(n_reader, 0);
		reader = gen_xmlTextReaderPtr(0, 0);
		ret = xmlTextReaderRead(reader);
		while (ret == 1)
		{
			ret_val = xmlTextReaderMoveToElement(reader);
			ret = xmlTextReaderRead(reader);
		}

		DTS_CHECK_EQ_MESSAGE("xmlTextReaderMoveToElement", (void *)ret_val, (void *)0, "xmlTextReaderMoveToElement Failed");
		desret_int(ret_val);
		des_xmlTextReaderPtr(n_reader, reader, 0);
		xmlResetLastError();
		}
#endif
}
	/**
	* @test			UTcxmlTextReaderMoveToNextAttribute01
	* @brief		int xmlTextReaderMoveToNextAttribute(xmlTextReaderPtr reader)
	* @desc         +ve and _ve TCs for xmlTextReaderMoveToNextAttribute
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Sathish Kumar (satish.k4@samsung.com)
	* @return		void
	* @see			none
	* @remarks      input1: [N/A, N/A] @n
            		{xmlTextReaderPtr(reader)} => {N/A | int(0)} @n
	*
	* @b priority
	* @b etc		none
	*/
static void UTcxmlTextReaderMoveToNextAttribute01()
{
#if defined(LIBXML_READER_ENABLED)
	int ret_val;
	xmlTextReaderPtr reader; /* the xmlTextReaderPtr used */
	int n_reader;
	int ret = 0;

	for (n_reader = 0;n_reader < gen_nb_xmlTextReaderPtr;n_reader++) {
		//reader = gen_xmlTextReaderPtr(n_reader, 0);
		reader = gen_xmlTextReaderPtr(0, 0);
		ret = xmlTextReaderRead(reader);
		while (ret == 1)
		{
			ret_val = xmlTextReaderMoveToNextAttribute(reader);
			ret = xmlTextReaderRead(reader);
		}

		DTS_CHECK_NE_MESSAGE("xmlTextReaderMoveToNextAttribute", (void *)ret_val, (void *)-1, "xmlTextReaderMoveToNextAttribute Failed");
		desret_int(ret_val);
		des_xmlTextReaderPtr(n_reader, reader, 0);
		xmlResetLastError();
	}
#endif
}
	/**
	* @test			UTcxmlTextReaderName01
	* @brief		xmlChar *xmlTextReaderName(xmlTextReaderPtr reader)
	* @desc         +ve and _ve TCs for xmlTextReaderName
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Sathish Kumar (satish.k4@samsung.com)
	* @return		void
	* @see			none
	* @remarks      input1: [N/A, N/A] @n
        		    {xmlTextReaderPtr(reader)} => {N/A | int(0)} @n
	*
	* @b priority
	* @b etc		none
	*/
static void UTcxmlTextReaderName01()
{
#if defined(LIBXML_READER_ENABLED)
	xmlChar * ret_val;
	xmlTextReaderPtr reader; /* the xmlTextReaderPtr used */
	int n_reader;
	int ret = 0;
	for (n_reader = 0;n_reader < gen_nb_xmlTextReaderPtr;n_reader++) {
		//reader = gen_xmlTextReaderPtr(n_reader, 0);
		reader = gen_xmlTextReaderPtr(0, 0);
		ret = xmlTextReaderRead(reader);
		while (ret == 1)
		{
			ret_val = xmlTextReaderName(reader);
			ret = xmlTextReaderRead(reader);
		}

		DTS_CHECK_NE_MESSAGE("xmlTextReaderName", (void *)ret_val, (void *)NULL, "xmlTextReaderName Failed");
		desret_xmlChar_ptr(ret_val);
		des_xmlTextReaderPtr(n_reader, reader, 0);
		xmlResetLastError();
	}
#endif
}
	/**
	* @test			UTcxmlTextReaderNamespaceUri01
	* @brief		xmlChar *xmlTextReaderNamespaceUri(xmlTextReaderPtr reader)
	* @desc         +ve and _ve TCs for xmlTextReaderNamespaceUri
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Sathish Kumar (satish.k4@samsung.com)
	* @return		void
	* @see			none
	* @remarks      input1: [N/A, N/A] @n
       	            {xmlTextReaderPtr(reader)} => {N/A | int(0)} @n

	*
	* @b priority
	* @b etc		none
	*/
static void UTcxmlTextReaderNamespaceUri01()
{
#if defined(LIBXML_READER_ENABLED)
	xmlChar * ret_val;
	xmlTextReaderPtr reader; /* the xmlTextReaderPtr used */
	int n_reader;
	int ret = 0;
	for (n_reader = 0;n_reader < gen_nb_xmlTextReaderPtr;n_reader++) {
		//reader = gen_xmlTextReaderPtr(n_reader, 0);
		reader = gen_xmlTextReaderPtr(0, 0);
		ret = xmlTextReaderRead(reader);
		while (ret == 1)
		{
			ret_val = xmlTextReaderNamespaceUri(reader);
			ret = xmlTextReaderRead(reader);
		}

		DTS_CHECK_NE_MESSAGE("xmlTextReaderNamespaceUri", (void *)ret_val, (void *)NULL, "xmlTextReaderNamespaceUri Failed");
		desret_xmlChar_ptr(ret_val);
		des_xmlTextReaderPtr(n_reader, reader, 0);
		xmlResetLastError();
	}
#endif
}
	/**
	* @test			UTcxmlTextReaderNextSibling01
	* @brief		int xmlTextReaderNextSibling(xmlTextReaderPtr reader)
	* @desc         +ve and _ve TCs for xmlTextReaderNextSibling
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Sathish Kumar (satish.k4@samsung.com)
	* @return		void
	* @see			none
	* @remarks      input1: [N/A, N/A] @n
         	        {xmlTextReaderPtr(reader)} => {N/A | int(0)} @n
	*
	* @b priority
	* @b etc		none
	*/
static void UTcxmlTextReaderNextSibling01()
{
#if defined(LIBXML_READER_ENABLED)
	int ret_val;
	xmlTextReaderPtr reader; /* the xmlTextReaderPtr used */
	int n_reader;
	int ret = 0;
	for (n_reader = 0;n_reader < gen_nb_xmlTextReaderPtr;n_reader++) {
		//reader = gen_xmlTextReaderPtr(n_reader, 0);
		reader = gen_xmlTextReaderPtr(0, 0);
		ret = xmlTextReaderRead(reader);
		while (ret == 1)
		{
			ret_val = xmlTextReaderNextSibling(reader);
			ret = xmlTextReaderRead(reader);
		}

		DTS_CHECK_EQ_MESSAGE("xmlTextReaderNextSibling", (void *)ret_val, (void *)-1, "xmlTextReaderNextSibling Failed");
		desret_int(ret_val);
		des_xmlTextReaderPtr(n_reader, reader, 0);
		xmlResetLastError();
	}
#endif
}
	/**
	* @test			UTcxmlTextReaderNodeType01
	* @brief		int xmlTextReaderNodeType(xmlTextReaderPtr reader)
	* @desc         +ve and _ve TCs for xmlTextReaderNodeType
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Sathish Kumar (satish.k4@samsung.com)
	* @return		void
	* @see			none
	* @remarks      input1: [N/A, N/A] @n
            		{xmlTextReaderPtr(reader)} => {N/A | int(0)} @n
	*
	* @b priority
	* @b etc		none
	*/
static void UTcxmlTextReaderNodeType01()
{
#if defined(LIBXML_READER_ENABLED)
	int ret_val;
	xmlTextReaderPtr reader; /* the xmlTextReaderPtr used */
	int n_reader;

	for (n_reader = 0;n_reader < gen_nb_xmlTextReaderPtr;n_reader++) {
		reader = gen_xmlTextReaderPtr(n_reader, 0);

		ret_val = xmlTextReaderNodeType(reader);
		if( reader )
		{
			DTS_CHECK_NE_MESSAGE("xmlTextReaderNodeType", (void *)ret_val, (void *)-1, "xmlTextReaderNodeType Failed");
		}
		else
		{
			DTS_CHECK_EQ_MESSAGE("xmlTextReaderNodeType", (void *)ret_val, (void *)-1, "xmlTextReaderNodeType Failed");
		}

		desret_int(ret_val);
		des_xmlTextReaderPtr(n_reader, reader, 0);
		xmlResetLastError();
	}
#endif
}
	/**
	* @test			UTcxmlTextReaderNormalization01
	* @brief		int xmlTextReaderNormalization(xmlTextReaderPtr reader)
	* @desc         +ve and _ve TCs for xmlTextReaderNormalization
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Sathish Kumar (satish.k4@samsung.com)
	* @return		void
	* @see			none
	* @remarks      input1: [N/A, N/A] @n
        		    {xmlTextReaderPtr(reader)} => {N/A | int(-1)} @n
        		    input2: [N/A, N/A] @n
		     		{xmlTextReaderPtr(reader)} => {N/A | int(1)} @n
	*
	* @b priority
	* @b etc		none
	*/
static void UTcxmlTextReaderNormalization01()
{
 

#if defined(LIBXML_READER_ENABLED)
	int ret_val;
	xmlTextReaderPtr reader; /* the xmlTextReaderPtr used */
	int n_reader;

	for (n_reader = 0;n_reader < gen_nb_xmlTextReaderPtr;n_reader++) {
		reader = gen_xmlTextReaderPtr(n_reader, 0);

		ret_val = xmlTextReaderNormalization(reader);
		if( reader )
		{
			DTS_CHECK_NE_MESSAGE("xmlTextReaderNormalization", (void *)ret_val, (void *)-1, "xmlTextReaderNormalization Failed");
		}
		else
		{
			DTS_CHECK_EQ_MESSAGE("xmlTextReaderNormalization", (void *)ret_val, (void *)-1, "xmlTextReaderNormalization Failed");
		}			
		desret_int(ret_val);
		des_xmlTextReaderPtr(n_reader, reader, 0);
		xmlResetLastError();
	}   
#endif
}
	/**
	* @test			UTcxmlTextReaderPrefix01
	* @brief		xmlChar *xmlTextReaderPrefix(xmlTextReaderPtr reader)
	* @desc         +ve and _ve TCs for xmlTextReaderPrefix
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Sathish Kumar (satish.k4@samsung.com)
	* @return		void
	* @see			none
	* @remarks      input1: [N/A, N/A] @n
        		    {xmlTextReaderPtr(NULL)} => {N/A | int(NULL)} @n
        		    input2: [N/A, N/A] @n
		     		{xmlTextReaderPtr(reader)} => {N/A | int(NULL)} @n
	*
	* @b priority
	* @b etc		none
	*/

static void UTcxmlTextReaderPrefix01()
{
#if defined(LIBXML_READER_ENABLED)
	xmlChar * ret_val;
	xmlTextReaderPtr reader; /* the xmlTextReaderPtr used */
	int n_reader;
	int ret = 0;

	for (n_reader = 0;n_reader < gen_nb_xmlTextReaderPtr;n_reader++) {
		//reader = gen_xmlTextReaderPtr(n_reader, 0);
		reader = gen_xmlTextReaderPtr(0, 0);
		ret = xmlTextReaderRead(reader);
		while (ret == 1)
		{
			ret_val = xmlTextReaderPrefix(reader);
			ret = xmlTextReaderRead(reader);
		}
		DTS_CHECK_NE_MESSAGE("xmlTextReaderPrefix", (void *)ret_val, (void *)NULL, "xmlTextReaderPrefix Failed");		
		desret_xmlChar_ptr(ret_val);
		des_xmlTextReaderPtr(n_reader, reader, 0);
		xmlResetLastError();
	}
#endif
}

static void desret_xmlNodePtr(xmlNodePtr val)
{
    if ((val != NULL) && (val != api_root) && (val != (xmlNodePtr) api_doc))
    {
      xmlUnlinkNode(val);
      xmlFreeNode(val);
    }
}
	/**
	* @test			UTcxmlTextReaderPreserve01
	* @brief		xmlNodePtr xmlTextReaderPreserve(xmlTextReaderPtr reader)
	* @desc         +ve and _ve TCs for xmlTextReaderPreserve
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Sathish Kumar (satish.k4@samsung.com)
	* @return		void
	* @see			none
	* @remarks      input1: [N/A, N/A] @n
        			{xmlTextReaderPtr(reader)} => {N/A | int(NULL)} @n
	*
	* @b priority
	* @b etc		none
	*/
static void UTcxmlTextReaderPreserve01()
{
 

#if defined(LIBXML_READER_ENABLED)
    
    xmlNodePtr ret_val;
    xmlTextReaderPtr reader; /* the xmlTextReaderPtr used */
    int n_reader;

    for (n_reader = 0;n_reader < gen_nb_xmlTextReaderPtr;n_reader++) {
        
        reader = gen_xmlTextReaderPtr(n_reader, 0);


        if(n_reader == 0)
        {
        	// @remarks   input1: [N/A, N/A] @n
        	//  		  {xmlTextReaderPtr(reader)} => {N/A | int(NULL)} @n
        	ret_val = xmlTextReaderPreserve(NULL);
		DTS_CHECK_EQ_MESSAGE("xmlTextReaderPreserve", (void *)ret_val, (void *)NULL, "xmlTextReaderPreserve Failed");		
        }

        desret_xmlNodePtr(ret_val);
        des_xmlTextReaderPtr(n_reader, reader, 0);
        xmlResetLastError();
    }
    
#endif
}
	/**
	* @test			UTcxmlTextReaderPreservePattern01
	* @brief		int xmlTextReaderPreservePattern(xmlTextReaderPtr reader,
	*                                                const xmlChar *pattern,
                                                     const xmlChar **namespaces)
	* @desc         +ve and _ve TCs for xmlTextReaderPreservePattern
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Sathish Kumar (satish.k4@samsung.com)
	* @return		void
	* @see			none
	* @remarks      input1: [N/A, N/A] @n
    	  		    {xmlTextReaderPtr(NULL), const xmlChar *(pattern), const xmlChar **(namespaces)} => {N/A | N/A} @n
    	  		    input2: [N/A, N/A] @n
    	  		    {xmlTextReaderPtr(reader), const xmlChar *(NULL), const xmlChar **(namespaces)} => {N/A | N/A} @n
	*
	* @b priority
	* @b etc		none
	*/
	
static void UTcxmlTextReaderPreservePattern01()
{
 

#if defined(LIBXML_READER_ENABLED) && defined(LIBXML_PATTERN_ENABLED)
#ifdef LIBXML_PATTERN_ENABLED
    
    int ret_val;
    xmlTextReaderPtr reader; /* the xmlTextReaderPtr used */
    int n_reader;
    xmlChar * pattern; /* an XPath subset pattern */
    int n_pattern;
    xmlChar ** namespaces; /* the prefix definitions, array of [URI, prefix] or NULL */
    int n_namespaces;

    for (n_reader = 0;n_reader < gen_nb_xmlTextReaderPtr;n_reader++) {
    for (n_pattern = 0;n_pattern < gen_nb_const_xmlChar_ptr;n_pattern++) {
    for (n_namespaces = 0;n_namespaces < gen_nb_const_xmlChar_ptr_ptr;n_namespaces++) {
        
        reader = gen_xmlTextReaderPtr(n_reader, 0);
        pattern = gen_const_xmlChar_ptr(n_pattern, 1);
        namespaces = gen_const_xmlChar_ptr_ptr(n_namespaces, 2);

    	// @remarks   input1: [N/A, N/A] @n
    	//  		  {xmlTextReaderPtr(NULL), const xmlChar *(pattern), const xmlChar **(namespaces)} => {N/A | N/A} @n
        ret_val = xmlTextReaderPreservePattern(NULL, (const xmlChar *)pattern, (const xmlChar **)namespaces);
	DTS_CHECK_EQ_MESSAGE("xmlTextReaderPreservePattern", (void *)ret_val, (void *)-1, "xmlTextReaderPreservePattern Failed");		

    	// @remarks   input2: [N/A, N/A] @n
    	//  		  {xmlTextReaderPtr(reader), const xmlChar *(NULL), const xmlChar **(namespaces)} => {N/A | N/A} @n
        {
        	xmlTextReaderPtr reader = gen_xmlTextReaderPtr(3, 0);
        	ret_val = xmlTextReaderPreservePattern(reader, NULL, (const xmlChar **)namespaces);
		DTS_CHECK_EQ_MESSAGE("xmlTextReaderPreservePattern", (void *)ret_val, (void *)-1, "xmlTextReaderPreservePattern Failed");			
        }

        desret_int(ret_val);
        des_xmlTextReaderPtr(n_reader, reader, 0);
        des_const_xmlChar_ptr(n_pattern, (const xmlChar *)pattern, 1);
        des_const_xmlChar_ptr_ptr(n_namespaces, (const xmlChar **)namespaces, 2);
        xmlResetLastError();
    }
    }
    }
    
#endif
#endif
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
	{UTcXmlNewTextReaderFilenameP01,1},
	{UTcXmlReaderForDocP01,2},
	{UTcXmlReaderForFileP01,3},
	{UTcXmlReaderForMemoryP01,4},
	{UTcXmlReaderNewDocP01,5},
	{UTcXmlReaderNewFileP01,6},
	{UTcXmlReaderNewMemoryP01,7},
	{UTcXmlReaderNewWalkerP01,8},
	{UTcXmlReaderWalkerP01,9},
	{UTcXmlTextReaderAttributeCountP01,10},

	{UTcXmlTextReaderBaseUriP01,11},
	{UTcXmlTextReaderCloseP01,12},
	{UTcXmlTextReaderConstBaseUriP01,13},
	{UTcXmlTextReaderConstLocalNameP01,14},
	{UTcXmlTextReaderConstNameP01,15},
	{UTcXmlTextReaderConstNamespaceUriP01,16},
	{UTcXmlTextReaderConstPrefixP01,17},
	{UTcXmlTextReaderConstStringP01,18},
	{UTcXmlTextReaderConstValueP01,19},
	{UTcXmlTextReaderConstXmlLangP01,20},

	{UTcXmlTextReaderCurrentDocP01,21},
	{UTcxmlTextReaderIsDefault01,22},
	{UTcxmlTextReaderIsEmptyElement01,23},
	{UTcxmlTextReaderIsValid01,24},
	{UTcxmlTextReaderLocalName01,25},
	{UTcxmlTextReaderLocatorBaseURI01,26},
	{UTcxmlTextReaderLocatorLineNumber01,27},
	{UTcxmlTextReaderLookupNamespace01,28},
	{UTcxmlTextReaderMoveToAttributeNo01,29},
	{UTcxmlTextReaderMoveToAttributeNs01,30},

	{UTcxmlTextReaderMoveToElement01,31},
	{UTcxmlTextReaderMoveToNextAttribute01,32},
	{UTcxmlTextReaderName01,33},
	{UTcxmlTextReaderNamespaceUri01,34},
	{UTcxmlTextReaderNextSibling01,35},
	{UTcxmlTextReaderNodeType01,36},
	{UTcxmlTextReaderNormalization01,37},
	{UTcxmlTextReaderPrefix01,38},
	{UTcxmlTextReaderPreserve01,39},
	{UTcxmlTextReaderPreservePattern01,40},
	{ NULL, 0 },
	
};


