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


static const char *input1[] = {
	"a", "b", "c",
	"d", "e", "f",
	"g", "h", "i",
	"j", "k", "l",
	NULL
};

static const char *input2[] = {
	"m", "n", "o",
	"p", "q", "r",
	"s", "t", "u",
	"v", "w", "x",
	NULL
};

#define NB_STRINGS_NS 100
#define NB_STRINGS_MAX 500
#define NB_STRINGS_MIN 10

static xmlChar *strings1[NB_STRINGS_MAX];
static xmlChar *strings2[NB_STRINGS_MAX];
static const xmlChar *test1[NB_STRINGS_MAX];
static const xmlChar *test2[NB_STRINGS_MAX];

static int fillStrings(void)
{
	int index1 = 0;
	int index2 = 0;
	int index3 = 0;

    for (index1 = 0; input1[index1] != NULL; index1++) {
		strings1[index1] = xmlStrdup((const xmlChar *) input1[index1]);
		if (strings1[index1] == NULL) {
			goto CATCH;
		}
    }
    for (index2 = 0, index3 = 0; index1 < NB_STRINGS_MAX - NB_STRINGS_NS; index1++,index2++) {
        strings1[index1] = xmlStrncatNew(strings1[index2], strings1[index3], xmlStrlen(strings1[index3]));
		if (strings1[index1] == NULL) {
			goto CATCH;
		}
		if (index2 >= 50) {
	    index2 = 0;
	    index3++;
		}
    }
    for (index2 = 0; (index2 < 50) && (index1 < NB_STRINGS_MAX); index1++, index2+=2) {
        strings1[index1] = xmlStrncatNew(strings1[index2], (const xmlChar *) ":", 1);
		if (strings1[index1] == NULL) {
			 goto CATCH;
		}
    }
    for (index2 = NB_STRINGS_MAX - NB_STRINGS_NS, index3 = 0; index1 < NB_STRINGS_MAX;index1++,index2++) {
        strings1[index1] = xmlStrncatNew(strings1[index2], strings1[index3], xmlStrlen(strings1[index3]));
			if (strings1[index1] == NULL) {
			  goto CATCH;
			}
		index3 += 3;
		if (index3 >= 50)
			index3 = 0;
    }

    /*
     * Now do the same with the second pool of strings
     */
    for (index1 = 0; input2[index1] != NULL; index1++) {
        strings2[index1] = xmlStrdup((const xmlChar *) input2[index1]);
		if (strings2[index1] == NULL) {
			  goto CATCH;
			}
	}
    for (index2 = 0, index3 = 0; index1 < NB_STRINGS_MAX - NB_STRINGS_NS; index1++,index2++) {
        strings2[index1] = xmlStrncatNew(strings2[index2], strings2[index3], xmlStrlen(strings2[index3]));
		if (strings2[index1] == NULL) {
			goto CATCH;
		}
		if (index2 >= 50) {
			index2 = 0;
			index3++;
		}
    }
    for (index2 = 0; (index2 < 50) && (index1 < NB_STRINGS_MAX); index1++, index2+=2) {
        strings2[index1] = xmlStrncatNew(strings2[index2], (const xmlChar *) ":", 1);
			if (strings2[index1] == NULL) {
				goto CATCH;
			}
    }
    for (index2 = NB_STRINGS_MAX - NB_STRINGS_NS, index3 = 0;
         index1 < NB_STRINGS_MAX;index1++,index2++) {
        strings2[index1] = xmlStrncatNew(strings2[index2], strings2[index3], xmlStrlen(strings2[index3]));
		if (strings2[index1] == NULL) {
			 goto CATCH;
			}
		index3 += 3;
		if (index3 >= 50) 
			index3 = 0;
    }
	return XML_TRUE;
CATCH:
	return XML_FALSE;

}

