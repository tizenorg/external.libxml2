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
#include <libxml/xinclude.h>


/***************************************************************************
* SUTsXmlInclude
***************************************************************************/
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

	/**    
	* @test			UTcXmlXIncludeNewContextP01
	* @brief		xmlXIncludeCtxtPtr xmlXIncludeNewContext(xmlDocPtr doc)
	* @desc			Positive and Negative Test for xmlXIncludeNewContext
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Sathish Kumar (satish.k4@samsung.com)
	* @return		xmlXIncludeCtxtPtr
	* @see			none
	* @remarks		input1: [N/A, N/A] @n
	*   			{xmlDocPtr(!=NULL)} => {N/A | xmlXIncludeCtxtPtr(!=NULL)} @n

					input2: [N/A, N/A] @n
	*   			{xmlDocPtr(==NULL)} => {N/A | xmlXIncludeCtxtPtr(==NULL)} @n
	* @b priority	Middle
	* @b etc		none
	*/
 static void UTcXmlXIncludeNewContextP01()
{
	    xmlXIncludeCtxtPtr ret_val=NULL;  /* pointer of xmlXIncludeCtxtPtr */
	    xmlDocPtr in_Doc = get_api_doc();   /*Initialize in_Doc ptr*/

		// @remarks   input1: [N/A, N/A] @n
	    //  		  {xmlDocPtr(!=NULL)} => {N/A | xmlXIncludeCtxtPtr(!=NULL)} @n
		if(in_Doc != NULL)
		{
		  ret_val = xmlXIncludeNewContext(in_Doc);
		  DTS_CHECK_NE_MESSAGE("xmlXIncludeNewContext", (void *)ret_val, (void *)NULL, "xmlXIncludeNewContext Failed");
		}


		// @remarks   input2: [N/A, N/A] @n
	    //    		{xmlDocPtr(==NULL)} => {N/A | xmlXIncludeCtxtPtr(==NULL)} @n

		in_Doc = NULL;
		if(in_Doc == NULL)
		{
			ret_val = xmlXIncludeNewContext(in_Doc);
			DTS_CHECK_EQ_MESSAGE("xmlXIncludeNewContext", (void *)ret_val, (void *)NULL, "xmlXIncludeNewContext Failed");
		}

        xmlXIncludeFreeContext(ret_val);
        xmlFreeDoc(in_Doc);//Free up all the structures used by a document.
 }
	/**
	* @test			UTcXmlXIncludeProcessFlagsP01
	* @brief		int xmlXIncludeProcessFlags(xmlDocPtr doc,int flags)
	* @desc			Positive and Negative Test for xmlXIncludeProcessFlags
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Sathish Kumar (satish.k4@samsung.com)
	* @return		int
	* @see			none
	* @remarks		input1: [N/A, N/A] @n
	*   			{xmlDocPtr(!=NULL),int(1)} => {N/A | int(0)} @n
	*
	*   			input2: [N/A, N/A] @n
	*   			{xmlDocPtr(==NULL),int(1)} => {N/A | int(-1)} @n
	* @b priority	Middle
	* @b etc		none
	*/
 static void UTcXmlXIncludeProcessFlagsP01()
{
    int ret_val;
    xmlDocPtr in_Doc=NULL; /* an XML document */
   in_Doc = get_api_doc(); /*Initialize in_Doc ptr*/

    //@remarks		input1: [N/A, N/A] @n
   //   			{xmlDocPtr(!=NULL),int(1)} => {N/A | int(0)} @n
    if(in_Doc != NULL)
    {
      ret_val = xmlXIncludeProcessFlags(in_Doc,1);
	  DTS_CHECK_EQ_MESSAGE("xmlXIncludeProcessFlags", (void *)ret_val, (void *)0, "xmlXIncludeProcessFlags Failed");
    }
   // @remarks    input2: [N/A, N/A] @n
   //             {xmlDocPtr(==NULL),int(1)} => {N/A | int(-1)} @n
    in_Doc = NULL;
    if(in_Doc == NULL)
    {
      ret_val = xmlXIncludeProcessFlags(in_Doc,1);
	  DTS_CHECK_EQ_MESSAGE("xmlXIncludeProcessFlags", (void *)ret_val, (void *)-1, "xmlXIncludeProcessFlags Failed");
    }
    xmlFreeDoc(in_Doc);//Free up all the structures used by a document.
}

	/**
	* @test			UTcXmlXIncludeProcessFlagsP01
	* @brief		int xmlXIncludeProcessNode(xmlXIncludeCtxtPtr ctxt, xmlNodePtr node)
	* @desc			Positive and Negative Test for xmlXIncludeProcessNode
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Sathish Kumar (satish.k4@samsung.com)
	* @return		int
	* @see			none
	* @remarks		input1: [N/A, N/A] @n
	*   			{xmlXIncludeCtxtPtr(ctxt_ptr!=NULL),xmlNodePtr(node_ptr==NULL )} => {N/A | int(-1)} @n
	*
	*   			input2: [N/A, N/A] @n
	*   			{xmlXIncludeCtxtPtr(ctxt_ptr!=NULL),xmlNodePtr(node_ptr!=NULL )} => {N/A | int(-1)} @n

	* 				input3: [N/A, N/A] @n
	*   			{xmlXIncludeCtxtPtr(ctxt_ptr!=NULL),xmlNodePtr(node_ptr!=NULL )} => {N/A | int(0)} @n

					input4: [N/A, N/A] @n
	*   			{xmlXIncludeCtxtPtr(ctxt_ptr==NULL),xmlNodePtr(node_ptr!=NULL )} => {N/A | int(-1)} @n
	* @b priority	Middle
	* @b etc		none
	*/
 static void UTcXmlXIncludeProcessNodeP01()
 {
	 xmlXIncludeCtxtPtr ctxt_ptr=NULL;
	 xmlDocPtr in_Doc=NULL; /* an XML document */
	 in_Doc = get_api_doc(); /*Initialize in_Doc ptr*/
	 ctxt_ptr = xmlXIncludeNewContext(in_Doc);

	 xmlNodePtr node_ptr = NULL; //Create node pointer
	 int out_value;

	// @remarks	input1: [N/A, N/A] @n
	// {xmlXIncludeCtxtPtr(ctxt_ptr!=NULL),xmlNodePtr(node_ptr==NULL)} => {N/A | int(-1)} @n

    if(ctxt_ptr != NULL && node_ptr == NULL)
    {
    	out_value = xmlXIncludeProcessNode(ctxt_ptr,node_ptr);
		  DTS_CHECK_EQ_MESSAGE("xmlXIncludeProcessNode", (void *)out_value, (void *)-1, "xmlXIncludeProcessNode 1 Failed");
    }
    //@remarks input2: [N/A, N/A] @n
	// 	{xmlXIncludeCtxtPtr(ctxt_ptr!=NULL),xmlNodePtr(node!=NULL)} => {N/A | int(-1)} @n


    node_ptr = get_api_root();

    if(ctxt_ptr != NULL && node_ptr != NULL)
    {
	   out_value = xmlXIncludeProcessNode(ctxt_ptr,node_ptr);
	   DTS_CHECK_EQ_MESSAGE("xmlXIncludeProcessNode", (void *)out_value, (void *)0, "xmlXIncludeProcessNode 2 Failed");
    }
    //	input3: [N/A, N/A] @n
    //	{xmlXIncludeCtxtPtr(ctxt_ptr!=NULL),xmlNodePtr(node_ptr!=NULL)} => {N/A | int(0)} @n


	 if(ctxt_ptr != NULL && node_ptr != NULL)
	 {
	 	out_value = xmlXIncludeProcessNode(ctxt_ptr,node_ptr);
		DTS_CHECK_EQ_MESSAGE("xmlXIncludeProcessNode", (void *)out_value, (void *)0, "xmlXIncludeProcessNode 3 Failed");
	 }

    //	 @remarks input4: [N/A, N/A] @n
    //	 {xmlXIncludeCtxtPtr(ctxt_ptr==NULL),xmlNodePtr(node_ptr!=NULL)} => {N/A | int(-1)} @n

	 	ctxt_ptr=NULL;
	 	if(ctxt_ptr == NULL && node_ptr != NULL)
	 	{
	 	  out_value = xmlXIncludeProcessNode(ctxt_ptr,node_ptr);
		  DTS_CHECK_EQ_MESSAGE("xmlXIncludeProcessNode", (void *)out_value, (void *)-1, "xmlXIncludeProcessNode 4 Failed");
	 	}

		xmlXIncludeFreeContext(ctxt_ptr);
		//xmlFreeNode(node_ptr);

 }

	/**
	* @test			UTcXmlXIncludeProcessTreeFlagsP01
	* @brief		int xmlXIncludeProcessTreeFlags(xmlNodePtr tree, int flags)
	* @desc			Positive and Negative Test for xmlXIncludeProcessTreeFlags
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Sathish Kumar (satish.k4@samsung.com)
	* @return		int
	* @see			none
	* @remarks		input1: [N/A, N/A] @n
	*   			{xmlNodePtr(node_ptr=NULL and N/A) ),int(1)} => {N/A | int(-1)} @n
	*
	*   			input2: [N/A, N/A] @n
	*   			{xmlNodePtr(node_ptr!=NULL and node_ptr->doc==NULL),int(1)} => {N/A | int(-1)} @n

	* 				input3: [N/A, N/A] @n
	*   			{xmlNodePtr(node_ptr!=NULL and node_ptr->doc==NULL ),int(1)} => {N/A | int(0)} @n
	* @b priority	Middle
	* @b etc		none
	*/

 static void UTcXmlXIncludeProcessTreeFlagsP01()
 {
	 xmlNodePtr node_ptr=NULL;
	 int out_value;
	// @remarks input1: [N/A, N/A] @n
	// 		 	  {xmlNodePtr(node_ptr=NULL and N/A) ),int(1)} => {N/A | int(-1)} @n

    if(node_ptr == NULL)
    {
	out_value = xmlXIncludeProcessTreeFlags(node_ptr,1);
	 DTS_CHECK_EQ_MESSAGE("xmlXIncludeProcessTreeFlags", (void *)out_value, (void *)-1, "xmlXIncludeProcessTreeFlags Failed");
    }

   // input2: [N/A, N/A] @n
   //	{xmlNodePtr(node_ptr!=NULL and node_ptr->doc==NULL),int(1)} => {N/A | int(-1)} @n

	xmlDocPtr in_Doc=NULL; /* an XML document */
	in_Doc = get_api_doc(); /*Initialize in_Doc ptr*/
	node_ptr = xmlDocGetRootElement(in_Doc);
	node_ptr->doc = NULL;
	if(node_ptr!=NULL && node_ptr->doc == NULL)
	{
	  out_value = xmlXIncludeProcessTreeFlags(node_ptr,1);
	   DTS_CHECK_EQ_MESSAGE("xmlXIncludeProcessTreeFlags", (void *)out_value, (void *)-1, "xmlXIncludeProcessTreeFlags Failed");
	}
   // input3: [N/A, N/A] @n
   // {xmlNodePtr(node_ptr!=NULL and node_ptr->doc==NULL ),int(1)} => {N/A | int(0)} @n

	node_ptr->doc = in_Doc;
	if(node_ptr!=NULL && node_ptr->doc != NULL)
	{
	  out_value = xmlXIncludeProcessTreeFlags(node_ptr,1);
	   DTS_CHECK_EQ_MESSAGE("xmlXIncludeProcessTreeFlags", (void *)out_value, (void *)0, "xmlXIncludeProcessTreeFlags Failed");
	}

	//xmlFreeNode(node_ptr);
 }
	/**
	* * @test		UTcXmlXIncludeSetFlagsP01
	* @brief		int xmlXIncludeSetFlags(xmlXIncludeCtxtPtr ctxt, int flags)
	* @desc			Positive and Negative Test for xmlXIncludeSetFlags
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Sathish Kumar (satish.k4@samsung.com)
	* @return		int
	* @see			none
	* @remarks		input1: [N/A, N/A] @n
	*   			{xmlXIncludeCtxtPtr(ctxt_ptr!=NULL),int(1)} => {N/A | int(0)} @n
	*
	*   			input2: [N/A, N/A] @n
	*   			{xmlXIncludeCtxtPtr(ctxt_ptr!=NULL),int(1)} => {N/A | int(-1)} @n

	* @b priority	Middle
	* @b etc		none
	*/
 static void UTcXmlXIncludeSetFlagsP01()
 {
	 int out_value;
	 xmlXIncludeCtxtPtr ctxt_ptr=NULL;
	 xmlDocPtr in_Doc=NULL; /* an XML document */
	 in_Doc = get_api_doc(); /*Initialize in_Doc ptr*/
	 ctxt_ptr = xmlXIncludeNewContext(in_Doc);
	// * @remarks input1: [N/A, N/A] @n
	//	*   	  {xmlXIncludeCtxtPtr(ctxt_ptr!=NULL),int(1)} => {N/A | int(0)} @n
    if(ctxt_ptr!=NULL)
    {
    	out_value = xmlXIncludeSetFlags(ctxt_ptr,1);
		DTS_CHECK_EQ_MESSAGE("xmlXIncludeSetFlags", (void *)out_value, (void *)0, "xmlXIncludeSetFlags Failed");
    }

    // * @remarks input1: [N/A, N/A] @n
    // *   	     {xmlXIncludeCtxtPtr(ctxt_ptr!=NULL),int(1)} => {N/A | int(0)} @n
    ctxt_ptr = NULL;
    if(ctxt_ptr==NULL)
    {
    	out_value = xmlXIncludeSetFlags(ctxt_ptr,1);
		DTS_CHECK_EQ_MESSAGE("xmlXIncludeSetFlags", (void *)out_value, (void *)-1, "xmlXIncludeSetFlags Failed");
    }
    xmlXIncludeFreeContext(ctxt_ptr);

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
	{UTcXmlXIncludeNewContextP01,1},
	{UTcXmlXIncludeProcessFlagsP01,2},
	{UTcXmlXIncludeProcessTreeFlagsP01,3},
	{UTcXmlXIncludeSetFlagsP01,4},
	{UTcXmlXIncludeProcessNodeP01,5},
	{NULL, 0 },
	
};
