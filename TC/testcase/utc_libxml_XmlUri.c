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
#include <libxml/xmlmemory.h>
#include <libxml/uri.h>
#include <libxml/globals.h>
#include <libxml/xmlunicode.h>




/***************************************************************************
* SUTsXmlUri
***************************************************************************/

void __HandleURI1(const char *str)
{
	xmlChar *res	= NULL;
	xmlChar	*parsed = NULL;
	xmlURIPtr uri;
	int ret = 0;

	uri = xmlCreateURI();
	DTS_CHECK_NE_MESSAGE("__HandleURI1", (void *)uri, (void *)NULL, "xmlCreateURI Failed");

	ret = xmlParseURIReference(uri, str);
	DTS_CHECK_EQ_MESSAGE("__HandleURI1", (void *)ret, (void *)0, "xmlParseURIReference Failed");
		
	if (ret != 0)
	{
		//Do nothing
	}
	else
	{
		if (uri->scheme)
		{
			DTS_CHECK_EQ_MESSAGE("__HandleURI1", (void *)(strcmp((uri->scheme),("http"))), (void *)0, "xmlParseURIReference scheme Failed");
		}
		#if 0
		if (uri->opaque)
		{
			DTS_CHECK_EQ_MESSAGE("__HandleURI1", (void *)uri->opaque, (void *)NULL, "xmlParseURIReference opaque Failed");
		}
		//if (uri->authority)
		{
			DTS_CHECK_EQ_MESSAGE("__HandleURI1", (void *)uri->authority, (void *)NULL, "xmlParseURIReference authority Failed");
		}
		#endif
		if (uri->server)
		{
			DTS_CHECK_EQ_MESSAGE("__HandleURI1", (void *)(strcmp((uri->server),("elsewhere.com"))), (void *)0, "xmlParseURIReference server Failed");
		}
		#if 0
		if (uri->user)
		{
			DTS_CHECK_EQ_MESSAGE("__HandleURI1", (void *)uri->user, (void *)NULL, "xmlParseURIReference user Failed");
		}
		#endif
		if (uri->port != 0)
		{
			DTS_CHECK_EQ_MESSAGE("__HandleURI1", (void *)uri->port, (void *)2880, "xmlParseURIReference port Failed");
		}
		if (uri->path)
		{
			DTS_CHECK_EQ_MESSAGE("__HandleURI1", (void *)(strcmp((uri->path),("/index.html"))), (void *)0, "xmlParseURIReference path Failed");
		}
		if (uri->query)
		{
			DTS_CHECK_EQ_MESSAGE("__HandleURI1", (void *)(strcmp((uri->query),("deep"))), (void *)0, "xmlParseURIReference query Failed");
		}
		if (uri->fragment)
		{
			DTS_CHECK_EQ_MESSAGE("__HandleURI1", (void *)(strcmp((uri->fragment),("deep2"))), (void *)0, "xmlParseURIReference fragment Failed");
		}

		int normalizeretval = xmlNormalizeURIPath(uri->path);
		DTS_CHECK_EQ_MESSAGE("__HandleURI1", (void *)normalizeretval, (void *)0, "xmlNormalizeURIPath Failed");

		parsed = xmlSaveUri(uri);
		DTS_CHECK_NE_MESSAGE("__HandleURI1", (void *)parsed, (void *)NULL, "xmlSaveUri Failed");
			
		res = xmlURIEscape(parsed);
		DTS_CHECK_NE_MESSAGE("__HandleURI1", (void *)res, (void *)NULL, "xmlURIEscape Failed");
			
	}
	if (res != NULL)
		xmlFree(res);
	if (parsed != NULL)
		xmlFree(parsed);
	xmlFreeURI(uri);
}
void __HandleURI2(const char *str)
{
	xmlChar *res	= NULL;
	xmlChar	*parsed = NULL;
	xmlURIPtr uri;
	int ret = 0;

	uri = xmlCreateURI();
	DTS_CHECK_NE_MESSAGE("__HandleURI2", (void *)uri, (void *)NULL, "xmlCreateURI Failed");

	ret = xmlParseURIReference(uri, str);
	DTS_CHECK_EQ_MESSAGE("__HandleURI2", (void *)ret, (void *)0, "xmlParseURIReference Failed");
		
	if (ret != 0)
	{
		//Do nothing
	}
	else
	{
		if (uri->scheme)
		{
			DTS_CHECK_EQ_MESSAGE("__HandleURI1", (void *)(strcmp((uri->scheme),("mailto"))), (void *)0, "xmlParseURIReference scheme Failed");
		}
		if (uri->opaque)
		{
			DTS_CHECK_EQ_MESSAGE("__HandleURI1", (void *)(strcmp((uri->opaque),("java-net@java.sun.com"))), (void *)NULL, "xmlParseURIReference opaque Failed");
		}
		#if 0
		//if (uri->authority)
		{
			DTS_CHECK_EQ_MESSAGE("__HandleURI1", (void *)uri->authority, (void *)NULL, "xmlParseURIReference authority Failed");
		}
		if (uri->server)
		{
			DTS_CHECK_EQ_MESSAGE("__HandleURI1", (void *)(strcmp((uri->server),("elsewhere.com"))), (void *)0, "xmlParseURIReference server Failed");
		}
		if (uri->user)
		{
			DTS_CHECK_EQ_MESSAGE("__HandleURI1", (void *)uri->user, (void *)NULL, "xmlParseURIReference user Failed");
		}
		if (uri->port != 0)
		{
			DTS_CHECK_EQ_MESSAGE("__HandleURI1", (void *)uri->port, (void *)2880, "xmlParseURIReference port Failed");
		}
		if (uri->path)
		{
			DTS_CHECK_EQ_MESSAGE("__HandleURI1", (void *)(strcmp((uri->path),("elsewhere.com"))), (void *)0, "xmlParseURIReference path Failed");
		}
		if (uri->query)
		{
			DTS_CHECK_EQ_MESSAGE("__HandleURI1", (void *)(strcmp((uri->query),("deep"))), (void *)0, "xmlParseURIReference query Failed");
		}
		#endif
		if (uri->fragment)
		{
			DTS_CHECK_EQ_MESSAGE("__HandleURI1", (void *)(strcmp((uri->fragment),("deep2"))), (void *)0, "xmlParseURIReference fragment Failed");
		}

		parsed = xmlSaveUri(uri);
		DTS_CHECK_NE_MESSAGE("__HandleURI1", (void *)parsed, (void *)NULL, "xmlSaveUri Failed");
			
		res = xmlURIEscape(parsed);
		DTS_CHECK_NE_MESSAGE("__HandleURI1", (void *)res, (void *)NULL, "xmlURIEscape Failed");
			
	}
	
	if (res != NULL)
		xmlFree(res);
	if (parsed != NULL)
		xmlFree(parsed);
	xmlFreeURI(uri);
}	

	/**    
	* @test			UTcUriP01
	* @brief		int	xmlNormalizeURIPath	(char * path)
					xmlChar *	xmlSaveUri (xmlURIPtr uri)
					xmlChar *	xmlURIEscape (const xmlChar * str)
	* @desc			3 APIs tested - Positive Test for Appling the 5 normalization steps to a path string, Saving the URI as an escaped string, escaping routine
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Michel Anthony (michelj@samsung.com)
	* @return		void
	* @see			none
	* @remarks		input1: [create an empty xmlURI and Parse an URI, Free up the xmlURI struct] @n
	*   			{char(uri->path)} => { N/A | 0 or error } @n
					input2: [creates an empty xmlURI and Parse an URI, Free up the xmlURI struct] @n
	*   			{xmlURIPtr(uri)} => {N/A | new string} @n
					input3: [create an empty xmlURI and Parse an URI, Free up the xmlURI struct] @n
	*   			{parser} => {N/A  | copy of a string} @n
	* @b priority	Middle
	* @b etc		none
	*/
