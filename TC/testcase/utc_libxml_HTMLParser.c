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


/***************************************************************************
* SUTsXmlWriter
***************************************************************************/
#define MY_ENCODING "ISO-8859-1"

                    //Target
#define	OUTFILE1	UTSHOME"/writer1.res"
#define	OUTFILE2	UTSHOME"/missing.xml"
#define	OUTFILE3	UTSHOME"/test.out"


/******************************************************************************************/
/******************************************************************************************/

static htmlDocPtr api_doc = NULL;
//static htmlDtdPtr api_dtd = NULL;
static htmlNodePtr api_root = NULL;
//static htmlAttrPtr api_attr = NULL;
//static htmlNsPtr api_ns = NULL;

static int call_tests = 0;
static int inttab[1024];
static xmlChar chartab[1024];
/********************************************************************************************/
/********************************************************************************************/
#define gen_nb_const_xmlChar_ptr1 1
#define gen_nb_const_htmlElemDesc_ptr 1
#define gen_nb_const_htmlElemDesc_ptr1 2
#define gen_nb_int 4
#define gen_nb_htmlDocPtr 3
#define gen_nb_htmlNodePtr 1
#define gen_nb_htmlNodePtr1 2
#define gen_nb_const_char_ptr 2
#define gen_nb_const_char_ptr2 4
#define gen_nb_htmlSAXHandlerPtr 1
#define gen_nb_userdata 3
#define gen_nb_fileoutput 6
#define gen_nb_xmlCharEncoding 4
#define gen_nb_htmlParserCtxtPtr 3
#define gen_nb_const_xmlChar_ptr 5
#define gen_nb_filepath 8
#define gen_nb_unsigned_char_ptr 1
#define gen_nb_int_ptr 2
#define gen_nb_const_unsigned_char_ptr 1
#define gen_nb_const_htmlNodePtr1 2
#define gen_nb_unsigned_int 3
#define gen_nb_unsigned_int1 4
#define gen_nb_xmlChar_ptr 2
#define gen_nb_const_xmlChar_ptr_ptr 1
/*******************************************************************************************/
/*******************************************************************************************/
static void
free_api_doc(void) {
   // htmlFreeDoc(api_doc);
    api_doc = NULL;
    //api_dtd = NULL;
    api_root = NULL;
   // api_attr = NULL;
   // api_ns = NULL;
}

static htmlDocPtr
get_api_doc(void) {
    if (api_doc == NULL) {
        api_doc = htmlReadMemory("<!DOCTYPE root [<!ELEMENT root EMPTY>]><root xmlns:h='http://example.com/' h:foo='bar'/>", 88, "root_test", NULL, 0);
	api_root = NULL;
	//api_attr = NULL;
    }
    return(api_doc);
}

static htmlNodePtr
get_api_root_NodeStatus(void) {
    if ((api_root == NULL) || (api_root->type != XML_ELEMENT_NODE)) {
       get_api_doc();
	if ((api_doc != NULL) && (api_doc->children != NULL) &&
	    (api_doc->children->next != NULL) &&
	    (api_doc->children->next->type == XML_ELEMENT_NODE))
	{
		api_doc->children->next->type = XML_CDATA_SECTION_NODE;
	    api_root = api_doc->children->next;
	}
    }


    return(api_root);
}

static htmlNodePtr
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


static const htmlElemDesc * gen_const_htmlElemDesc_ptr_AttrAllowed(int no ATTRIBUTE_UNUSED, int nr ATTRIBUTE_UNUSED) {
    if(no == 0) return((htmlTagLookup((xmlChar *)"script")));
	return(NULL);
}

static const htmlElemDesc * gen_const_htmlElemDesc_ptr_ElementAllowedHere(int no ATTRIBUTE_UNUSED, int nr ATTRIBUTE_UNUSED) {
    if(no == 0) return((htmlTagLookup((xmlChar *)"form")));
	return(NULL);
}

static const htmlElemDesc * gen_const_htmlElemDesc_ptr_ElementStatusHere(int no ATTRIBUTE_UNUSED, int nr ATTRIBUTE_UNUSED) {
    if(no == 0) return((htmlTagLookup((xmlChar *)"script")));
    if(no == 1) return((htmlTagLookup((xmlChar *)"form")));
	return(NULL);
}

static const xmlChar * gen_htmlTagLookup_ptr(int no ATTRIBUTE_UNUSED, int nr ATTRIBUTE_UNUSED) {
    if(no == 0) return((xmlChar *)"a");
    if(no == 1) return((xmlChar *)"samsung");
	return(NULL);
}

static htmlElemDesc * gen_const_htmlElemDesc_ptr(int no ATTRIBUTE_UNUSED, int nr ATTRIBUTE_UNUSED) {
    //if(no == 0) return((htmlTagLookup((xmlChar *)"script")));
	return(NULL);
}
static void des_const_htmlElemDesc_ptr(int no ATTRIBUTE_UNUSED, const htmlElemDesc * val ATTRIBUTE_UNUSED, int nr ATTRIBUTE_UNUSED) {
}

static void des_const_xmlChar_ptr(int no ATTRIBUTE_UNUSED, const xmlChar *val ATTRIBUTE_UNUSED, int nr ATTRIBUTE_UNUSED) {
}

static void des_int(int no ATTRIBUTE_UNUSED, int val ATTRIBUTE_UNUSED, int nr ATTRIBUTE_UNUSED) {
}

static xmlChar *gen_const_xmlChar_ptr(int no, int nr ATTRIBUTE_UNUSED) {
    if (no == 0) return((xmlChar *) "foo");
    if (no == 1) return((xmlChar *) "<foo/>");
    if (no == 2) return((xmlChar *) "n?e");
    if (no == 3) return((xmlChar *) " 2ab ");
    return(NULL);
}

static xmlChar *gen_const_xmlChar_ptr_ScriptAttribute(int no, int nr ATTRIBUTE_UNUSED) {
    if (no == 0) return((xmlChar *) "foo");
    if (no == 1) return((xmlChar *) "<foo/>");
    if (no == 2) return((xmlChar *) "n?e");
    if (no == 3) return((xmlChar *) " 2ab ");
    if (no == 4) return((xmlChar *) "onclick");
    return(NULL);
}

static xmlChar *gen_const_xmlChar_ptr_AttrAllowed(int no, int nr ATTRIBUTE_UNUSED) {
    if (no == 0) return((xmlChar *) "foo");
    if (no == 1) return((xmlChar *) "<foo/>");
    if (no == 2) return((xmlChar *) "n?e");
    if (no == 3) return((xmlChar *) " 2ab ");
    if (no == 4) return((xmlChar *) "type");
    return(NULL);
}

static xmlChar *gen_const_xmlChar_ptr_htmlElementAllowedHere(int no, int nr ATTRIBUTE_UNUSED) {
    if (no == 0) return((xmlChar *) "foo");
    if (no == 1) return((xmlChar *) "<foo/>");
    if (no == 2) return((xmlChar *) "n?e");
    if (no == 3) return((xmlChar *) " 2ab ");
    if (no == 4) return((xmlChar *) "pre");
    return(NULL);
}

static xmlChar *gen_const_xmlChar_ptr_EntityLookup(int no, int nr ATTRIBUTE_UNUSED) {
    if (no == 0) return((xmlChar *) "foo");
    if (no == 1) return((xmlChar *) "<foo/>");
    if (no == 2) return((xmlChar *) "n?e");
    if (no == 3) return((xmlChar *) " 2ab ");
    if (no == 4) return((xmlChar *) "amp");
    return(NULL);
}
static int gen_int(int no, int nr ATTRIBUTE_UNUSED) {
    if (no == 0) return(0);
    if (no == 1) return(1);
    if (no == 2) return(-1);
    if (no == 3) return(122);
    return(-1);
}

static htmlDocPtr gen_htmlDocPtr(int no ATTRIBUTE_UNUSED, int nr ATTRIBUTE_UNUSED) {
    //if (no == 0) return(htmlNewDoc(NULL, NULL));
    //if (no == 0) return(htmlNewDocNoDtD(NULL, NULL));
    if (no == 0) return(htmlNewDoc(NULL, NULL));
    if (no == 1) return(htmlReadMemory("<html/>", 7, "test", NULL, 0));
    return(NULL);
}
static void desret_htmlStatus(htmlStatus val ATTRIBUTE_UNUSED) {
}

static htmlNodePtr gen_htmlNodePtr(int no ATTRIBUTE_UNUSED, int nr ATTRIBUTE_UNUSED) {
    //if(no == 1){return(get_api_root());}
	return(NULL);
}
static htmlNodePtr gen_htmlNodePtr_AutoCloseTag(int no ATTRIBUTE_UNUSED, int nr ATTRIBUTE_UNUSED) {
    //if(no == 1){return(get_api_root());}
	//if(no == 0) return(get_api_root());
	return(NULL);
}
static void des_htmlDocPtr(int no ATTRIBUTE_UNUSED, htmlDocPtr val ATTRIBUTE_UNUSED, int nr ATTRIBUTE_UNUSED) {
    if ((val != NULL) && (val != api_doc) && (val->doc != api_doc))
        xmlFreeDoc(val);
}
static void des_htmlNodePtr(int no ATTRIBUTE_UNUSED, htmlNodePtr val ATTRIBUTE_UNUSED, int nr ATTRIBUTE_UNUSED) {
}

static char *gen_const_char_ptr(int no, int nr ATTRIBUTE_UNUSED) {
    if (no == 0) return((char *) "foo");
    if (no == 1) return((char *) "<foo/>");
    if (no == 2) return((char *) "test/ent2");
    return(NULL);
}

static htmlSAXHandlerPtr gen_htmlSAXHandlerPtr(int no ATTRIBUTE_UNUSED, int nr ATTRIBUTE_UNUSED) {
    return(NULL);
}

static void *gen_userdata(int no, int nr ATTRIBUTE_UNUSED) {
    if (no == 0) return((void *) &call_tests);
    if (no == 1) return((void *) -1);
    return(NULL);
}

static xmlCharEncoding gen_xmlCharEncoding(int no, int nr ATTRIBUTE_UNUSED) {
    if (no == 0) return(XML_CHAR_ENCODING_UTF8);
    if (no == 1) return(XML_CHAR_ENCODING_NONE);
    if (no == 2) return(XML_CHAR_ENCODING_8859_1);
    return(XML_CHAR_ENCODING_ERROR);
}

static void desret_htmlParserCtxtPtr(htmlParserCtxtPtr val) {
    if (val != NULL)
        htmlFreeParserCtxt(val);
}

static void des_htmlSAXHandlerPtr(int no ATTRIBUTE_UNUSED, htmlSAXHandlerPtr val ATTRIBUTE_UNUSED, int nr ATTRIBUTE_UNUSED) {
}

static void des_userdata(int no ATTRIBUTE_UNUSED, void *val ATTRIBUTE_UNUSED, int nr ATTRIBUTE_UNUSED) {
}

static void des_const_char_ptr(int no ATTRIBUTE_UNUSED, const char *val ATTRIBUTE_UNUSED, int nr ATTRIBUTE_UNUSED) {
}

static void des_fileoutput(int no ATTRIBUTE_UNUSED, const char *val ATTRIBUTE_UNUSED, int nr ATTRIBUTE_UNUSED) {
}