static void 
cleanStrings(void) 
{
    int index;

    for (index = 0; index < NB_STRINGS_MAX; index++) {
        if (strings1[index] != NULL) /* really should not happen */
				xmlFree(strings1[index]);
    }
    for (index = 0; index < NB_STRINGS_MAX; index++) {
        if (strings2[index] != NULL) /* really should not happen */
				xmlFree(strings2[index]);
    }
}
/**    
	* @test			UTcxmlDictP01
	* @brief		const xmlChar *	xmlDictLookup	(xmlDictPtr dict, const xmlChar * name, int len)
					const xmlChar *	xmlDictQLookup (xmlDictPtr dict, const xmlChar * prefix, const xmlChar * name)
					int xmlDictOwns (xmlDictPtr dict, const xmlChar * str)
	* @desc			Positive Test for Adding the @name to the dictionnary @dict if not present
					Positive test for Adding the QName @prefix:@name to the hash @dict if not present
					Positive Test for checking if a string is owned by the disctionary
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Michel Anthony (michelj@samsung.com)
	* @return		void
	* @see			none
	* @remarks		input1: [create a new dictionary, Free the hash dict and its contents] @n
	*   			{xmlDictPtr(dict), xmlChar *(string with index1), length i.e int(-1)} => {N/A |Internal copy of the name or NULL} @n
					input2: [create a new dictionary, Free the hash dict and its contents] @n
	*   			{xmlDictPtr(dict), xmlChar *(string with index2), length of string int(len)} => {N/A |Internal copy of the name or NULL} @n
					input3: [create a new dictionary, Free the hash dict and its contents] @n
	*   			{xmlDictPtr(dict), xmlChar *(string with different index), length of string int(len)} => {N/A |Internal copy of the name or NULL} @n
					input4: [Create a new dictionary, inheriting strings from the read-only dictionnary @sub, N/A]
					{xmlDictPtr(dict), xmlChar*(prefix), xmlChar *(name)} => {N/A |Internal copy of the Qname or NULL} @n
					input5: [Create a new dictionary, N/A]
					{xmlDictPtr(dict), xmlChar *(str)} => {N/A |Internal copy of the Qname or NULL} @n
	* @b priority	Middle
	* @b etc		none
	*/