static void UTcUriP01()
{
	char inputstr[1024] = "http://elsewhere.com:2880/index.html?deep#deep2";
	int len =  (int)strlen(inputstr);
	while ((len > 0) &&
		((inputstr[len - 1] == '\n') || (inputstr[len - 1] == '\r') ||
		(inputstr[len - 1] == ' ') || (inputstr[len - 1] == '\t')))
	{
			len--;
			inputstr[len] = 0;
	}
	__HandleURI1(inputstr);
}
	/**    
	* @test			UTcUriP02
	* @brief		xmlChar *	xmlSaveUri		(xmlURIPtr uri)
					xmlChar *	xmlURIEscape		(const xmlChar * str)
	* @desc			2 APIs Tested - Positive Test for Saving the URI as an escaped string, escaping routine
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Michel Anthony (michelj@samsung.com)
	* @return		void
	* @see			none
	* @remarks		input1: [creates an empty xmlURI and Parse an URI, Free up the xmlURI struct] @n
	*   			{xmlURIPtr(uri)} => {N/A| NULL } @n
					input2: [creates an empty xmlURI and Parse an URI, Free up the xmlURI struct] @n
	*   			{parser} => {N/A| NULL} @n
	* @b priority	Middle
	* @b etc		none
	*/
static void UTcUriP02()
{
	char inputstr[1024] = "mailto:java-net@java.sun.com#deep2  ";
	int len =  (int)strlen(inputstr);
	while ((len > 0) &&
		((inputstr[len - 1] == '\n') || (inputstr[len - 1] == '\r') ||
		(inputstr[len - 1] == ' ') || (inputstr[len - 1] == '\t')))
	{
		len--;
		inputstr[len] = 0;
	}
	__HandleURI2(inputstr);
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
	{UTcUriP01,1},
	{UTcUriP02,2},
	{ NULL, 0 },
	
};