static void des_xmlCharEncoding(int no ATTRIBUTE_UNUSED, xmlCharEncoding val ATTRIBUTE_UNUSED, int nr ATTRIBUTE_UNUSED) {
}
static void desret_int(int val ATTRIBUTE_UNUSED) {
}

static unsigned char * gen_unsigned_char_ptr(int no ATTRIBUTE_UNUSED, int nr ATTRIBUTE_UNUSED) {
    if(no == 0)return ((unsigned char*)"samsung");
	return(NULL);
}
static htmlParserCtxtPtr gen_htmlParserCtxtPtr(int no ATTRIBUTE_UNUSED, int nr ATTRIBUTE_UNUSED) {
    if (no == 0) return(xmlNewParserCtxt());
    return(NULL);
}

static htmlParserCtxtPtr gen_htmlParserCtxtPtr_ParseDocument(int no ATTRIBUTE_UNUSED, int nr ATTRIBUTE_UNUSED) {

	if (no == 0) return(xmlNewParserCtxt());
    if (no == 1) return(htmlCreateMemoryParserCtxt("<html/>", 7));
    if (no == 2)
    {
    	htmlParserCtxtPtr CtxtPtr;
    	CtxtPtr = htmlCreateMemoryParserCtxt("<html/>", 7);
    	CtxtPtr->wellFormed = 0;
    	return CtxtPtr;
    }
    return(NULL);
}


static const char *gen_filepath(int no, int nr ATTRIBUTE_UNUSED) {
    if (no == 0) return(MISSINGXML);
    if (no == 1) return("<foo/>");
              //Target
    if (no == 2) return(ENT2);
    if (no == 3) return(RECxml19980210);
    if (no == 4) return(XHTML1STRICTDTD);

    if (no == 5) return(REMOTE1GOOD);
    if (no == 6) return(REMOTE1BAD);
    return(NULL);
}

static htmlParserCtxtPtr gen_htmlParserCtxtPtr_1(int no ATTRIBUTE_UNUSED, int nr ATTRIBUTE_UNUSED) {

	if (no == 0) return(xmlNewParserCtxt());
    if (no == 1) return(htmlCreateMemoryParserCtxt("<html/>", 7));
    if (no == 2)
    {
    	const char *char1;
    	htmlParserCtxtPtr CtxtPtr;
    	xmlParserCtxtPtr xmlCtxtPtr = NULL;
    	CtxtPtr = htmlCreateMemoryParserCtxt("<html/>", 7);
    	return CtxtPtr;
    }
    return(NULL);
}
static void desret_htmlDocPtr(htmlDocPtr val) {
    if ((val != NULL) && (val != api_doc) && (val->doc != api_doc))
        xmlFreeDoc(val);
}

static void des_htmlParserCtxtPtr(int no ATTRIBUTE_UNUSED, htmlParserCtxtPtr val ATTRIBUTE_UNUSED, int nr ATTRIBUTE_UNUSED) {
    if (val != NULL)
        htmlFreeParserCtxt(val);
}

static void des_filepath(int no ATTRIBUTE_UNUSED, const char *val ATTRIBUTE_UNUSED, int nr ATTRIBUTE_UNUSED) {
}

static int *gen_int_ptr(int no, int nr) {
    if (no == 0) return(&inttab[nr]);
    return(NULL);
}

static unsigned char * gen_const_unsigned_char_ptr(int no ATTRIBUTE_UNUSED, int nr ATTRIBUTE_UNUSED) {
    if(no == 0) return((unsigned char*)"samsung");
	return(NULL);
}
static void des_const_unsigned_char_ptr(int no ATTRIBUTE_UNUSED, const unsigned char * val ATTRIBUTE_UNUSED, int nr ATTRIBUTE_UNUSED) {
}

static void des_int_ptr(int no ATTRIBUTE_UNUSED, int *val ATTRIBUTE_UNUSED, int nr ATTRIBUTE_UNUSED) {
}

static void des_unsigned_char_ptr(int no ATTRIBUTE_UNUSED, unsigned char * val ATTRIBUTE_UNUSED, int nr ATTRIBUTE_UNUSED) {
}

static htmlNodePtr gen_const_htmlNodePtr_NodeStatus(int no ATTRIBUTE_UNUSED, int nr ATTRIBUTE_UNUSED) {
	if(no == 0) return(get_api_root_NodeStatus());
	return(NULL);
}

static void des_const_htmlNodePtr(int no ATTRIBUTE_UNUSED, const htmlNodePtr val ATTRIBUTE_UNUSED, int nr ATTRIBUTE_UNUSED) {
}

static void desret_const_htmlEntityDesc_ptr(const htmlEntityDesc * val ATTRIBUTE_UNUSED) {
}

static unsigned int gen_unsigned_int(int no, int nr ATTRIBUTE_UNUSED) {
    if (no == 0) return(0);
    if (no == 1) return(1);
    if (no == 2) return(122);
    return((unsigned int) -1);
}
static unsigned int gen_unsigned_int_EntityValueLookup(int no, int nr ATTRIBUTE_UNUSED) {
    if (no == 0) return(0);
    if (no == 1) return(1);
    if (no == 2) return(122);
    if (no == 3) return(34);
    return((unsigned int) -1);
}

static void des_unsigned_int(int no ATTRIBUTE_UNUSED, unsigned int val ATTRIBUTE_UNUSED, int nr ATTRIBUTE_UNUSED) {
}

static xmlChar *gen_xmlChar_ptr_ParseDoc(int no, int nr ATTRIBUTE_UNUSED) {
    if (no == 0) return(&chartab[0]);
   if (no == 1) return((xmlChar *) "samsung");
    return(NULL);
}

static void des_xmlChar_ptr(int no ATTRIBUTE_UNUSED, xmlChar *val ATTRIBUTE_UNUSED, int nr ATTRIBUTE_UNUSED) {
}

static xmlChar ** gen_const_xmlChar_ptr_ptr(int no ATTRIBUTE_UNUSED, int nr ATTRIBUTE_UNUSED) {
    return(NULL);
}

static void des_const_xmlChar_ptr_ptr(int no ATTRIBUTE_UNUSED, const xmlChar ** val ATTRIBUTE_UNUSED, int nr ATTRIBUTE_UNUSED) {
}

static xmlChar *gen_xmlChar_ptr(int no, int nr ATTRIBUTE_UNUSED) {

	memset(chartab, 0, sizeof(chartab));
	strncpy((char *) chartab, "  chartab\n", 20);
    if (no == 0) return(&chartab[0]);
    return(NULL);
}
/******************************************************************************************/
/******************************************************************************************/

	/**
	* @test			UTcHtmlAttrAllowedP01
	* @brief		htmlStatus htmlAttrAllowed(const htmlElemDesc* elt, const xmlChar* attr, int legacy)
	* @desc			Positive and Negative Test for htmlAttrAllowed
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Sathish Kumar (satish.k4@samsung.com)
	* @return		void
	* @see			none
	* @remarks		input1: [N/A, N/A] @n
	*   			{xmlTextWriterPtr(htmlElemDesc(html_emt_ptr),xmlChar(val_char),int(1)} => {N/A | htmlStatus(ret_html_status)} @n

					input1: [N/A, N/A] @n
	*   			{xmlTextWriterPtr(htmlElemDesc(html_emt_ptr),xmlChar(val_char),int(1)} => {N/A | htmlStatus(ret_html_status)} @n
	* @b priority	Middle
	* @b etc		none
	*/

static void UTcHtmlAttrAllowedP01()
{
	    int test_ret = 0;
	    htmlStatus ret_val;
	    const htmlElemDesc * elt; /* HTML element */
 	    int n_elt;
	    xmlChar * attr; /* HTML attribute */
	    int n_attr;
	    int legacy; /* whether to allow deprecated attributes */
	    int n_legacy;
	    for (n_elt = 0;n_elt < gen_nb_const_htmlElemDesc_ptr;n_elt++) {
	    for (n_attr = 0;n_attr < gen_nb_const_xmlChar_ptr;n_attr++) {
	    for (n_legacy = 0;n_legacy < gen_nb_int;n_legacy++) {

	    	elt = gen_const_htmlElemDesc_ptr_AttrAllowed(n_elt, 0);
	        attr = gen_const_xmlChar_ptr_AttrAllowed(n_attr, 1);
	        legacy = gen_int(n_legacy, 2);

	        /* * @remarks input1: [N/A, N /A] @n
	         * {htmlElemDesc*(elt),xmlChar*(attr),int()} => {N/A | int(!=1)} @n
	       */
	        ret_val = htmlAttrAllowed((const htmlElemDesc *)elt, (const xmlChar *)attr, legacy);
	        if(ret_val == 1)
	        {
	            //Negative test
			DTS_CHECK_EQ_MESSAGE("htmlAttrAllowed", (void*)ret_val, 1, "htmlAttrAllowed Failed");
	        }
	        else
	        {
	        	//positive test
			DTS_CHECK_NE_MESSAGE("htmlAttrAllowed", (void*)ret_val, 1, "htmlAttrAllowed Failed");	
	        }


	     	des_const_htmlElemDesc_ptr(n_elt, (const htmlElemDesc *)elt, 0);
	        des_const_xmlChar_ptr(n_attr, (const xmlChar *)attr, 1);
	        des_int(n_legacy, legacy, 2);
	        xmlResetLastError();
	       }
	      }
	     }
}

/**
	* @test			UTcHtmlAttrAllowedP01
	* @brief		htmlStatus htmlAttrAllowed(const htmlElemDesc* elt, const xmlChar* attr, int legacy)
	* @desc			Positive and Negative Test for htmlAttrAllowed
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Sathish Kumar (satish.k4@samsung.com)
	* @return		void
	* @see			none
	* @remarks		input1: [N/A, N/A] @n
	*   			{xmlTextWriterPtr(htmlElemDesc(html_emt_ptr),xmlChar(val_char),int(1)} => {N/A | htmlStatus(ret_html_status)} @n

	*				input2: [N/A, N/A] @n
	*   			{xmlTextWriterPtr(htmlElemDesc(html_emt_ptr),xmlChar(val_char),int(1)} => {N/A | htmlStatus(ret_html_status)} @n

	*				input3: [N/A, N/A] @n
    *			    {xmlTextWriterPtr(htmlDocPtr(html_emt_ptr->attrs_depr!=NULL),xmlChar(val_char='s'),xmlNodePtr(node_ptr->name='p')} => {N/A | int(1)} @n

	*				input4: [N/A, N/A] @n
	*				{xmlTextWriterPtr(htmlDocPtr(html_emt_ptr->attrs_depr!=NULL),xmlChar(val_char='s'),xmlNodePtr(node_ptr->children=NULL)} => {N/A | int(1)} @n

	*				input5: [N/A, N/A] @n
	*				{xmlTextWriterPtr(htmlDocPtr(html_emt_ptr->attrs_depr!=NULL),xmlChar(val_char='s'),xmlNodePtr(node_ptr->children!=NULL)} => {N/A | int(1)} @n

	* @b priority	Middle
	* @b etc		none
	*/
