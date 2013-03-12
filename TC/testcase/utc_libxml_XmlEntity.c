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



/**    
	* @test			UTcxmlGetPredefinedEntityP01
	* @brief		xmlEntityPtr	xmlGetPredefinedEntity	(const xmlChar * name)
	* @desc			Positive Test for Setting up the predefined entities
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Michel Anthony (michelj@samsung.com)
	* @return		void
	* @see			none
	* @remarks		input1: [N/A, N/A] @n
	*				{ const xmlChar * "lt" } => { N/A | xmlEntityPtr pointer } @n
					input2: [N/A, N/A] @n
	*				{ const xmlChar * "gt" } => { N/A | xmlEntityPtr pointer } @n
					input3: [N/A, N/A] @n
	*				{ const xmlChar * "amp" } => { N/A | xmlEntityPtr pointer } @n
					input4: [N/A, N/A] @n
	*				{ const xmlChar * "apos" } => { N/A | xmlEntityPtr pointer } @n
					input5: [N/A, N/A] @n
	*				{ const xmlChar * "quot" } => { N/A | xmlEntityPtr pointer } @n
					input6: [N/A, N/A] @n
	*				{ const xmlChar * "invalid" } => { N/A | NULL } @n
	* @b priority	Middle
	* @b etc		none
	*/

static void
UTcxmlGetPredefinedEntityP01()
{
	char *pName1 = "lt";
	char *pName2 = "gt";
	char *pName3 = "amp";
	char *pName4 = "apos";
	char *pName5 = "quot";
	char *pName6 = "invalid";

	/**
	* @remarks   input1: [N/A, N/A] @n
	*            { "lt" } => { N/A | xmlEntityPtr pointer } @n
	*/
	xmlEntityPtr pEntity = xmlGetPredefinedEntity((const xmlChar *)pName1);
	DTS_CHECK_NE_MESSAGE("xmlGetPredefinedEntity", (void *)pEntity, (void *)NULL, "xmlGetPredefinedEntity Failed");

	/**
	* @remarks   input2: [N/A, N/A] @n
	*            { "gt" } => { N/A | xmlEntityPtr pointer } @n
	*/
	pEntity = xmlGetPredefinedEntity((const xmlChar *)pName2);
	DTS_CHECK_NE_MESSAGE("xmlGetPredefinedEntity", (void *)pEntity, (void *)NULL, "xmlGetPredefinedEntity Failed");

	/**
	* @remarks   input3: [N/A, N/A] @n
	*            { "amp" } => { N/A | xmlEntityPtr pointer } @n
	*/
	pEntity = xmlGetPredefinedEntity((const xmlChar *)pName3);
	DTS_CHECK_NE_MESSAGE("xmlGetPredefinedEntity", (void *)pEntity, (void *)NULL, "xmlGetPredefinedEntity Failed");

	/**
	* @remarks   input4: [N/A, N/A] @n
	*            { "apos" } => { N/A | xmlEntityPtr pointer } @n
	*/
	pEntity = xmlGetPredefinedEntity((const xmlChar *)pName4);
	DTS_CHECK_NE_MESSAGE("xmlGetPredefinedEntity", (void *)pEntity, (void *)NULL, "xmlGetPredefinedEntity Failed");

	/**
	* @remarks   input5: [N/A, N/A] @n
	*            { "quot" } => { N/A | xmlEntityPtr pointer } @n
	*/
	pEntity = xmlGetPredefinedEntity((const xmlChar *)pName5);
	DTS_CHECK_NE_MESSAGE("xmlGetPredefinedEntity", (void *)pEntity, (void *)NULL, "xmlGetPredefinedEntity Failed");

	/**
	* @remarks   input6: [N/A, N/A] @n
	*            { "invalid" } => { N/A | NULL } @n
	*/
	pEntity = xmlGetPredefinedEntity((const xmlChar *)pName6);
	DTS_CHECK_EQ_MESSAGE("xmlGetPredefinedEntity", (void *)pEntity, (void *)NULL, "xmlGetPredefinedEntity Failed");
	
}

