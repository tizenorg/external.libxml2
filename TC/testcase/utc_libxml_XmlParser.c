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

#define gen_nb_xmlChar_ptr 2
#define gen_nb_const_xmlChar_ptr 5
#define gen_nb_xmlParserInputPtr 1
#define gen_nb_xmlNodePtr 3
#define gen_nb_int 4
#define gen_nb_parseroptions 5
#define gen_nb_long 5
#define gen_nb_xmlChar 4
#define gen_nb_unsigned_int 3
#define gen_nb_unsigned_long 4
#define gen_nb_xmlChar_ptr_ptr 1
#define gen_nb_const_char_ptr 4
#define gen_nb_xmlSAXHandlerPtr 2
#define gen_nb_userdata 3
#define gen_nb_fileoutput 6
#define gen_nb_xmlNodePtr_ptr 1
#define gen_nb_xmlDocPtr 4
#define gen_nb_xmlSAXHandlerPtr 2
#define gen_nb_filepath 8

static xmlChar chartab[1024];
static int inttab[1024];
static unsigned long longtab[1024];

static xmlDocPtr api_doc = NULL;
static xmlDtdPtr api_dtd = NULL;
static xmlNodePtr api_root = NULL;
static xmlAttrPtr api_attr = NULL;
static xmlNsPtr api_ns = NULL;
static int call_tests = 0;


static int
closeFunction (void * context)
{
	//Dummy Callbacks for registration
	return 0;
}

static int
readFunction (void * context, char * buffer, int len)
{
	//Dummy Callbacks for registration
	return 0;
}

static void ParseFSMstartElementNs( void * ctx,
                               const xmlChar * localname,
                               const xmlChar * prefix,
                               const xmlChar * URI,
                               int nb_namespaces,
                               const xmlChar ** namespaces,
                               int nb_attributes,
                               int nb_defaulted,
                               const xmlChar ** attributes )
   {
int indexNamespace =0;
 int indexAttribute = 0;
	#ifdef DISABLE_PRINTF
      printf( "startElementNs: name = '%s' prefix = '%s' uri = (%p)'%s'\n", localname, prefix, URI, URI );
	#endif
      for ( indexNamespace = 0; indexNamespace < nb_namespaces; ++indexNamespace )
      {
         const xmlChar *prefix = namespaces[indexNamespace*2];
         const xmlChar *nsURI = namespaces[indexNamespace*2+1];
	#ifdef DISABLE_PRINTF
         printf( "  namespace: name='%s' uri=(%p)'%s'\n", prefix, nsURI, nsURI );
	#endif
      }

      unsigned int index = 0;
      for ( indexAttribute = 0;
            indexAttribute < nb_attributes;
            ++indexAttribute, index += 5 )
      {
         const xmlChar *localname = attributes[index];
         const xmlChar *prefix = attributes[index+1];
         const xmlChar *nsURI = attributes[index+2];
         const xmlChar *valueBegin = attributes[index+3];
         const xmlChar *valueEnd = attributes[index+4];

      }
   }

   static void ParseFSMendElementNs( void * ctx,
                             const xmlChar * localname,
                             const xmlChar * prefix,
                             const xmlChar * URI )
   {
      printf( "endElementNs: name = '%s' prefix = '%s' uri = '%s'\n", localname, prefix, URI );
   }

   /** Display and format an error messages, callback.
      ctx:  an XML parser context
      msg:  the message to display/transmit
      ...:  extra parameters for the message display
      */
   static void ParseFSMerror( void * ctx,
                      const char * msg,
                      ... )
   {
      va_list args;
      va_start(args, msg);
      vprintf( msg, args );
      va_end(args);
   }

   /** Display and format a warning messages, callback.
      ctx:  an XML parser context
      msg:  the message to display/transmit
      ...:  extra parameters for the message display
      */
   static void ParseFSMwarning( void * ctx,
                        const char * msg,
                        ... )
   {
      va_list args;
      va_start(args, msg);
      vprintf( msg, args );
      va_end(args);
   }


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

static xmlChar *gen_const_xmlChar_ptr(int no, int nr ATTRIBUTE_UNUSED) {
    if (no == 0) return((xmlChar *) "foo");
    if (no == 1) return((xmlChar *) "<foo/>");
    if (no == 2) return((xmlChar *) "none");
    if (no == 3) return((xmlChar *) " 2ab ");
    return(NULL);
}
static void des_const_xmlChar_ptr(int no ATTRIBUTE_UNUSED, const xmlChar *val ATTRIBUTE_UNUSED, int nr ATTRIBUTE_UNUSED) {
}
static void desret_int(int val ATTRIBUTE_UNUSED) {
}
static void des_xmlParserCtxtPtr(int no ATTRIBUTE_UNUSED, xmlParserCtxtPtr val, int nr ATTRIBUTE_UNUSED) {
    if (val != NULL)
        xmlFreeParserCtxt(val);
}
static void des_xmlParserInputPtr(int no ATTRIBUTE_UNUSED, xmlParserInputPtr val ATTRIBUTE_UNUSED, int nr ATTRIBUTE_UNUSED) {
}
static xmlParserCtxtPtr gen_xmlParserCtxtPtr(int no, int nr ATTRIBUTE_UNUSED) {
    if (no == 0) return(xmlNewParserCtxt());
    if (no == 1) return(xmlCreateMemoryParserCtxt("<doc/>", 6));
    return(NULL);
}
static xmlParserInputPtr gen_xmlParserInputPtr(int no ATTRIBUTE_UNUSED, int nr ATTRIBUTE_UNUSED) {
    return(NULL);
}
static void desret_xmlParserInputPtr(xmlParserInputPtr val) {
	if(val != NULL)
		 xmlFreeInputStream(val);
}
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

static void desret_xmlNodePtr(xmlNodePtr val) {
    if ((val != NULL) && (val != api_root) && (val != (xmlNodePtr) api_doc)) {
	xmlUnlinkNode(val);
	xmlFreeNode(val);
    }
}
//static void des_xmlParserCtxtPtr(int no ATTRIBUTE_UNUSED, xmlParserCtxtPtr val, int nr ATTRIBUTE_UNUSED) {
//    if (val != NULL)
//        xmlFreeParserCtxt(val);
//}
static void desret_const_xmlChar_ptr(const xmlChar *val ATTRIBUTE_UNUSED) {
}
static void desret_xmlChar(xmlChar val ATTRIBUTE_UNUSED) {
}
static xmlChar *gen_xmlChar_ptr(int no, int nr ATTRIBUTE_UNUSED) {
    if (no == 0) return(&chartab[0]);
    return(NULL);
}
static xmlChar gen_xmlChar(int no, int nr ATTRIBUTE_UNUSED) {
    if (no == 0) return('a');
    if (no == 1) return(' ');
    if (no == 2) return(' ');
    return(0);
}

static int gen_int(int no, int nr ATTRIBUTE_UNUSED) {
    if (no == 0) return(0);
    if (no == 1) return(1);
    if (no == 2) return(-1);
    if (no == 3) return(122);
    return(-1);
}