static void
UTcxmlDictP01()
{
	int				resultVal = 0;
	int				resultVal1 = 0;	
    int				index1 = 0;
	int				index2 = 0;
    xmlDictPtr		dict;
    int				ret = 0;
    xmlChar			prefix[40];
    xmlChar			*pCur = NULL;
	xmlChar			*pRef = NULL;
    const xmlChar	*pTmp = NULL;

LIBXML_TEST_VERSION
	/*
	* Test a single dictionary
	*/
    int res = fillStrings();
	DTS_CHECK_EQ_MESSAGE("xmlDictQLookup", (void *)res, (void *)XML_TRUE, "xmlDictQLookup Failed");

    dict = xmlDictCreate();
	DTS_CHECK_NE_MESSAGE("xmlDictQLookup", (void *)dict, (void *)NULL, "xmlDictQLookup Failed");	

    memset(test1, 0, sizeof(test1));
	resultVal1 = xmlDictSize(dict);
	DTS_CHECK_EQ_MESSAGE("xmlDictQLookup", (void *)resultVal1, (void *)0, "xmlDictQLookup Failed");

    /*
     * Fill in NB_STRINGS_MIN, at this point the dictionary should not grow
     * and we allocate all those doing the fast key computations
     */
    for (index1 = 0;index1 < NB_STRINGS_MIN;index1++) {
        test1[index1] = xmlDictLookup(dict, strings1[index1], -1);
		DTS_CHECK_NE_MESSAGE("xmlDictQLookup", (void *)test1[index1], (void *)NULL, "xmlDictQLookup Failed");    
	}
	DTS_PRINT("xmlDictQLookup", "Loop 1 Done");
    index2 = NB_STRINGS_MAX - NB_STRINGS_NS;
    for (index1 = 0;index1 < NB_STRINGS_MIN;index1++, index2++) {
        test1[index2] = xmlDictLookup(dict, strings1[index2], xmlStrlen(strings1[index2]));
	DTS_CHECK_NE_MESSAGE("xmlDictQLookup", (void *)test1[index2], (void *)NULL, "xmlDictQLookup Failed");
	}
DTS_PRINT("xmlDictQLookup", "Loop 2 Done");
    index2 = NB_STRINGS_MAX - NB_STRINGS_MIN;
    for (index1 = 0;index1 < NB_STRINGS_MIN;index1++, index2++) {
        test1[index2] = xmlDictLookup(dict, strings1[index2], xmlStrlen(strings1[index2]));
		DTS_CHECK_NE_MESSAGE("xmlDictQLookup", (void *)test1[index2] , (void *)NULL, "xmlDictQLookup Failed");
    }
DTS_PRINT("xmlDictQLookup", "Loop 3 Done");
    /*
     * At this point allocate all the strings
     * the dictionary will grow in the process, reallocate more string tables
     * and switch to the better key generator
     */
    for (index1 = 0;index1 < NB_STRINGS_MAX;index1++) {
        if (test1[index1] != NULL)
			continue;
		test1[index1] = xmlDictLookup(dict, strings1[index1], -1);
		DTS_CHECK_NE_MESSAGE("xmlDictQLookup", (void *)test1[index1], (void *)NULL, "xmlDictQLookup Failed");
    }
DTS_PRINT("xmlDictQLookup", "Loop 4 Done");
    /*
     * Now we can start to test things, first that all strings1 belongs to
     * the dict
     */
    for (index1 = 0; index1 < NB_STRINGS_MAX; index1++) {
		int retval = xmlDictOwns(dict, test1[index1]);
		DTS_CHECK_NE_MESSAGE("xmlDictQLookup", (void *)retval, (void *)0, "xmlDictQLookup Failed");
    }

DTS_PRINT("xmlDictQLookup", "Loop 41 Done");

    /*
     * Then that another lookup to the string will return the same
     */
    for (index1 = 0; index1 < NB_STRINGS_MAX; index1++) {
		pTmp = xmlDictLookup(dict, strings1[index1], -1);
		resultVal = xmlStrcmp(pTmp, test1[index1]);
		DTS_CHECK_EQ_MESSAGE("xmlDictQLookup", (void *)resultVal, (void *)0, "xmlDictQLookup Failed");

    }
DTS_PRINT("xmlDictQLookup", "Loop 5 Done");
    /*
     * More complex, check the QName lookups
     */
    for (index1 = NB_STRINGS_MAX - NB_STRINGS_NS;index1 < NB_STRINGS_MAX;index1++) {
        pCur = strings1[index1];
		pRef = &prefix[0];
		while (*pCur != ':') {
			*pRef++ = *pCur++;
		}
		pCur++;
		*pRef = 0;
		pTmp = xmlDictQLookup(dict, &prefix[0], pCur);
		resultVal = xmlStrcmp(pTmp, test1[index1]);

		DTS_CHECK_EQ_MESSAGE("xmlDictQLookup", (void *)resultVal, (void *)0, "xmlDictQLookup Failed");

    }
DTS_PRINT("xmlDictQLookup", "Loop 6 Done");
    xmlDictFree(dict);
    cleanStrings();
}
/**    
	* @test			UTcxmlDictP02
	* @brief		const xmlChar *	xmlDictLookup	(xmlDictPtr dict, const xmlChar * name, int len)
					const xmlChar *	xmlDictQLookup (xmlDictPtr dict, const xmlChar * prefix, const xmlChar * name)
					int xmlDictOwns (xmlDictPtr dict, const xmlChar * str)
	* @desc			Positive Test for Adding the @name to the dictionnary @dict if not present
					Positive test for Adding the QName @prefix:@name to the hash @dict if not present
					Positive Test for checking if a string is owned by the disctionary
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Michel Anthony (michelj@samsung.com)
	* @return		void
	* @see			none
	* @remarks		input1: [create a new dictionary, Free the hash dict and its contents] @n
	*   			{xmlDictPtr(dict), xmlChar*(string with index1), length i.e int(-1)} => {N/A |Internal copy of the name or NULL} @n
					input2: [create a new dictionary, Free the hash dict and its contents] @n
	*   			{xmlDictPtr(dict), xmlChar *(string with index2), length of string int(len)} => {N/A |Internal copy of the name or NULL} @n
					input3: [create a new dictionary, Free the hash dict and its contents] @n
	*   			{xmlDictPtr(dict), xmlChar *(string with different index), length of string int(len)} => {N/A |Internal copy of the name or NULL} @n
					input4: [Create a new dictionary, inheriting strings from the read-only dictionnary @sub, N/A]
					{xmlDictPtr(dict), xmlChar *(string with index1), length i.e int(-1)} => {N/A |Internal copy of the name or NULL} @n
					input5: [Create a new dictionary, inheriting strings from the read-only dictionnary @sub, N/A]
					{xmlDictPtr(dict), xmlChar *(string with index2), length of string INT(LEN)} => {N/A |Internal copy of the name or NULL} @n
					input6: [Create a new dictionary, inheriting strings from the read-only dictionnary @sub, N/A]
					{xmlDictPtr(dict), xmlChar *(string with different index), length of string int(len)} => {N/A |Internal copy of the name or NULL} @n
					input7: [Create a new dictionary, inheriting strings from the read-only dictionnary @sub, N/A]
					{xmlDictPtr(dict), xmlChar* (prefix), xmlChar *(name)} => {N/A |Internal copy of the Qname or NULL} @n
					input8: [Create a new dictionary, N/A]
					{xmlDictPtr(dict), xmlChar *(str)} => {N/A |Internal copy of the Qname or NULL} @n
	* @b priority	Middle
	* @b etc		none
	*/