/**    
	* @test			UTcxmlCreateEntitiesTableP01
	* @brief		xmlEntitiesTablePtr	xmlCreateEntitiesTable	(void)
	* @desc			Positive Test for creating and initializing an empty entities hash table
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Michel Anthony (michelj@samsung.com)
	* @return		void
	* @see			none
	* @remarks		input1: [N/A, N/A] @n
	*				{ void } => { N/A | xmlEntitiesTablePtr pointer } @n
	* @b priority	Middle
	* @b etc		none
	*/
static void
UTcxmlCreateEntitiesTableP01()
{
	/**
	* @remarks   input1: [N/A, N/A] @n
	*            { void } => { N/A | xmlEntitiesTablePtr pointer } @n
	*/
	xmlEntitiesTablePtr pTable = xmlCreateEntitiesTable();
	DTS_CHECK_NE_MESSAGE("UTcxmlCreateEntitiesTableP01", (void *)pTable, (void *)NULL, "xmlCreateEntitiesTable Failed");

	xmlFreeEntitiesTable(pTable);
}

/**    
	* @test			UTcxmlFreeEntitiesTableP01
	* @brief		void xmlFreeEntitiesTable (xmlEntitiesTablePtr table)
	* @desc			Positive Test for Deallocating the memory used by an entities hash table
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Michel Anthony (michelj@samsung.com)
	* @return		void
	* @see			none
	* @remarks		input1: [Create the entities table, N/A] @n
	*				{ xmlEntitiesTablePtr(table) } => { N/A | N/A } @n
	* @b priority	Middle
	* @b etc		none
	*/
static void
UTcxmlFreeEntitiesTableP01()
{
	xmlErrorPtr pError;

	xmlResetLastError();
	xmlEntitiesTablePtr pTable = xmlCreateEntitiesTable();
	DTS_CHECK_NE_MESSAGE("xmlCreateEntitiesTable", (void *)pTable, (void *)NULL, "xmlCreateEntitiesTable Failed");

	/**
	* @remarks   input1: [Create the entities table, N/A] @n
	*            { xmlEntitiesTablePtr pointer } => { N/A | N/A } @n
	*/
	xmlFreeEntitiesTable(pTable);
	pError = xmlGetLastError();
	DTS_CHECK_EQ_MESSAGE("xmlCreateEntitiesTable", (void *)pError, (void *)NULL, "xmlGetLastError Failed");
}

/**    
	* @test			UTcxmlCopyEntitiesTableP01
	* @brief		xmlEntitiesTablePtr	xmlCopyEntitiesTable (xmlEntitiesTablePtr table)
	* @desc			Positive Test for Building a copy of an entity table.
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Michel Anthony (michelj@samsung.com)
	* @return		void
	* @see			none
	* @remarks		input1: [Create the entities table, N/A] @n
	*				{ xmlEntitiesTablePtr(Table) } => { N/A | xmlEntitiesTablePtr pTable } @n
	* @b priority	Middle
	* @b etc		none
	*/
static void
UTcxmlCopyEntitiesTableP01()
{

	xmlEntitiesTablePtr pTable = xmlCreateEntitiesTable();
	DTS_CHECK_NE_MESSAGE("xmlCreateEntitiesTable", (void *)pTable, (void *)NULL, "xmlCreateEntitiesTable Failed");

	/**
	* @remarks   input1: [Create the entities table, N/A] @n
	*            { xmlEntitiesTablePtr pTable } => { N/A | xmlEntitiesTablePtr pTable } @n
	*/
	xmlEntitiesTablePtr pTableNew = xmlCopyEntitiesTable(pTable);
	DTS_CHECK_NE_MESSAGE("xmlCreateEntitiesTable", (void *)pTableNew , (void *)NULL, "xmlCreateEntitiesTable Failed");

	xmlFreeEntitiesTable(pTable);
	xmlFreeEntitiesTable(pTableNew);
}