static void UTcHtmlAutoCloseTagP01()
{
		int ret_val;
	    htmlDocPtr doc; /* the HTML document */
	    int n_doc;
	    xmlChar * name; /* The tag name */
	    int n_name;
	    htmlNodePtr elem; /* the HTML element */
	    int n_elem;

	    for (n_doc = 0;n_doc < gen_nb_htmlDocPtr;n_doc++) {
	    for (n_name = 0;n_name < gen_nb_const_xmlChar_ptr;n_name++) {
	    for (n_elem = 0;n_elem < gen_nb_htmlNodePtr1;n_elem++) {

	        doc = gen_htmlDocPtr(n_doc, 0);
	        name = gen_const_xmlChar_ptr(n_name, 1);
	        elem = gen_htmlNodePtr_AutoCloseTag(n_elem, 2);
	        /* * @remarks input1: [N/A, N/A] @n
	       	   * {htmlDocPtr(doc),const xmlChar*(name),htmlNodePtr(elem)} => {N/A | int(1)} @n
	       	   *
	       	*/
	        ret_val = htmlAutoCloseTag(doc, (const xmlChar *)name, elem);
	        if(ret_val == 1)
	        {
	        	 //positive test case
		 	DTS_CHECK_EQ_MESSAGE("htmlAutoCloseTag", (void*)ret_val, 1, "htmlAutoCloseTag Failed");
	        }
	        else
	        {
	        	//Negative test case
			DTS_CHECK_EQ_MESSAGE("htmlAutoCloseTag", (void*)ret_val, 0, "htmlAutoCloseTag Failed");
	        }
	        desret_int(ret_val);
	        des_const_xmlChar_ptr(n_name, (const xmlChar *)name, 1);
	        des_htmlNodePtr(n_elem, elem, 2);
	        xmlResetLastError();

	    }
	    }
	    }
}


	/**
		* @test			UTcHtmlAttrAllowedP01
		* @brief		htmlParserCtxtPtr htmlCreateMemoryParserCtxt(const char *buffer, int size)
		* @desc			Positive and Negative Test for htmlCreateMemoryParserCtxt
		* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
		* @b tester		Sathish Kumar (satish.k4@samsung.com)
		* @return		void
		* @see			none
		* @remarks input1: [N/A, N/A] @n
	    * {xmlTextWriterPtr(const char(buffer),int(size))} => {N/A | htmlParserCtxtPtr)} @n

		* @b priority	Middle
		* @b etc		none
		*/
static void UTcHtmlCreateMemoryParserCtxtP01()
{

		//int test_ret = 0;

	    htmlParserCtxtPtr ret_val;
	    char * buffer; /* a pointer to a char array */
	    int n_buffer;
	    int size; /* the size of the array */
	    int n_size;
	    int count=1;

	    for (n_buffer = 0;n_buffer < gen_nb_const_char_ptr2;n_buffer++) {
	    for (n_size = 0;n_size < gen_nb_int;n_size++) {
	       	buffer = gen_const_char_ptr(n_buffer, 0);
	        size = gen_int(n_size, 1);

	        /* * @remarks input1: [N/A, N/A] @n
	         * {const char*(buffer),int(size)} => {N/A | NULL)} @n
	       	 *
	        */
	        ret_val = htmlCreateMemoryParserCtxt((const char *)buffer, size);
            if(ret_val == NULL)
            {
            	   //Negative test
			DTS_CHECK_EQ_MESSAGE("htmlCreateMemoryParserCtxt", (void*)ret_val, NULL, "htmlCreateMemoryParserCtxt Failed");
            }
            else
            {
            	//Positive test
			DTS_CHECK_NE_MESSAGE("htmlCreateMemoryParserCtxt", (void*)ret_val, NULL, "htmlCreateMemoryParserCtxt Failed");
            }

            desret_htmlParserCtxtPtr(ret_val);
            des_const_char_ptr(n_buffer, (const char *)buffer, 0);
            des_int(n_size, size, 1);
            xmlResetLastError();
	     }
	    }
}

	/**
	* @test			UTcHtmlCreatePushParserCtxtP01
	* @brief		htmlParserCtxtPtr htmlCreatePushParserCtxt(htmlSAXHandlerPtr sax,
	* 				void *user_data,const char *chunk, int size,
	*        const char *filename,xmlCharEncoding enc)
	* @desc			Positive and Negative Test for htmlCreateMemoryParserCtxt
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Sathish Kumar (satish.k4@samsung.com)
	* @return		void
	* @see			none
	* @remarks input1: [N/A, N/A] @n
	* {htmlSAXHandlerPtr(sax),void*(user_data),const char(*chunk),int(size),
	* 			const char(*filename),xmlCharEncoding(enc)} => {N/A | htmlParserCtxtPtr)} @n

	* @b priority	Middle
	* @b etc		none
	*/
static void UTcHtmlCreatePushParserCtxtP01()
{

		htmlParserCtxtPtr ret_val;
	    htmlSAXHandlerPtr sax; /* a SAX handler */
	    int n_sax;
	    void * user_data; /* The user data returned on SAX callbacks */
	    int n_user_data;
	    char * chunk; /* a pointer to an array of chars */
	    int n_chunk;
	    int size; /* number of chars in the array */
	    int n_size;
	    const char * filename; /* an optional file name or URI */
	    int n_filename;
	    xmlCharEncoding enc; /* an optional encoding */
	    int n_enc;

	    for (n_sax = 0;n_sax < gen_nb_htmlSAXHandlerPtr;n_sax++) {
	    for (n_user_data = 0;n_user_data < gen_nb_userdata;n_user_data++) {
	    for (n_chunk = 0;n_chunk < gen_nb_const_char_ptr;n_chunk++) {
	    for (n_size = 0;n_size < gen_nb_int;n_size++) {
	    for (n_filename = 0;n_filename < gen_nb_fileoutput;n_filename++) {
	    for (n_enc = 0;n_enc < gen_nb_xmlCharEncoding;n_enc++) {

	        sax = gen_htmlSAXHandlerPtr(n_sax, 0);
	        user_data = gen_userdata(n_user_data, 1);
	        chunk = gen_const_char_ptr(n_chunk, 2);
	        size = gen_int(n_size, 3);
	        filename = gen_fileoutput(n_filename, 4);
	        enc = gen_xmlCharEncoding(n_enc, 5);
	        /* * @remarks input1: [N/A, N/A] @n
	           *{htmlSAXHandlerPtr(sax),void*(user_data),const char(*chunk),int(size),
		       * 	const char(*filename),xmlCharEncoding(enc)} => {N/A | htmlParserCtxtPtr)} @n
	           * Note:verification for Positive(!=NULL) test.
	        */
	        ret_val = htmlCreatePushParserCtxt(sax, user_data, (const char *)chunk, size, filename, enc);
	        if(ret_val != NULL)
	        {
	        	//Positive test
			DTS_CHECK_NE_MESSAGE("htmlCreatePushParserCtxt", (void*)ret_val, NULL, "htmlCreatePushParserCtxt Failed");
	        }
	        else
	        {
	        	//Negative test case. As per code analysis we can not make scenario for negative test case.
			DTS_CHECK_EQ_MESSAGE("htmlCreatePushParserCtxt", (void*)ret_val, NULL, "htmlCreatePushParserCtxt Failed");
	        }

	        desret_htmlParserCtxtPtr(ret_val);

	        call_tests++;
	        des_htmlSAXHandlerPtr(n_sax, sax, 0);
	        des_userdata(n_user_data, user_data, 1);
	        des_const_char_ptr(n_chunk, (const char *)chunk, 2);
	        des_int(n_size, size, 3);
	        des_fileoutput(n_filename, filename, 4);
	        des_xmlCharEncoding(n_enc, enc, 5);

	    }
	    }
	    }
	    }
	    }
	    }
}

	/**
			* @test			UTcHtmlCtxtReadDocP01
			* @brief		htmlDocPtr htmlCtxtReadDoc(htmlParserCtxtPtr ctxt, const xmlChar * cur,
               	   	   	   	   	   	   	   	   	   const char *URL, const char *encoding, int options)

			* @desc			Positive and Negative Test for htmlCtxtReadDoc
			* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
			* @b tester		Sathish Kumar (satish.k4@samsung.com)
			* @return		void
			* @see			none
			* @remarks input1: [N/A, N/A] @n
		    * {htmlParserCtxtPtr(ctxt),const xmlChar(cur),const char(*URL),const char(*encoding),
		    * 		     	int(option)} => {N/A | htmlDocPtr(ret_val)} @n

			* @b priority	Middle
			* @b etc		none
			*/
static void UTcHtmlCtxtReadDocP01()
{
	    htmlDocPtr ret_val;
	    htmlParserCtxtPtr ctxt; /* an HTML parser context */
	    int n_ctxt;
	    xmlChar * cur; /* a pointer to a zero terminated string */
	    int n_cur;
	    const char * URL; /* the base URL to use for the document */
	    int n_URL;
	    char * encoding; /* the document encoding, or NULL */
	    int n_encoding;
	    int options; /* a combination of htmlParserOption(s) */
	    int n_options;

	    for (n_ctxt = 0;n_ctxt < gen_nb_htmlParserCtxtPtr;n_ctxt++) {
	    for (n_cur = 0;n_cur < gen_nb_const_xmlChar_ptr;n_cur++) {
	    for (n_URL = 0;n_URL < gen_nb_filepath;n_URL++) {
	    for (n_encoding = 0;n_encoding < gen_nb_const_char_ptr;n_encoding++) {
	    for (n_options = 0;n_options < gen_nb_int;n_options++) {
	        ctxt = gen_htmlParserCtxtPtr(n_ctxt, 0);
	        cur = gen_const_xmlChar_ptr(n_cur, 1);
	        URL = gen_filepath(n_URL, 2);
	        encoding = gen_const_char_ptr(n_encoding, 3);
	        options = gen_int(n_options, 4);

	        /* @remarks input1: [N/A, N/A] @n
	         * {htmlParserCtxtPtr(ctxt),const xmlChar(cur),const char(*URL),const char(*encoding),
	         * 		     	int(option)} => {N/A | htmlDocPtr(ret_val)} @n
	        */
	        ret_val = htmlCtxtReadDoc(ctxt, (const xmlChar *)cur, URL, (const char *)encoding, options);
	        if(ret_val==NULL)
	        {
	        	//Negative test case.
				DTS_CHECK_EQ_MESSAGE("htmlCtxtReadDoc", (void*)ret_val, NULL, "htmlCtxtReadDoc Failed");
	        }
	        else
	        {
	        	//Positive test case
				DTS_CHECK_NE_MESSAGE("htmlCtxtReadDoc", (void*)ret_val, NULL, "htmlCtxtReadDoc Failed");
	        }
	        call_tests++;
            des_htmlParserCtxtPtr(n_ctxt, ctxt, 0);
    	    des_const_xmlChar_ptr(n_cur, (const xmlChar *)cur, 1);
	        des_filepath(n_URL, URL, 2);
	        des_const_char_ptr(n_encoding, (const char *)encoding, 3);
	        des_int(n_options, options, 4);
	        xmlResetLastError();
	    }
	    }
	    }
	    }
	    }

}

/**
				* @test			UTcHtmlCtxtReadFileP01
				* @brief		htmlDocPtr htmlCtxtReadFile(htmlParserCtxtPtr ctxt, const char *filename,
                										const char *encoding, int options)


				* @desc			Positive and Negative Test for htmlCtxtReadFile
				* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
				* @b tester		Sathish Kumar (satish.k4@samsung.com)
				* @return		void
				* @see			none
			* @remarks input1: [N/A, N/A] @n
		    * {htmlParserCtxtPtr(ctxt),const char(filename),const char(*encoding),int(option)} => {N/A | htmlDocPtr(ret_val)} @n
			* @b priority	Middle
			* @b etc		none
		*/