static void
UTcxmlDictP02()
{

	int				resultVal = 0;
    int				index1 = 0;
	int				index2 = 0;
    xmlDictPtr		dict;
	xmlDictPtr		parent;
    int				ret = 0;
    xmlChar			prefix[40];
    xmlChar			*pCur = NULL;
	xmlChar			*pRef = NULL;
    const xmlChar	*pTmp = NULL;

LIBXML_TEST_VERSION
    int res = fillStrings();
	DTS_ASSERT_MESSAGE("xmlDictQLookup", (res != XML_TRUE), "fillStrings Failed");

    parent = xmlDictCreate();
	DTS_ASSERT_MESSAGE("xmlDictQLookup", (parent == NULL), "xmlDictCreate Failed");

	DTS_ASSERT_MESSAGE("xmlDictQLookup", (xmlDictSize(parent) != 0), "xmlDictSize Failed");

    /*
     * Fill in NB_STRINGS_MIN, at this point the dictionary should not grow
     * and we allocate all those doing the fast key computations
     */
    for (index1 = 0;index1 < NB_STRINGS_MIN;index1++) {
        test1[index1] = xmlDictLookup(parent, strings1[index1], -1);
		DTS_ASSERT_MESSAGE("xmlDictQLookup", (test1[index1] == NULL), "xmlDictQLookup Failed");
    }
	DTS_PRINT("xmlDictQLookup", "Loop 1");
    index2 = NB_STRINGS_MAX - NB_STRINGS_NS;
    for (index1 = 0;index1 < NB_STRINGS_MIN;index1++, index2++) {
        test1[index2] = xmlDictLookup(parent, strings1[index2], xmlStrlen(strings1[index2]));
		DTS_ASSERT_MESSAGE("xmlDictQLookup", (test1[index2] == NULL), "xmlDictQLookup Failed");
    }
	DTS_PRINT("xmlDictQLookup", "Loop 2");
    index2 = NB_STRINGS_MAX - NB_STRINGS_MIN;
    for (index1 = 0;index1 < NB_STRINGS_MIN;index1++, index2++) {
        test1[index2] = xmlDictLookup(parent, strings1[index2], xmlStrlen(strings1[index2]));
		DTS_ASSERT_MESSAGE("xmlDictQLookup", (test1[index2] == NULL), "xmlDictQLookup Failed");
    }
	DTS_PRINT("xmlDictQLookup", "Loop 3");
    /*
     * At this point allocate all the strings
     * the dictionary will grow in the process, reallocate more string tables
     * and switch to the better key generator
     */
    for (index1 = 0;index1 < NB_STRINGS_MAX;index1++) {
        if (test1[index1] != NULL)
			continue;
		test1[index1] = xmlDictLookup(parent, strings1[index1], -1);
		if(test1[index1] == NULL){
		DTS_FAIL("xmlDictQLookup", "xmlDictQLookup Failed");
		}
    }
	DTS_PRINT("xmlDictQLookup", "Loop 4");

	//Create the sub directory from the parent directory
    dict = xmlDictCreateSub(parent);
	DTS_ASSERT_MESSAGE("xmlDictQLookup", (dict==NULL), "xmlDictQLookup Failed");

	DTS_PRINT("xmlDictQLookup", "Loop 5");
    memset(test2, 0, sizeof(test2));
	DTS_ASSERT_MESSAGE("xmlDictQLookup", (xmlDictSize(parent) != xmlDictSize(dict)), "xmlDictQLookup Failed");
	DTS_PRINT("xmlDictQLookup", "Loop 6");
    /*
     * Fill in NB_STRINGS_MIN, at this point the dictionary should not grow
     * and we allocate all those doing the fast key computations
     * All the strings are based on a different seeds subset so we know
     * they are allocated in the main dictionary, not coming from the parent
     */
    for (index1 = 0;index1 < NB_STRINGS_MIN;index1++) {
        test2[index1] = xmlDictLookup(dict, strings2[index1], -1);
		DTS_ASSERT_MESSAGE("xmlDictQLookup", (test2[index1] == NULL), "xmlDictQLookup Failed");
    }
	DTS_PRINT("xmlDictQLookup", "Loop 7");
    index2 = NB_STRINGS_MAX - NB_STRINGS_NS;

    for (index1 = 0;index1 < NB_STRINGS_MIN;index1++, index2++) {
        test2[index2] = xmlDictLookup(dict, strings2[index2], xmlStrlen(strings2[index2]));
		DTS_ASSERT_MESSAGE("xmlDictQLookup", (test2[index2] == NULL), "xmlDictQLookup Failed");
    }
	DTS_PRINT("xmlDictQLookup", "Loop 8");

    index2 = NB_STRINGS_MAX - NB_STRINGS_MIN;
    for (index1 = 0;index1 < NB_STRINGS_MIN;index1++, index2++) {
        test2[index2] = xmlDictLookup(dict, strings2[index2], xmlStrlen(strings2[index2]));
		DTS_ASSERT_MESSAGE("xmlDictQLookup", (test2[index2] == NULL), "xmlDictQLookup Failed");
    }
	DTS_PRINT("xmlDictQLookup", "Loop 9");

    /*
     * At this point allocate all the strings
     * the dictionary will grow in the process, reallocate more string tables
     * and switch to the better key generator
     */
    for (index1 = 0;index1 < NB_STRINGS_MAX;index1++) {
        if (test2[index1] != NULL)
			continue;
		test2[index1] = xmlDictLookup(dict, strings2[index1], -1);
		if (test2[index1] == NULL) {
		DTS_FAIL("xmlDictQLookup", "xmlDictQLookup Failed");
 		}
   }
	DTS_PRINT("xmlDictQLookup", "Loop 10");

    /*
     * Now we can start to test things, first that all strings2 belongs to
     * the dict, and that none of them was actually allocated in the parent
     */
    for (index1 = 0;index1 < NB_STRINGS_MAX;index1++) {
    	if(!xmlDictOwns(dict, test2[index1]))
    	{
    		DTS_FAIL("xmlDictQLookup", "xmlDictQLookup Failed");
    	}
    	if(xmlDictOwns(parent, test2[index1]))
    	{
    		DTS_FAIL("xmlDictQLookup", "xmlDictQLookup Failed");
    	}
    }
	DTS_PRINT("xmlDictQLookup", "Loop 11");
#if 0
    /*
     * Also verify that all strings from the parent are seen from the subdict
     */
    for (index1 = 0; index1 < NB_STRINGS_MAX; index1++) {
		if(!xmlDictOwns(dict, test1[index1])){
			DTS_FAIL("xmlDictQLookup", "xmlDictQLookup Failed");
		}
    }
#endif
	DTS_PRINT("xmlDictQLookup", "Loop 12");
    /*
     * Then that another lookup to the string in sub will return the same
     */
    for (index1 = 0; index1 < NB_STRINGS_MAX; index1++) {
		pTmp = xmlDictLookup(dict, strings2[index1], -1);
		resultVal = xmlStrcmp(pTmp, test2[index1]);
		if(resultVal != 0){
			DTS_FAIL("xmlDictQLookup", "xmlStrcmp Failed");
		}
	}
  	DTS_PRINT("xmlDictQLookup", "Loop 13");
#if 0
	/*
     * But also that any lookup for a string in the parent will be provided
     * as in the parent
     */
    for (index1 = 0; index1 < NB_STRINGS_MAX; index1++) {
		pTmp = xmlDictLookup(dict, strings1[index1], -1);
		resultVal = xmlStrcmp(pTmp, test1[index1]);
		if(resultVal != 0){
			DTS_FAIL("xmlDictQLookup", "xmlStrcmp Failed");
		}
    }
	DTS_PRINT("xmlDictQLookup", "Loop 14");
#endif
    /*
     * check the QName lookups
     */
    for (index1 = NB_STRINGS_MAX - NB_STRINGS_NS; index1 < NB_STRINGS_MAX; index1++) {
        pCur = strings2[index1];
		pRef = &prefix[0];
		while (*pCur != ':') {
			*pRef++ = *pCur++;
		}
		pCur++;
		*pRef = 0;
		pTmp = xmlDictQLookup(dict, &prefix[0], pCur);
		resultVal = xmlStrcmp(pTmp, test2[index1]);
		if(resultVal != 0){
			DTS_FAIL("xmlDictQLookup", "xmlStrcmp Failed");
		}
    }
	DTS_PRINT("xmlDictQLookup", "Loop 15");
#if 0
    /*
     * check the QName lookups for strings from the parent
     */
    for (index1 = NB_STRINGS_MAX - NB_STRINGS_NS;index1 < NB_STRINGS_MAX; index1++) {
        pCur = strings1[index1];
		pRef = &prefix[0];
		while (*pCur != ':') {
			*pRef++ = *pCur++;
		}
		pCur++;
		*pRef = 0;
		pTmp = xmlDictQLookup(dict, &prefix[0], pCur);
		resultVal = xmlStrcmp(pTmp, test1[index1]);
		if(resultVal != 0){
			DTS_FAIL("xmlDictQLookup", "xmlStrcmp Failed");
		}
    }
#endif
	DTS_ASSERT_MESSAGE("xmlDictQLookup", ((xmlDictReference(dict)) != 0), "xmlDictQLookup Failed");
    DTS_PRINT("xmlDictQLookup", "Loop 16");
    DTS_PASS("xmlDictQLookup", "xmlDictQLookup passed");

	xmlDictFree(dict);
	xmlDictFree(parent);
	xmlDictFree(dict);

	//xmlDictFree(parent);

    cleanStrings();

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
	{UTcxmlDictP01,1},
   	{UTcxmlDictP02,2},
	{ NULL, 0 },
	
};