/**    
	* @test			UTcxmlAddDocEntityP01
	* @brief		xmlEntityPtr xmlAddDocEntity (xmlDocPtr doc, const xmlChar * name, int type, const xmlChar * ExternalID, const xmlChar * SystemID, const xmlChar * content)
	* @desc			Positive Test for Registering a new entity for this document.
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Michel Anthony (michelj@samsung.com)
	* @return		void
	* @see			none
	* @remarks		input1: [xmlDocPtr is retrieved, N/A] @n
	*				{ xmlDocPtr(doc), const xmlChar *  "amp", int(1), const xmlChar * "amp", const xmlChar * "amp", const xmlChar * "amp" } => { N/A | xmlEntityPtr pEntity } @n
	* @b priority	Middle
	* @b etc		none
	*/
static void
UTcxmlAddDocEntityP01()
{

	char		*pName = "amp";
	xmlDocPtr	doc;

	doc = xmlReadMemory("<!DOCTYPE foo []> <foo/>", 24, "test", NULL, 0);

	/**
	* @remarks   input1: [xmlDocPtr is retrieved, N/A] @n
	*            { xmlDocPtr, "amp", 1, "amp", "amp", "amp" } => { N/A | xmlEntityPtr pEntity } @n
	*/
	xmlEntityPtr pEntity = xmlAddDocEntity(doc, (const xmlChar *)pName, 1, (const xmlChar *)pName, (const xmlChar *)pName, (const xmlChar *)pName);
	DTS_CHECK_NE_MESSAGE("xmlAddDocEntity", (void *)pEntity , (void *)NULL, "xmlAddDocEntity Failed");
	
	xmlFreeDoc(doc);
	//xmlFree((void *)pEntity);
}

	/**    
	* @test			UTcxmlAddDocEntityN01
	* @brief		xmlEntityPtr xmlAddDocEntity (xmlDocPtr doc, const xmlChar * name, int type, const xmlChar * ExternalID, const xmlChar * SystemID, const xmlChar * content)
	* @desc			Negative Test for Registering a new entity for this document.
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Michel Anthony (michelj@samsung.com)
	* @return		void
	* @see			none
	* @remarks		input1: [N/A, N/A] @n
	*				{ NULL, const xmlChar * "amp", int(1), const xmlChar * "amp", const xmlChar * "amp", const xmlChar * "amp" } => { N/A | NULL } @n
	* @b priority	Middle
	* @b etc		none
	*/
static void
UTcxmlAddDocEntityN01()
{

	char		*pName = "amp";

	/**
	* @remarks   input1: [N/A, N/A] @n
	*            { NULL, "amp", 1, "amp", "amp", "amp" } => { N/A | NULL } @n
	*/
	xmlEntityPtr pEntity = xmlAddDocEntity(NULL, (const xmlChar *)pName, 1, (const xmlChar *)pName, (const xmlChar *)pName, (const xmlChar *)pName);
	DTS_CHECK_EQ_MESSAGE("xmlAddDocEntity", (void *)pEntity , (void *)NULL, "xmlAddDocEntity Failed");
}

/**    
	* @test			UTcxmlGetDocEntityP01
	* @brief		xmlEntityPtr xmlGetDocEntity (xmlDocPtr doc, const xmlChar * name)
	* @desc			Positive Test to do an entity lookup in the document entity hash table and
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Michel Anthony (michelj@samsung.com)
	* @return		void
	* @see			none
	* @remarks		input1: [xmlDocPtr is retrieved, N/A] @n
	*				{ xmlDocPtr(doc), const xmlChar * "amp" } => { N/A | xmlEntityPtr pEntity } @n
	* @b priority	Middle
	* @b etc		none
	*/
static void
UTcxmlGetDocEntityP01()
{
	char		*pName = "amp";
	xmlDocPtr	doc;

	doc = xmlReadMemory("<!DOCTYPE foo []> <foo/>", 24, "test", NULL, 0);
	/**
	* @remarks   input1: [xmlDocPtr is retrieved, N/A] @n
	*            { xmlDocPtr, "amp" } => { N/A | xmlEntityPtr pEntity } @n
	*/
	xmlEntityPtr pEntity = xmlGetDocEntity(doc, (const xmlChar *)pName);
	DTS_CHECK_NE_MESSAGE("xmlGetDocEntity", (void *)pEntity , (void *)NULL, "xmlGetDocEntity Failed");
	
	xmlFreeDoc(doc);
	//xmlFree((void *)pEntity);
}