static void UTcHtmlCtxtReadFileP01()
{
	    htmlDocPtr ret_val;
	    htmlParserCtxtPtr ctxt; /* an HTML parser context */
	    int n_ctxt;
	    const char* filename; /* a file or URL */
	    int n_filename;
	    char * encoding; /* the document encoding, or NULL */
	    int n_encoding;
	    int options; /* a combination of htmlParserOption(s) */
	    int n_options;

	    for (n_ctxt = 0;n_ctxt < gen_nb_htmlParserCtxtPtr;n_ctxt++) {
	    for (n_filename = 0;n_filename < gen_nb_filepath;n_filename++) {
	    for (n_encoding = 0;n_encoding < gen_nb_const_char_ptr2;n_encoding++) {
	    for (n_options = 0;n_options < gen_nb_int;n_options++) {
	        ctxt = gen_htmlParserCtxtPtr(n_ctxt, 0);
	        filename = gen_filepath(n_filename, 1);
	        encoding = gen_const_char_ptr(n_encoding, 2);
	        options = gen_int(n_options, 3);
	  /*    * @remarks input1: [N/A, N/A] @n
	        * {htmlParserCtxtPtr(ctxt),const char(filename),const char(*encoding),int(option)} => {N/A | htmlDocPtr(ret_val)} @n
	  */
	        ret_val = htmlCtxtReadFile(ctxt, filename, (const char *)encoding, options);
	        if(ret_val == NULL)
	        {
	        	//Negative test case.
			DTS_CHECK_EQ_MESSAGE("htmlCtxtReadFile", (void*)ret_val, NULL, "htmlCtxtReadFile Failed");
	        }
	        else
	        {
	        	//Positive test case,Not executing @ xmlNewInputFromFile() returning NULL;
			DTS_CHECK_NE_MESSAGE("htmlCtxtReadFile", (void*)ret_val, NULL, "htmlCtxtReadFile Failed");
	        }

	        desret_htmlDocPtr(ret_val);
	        des_htmlParserCtxtPtr(n_ctxt, ctxt, 0);
	        des_filepath(n_filename, filename, 1);
	        des_const_char_ptr(n_encoding, (const char *)encoding, 2);
	        des_int(n_options, options, 3);
	        xmlResetLastError();
	    }
	    }
	    }
	    }
}
/**
		* @test			UTcHtmlCtxtReadMemoryP01
		* @brief		htmlDocPtr htmlCtxtReadMemory(htmlParserCtxtPtr ctxt, const char *buffer, int size,
                                           const char *URL, const char *encoding, int options)
		* @desc			Positive and Negative Test for htmlCtxtReadFile
		* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
		* @b tester		Sathish Kumar (satish.k4@samsung.com)
		* @return		void
		* @see			none
		* @remarks input1: [N/A, N/A] @n
		* {htmlParserCtxtPtr(ctxt),const char(buffer),int(size),const char(URL), const char*(encoding),int(option)} => {N/A | htmlDocPtr(ret_val)} @n
		* @b priority	Middle
		* @b etc		none
	*/
static void UTcHtmlCtxtReadMemoryP01()
{
    htmlDocPtr ret_val;
    htmlParserCtxtPtr ctxt; /* an HTML parser context */
    int n_ctxt;
    char * buffer; /* a pointer to a char array */
    int n_buffer;
    int size; /* the size of the array */
    int n_size;
    const char * URL; /* the base URL to use for the document */
    int n_URL;
    char * encoding; /* the document encoding, or NULL */
    int n_encoding;
    int options; /* a combination of htmlParserOption(s) */
    int n_options;

    for (n_ctxt = 0;n_ctxt < gen_nb_htmlParserCtxtPtr;n_ctxt++) {
    for (n_buffer = 0;n_buffer < gen_nb_const_char_ptr2;n_buffer++) {
    for (n_size = 0;n_size < gen_nb_int;n_size++) {
    for (n_URL = 0;n_URL < gen_nb_filepath;n_URL++) {
    for (n_encoding = 0;n_encoding < gen_nb_const_char_ptr2;n_encoding++) {
    for (n_options = 0;n_options < gen_nb_int;n_options++) {
        ctxt = gen_htmlParserCtxtPtr(n_ctxt, 0);
        buffer = gen_const_char_ptr(n_buffer, 1);
        size = gen_int(n_size, 2);
        URL = gen_filepath(n_URL, 3);
        encoding = gen_const_char_ptr(n_encoding, 4);
        options = gen_int(n_options, 5);

        /* @remarks input1: [N/A, N/A] @n
        	* {htmlParserCtxtPtr(ctxt),const char(buffer),int(size),const char(URL), const char*(encoding),int(option)} => {N/A | htmlDocPtr(ret_val)} @n
         */
        ret_val = htmlCtxtReadMemory(ctxt, (const char *)buffer, size, URL, (const char *)encoding, options);
        if(ret_val == NULL)
        {
        	//Negative test cases
			DTS_CHECK_EQ_MESSAGE("htmlCtxtReadMemory", (void*)ret_val, NULL, "htmlCtxtReadMemory Failed");
        }

        else
        {
        	//Positive test case
			DTS_CHECK_NE_MESSAGE("htmlCtxtReadMemory",(void*) ret_val, NULL, "htmlCtxtReadMemory Failed");
        }
        des_htmlParserCtxtPtr(n_ctxt, ctxt, 0);
        des_const_char_ptr(n_buffer, (const char *)buffer, 1);
        des_int(n_size, size, 2);
        des_filepath(n_URL, URL, 3);
        des_const_char_ptr(n_encoding, (const char *)encoding, 4);
        des_int(n_options, options, 5);
        xmlResetLastError();

    }
    }
    }
    }
    }
    }

}
	/**
			* @test			UTcHtmlCtxtResetP01
			* @brief		void htmlCtxtReset(htmlParserCtxtPtr ctxt)
			* @desc			Positive and Negative Test for htmlCtxtReset
			* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
			* @b tester		Sathish Kumar (satish.k4@samsung.com)
			* @return		void
			* @see			none
			* @remarks input1: [N/A, N/A] @n
			* {htmlParserCtxtPtr(ctxt))} => {N/A | htmlParserCtxtPtr(!NULL)} @n
			* @b priority	Middle
			* @b etc		none
		*/
static void UTcHtmlCtxtResetP01()
{
	htmlParserCtxtPtr ctxt; /* an HTML parser context */
	int n_ctxt;
	for (n_ctxt = 0;n_ctxt < gen_nb_htmlParserCtxtPtr;n_ctxt++) {
		ctxt = gen_htmlParserCtxtPtr(n_ctxt, 0);
   /* * @remarks input1: [N/A, N/A] @n
	  * {htmlParserCtxtPtr(ctxt))} => {N/A | htmlParserCtxtPtr(!NULL)} @n
   */
			htmlCtxtReset(ctxt);

		if(ctxt == NULL)
		{
			//Negative test cases
			DTS_CHECK_EQ_MESSAGE("htmlCtxtReset", ctxt, NULL, "htmlCtxtReset Failed");
		}
		else
		{
			//Positive test cases
			DTS_CHECK_NE_MESSAGE("htmlCtxtReset", ctxt, NULL, "htmlCtxtReset Failed");
		}
		des_htmlParserCtxtPtr(n_ctxt, ctxt, 0);
		xmlResetLastError();
	 }
}


/**
	* @test			UTcHtmlCtxtUseOptionsP01
	* @brief		int htmlCtxtUseOptions(htmlParserCtxtPtr ctxt, int options)
	* @desc			Positive and Negative Test for htmlCtxtUseOptions
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Sathish Kumar (satish.k4@samsung.com)
	* @return		void
	* @see			none
	* @remarks     input1: [N/A, N/A] @n
	*               {htmlParserCtxtPtr(ctxt),int(option)} => {N/A | int(0)} @n
	* @b priority	Middle
	* @b etc		none
	*/
static void UTcHtmlCtxtUseOptionsP01()
{
	int mem_base;
	int ret_val;
	htmlParserCtxtPtr ctxt; /* an HTML parser context */
	int n_ctxt;
	int options; /* a combination of htmlParserOption(s) */
	int n_options;

	for (n_ctxt = 0;n_ctxt < gen_nb_htmlParserCtxtPtr;n_ctxt++) {
	for (n_options = 0;n_options < gen_nb_int;n_options++) {
		ctxt = gen_htmlParserCtxtPtr(n_ctxt, 0);
			options = gen_int(n_options, 1);

		 /*  * @remarks     input1: [N/A, N/A] @n
			 *              {htmlParserCtxtPtr(ctxt),int(option)} => {N/A | int(0)} @n
		 */
			ret_val = htmlCtxtUseOptions(ctxt, options);
			if(ret_val == 0)
			{
			   //Positive test case
				DTS_CHECK_EQ_MESSAGE("htmlCtxtUseOptions", (void*)ret_val, 0, "htmlCtxtUseOptions Failed");
			}
			else
			{
				//Negative test case
				DTS_CHECK_NE_MESSAGE("htmlCtxtUseOptions", (void*)ret_val, 0, "htmlCtxtUseOptions Failed");
			}
			desret_int(ret_val);
			call_tests++;
			des_htmlParserCtxtPtr(n_ctxt, ctxt, 0);
			des_int(n_options, options, 1);
			xmlResetLastError();
	}
	}

}

/**
	* @test			UTcHtmlElementAllowedHereP01
	* @brief		int htmlElementAllowedHere(const htmlElemDesc* parent, const xmlChar* elt)
	* @desc			Positive and Negative Test for htmlElementAllowedHere
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Sathish Kumar (satish.k4@samsung.com)
	* @return		void
	* @see			none
	* @remarks     input1: [N/A, N/A] @n
	*               {const htmlElemDesc*(parent),const xmlChar*(elt)} => {N/A | int(1)} @n
	* @b priority	Middle
	* @b etc		none
	*/
static void UTcHtmlElementAllowedHereP01()
{
	int ret_val;
	const htmlElemDesc * parent; /* HTML parent element */
	int n_parent;
	xmlChar * elt; /* HTML element */
	int n_elt;

	for (n_parent = 0;n_parent < gen_nb_const_htmlElemDesc_ptr;n_parent++) {
	for (n_elt = 0;n_elt < gen_nb_const_xmlChar_ptr;n_elt++) {

		parent = gen_const_htmlElemDesc_ptr_ElementAllowedHere(n_parent, 0);
		elt = gen_const_xmlChar_ptr_htmlElementAllowedHere(n_elt, 1);

	/*	* @remarks     input1: [N/A, N/A] @n
		*               {const htmlElemDesc*(parent),const xmlChar*(elt)} => {N/A | int(1)} @n
	*/

		ret_val = htmlElementAllowedHere((const htmlElemDesc *)parent, (const xmlChar *)elt);

		if(ret_val == 0)
	   {
		   //positive test
		   DTS_CHECK_EQ_MESSAGE("htmlElementAllowedHere", (void*)ret_val, 0, "htmlElementAllowedHere Failed");
	   }
	   else
	   {
		   //Negative test
		   DTS_CHECK_NE_MESSAGE("htmlElementAllowedHere", (void*)ret_val, 0, "htmlElementAllowedHere Failed");
	   }
		desret_int(ret_val);
		des_const_htmlElemDesc_ptr(n_parent, (const htmlElemDesc *)parent, 0);
		des_const_xmlChar_ptr(n_elt, (const xmlChar *)elt, 1);
		xmlResetLastError();
	}
	}
}