static void desret_xmlChar_ptr(xmlChar *val) {
    if (val != NULL)
	xmlFree(val);
}
static void des_int(int no ATTRIBUTE_UNUSED, int val ATTRIBUTE_UNUSED, int nr ATTRIBUTE_UNUSED) {
}
static void des_xmlChar(int no ATTRIBUTE_UNUSED, xmlChar val ATTRIBUTE_UNUSED, int nr ATTRIBUTE_UNUSED) {
}
static xmlChar ** gen_xmlChar_ptr_ptr(int no ATTRIBUTE_UNUSED, int nr ATTRIBUTE_UNUSED) {
    return(NULL);
}
static void des_xmlChar_ptr_ptr(int no ATTRIBUTE_UNUSED, xmlChar ** val ATTRIBUTE_UNUSED, int nr ATTRIBUTE_UNUSED) {
}
static char *gen_const_char_ptr(int no, int nr ATTRIBUTE_UNUSED) {
    if (no == 0) return((char *) "foo");
    if (no == 1) return((char *) "<foo/>");
    if (no == 2) return((char *) "test/ent2");
    return(NULL);
}
static void des_const_char_ptr(int no ATTRIBUTE_UNUSED, const char *val ATTRIBUTE_UNUSED, int nr ATTRIBUTE_UNUSED) {
}
static xmlSAXHandlerPtr gen_xmlSAXHandlerPtr(int no, int nr ATTRIBUTE_UNUSED) {
#ifdef LIBXML_SAX1_ENABLED
    if (no == 0) return((xmlSAXHandlerPtr) &xmlDefaultSAXHandler);
#endif
    return(NULL);
}
static void *gen_userdata(int no, int nr ATTRIBUTE_UNUSED) {
    if (no == 0) return((void *) &call_tests);
    if (no == 1) return((void *) -1);
    return(NULL);
}
static void des_userdata(int no ATTRIBUTE_UNUSED, void *val ATTRIBUTE_UNUSED, int nr ATTRIBUTE_UNUSED) {
}
static void des_fileoutput(int no ATTRIBUTE_UNUSED, const char *val ATTRIBUTE_UNUSED, int nr ATTRIBUTE_UNUSED) {
}
static void des_xmlSAXHandlerPtr(int no ATTRIBUTE_UNUSED, xmlSAXHandlerPtr val ATTRIBUTE_UNUSED, int nr ATTRIBUTE_UNUSED) {
}
static void desret_xmlParserCtxtPtr(xmlParserCtxtPtr val) {
    xmlFreeParserCtxt(val);
}
static xmlNodePtr * gen_xmlNodePtr_ptr(int no ATTRIBUTE_UNUSED, int nr ATTRIBUTE_UNUSED) {
    return(NULL);
}
static void des_xmlNodePtr_ptr(int no ATTRIBUTE_UNUSED, xmlNodePtr * val ATTRIBUTE_UNUSED, int nr ATTRIBUTE_UNUSED) {
}
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
static const char *gen_filepath(int no, int nr ATTRIBUTE_UNUSED) {
    if (no == 0) return(MISSINGXML);
    if (no == 1) return("<foo/>");
    if (no == 2) return("test/ent2");
    if (no == 3) return(TESTRECxml19980210);
    if (no == 4) return(TESTXHTML1STRICTDTD);
    if (no == 5) return(REMOTE1GOOD);
    if (no == 6) return(REMOTE1BAD);
    return(NULL);
}
static void desret_xmlDocPtr(xmlDocPtr val) {
    if (val != NULL)
		xmlFreeDoc(val);
}
static void des_filepath(int no ATTRIBUTE_UNUSED, const char *val ATTRIBUTE_UNUSED, int nr ATTRIBUTE_UNUSED) {
}
static void des_xmlChar_ptr(int no ATTRIBUTE_UNUSED, xmlChar *val ATTRIBUTE_UNUSED, int nr ATTRIBUTE_UNUSED) {
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
static const char *pDocument = "<root>TestCase</root>";
static const int length = 21; // length of string pDocument

static void
UTcXmlCheckLanguageIDP01(void) {
    int ret_val;
    xmlChar * lang; /* pointer to the string value */
	lang = (xmlChar*)"en-GB";
  /**
   * @remarks   input 1: [N/A, N/A] @n
   *            {"en-GB"} => {N/A | 1} @n
   */
    ret_val = xmlCheckLanguageID((const xmlChar *) (lang));
	DTS_CHECK_EQ_MESSAGE("xmlCheckLanguageID", (void *)ret_val, (void *)1, "xmlCheckLanguageID Failed");
	lang = (xmlChar*)"en-US";

  /**
   * @remarks   input 2: [N/A, N/A] @n
   *            {"en-US"} => {N/A | 1} @n
   */ret_val = xmlCheckLanguageID((const xmlChar *) (lang));
	DTS_CHECK_EQ_MESSAGE("xmlCheckLanguageID", (void *)ret_val, (void *)1, "xmlCheckLanguageID Failed");
	lang = (xmlChar*)"foo";

  /**
   * @remarks   input 3: [N/A, N/A] @n
   *            {"foo"} => {N/A | 0} @n
   */
    ret_val = xmlCheckLanguageID((const xmlChar *) (lang));
	DTS_CHECK_EQ_MESSAGE("xmlCheckLanguageID", (void *)ret_val, (void *)1, "xmlCheckLanguageID Failed");
}

	/**    
	* @test			UTcInputPushP01
	* @brief		int inputPush(xmlParserCtxtPtr ctxt, xmlParserInputPtr value)
	* @desc			Positive Test for inputPush()
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Michel Anthony (michelj@samsung.com)
	* @return		void
	* @see			none
	* @remarks		input1: [N/A, N/A] @n
	*   			{xmlParserCtxtPtr(ctxt), xmlParserInputPtr(0)} => {N/A | int(0)} @n
					input2: [N/A, N/A] @n
	*   			{xmlParserCtxtPtr(ctxt), xmlParserInputPtr(value)} => {N/A | int(1)} @n
	* @b priority	Middle
	* @b etc		none
	*/
static void
UTcInputPushP01(void) {
    int ret_val;
    xmlParserCtxtPtr ctxt; /* an XML parser context */
    int n_ctxt;
    xmlParserInputPtr value; /* the parser input */
    int n_value;

    for (n_ctxt = 0;n_ctxt < 2;n_ctxt++) {
    for (n_value = 0;n_value < gen_nb_xmlParserInputPtr;n_value++) {
        ctxt = gen_xmlParserCtxtPtr(n_ctxt, 0);
        //value = xmlNewInputStream(ctxt);
		 if(n_ctxt == 0)
		{
		  /**
		   * @remarks   input 1: [N/A, N/A] @n
		   *            {ctxt, NULL} => {N/A | 0} @n
		   */
			ret_val = inputPush(ctxt, NULL);
			DTS_CHECK_EQ_MESSAGE("inputPush", (void *)ret_val, (void *)-1, "inputPush 1 Failed");
		}
		else
		{ /**
		   * @remarks   input 2: [N/A, N/A] @n
		   *            {ctxt, NULL} => {N/A | 1} @n
		   */
			value = xmlNewInputStream(ctxt);
			ret_val = inputPush(ctxt, value);
			DTS_CHECK_NE_MESSAGE("inputPush", (void *)ret_val, (void *)-1, "inputPush 2 Failed");
		}
         des_xmlParserCtxtPtr(n_ctxt, ctxt, 0);
         //desret_xmlParserInputPtr(value);
    }
    }
}
	/**    
	* @test			UTcInputPopP01
	* @brief		xmlParserInputPtr inputPop(xmlParserCtxtPtr ctxt)
	* @desc			Positive Test for inputPop()
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Michel Anthony (michelj@samsung.com)
	* @return		void
	* @see			none
	* @remarks		input1: [Create XML parser context, Free XML parser context] @n
	*   			{xmlParserCtxtPtr(ctxt)} => {N/A | NULL} @n
					input2: [N/A, N/A] @n
	*   			{xmlParserCtxtPtr(ctxt)} => {N/A | NULL} @n
	* @b priority	Middle
	* @b etc		none
	*/
static void
UTcInputPopP01(void) {

    xmlParserInputPtr ret_val;
    xmlParserCtxtPtr ctxt; /* an XML parser context */
    int n_ctxt;

    for (n_ctxt = 0;n_ctxt < 2;n_ctxt++) {
        ctxt = gen_xmlParserCtxtPtr(n_ctxt, 0);
        if(n_ctxt == 0)
		{/**
		   * @remarks   input 1: [N/A, N/A] @n
		   *            {ctxt} => {N/A | 1} @n
		   */
			ret_val = inputPop(ctxt);
			DTS_CHECK_EQ_MESSAGE("inputPop", (void *)ret_val, (void *)NULL, "inputPop Failed");			
		}
		else
		{/**
		   * @remarks   input 2: [N/A, N/A] @n
		   *            {ctxt} => {N/A | 1} @n
		   */
			ret_val = inputPop(ctxt);
			DTS_CHECK_NE_MESSAGE("inputPop", (void *)ret_val, (void *)NULL, "inputPop Failed");
		}
        desret_xmlParserInputPtr(ret_val);
        des_xmlParserCtxtPtr(n_ctxt, ctxt, 0);
    }

}
	/**    
	* @test			UTcNodePushP01
	* @brief		int nodePush(xmlParserCtxtPtr ctxt, xmlNodePtr value)
	* @desc			Positive Test for nodePush()
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Michel Anthony (michelj@samsung.com)
	* @return		void
	* @see			none
	* @remarks		input1: [Create an instance of xmlParserCtxtPtr (ctxt)@n Create an instance of xmlNodePtr (value) , Free xmlParserCtxtPtr and XML node pointers] @n
	*   			{xmlParserCtxtPtr(ctxt), xmlNodePtr(value)} => {N/A | int(1)} @n
	* @b priority	Middle
	* @b etc		none
	*/
static void
UTcNodePushP01(void) {

    int ret_val;
    xmlParserCtxtPtr ctxt; /* an XML parser context */
    int n_ctxt;
    xmlNodePtr value; /* the element node */
    int n_value;

    for (n_ctxt = 1;n_ctxt < 2;n_ctxt++) {
    for (n_value = 0;n_value < gen_nb_xmlNodePtr-1;n_value++) {
        ctxt = gen_xmlParserCtxtPtr(n_ctxt, 0);
        value = gen_xmlNodePtr(n_value, 1);
		ctxt->nodeNr = 1;
		/**
		 * @remarks   input 1: [Create an instance of xmlParserCtxtPtr (ctxt)@n
		 *						Create an instance of xmlNodePtr (value), N/A] @n
		 *            {ctxt, xmlNodePtr} => {N/A | 1} @n
		 */
        ret_val = nodePush(ctxt, value);
	DTS_CHECK_NE_MESSAGE("nodePush", (void *)ret_val, (void *)NULL, "nodePush Failed");			
        des_xmlParserCtxtPtr(n_ctxt, ctxt, 0);
        des_xmlNodePtr(n_value, value, 1);
    }
    }

}
	/**    
	* @test			UTcNodePopP01
	* @brief		xmlNodePtr nodePop(xmlParserCtxtPtr ctxt)
	* @desc			Positive Test for nodePop()
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Michel Anthony (michelj@samsung.com)
	* @return		void
	* @see			none
	* @remarks		input1: [[Create an instance of xmlParserCtxtPtr (ctxt), Free xmlParserCtxtPtr and XML node pointers] @n
	*   			{xmlParserCtxtPtr(ctxt)} => {N/A | NULL} @n
	* @b priority	Middle
	* @b etc		none
	*/
static void
UTcNodePopP01(void) {

    xmlNodePtr ret_val;
    xmlParserCtxtPtr ctxt; /* an XML parser context */
    int n_ctxt;
	int ret_val_push;


    for (n_ctxt = 1;n_ctxt < 2;n_ctxt++) {
        ctxt = gen_xmlParserCtxtPtr(n_ctxt, 0);
		ctxt->nodeNr = 1;
		ret_val_push = nodePush(ctxt, gen_xmlNodePtr(0, 1));
		DTS_CHECK_NE_MESSAGE("nodePush", (void *)ret_val_push, (void *)0, "nodePush Failed");
		/**
		 * @remarks   input 1: [Create an instance of xmlParserCtxtPtr (ctxt), N/A] @n
		 *            {ctxt} => {N/A | 1} @n
		 */
       ret_val = nodePop(ctxt);
	   DTS_CHECK_NE_MESSAGE("nodePush", (void *)ret_val, (void *)NULL, "nodePush Failed");
       des_xmlParserCtxtPtr(n_ctxt, ctxt, 0);
	   xmlFreeNode(ret_val);
    }
}
	/**    
	* @test			UTcNamePushP01
	* @brief		int namePush(xmlParserCtxtPtr ctxt, const xmlChar * value)
	* @desc			Positive Test for namePush()
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Michel Anthony (michelj@samsung.com)
	* @return		void
	* @see			none
	* @remarks		input1: [Create an instance of xmlParserCtxtPtr (ctxt). Create an instance of xmlChar (value), Free xmlParserCtxtPtr and const_xmlChar_ptr pointers] @n
	*   			{xmlParserCtxtPtr(ctxt), xmlChar(value)} => {N/A | int(-1)} @n
	* @b priority	Middle
	* @b etc		none
	*/
static void
UTcNamePushP01(void) {
    int ret_val;
    xmlParserCtxtPtr ctxt; /* an XML parser context */
    int n_ctxt;
    xmlChar * value; /* the element name */
    int n_value;

    for (n_ctxt = 0;n_ctxt < 2;n_ctxt++) {
    for (n_value = 0;n_value < gen_nb_const_xmlChar_ptr;n_value++) {
        ctxt = gen_xmlParserCtxtPtr(n_ctxt, 0);
        value = gen_const_xmlChar_ptr(n_value, 1);
		/**
		 * @remarks   input 1: [Create an instance of xmlParserCtxtPtr (ctxt)@n
		 *						Create an instance of xmlChar (value), N/A] @n
		 *            {ctxt, value} => {N/A |any integer value which is not equal to -1} @n
		 */
        ret_val = namePush(ctxt, (const xmlChar *)value);
        desret_int(ret_val);
	DTS_CHECK_NE_MESSAGE("namePush", (void *)ret_val, (void *)-1, "namePush Failed");
		des_xmlParserCtxtPtr(n_ctxt, ctxt, 0);
        des_const_xmlChar_ptr(n_value, (const xmlChar *)value, 1);
//		xmlFree(value);
        xmlResetLastError();
    }
    }
}
	/**    
	* @test			UTcNamePopP01
	* @brief		const xmlChar * namePop(xmlParserCtxtPtr ctxt)
	* @desc			Positive Test for namePop()
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Michel Anthony (michelj@samsung.com)
	* @return		void
	* @see			none
	* @remarks		input1: [Create an instance of xmlParserCtxtPtr (ctxt), Free const_xmlChar_ptr and xmlParserCtxtPtr pointers] @n
	*   			{xmlParserCtxtPtr(ctxt)} => {N/A | non-NULL xmlChar} @n
	* @b priority	Middle
	* @b etc		none
	*/
static void
UTcNamePopP01(void) {
    const xmlChar * ret_val;
    xmlParserCtxtPtr ctxt; /* an XML parser context */
    int n_ctxt;
	int ret_val_namepush;
	xmlChar * value; /* the element name */

    for (n_ctxt = 1;n_ctxt < 2;n_ctxt++) {
        ctxt = gen_xmlParserCtxtPtr(n_ctxt, 0);
		ctxt->nameNr = 2;

		value = gen_const_xmlChar_ptr(0, 1);
		ret_val_namepush = namePush(ctxt, (const xmlChar *)value);
		/**
		 * @remarks   input 1: [Create an instance of xmlParserCtxtPtr (ctxt), N/A] @n
		 *            {ctxt } => {N/A | non-NULL xmlChar} @n
		 */
        ret_val = namePop(ctxt);
	DTS_CHECK_NE_MESSAGE("namePop", (void *)ret_val, (void *)NULL, "namePop Failed");
        desret_const_xmlChar_ptr(ret_val);
        des_xmlParserCtxtPtr(n_ctxt, ctxt, 0);
    }
}
	/**    
	* @test			UtcXmlPopInputP01
	* @brief		xmlChar xmlPopInput(xmlParserCtxtPtr ctxt)
	* @desc			Positive Test for xmlPopInput()
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Michel Anthony (michelj@samsung.com)
	* @return		void
	* @see			none
	* @remarks		input1: [Create an instance of xmlParserCtxtPtr (ctxt), Free xmlParserCtxtPtr pointer] @n
	*   			{xmlParserCtxtPtr(ctxt)} => {N/A | xmlChar(between 0 and 255)} @n
	* @b priority	Middle
	* @b etc		none
	*/
static void
UtcXmlPopInputP01(void) {        //crashing

    xmlChar ret_val;
    xmlParserCtxtPtr ctxt; /* an XML parser context */
    int n_ctxt;

    for (n_ctxt = 1;n_ctxt < 2;n_ctxt++) {
        ctxt = gen_xmlParserCtxtPtr(n_ctxt, 0);
		/**
		 * @remarks   input 1: [Create an instance of xmlParserCtxtPtr (ctxt), N/A] @n
		 *            {ctxt } => {N/A | between 0 and 255} @n
		 */
        ret_val = xmlPopInput(ctxt);
	DTS_CHECK_EQ_MESSAGE("xmlPopInput", (void *)(ret_val>=0 && ret_val<= 255), (void *)1, "xmlPopInput Failed");
        desret_xmlChar(ret_val);
        des_xmlParserCtxtPtr(n_ctxt, ctxt, 0);
    }
}
	/**    
	* @test			UtcXmlPushInputP01
	* @brief		void xmlPushInput(xmlParserCtxtPtr ctxt, xmlParserInputPtr input)
	* @desc			Positive Test for xmlPushInput()
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Michel Anthony (michelj@samsung.com)
	* @return		void
	* @see			none
	* @remarks		input1: [Create an instance of xmlParserCtxtPtr (ctxt). Create an instance of xmlParserInputPtr (input), Free xmlParserCtxtPtr pointer] @n
	*   			{xmlParserCtxtPtr(ctxt), xmlParserInputPtr(input)} => {N/A | xmlChar(between 0 and 255)} @n
	* @b priority	Middle
	* @b etc		none
	*/
static void
UtcXmlPushInputP01(void) {

    xmlChar ret_val;
    xmlParserCtxtPtr ctxt; /* an XML parser context */
    int n_ctxt;
    xmlParserInputPtr input; /* an XML parser input fragment (entity, XML fragment ...). */
    int n_input;

    for (n_ctxt = 1;n_ctxt < 2;n_ctxt++) {
    for (n_input = 0;n_input < gen_nb_xmlParserInputPtr;n_input++) {
        ctxt = gen_xmlParserCtxtPtr(n_ctxt, 0);
        input = gen_xmlParserInputPtr(n_input, 1);
		/**
		 * @remarks   input 1: [Create an instance of xmlParserCtxtPtr (ctxt)@n
		 *						Create an instance of xmlParserInputPtr (input), N/A] @n
		 *            {ctxt, input } => {N/A | between 0 and 255} @n
		 */
        xmlPushInput(ctxt, input);
		ret_val = xmlPopInput(ctxt);
	DTS_CHECK_EQ_MESSAGE("xmlPopInput", (void *)(ret_val>=0 && ret_val<= 255), (void *)1, "xmlPopInput Failed");
		
        des_xmlParserCtxtPtr(n_ctxt, ctxt, 0);
        des_xmlParserInputPtr(n_input, input, 1);
    }
    }
}
	/**    
	* @test			UtcXmlStringLenDecodeEntitiesP01
	* @brief		xmlChar * xmlStringLenDecodeEntities(xmlParserCtxtPtr ctxt, const xmlChar *str, int len, int what, xmlChar end, xmlChar  end2, xmlChar end3)
	* @desc			Positive Test for xmlStringLenDecodeEntities()
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Michel Anthony (michelj@samsung.com)
	* @return		void
	* @see			none
	* @remarks		input1: [Create an instance of xmlParserCtxtPtr (ctxt), Free xmlParserCtxtPtr ponter] @n
	*   			{xmlParserCtxtPtr(ctxt), xmlChar(xmlChar), int(len), int(what), xmlChar(end), xmlChar(end2), xmlChar(end3)} => {N/A | xmlChar(NULL)} @n
					input2: [Create an instance of xmlParserCtxtPtr (ctxt), N/A] @n
	*   			{xmlParserCtxtPtr(ctxt), xmlChar(xmlChar), int(len), int(what), xmlChar(end), xmlChar(end2), xmlChar(end3)} => {N/A | non-NULL XmlChar} @n
	* @b priority	Middle
	* @b etc		none
	*/
static void
UtcXmlStringLenDecodeEntitiesP01(void) {
    int test_ret = 0;

    xmlChar * ret_val;
    xmlParserCtxtPtr ctxt; /* the parser context */
    int n_ctxt = 0;
    xmlChar * str; /* the input string */
    int n_str = 0;
    int len; /* the string length */
    int n_len = 0;
    int what; /* combination of XML_SUBSTITUTE_REF and XML_SUBSTITUTE_PEREF */
    int n_what = 0;
    xmlChar end; /* an end marker xmlChar, 0 if none */
    int n_end = 0;
    xmlChar end2; /* an end marker xmlChar, 0 if none */
    int n_end2 = 0;
    xmlChar end3; /* an end marker xmlChar, 0 if none */
    int n_end3 = 0;

    //for (n_ctxt = 0;n_ctxt < 2;n_ctxt++) {
    //for (n_str = 0;n_str < gen_nb_const_xmlChar_ptr-1;n_str++) {
    //for (n_len = 0;n_len < gen_nb_int-1;n_len++) {
    //for (n_what = 0;n_what < gen_nb_int-1;n_what++) {
    //for (n_end = 0;n_end < gen_nb_xmlChar-1;n_end++) {
    //for (n_end2 = 0;n_end2 < gen_nb_xmlChar-1;n_end2++) {
    //for (n_end3 = 0;n_end3 < gen_nb_xmlChar-1;n_end3++) {
        ctxt = gen_xmlParserCtxtPtr(n_ctxt, 0);
        str = gen_const_xmlChar_ptr(n_str, 1);
        len = gen_int(n_len, 2);
        what = gen_int(n_what, 3);
        end = gen_xmlChar(n_end, 4);
        end2 = gen_xmlChar(n_end2, 5);
        end3 = gen_xmlChar(n_end3, 6);
		//if(n_len == 2) {
		/**
		 * @remarks   input 1: [Create an instance of xmlParserCtxtPtr (ctxt) , N/A] @n
		 *            {ctxt, ("foo","<foo/>","none", " 2ab "), -1, (0, 1, -1, 122), ('a',' ',''), ('a',' ',''), ('a',' ','')  } => {N/A | non-NULL XmlChar*} @n
		 */
        //ret_val = xmlStringLenDecodeEntities(ctxt, (const xmlChar *)str, len, what, end, end2, end3);
        //MT_CHECK_MESSAGE2((ret_val == NULL), "Invalid ret_val " );
		//}else	{
		/**
		 * @remarks   input 2: [N/A , N/A] @n
		 *            {ctxt, ("foo","<foo/>","none", " 2ab "), (0, 1,122), (0, 1, -1, 122), ('a',' ',''), ('a',' ',''), ('a',' ','')  } => {N/A | non-NULL XmlChar*} @n
		 */
        ret_val = xmlStringLenDecodeEntities(ctxt, (const xmlChar *)str, len, what, end, end2, end3);
	DTS_CHECK_NE_MESSAGE("xmlStringLenDecodeEntities", (void *)ret_val, (void *)NULL, "xmlStringLenDecodeEntities Failed");
		
		//}
		desret_xmlChar_ptr(ret_val);
        des_xmlParserCtxtPtr(n_ctxt, ctxt, 0);
        des_const_xmlChar_ptr(n_str, (const xmlChar *)str, 1);
        des_int(n_len, len, 2);
        des_int(n_what, what, 3);
        des_xmlChar(n_end, end, 4);
        des_xmlChar(n_end2, end2, 5);
        des_xmlChar(n_end3, end3, 6);

    //}
    //}
    //}
    //}
    //}
    //}
    //}
}
	/**    
	* @test			UtcXmlStringDecodeEntitiesP01
	* @brief		xmlChar * xmlStringDecodeEntities(xmlParserCtxtPtr ctxt, const xmlChar *str, int what, xmlChar end, xmlChar  end2, xmlChar end3)
	* @desc			Positive Test for xmlStringDecodeEntities()
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Michel Anthony (michelj@samsung.com)
	* @return		void
	* @see			none
	* @remarks		input1: [Create an instance of xmlParserCtxtPtr (ctxt), Free xmlParserCtxtPtr pointer] @n
	*   			{xmlParserCtxtPtr(ctxt), xmlChar(xmlChar), int(what), xmlChar(end), xmlChar(end2), xmlChar(end3)} => {N/A | non-NULL XmlChar} @n
	* @b priority	Middle
	* @b etc		none
	*/
static void
UtcXmlStringDecodeEntitiesP01(void) {

    xmlChar * ret_val;
    xmlParserCtxtPtr ctxt; /* the parser context */
    int n_ctxt;
    xmlChar * str; /* the input string */
    int n_str;
    int what; /* combination of XML_SUBSTITUTE_REF and XML_SUBSTITUTE_PEREF */
    int n_what;
    xmlChar end; /* an end marker xmlChar, 0 if none */
    int n_end;
    xmlChar end2; /* an end marker xmlChar, 0 if none */
    int n_end2;
    xmlChar end3; /* an end marker xmlChar, 0 if none */
    int n_end3;

    for (n_ctxt = 1;n_ctxt < 2;n_ctxt++) {
    for (n_str = 0;n_str < gen_nb_const_xmlChar_ptr-2;n_str++) {
    for (n_what = 0;n_what < gen_nb_int-1;n_what++) {
    for (n_end = 0;n_end < gen_nb_xmlChar-1;n_end++) {
    for (n_end2 = 0;n_end2 < gen_nb_xmlChar-1;n_end2++) {
    for (n_end3 = 0;n_end3 < gen_nb_xmlChar-1;n_end3++) {
        ctxt = gen_xmlParserCtxtPtr(n_ctxt, 0);
        str = gen_const_xmlChar_ptr(n_str, 1);
        what = gen_int(n_what, 2);
        end = gen_xmlChar(n_end, 3);
        end2 = gen_xmlChar(n_end2, 4);
        end3 = gen_xmlChar(n_end3, 5);
		/**
		 * @remarks   input 1: [Create an instance of xmlParserCtxtPtr (ctxt) , N/A] @n
		 *            {ctxt, ("foo","<foo/>","none", " 2ab "),  (0, 1, -1, 122), ('a',' ',''), ('a',' ',''), ('a',' ','')  } => {N/A | non-NULL XmlChar*} @n
		 */
        ret_val = xmlStringDecodeEntities(ctxt, (const xmlChar *)str, what, end, end2, end3);
	DTS_CHECK_NE_MESSAGE("xmlStringDecodeEntities", (void *)ret_val, (void *)NULL, "xmlStringDecodeEntities Failed");
		
        desret_xmlChar_ptr(ret_val);
        des_xmlParserCtxtPtr(n_ctxt, ctxt, 0);
        des_const_xmlChar_ptr(n_str, (const xmlChar *)str, 1);
        des_int(n_what, what, 2);
        des_xmlChar(n_end, end, 3);
        des_xmlChar(n_end2, end2, 4);
        des_xmlChar(n_end3, end3, 5);
    }
    }
    }
    }
    }
    }

}
	/**    
	* @test			UtcXmlSplitQNameP01
	* @brief		xmlChar * xmlSplitQName(xmlParserCtxtPtr ctxt, const xmlChar *name, xmlChar **prefix)
	* @desc			Positive Test for xmlSplitQName()
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Michel Anthony (michelj@samsung.com)
	* @return		void
	* @see			none
	* @remarks		input1: [Create an instance of xmlParserCtxtPtr (ctxt), Free xmlParserCtxtPtr pointer] @n
	*   			{xmlParserCtxtPtr(ctxt), xmlChar(name), xmlChar(prefix)} => {N/A | non-NULL XmlChar} @n
	* @b priority	Middle
	* @b etc		none
	*/
static void
UtcXmlSplitQNameP01(void) {

    xmlChar * ret_val;
    xmlParserCtxtPtr ctxt; /* an XML parser context */
    int n_ctxt;
    xmlChar * name; /* an XML parser context */
    int n_name;
    xmlChar ** prefix; /* a xmlChar ** */
	xmlChar *name1 = (xmlChar*)"name";
	prefix = &name1;
    int n_prefix;

    for (n_ctxt = 1;n_ctxt < 2;n_ctxt++) {
    for (n_name = 0;n_name < gen_nb_const_xmlChar_ptr-2;n_name++) {
    for (n_prefix = 0;n_prefix < gen_nb_xmlChar_ptr_ptr;n_prefix++) {
        ctxt = gen_xmlParserCtxtPtr(n_ctxt, 0);
        name = gen_const_xmlChar_ptr(n_name, 1);
        //prefix = gen_xmlChar_ptr_ptr(n_prefix, 2);
		/**
		 * @remarks   input 1: [Create an instance of xmlParserCtxtPtr (ctxt), N/A] @n
		 *            {ctxt, name, prefix} => {N/A |  non-NULL XmlChar*} @n
		 */
        ret_val = xmlSplitQName(ctxt, (const xmlChar *)name, prefix);
	DTS_CHECK_NE_MESSAGE("xmlSplitQName", (void *)ret_val, (void *)NULL, "xmlSplitQName Failed");
        desret_xmlChar_ptr(ret_val);
        des_xmlParserCtxtPtr(n_ctxt, ctxt, 0);
        des_const_xmlChar_ptr(n_name, (const xmlChar *)name, 1);
        des_xmlChar_ptr_ptr(n_prefix, prefix, 2);
    }
    }
    }
}
	/**    
	* @test			UtcXmlParseDocumentP01
	* @brief		int xmlParseDocument(xmlParserCtxtPtr ctxt)
	* @desc			Positive Test for xmlParseDocument()
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Michel Anthony (michelj@samsung.com)
	* @return		void
	* @see			none
	* @remarks		input1: [Create an instance of xmlParserCtxtPtr (ctxt), Free xmlParserCtxtPtr pointer] @n
	*   			{xmlParserCtxtPtr(ctxt)} => {N/A | int(0)} @n
	* @b priority	Middle
	* @b etc		none
	*/
static void
UtcXmlParseDocumentP01(void) {

    int ret_val;
    xmlParserCtxtPtr ctxt; /* an XML parser context */
    int n_ctxt;

    for (n_ctxt = 1;n_ctxt < 2;n_ctxt++) {
        ctxt = gen_xmlParserCtxtPtr(n_ctxt, 0);
		/**
		 * @remarks   input 1: [Create an instance of xmlParserCtxtPtr (ctxt), N/A] @n
		 *            {ctxt } => {N/A |  0} @n
		 */
        ret_val = xmlParseDocument(ctxt);
		DTS_CHECK_EQ_MESSAGE("xmlParseDocument", (void *)ret_val, (void *)0, "xmlParseDocument Failed");
        if (ctxt != NULL) {xmlFreeDoc(ctxt->myDoc); ctxt->myDoc = NULL;}
        desret_int(ret_val);
        des_xmlParserCtxtPtr(n_ctxt, ctxt, 0);
    }
}
	/**    
	* @test			UtcXmlParseExtParsedEntP01
	* @brief		int xmlParseExtParsedEnt(xmlParserCtxtPtr ctxt)
	* @desc			Positive Test for xmlParseExtParsedEnt()
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Michel Anthony (michelj@samsung.com)
	* @return		void
	* @see			none
	* @remarks		input1: [Create an instance of xmlParserCtxtPtr (ctxt), Free xmlParserCtxtPtr pointer] @n
	*   			{xmlParserCtxtPtr(ctxt)} => {N/A | int(0)} @n
	* @b priority	Middle
	* @b etc		none
	*/
static void
UtcXmlParseExtParsedEntP01(void) {

    int ret_val;
    xmlParserCtxtPtr ctxt; /* an XML parser context */
    int n_ctxt;

    for (n_ctxt = 1;n_ctxt < 2;n_ctxt++) {
        ctxt = gen_xmlParserCtxtPtr(n_ctxt, 0);
		/**
		 * @remarks   input 1: [Create an instance of xmlParserCtxtPtr (ctxt), N/A] @n
		 *            {ctxt } => {N/A |  0} @n
		 */
        ret_val = xmlParseExtParsedEnt(ctxt);
	DTS_CHECK_EQ_MESSAGE("xmlParseExtParsedEnt", (void *)ret_val, (void *)0, "xmlParseExtParsedEnt Failed");
        if (ctxt != NULL) {xmlFreeDoc(ctxt->myDoc); ctxt->myDoc = NULL;}
        desret_int(ret_val);
        des_xmlParserCtxtPtr(n_ctxt, ctxt, 0);
      }
}
	/**    
	* @test			UtcXmlParseChunkP01
	* @brief		int xmlParseChunk(xmlParserCtxtPtr ctxt, const char *chunk, int size, int terminate)
	* @desc			Positive Test for xmlParseChunk()
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Michel Anthony (michelj@samsung.com)
	* @return		void
	* @see			none
	* @remarks		input1: [Create an instance of xmlParserCtxtPtr (ctxt), Free xmlParserCtxtPtr pointer] @n
	*   			{xmlParserCtxtPtr(), char(chunk), int(size), int(terminate)} => {N/A | int(0)} @n
	* @b priority	Middle
	* @b etc		none
	*/
static void
UtcXmlParseChunkP01(void) {

#if defined(LIBXML_PUSH_ENABLED)
    int ret_val;
    xmlParserCtxtPtr ctxt; /* an XML parser context */
    int n_ctxt;
    char * chunk; /* an char array */
    int n_chunk;
    int size; /* the size in byte of the chunk */
    int n_size;
    int terminate; /* last chunk indicator */
    int n_terminate;

    for (n_ctxt = 1;n_ctxt < 2;n_ctxt++) {
    for (n_chunk = 0;n_chunk < gen_nb_const_char_ptr-2;n_chunk++) {
    for (n_size = 0;n_size < gen_nb_int-1;n_size++) {
    for (n_terminate = 0;n_terminate < n_size-1;n_terminate++) {
        ctxt = gen_xmlParserCtxtPtr(n_ctxt, 0);
		DTS_CHECK_NE_MESSAGE("xmlParseChunk", (void *)ctxt, (void *)NULL, "gen_xmlParserCtxtPtr Failed");
        chunk = gen_const_char_ptr(n_chunk, 1);
		DTS_CHECK_NE_MESSAGE("xmlParseChunk", (void *)chunk, (void *)NULL, "gen_const_char_ptr Failed");
        size = gen_int(n_size, 2);
        terminate = gen_int(n_terminate, 3);
		/**
		 * @remarks   input 1: [Create an instance of xmlParserCtxtPtr (ctxt), N/A] @n
		 *            {ctxt, ("foo", "<foo/>", "test/ent2"),(0, 1, -1, 122),(0, 1, -1, 122) } => {N/A |  0} @n
		 */
        ret_val = xmlParseChunk(ctxt, (const char *)chunk, size, terminate);
		DTS_CHECK_EQ_MESSAGE("xmlParseChunk", (void *)ret_val, (void *)0, "xmlParseChunk Failed");
        if (ctxt != NULL) {xmlFreeDoc(ctxt->myDoc); ctxt->myDoc = NULL;}
        desret_int(ret_val);
        des_xmlParserCtxtPtr(n_ctxt, ctxt, 0);
        des_const_char_ptr(n_chunk, (const char *)chunk, 1);
        des_int(n_size, size, 2);
        des_int(n_terminate, terminate, 3);
    }
    }
    }
    }
#endif
}
	/**    
	* @test			UtcXmlStopParserP01
	* @brief		void xmlStopParser(xmlParserCtxtPtr ctxt)
	* @desc			Positive Test for xmlStopParser()
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Michel Anthony (michelj@samsung.com)
	* @return		void
	* @see			none
	* @remarks		input1: [Create an instance of xmlParserCtxtPtr (ctxt), Free xmlParserCtxtPtr pointer] @n
	*   			{xmlParserCtxtPtr(ctxt)} => {void} @n
	* @b priority	Middle
	* @b etc		none
	*/
static void
UtcXmlStopParserP01(void) {

#ifdef LIBXML_PUSH_ENABLED
    xmlParserCtxtPtr ctxt; /* an XML parser context */
    int n_ctxt;

    for (n_ctxt = 0;n_ctxt < 2;n_ctxt++) {
        ctxt = gen_xmlParserCtxtPtr(n_ctxt, 0);
		/**
		 * @remarks   input 1: [Create an instance of xmlParserCtxtPtr (ctxt), N/A] @n
		 *            {ctxt} => {N/A |void} @n
		 */
        xmlStopParser(ctxt);
		DTS_CHECK_NE_MESSAGE("xmlStopParser", (void *)ctxt, (void *)NULL, "xmlStopParser Failed");
        des_xmlParserCtxtPtr(n_ctxt, ctxt, 0);
    }
#endif

}
	/**    
	* @test			UtcXmlCreatePushParserCtxtP01
	* @brief		xmlParserCtxtPtr xmlCreatePushParserCtxt(xmlSAXHandlerPtr sax, void *user_data, const char *chunk, int size, const char *filename)
	* @desc			Positive Test for xmlCreatePushParserCtxt()
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Michel Anthony (michelj@samsung.com)
	* @return		void
	* @see			none
	* @remarks		input1: [Create an instance of xmlSAXHandlerPtr (sax), Free xmlSAXHandlerPtr pointer] @n
	*   			{xmlSAXHandlerPtr(sax), user_data(user_data), char((const char *)chunk), int(size), char(LIBXML2TESTXML)} => {N/A | non-NULL xmlParserCtxtPtr} @n
	* @b priority	Middle
	* @b etc		none
	*/
static void
UtcXmlCreatePushParserCtxtP01(void) {

#if defined(LIBXML_PUSH_ENABLED)
    xmlParserCtxtPtr ret_val;
    xmlSAXHandlerPtr sax; /* a SAX handler */
    int n_sax;
    void * user_data; /* The user data returned on SAX callbacks */
    int n_user_data;
    char * chunk; /* a pointer to an array of chars */
    int n_chunk;
    int size; /* number of chars in the array */
    int n_size;
    const char * filename; /* an optional file name or URI */
    int n_filename;

    for (n_sax = 0;n_sax < gen_nb_xmlSAXHandlerPtr-1;n_sax++) {
    for (n_user_data = 0;n_user_data < gen_nb_userdata-1;n_user_data++) {
    for (n_chunk = 0;n_chunk < gen_nb_const_char_ptr-1;n_chunk++) {
    for (n_size = 0;n_size < gen_nb_int-1;n_size++) {
    for (n_filename = 0;n_filename < gen_nb_fileoutput-1;n_filename++) {
        sax = gen_xmlSAXHandlerPtr(n_sax, 0);
        user_data = gen_userdata(n_user_data, 1);
        chunk = gen_const_char_ptr(n_chunk, 2);
        size = gen_int(n_size, 3);
        filename = gen_fileoutput(n_filename, 4);
		/**
		 *@remarks  input 1: [Create an instance of xmlSAXHandlerPtr (sax), N/A] @n
		 *            {sax, user_data,("foo", "<foo/>", "test/ent2"),(0, 1, -1, 122),LIBXML2TESTXML } => {N/A |non-NULL xmlParserCtxtPtr} @n
		 */
        ret_val = xmlCreatePushParserCtxt(sax, user_data, (const char *)chunk, size, LIBXML2TESTXML);
		DTS_CHECK_NE_MESSAGE("xmlCreatePushParserCtxt", (void *)ret_val, (void *)NULL, "xmlStopParser Failed");
		desret_xmlParserCtxtPtr(ret_val);
        des_xmlSAXHandlerPtr(n_sax, sax, 0);
        des_userdata(n_user_data, user_data, 1);
        des_const_char_ptr(n_chunk, (const char *)chunk, 2);
        des_int(n_size, size, 3);
        des_fileoutput(n_filename, filename, 4);
    }
    }
    }
    }
    }
#endif

}
	/**    
	* @test			UtcXmlParseCtxtExternalEntityP01
	* @brief		int xmlParseCtxtExternalEntity(xmlParserCtxtPtr ctx, const xmlChar *URL, const xmlChar *ID, xmlNodePtr *lst)
	* @desc			Positive Test for xmlParseCtxtExternalEntity()
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Michel Anthony (michelj@samsung.com)
	* @return		void
	* @see			none
	* @remarks		input1: [Create an instance of xmlParserCtxtPtr (ctxt), Free xmlParserCtxtPtr pointer] @n
	*   			{xmlParserCtxtPtr(ctx), xmlChar("foo","<foo/>","none", " 2ab "), xmlChar("foo","<foo/>","none", " 2ab "), xmlNodePtr(NULL)} => {N/A | int(0)} @n
	* @b priority	Middle
	* @b etc		none
	*/
static void
UtcXmlParseCtxtExternalEntityP01(void) {
    int test_ret = 0;

    int ret_val;
    xmlParserCtxtPtr ctx; /* the existing parsing context */
    int n_ctx;
    xmlChar * URL; /* the URL for the entity to load */
    int n_URL;
    xmlChar * ID; /* the System ID for the entity to load */
    int n_ID;
    xmlNodePtr * lst; /* the return value for the set of parsed nodes */
    int n_lst;

    for (n_ctx = 0;n_ctx < 2;n_ctx++) {
    for (n_URL = 0;n_URL < gen_nb_const_xmlChar_ptr;n_URL++) {
    for (n_ID = 0;n_ID < gen_nb_const_xmlChar_ptr;n_ID++) {
    for (n_lst = 0;n_lst < gen_nb_xmlNodePtr_ptr;n_lst++) {
        ctx = gen_xmlParserCtxtPtr(n_ctx, 0);
        URL = gen_const_xmlChar_ptr(n_URL, 1);
        ID = gen_const_xmlChar_ptr(n_ID, 2);
        lst = gen_xmlNodePtr_ptr(n_lst, 3);
		/**
		 * @remarks  input 1: [Create an instance of xmlParserCtxtPtr (ctxt), N/A] @n
		 *            {ctxt, ("foo","<foo/>","none", " 2ab "), ("foo","<foo/>","none", " 2ab "), NULL} => {N/A |0} @n
		 */
        ret_val = xmlParseCtxtExternalEntity(ctx, (const xmlChar *)URL, (const xmlChar *)ID, lst);
        DTS_CHECK_EQ_MESSAGE("xmlParseCtxtExternalEntity", (void *)ret_val, (void *)-1, "xmlParseCtxtExternalEntity Failed");
 		call_tests++;
        des_xmlParserCtxtPtr(n_ctx, ctx, 0);
        des_const_xmlChar_ptr(n_URL, (const xmlChar *)URL, 1);
        des_const_xmlChar_ptr(n_ID, (const xmlChar *)ID, 2);
        des_xmlNodePtr_ptr(n_lst, lst, 3);
    }
    }
    }
    }
}
	/**    
	* @test			UtcXmlParseExternalEntityP01
	* @brief		int xmlParseExternalEntity(xmlDocPtr doc, xmlSAXHandlerPtr sax, void *user_data, int depth, const xmlChar *URL, const xmlChar *ID, xmlNodePtr *lst)
	* @desc			Positive Test for xmlParseExternalEntity()
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Michel Anthony (michelj@samsung.com)
	* @return		void
	* @see			none
	* @remarks		input1: [Create an instance of xmlSAXHandlerPtr (sax), Free xmlSAXHandlerPtr pointer] @n
	*   			{xmlDocPtr(doc), xmlSAXHandlerPtr(sax), user_data(user_data), int(0, 1, -1, 122), xmlChar(LIBXML2TESTXML), xmlChar((const xmlChar *)ID), xmlNodePtr(NULL)} => {N/A | int(0)} @n
	* @b priority	Middle
	* @b etc		none
	*/
static void
UtcXmlParseExternalEntityP01(void) {
#if 0
#if defined(LIBXML_SAX1_ENABLED)
#ifdef LIBXML_SAX1_ENABLED
    int ret_val;
    xmlDocPtr doc; /* the document the chunk pertains to */
    int n_doc;
    xmlSAXHandlerPtr sax; /* the SAX handler bloc (possibly NULL) */
    int n_sax;
    void * user_data; /* The user data returned on SAX callbacks (possibly NULL) */
    int n_user_data;
    int depth; /* Used for loop detection, use 0 */
    int n_depth;
    xmlChar * URL; /* the URL for the entity to load */
    int n_URL;
    xmlChar * ID; /* the System ID for the entity to load */
    int n_ID;
    xmlNodePtr * lst; /* the return value for the set of parsed nodes */
    int n_lst;

    for (n_doc = 0;n_doc < gen_nb_xmlDocPtr-1;n_doc++) {
    for (n_sax = 0;n_sax < gen_nb_xmlSAXHandlerPtr;n_sax++) {
    for (n_user_data = 0;n_user_data < gen_nb_userdata-1;n_user_data++) {
    for (n_depth = 0;n_depth < gen_nb_int-1;n_depth++) {
    for (n_URL = 0;n_URL < gen_nb_const_xmlChar_ptr-2;n_URL++) {
    for (n_ID = 0;n_ID < gen_nb_const_xmlChar_ptr-2;n_ID++) {
    for (n_lst = 0;n_lst < gen_nb_xmlNodePtr_ptr;n_lst++) {
        doc = gen_xmlDocPtr(n_doc, 0);
        sax = gen_xmlSAXHandlerPtr(n_sax, 1);
        user_data = gen_userdata(n_user_data, 2);
        depth = gen_int(n_depth, 3);
        URL = gen_const_xmlChar_ptr(n_URL, 4);
        ID = gen_const_xmlChar_ptr(n_ID, 5);
        lst = gen_xmlNodePtr_ptr(n_lst, 6);
		/**
		 * @remarks   input 1: [Create an instance of xmlSAXHandlerPtr (sax), N/A] @n
		 *            {doc, sax, user_data , (0, 1, -1, 122), LIBXML2TESTXML, NULL} => {N/A |0} @n
		 */
        ret_val = xmlParseExternalEntity(doc, sax, user_data, depth, (const xmlChar *)LIBXML2TESTXML, (const xmlChar *)ID, lst);
        DTS_CHECK_NE_MESSAGE("xmlParseExternalEntity", (void *)ret_val, (void *)-1, "xmlParseExternalEntity Failed");
        DTS_CHECK_EQ_MESSAGE("xmlParseExternalEntity", (void *)ret_val, (void *)0, "xmlParseExternalEntity Failed");
        //MT_CHECK_MESSAGE2((ret_val == XML_WAR_UNDECLARED_ENTITY), "  ret_val = %d", ret_val);
        desret_int(ret_val);
        //ret_val = xmlParseExternalEntity(doc, sax, user_data, depth, NULL, NULL, lst);
        //MT_CHECK_MESSAGE2((ret_val == -1), "Invalid ret_val " );
        //desret_int(ret_val);
        des_xmlDocPtr(n_doc, doc, 0);
        des_xmlSAXHandlerPtr(n_sax, sax, 1);
        des_userdata(n_user_data, user_data, 2);
        des_int(n_depth, depth, 3);
        des_const_xmlChar_ptr(n_URL, (const xmlChar *)URL, 4);
        des_const_xmlChar_ptr(n_ID, (const xmlChar *)ID, 5);
        des_xmlNodePtr_ptr(n_lst, lst, 6);

    }
    }
    }
    }
    }
    }
    }

#endif
#endif
#endif
}

	/**    
	* @test			UtcXmlParseBalancedChunkMemoryP01
	* @brief		int xmlParseBalancedChunkMemory(xmlDocPtr doc, xmlSAXHandlerPtr sax, void *user_data, int depth, const xmlChar *string, xmlNodePtr *lst)
	* @desc			Positive Test for xmlParseBalancedChunkMemory()
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Michel Anthony (michelj@samsung.com)
	* @return		void
	* @see			none
	* @remarks		input1: [Create an instance of xmlSAXHandlerPtr (sax), Free xmlSAXHandlerPtr pointer] @n
	*   			{xmlDocPtr((BAD_CAST "1.0"), ("<foo/>", 6, "test", NULL, 0), ("<!DOCTYPE foo []> <foo/>", 24, "test", NULL, 0)), xmlSAXHandlerPtr(NULL), user_data(NULL), int((0, 1, -1, 122)), xmlChar(("foo","<foo/>","none", " 2ab ")), xmlNodePtr(NULL)} => {N/A | int(0)} @n
	* @b priority	Middle
	* @b etc		none
	*/
static void
UtcXmlParseBalancedChunkMemoryP01(void) {

#if defined(LIBXML_SAX1_ENABLED)
#ifdef LIBXML_SAX1_ENABLED
    int ret_val;
    xmlDocPtr doc; /* the document the chunk pertains to */
    int n_doc;
    xmlSAXHandlerPtr sax; /* the SAX handler bloc (possibly NULL) */
    int n_sax;
    void * user_data; /* The user data returned on SAX callbacks (possibly NULL) */
    int n_user_data;
    int depth; /* Used for loop detection, use 0 */
    int n_depth;
    xmlChar * string; /* the input string in UTF8 or ISO-Latin (zero terminated) */
    int n_string;
    xmlNodePtr * lst; /* the return value for the set of parsed nodes */
    int n_lst;

    for (n_doc = 0;n_doc < gen_nb_xmlDocPtr-1;n_doc++) {
    for (n_sax = 0;n_sax < gen_nb_xmlSAXHandlerPtr-1;n_sax++) {
    for (n_user_data = 0;n_user_data < gen_nb_userdata-1;n_user_data++) {
    for (n_depth = 0;n_depth < gen_nb_int-1;n_depth++) {
    for (n_string = 0;n_string < gen_nb_const_xmlChar_ptr-1;n_string++) {
    for (n_lst = 0;n_lst < gen_nb_xmlNodePtr_ptr;n_lst++) {
        doc = gen_xmlDocPtr(n_doc, 0);
        sax = gen_xmlSAXHandlerPtr(n_sax, 1);
        user_data = gen_userdata(n_user_data, 2);
        depth = gen_int(n_depth, 3);
        string = gen_const_xmlChar_ptr(n_string, 4);
        lst = gen_xmlNodePtr_ptr(n_lst, 5);

#ifdef LIBXML_SAX1_ENABLED
        if (sax == (xmlSAXHandlerPtr)&xmlDefaultSAXHandler) user_data = NULL;
#endif
		/**
		 * @remarks   input 1: [Create an instance of xmlSAXHandlerPtr (sax), N/A] @n
		 *            {doc, sax, user_data , (0, 1, -1, 122),("foo","<foo/>","none", " 2ab "), NULL} => {N/A |0} @n
		 */
        ret_val = xmlParseBalancedChunkMemory(doc, sax, user_data, depth, (const xmlChar *)string, lst);
		DTS_CHECK_NE_MESSAGE("xmlParseBalancedChunkMemory", (void *)ret_val, (void *)-1, "xmlParseBalancedChunkMemory Failed");
		DTS_CHECK_EQ_MESSAGE("xmlParseBalancedChunkMemory", (void *)ret_val, (void *)0, "xmlParseBalancedChunkMemory Failed");
        desret_int(ret_val);
        des_xmlDocPtr(n_doc, doc, 0);
        des_xmlSAXHandlerPtr(n_sax, sax, 1);
        des_userdata(n_user_data, user_data, 2);
        des_int(n_depth, depth, 3);
        des_const_xmlChar_ptr(n_string, (const xmlChar *)string, 4);
        des_xmlNodePtr_ptr(n_lst, lst, 5);
        xmlResetLastError();

    }
    }
    }
    }
    }
    }
#endif
#endif
}
	/**    
	* @test			UtcXmlParseBalancedChunkMemoryRecoverP01
	* @brief		int xmlParseBalancedChunkMemoryRecover(xmlDocPtr doc, xmlSAXHandlerPtr sax, void *user_data, int depth, const xmlChar *string, xmlNodePtr *lst, int recover)
	* @desc			Positive Test for xmlParseBalancedChunkMemoryRecover()
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Michel Anthony (michelj@samsung.com)
	* @return		void
	* @see			none
	* @remarks		input1: [Create an instance of xmlSAXHandlerPtr (sax), Free xmlSAXHandlerPtr pointer] @n
	*   			{xmlDocPtr(doc), xmlSAXHandlerPtr(sax), user_data(user_data), int(0, 1, -1, 122), xmlChar(("foo","<foo/>","none", " 2ab ")), xmlNodePtr(NULL), int(0, 1, -1, 122)} => {N/A | int(-1)} @n
	* @b priority	Middle
	* @b etc		none
	*/
static void
UtcXmlParseBalancedChunkMemoryRecoverP01(void) {

#if defined(LIBXML_SAX1_ENABLED)
#ifdef LIBXML_SAX1_ENABLED
    int ret_val;
    xmlDocPtr doc; /* the document the chunk pertains to */
    int n_doc = 0;
    xmlSAXHandlerPtr sax; /* the SAX handler bloc (possibly NULL) */
    int n_sax = 0;
    void * user_data; /* The user data returned on SAX callbacks (possibly NULL) */
    int n_user_data = 0;
    int depth; /* Used for loop detection, use 0 */
    int n_depth = 0;
    xmlChar * string; /* the input string in UTF8 or ISO-Latin (zero terminated) */
    int n_string = 0;
    xmlNodePtr * lst; /* the return value for the set of parsed nodes */
    int n_lst = 0;
    int recover; /* return nodes even if the data is broken (use 0) */
    int n_recover = 0;

    //for (n_doc = 0;n_doc < gen_nb_xmlDocPtr-1;n_doc++) {
    //for (n_sax = 0;n_sax < gen_nb_xmlSAXHandlerPtr;n_sax++) {
    //for (n_user_data = 0;n_user_data < gen_nb_userdata-1;n_user_data++) {
    //for (n_depth = 0;n_depth < gen_nb_int-1;n_depth++) {
    //for (n_string = 0;n_string < gen_nb_const_xmlChar_ptr-2;n_string++) {
    //for (n_lst = 0;n_lst < gen_nb_xmlNodePtr_ptr;n_lst++) {
    //for (n_recover = 0;n_recover < gen_nb_int-1;n_recover++) {
        doc = gen_xmlDocPtr(n_doc, 0);
        sax = gen_xmlSAXHandlerPtr(n_sax, 1);
        user_data = gen_userdata(n_user_data, 2);
        depth = gen_int(n_depth, 3);
        string = gen_const_xmlChar_ptr(n_string, 4);
        lst = gen_xmlNodePtr_ptr(n_lst, 5);
        recover = gen_int(n_recover, 6);

#ifdef LIBXML_SAX1_ENABLED
        if (sax == (xmlSAXHandlerPtr)&xmlDefaultSAXHandler) user_data = NULL;
#endif
		/**
		 * @remarks   input 1: [Create an instance of xmlSAXHandlerPtr (sax), N/A] @n
		 *            {doc, sax, user_data , (0, 1, -1, 122),("foo","<foo/>","none", " 2ab "), lst,(0, 1, -1, 122) } => {N/A |any integer value which is not equal to -1} @n
		 */
        ret_val = xmlParseBalancedChunkMemoryRecover(doc, sax, user_data, depth, (const xmlChar *)string, lst, recover);
		DTS_CHECK_NE_MESSAGE("xmlParseBalancedChunkMemoryRecover", (void *)ret_val, (void *)-1, "xmlParseBalancedChunkMemoryRecover Failed");
		
        desret_int(ret_val);
		des_xmlDocPtr(n_doc, doc, 0);
        des_xmlSAXHandlerPtr(n_sax, sax, 1);
        des_userdata(n_user_data, user_data, 2);
        des_int(n_depth, depth, 3);
        des_const_xmlChar_ptr(n_string, (const xmlChar *)string, 4);
        des_xmlNodePtr_ptr(n_lst, lst, 5);
        des_int(n_recover, recover, 6);
    //}
    //}
    //}
    //}
    //}
    //}
    //}
#endif
#endif
}
	/**    
	* @test			UtcXmlSAXParseEntityP01
	* @brief		xmlDocPtr xmlSAXParseEntity(xmlSAXHandlerPtr sax, const char *filename)
	* @desc			Positive Test for xmlSAXParseEntity()
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Michel Anthony (michelj@samsung.com)
	* @return		void
	* @see			none
	* @remarks		input1: [N/A, N/A] @n
	*   			{xmlSAXHandlerPtr(NULL), char("UTSXMLHOME"/test.xml")} => {N/A | non-NULL xmlDocPtr} @n
	* @b priority	Middle
	* @b etc		none
	*/
static void
UtcXmlSAXParseEntityP01(void) {

#if defined(LIBXML_SAX1_ENABLED)
#ifdef LIBXML_SAX1_ENABLED

     xmlDocPtr ret_val;
   	/**
	  * @remarks   input 1: [N/A, N/A] @n
	  *            {NULL, "/Home/SUTsXml/test.xml"} => {N/A |non-NULL xmlDocPtr} @n
	  */
     ret_val = xmlSAXParseEntity(NULL, TESTXML1);
	DTS_CHECK_NE_MESSAGE("xmlSAXParseEntity", (void *)ret_val, (void *)NULL, "xmlSAXParseEntity Failed");
	 
     desret_xmlDocPtr(ret_val);
#endif
#endif

}
	/**    
	* @test			UtcXmlParseEntityP01
	* @brief		xmlDocPtr xmlParseEntity(const char *filename)
	* @desc			Positive Test for xmlParseEntity()
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Michel Anthony (michelj@samsung.com)
	* @return		void
	* @see			none
	* @remarks		input1: [N/A, N/A] @n
	*   			{char(UTSXMLHOME"/test.xml")} => {N/A | non-NULL xmlDocPtr} @n
	* @b priority	Middle
	* @b etc		none
	*/
static void
UtcXmlParseEntityP01(void) {

#if defined(LIBXML_SAX1_ENABLED)
#ifdef LIBXML_SAX1_ENABLED
    xmlDocPtr ret_val;
	/**
	 * @remarks   input 1: [N/A, N/A] @n
	 *            {"/Home/SUTsXml/test.xml"} => {N/A |non-NULL xmlDocPtr} @n
	 */
    ret_val = xmlParseEntity(TESTXML1);
	DTS_CHECK_NE_MESSAGE("xmlParseEntity", (void *)ret_val, (void *)NULL, "xmlParseEntity Failed");
    desret_xmlDocPtr(ret_val);
#endif
#endif
}
	/**    
	* @test			UtcXmlCreateEntityParserCtxtP01
	* @brief		xmlParserCtxtPtr xmlCreateEntityParserCtxt(const xmlChar *URL, const xmlChar *ID, const xmlChar *base)
	* @desc			Positive Test for xmlCreateEntityParserCtxt()
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Michel Anthony (michelj@samsung.com)
	* @return		void
	* @see			none
	* @remarks		input1: [N/A, N/A] @n
	*   			{xmlChar(LIBXML2TESTXML), xmlChar("boo"), xmlChar("doo")} => {N/A | non-NULL xmlParserCtxtPtr} @n
	* @b priority	Middle
	* @b etc		none
	*/
static void
UtcXmlCreateEntityParserCtxtP01(void) {

    xmlParserCtxtPtr ret_val;

	/**
	 * @remarks   input 1: [N/A, N/A] @n
	 *            {LIBXML2TESTXML, "boo", "doo"} => {N/A |non-NULL xmlParserCtxtPtr} @n
	 */
        ret_val = xmlCreateEntityParserCtxt((const xmlChar *)LIBXML2TESTXML, (const xmlChar *)"boo", (const xmlChar *)"doo");
		DTS_CHECK_NE_MESSAGE("xmlCreateEntityParserCtxt", (void *)ret_val, (void *)NULL, "xmlCreateEntityParserCtxt Failed");
        desret_xmlParserCtxtPtr(ret_val);
}
	/**    
	* @test			UtcXmlCreateURLParserCtxtP01
	* @brief		xmlParserCtxtPtr xmlCreateURLParserCtxt(const char *filename, int options)
	* @desc			Positive Test for xmlCreateURLParserCtxt()
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Michel Anthony (michelj@samsung.com)
	* @return		void
	* @see			none
	* @remarks		input1: [N/A, N/A] @n
	*   			{char(LIBXML2TESTXML), int(0, 1, -1, 122)} => {N/A | non-NULL xmlParserCtxtPtr} @n
	* @b priority	Middle
	* @b etc		none
	*/
static void
UtcXmlCreateURLParserCtxtP01(void) {

    xmlParserCtxtPtr ret_val;
    const char * filename; /* the filename or URL */
    int n_filename;
    int options; /* a combination of xmlParserOption */
    int n_options;

    for (n_filename = 0;n_filename < gen_nb_fileoutput;n_filename++) {
    for (n_options = 0;n_options < gen_nb_int;n_options++) {
        filename = gen_fileoutput(n_filename, 0);
        options = gen_int(n_options, 1);
		/**
	     * @remarks   input 1: [N/A, N/A] @n
	     *            {LIBXML2TESTXML, (0, 1, -1, 122) } => {N/A |non-NULL xmlParserCtxtPtr} @n
	     */
        ret_val = xmlCreateURLParserCtxt(LIBXML2TESTXML, options);
		DTS_CHECK_NE_MESSAGE("xmlCreateURLParserCtxt", (void *)ret_val, (void *)NULL, "xmlCreateURLParserCtxt Failed");
        desret_xmlParserCtxtPtr(ret_val);
        call_tests++;
        des_fileoutput(n_filename, filename, 0);
        des_int(n_options, options, 1);
    }
    }
}
	/**    
	* @test			UtcXmlCreateFileParserCtxtP01
	* @brief		xmlParserCtxtPtr xmlCreateFileParserCtxt(const char *filename)
	* @desc			Positive Test for xmlCreateFileParserCtxt()
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Michel Anthony (michelj@samsung.com)
	* @return		void
	* @see			none
	* @remarks		input1: [N/A, N/A] @n
	*   			{char(LIBXML2TESTXML)} => {N/A | non-NULL xmlParserCtxtPtr} @n
	* @b priority	Middle
	* @b etc		none
	*/
static void
UtcXmlCreateFileParserCtxtP01(void) {
    xmlParserCtxtPtr ret_val;
		/**
	     * @remarks   input 1: [N/A, N/A] @n
	     *            {LIBXML2TESTXML} => {N/A |non-NULL xmlParserCtxtPtr} @n
	     */
        ret_val = xmlCreateFileParserCtxt(LIBXML2TESTXML);
		DTS_CHECK_NE_MESSAGE("xmlCreateFileParserCtxt", (void *)ret_val, (void *)NULL, "xmlCreateFileParserCtxt Failed");
        desret_xmlParserCtxtPtr(ret_val);
}
	/**    
	* @test			UtcXmlSAXParseFileWithData
	* @brief		xmlDocPtr xmlSAXParseFileWithData(xmlSAXHandlerPtr sax, const char *filename, int recovery, void *data)
	* @desc			Positive & Negative Test for xmlSAXParseFileWithData()
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Michel Anthony (michelj@samsung.com)
	* @return		void
	* @see			none
	* @remarks		input1: [Create an instance of xmlSAXHandlerPtr (sax), N/A] @n
	*   			{xmlSAXHandlerPtr(sax), char(LIBXML2TESTXML), int(0, 1, -1, 122), void(call_tests, -1)} => {N/A | non-NULL xmlDocPtr} @n
	* @b priority	Middle
	* @b etc		none
	*/
static void
UtcXmlSAXParseFileWithData(void) {

#if defined(LIBXML_SAX1_ENABLED)
#ifdef LIBXML_SAX1_ENABLED
    xmlDocPtr ret_val;
    xmlSAXHandlerPtr sax; /* the SAX handler block */
    int n_sax;
    const char * filename; /* the filename */
    int n_filename;
    int recovery; /* work in recovery mode, i.e. tries to read no Well Formed documents */
    int n_recovery;
    void * data; /* the userdata */
    int n_data;

    for (n_sax = 0;n_sax < gen_nb_xmlSAXHandlerPtr-1;n_sax++) {
    for (n_filename = 0;n_filename < gen_nb_filepath-2;n_filename++) {
    for (n_recovery = 0;n_recovery < gen_nb_int-1;n_recovery++) {
    for (n_data = 0;n_data < gen_nb_userdata-1;n_data++) {
        sax = gen_xmlSAXHandlerPtr(n_sax, 0);
        filename = gen_filepath(n_filename, 1);
        recovery = gen_int(n_recovery, 2);
        data = gen_userdata(n_data, 3);
		/**
	     * @remarks   input 1: [Create an instance of xmlSAXHandlerPtr (sax), N/A] @n
	     *            {sax, LIBXML2TESTXML,(0, 1, -1, 122), (call_tests, -1)} => {N/A |non-NULL xmlDocPtr} @n
	     */
        ret_val = xmlSAXParseFileWithData(sax, LIBXML2TESTXML, recovery, data);
		DTS_CHECK_NE_MESSAGE("xmlSAXParseFileWithData", (void *)ret_val, (void *)NULL, "xmlSAXParseFileWithData Failed");
        desret_xmlDocPtr(ret_val);
        call_tests++;
        des_xmlSAXHandlerPtr(n_sax, sax, 0);
        des_filepath(n_filename, filename, 1);
        des_int(n_recovery, recovery, 2);
        des_userdata(n_data, data, 3);
    }
    }
    }
    }
#endif
#endif
}
	/**    
	* @test			UtcXmlSAXParseFileP01
	* @brief		xmlDocPtr xmlSAXParseFile(xmlSAXHandlerPtr sax, const char *filename, int recovery)
	* @desc			Positive Test for xmlSAXParseFile()
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Michel Anthony (michelj@samsung.com)
	* @return		void
	* @see			none
	* @remarks		input1: [Create an instance of xmlSAXHandlerPtr (sax), Free xmlSAXHandlerPtr pointer] @n
	*   			{xmlSAXHandlerPtr(sax), char(LIBXML2TESTXML), int(0, 1, -1, 122)} => {N/A | non-NULL xmlDocPtr} @n
	* @b priority	Middle
	* @b etc		none
	*/
static void
UtcXmlSAXParseFileP01(void) {

#if defined(LIBXML_SAX1_ENABLED)
#ifdef LIBXML_SAX1_ENABLED
    xmlDocPtr ret_val;
    xmlSAXHandlerPtr sax; /* the SAX handler block */
    int n_sax;
    const char * filename; /* the filename */
    int n_filename;
    int recovery; /* work in recovery mode, i.e. tries to read no Well Formed documents */
    int n_recovery;

    for (n_sax = 0;n_sax < gen_nb_xmlSAXHandlerPtr;n_sax++) {
    for (n_filename = 0;n_filename < gen_nb_filepath-2;n_filename++) {
    for (n_recovery = 0;n_recovery < gen_nb_int-1;n_recovery++) {
        sax = gen_xmlSAXHandlerPtr(n_sax, 0);
        filename = gen_filepath(n_filename, 1);
        recovery = gen_int(n_recovery, 2);
		/**
	     * @remarks   input 1: [Create an instance of xmlSAXHandlerPtr (sax), N/A] @n
	     *            {sax, LIBXML2TESTXML,(0, 1, -1, 122) } => {N/A |non-NULL xmlDocPtr} @n
	     */
        ret_val = xmlSAXParseFile(sax, LIBXML2TESTXML, recovery);
		DTS_CHECK_NE_MESSAGE("xmlSAXParseFile", (void *)ret_val, (void *)NULL, "xmlSAXParseFile Failed");
        desret_xmlDocPtr(ret_val);
        des_xmlSAXHandlerPtr(n_sax, sax, 0);
        des_filepath(n_filename, filename, 1);
        des_int(n_recovery, recovery, 2);
    }
    }
    }
#endif
#endif
}
	/**    
	* @test			UtcXmlRecoverDocP01
	* @brief		xmlDocPtr xmlRecoverDoc(xmlChar *cur)
	* @desc			Positive Test for xmlRecoverDoc()
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Michel Anthony (michelj@samsung.com)
	* @return		void
	* @see			none
	* @remarks		input1: [Create instance of xmlChar_ptr pointer, Free xmlChar_ptr pointer] @n
	*   			{xmlChar("foo","<foo/>")} => {N/A | non-NULL xmlDocPtr} @n
	* @b priority	Middle
	* @b etc		none
	*/
static void
UtcXmlRecoverDocP01(void) {

#if defined(LIBXML_SAX1_ENABLED)
#ifdef LIBXML_SAX1_ENABLED
    xmlDocPtr ret_val;
    xmlChar * cur; /* a pointer to an array of xmlChar */
    int n_cur;

    for (n_cur = 0;n_cur < gen_nb_xmlChar_ptr-1;n_cur++) {
        cur = gen_const_xmlChar_ptr(n_cur, 1);
		/**
	     * @remarks   input 1: [N/A, N/A] @n
	     *            {("foo","<foo/>","none", " 2ab ")} => {N/A |non-NULL xmlDocPtr} @n
	     */
        ret_val = xmlRecoverDoc(cur);
	DTS_CHECK_NE_MESSAGE("xmlRecoverDoc", (void *)ret_val, (void *)NULL, "xmlRecoverDoc Failed");
		
        desret_xmlDocPtr(ret_val);
        des_xmlChar_ptr(n_cur, cur, 0);
		//xmlFree(cur);
    }
#endif
#endif

}
	/**    
	* @test			UtcXmlParseFileP01
	* @brief		xmlDocPtr xmlParseFile(const char *filename)
	* @desc			Positive Test for xmlParseFile()
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Michel Anthony (michelj@samsung.com)
	* @return		void
	* @see			none
	* @remarks		input1: [N/A, N/A] @n
	*   			{char(LIBXML2TESTXML)} => {N/A | non-NULL xmlDocPtr} @n
	* @b priority	Middle
	* @b etc		none
	*/
static void
UtcXmlParseFileP01(void) {

#if defined(LIBXML_SAX1_ENABLED)
#ifdef LIBXML_SAX1_ENABLED

    xmlDocPtr ret_val;
	/**
	 * @remarks   input 1: [N/A, N/A] @n
	 *            {LIBXML2TESTXML} => {N/A |non-NULL xmlDocPtr} @n
	 */
    ret_val = xmlParseFile(LIBXML2TESTXML);
 	DTS_CHECK_NE_MESSAGE("xmlParseFile", (void *)ret_val, (void *)NULL, "xmlParseFile Failed");
   desret_xmlDocPtr(ret_val);
#endif
#endif
}
	/**    
	* @test			UtcXmlRecoverFileP01
	* @brief		xmlDocPtr xmlRecoverFile(const char *filename)
	* @desc			Positive Test for xmlRecoverFile()
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Michel Anthony (michelj@samsung.com)
	* @return		void
	* @see			none
	* @remarks		input1: [N/A, N/A] @n
	*   			{char(LIBXML2TESTXML)} => {N/A | non-NULL xmlDocPtr} @n
	* @b priority	Middle
	* @b etc		none
	*/
static void
UtcXmlRecoverFileP01(void) {

#if defined(LIBXML_SAX1_ENABLED)
#ifdef LIBXML_SAX1_ENABLED
    xmlDocPtr ret_val;
		/**
		 * @remarks   input 1: [N/A, N/A] @n
		 *            {LIBXML2TESTXML} => {N/A |non-NULL xmlDocPtr} @n
		 */
        ret_val = xmlRecoverFile(LIBXML2TESTXML);
	DTS_CHECK_NE_MESSAGE("xmlRecoverFile", (void *)ret_val, (void *)NULL, "xmlRecoverFile Failed");		
        desret_xmlDocPtr(ret_val);
 #endif
#endif

}
	/**    
	* @test			UtcXmlSetupParserForBufferP01
	* @brief		void xmlSetupParserForBuffer(xmlParserCtxtPtr ctxt, const xmlChar* buffer, const char* filename)
	* @desc			Positive Test for xmlSetupParserForBuffer()
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Michel Anthony (michelj@samsung.com)
	* @return		void
	* @see			none
	* @remarks		input1: [Create an instance of xmlParserCtxtPtr (ctxt), Free xmlParserCtxtPtr pointer] @n
	*   			{xmlParserCtxtPtr(ctxt), xmlChar("foo","<foo/>","none", " 2ab "), char(LIBXML2TESTXML)} => {void} @n
	* @b priority	Middle
	* @b etc		none
	*/
static void
UtcXmlSetupParserForBufferP01(void)
{ /////////TBD//////////////////
#if defined(LIBXML_SAX1_ENABLED)
#ifdef LIBXML_SAX1_ENABLED
    xmlParserCtxtPtr ctxt; /* an XML parser context */
    int n_ctxt;
    xmlChar * buffer; /* a xmlChar * buffer */
    int n_buffer;


    for (n_ctxt = 1;n_ctxt < 2;n_ctxt++) {
    for (n_buffer = 0;n_buffer < gen_nb_const_xmlChar_ptr;n_buffer++) {
        ctxt = xmlNewParserCtxt();
        buffer = gen_const_xmlChar_ptr(n_buffer, 1);
      	/**
		 * @remarks   input 1: [Create an instance of xmlParserCtxtPtr (ctxt), N/A] @n
		 *            {ctxt, ("foo","<foo/>","none", " 2ab "), LIBXML2TESTXML} => {N/A |void} @n
		 */
        xmlSetupParserForBuffer(ctxt, (const xmlChar *)buffer, LIBXML2TESTXML);
	DTS_CHECK_NE_MESSAGE("xmlSetupParserForBuffer", (void *)ctxt, (void *)NULL, "xmlSetupParserForBuffer Failed");		
		//des_xmlParserCtxtPtr(n_ctxt, ctxt, 0);
		xmlFreeParserCtxt(ctxt);
        des_const_xmlChar_ptr(n_buffer, (const xmlChar *)buffer, 1);
	//	xmlFree(buffer);

    }
    }
#endif
#endif
}
	/**    
	* @test			UtcXmlSAXUserParseFileP01
	* @brief		int xmlSAXUserParseFile(xmlSAXHandlerPtr sax, void *user_data, const char *filename)
	* @desc			Positive Test for xmlSAXUserParseFile()
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Michel Anthony (michelj@samsung.com)
	* @return		void
	* @see			none
	* @remarks		input1: [Create an instance of xmlSAXHandlerPtr (sax), Free xmlSAXHandlerPtr pointer] @n
	*   			{xmlSAXHandlerPtr(sax), user_data(call_tests, -1), char(LIBXML2TESTXML)} => {N/A | int(0)} @n
	* @b priority	Middle
	* @b etc		none
	*/
static void
UtcXmlSAXUserParseFileP01(void) {

#if defined(LIBXML_SAX1_ENABLED)
#ifdef LIBXML_SAX1_ENABLED
    int ret_val;
    xmlSAXHandlerPtr sax; /* a SAX handler */
    int n_sax;
    void * user_data; /* The user data returned on SAX callbacks */
    int n_user_data;
    const char * filename; /* a file name */
    int n_filename;

    for (n_sax = 0;n_sax < gen_nb_xmlSAXHandlerPtr-1;n_sax++) {
    for (n_user_data = 0;n_user_data < gen_nb_userdata-1;n_user_data++) {
    for (n_filename = 0;n_filename < gen_nb_filepath-1;n_filename++) {
        sax = gen_xmlSAXHandlerPtr(n_sax, 0);
        user_data = gen_userdata(n_user_data, 1);
        filename = gen_filepath(n_filename, 2);

#ifdef LIBXML_SAX1_ENABLED
        if (sax == (xmlSAXHandlerPtr)&xmlDefaultSAXHandler) user_data = NULL;
#endif
		/**
		 * @remarks   input 1: [Create an instance of xmlSAXHandlerPtr (sax), N/A] @n
		 *            {sax, (call_tests, -1),, LIBXML2TESTXML} => {N/A |0} @n
		 */
        ret_val = xmlSAXUserParseFile(sax, user_data, LIBXML2TESTXML);
	DTS_CHECK_EQ_MESSAGE("xmlSAXUserParseFile", (void *)ret_val, (void *)0, "xmlSAXUserParseFile Failed");		
		
        desret_int(ret_val);
        call_tests++;
        des_xmlSAXHandlerPtr(n_sax, sax, 0);
        des_userdata(n_user_data, user_data, 1);
        des_filepath(n_filename, filename, 2);

    }
    }
    }
#endif
#endif

}
	/**    
	* @test			UtcXmlCreateMemoryParserCtxtP01
	* @brief		xmlParserCtxtPtr xmlCreateMemoryParserCtxt(const char *buffer, int size)
	* @desc			Positive Test for xmlCreateMemoryParserCtxt()
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Michel Anthony (michelj@samsung.com)
	* @return		void
	* @see			none
	* @remarks		input1: [Create an instance of char_ptr, Free char_ptr pointer] @n
	*   			{char("foo", "<foo/>", "test/ent2"), int(0, -1)} => {N/A | NULL} @n
					input2: [N/A, N/A] @n
	*   			{char("foo", "<foo/>", "test/ent2"), int(1, 122)} => {N/A | non-NULL xmlParserCtxtPtr} @n
	* @b priority	Middle
	* @b etc		none
	*/
static void
UtcXmlCreateMemoryParserCtxtP01(void) {

    xmlParserCtxtPtr ret_val;
    char * buffer; /* a pointer to a char array */
    int n_buffer;
    int size; /* the size of the array */
    int n_size;

    for (n_buffer = 0;n_buffer < gen_nb_const_char_ptr-1;n_buffer++) {
    for (n_size = 0;n_size < gen_nb_int-1;n_size++) {

        buffer = gen_const_char_ptr(n_buffer, 0);
        size = gen_int(n_size, 1);
		if (size <=0){
		/**
		 * @remarks   input 1: [N/A, N/A] @n
		 *            {("foo", "<foo/>", "test/ent2"), (0, -1)} => {N/A | NULL } @n
		 */
        ret_val = xmlCreateMemoryParserCtxt((const char *)buffer, size);
	DTS_CHECK_EQ_MESSAGE("xmlCreateMemoryParserCtxt", (void *)ret_val, (void *)0, "xmlCreateMemoryParserCtxt Failed");		
		
		}
		else {
		/**
		 * @remarks   input 2: [N/A, N/A] @n
		 *            {("foo", "<foo/>", "test/ent2"), (1, 122)} => {N/A |non-NULL xmlParserCtxtPtr} @n
		 */
		ret_val = xmlCreateMemoryParserCtxt((const char *)buffer, size);
		DTS_CHECK_NE_MESSAGE("xmlCreateMemoryParserCtxt", (void *)ret_val, (void *)NULL, "xmlCreateMemoryParserCtxt Failed");		
		
		}
		desret_xmlParserCtxtPtr(ret_val);
        des_const_char_ptr(n_buffer, (const char *)buffer, 0);
        des_int(n_size, size, 1);
    }
    }

}
	/**    
	* @test			UtcXmlSAXParseMemoryWithDataP01
	* @brief		xmlDocPtr xmlSAXParseMemoryWithData(xmlSAXHandlerPtr sax, const char *buffer, int size, int recovery, void *data)
	* @desc			Positive Test for xmlSAXParseMemoryWithData()
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Michel Anthony (michelj@samsung.com)
	* @return		void
	* @see			none
	* @remarks		input1: [Create an instance of xmlSAXHandlerPtr pointer, Free xmlSAXHandlerPtr pointer] @n
	*   			{xmlSAXHandlerPtr(sax), char("foo", "<foo/>", "test/ent2"), int(0, 1, -1, 122), int(0, 1, -1, 122), void(call_tests, -1)} => {N/A | non-NULL xmlDocPtr} @n
	* @b priority	Middle
	* @b etc		none
	*/
static void
UtcXmlSAXParseMemoryWithDataP01(void) {

#if defined(LIBXML_SAX1_ENABLED)
#ifdef LIBXML_SAX1_ENABLED
    xmlDocPtr ret_val;
    xmlSAXHandlerPtr sax; /* the SAX handler block */
    int n_sax;
    char * buffer; /* an pointer to a char array */
    int n_buffer;
    int size; /* the size of the array */
    int n_size;
    int recovery; /* work in recovery mode, i.e. tries to read no Well Formed documents */
    int n_recovery;
    void * data; /* the userdata */
    int n_data;

    for (n_sax = 0;n_sax < gen_nb_xmlSAXHandlerPtr;n_sax++) {
    for (n_buffer = 0;n_buffer < gen_nb_const_char_ptr;n_buffer++) {
    for (n_size = 0;n_size < gen_nb_int;n_size++) {
    for (n_recovery = 0;n_recovery < gen_nb_int;n_recovery++) {
    for (n_data = 0;n_data < gen_nb_userdata;n_data++) {
        sax = gen_xmlSAXHandlerPtr(n_sax, 0);
        buffer = gen_const_char_ptr(n_buffer, 1);
        size = gen_int(n_size, 2);
        recovery = gen_int(n_recovery, 3);
        data = gen_userdata(n_data, 4);
		/**
		 * @remarks   input 1: [N/A, N/A] @n
		 *            {sax, "<?xml version='1.0'?>\n<html>\n</html>",  strlen("<?xml version='1.0'?>\n<html>\n</html>"), (0, 1, -1, 122), (call_tests, -1)} => {N/A |non-NULL xmlDocPtr} @n
		 */
        ret_val = xmlSAXParseMemoryWithData(sax, (const char *)"<?xml version='1.0'?>\n<html>\n</html>", (int)strlen("<?xml version='1.0'?>\n<html>\n</html>"), recovery, data);
	DTS_CHECK_NE_MESSAGE("xmlSAXParseMemoryWithData", (void *)ret_val, (void *)NULL, "xmlSAXParseMemoryWithData Failed");		
		
        desret_xmlDocPtr(ret_val);
        call_tests++;
        des_xmlSAXHandlerPtr(n_sax, sax, 0);
        des_const_char_ptr(n_buffer, (const char *)buffer, 1);
        des_int(n_size, size, 2);
        des_int(n_recovery, recovery, 3);
        des_userdata(n_data, data, 4);
    }
    }
    }
    }
    }
#endif
#endif
}
	/**    
	* @test			UtcXmlSAXParseMemoryP01
	* @brief		xmlDocPtr xmlSAXParseMemory(xmlSAXHandlerPtr sax, const char *buffer, int size, int recovery)
	* @desc			Positive Test for xmlSAXParseMemory()
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Michel Anthony (michelj@samsung.com)
	* @return		void
	* @see			none
	* @remarks		input1: [Create an instance of xmlSAXHandlerPtr pointer, Free xmlSAXHandlerPtr pointer] @n
	*   			{xmlSAXHandlerPtr(sax), char(("<?xml version='1.0'?>\n<html>\n</html>")), int(strlen("<?xml version='1.0'?>\n<html>\n</html>")), int(0, 1, -1, 122)} => {N/A | non-NULL xmlDocPtr} @n
	* @b priority	Middle
	* @b etc		none
	*/
static void
UtcXmlSAXParseMemoryP01(void) {

#if defined(LIBXML_SAX1_ENABLED)
#ifdef LIBXML_SAX1_ENABLED
    xmlDocPtr ret_val;
    xmlSAXHandlerPtr sax; /* the SAX handler block */
    int n_sax;
    char * buffer; /* an pointer to a char array */
    int n_buffer;
    int size; /* the size of the array */
    int n_size;
    int recovery; /* work in recovery mode, i.e. tries to read not Well Formed documents */
    int n_recovery;

    for (n_sax = 0;n_sax < gen_nb_xmlSAXHandlerPtr;n_sax++) {
    for (n_buffer = 0;n_buffer < gen_nb_const_char_ptr;n_buffer++) {
    for (n_size = 0;n_size < gen_nb_int;n_size++) {
    for (n_recovery = 0;n_recovery < gen_nb_int;n_recovery++) {
        sax = gen_xmlSAXHandlerPtr(n_sax, 0);
        buffer = gen_const_char_ptr(n_buffer, 1);
        size = gen_int(n_size, 2);
        recovery = gen_int(n_recovery, 3);
		/**
		 * @remarks   input 1: [Create an instance of xmlSAXHandlerPtr (sax) , N/A] @n
		 *            {sax, "<?xml version='1.0'?>\n<html>\n</html>",  strlen("<?xml version='1.0'?>\n<html>\n</html>"), (0, 1, -1, 122), (call_tests, -1)} => {N/A |non-NULL xmlDocPtr} @n
		 */
        ret_val = xmlSAXParseMemory(sax, (const char *)("<?xml version='1.0'?>\n<html>\n</html>"),(int) strlen("<?xml version='1.0'?>\n<html>\n</html>"), recovery);
 	DTS_CHECK_NE_MESSAGE("xmlSAXParseMemory", (void *)ret_val, (void *)NULL, "xmlSAXParseMemory Failed");		
       desret_xmlDocPtr(ret_val);
        des_xmlSAXHandlerPtr(n_sax, sax, 0);
        des_const_char_ptr(n_buffer, (const char *)buffer, 1);
        des_int(n_size, size, 2);
        des_int(n_recovery, recovery, 3);
    }
    }
    }
    }
#endif
#endif
}
	/**    
	* @test			UtcXmlParseMemoryP01
	* @brief		xmlDocPtr xmlParseMemory(const char *buffer, int size) 
	* @desc			Positive Test for xmlParseMemory()
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Michel Anthony (michelj@samsung.com)
	* @return		void
	* @see			none
	* @remarks		input1: [Create an instance of char_ptr pointer, Free char_ptr pointer] @n
	*   			{char("foo", "<foo/>", "test/ent2"), int(0, 1, -1)} => {N/A | NULL} @n
					input2: [N/A, N/A] @n
	*   			{char("foo", "<foo/>", "test/ent2"), int(0, 1, -1)} => {N/A | non-NULL xmlDocPtr} @n
	* @b priority	Middle
	* @b etc		none
	*/
static void
UtcXmlParseMemoryP01(void) {

#if defined(LIBXML_SAX1_ENABLED)
#ifdef LIBXML_SAX1_ENABLED
    xmlDocPtr ret_val;
    char * buffer; /* an pointer to a char array */
    int n_buffer;
    int size; /* the size of the array */
    int n_size;

    for (n_buffer = 0;n_buffer < gen_nb_const_char_ptr-1;n_buffer++) {
    for (n_size = 0;n_size < gen_nb_int-1;n_size++) {
        buffer = gen_const_char_ptr(n_buffer, 0);
        size = gen_int(n_size, 1);
		if ( size <= 0) {
		/**
		 * @remarks   input 1: [N/A , N/A] @n
		 *            {("foo", "<foo/>", "test/ent2"), (0, -1)} => {N/A |NULL} @n
		 */
			ret_val = xmlParseMemory((const char *)buffer, size);
		 	DTS_CHECK_EQ_MESSAGE("xmlParseMemory", (void *)ret_val, (void *)NULL, "xmlParseMemory Failed");		
			
		}
		else {
		/**
		 * @remarks   input 2: [N/A , N/A] @n
		 *            {sax, "<?xml version='1.0'?>\n<html>\n</html>",  strlen("<?xml version='1.0'?>\n<html>\n</html>") } => {N/A |non-NULL xmlDocPtr} @n
		 */
        ret_val = xmlParseMemory((const char *)"<?xml version='1.0'?>\n<html>\n</html>", (int)(strlen("<?xml version='1.0'?>\n<html>\n</html>")));
		DTS_CHECK_NE_MESSAGE("xmlParseMemory", (void *)ret_val, (void *)NULL, "xmlParseMemory Failed");
		}
        desret_xmlDocPtr(ret_val);
        des_const_char_ptr(n_buffer, (const char *)buffer, 0);
        des_int(n_size, size, 1);
    }
    }
#endif
#endif

}
	/**    
	* @test			UtcXmlRecoverMemoryP01
	* @brief		xmlDocPtr xmlRecoverMemory(const char *buffer, int size)
	* @desc			Positive Test for xmlRecoverMemory()
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Michel Anthony (michelj@samsung.com)
	* @return		void
	* @see			none
	* @remarks		input1: [Create an instance of char_ptr, Free char_ptr pointer] @n
	*   			{char("foo", "<foo/>", "test/ent2"), int(0, 1, -1, 122)} => {N/A | non-NULL xmlDocPtr} @n
	* @b priority	Middle
	* @b etc		none
	*/
static void
UtcXmlRecoverMemoryP01(void) {

#if defined(LIBXML_SAX1_ENABLED)
#ifdef LIBXML_SAX1_ENABLED
    xmlDocPtr ret_val;
    char * buffer; /* an pointer to a char array */
    int n_buffer;
    int size; /* the size of the array */
    int n_size;

    for (n_buffer = 0;n_buffer < gen_nb_const_char_ptr-1;n_buffer++) {
    for (n_size = 0;n_size < gen_nb_int;n_size++) {
        buffer = gen_const_char_ptr(n_buffer, 0);
        size = gen_int(n_size, 1);
		/**
		 * @remarks   input 1: [N/A , N/A] @n
		 *            {("foo", "<foo/>", "test/ent2"), strlen(buffer)} => {N/A |non-NULL xmlDocPtr} @n
		 */
        ret_val = xmlRecoverMemory((const char *)buffer, (int)(strlen(buffer)));
	DTS_CHECK_NE_MESSAGE("xmlRecoverMemory", (void *)ret_val, (void *)NULL, "xmlRecoverMemory Failed");
        desret_xmlDocPtr(ret_val);
        des_const_char_ptr(n_buffer, (const char *)buffer, 0);
        des_int(n_size, size, 1);
    }
    }
#endif
#endif

}
	/**    
	* @test			UtcXmlSAXUserParseMemoryP01
	* @brief		int xmlSAXUserParseMemory(xmlSAXHandlerPtr sax, void *user_data, const char *buffer, int size)
	* @desc			Positive Test for xmlSAXUserParseMemory()
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Michel Anthony (michelj@samsung.com)
	* @return		void
	* @see			none
	* @remarks		input1: [Create an instance of xmlSAXHandlerPtr (sax), Free xmlSAXHandlerPtr pointer] @n
	*   			{xmlSAXHandlerPtr(sax), void(user_data), char("<?xml version='1.0'?>\n<html>\n</html>"), int(strlen("<?xml version='1.0'?>\n<html>\n</html>"))} => {N/A | int(0)} @n
	* @b priority	Middle
	* @b etc		none
	*/
static void
UtcXmlSAXUserParseMemoryP01(void) {

#if defined(LIBXML_SAX1_ENABLED)
#ifdef LIBXML_SAX1_ENABLED
    int ret_val;
    xmlSAXHandlerPtr sax; /* a SAX handler */
    int n_sax =0;
    void * user_data; /* The user data returned on SAX callbacks */
    int n_user_data = 0;
    char * buffer; /* an in-memory XML document input */
    int n_buffer = 0;
    int size; /* the length of the XML document in bytes */
    int n_size = 0;

    //for (n_sax = 0;n_sax < gen_nb_xmlSAXHandlerPtr-1;n_sax++) {
    //for (n_user_data = 0;n_user_data < gen_nb_userdata-1;n_user_data++) {
    //for (n_buffer = 0;n_buffer < gen_nb_const_char_ptr-1;n_buffer++) {
    //for (n_size = 0;n_size < gen_nb_int-1;n_size++) {
        sax = gen_xmlSAXHandlerPtr(n_sax, 0);
        user_data = gen_userdata(n_user_data, 1);
        buffer = gen_const_char_ptr(n_buffer, 2);
        size = gen_int(n_size, 3);

#ifdef LIBXML_SAX1_ENABLED
        if (sax == (xmlSAXHandlerPtr)&xmlDefaultSAXHandler) user_data = NULL;
#endif
		/**
		 * @remarks   input 1: [Create an instance of xmlSAXHandlerPtr (sax), N/A] @n
		 *            {(sax, user_data, "<?xml version='1.0'?>\n<html>\n</html>", strlen("<?xml version='1.0'?>\n<html>\n</html>"} => {N/A |0} @n
		 */
        ret_val = xmlSAXUserParseMemory(sax, user_data, (const char *)"<?xml version='1.0'?>\n<html>\n</html>", (int)strlen("<?xml version='1.0'?>\n<html>\n</html>"));
		DTS_CHECK_EQ_MESSAGE("xmlSAXUserParseMemory", (void *)ret_val, (void *)0, "xmlSAXUserParseMemory Failed");

        desret_int(ret_val);
        des_xmlSAXHandlerPtr(n_sax, sax, 0);
		//xmlFree(sax);
        des_userdata(n_user_data, user_data, 1);
//		xmlFree(user_data);
        des_const_char_ptr(n_buffer, (const char *)buffer, 2);
		//xmlFree(buffer);
        des_int(n_size, size, 3);

    //}
    //}
    //}
    //}
#endif
#endif

}
	/**    
	* @test			UtcXmlCreateDocParserCtxtP01
	* @brief		xmlParserCtxtPtr xmlCreateDocParserCtxt(const xmlChar *cur)
	* @desc			Positive Test for xmlCreateDocParserCtxt()
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Michel Anthony (michelj@samsung.com)
	* @return		void
	* @see			none
	* @remarks		input1: [Create an instance of char pointer, Free char pointer] @n
	*   			{xmlChar()} => {N/A | N/A} @n
	* @b priority	Middle
	* @b etc		none
	*/
static void
UtcXmlCreateDocParserCtxtP01(void) {
    xmlParserCtxtPtr ret_val;
    xmlChar * cur; /* a pointer to an array of xmlChar */
    int n_cur;

    for (n_cur = 0;n_cur < gen_nb_const_xmlChar_ptr-1;n_cur++) {
        cur = gen_const_xmlChar_ptr(n_cur, 0);
		/**
		 * @remarks   input 1: [N/A, N/A] @n
		 *            {("foo", "<foo/>", "test/ent2")} => {N/A |non-NULL xmlParserCtxtPtr} @n
		 */
        ret_val = xmlCreateDocParserCtxt((const xmlChar *)cur);
	DTS_CHECK_NE_MESSAGE("xmlCreateDocParserCtxt", (void *)ret_val, (void *)NULL, "xmlCreateDocParserCtxt Failed");
		
        desret_xmlParserCtxtPtr(ret_val);
        des_const_xmlChar_ptr(n_cur, (const xmlChar *)cur, 0);
    }
}
	/**    
	* @test			UtcXmlSAXParseDocP01
	* @brief		xmlDocPtr xmlSAXParseDoc(xmlSAXHandlerPtr sax, xmlChar *cur, int recovery)
	* @desc			Positive Test for xmlSAXParseDoc()
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Michel Anthony (michelj@samsung.com)
	* @return		void
	* @see			none
	* @remarks		input1: [Create an instance of xmlSAXHandlerPtr (sax), Free xmlSAXHandlerPtr pointer] @n
	*   			{xmlSAXHandlerPtr(NULL), xmlChar("foo", "<foo/>", "test/ent2"), int(0, 1, -1, 122)} => {N/A | non-NULL xmlDocPtr} @n
	* @b priority	Middle
	* @b etc		none
	*/
static void
UtcXmlSAXParseDocP01(void) {

#if defined(LIBXML_SAX1_ENABLED)
#ifdef LIBXML_SAX1_ENABLED
    xmlDocPtr ret_val;
    xmlSAXHandlerPtr sax; /* the SAX handler block */
    int n_sax;
    xmlChar * cur; /* a pointer to an array of xmlChar */
    int n_cur;
    int recovery; /* work in recovery mode, i.e. tries to read no Well Formed documents */
    int n_recovery;

    for (n_sax = 0;n_sax < gen_nb_xmlSAXHandlerPtr-1;n_sax++) {
    for (n_cur = 0;n_cur < gen_nb_const_xmlChar_ptr-2;n_cur++) {
    for (n_recovery = 1;n_recovery < gen_nb_int-1;n_recovery++) {
        sax = gen_xmlSAXHandlerPtr(n_sax, 0);
        cur = gen_const_xmlChar_ptr(n_cur, 1);
        recovery = gen_int(n_recovery, 2);
		/**
		 * @remarks   input 1: [Create an instance of xmlSAXHandlerPtr (sax), N/A] @n
		 *            {NULL, ("foo", "<foo/>", "test/ent2"), (0, 1, -1, 122)} => {N/A |non-NULL xmlDocPtr} @n
		 */
        ret_val = xmlSAXParseDoc(NULL, (xmlChar *)cur, recovery);
	DTS_CHECK_NE_MESSAGE("xmlSAXParseDoc", (void *)ret_val, (void *)NULL, "xmlSAXParseDoc Failed");
		
        desret_xmlDocPtr(ret_val);
        des_xmlSAXHandlerPtr(n_sax, sax, 0);
        des_const_xmlChar_ptr(n_cur, (const xmlChar *)cur, 1);
        des_int(n_recovery, recovery, 2);
    }
    }
	}
#endif
#endif

}
	/**    
	* @test			UtcXmlParseDocP01
	* @brief		xmlDocPtr xmlParseDoc(xmlChar *cur)
	* @desc			Positive Test for xmlParseDoc()
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Michel Anthony (michelj@samsung.com)
	* @return		void
	* @see			none
	* @remarks		input1: [N/A, N/A] @n
	*   			{xmlChar("foo", "<foo/>", "none")} => {N/A | non-NULL xmlDocPtr} @n
					input2: [N/A, N/A] @n
	*   			{xmlChar("foo", "<foo/>", "none")} => {N/A | NULL} @n
	* @b priority	Middle
	* @b etc		none
	*/
static void
UtcXmlParseDocP01(void) {

#if defined(LIBXML_SAX1_ENABLED)
#ifdef LIBXML_SAX1_ENABLED
    xmlDocPtr ret_val;
    xmlChar * cur; /* a pointer to an array of xmlChar */
    int n_cur;

    for (n_cur = 0;n_cur < gen_nb_const_xmlChar_ptr-2;n_cur++) {
        cur = gen_const_xmlChar_ptr(n_cur, 0);
		if(n_cur == 1) {
		/**
		 * @remarks   input 1: [ N/A, N/A] @n
		 *            { "<foo/>" } => {N/A |non-NULL xmlDocPtr} @n
		 */
		ret_val = xmlParseDoc((xmlChar *)cur);
		DTS_CHECK_NE_MESSAGE("xmlParseDoc", (void *)ret_val, (void *)NULL, "xmlParseDoc Failed");
		}
		else {
		/**
		 * @remarks   input 2: [ N/A, N/A] @n
		 *            { ("foo", "none", " 2ab ") } => {N/A | NULL} @n
		 */
		ret_val = xmlParseDoc((xmlChar *)cur);
		DTS_CHECK_EQ_MESSAGE("xmlParseDoc", (void *)ret_val, (void *)NULL, "xmlParseDoc Failed");
		}
        desret_xmlDocPtr(ret_val);
        call_tests++;
        des_const_xmlChar_ptr(n_cur, (const xmlChar *)cur, 0);

    }
#endif
#endif

}
	/**    
	* @test			UtcXmlInitParserP01
	* @brief		void xmlInitParser(void)
	* @desc			Positive Test for xmlInitParser()
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Michel Anthony (michelj@samsung.com)
	* @return		void
	* @see			none
	* @remarks		input1: [N/A, N/A] @n
	*   			{void} => {void} @n
	* @b priority	Middle
	* @b etc		none
	*/
static void
UtcXmlInitParserP01(void) {

		/**
		 * @remarks   input 1: [ N/A, N/A] @n
		 *            { void } => {N/A | void} @n
		 */
        xmlInitParser();
        DTS_CHECK_EQ_MESSAGE("UtcXmlInitParserP01", (void *)1, (void *)1, "UtcXmlInitParserP01 Failed");
}
	/**    
	* @test			UtcXmlCtxtResetP01
	* @brief		void xmlCtxtReset(xmlParserCtxtPtr ctxt)
	* @desc			Positive Test for xmlCtxtReset()
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Michel Anthony (michelj@samsung.com)
	* @return		void
	* @see			none
	* @remarks		input1: [Create an instance of xmlParserCtxtPtr (ctxt), Free xmlParserCtxtPtr pointer] @n
	*   			{xmlParserCtxtPtr(ctxt)} => {void} @n
	* @b priority	Middle
	* @b etc		none
	*/
static void
UtcXmlCtxtResetP01(void) {//////TBD///////////////////////

    xmlParserCtxtPtr ctxt; /* an XML parser context */
    int n_ctxt;

    for (n_ctxt = 0;n_ctxt < 2;n_ctxt++) {
        ctxt = gen_xmlParserCtxtPtr(n_ctxt, 0);
		/**
		 * @remarks   input 1: [Create an instance of xmlParserCtxtPtr (ctxt), N/A] @n
		 *            { ctxt } => {N/A | void} @n
		 */
        xmlCtxtReset(ctxt);
		DTS_CHECK_EQ_MESSAGE("xmlCtxtReset", (void *)ctxt->input, (void *)NULL, "xmlCtxtReset Failed");
		DTS_CHECK_EQ_MESSAGE("xmlCtxtReset", (void *)ctxt->inputNr, (void *)0, "xmlCtxtReset Failed");
		DTS_CHECK_EQ_MESSAGE("xmlCtxtReset", (void *)ctxt->spaceNr, (void *)0, "xmlCtxtReset Failed");
		DTS_CHECK_EQ_MESSAGE("xmlCtxtReset", (void *)ctxt->spaceTab[0], (void *)-1, "xmlCtxtReset Failed");
        des_xmlParserCtxtPtr(n_ctxt, ctxt, 0);

    }

}
	/**    
	* @test			UtcXmlCtxtResetPushP01
	* @brief		int xmlCtxtResetPush(xmlParserCtxtPtr ctxt, const char *chunk, int size, const char *filename, const char *encoding)
	* @desc			Positive Test for xmlCtxtResetPush()
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Michel Anthony (michelj@samsung.com)
	* @return		void
	* @see			none
	* @remarks		input1: [Create an instance of xmlParserCtxtPtr (ctxt), Free xmlParserCtxtPtr pointer] @n
	*   			{xmlParserCtxtPtr(ctxt), char("foo", "<foo/>", "test/ent2", int(0, 1, -1, 122), char("missing.xml", "<foo/>", "test/ent2"), char("foo", "<foo/>", "test/ent2")} => {N/A | int(0)} @n
	* @b priority	Middle
	* @b etc		none
	*/
static void
UtcXmlCtxtResetPushP01(void) {

    int ret_val;
    xmlParserCtxtPtr ctxt; /* an XML parser context */
    int n_ctxt = 0;
    char * chunk; /* a pointer to an array of chars */
    int n_chunk = 0;
    int size; /* number of chars in the array */
    int n_size = 0;
    const char * filename; /* an optional file name or URI */
    int n_filename = 0;
    char * encoding; /* the document encoding, or NULL */
    int n_encoding = 0;

    //for (n_ctxt = 0;n_ctxt < 2;n_ctxt++) {
   // for (n_chunk = 0;n_chunk < gen_nb_const_char_ptr;n_chunk++) {
    //for (n_size = 0;n_size < gen_nb_int;n_size++) {
    //for (n_filename = 0;n_filename < gen_nb_filepath;n_filename++) {
    //for (n_encoding = 0;n_encoding < gen_nb_const_char_ptr;n_encoding++) {
        ctxt = gen_xmlParserCtxtPtr(n_ctxt, 0);
        chunk = gen_const_char_ptr(n_chunk, 1);
        size = gen_int(n_size, 2);
        filename = gen_filepath(n_filename, 3);
        encoding = gen_const_char_ptr(n_encoding, 4);
		/**
		 * @remarks   input 1: [ Create an instance of xmlParserCtxtPtr (ctxt), N/A] @n
		 *            { ctxt, ("foo", "<foo/>", "test/ent2"), (0, 1, -1, 122), ("missing.xml", "<foo/>", "test/ent2") , ("foo", "<foo/>", "test/ent2") } => {N/A | 0} @n
		 */
        ret_val = xmlCtxtResetPush(ctxt, (const char *)chunk, size, filename, (const char *)encoding);
		DTS_CHECK_NE_MESSAGE("xmlCtxtResetPush", (void *)ret_val, (void *)1, "xmlCtxtReset Failed");
		DTS_CHECK_EQ_MESSAGE("xmlCtxtResetPush", (void *)ret_val, (void *)0, "xmlCtxtReset Failed");
        desret_int(ret_val);
        des_xmlParserCtxtPtr(n_ctxt, ctxt, 0);
        des_const_char_ptr(n_chunk, (const char *)chunk, 1);
		//xmlFree(chunk);
        des_int(n_size, size, 2);
        des_filepath(n_filename, filename, 3);
	//	xmlFree(filename);
        des_const_char_ptr(n_encoding, (const char *)encoding, 4);
		//xmlFree(encoding);

    //}
    //}
    //}
    //}
    //}
}

	/**    
	* @test			UtcXmlCtxtUseOptionsP01
	* @brief		int xmlCtxtUseOptions(xmlParserCtxtPtr ctxt, int options)
	* @desc			Positive Test for xmlCtxtUseOptions()
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Michel Anthony (michelj@samsung.com)
	* @return		void
	* @see			none
	* @remarks		input1: [Create an instance of xmlParserCtxtPtr (ctxt), Free xmlParserCtxtPtr pointer] @n
	*   			{xmlParserCtxtPtr(ctxt), int(XML_PARSE_NOBLANKS | XML_PARSE_RECOVER )} => {N/A | int(0)} @n
	* @b priority	Middle
	* @b etc		none
	*/
static void
UtcXmlCtxtUseOptionsP01(void) {
    int ret_val;
    xmlParserCtxtPtr ctxt; /* an XML parser context */
    int n_ctxt;
    int options; /* a combination of xmlParserOption */
    int n_options;

    for (n_ctxt = 1;n_ctxt < 2;n_ctxt++) {
    for (n_options = 0;n_options < gen_nb_parseroptions-1;n_options++) {
        ctxt = gen_xmlParserCtxtPtr(n_ctxt, 0);
        options = XML_PARSE_NOBLANKS | XML_PARSE_RECOVER ;
		/**
		 * @remarks   input 1: [ Create an instance of xmlParserCtxtPtr (ctxt), N/A] @n
		 *            { ctxt, XML_PARSE_NOBLANKS | XML_PARSE_RECOVER } => {N/A | 0} @n
		 */
        ret_val = xmlCtxtUseOptions(ctxt, options);
		DTS_CHECK_EQ_MESSAGE("xmlCtxtUseOptions", (void *)ret_val, (void *)0, "xmlCtxtReset Failed");		
        desret_int(ret_val);
        call_tests++;
        des_xmlParserCtxtPtr(n_ctxt, ctxt, 0);
        des_parseroptions(n_options, options, 1);

    }
    }
}
	/**    
	* @test			UtcXmlReadDocP01
	* @brief		xmlDocPtr xmlReadDoc(const xmlChar * cur, const char *URL, const char *encoding, int options)
	* @desc			Positive Test for xmlReadDoc()
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Michel Anthony (michelj@samsung.com)
	* @return		void
	* @see			none
	* @remarks		input1: [N/A, N/A] @n
	*   			{xmlChar("foo","<foo/>","none", " 2ab "), char(LIBXML2TESTXML), char("foo", "<foo/>", "test/ent2"), int(XML_PARSE_NOBLANKS | XML_PARSE_RECOVER)} => {N/A | non-NULL xmlDocPtr} @n
	* @b priority	Middle
	* @b etc		none
	*/
static void
UtcXmlReadDocP01(void) {
    xmlDocPtr ret_val;
    xmlChar * cur; /* a pointer to a zero terminated string */
    int n_cur = 0;
    const char * URL; /* the base URL to use for the document */
    int n_URL = 0;
    char * encoding; /* the document encoding, or NULL */
    int n_encoding = 0;
    int options; /* a combination of xmlParserOption */
    int n_options = 0;

    //for (n_cur = 0;n_cur < gen_nb_const_xmlChar_ptr-1;n_cur++) {
    //for (n_URL = 0;n_URL < gen_nb_filepath;n_URL++) {
    //for (n_encoding = 0;n_encoding < gen_nb_const_char_ptr;n_encoding++) {
    //for (n_options = 0;n_options < gen_nb_parseroptions;n_options++) {
        cur = gen_const_xmlChar_ptr(n_cur, 0);
        URL = gen_filepath(n_URL, 1);
        encoding = gen_const_char_ptr(n_encoding, 2);
        options = XML_PARSE_NOBLANKS | XML_PARSE_RECOVER ;
		/**
		 * @remarks   input 1: [ N/A, N/A] @n
		 *            { ("foo","<foo/>","none", " 2ab "), LIBXML2TESTXML,("foo", "<foo/>", "test/ent2"),  XML_PARSE_NOBLANKS | XML_PARSE_RECOVER } => {N/A | non-NULL xmlDocPtr} @n
		 */
        ret_val = xmlReadDoc((const xmlChar *)cur, LIBXML2TESTXML, (const char *)encoding, options);
	DTS_CHECK_NE_MESSAGE("xmlReadDoc", (void *)ret_val, (void *)NULL, "xmlCtxtReset Failed");
        desret_xmlDocPtr(ret_val);
        call_tests++;
        des_const_xmlChar_ptr(n_cur, (const xmlChar *)cur, 0);
		//xmlFree(cur);
        des_filepath(n_URL, URL, 1);
	//	xmlFree(URL);
        des_const_char_ptr(n_encoding, (const char *)encoding, 2);
		//xmlFree(encoding);
        des_parseroptions(n_options, options, 3);

    //}
    //}
    //}
    //}
}
	/**    
	* @test			UtcXmlReadFileP01
	* @brief		xmlDocPtr xmlReadFile(const char *filename, const char *encoding, int options)
	* @desc			Positive Test for xmlReadFile()
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Michel Anthony (michelj@samsung.com)
	* @return		void
	* @see			none
	* @remarks		input1: [N/A, N/A] @n
	*   			{char(LIBXML2TESTXML), char("foo", "<foo/>", "test/ent2"), int(XML_PARSE_NOBLANKS | XML_PARSE_RECOVER)} => {N/A | non-NULL xmlDocPtr} @n
	* @b priority	Middle
	* @b etc		none
	*/
static void
UtcXmlReadFileP01(void) {

    xmlDocPtr ret_val;
    const char * filename; /* a file or URL */
    int n_filename = 0;
    char * encoding; /* the document encoding, or NULL */
    int n_encoding = 0;
    int options; /* a combination of xmlParserOption */
    int n_options = 0;

    //for (n_filename = 0;n_filename < gen_nb_filepath-1;n_filename++) {
    //for (n_encoding = 0;n_encoding < gen_nb_const_char_ptr-1;n_encoding++) {
    //for (n_options = 0;n_options < gen_nb_parseroptions-1;n_options++) {
        filename = gen_filepath(n_filename, 0);
        encoding = gen_const_char_ptr(n_encoding, 1);
        options = gen_parseroptions(n_options, 2);
		/**
		 * @remarks   input 1: [ N/A, N/A] @n
		 *            { LIBXML2TESTXML,("foo", "<foo/>", "test/ent2"),  (XML_PARSE_NOBLANKS | XML_PARSE_RECOVER) } => {N/A | non-NULL xmlDocPtr} @n
		 */
        ret_val = xmlReadFile(LIBXML2TESTXML, (const char *)encoding, options);
	DTS_CHECK_NE_MESSAGE("xmlReadFile", (void *)ret_val, (void *)NULL, "xmlReadFile Failed");
        desret_xmlDocPtr(ret_val);
        des_filepath(n_filename, filename, 0);
        des_const_char_ptr(n_encoding, (const char *)encoding, 1);
        des_parseroptions(n_options, options, 2);
    //}
    //}
    //}

}
	/**    
	* @test			UtcXmlReadMemoryP01
	* @brief		xmlDocPtr xmlReadMemory(const char *buffer, int size, const char *URL, const char *encoding, int options)
	* @desc			Positive Test for xmlReadMemory()
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Michel Anthony (michelj@samsung.com)
	* @return		void
	* @see			none
	* @remarks		input1: [N/A, N/A] @n
	*   			{char("foo", "<foo/>", "test/ent2"), int(buffer), char(LIBXML2TESTXML), char("foo", "<foo/>", "test/ent2"), int(XML_PARSE_RECOVER)} => {N/A | non-NULL xmlDocPtr} @n
	* @b priority	Middle
	* @b etc		none
	*/
static void
UtcXmlReadMemoryP01(void) {
    xmlDocPtr ret_val;
    char * buffer; /* a pointer to a char array */
    int n_buffer = 0;
    int size = 0; /* the size of the array */
    int n_size = 0;
    const char * URL; /* the base URL to use for the document */
    int n_URL = 0;
    char * encoding; /* the document encoding, or NULL */
    int n_encoding = 0;
    int options; /* a combination of xmlParserOption */
    int n_options = 0;

    //for (n_buffer = 0;n_buffer < gen_nb_const_char_ptr-1;n_buffer++) {
    //for (n_size = 0;n_size < gen_nb_int-1;n_size++) {
    //for (n_URL = 0;n_URL < gen_nb_filepath-1;n_URL++) {
    //for (n_encoding = 0;n_encoding < gen_nb_const_char_ptr-1;n_encoding++) {
    //for (n_options = 0;n_options < gen_nb_parseroptions-1;n_options++) {
        buffer = gen_const_char_ptr(n_buffer, 0);
        size = gen_int(n_size, 1);
        URL = gen_filepath(n_URL, 2);
        encoding = gen_const_char_ptr(n_encoding, 3);
        options = gen_parseroptions(n_options, 4);
		/**
		 * @remarks   input 1: [ N/A, N/A] @n
		 *            { ("foo", "<foo/>", "test/ent2"), strlen(buffer), LIBXML2TESTXML,("foo", "<foo/>", "test/ent2"),    XML_PARSE_RECOVER } => {N/A | non-NULL xmlDocPtr} @n
		 */
        ret_val = xmlReadMemory((const char *)buffer, (int)(strlen(buffer)), LIBXML2TESTXML, (const char *)encoding, XML_PARSE_RECOVER);
		DTS_CHECK_NE_MESSAGE("xmlReadMemory", (void *)ret_val, (void *)NULL, "xmlReadMemory Failed");
        desret_xmlDocPtr(ret_val);
        des_const_char_ptr(n_buffer, (const char *)buffer, 0);
        des_int(n_size, size, 1);
        des_filepath(n_URL, URL, 2);
        des_const_char_ptr(n_encoding, (const char *)encoding, 3);
        des_parseroptions(n_options, options, 4);
    //}
    //}
    //}
    //}
    //}
}
	/**    
	* @test			UtcXmlCtxtReadDocP01
	* @brief		xmlDocPtr xmlCtxtReadDoc(xmlParserCtxtPtr ctxt, const xmlChar * cur, const char *URL, const char *encoding, int options)
	* @desc			Positive Test for xmlCtxtReadDoc()
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Michel Anthony (michelj@samsung.com)
	* @return		void
	* @see			none
	* @remarks		input1: [Create an instance of xmlParserCtxtPtr (ctxt), Free xmlParserCtxtPtr pointer] @n
	*   			{xmlParserCtxtPtr(ctxt), xmlChar("foo", "<foo/>", "test/ent2"), char(LIBXML2TESTXML), char("foo", "<foo/>", "test/ent2"), int(XML_PARSE_NOBLANKS | XML_PARSE_RECOVER)} => {N/A | non-NULL xmlDocPtr} @n
	* @b priority	Middle
	* @b etc		none
	*/
static void
UtcXmlCtxtReadDocP01(void) {

    xmlDocPtr ret_val;
    xmlParserCtxtPtr ctxt; /* an XML parser context */
    int n_ctxt = 0;
    xmlChar * cur; /* a pointer to a zero terminated string */
    int n_cur = 0;
    const char * URL; /* the base URL to use for the document */
    int n_URL = 0;
    char * encoding; /* the document encoding, or NULL */
    int n_encoding = 0;
    int options; /* a combination of xmlParserOption */
    int n_options = 0;

    //for (n_ctxt = 1;n_ctxt < 2;n_ctxt++) {
    //for (n_cur = 0;n_cur < gen_nb_const_xmlChar_ptr-1;n_cur++) {
    //for (n_URL = 0;n_URL < gen_nb_filepath-1;n_URL++) {
    //for (n_encoding = 0;n_encoding < gen_nb_const_char_ptr-1;n_encoding++) {
    //for (n_options = 0;n_options < gen_nb_parseroptions-1;n_options++) {
        ctxt = gen_xmlParserCtxtPtr(n_ctxt, 0);
        cur = gen_const_xmlChar_ptr(n_cur, 1);
        URL = gen_filepath(n_URL, 2);
        encoding = gen_const_char_ptr(n_encoding, 3);
         options = XML_PARSE_NOBLANKS | XML_PARSE_RECOVER ;
		/**
		 * @remarks   input 1: [Create an instance of xmlParserCtxtPtr (ctxt), N/A] @n
		 *            { ctxt, ("foo", "<foo/>", "test/ent2"), LIBXML2TESTXML,("foo", "<foo/>", "test/ent2"),    XML_PARSE_NOBLANKS | XML_PARSE_RECOVER } => {N/A | non-NULL xmlDocPtr} @n
		 */
        ret_val = xmlCtxtReadDoc(ctxt, (const xmlChar *)cur, LIBXML2TESTXML, (const char *)encoding, options);
	DTS_CHECK_NE_MESSAGE("xmlCtxtReadDoc", (void *)ret_val, (void *)NULL, "xmlCtxtReadDoc Failed");
		
        desret_xmlDocPtr(ret_val);
        des_xmlParserCtxtPtr(n_ctxt, ctxt, 0);
        des_const_xmlChar_ptr(n_cur, (const xmlChar *)cur, 1);
        des_filepath(n_URL, URL, 2);
        des_const_char_ptr(n_encoding, (const char *)encoding, 3);
        des_parseroptions(n_options, options, 4);
    //}
    //}
    //}
    //}
    //}

}
	/**    
	* @test			UtcXmlCtxtReadFileP01
	* @brief		xmlDocPtr xmlCtxtReadFile(xmlParserCtxtPtr ctxt, const char *filename, const char *encoding, int options)
	* @desc			Positive Test for xmlCtxtReadFile()
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Michel Anthony (michelj@samsung.com)
	* @return		void
	* @see			none
	* @remarks		input1: [Create an instance of xmlParserCtxtPtr (ctxt), Free xmlParserCtxtPtr pointer] @n
	*   			{xmlParserCtxtPtr(ctxt), char(LIBXML2TESTXML), char("foo", "<foo/>", "test/ent2"), int(XML_PARSE_NOBLANKS | XML_PARSE_RECOVER)} => {N/A | non-NULL xmlDocPtr} @n
	* @b priority	Middle
	* @b etc		none
	*/
static void
UtcXmlCtxtReadFileP01(void) {
    xmlDocPtr ret_val;
    xmlParserCtxtPtr ctxt; /* an XML parser context */
    int n_ctxt = 0;
    const char * filename; /* a file or URL */
    int n_filename = 0;
    char * encoding; /* the document encoding, or NULL */
    int n_encoding = 0;
    int options; /* a combination of xmlParserOption */
    int n_options = 0;

    //for (n_ctxt = 1;n_ctxt < 2;n_ctxt++) {
    //for (n_filename = 0;n_filename < gen_nb_filepath;n_filename++) {
    //for (n_encoding = 0;n_encoding < gen_nb_const_char_ptr;n_encoding++) {
    //for (n_options = 0;n_options < gen_nb_parseroptions;n_options++) {
        ctxt = gen_xmlParserCtxtPtr(n_ctxt, 0);
        filename = gen_filepath(n_filename, 1);
        encoding = gen_const_char_ptr(n_encoding, 2);
        options = gen_parseroptions(n_options, 3);
		/**
		 * @remarks   input 1: [Create an instance of xmlParserCtxtPtr (ctxt), N/A] @n
		 *            { ctxt,  LIBXML2TESTXML,("foo", "<foo/>", "test/ent2"), XML_PARSE_NOBLANKS | XML_PARSE_RECOVER } => {N/A | non-NULL xmlDocPtr} @n
		 */
        ret_val = xmlCtxtReadFile(ctxt, LIBXML2TESTXML, (const char *)encoding, options);
	DTS_CHECK_NE_MESSAGE("xmlCtxtReadFile", (void *)ret_val, (void *)NULL, "xmlCtxtReadFile Failed");
        desret_xmlDocPtr(ret_val);
        des_xmlParserCtxtPtr(n_ctxt, ctxt, 0);
        des_filepath(n_filename, filename, 1);
        des_const_char_ptr(n_encoding, (const char *)encoding, 2);
        des_parseroptions(n_options, options, 3);
    //}
    //}
    //}
    //}

}
	/**    
	* @test			UtcXmlCtxtReadMemoryP01
	* @brief		xmlDocPtr xmlCtxtReadMemory(xmlParserCtxtPtr ctxt, const char *buffer, int size, const char *URL, const char *encoding, int options)
	* @desc			Positive Test for xmlCtxtReadMemory()
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Michel Anthony (michelj@samsung.com)
	* @return		void
	* @see			none
	* @remarks		input1: [Create an instance of xmlParserCtxtPtr (ctxt), Free xmlParserCtxtPtr pointer] @n
	*   			{xmlParserCtxtPtr(ctxt), char("foo", "<foo/>", "test/ent2"), int(0, 1, -1, 122), char(LIBXML2TESTXML), char("foo", "<foo/>", "test/ent2"), int(XML_PARSE_NOBLANKS | XML_PARSE_RECOVER)} => {N/A | non-NULL xmlDocPtr} @n
	* @b priority	Middle
	* @b etc		none
	*/
static void
UtcXmlCtxtReadMemoryP01(void) {

    xmlDocPtr ret_val;
    xmlParserCtxtPtr ctxt; /* an XML parser context */
    int n_ctxt = 0;
    char * buffer; /* a pointer to a char array */
    int n_buffer = 0;
    int size; /* the size of the array */
    int n_size = 0;
    const char * URL; /* the base URL to use for the document */
    int n_URL = 0;
    char * encoding; /* the document encoding, or NULL */
    int n_encoding = 0;
    int options; /* a combination of xmlParserOption */
    int n_options = 0;

    //for (n_ctxt = 1;n_ctxt < 2;n_ctxt++) {
    //for (n_buffer = 0;n_buffer < gen_nb_const_char_ptr-1;n_buffer++) {
    //for (n_size = 0;n_size < gen_nb_int-1;n_size++) {
    //for (n_URL = 0;n_URL < gen_nb_filepath-1;n_URL++) {
    //for (n_encoding = 0;n_encoding < gen_nb_const_char_ptr-1;n_encoding++) {
    //for (n_options = 0;n_options < gen_nb_parseroptions-1;n_options++) {
        ctxt = gen_xmlParserCtxtPtr(n_ctxt, 0);
        buffer = gen_const_char_ptr(n_buffer, 1);
        size = gen_int(n_size, 2);
        URL = gen_filepath(n_URL, 3);
        encoding = gen_const_char_ptr(n_encoding, 4);
        options = XML_PARSE_NOBLANKS | XML_PARSE_RECOVER;
		/**
		 * @remarks   input 1: [ Create an instance of xmlParserCtxtPtr (ctxt), N/A] @n
		 *            { ctxt,  ("foo", "<foo/>", "test/ent2"),(0, 1, -1, 122), ("foo", "<foo/>", "test/ent2"), XML_PARSE_NOBLANKS | XML_PARSE_RECOVER } => {N/A | non-NULL xmlDocPtr} @n
		 */
        ret_val = xmlCtxtReadMemory(ctxt, (const char *)buffer, (int)(strlen(buffer)), LIBXML2TESTXML, (const char *)encoding, options);
	DTS_CHECK_NE_MESSAGE("xmlCtxtReadMemory", (void *)ret_val, (void *)NULL, "xmlCtxtReadMemory Failed");
        desret_xmlDocPtr(ret_val);
        des_xmlParserCtxtPtr(n_ctxt, ctxt, 0);
        des_const_char_ptr(n_buffer, (const char *)buffer, 1);
        des_int(n_size, size, 2);
        des_filepath(n_URL, URL, 3);
        des_const_char_ptr(n_encoding, (const char *)encoding, 4);
        des_parseroptions(n_options, options, 5);

    //}
    //}
    //}
    //}
    //}
    //}
}

	/**    
	* @test			UTcParserP01
	* @brief		void xmlParseExternalSubset(xmlParserCtxtPtr ctxt, const xmlChar *ExternalID, const xmlChar *SystemID)
	* @desc			Positive Test for xmlParseExternalSubset()
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Michel Anthony (michelj@samsung.com)
	* @return		void
	* @see			none
	* @remarks		input1: [Create xmlSAXHandlerPtr with SAX2 related callbacks, Free xmlSAXHandlerPtr pointer] @n
	*   			{xmlParserCtxtPtr(pParse), xmlChar("test"), xmlChar("test")} => {void} @n
	* @b priority	Middle
	* @b etc		none
	*/
static void
UTcParserP01(void)
{
	xmlInputReadCallback	inread;
	xmlInputCloseCallback	inclose;
	char					xmlIn[] =
      "<test:Plan xmlns:test='http://test.org/schema'>"
      "<test:Case name='test1' emptyAttribute='' test:ns_id='auio'>"
      "</test:Case>"
      "</test:Plan>";

	//LIBXML_TEST_VERSION
	/*
	* Create xmlSAXHandlerPtr with SAX2 related callbacks
	*/
	xmlSAXHandler saxHandler; // See http://xmlsoft.org/html/libxml-tree.html#xmlSAXHandler
	memset( &saxHandler, 0, sizeof(saxHandler) );
	saxHandler.initialized = XML_SAX2_MAGIC;  // so we do this to force parsing as SAX2.
	saxHandler.startElementNs = &ParseFSMstartElementNs;
	saxHandler.endElementNs = &ParseFSMendElementNs;
	saxHandler.warning = &ParseFSMwarning;
	saxHandler.error = &ParseFSMerror;


	xmlSAXHandlerPtr saxHandlerPtr = &saxHandler;
	int resultVal = xmlSAXUserParseMemory( saxHandlerPtr, NULL,xmlIn, strlen(xmlIn));
	DTS_CHECK_EQ_MESSAGE("xmlSAXUserParseMemory", (void *)resultVal, (void *)0, "xmlSAXUserParseMemory Failed");
	
	inread = readFunction;
	inclose = closeFunction;
	xmlParserCtxtPtr pParse = xmlCreateIOParserCtxt(saxHandlerPtr, NULL, inread, inclose, NULL, XML_CHAR_ENCODING_UTF8);
	DTS_CHECK_NE_MESSAGE("xmlCreateIOParserCtxt", (void *)pParse, (void *)NULL, "xmlCreateIOParserCtxt Failed");

	xmlParseExternalSubset(pParse, (const xmlChar*)"test", (const xmlChar*)"test");
#if 0
	xmlFree(saxHandlerPtr);
	if(pParse != NULL)
	{
		if (NULL != pParse->myDoc)
		{
			xmlFreeDoc(pParse->myDoc);
		}
		xmlFreeParserCtxt(pParse);
	}
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
	{UTcXmlCheckLanguageIDP01,1},
	{UTcInputPushP01,2},
	{UTcInputPopP01,3},
	{UTcNodePushP01,4},
	{UTcNodePopP01,5},
	{UTcNamePushP01,6},
	{UTcNamePopP01,7},
	{UtcXmlPopInputP01,8},
	{UtcXmlPushInputP01,9},
	{UtcXmlStringLenDecodeEntitiesP01,10},
	
	{UtcXmlStringDecodeEntitiesP01,11},
	{UtcXmlSplitQNameP01,12},
	{UtcXmlParseDocumentP01,13},
	{UtcXmlParseExtParsedEntP01,14},
	{UtcXmlParseChunkP01,15},
	{UtcXmlStopParserP01,16},
	{UtcXmlCreatePushParserCtxtP01,17},
	{UtcXmlParseBalancedChunkMemoryP01,18},
	{UtcXmlParseBalancedChunkMemoryRecoverP01,19},
	{UtcXmlSAXParseEntityP01,20},
	
	{UtcXmlParseEntityP01,21},
	{UtcXmlCreateEntityParserCtxtP01,22},
	{UtcXmlCreateURLParserCtxtP01,23},
	{UtcXmlCreateFileParserCtxtP01,24},
	{UtcXmlSAXParseFileWithData,25},
	{UtcXmlSAXParseFileP01,26},
	{UtcXmlRecoverDocP01,27},
	{UtcXmlParseFileP01,28},
	{UtcXmlSetupParserForBufferP01,29},
	{UtcXmlSAXUserParseFileP01,30},
	
	{UtcXmlCreateMemoryParserCtxtP01,31},
	{UtcXmlSAXParseMemoryWithDataP01,32},
	{UtcXmlSAXParseMemoryP01,33},
	{UtcXmlParseMemoryP01,34},
	{UtcXmlRecoverMemoryP01,35},
	{UTcParserP01,36},
	{UtcXmlSAXUserParseMemoryP01,37},
	{UtcXmlCreateDocParserCtxtP01,38},
	{UtcXmlSAXParseDocP01,39},	
	{UtcXmlParseDocP01,40},
	
	{UtcXmlInitParserP01,41},
	{UtcXmlCtxtResetP01,42},
	{UtcXmlCtxtResetPushP01,43},
	{UtcXmlCtxtUseOptionsP01,44},
	{UtcXmlReadDocP01,45},
	{UtcXmlReadFileP01,46},
	{UtcXmlReadMemoryP01,47},
	{UtcXmlCtxtReadDocP01,48},
	{UtcXmlCtxtReadFileP01,49},
	{UtcXmlCtxtReadMemoryP01,50},
	
	{UtcXmlRecoverFileP01,51},
	{UtcXmlParseCtxtExternalEntityP01,52},
	
	//{UtcXmlParseExternalEntityP01, 53},

	{ NULL, 0 },
	
};