/**    
	* @test			UTcxmlGetDocEntityP02
	* @brief		xmlEntityPtr xmlGetDocEntity (xmlDocPtr doc, const xmlChar * name)
	* @desc			Positive Test to do an entity lookup in the document entity hash table and
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Michel Anthony (michelj@samsung.com)
	* @return		void
	* @see			none
	* @remarks		input1: [Register a new entity for the document, N/A] @n
	*				{ xmlDocPtr(doc), const xmlChar * "amp" } => { N/A | xmlEntityPtr pEntity } @n
	* @b priority	Middle
	* @b etc		none
	*/

static void
UTcxmlGetDocEntityP02()
{
	char		*pName = "amp";
	xmlDocPtr	doc;

	doc = xmlReadMemory("<!DOCTYPE foo []> <foo/>", 24, "test", NULL, 0);
	xmlEntityPtr pEntity = xmlAddDocEntity(doc, (const xmlChar *)pName, 1, (const xmlChar *)pName, (const xmlChar *)pName, (const xmlChar *)pName);
	DTS_CHECK_NE_MESSAGE("xmlGetDocEntity", (void *)pEntity , (void *)NULL, "xmlAddDocEntity Failed");

	/**
	* @remarks   input1: [Register a new entity for the document, N/A] @n
	*            { xmlDocPtr, "amp" } => { N/A | xmlEntityPtr pEntity } @n
	*/
	xmlEntityPtr pEntity1 = xmlGetDocEntity(doc, (const xmlChar *)pName);
	DTS_CHECK_NE_MESSAGE("xmlGetDocEntity", (void *)pEntity1 , (void *)NULL, "xmlGetDocEntity Failed");

	xmlFreeDoc(doc);
//	xmlFree((void *)pEntity);
}

/**    
	* @test			UTcxmlGetDocEntityN01
	* @brief		xmlEntityPtr xmlGetDocEntity (xmlDocPtr doc, const xmlChar * name)
	* @desc			Negative Test to do an entity lookup in the document entity hash table and
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Michel Anthony (michelj@samsung.com)
	* @return		void
	* @see			none
	* @remarks		input1: [N/A, N/A] @n
	*				{ NULL, const xmlChar * "invalid" } => { N/A | NULL } @n
	* @b priority	Middle
	* @b etc		none
	*/
static void
UTcxmlGetDocEntityN01()
{
	char		*pName = "invalid";

	/**
	* @remarks   input1: [N/A, N/A] @n
	*            { NULL, "invalid" } => { N/A | NULL } @n
	*/
	xmlEntityPtr pEntity = xmlGetDocEntity(NULL, (const xmlChar *)pName);
	DTS_CHECK_EQ_MESSAGE("xmlGetDocEntity", (void *)pEntity , (void *)NULL, "xmlGetDocEntity Failed");
}

/**    
	* @test			UTcxmlAddDtdEntityN01
	* @brief		xmlEntityPtr xmlAddDtdEntity (xmlDocPtr doc, const xmlChar * name, int type, const xmlChar * ExternalID, const xmlChar * SystemID, const xmlChar * content)
	* @desc			Negative Test for registering a new entity for this document DTD external subset.
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Michel Anthony (michelj@samsung.com)
	* @return		void
	* @see			none
	* @remarks		input1: [xmlAddDtdEntity document is without external subset, N/A] @n
	*				{ xmlDocPtr(doc), const xmlChar * "amp", int(1), const xmlChar * "amp", const xmlChar * "amp", const xmlChar * "amp" } => { N/A | NULL } @n
	* @b priority	Middle
	* @b etc		none
	*/
static void
UTcxmlAddDtdEntityN01()
{

	char		*pName = "amp";
	xmlDocPtr	doc;

	doc = xmlReadMemory("<!DOCTYPE foo []> <foo/>", 24, "test", NULL, 0);

	/**
	* @remarks   input1: [xmlAddDtdEntity document is without external subset, N/A] @n
	*            { xmlDocPtr, "amp", 1, "amp", "amp", "amp" } => { N/A | NULL } @n
	*/
	xmlEntityPtr pEntity = xmlAddDtdEntity(doc, (const xmlChar *)pName, 1, (const xmlChar *)pName, (const xmlChar *)pName, (const xmlChar *)pName);
	DTS_CHECK_EQ_MESSAGE("xmlAddDtdEntity", (void *)pEntity , (void *)NULL, "xmlAddDtdEntity Failed");

	xmlFreeDoc(doc);
}