/**
	* @test			UTcHtmlElementStatusHereP01
	* @brief		htmlStatus htmlElementStatusHere(const htmlElemDesc* parent, const htmlElemDesc* elt)
	* @desc			Positive and Negative Test for htmlElementStatusHere
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Sathish Kumar (satish.k4@samsung.com)
	* @return		void
	* @see			none
	* @remarks     input1: [N/A, N/A] @n
	*               {const htmlElemDesc*(parent),const htmlElemDesc*(elt)} => {N/A | int(1)} @n
	* @b priority	Middle
	* @b etc		none
	*/
static void UTcHtmlElementStatusHereP01()
{
    htmlStatus ret_val;
	const htmlElemDesc * parent; /* HTML parent element */
    int n_parent;
	const htmlElemDesc * elt; /* HTML element */
    int n_elt;

    for (n_parent = 0;n_parent < gen_nb_const_htmlElemDesc_ptr;n_parent++) {
    for (n_elt = 0;n_elt < gen_nb_const_htmlElemDesc_ptr1;n_elt++) {
        parent = gen_const_htmlElemDesc_ptr_ElementAllowedHere(n_parent, 0);
        elt = gen_const_htmlElemDesc_ptr_ElementStatusHere(n_elt, 1);

        ret_val = htmlElementStatusHere((const htmlElemDesc *)parent, (const htmlElemDesc *)elt);
        if(ret_val == 1)
        {
        	//Negative test
		 DTS_CHECK_EQ_MESSAGE("htmlElementStatusHere", (void*)ret_val, 1, "htmlElementStatusHere Failed");
        }

        else
        {
        	//Positive test
   		 DTS_CHECK_NE_MESSAGE("htmlElementStatusHere", (void*)ret_val, 0, "htmlElementStatusHere Failed");
        }

        desret_htmlStatus(ret_val);
        des_const_htmlElemDesc_ptr(n_parent, (const htmlElemDesc *)parent, 0);
        des_const_htmlElemDesc_ptr(n_elt, (const htmlElemDesc *)elt, 1);
        xmlResetLastError();
    }
    }
}

/**
	* @test			UTcHtmlEncodeEntitiesP01
	* @brief		int htmlEncodeEntities(unsigned char* out, int *outlen,
		                                     const unsigned char* in, int *inlen, int quoteChar)
	* @desc			Positive and Negative Test for htmlEncodeEntities
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Sathish Kumar (satish.k4@samsung.com)
	* @return		void
	* @see			none
	* @remarks     input1: [N/A, N/A] @n
	*               {unsigned char*(out),int*(outlen),const unsigned char*(in),int*(inlen)
	*               int(quoteChar)} => {N/A | int(0)} @n
	* @b priority	Middle
	* @b etc		none
	*/
static void UTcHtmlEncodeEntitiesP01()
{
	int ret_val;
	unsigned char * out; /* a pointer to an array of bytes to store the result */
	int n_out;
	int * outlen; /* the length of @out */
	int n_outlen;
	unsigned char * in; /* a pointer to an array of UTF-8 chars */
	int n_in;
	int * inlen; /* the length of @in */
	int n_inlen;
	int quoteChar; /* the quote character to escape (' or ") or zero. */
	int n_quoteChar;

	for (n_out = 0;n_out < gen_nb_unsigned_char_ptr;n_out++) {
	for (n_outlen = 0;n_outlen < gen_nb_int_ptr;n_outlen++) {
	for (n_in = 0;n_in < gen_nb_const_unsigned_char_ptr;n_in++) {
	for (n_inlen = 0;n_inlen < gen_nb_int_ptr;n_inlen++) {
	for (n_quoteChar = 0;n_quoteChar < gen_nb_int;n_quoteChar++) {
		out = gen_unsigned_char_ptr(n_out, 0);
		outlen = gen_int_ptr(n_outlen, 1);
		in = gen_const_unsigned_char_ptr(n_in, 2);
		inlen = gen_int_ptr(n_inlen, 3);
		quoteChar = gen_int(n_quoteChar, 4);

			ret_val = htmlEncodeEntities(out, outlen, (const unsigned char *)in, inlen, quoteChar);
		   if(ret_val == 0)
		   {
			   //positive test
			    DTS_CHECK_EQ_MESSAGE("htmlEncodeEntities", (void*)ret_val, 0, "htmlEncodeEntities Failed");
		   }

		   if(ret_val == -1)
		   {
			  //Negative  test
			   DTS_CHECK_EQ_MESSAGE("htmlEncodeEntities", (void*)ret_val, -1, "htmlEncodeEntities Failed");
		   }

			desret_int(ret_val);
			call_tests++;
			des_unsigned_char_ptr(n_out, out, 0);
			des_int_ptr(n_outlen, outlen, 1);
			des_const_unsigned_char_ptr(n_in, (const unsigned char *)in, 2);
			des_int_ptr(n_inlen, inlen, 3);
			des_int(n_quoteChar, quoteChar, 4);
			xmlResetLastError();
	}
	}
	}
	}
	}

}

/**
	* @test			UTcHtmlHandleOmittedElemP01
	* @brief		int htmlHandleOmittedElem(int val)
	* @desc			Positive and Negative Test for htmlEncodeEntities
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Sathish Kumar (satish.k4@samsung.com)
	* @return		void
	* @see			none
	* @remarks     input1: [N/A, N/A] @n
	*               {int(val)} => {N/A | int(0)} @n
	* @b priority	Middle
	* @b etc		none
	*/
static void UTcHtmlHandleOmittedElemP01()
{
	    int ret_val;
	    int val; /* int 0 or 1 */
	    int n_val;

	    for (n_val = 0;n_val < gen_nb_int;n_val++) {
	        val = gen_int(n_val, 0);

	        ret_val = htmlHandleOmittedElem(val);
	        if(ret_val == 0)
	        {
	        	//Positive test
			 DTS_CHECK_EQ_MESSAGE("htmlHandleOmittedElem", (void*)ret_val, 0, "htmlHandleOmittedElem Failed");
	        }

	        if(ret_val == 1)
	        {
	        	//Negative test
			 DTS_CHECK_EQ_MESSAGE("htmlHandleOmittedElem", (void*)ret_val, 1, "htmlHandleOmittedElem Failed");
	        }
	        desret_int(ret_val);
	        call_tests++;
	        des_int(n_val, val, 0);
	        xmlResetLastError();
	    }
}


	/**
	* @test			UTcHtmlIsAutoClosedP01
	* @brief		int htmlIsAutoClosed(htmlDocPtr doc, htmlNodePtr elem)
	* @desc			Positive and Negative Test for htmlIsAutoClosed
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Sathish Kumar (satish.k4@samsung.com)
	* @return		void
	* @see			none
	* @remarks     input1: [N/A, N/A] @n
	*               {htmlDocPtr(doc),htmlNodePtr(elem)} => {N/A | int(0)} @n
	* @b priority	Middle
	* @b etc		none
	*/
static void UTcHtmlIsAutoClosedP01()
{
    int ret_val;
    htmlDocPtr doc; /* the HTML document */
    int n_doc;
    htmlNodePtr elem; /* the HTML element */
    int n_elem;

    for (n_doc = 0;n_doc < gen_nb_htmlDocPtr;n_doc++) {
    for (n_elem = 0;n_elem < gen_nb_htmlNodePtr1;n_elem++) {
        doc = gen_htmlDocPtr(n_doc, 0);
        elem = gen_htmlNodePtr_AutoCloseTag(n_elem, 2);
        /* @remarks     input1: [N/A, N/A] @n
        	*               {htmlDocPtr(doc),htmlNodePtr(elem)} => {N/A | int(1)} @n
        */
        ret_val = htmlIsAutoClosed(doc, elem);
        if(ret_val == 1)
        {
        	//Positive test
		DTS_CHECK_EQ_MESSAGE("htmlIsAutoClosed", (void*)ret_val, 1, "htmlIsAutoClosed Failed");
        }

        else
        {
        	//Negative test
		DTS_CHECK_NE_MESSAGE("htmlIsAutoClosed", (void*)ret_val, 0, "htmlIsAutoClosed Failed");
        }
        desret_int(ret_val);
        call_tests++;
        des_htmlDocPtr(n_doc, doc, 0);
        des_htmlNodePtr(n_elem, elem, 1);
        xmlResetLastError();
    }
    }
}

/**
	* @test			UTcHtmlIsScriptAttributeP01
	* @brief		int htmlIsScriptAttribute(const xmlChar *name)
	* @desc			Positive and Negative Test for htmlIsScriptAttribute
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Sathish Kumar (satish.k4@samsung.com)
	* @return		void
	* @see			none
	* @remarks     input1: [N/A, N/A] @n
	*               {const xmlChar*(name)} => {N/A | int(1)} @n
	* @b priority	Middle
	* @b etc		none
	*/
static void UTcHtmlIsScriptAttributeP01()
{
	    int ret_val;
	    xmlChar * name; /* an attribute name */
	    int n_name;

	    for (n_name = 0;n_name < gen_nb_const_xmlChar_ptr;n_name++) {
	        name = gen_const_xmlChar_ptr_ScriptAttribute(n_name, 0);
	       /* * @remarks     input1: [N/A, N/A] @n
	         *               {const xmlChar*(name)} => {N/A | int(1)} @n
	       */
	        ret_val = htmlIsScriptAttribute((const xmlChar *)name);

	        if(ret_val == 1)
	        {
	        	//Positive Test
			DTS_CHECK_EQ_MESSAGE("htmlIsScriptAttribute", (void*)ret_val, 1, "htmlIsScriptAttribute Failed");
	        }

	        else
	        {
	        	//Negative Test
			DTS_CHECK_NE_MESSAGE("htmlIsScriptAttribute", (void*)ret_val, 1, "htmlIsScriptAttribute Failed");
	        }

	        desret_int(ret_val);
	        des_const_xmlChar_ptr(n_name, (const xmlChar *)name, 0);
	        xmlResetLastError();
	    }
	 }

/**
	* @test			UTcHtmlNewParserCtxtP01
	* @brief		htmlParserCtxtPtr htmlNewParserCtxt(void)
	* @desc			Positive and Negative Test for htmlNewParserCtxt
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Sathish Kumar (satish.k4@samsung.com)
	* @return		void
	* @see			none
	* @remarks     input1: [N/A, N/A] @n
	*               {N/A} => {N/A | htmlParserCtxtPtr(1)} @n
	* @b priority	Middle
	* @b etc		none
	*/
static void UTcHtmlNewParserCtxtP01()
{
	htmlParserCtxtPtr ret_val = NULL;
	ret_val = NULL;
	//this function is static in library
	ret_val = htmlNewParserCtxt();
	//Positive test
	DTS_CHECK_NE_MESSAGE("htmlNewParserCtxt", (void*)ret_val, NULL, "htmlNewParserCtxt Failed");
	desret_htmlParserCtxtPtr(ret_val);
	xmlResetLastError();
}

/**
	* @test			UTcHtmlNodeStatusP01
	* @brief		htmlStatus htmlNodeStatus(const htmlNodePtr node, int legacy)
	* @desc			Positive and Negative Test for htmlNodeStatus
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Sathish Kumar (satish.k4@samsung.com)
	* @return		void
	* @see			none
	* @remarks     input1: [N/A, N/A] @n
	*               {const htmlNodePtr(node),int(legacy)} => {N/A | htmlStatus(1)} @n
	* @b priority	Middle
	* @b etc		none
	*/