/**    
	* @test			UTcxmlAddDtdEntityN02
	* @brief		xmlEntityPtr xmlAddDtdEntity (xmlDocPtr doc, const xmlChar * name, int type, const xmlChar * ExternalID, const xmlChar * SystemID, const xmlChar * content)
	* @desc			Negative Test for registering a new entity for this document DTD external subset.
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Michel Anthony (michelj@samsung.com)
	* @return		void
	* @see			none
	* @remarks		input1: [N/A, N/A] @n
	*				{ NULL, const xmlChar * "amp", int(1), const xmlChar * "amp", const xmlChar * "amp", const xmlChar * "amp" } => { N/A | NULL } @n
	* @b priority	Middle
	* @b etc		none
	*/
static void
UTcxmlAddDtdEntityN02()
{

	char		*pName = "amp";

	/**
	* @remarks   input1: [N/A, N/A] @n
	*            { NULL, "amp", 1, "amp", "amp", "amp" } => { N/A | NULL } @n
	*/
	xmlEntityPtr pEntity = xmlAddDtdEntity(NULL, (const xmlChar *)pName, 1, (const xmlChar *)pName, (const xmlChar *)pName, (const xmlChar *)pName);
	DTS_CHECK_EQ_MESSAGE("xmlAddDtdEntity", (void *)pEntity , (void *)NULL, "xmlAddDtdEntity Failed");
}

/**    
	* @test			UTcxmlEntityP01
	* @brief		xmlEntityPtr xmlAddDtdEntity (xmlDocPtr doc, const xmlChar * name, int type, const xmlChar * ExternalID, const xmlChar * SystemID, const xmlChar * content)
					xmlEntityPtr xmlGetDtdEntity	(xmlDocPtr doc, const xmlChar * name)
	* @desc			Positive Test for registering a new entity for this document DTD external subset.
					Positive test to do an entity lookup in the DTD entity hash table
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Michel Anthony (michelj@samsung.com)
	* @return		void
	* @see			none
	* @remarks		input1: [N/A, N/A] @n
	*   			{xmlDocPtr(doc), xmlChar *(name), int(1), const xmlChar *(ExternalID), const xmlChar *(SystemID), const xmlChar *(content)} => {xmlEntityPtr or NULL | N/A} @n
					input2: [N/A, N/A] @n
	*   			{xmlDocPtr(doc), xmlChar *(name)} => {N/A | Returns the corresponding entity found} @n
	* @b priority	Middle
	* @b etc		none
	*/
static void
UTcxmlEntityP01()
{
	char		*pName = "amp";
	xmlDocPtr	doc = NULL;

	doc = xmlReadMemory("<!DOCTYPE foo []> <foo/>", 24, "test", NULL, 0);
	doc->extSubset = xmlNewDtd(NULL, (const xmlChar *)pName, (const xmlChar *)pName, (const xmlChar *)pName);

	xmlEntityPtr pEntity = xmlAddDtdEntity(doc, (const xmlChar *)pName, 1, (const xmlChar *)pName, (const xmlChar *)pName, (const xmlChar *)pName);
	DTS_CHECK_NE_MESSAGE("xmlAddDtdEntity", (void *)pEntity , (void *)NULL, "xmlAddDtdEntity Failed");
	

	xmlEntityPtr pEntity1 = xmlGetDtdEntity(doc, (const xmlChar *)pName);
	DTS_CHECK_NE_MESSAGE("xmlAddDtdEntity", (void *)pEntity1 , (void *)NULL, "xmlAddDtdEntity Failed");
	
	xmlFreeDoc(doc);
//	xmlFree((void *)pEntity);
}

/**    
	* @test			UTcxmlEntityP02
	* @brief		void xmlDumpEntitiesTable (xmlBufferPtr buf, xmlEntitiesTablePtr table)
					void xmlDumpEntityDecl (xmlBufferPtr buf, xmlEntityPtr ent)
	* @desc			Positive Test for dumping the content of the entity table as an XML DTD definition
					Positive test for dumping the content of the entity table as an XML DTD definition
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Michel Anthony (michelj@samsung.com)
	* @return		void
	* @see			none
	* @remarks		input1: [N/A, N/A] @n
	*   			{xmlBufferPtr(buf), xmlEntitiesTablePtr(table)} => {N/A | N/A} @n
					input2: [N/A, N/A] @n
	*   			{xmlBufferPtr(buf), xmlEntityPtr(ent)} => {N/A | N/A} @n
	* @b priority	Middle
	* @b etc		none
	*/
static void
UTcxmlEntityP02()
{
	xmlErrorPtr pError = NULL;
	char		*pName1 = "amp";

	xmlResetLastError();
	xmlBufferPtr buf = xmlBufferCreate();
	xmlEntitiesTablePtr pTable = xmlCreateEntitiesTable();
	xmlDumpEntitiesTable(buf, pTable);
	pError = xmlGetLastError();
	DTS_CHECK_EQ_MESSAGE("UTcxmlEntityP02", (void *)pError , (void *)NULL, "xmlDumpEntityDecl 1 Failed");

	xmlEntityPtr pEntity = xmlGetPredefinedEntity((const xmlChar *)pName1);
	xmlDumpEntityDecl(buf, pEntity);
	pError = xmlGetLastError();
	DTS_CHECK_NE_MESSAGE("UTcxmlEntityP02", (void *)pError , (void *)NULL, "xmlDumpEntityDecl 2 Failed");
	
	xmlBufferFree(buf);
	xmlFreeEntitiesTable(pTable);
}

/**    
	* @test			UTcxmlEntityP03
	* @brief		xmlChar * xmlEncodeSpecialChars (xmlDocPtr doc, const xmlChar * input)
	* @desc			Positive Test to perform a global encoding of a string, replacing the predefined entities this routine is reentrant, and result must be deallocated
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Michel Anthony (michelj@samsung.com)
	* @return		void
	* @see			none
	* @remarks		input1: [N/A, N/A] @n
	*   			{xmlDocPtr(doc), const xmlChar *(input)} => {N/A | Newly allocated string} @n
	* @b priority	Middle
	* @b etc		none
	*/
static void
UTcxmlEntityP03()
{
    xmlDocPtr		doc = NULL;

	doc = xmlNewDoc(BAD_CAST "1.0");  
 	const xmlChar* pSpecial = xmlEncodeSpecialChars(doc, BAD_CAST "text con&tent and <tag>");  
	DTS_CHECK_NE_MESSAGE("xmlEncodeSpecialChars", (void *)pSpecial , (void *)NULL, "xmlGetLastError Failed");
	
	xmlFreeDoc(doc);
	//xmlFree((void *)pSpecial);
	//delete pSpecial;
	//pSpecial = NULL;
	//xmlFree();
}

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

void (*tet_startup)( void) = startup;
void (*tet_cleanup)( void) = cleanup;

struct tet_testlist tet_testlist[] = {
	// Handling of out of context errors
	   {UTcxmlGetPredefinedEntityP01,1},
	   {UTcxmlCreateEntitiesTableP01,2},
	   {UTcxmlFreeEntitiesTableP01,3},
	   {UTcxmlCopyEntitiesTableP01,4},
	   {UTcxmlAddDocEntityP01,5},
	   {UTcxmlAddDocEntityN01,6},
	   {UTcxmlGetDocEntityP01,7},
	   {UTcxmlGetDocEntityP02,8},
	   {UTcxmlGetDocEntityN01,9},
  	   {UTcxmlAddDtdEntityN01,10},
  	   
	   {UTcxmlAddDtdEntityN02,11},
	   {UTcxmlEntityP01,12},
	   {UTcxmlEntityP02,13},
	   {UTcxmlEntityP03,14},
	   { NULL, 0},
	
};