static void UTcHtmlNodeStatusP01()
{
    htmlStatus ret_val;
    htmlNodePtr node; /* an htmlNodePtr in a tree */
    int n_node;
    int legacy; /* whether to allow deprecated elements (YES is faster here for Element nodes) */
    int n_legacy;

    for (n_node = 0;n_node < gen_nb_const_htmlNodePtr1;n_node++) {
    for (n_legacy = 0;n_legacy < gen_nb_int;n_legacy++) {
        node = gen_const_htmlNodePtr_NodeStatus(n_node, 0);
        legacy = gen_int(n_legacy, 1);

    	/* @remarks     input1: [N/A, N/A] @n
    	*               {const htmlNodePtr(node),int(legacy)} => {N/A | htmlStatus(1)} @n
        */
        ret_val = htmlNodeStatus((const htmlNodePtr)node, legacy);
        if(ret_val == 1)
        {
        	//Negative test
			DTS_CHECK_EQ_MESSAGE("htmlNodeStatus", (void*)ret_val, 1, "htmlNodeStatus Failed");
        }
        else
        {
        	//Positive Test
			DTS_CHECK_NE_MESSAGE("htmlNodeStatus", (void*)ret_val, 1, "htmlNodeStatus Failed");
        }
        desret_htmlStatus(ret_val);
        des_const_htmlNodePtr(n_node, (const htmlNodePtr)node, 0);
        des_int(n_legacy, legacy, 1);
        xmlResetLastError();
    }
    }
}

/**
	* @test			UTcHtmlParseCharRefP01
	* @brief		int htmlParseCharRef(htmlParserCtxtPtr ctxt)
	* @desc			Positive and Negative Test for htmlParseCharRef
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Sathish Kumar (satish.k4@samsung.com)
	* @return		void
	* @see			none
	* @remarks     input1: [N/A, N/A] @n
	*               {htmlParserCtxtPtr(ctxt)} => {N/A | int(1)} @n
	* @b priority	Middle
	* @b etc		none
	*/
static void UTcHtmlParseCharRefP01()
{
	int ret_val;
	htmlParserCtxtPtr ctxt; /* an HTML parser context */
	int n_ctxt;

	for (n_ctxt = 0;n_ctxt < gen_nb_htmlParserCtxtPtr;n_ctxt++) {
		ctxt = gen_htmlParserCtxtPtr(n_ctxt, 0);

		/* @remarks     input1: [N/A, N/A] @n
			*               {htmlParserCtxtPtr(ctxt)} => {N/A | int(1)} @n
		*/
		//Negative test is not required.

		ret_val = htmlParseCharRef(ctxt);
		DTS_CHECK_EQ_MESSAGE("htmlParseCharRef", (void*)ret_val, 0, "htmlParseCharRef Failed");

		desret_int(ret_val);
		des_htmlParserCtxtPtr(n_ctxt, ctxt, 0);
		xmlResetLastError();
	}
}

/**
	* @test			UTcHtmlEntityLookupP01
	* @brief		const htmlEntityDesc* htmlEntityLookup(const xmlChar *name)
	* @desc			Positive and Negative Test for htmlEntityLookup
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Sathish Kumar (satish.k4@samsung.com)
	* @return		void
	* @see			none
	* @remarks     input1: [N/A, N/A] @n
	*               {htmlParserCtxtPtr(ctxt)} => {N/A | int(1)} @n
	* @b priority	Middle
	* @b etc		none
	*/
static void UTcHtmlEntityLookupP01()
{
    const htmlEntityDesc * ret_val;
    xmlChar * name; /* the entity name */
    int n_name;

    for (n_name = 0;n_name < gen_nb_const_xmlChar_ptr;n_name++) {
        name = gen_const_xmlChar_ptr_EntityLookup(n_name, 0);

        ret_val = htmlEntityLookup((const xmlChar *)name);
        if(ret_val == NULL)
        {
        	//Negative test
			DTS_CHECK_EQ_MESSAGE("htmlEntityLookup", (void*)ret_val, NULL, "htmlEntityLookup Failed");
        }
        else
        {
           //Negative test
		   DTS_CHECK_NE_MESSAGE("htmlEntityLookup", (void*)ret_val, NULL, "htmlEntityLookup Failed");
        }
        desret_const_htmlEntityDesc_ptr(ret_val);
        des_const_xmlChar_ptr(n_name, (const xmlChar *)name, 0);
        xmlResetLastError();
    }
}

/**
	* @test			UTcHtmlParseChunkP01
	* @brief		int htmlParseChunk(htmlParserCtxtPtr ctxt, const char *chunk, int size,
              	  	  	  	  	  	  int terminate)
	* @desc			Positive and Negative Test for htmlParseChunk
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Sathish Kumar (satish.k4@samsung.com)
	* @return		void
	* @see			none
	* @remarks     input1: [N/A, N/A] @n
	*               {htmlParserCtxtPtr(ctxt),const char *(chunk),int(size),int (terminate)} => {N/A | int(0)} @n
	* @b priority	Middle
	* @b etc		none
	*/
static void UTcHtmlEntityValueLookupP01()
{
	const htmlEntityDesc * ret_val;
	unsigned int value; /* the entity's unicode value */
	int n_value;

	for (n_value = 0;n_value < gen_nb_unsigned_int1;n_value++) {
		 value = gen_unsigned_int_EntityValueLookup(n_value, 0);
		/* @remarks  input1: [N/A, N/A] @n
		*           {unsigned int(value)} => {N/A | const htmlEntityDesc(ret_val)} @n
		*/
		ret_val = htmlEntityValueLookup(value);
		if(ret_val == NULL)
		{
		   DTS_CHECK_EQ_MESSAGE("htmlEntityValueLookup", (void*)ret_val, NULL, "htmlEntityValueLookup Failed");
			//Negative test

		}

		else
		{
			//Positive test
			DTS_CHECK_NE_MESSAGE("htmlEntityValueLookup", (void*)ret_val, NULL, "htmlEntityValueLookup Failed");
		}
		desret_const_htmlEntityDesc_ptr(ret_val);
		call_tests++;
		des_unsigned_int(n_value, value, 0);
		xmlResetLastError();
	}
}

	/**
	* @test			UTcHtmlParseChunkP01
	* @brief		int htmlParseChunk(htmlParserCtxtPtr ctxt, const char *chunk, int size,
              	  	  	  	  	  	  int terminate)
	* @desc			Positive and Negative Test for htmlParseChunk
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Sathish Kumar (satish.k4@samsung.com)
	* @return		void
	* @see			none
	* @remarks     input1: [N/A, N/A] @n
	*               {htmlParserCtxtPtr(ctxt),const char *(chunk),int(size),int (terminate)} => {N/A | int(0)} @n
	* @b priority	Middle
	* @b etc		none
	*/
static void UTcHtmlParseChunkP01()
{
	int ret_val;
	htmlParserCtxtPtr ctxt; /* an HTML parser context */
	int n_ctxt;
	char * chunk; /* an char array */
	int n_chunk;
	int size; /* the size in byte of the chunk */
	int n_size;
	int terminate; /* last chunk indicator */
	int n_terminate;

	for (n_ctxt = 0;n_ctxt < gen_nb_htmlParserCtxtPtr;n_ctxt++) {
	for (n_chunk = 0;n_chunk < gen_nb_const_char_ptr;n_chunk++) {
	for (n_size = 0;n_size < gen_nb_int;n_size++) {
	for (n_terminate = 0;n_terminate < gen_nb_int;n_terminate++) {
		ctxt = gen_htmlParserCtxtPtr(n_ctxt, 0);
		chunk = gen_const_char_ptr(n_chunk, 1);
		size = gen_int(n_size, 2);
		terminate = gen_int(n_terminate, 3);
   /* * @remarks     input1: [N/A, N/A] @n
	  *        {htmlParserCtxtPtr(ctxt),const char *(chunk),int(size),int (terminate)} => {N/A | int(0)} @n
	*/
		ret_val = htmlParseChunk(ctxt, (const char *)chunk, size, terminate);
		if(ret_val == 0)
		{
			//Positive Test
			 DTS_CHECK_EQ_MESSAGE("htmlParseChunk", (void*)ret_val, 0, "htmlParseChunk Failed");
		}
		else
		{
			//Negative test
			 DTS_CHECK_NE_MESSAGE("htmlParseChunk", (void*)ret_val, 0, "htmlParseChunk Failed");
		}
		desret_int(ret_val);
		des_htmlParserCtxtPtr(n_ctxt, ctxt, 0);
		des_const_char_ptr(n_chunk, (const char *)chunk, 1);
		des_int(n_size, size, 2);
		des_int(n_terminate, terminate, 3);
		xmlResetLastError();
	}
	}
	}
	}
}

/**
	* @test			UTcHtmlParseDocP01
	* @brief		htmlDocPtr htmlParseDoc(xmlChar *cur, const char *encoding)
	* @desc			Positive and Negative Test for htmlParseDoc
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Sathish Kumar (satish.k4@samsung.com)
	* @return		void
	* @see			none
	* @remarks     input1: [N/A, N/A] @n
	*               {xmlChar*(cur),const char *(encoding))} => {N/A | htmlDocPtr(ret_val)} @n
	* @b priority	Middle
	* @b etc		none
	*/
static void UTcHtmlParseDocP01()
{
	htmlDocPtr ret_val;
	xmlChar * cur; /* a pointer to an array of xmlChar */
	int n_cur;
	char * encoding; /* a free form C string describing the HTML document encoding, or NULL */
	int n_encoding;

	for (n_cur = 0;n_cur < gen_nb_xmlChar_ptr;n_cur++) {
	for (n_encoding = 0;n_encoding < gen_nb_const_char_ptr;n_encoding++) {
		cur = gen_xmlChar_ptr_ParseDoc(n_cur, 0);
		encoding = gen_const_char_ptr(n_encoding, 1);
	   /* * @remarks  input1: [N/A, N/A] @n
		*             {xmlChar*(cur),const char *(encoding))} => {N/A | htmlDocPtr(ret_val)} @n
		*/
		ret_val = htmlParseDoc(cur, (const char *)encoding);

		if(ret_val != NULL)
		{
			//Positive test
			DTS_CHECK_NE_MESSAGE("htmlParseDoc", (void*)ret_val, NULL, "htmlParseDoc Failed");
		}
		else
		{
			//Negative test
			DTS_CHECK_EQ_MESSAGE("htmlParseDoc", (void*)ret_val, NULL, "htmlParseDoc Failed");
		}
		desret_htmlDocPtr(ret_val);
		des_xmlChar_ptr(n_cur, cur, 0);
		xmlResetLastError();
	}
	}
}

/**
	* @test			UTcHtmlParseDocumentP01
	* @brief		int htmlParseDocument(htmlParserCtxtPtr ctxt)
	* @desc			Positive and Negative Test for htmlParseDocument
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Sathish Kumar (satish.k4@samsung.com)
	* @return		void
	* @see			none
	* @remarks     input1: [N/A, N/A] @n
	*               {htmlParserCtxtPtr(ctxt))} => {N/A |int(ret_val)} @n
	* @b priority	Middle
	* @b etc		none
	*/
static void UTcHtmlParseDocumentP01()
{
	int ret_val;
	htmlParserCtxtPtr ctxt; /* an HTML parser context */
	int n_ctxt;

	for (n_ctxt = 0;n_ctxt < gen_nb_htmlParserCtxtPtr;n_ctxt++) {
		ctxt = gen_htmlParserCtxtPtr_ParseDocument(n_ctxt, 0);
	   /* * @remarks     input1: [N/A, N/A] @n
		*            {htmlParserCtxtPtr(ctxt)} => {N/A |N/A} @n
	   */
		ret_val = htmlParseDocument(ctxt);
	   if(ret_val == 0)
	   {
		   //Positive test
		   DTS_CHECK_EQ_MESSAGE("htmlParseDocument", (void*)ret_val, 0, "htmlParseDocument Failed");
	   }
	   else if(ret_val == 1)
	   {
		   //Negative test
		   DTS_CHECK_EQ_MESSAGE("htmlParseDocument", (void*)ret_val, 1, "htmlParseDocument Failed");
	   }

	   else
	   {
		   //Negative test
		   DTS_CHECK_EQ_MESSAGE("htmlParseDocument", (void*)ret_val, -1, "htmlParseDocument Failed");
	   }

		if (ctxt != NULL) {xmlFreeDoc(ctxt->myDoc); ctxt->myDoc = NULL;}
		des_htmlParserCtxtPtr(n_ctxt, ctxt, 0);
		xmlResetLastError();
		}
}

/**
	* @test			UTcHtmlParseElementP01
	* @brief		void htmlParseElement(htmlParserCtxtPtr ctxt)
	* @desc			Positive and Negative Test for htmlParseElement
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Sathish Kumar (satish.k4@samsung.com)
	* @return		void
	* @see			none
	* @remarks     input1: [N/A, N/A] @n
	*               {htmlParserCtxtPtr(ctxt)} => {N/A |N/A} @n
	* @b priority	Middle
	* @b etc		none
	*/
static void UTcHtmlParseElementP01()
{
	htmlParserCtxtPtr ctxt; /* an HTML parser context */
	int n_ctxt;

	for (n_ctxt = 0;n_ctxt < gen_nb_htmlParserCtxtPtr;n_ctxt++) {
		ctxt = gen_htmlParserCtxtPtr(n_ctxt, 0);

		/** @remarks     input1: [N/A, N/A] @n
	   *               {htmlParserCtxtPtr(ctxt))} => {N/A |int(ret_val)} @n
	 */
		htmlParseElement(ctxt);
		if(ctxt == NULL)
		{
			//Negative Test
			 DTS_CHECK_EQ_MESSAGE("htmlParseElement", (void*)ctxt, NULL, "htmlParseElement Failed");
		}
		else
		{
			//Positive Test
			 DTS_CHECK_NE_MESSAGE("htmlParseElement", (void*)ctxt, NULL, "htmlParseElement Failed");
		}

		des_htmlParserCtxtPtr(n_ctxt, ctxt, 0);
		xmlResetLastError();
	}
}

/**
	* @test			UTcHtmlParseEntityRefP01
	* @brief		const htmlEntityDesc *htmlParseEntityRef(htmlParserCtxtPtr ctxt, const xmlChar **str)
	* @desc			Positive and Negative Test for htmlParseEntityRef
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Sathish Kumar (satish.k4@samsung.com)
	* @return		void
	* @see			none
	* @remarks     input1: [N/A, N/A] @n
	*               {htmlParserCtxtPtr(ctxt),const xmlChar (**str) } => {N/A |const htmlEntityDesc(ret_val} @n
	* @b priority	Middle
	* @b etc		none
	*/
static void UTcHtmlParseEntityRefP01()
{
	const htmlEntityDesc * ret_val;
	htmlParserCtxtPtr ctxt; /* an HTML parser context */
	int n_ctxt;
	xmlChar ** str; /* location to store the entity name */
	int n_str;

	for (n_ctxt = 0;n_ctxt < gen_nb_htmlParserCtxtPtr;n_ctxt++) {
	for (n_str = 0;n_str < gen_nb_const_xmlChar_ptr_ptr;n_str++) {
		ctxt = gen_htmlParserCtxtPtr_1(n_ctxt, 0);
		str = gen_const_xmlChar_ptr_ptr(n_str, 1);

   /*  * @remarks     input1: [N/A, N/A] @n
	   *      {htmlParserCtxtPtr(ctxt),const xmlChar (**str) } => {N/A |const htmlEntityDesc(ret_val} @n
   */
		ret_val = htmlParseEntityRef(ctxt, (const xmlChar **)str);

		if(ret_val == NULL)
		{
			//Negative test
			DTS_CHECK_EQ_MESSAGE("htmlParseEntityRef", (void*)ret_val, NULL, "htmlParseEntityRef Failed");
		}
		else
		{
			//Positive test
			DTS_CHECK_NE_MESSAGE("htmlParseEntityRef", (void*)ret_val, NULL, "htmlParseEntityRef Failed");
		}

		desret_const_htmlEntityDesc_ptr(ret_val);
		call_tests++;
		des_htmlParserCtxtPtr(n_ctxt, ctxt, 0);
		des_const_xmlChar_ptr_ptr(n_str, (const xmlChar **)str, 1);
		xmlResetLastError();
	}
	}
}

	/**
	* @test			UTcHtmlParseFileP01
	* @brief		htmlDocPtr htmlParseFile(const char *filename, const char *encoding)
	* @desc			Positive and Negative Test for htmlParseFile
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Sathish Kumar (satish.k4@samsung.com)
	* @return		void
	* @see			none
	* @remarks     input1: [N/A, N/A] @n
	*               {const char *(filename),const char *(encoding) } => {N/A |htmlDocPtr(ret_val} @n
	* @b priority	Middle
	* @b etc		none
	*/
static void UTcHtmlParseFileP01()
{
	htmlDocPtr ret_val;
	const char * filename; /* the filename */
	int n_filename;
	char * encoding; /* a free form C string describing the HTML document encoding, or NULL */
	int n_encoding;

	for (n_filename = 0;n_filename < gen_nb_filepath;n_filename++) {
	for (n_encoding = 0;n_encoding < gen_nb_const_char_ptr;n_encoding++) {
		filename = gen_filepath(n_filename, 0);
		encoding = gen_const_char_ptr(n_encoding, 1);

	  /*  * @remarks     input1: [N/A, N/A] @n
		  *            {const char *(filename),const char *(encoding) } => {N/A |htmlDocPtr(ret_val} @n
	  */
		ret_val = htmlParseFile(filename, (const char *)encoding);
		if(ret_val == NULL)
		{
			//Negative test
			DTS_CHECK_EQ_MESSAGE("htmlParseFile", (void*)ret_val, NULL, "htmlParseFile Failed");
		}

		else
		{
			//Positive test
			DTS_CHECK_NE_MESSAGE("htmlParseFile", (void*)ret_val, NULL, "htmlParseFile Failed");
		}
		desret_htmlDocPtr(ret_val);
		des_filepath(n_filename, filename, 0);
		des_const_char_ptr(n_encoding, (const char *)encoding, 1);
		xmlResetLastError();
	}
	}
}

/**
	* @test		    UTcHtmlReadDocP01
	* @brief		htmlDocPtr htmlReadDoc(const xmlChar * cur, const char *URL, const char *encoding, int options)
	* @desc			Positive and Negative Test for htmlReadDoc
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Sathish Kumar (satish.k4@samsung.com)
	* @return		void
	* @see			none
	* @remarks     input1: [N/A, N/A] @n
	*               {const xmlChar*(cur),const char *(URL),const char *(encoding),int(options) } => {N/A |htmlDocPtr(ret_val} @n
	* @b priority	Middle
	* @b etc		none
	*/
static void UTcHtmlReadDocP01()
{
	htmlDocPtr ret_val;
	xmlChar * cur; /* a pointer to a zero terminated string */
	int n_cur;
	const char * URL; /* the base URL to use for the document */
	int n_URL;
	char * encoding; /* the document encoding, or NULL */
	int n_encoding;
	int options; /* a combination of htmlParserOption(s) */
	int n_options;

	for (n_cur = 0;n_cur < gen_nb_const_xmlChar_ptr;n_cur++) {
	for (n_URL = 0;n_URL < gen_nb_filepath;n_URL++) {
	for (n_encoding = 0;n_encoding < gen_nb_const_char_ptr;n_encoding++) {
	for (n_options = 0;n_options < gen_nb_int;n_options++) {
		cur = gen_const_xmlChar_ptr(n_cur, 0);
		URL = gen_filepath(n_URL, 1);
		encoding = gen_const_char_ptr(n_encoding, 2);
		options = gen_int(n_options, 3);
   /* @remarks     input1: [N/A, N/A] @n
	*               {const xmlChar*(cur),const char *(URL),const char *(encoding),int(options) } => {N/A |htmlDocPtr(ret_val} @n
  */
		ret_val = htmlReadDoc((const xmlChar *)cur, URL, (const char *)encoding, options);
	  if(ret_val == NULL)
	  {
		  //Negative test
		  DTS_CHECK_EQ_MESSAGE("htmlReadDoc", (void*)ret_val, NULL, "htmlReadDoc Failed");
	  }

	  else
	  {
		  //Positive test
		  DTS_CHECK_NE_MESSAGE("htmlReadDoc", (void*)ret_val, NULL, "htmlReadDoc Failed");
	  }
		des_const_xmlChar_ptr(n_cur, (const xmlChar *)cur, 0);
		des_filepath(n_URL, URL, 1);
		des_const_char_ptr(n_encoding, (const char *)encoding, 2);
		des_int(n_options, options, 3);
		xmlResetLastError();
	}
	}
	}
	}
}

	/**
	* @test		    UTcHtmlReadFileP01
	* @brief		htmlDocPtr htmlReadFile(const char *filename, const char *encoding, int options)
	* @desc			Positive and Negative Test for htmlReadFile
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Sathish Kumar (satish.k4@samsung.com)
	* @return		void
	* @see			none
	* @remarks     input1: [N/A, N/A] @n
	*               {const xmlChar*(filename),const char *(encoding),int(options) } => {N/A |htmlDocPtr(ret_val} @n
	* @b priority	Middle
	* @b etc		none
	*/
static void UTcHtmlReadFileP01()
{
    htmlDocPtr ret_val;
    const char * filename; /* a file or URL */
    int n_filename;
    char * encoding; /* the document encoding, or NULL */
    int n_encoding;
    int options; /* a combination of htmlParserOption(s) */
    int n_options;

    for (n_filename = 3;n_filename < gen_nb_filepath;n_filename++) {
    for (n_encoding = 0;n_encoding < gen_nb_const_char_ptr;n_encoding++) {
    for (n_options = 0;n_options < gen_nb_int;n_options++) {
        filename = gen_filepath(n_filename, 0);
        encoding = gen_const_char_ptr(n_encoding, 1);
        options = gen_int(n_options, 2);
        ret_val = htmlReadFile(filename, (const char *)encoding, options);

        if(ret_val != NULL)
        {
        	//Positive test
			DTS_CHECK_NE_MESSAGE("htmlReadFile",(void*) ret_val, NULL, "htmlReadFile Failed");
        }
        else
        {
        	//Negative test
			DTS_CHECK_EQ_MESSAGE("htmlReadFile", (void*)ret_val, NULL, "htmlReadFile Failed");
        }
        desret_htmlDocPtr(ret_val);
        des_filepath(n_filename, filename, 0);
        des_const_char_ptr(n_encoding, (const char *)encoding, 1);
        des_int(n_options, options, 2);
        xmlResetLastError();
    }
    }
    }
 }

	/**
	* @test		    UTcHtmlReadMemoryP01
	* @brief		htmlDocPtr htmlReadMemory(const char *buffer, int size, const char *URL, const char *encoding, int options)
	* @desc			Positive and Negative Test for htmlReadMemory
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Sathish Kumar (satish.k4@samsung.com)
	* @return		void
	* @see			none
	* @remarks     input1: [N/A, N/A] @n
	*               {const char*(buffer),int(size),const char*(URL),const char*(encoding),int(options)} => {N/A |htmlDocPtr(ret_val} @n
	* @b priority	Middle
	* @b etc		none
	*/
static void UTcHtmlReadMemoryP01()
{
	htmlDocPtr ret_val;
	char * buffer; /* a pointer to a char array */
	int n_buffer;
	int size; /* the size of the array */
	int n_size;
	const char * URL; /* the base URL to use for the document */
	int n_URL;
	char * encoding; /* the document encoding, or NULL */
	int n_encoding;
	int options; /* a combination of htmlParserOption(s) */
	int n_options;

	for (n_buffer = 0;n_buffer < gen_nb_const_char_ptr;n_buffer++) {
	for (n_size = 0;n_size < gen_nb_int;n_size++) {
	for (n_URL = 0;n_URL < gen_nb_filepath;n_URL++) {
	for (n_encoding = 0;n_encoding < gen_nb_const_char_ptr;n_encoding++) {
	for (n_options = 0;n_options < gen_nb_int;n_options++) {
		buffer = gen_const_char_ptr(n_buffer, 0);
		size = gen_int(n_size, 1);
		URL = gen_filepath(n_URL, 2);
		encoding = gen_const_char_ptr(n_encoding, 3);
		options = gen_int(n_options, 4);
	/*	* @remarks input1: [N/A, N/A] @n
		*           {const char*(buffer),int(size),const char*(URL),const char*(encoding),int(options)} => {N/A |htmlDocPtr(ret_val} @n
	 */
		ret_val = htmlReadMemory((const char *)buffer, size, URL, (const char *)encoding, options);
		if(ret_val == NULL)
		{
			//Negative test
			DTS_CHECK_EQ_MESSAGE("htmlReadMemory", (void*)ret_val, NULL, "htmlReadMemory Failed");
		}
		else
		{
			//Positive test
			DTS_CHECK_NE_MESSAGE("htmlReadMemory", (void*)ret_val, NULL, "htmlReadMemory Failed");
		}

		des_const_char_ptr(n_buffer, (const char *)buffer, 0);
		des_int(n_size, size, 1);
		des_filepath(n_URL, URL, 2);
		des_const_char_ptr(n_encoding, (const char *)encoding, 3);
		des_int(n_options, options, 4);
		xmlResetLastError();
	}
	}
	}
	}
	}
}

/**
	* @test		    UTcHtmlSAXParseDocP01
	* @brief		htmlDocPtr htmlSAXParseDoc(xmlChar *cur, const char *encoding, htmlSAXHandlerPtr sax, void *userData)
	* @desc			Positive and Negative Test for htmlSAXParseDoc
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Sathish Kumar (satish.k4@samsung.com)
	* @return		void
	* @see			none
	* @remarks     input1: [N/A, N/A] @n
	*               {xmlChar *(cur), const char *(encoding), htmlSAXHandlerPtr (sax), void *(userData)} => {N/A |htmlDocPtr(ret_val} @n
	* @b priority	Middle
	* @b etc		none
	*/
static void UTcHtmlSAXParseDocP01()
{
	htmlDocPtr ret_val;
	xmlChar * cur; /* a pointer to an array of xmlChar */
	int n_cur;
	char * encoding; /* a free form C string describing the HTML document encoding, or NULL */
	int n_encoding;
	htmlSAXHandlerPtr sax; /* the SAX handler block */
	int n_sax;
	void * userData; /* if using SAX, this pointer will be provided on callbacks. */
	int n_userData;

	for (n_cur = 0;n_cur < gen_nb_xmlChar_ptr;n_cur++) {
	for (n_encoding = 0;n_encoding < gen_nb_const_char_ptr;n_encoding++) {
	for (n_sax = 0;n_sax < gen_nb_htmlSAXHandlerPtr;n_sax++) {
	for (n_userData = 0;n_userData < gen_nb_userdata;n_userData++) {
		cur = gen_xmlChar_ptr(n_cur, 0);
		encoding = gen_const_char_ptr(n_encoding, 1);
		sax = gen_htmlSAXHandlerPtr(n_sax, 2);
		userData = gen_userdata(n_userData, 3);

		ret_val = htmlSAXParseDoc(cur, (const char *)encoding, sax, userData);

		if(n_cur == 0)
		{
			//Positive test
			DTS_CHECK_NE_MESSAGE("htmlSAXParseDoc", (void*)ret_val, NULL, "htmlSAXParseDoc Failed");
		}

		if(n_cur != 0)
		{
			//Negative Test
			DTS_CHECK_EQ_MESSAGE("htmlSAXParseDoc",(void*) ret_val, NULL, "htmlSAXParseDoc Failed");
		}
		des_xmlChar_ptr(n_cur, cur, 0);
		des_const_char_ptr(n_encoding, (const char *)encoding, 1);
		des_htmlSAXHandlerPtr(n_sax, sax, 2);
		des_userdata(n_userData, userData, 3);
		xmlResetLastError();
	}
	}
	}
	}
}

/**
	* @test		    UTcHtmlSAXParseFileP01
	* @brief		htmlDocPtr htmlSAXParseFile(const char *filename, const char *encoding, htmlSAXHandlerPtr sax,
                 void *userData)
	* @desc			Positive and Negative Test for htmlSAXParseFile
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Sathish Kumar (satish.k4@samsung.com)
	* @return		void
	* @see			none
	* @remarks     input1: [N/A, N/A] @n
	*               {const char *(filename), const char *(encoding), htmlSAXHandlerPtr (sax),
                      void *(userData)} => {N/A |htmlDocPtr(ret_val} @n
	* @b priority	Middle
	* @b etc		none
	*/
static void UTcHtmlSAXParseFileP01()
{
	htmlDocPtr ret_val;
	const char * filename; /* the filename */
	int n_filename;
	char * encoding; /* a free form C string describing the HTML document encoding, or NULL */
	int n_encoding;
	htmlSAXHandlerPtr sax; /* the SAX handler block */
	int n_sax;
	void * userData; /* if using SAX, this pointer will be provided on callbacks. */
	int n_userData;

	for (n_filename = 0;n_filename < gen_nb_filepath;n_filename++) {
	for (n_encoding = 0;n_encoding < gen_nb_const_char_ptr;n_encoding++) {
	for (n_sax = 0;n_sax < gen_nb_htmlSAXHandlerPtr;n_sax++) {
	for (n_userData = 0;n_userData < gen_nb_userdata;n_userData++) {
		filename = gen_filepath(n_filename, 0);
		encoding = gen_const_char_ptr(n_encoding, 1);
		sax = gen_htmlSAXHandlerPtr(n_sax, 2);
		userData = gen_userdata(n_userData, 3);

		/* @remarks  input1: [N/A, N/A] @n
		* {const char *(filename), const char *(encoding), htmlSAXHandlerPtr (sax),
					 void *(userData)} => {N/A |htmlDocPtr(ret_val} @n
		*/
	   ret_val = htmlSAXParseFile(filename, (const char *)encoding, sax, userData);

		if(ret_val != NULL)
		{
			//positive test
			DTS_CHECK_NE_MESSAGE("htmlSAXParseFile", (void*)ret_val, NULL, "htmlSAXParseFile Failed");
		}
		else
		{
			//Negative test
			DTS_CHECK_EQ_MESSAGE("htmlSAXParseFile", (void*)ret_val, NULL, "htmlSAXParseFile Failed");
		}

		des_filepath(n_filename, filename, 0);
		des_const_char_ptr(n_encoding, (const char *)encoding, 1);
		des_htmlSAXHandlerPtr(n_sax, sax, 2);
		des_userdata(n_userData, userData, 3);
		xmlResetLastError();
	}
	}
	}
	}
}

/**
	* @test		    UTcHtmlTagLookupP01
	* @brief		const htmlElemDesc *htmlTagLookup(const xmlChar *tag)
	* @desc			Positive and Negative Test for htmlTagLookup
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Sathish Kumar (satish.k4@samsung.com)
	* @return		void
	* @see			none
	* @remarks     input1: [N/A, N/A] @n
	*               {const xmlChar *(tag)} => {N/A |const htmlElemDesc *(ret_val} @n
	* @b priority	Middle
	* @b etc		none
	*/
static void UTcHtmlTagLookupP01()
{
	const htmlElemDesc * ret_val;
	const xmlChar * tag;
	int n_elemt;
	for(n_elemt = 0;n_elemt < 3; n_elemt++)
	{
		tag = gen_htmlTagLookup_ptr(n_elemt,1);

		/* @remarks     input1: [N/A, N/A] @n
		*               {const xmlChar *(tag)} => {N/A |const htmlElemDesc*(ret_val} @n
		*/
		ret_val = htmlTagLookup((const xmlChar *)tag);

		if(ret_val != NULL && n_elemt == 0)
		{
			//Positive test
			DTS_CHECK_NE_MESSAGE("htmlTagLookup", (void*)ret_val, NULL, "htmlTagLookup Failed");
		}
		if(n_elemt == 1 || n_elemt == 2)
		{
			//Negative test
			DTS_CHECK_EQ_MESSAGE("htmlTagLookup",(void*) ret_val, NULL, "htmlTagLookup Failed");
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
	{UTcHtmlAttrAllowedP01,1},
	{UTcHtmlAutoCloseTagP01,2},
	{UTcHtmlCreateMemoryParserCtxtP01,3},
	{UTcHtmlCreatePushParserCtxtP01,4},
	{UTcHtmlCtxtReadDocP01,5},
	{UTcHtmlCtxtReadFileP01,6},
	{UTcHtmlCtxtReadMemoryP01,7},
	{UTcHtmlCtxtResetP01,8},
	{UTcHtmlCtxtUseOptionsP01,9},
	{UTcHtmlElementAllowedHereP01,10},
	
	{UTcHtmlElementStatusHereP01,11},
	{UTcHtmlEncodeEntitiesP01,12},
	{UTcHtmlHandleOmittedElemP01,13},
	{UTcHtmlIsAutoClosedP01,14},
	{UTcHtmlIsScriptAttributeP01,15},
	{UTcHtmlNewParserCtxtP01,16},
	{UTcHtmlNodeStatusP01,17},
	{UTcHtmlParseCharRefP01,18},
	{UTcHtmlEntityLookupP01,19},
	{UTcHtmlEntityValueLookupP01,20},
	
	{UTcHtmlParseChunkP01,21},
	{UTcHtmlParseDocP01,22},
	{UTcHtmlParseDocumentP01,23},
	{UTcHtmlParseElementP01,24},
	{UTcHtmlParseEntityRefP01,25},
	{UTcHtmlParseFileP01,26},
	{UTcHtmlReadDocP01,27},
	{UTcHtmlReadFileP01,28},
	{UTcHtmlReadMemoryP01,29},
	{UTcHtmlSAXParseDocP01,30},
	
	{UTcHtmlSAXParseFileP01,31},
	{UTcHtmlTagLookupP01,32},
	{ NULL, 0 },
	
};


