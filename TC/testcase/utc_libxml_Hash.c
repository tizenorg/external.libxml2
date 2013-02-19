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



#ifdef DEBUG_MEM_LEAK
extern "C"
{
	extern void MemStartSaveCallStack(void);
	extern void MemEndSaveCallStack(void);
	extern void MemPrintCurrentIndex(void);
	extern void MemTraceAllocMemInfo(void);
}
#endif

static int call_tests = 0;

#define gen_nb_xmlHashTablePtr 1
static xmlHashTablePtr gen_xmlHashTablePtr(int no, int nr ATTRIBUTE_UNUSED)
{
	if (no == 0) return(xmlHashCreate(10));
	return(NULL);
}
static void des_xmlHashTablePtr(int no ATTRIBUTE_UNUSED, xmlHashTablePtr val, int nr ATTRIBUTE_UNUSED)
{
	if (val != NULL) {
		xmlHashFree(val, NULL);
	}
}

#define gen_nb_const_xmlChar_ptr 2

static xmlChar *gen_const_xmlChar_ptr(int no, int nr ATTRIBUTE_UNUSED)
{
	if (no == 0) return((xmlChar *) "foo");
	if (no == 1) return((xmlChar *) "<foo/>");
	if (no == 2) return((xmlChar *) "none");
	if (no == 3) return((xmlChar *) " 2ab ");
	return(NULL);
}
static void des_const_xmlChar_ptr(int no ATTRIBUTE_UNUSED, const xmlChar *val ATTRIBUTE_UNUSED, int nr ATTRIBUTE_UNUSED)
{
}

#define gen_nb_xmlHashDeallocator 1
static void
test_xmlHashDeallocator(void *payload ATTRIBUTE_UNUSED, xmlChar *name ATTRIBUTE_UNUSED)
{
}
static void
test_xmlHashScanner(void *payload ATTRIBUTE_UNUSED,void *data ATTRIBUTE_UNUSED, xmlChar *name ATTRIBUTE_UNUSED)
{
}
static xmlHashScanner gen_xmlHashScanner(int no, int nr ATTRIBUTE_UNUSED)
{
	if (no == 0) return(test_xmlHashScanner);
	return(NULL);
}

static xmlHashDeallocator gen_xmlHashDeallocator(int no, int nr ATTRIBUTE_UNUSED)
{
	if (no == 0) return(test_xmlHashDeallocator);
	return(NULL);
}
static void des_xmlHashDeallocator(int no ATTRIBUTE_UNUSED, xmlHashDeallocator val ATTRIBUTE_UNUSED, int nr ATTRIBUTE_UNUSED)
{
}

#define gen_nb_userdata 2

static void *gen_userdata(int no, int nr ATTRIBUTE_UNUSED)
{
	if (no == 0) return((void *) &call_tests);
//    if (no == 0) return(NULL);
	if (no == 1) return((void *) -1);
	return(NULL);
}
static void des_userdata(int no ATTRIBUTE_UNUSED, void *val ATTRIBUTE_UNUSED, int nr ATTRIBUTE_UNUSED)
{
}

static void desret_int(int val ATTRIBUTE_UNUSED)
{
}

static void desret_void_ptr(void *val ATTRIBUTE_UNUSED)
{
}

	/**    
	* @test			UTcXmlHashCreateP01
	* @brief		
	* @desc			
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Michel Anthony (michelj@samsung.com)
	* @return		void
	* @see			none
	* @remarks		
	* @b priority	Middle
	* @b etc		none
	*/

static void
UTcXmlHashCreateP01()
{

	/**
	 * @remarks   input1: [N/A, N/A] @n
	 *            {void} => { N/A | N/A} @n
	 */
	DTS_CHECK_EQ_MESSAGE("UTcXmlHashCreateP01", 1, 1, "UTcXmlHashCreateP01 returned 0");
}

	/**    
	* @test			UTcXmlHashFreeP01
	* @brief		
	* @desc			
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Michel Anthony (michelj@samsung.com)
	* @return		void
	* @see			none
	* @remarks		
	* @b priority	Middle
	* @b etc		none
	*/
static void
UTcXmlHashFreeP01()
{

	/**
	 * @remarks   input1: [N/A, N/A] @n
	 *            {} => { | } @n
	 */
	DTS_CHECK_EQ_MESSAGE("UTcXmlHashFreeP01", 1, 1, "UTcXmlHashFreeP01 returned 0");
	/* missing type support */
}

	/**    
	* @test			UTcXmlHashAddEntryP01
	* @brief		int xmlHashAddEntry (xmlHashTablePtr table, const xmlChar *name, void *userdata)
	* @desc			Positive Test for xmlHashAddEntry
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Michel Anthony (michelj@samsung.com)
	* @return		void
	* @see			none
	* @remarks		input1: [Create table, free the hash table and its contents] @n
	*   			{xmlHashTablePtr(hash table), xmlChar *("foo", "<foo/>", "none", " 2ab " ), userdata} => {N/A | int(0)} @n
	* @b priority	Middle
	* @b etc		none
	*/
static void
UTcXmlHashAddEntryP01()
{
	int ret_val;
	xmlHashTablePtr table; /* the hash table */
	int n_table = 0;
	xmlChar * name; /* the name of the userdata */
	int n_name = 0;
	void * userdata; /* a pointer to the userdata */
	int n_userdata = 0;

	for (n_table = 0;n_table < gen_nb_xmlHashTablePtr;n_table++) {
		for (n_name = 0;n_name < gen_nb_const_xmlChar_ptr;n_name++) {
			for (n_userdata = 0;n_userdata < gen_nb_userdata;n_userdata++) {

				table = gen_xmlHashTablePtr(n_table, 0);
				DTS_CHECK_NE_MESSAGE("xmlHashAddEntry", table, NULL, "gen_xmlHashTablePtr returned NULL");

				name = gen_const_xmlChar_ptr(n_name, 1);
				DTS_CHECK_NE_MESSAGE("xmlHashAddEntry", name, NULL, "gen_const_xmlChar_ptr returned NULL");

				userdata = gen_userdata(n_userdata, 2);
				DTS_CHECK_NE_MESSAGE("xmlHashAddEntry", userdata, NULL, "gen_userdata returned NULL");
				/**
				 * @remarks   input1: [N/A, N/A] @n
				 *            {table of size 10 , userdata name("foo" ,"<foo/>" ,"none"," 2ab )" , userdata} =>@n
				     *			  {N/A | 0} @n
				 */
				ret_val = xmlHashAddEntry(table, (const xmlChar *)name, userdata);
				DTS_CHECK_EQ_MESSAGE("xmlHashAddEntry", ret_val, 0, "xmlHashAddEntry Failed");
				desret_int(ret_val);
				call_tests++;
				des_xmlHashTablePtr(n_table, table, 0);
				des_const_xmlChar_ptr(n_name, (const xmlChar *)name, 1);
				des_userdata(n_userdata, userdata, 2);
				xmlResetLastError();
			}
		}
	}
}
/**    
	* @test			UTcXmlHashUpdateEntryP01
	* @brief		int xmlHashUpdateEntry(xmlHashTablePtr table, const xmlChar *name, void *userdata, xmlHashDeallocator f)
	* @desc			Positive Test for xmlHashUpdateEntry
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Michel Anthony (michelj@samsung.com)
	* @return		void
	* @see			none
	* @remarks		input1: [Create table, free the hash table and its contents] @n
	*   			{xmlHashTablePtr(hash table), xmlChar *("foo", "<foo/>", "none", " 2ab " ), userdata, xmlHashDeallocator} => {N/A | int(NOT -1)} @n
	* @b priority	Middle
	* @b etc		none
	*/
static void
UTcXmlHashUpdateEntryP01()
{
	int ret_val;
	xmlHashTablePtr table; /* the hash table */
	int n_table;
	xmlChar * name; /* the name of the userdata */
	int n_name;
	void * userdata; /* a pointer to the userdata */
	int n_userdata;
	xmlHashDeallocator f; /* the deallocator function for replaced item (if any) */
	int n_f;

	for (n_table = 0;n_table < gen_nb_xmlHashTablePtr;n_table++) {
		for (n_name = 0;n_name < gen_nb_const_xmlChar_ptr;n_name++) {
			for (n_userdata = 0;n_userdata < gen_nb_userdata;n_userdata++) {
				for (n_f = 0;n_f < gen_nb_xmlHashDeallocator;n_f++) {

					table = gen_xmlHashTablePtr(n_table, 0);
					DTS_CHECK_NE_MESSAGE("xmlHashUpdateEntry", table, NULL, "gen_xmlHashTablePtr returned NULL");

					name = gen_const_xmlChar_ptr(n_name, 1);
					DTS_CHECK_NE_MESSAGE("xmlHashUpdateEntry", name, NULL, "gen_const_xmlChar_ptr returned NULL");

					userdata = gen_userdata(n_userdata, 2);
					DTS_CHECK_NE_MESSAGE("xmlHashUpdateEntry", userdata, NULL, "gen_userdata returned NULL");

					f = gen_xmlHashDeallocator(n_f, 3);
					DTS_CHECK_NE_MESSAGE("xmlHashUpdateEntry", userdata, NULL, "gen_xmlHashDeallocator returned NULL");
					
					/**
						 * @remarks   input1: [N/A, N/A] @n
						 *            {table of size 10 , userdata name("foo" ,"<foo/>" ,"none"," 2ab ") , userdata , deallocator} =>@n
					     *			  {N/A | 0} @n
						 */
					ret_val = xmlHashUpdateEntry(table, (const xmlChar *)name, userdata, f);
					DTS_CHECK_EQ_MESSAGE("xmlHashUpdateEntry", ret_val, 0, "xmlHashUpdateEntry Failed");
					

					desret_int(ret_val);
					des_xmlHashTablePtr(n_table, table, 0);
					des_const_xmlChar_ptr(n_name, (const xmlChar *)name, 1);
					des_userdata(n_userdata, userdata, 2);
					des_xmlHashDeallocator(n_f, f, 3);
					xmlResetLastError();
				}
			}
		}
	}
}
/**    
	* @test			UTcXmlHashAddEntry2P01
	* @brief		int xmlHashAddEntry2(xmlHashTablePtr table, const xmlChar *name, const xmlChar *name2, void *userdata)
	* @desc			Positive Test for xmlHashAddEntry2
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Michel Anthony (michelj@samsung.com)
	* @return		void
	* @see			none
	* @remarks		input1: [Create table, free the hash table and its contents] @n
	*   			{xmlHashTablePtr(hash table), xmlChar *("foo", "<foo/>", "none", " 2ab " ), xmlChar *("foo", "<foo/>", "none", " 2ab " ), userdata, xmlHashDeallocator} => {N/A | int(NOT -1)} @n
	* @b priority	Middle
	* @b etc		none
	*/
static void
UTcXmlHashAddEntry2P01()
{
	int ret_val;
	xmlHashTablePtr table; /* the hash table */
	int n_table;
	xmlChar * name; /* the name of the userdata */
	int n_name;
	xmlChar * name2; /* a second name of the userdata */
	int n_name2;
	void * userdata; /* a pointer to the userdata */
	int n_userdata;

	for (n_table = 0;n_table < gen_nb_xmlHashTablePtr;n_table++) {
		for (n_name = 0;n_name < gen_nb_const_xmlChar_ptr;n_name++) {
			for (n_name2 = 0;n_name2 < gen_nb_const_xmlChar_ptr;n_name2++) {
				for (n_userdata = 0;n_userdata < gen_nb_userdata;n_userdata++) {
					table = gen_xmlHashTablePtr(n_table, 0);
					DTS_CHECK_NE_MESSAGE("xmlHashAddEntry2", table, NULL, "hash table NULL");
					name = gen_const_xmlChar_ptr(n_name, 1);
					DTS_CHECK_NE_MESSAGE("xmlHashAddEntry2", name, NULL, "userdata NULL");
					name2 = gen_const_xmlChar_ptr(n_name2, 2);
					DTS_CHECK_NE_MESSAGE("xmlHashAddEntry2", name2, NULL, "userdata NULL");
					userdata = gen_userdata(n_userdata, 3);
					DTS_CHECK_NE_MESSAGE("xmlHashAddEntry2", userdata, NULL, "pointer to the userdata is NULL");
					/**
					 * @remarks   input1: [N/A, N/A] @n
					 *            {table of size 10 , userdata name("foo" ,"<foo/>" ,"none"," 2ab ") , @n
					 *			  userdata name2("foo" ,"<foo/>" ,"none"," 2ab ") ,userdata , deallocator} =>@n
					*        		  {N/A | 0} @n
					 */
					ret_val = xmlHashAddEntry2(table, (const xmlChar *)name, (const xmlChar *)name2, userdata);
					DTS_CHECK_EQ_MESSAGE("xmlHashAddEntry2", ret_val, 0, "xmlHashAddEntry2 Failed");
					desret_int(ret_val);
					des_xmlHashTablePtr(n_table, table, 0);
					des_const_xmlChar_ptr(n_name, (const xmlChar *)name, 1);
					des_const_xmlChar_ptr(n_name2, (const xmlChar *)name2, 2);
					des_userdata(n_userdata, userdata, 3);
				}
			}
		}
	}
}
/**    
	* @test			UTcXmlHashUpdateEntry2P01
	* @brief		int xmlHashUpdateEntry2(xmlHashTablePtr table, const xmlChar *name, const xmlChar *name2, void *userdata, xmlHashDeallocator f) 
	* @desc			Positive Test for xmlHashUpdateEntry2
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Michel Anthony (michelj@samsung.com)
	* @return		void
	* @see			none
	* @remarks		input1: [Create table, free the hash table and its contents] @n
	*   			{xmlHashTablePtr(hash table), xmlChar *("foo", "<foo/>", "none", " 2ab " ), xmlChar *("foo", "<foo/>", "none", " 2ab " ), userdata, xmlHashDeallocator} => {N/A | int(NOT -1)} @n
	* @b priority	Middle
	* @b etc		none
	*/
static void
UTcXmlHashUpdateEntry2P01()
{
	int ret_val;
	xmlHashTablePtr table; /* the hash table */
	int n_table;
	xmlChar * name; /* the name of the userdata */
	int n_name;
	xmlChar * name2; /* a second name of the userdata */
	int n_name2;
	void * userdata; /* a pointer to the userdata */
	int n_userdata;
	xmlHashDeallocator f; /* the deallocator function for replaced item (if any) */
	int n_f;

	for (n_table = 0;n_table < gen_nb_xmlHashTablePtr;n_table++) {
		for (n_name = 0;n_name < gen_nb_const_xmlChar_ptr;n_name++) {
			for (n_name2 = 0;n_name2 < gen_nb_const_xmlChar_ptr;n_name2++) {
				for (n_userdata = 0;n_userdata < gen_nb_userdata;n_userdata++) {
					for (n_f = 0;n_f < gen_nb_xmlHashDeallocator;n_f++) {
						table = gen_xmlHashTablePtr(n_table, 0);
						DTS_CHECK_NE_MESSAGE("xmlHashUpdateEntry2", table, NULL, "hash table is NULL");
						name = gen_const_xmlChar_ptr(n_name, 1);
						DTS_CHECK_NE_MESSAGE("xmlHashUpdateEntry2", name, NULL, "userdata is NULL");
						name2 = gen_const_xmlChar_ptr(n_name2, 2);
						DTS_CHECK_NE_MESSAGE("xmlHashUpdateEntry2", name2, NULL, "userdata is NULL");
						userdata = gen_userdata(n_userdata, 3);
						DTS_CHECK_NE_MESSAGE("xmlHashUpdateEntry2", userdata, NULL, "pointer to the userdata is NULL");
						f = gen_xmlHashDeallocator(n_f, 4);
						DTS_CHECK_NE_MESSAGE("xmlHashUpdateEntry2", f, NULL, "gen_xmlHashDeallocator returned NULL");
						/**
						 * @remarks   input1: [N/A, N/A] @n
						 *            {table of size 10 , userdata name("foo" ,"<foo/>" ,"none"," 2ab ") ,userdata , deallocator} =>@n
						 *			  {N/A | 0} @n
						 */
						ret_val = xmlHashUpdateEntry2(table, (const xmlChar *)name, (const xmlChar *)name2, userdata, f);
						DTS_CHECK_EQ_MESSAGE("xmlHashUpdateEntry2", ret_val, 0, "xmlHashUpdateEntry2 Failed");
						desret_int(ret_val);
						des_xmlHashTablePtr(n_table, table, 0);
						des_const_xmlChar_ptr(n_name, (const xmlChar *)name, 1);
						des_const_xmlChar_ptr(n_name2, (const xmlChar *)name2, 2);
						des_userdata(n_userdata, userdata, 3);
						des_xmlHashDeallocator(n_f, f, 4);
						xmlResetLastError();
					}
				}
			}
		}
	}
}
/**    
	* @test			UTcXmlHashAddEntry3P01
	* @brief		int xmlHashAddEntry3(xmlHashTablePtr table, const xmlChar *name, const xmlChar *name2, const xmlChar *name3, void *userdata) 
	* @desc			Positive Test for xmlHashAddEntry3
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Michel Anthony (michelj@samsung.com)
	* @return		void
	* @see			none
	* @remarks		input1: [Create table, free the hash table and its contents] @n
	*   			{xmlHashTablePtr(hash table), xmlChar *("foo", "<foo/>", "none", " 2ab " ), xmlChar *("foo", "<foo/>", "none", " 2ab " ), xmlChar *("foo", "<foo/>", "none", " 2ab " ), userdata} => {N/A | int(NOT -1)} @n
	* @b priority	Middle
	* @b etc		none
	*/
static void
UTcXmlHashAddEntry3P01()
{
	int ret_val;
	xmlHashTablePtr table; /* the hash table */
	int n_table;
	xmlChar * name; /* the name of the userdata */
	int n_name;
	xmlChar * name2; /* a second name of the userdata */
	int n_name2;
	xmlChar * name3; /* a third name of the userdata */
	int n_name3;
	void * userdata; /* a pointer to the userdata */
	int n_userdata;

	for (n_table = 0;n_table < gen_nb_xmlHashTablePtr;n_table++) {
		for (n_name = 0;n_name < gen_nb_const_xmlChar_ptr;n_name++) {
			for (n_name2 = 0;n_name2 < gen_nb_const_xmlChar_ptr;n_name2++) {
				for (n_name3 = 0;n_name3 < gen_nb_const_xmlChar_ptr;n_name3++) {
					for (n_userdata = 0;n_userdata < gen_nb_userdata;n_userdata++) {
						table = gen_xmlHashTablePtr(n_table, 0);
						DTS_CHECK_NE_MESSAGE("xmlHashAddEntry3", table, NULL, "hash table is NULL");
						name = gen_const_xmlChar_ptr(n_name, 1);
						DTS_CHECK_NE_MESSAGE("xmlHashAddEntry3", name, NULL, "userdata is NULL");
						name2 = gen_const_xmlChar_ptr(n_name2, 2);
						DTS_CHECK_NE_MESSAGE("xmlHashAddEntry3", name2, NULL, "userdata is NULL");
						name3 = gen_const_xmlChar_ptr(n_name3, 3);
						DTS_CHECK_NE_MESSAGE("xmlHashAddEntry3", name3, NULL, "userdata is NULL");
						userdata = gen_userdata(n_userdata, 3);
						DTS_CHECK_NE_MESSAGE("xmlHashAddEntry3", userdata, NULL, "pointer to the userdata is NULL");
						
						/**
						 * @remarks   input1: [N/A, N/A] @n
						 *            {table of size 10 , userdata name("foo" ,"<foo/>" ,"none"," 2ab ") ,@n
						 *			   userdata name2("foo" ,"<foo/>" ,"none"," 2ab ") , userdata name3("foo" ,"<foo/>" ,"none"," 2ab " )@n
						 *			   userdata , deallocator} => {N/A | 0} @n
						 */
						ret_val = xmlHashAddEntry3(table, (const xmlChar *)name, (const xmlChar *)name2, (const xmlChar *)name3, userdata);
						DTS_CHECK_EQ_MESSAGE("xmlHashAddEntry3", ret_val, 0, "xmlHashAddEntry3 Failed");
						desret_int(ret_val);
						des_xmlHashTablePtr(n_table, table, 0);
						des_const_xmlChar_ptr(n_name, (const xmlChar *)name, 1);
						des_const_xmlChar_ptr(n_name2, (const xmlChar *)name2, 2);
						des_const_xmlChar_ptr(n_name3, (const xmlChar *)name3, 3);
						des_userdata(n_userdata, userdata, 4);
						xmlResetLastError();
					}
				}
			}
		}
	}
}
	/**    
	* @test			UTcXmlHashUpdateEntry3P01
	* @brief		int xmlHashUpdateEntry3(xmlHashTablePtr table, const xmlChar *name, const xmlChar *name2, const xmlChar *name3, void *userdata, xmlHashDeallocator f)
	* @desc			Positive Test for xmlHashUpdateEntry3
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Michel Anthony (michelj@samsung.com)
	* @return		void
	* @see			none
	* @remarks		input1: [Create table, free the hash table and its contents] @n
	*   			{xmlHashTablePtr(hash table), xmlChar *("foo", "<foo/>", "none", " 2ab " ), xmlChar *("foo", "<foo/>", "none", " 2ab " ), xmlChar *("foo", "<foo/>", "none", " 2ab " ), userdata, xmlHashDeallocator} => {N/A | int(NOT -1)} @n
	* @b priority	Middle
	* @b etc		none
	*/
static void
UTcXmlHashUpdateEntry3P01()
{
	int ret_val;
	xmlHashTablePtr table; /* the hash table */
	int n_table;
	xmlChar * name; /* the name of the userdata */
	int n_name;
	xmlChar * name2; /* a second name of the userdata */
	int n_name2;
	xmlChar * name3; /* a third name of the userdata */
	int n_name3;
	void * userdata; /* a pointer to the userdata */
	int n_userdata;
	xmlHashDeallocator f; /* the deallocator function for replaced item (if any) */
	int n_f;

	for (n_table = 0;n_table < gen_nb_xmlHashTablePtr;n_table++) {
		for (n_name = 0;n_name < gen_nb_const_xmlChar_ptr;n_name++) {
			for (n_name2 = 0;n_name2 < gen_nb_const_xmlChar_ptr;n_name2++) {
				for (n_name3 = 0;n_name3 < gen_nb_const_xmlChar_ptr;n_name3++) {
					for (n_userdata = 0;n_userdata < gen_nb_userdata;n_userdata++) {
						for (n_f = 0;n_f < gen_nb_xmlHashDeallocator;n_f++) {
							table = gen_xmlHashTablePtr(n_table, 0);
							DTS_CHECK_NE_MESSAGE("xmlHashAddEntry3", table, NULL, "hash table is NULL");
							name = gen_const_xmlChar_ptr(n_name, 1);
							DTS_CHECK_NE_MESSAGE("xmlHashAddEntry3", name, NULL, "userdata is NULL");
							name2 = gen_const_xmlChar_ptr(n_name2, 2);
							DTS_CHECK_NE_MESSAGE("xmlHashAddEntry3", name2, NULL, "userdata is NULL");
							name3 = gen_const_xmlChar_ptr(n_name3, 3);
							DTS_CHECK_NE_MESSAGE("xmlHashAddEntry3", name3, NULL, "userdata is NULL");
							userdata = gen_userdata(n_userdata, 3);
							DTS_CHECK_NE_MESSAGE("xmlHashAddEntry3", userdata, NULL, "pointer to the userdata is NULL");
							f = gen_xmlHashDeallocator(n_f, 5);
							DTS_CHECK_NE_MESSAGE("xmlHashAddEntry3", f, NULL, "gen_xmlHashDeallocator returned NULL");
							/**
							    * @remarks   input1: [N/A, N/A] @n
							    *            {table of size 10 , userdata name("foo" ,"<foo/>" ,"none"," 2ab ") , @n
							    *			  userdata name2("foo" ,"<foo/>" ,"none"," 2ab ") , userdata name3("foo" ,"<foo/>" ,"none"," 2ab ") @n
							    *			  userdata , deallocator} => {N/A | 0} @n
							    */
							ret_val = xmlHashUpdateEntry3(table, (const xmlChar *)name, (const xmlChar *)name2, (const xmlChar *)name3, userdata, f);
							DTS_CHECK_EQ_MESSAGE("xmlHashUpdateEntry3", ret_val, 0, "xmlHashUpdateEntry3 Failed");
							desret_int(ret_val);
							des_xmlHashTablePtr(n_table, table, 0);
							des_const_xmlChar_ptr(n_name, (const xmlChar *)name, 1);
							des_const_xmlChar_ptr(n_name2, (const xmlChar *)name2, 2);
							des_const_xmlChar_ptr(n_name3, (const xmlChar *)name3, 3);
							des_userdata(n_userdata, userdata, 4);
							des_xmlHashDeallocator(n_f, f, 5);
							xmlResetLastError();
						}
					}
				}
			}
		}
	}
}
/**    
	* @test			UTcXmlHashRemoveEntryP01
	* @brief		int xmlHashRemoveEntry(xmlHashTablePtr table, const xmlChar *name, xmlHashDeallocator f)
	* @desc			Positive Test for xmlHashRemoveEntry
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Michel Anthony (michelj@samsung.com)
	* @return		void
	* @see			none
	* @remarks		input1: [Create table, free the hash table and its contents] @n
	*   			{xmlHashTablePtr(hash table), xmlChar *("foo", "<foo/>", "none", " 2ab " ), userdata, xmlHashDeallocator} => {N/A | int(0)} @n
	* @b priority	Middle
	* @b etc		none
	*/
static void
UTcXmlHashRemoveEntryP01()
{
	int ret_val;
	xmlHashTablePtr table; /* the hash table */
	int n_table;
	xmlChar * name; /* the name of the userdata */
	int n_name;
	xmlHashDeallocator f; /* the deallocator function for removed item (if any) */
	int n_f;

	for (n_table = 0;n_table < gen_nb_xmlHashTablePtr;n_table++) {
		for (n_name = 0;n_name < gen_nb_const_xmlChar_ptr;n_name++) {
			for (n_f = 0;n_f < gen_nb_xmlHashDeallocator;n_f++) {
				table = gen_xmlHashTablePtr(n_table, 0);
				DTS_CHECK_NE_MESSAGE("xmlHashRemoveEntry", table, NULL, "hash table is NULL");
				name = gen_const_xmlChar_ptr(n_name, 1);
				DTS_CHECK_NE_MESSAGE("xmlHashRemoveEntry", name, NULL, "userdata is NULL");
				f = gen_xmlHashDeallocator(n_f, 5);
				DTS_CHECK_NE_MESSAGE("xmlHashRemoveEntry", f, NULL, "gen_xmlHashDeallocator returned NULL");
				
				/**
				 * @remarks   input1: [N/A, N/A] @n
				 *            {table of size 10 , userdata name("foo" ,"<foo/>" ,"none"," 2ab ") , @n
				 *			  deallocator} => {N/A | 0} @n
				 */

				ret_val = xmlHashAddEntry(table, (const xmlChar *)name, "NULL");
				DTS_CHECK_EQ_MESSAGE("xmlHashRemoveEntry", ret_val, 0, "xmlHashAddEntry Failed");
				ret_val = xmlHashRemoveEntry(table, (const xmlChar *)name, f);
				DTS_CHECK_EQ_MESSAGE("xmlHashRemoveEntry", ret_val, 0, "xmlHashRemoveEntry Failed");
				desret_int(ret_val);
				des_xmlHashTablePtr(n_table, table, 0);
				des_const_xmlChar_ptr(n_name, (const xmlChar *)name, 1);
				des_xmlHashDeallocator(n_f, f, 2);
				xmlResetLastError();
			}
		}
	}
}
/**    
	* @test			UTcXmlHashRemoveEntry2P01
	* @brief		int xmlHashRemoveEntry2(xmlHashTablePtr table, const xmlChar *name, const xmlChar *name2, xmlHashDeallocator f)
	* @desc			Positive Test for xmlHashRemoveEntry2
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Michel Anthony (michelj@samsung.com)
	* @return		void
	* @see			none
	* @remarks		input1: [Create table, free the hash table and its contents] @n
	*   			{xmlHashTablePtr(hash table), xmlChar *("foo", "<foo/>", "none", " 2ab " ), xmlChar *("foo", "<foo/>", "none", " 2ab " ), xmlHashDeallocator} => {N/A | int(NOT -1)} @n
	* @b priority	Middle
	* @b etc		none
	*/
static void
UTcXmlHashRemoveEntry2P01()
{
	int ret_val;
	xmlHashTablePtr table; /* the hash table */
	int n_table;
	xmlChar * name; /* the name of the userdata */
	int n_name;
	xmlChar * name2; /* a second name of the userdata */
	int n_name2;
	xmlHashDeallocator f; /* the deallocator function for removed item (if any) */
	int n_f;

	for (n_table = 0;n_table < gen_nb_xmlHashTablePtr;n_table++) {
		for (n_name = 0;n_name < gen_nb_const_xmlChar_ptr;n_name++) {
			for (n_name2 = 0;n_name2 < gen_nb_const_xmlChar_ptr;n_name2++) {
				for (n_f = 0;n_f < gen_nb_xmlHashDeallocator;n_f++) {
					table = gen_xmlHashTablePtr(n_table, 0);
					DTS_CHECK_NE_MESSAGE("xmlHashRemoveEntry2", table, NULL, "hash table is NULL");
					name = gen_const_xmlChar_ptr(n_name, 1);
					DTS_CHECK_NE_MESSAGE("xmlHashRemoveEntry2", name, NULL, "userdata is NULL");
					name2 = gen_const_xmlChar_ptr(n_name2, 2);
					DTS_CHECK_NE_MESSAGE("xmlHashRemoveEntry2", name2, NULL, "userdata is NULL");
					f = gen_xmlHashDeallocator(n_f, 5);
					DTS_CHECK_NE_MESSAGE("xmlHashRemoveEntry2", f, NULL, "gen_xmlHashDeallocator returned NULL");					
					/**
						 * @remarks   input1: [N/A, N/A] @n
						 *            {table of size 10 , userdata name("foo" ,"<foo/>" ,"none"," 2ab ") , @n
						 *			  userdata name2("foo" ,"<foo/>" ,"none"," 2ab ") , deallocator} => {N/A | 0} @n
						 */
					ret_val = xmlHashAddEntry2(table, (const xmlChar *)name, (const xmlChar *)name2, "NULL");
					DTS_CHECK_EQ_MESSAGE("xmlHashAddEntry2", ret_val, 0, "xmlHashAddEntry2 Failed");
					
					ret_val = xmlHashRemoveEntry2(table, (const xmlChar *)name, (const xmlChar *)name2, f);
					DTS_CHECK_EQ_MESSAGE("xmlHashRemoveEntry2", ret_val, 0, "xmlHashRemoveEntry2 Failed");
					desret_int(ret_val);
					des_xmlHashTablePtr(n_table, table, 0);
					des_const_xmlChar_ptr(n_name, (const xmlChar *)name, 1);
					des_const_xmlChar_ptr(n_name2, (const xmlChar *)name2, 2);
					des_xmlHashDeallocator(n_f, f, 3);
					xmlResetLastError();
				}
			}
		}
	}
}

	/**    
	* @test			UTcXmlHashRemoveEntry3P01
	* @brief		int xmlHashRemoveEntry3(xmlHashTablePtr table, const xmlChar *name, const xmlChar *name2, const xmlChar *name3, xmlHashDeallocator f)
	* @desc			Positive Test for xmlHashRemoveEntry3
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Michel Anthony (michelj@samsung.com)
	* @return		void
	* @see			none
	* @remarks		input1: [Create table, free the hash table and its contents] @n
	*   			{xmlHashTablePtr(hash table), xmlChar *("foo", "<foo/>", "none", " 2ab " ), xmlChar *("foo", "<foo/>", "none", " 2ab " ), xmlChar *("foo", "<foo/>", "none", " 2ab " ), xmlHashDeallocator} => {N/A | int(NOT -1)} @n
	* @b priority	Middle
	* @b etc		none
	*/
static void
UTcXmlHashRemoveEntry3P01()
{
	int ret_val;
	xmlHashTablePtr table; /* the hash table */
	int n_table;
	xmlChar * name; /* the name of the userdata */
	int n_name;
	xmlChar * name2; /* a second name of the userdata */
	int n_name2;
	xmlChar * name3; /* a third name of the userdata */
	int n_name3;
	xmlHashDeallocator f; /* the deallocator function for removed item (if any) */
	int n_f;

	for (n_table = 0;n_table < gen_nb_xmlHashTablePtr;n_table++) {
		for (n_name = 0;n_name < gen_nb_const_xmlChar_ptr;n_name++) {
			for (n_name2 = 0;n_name2 < gen_nb_const_xmlChar_ptr;n_name2++) {
				for (n_name3 = 0;n_name3 < gen_nb_const_xmlChar_ptr;n_name3++) {
					for (n_f = 0;n_f < gen_nb_xmlHashDeallocator;n_f++) {
						table = gen_xmlHashTablePtr(n_table, 0);
						DTS_CHECK_NE_MESSAGE("xmlHashRemoveEntry3", table, NULL, "hash table is NULL");
						name = gen_const_xmlChar_ptr(n_name, 1);
						DTS_CHECK_NE_MESSAGE("xmlHashRemoveEntry3", name, NULL, "userdata is NULL");
						name2 = gen_const_xmlChar_ptr(n_name2, 2);
						DTS_CHECK_NE_MESSAGE("xmlHashRemoveEntry3", name2, NULL, "userdata is NULL");
						name3 = gen_const_xmlChar_ptr(n_name3, 3);
						DTS_CHECK_NE_MESSAGE("xmlHashRemoveEntry3", name3, NULL, "userdata is NULL");
						f = gen_xmlHashDeallocator(n_f, 5);
						DTS_CHECK_NE_MESSAGE("xmlHashRemoveEntry3", f, NULL, "gen_xmlHashDeallocator returned NULL");						
						/**
						 * @remarks   input1: [N/A, N/A] @n
						 *            {table of size 10 , userdata name("foo" ,"<foo/>" ,"none"," 2ab ") , @n
						 *			  userdata name2("foo" ,"<foo/>" ,"none"," 2ab ") , userdata name3("foo" ,"<foo/>" ,"none"," 2ab ") @n
						 *			  deallocator} => {N/A | 0} @n
						 */

						ret_val = xmlHashAddEntry3(table, (const xmlChar *)name, (const xmlChar *)name2, (const xmlChar *)name3, "NULL");
						DTS_CHECK_EQ_MESSAGE("xmlHashRemoveEntry3", ret_val, 0, "xmlHashAddEntry3 Failed");
						
						ret_val = xmlHashRemoveEntry3(table, (const xmlChar *)name, (const xmlChar *)name2, (const xmlChar *)name3, f);
						DTS_CHECK_EQ_MESSAGE("xmlHashRemoveEntry3", ret_val, 0, "xmlHashRemoveEntry3 Failed");
						desret_int(ret_val);
						des_xmlHashTablePtr(n_table, table, 0);
						des_const_xmlChar_ptr(n_name, (const xmlChar *)name, 1);
						des_const_xmlChar_ptr(n_name2, (const xmlChar *)name2, 2);
						des_const_xmlChar_ptr(n_name3, (const xmlChar *)name3, 3);
						des_xmlHashDeallocator(n_f, f, 4);
						xmlResetLastError();
					}
				}
			}
		}
	}
}
	/**    
	* @test			UTcXmlHashLookupP01
	* @brief		void *xmlHashLookup(xmlHashTablePtr table, const xmlChar *name)
	* @desc			Positive Test for xmlHashLookup
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Michel Anthony (michelj@samsung.com)
	* @return		void
	* @see			none
	* @remarks		input1: [Create table, free the hash table and its contents] @n
	*   			{xmlHashTablePtr(hash table), xmlChar *("foo", "<foo/>", "none", " 2ab " )} => {N/A | int(NOT -1)} @n
	* @b priority	Middle
	* @b etc		none
	*/
static void
UTcXmlHashLookupP01()
{
	void * ret_val;
	xmlHashTablePtr table; /* the hash table */
	int n_table;
	xmlChar * name; /* the name of the userdata */
	int n_name;

	for (n_table = 0;n_table < gen_nb_xmlHashTablePtr;n_table++) {
		for (n_name = 0;n_name < gen_nb_const_xmlChar_ptr;n_name++) {
			table = gen_xmlHashTablePtr(n_table, 0);
			DTS_CHECK_NE_MESSAGE("xmlHashLookup", table, NULL, "hash table is NULL");
			name = gen_const_xmlChar_ptr(n_name, 1);
			DTS_CHECK_NE_MESSAGE("xmlHashLookup", name, NULL, "userdata is NULL");			
			/**
			   	 * @remarks   input1: [N/A, N/A] @n
				 *            {table of size 10 , userdata name("foo" ,"<foo/>" ,"none"," 2ab ") } @n
				 *			   => {N/A | void pointer} @n
				 */
			ret_val = xmlHashLookup(table, (const xmlChar *)name);
			DTS_CHECK_EQ_MESSAGE("xmlHashLookup", ret_val, 0, "xmlHashLookup Failed");
			desret_void_ptr(ret_val);
			des_xmlHashTablePtr(n_table, table, 0);
			des_const_xmlChar_ptr(n_name, (const xmlChar *)name, 1);
			xmlResetLastError();
		}
	}
}
/**    
	* @test			UTcXmlHashLookup2P01
	* @brief		void * xmlHashLookup2(xmlHashTablePtr table, const xmlChar *name, const xmlChar *name2) 
	* @desc			Positive Test for xmlHashLookup2
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Michel Anthony (michelj@samsung.com)
	* @return		void
	* @see			none
	* @remarks		input1: [Create table, free the hash table and its contents] @n
	*   			{xmlHashTablePtr(hash table), xmlChar *("foo", "<foo/>", "none", " 2ab " ), xmlChar *("foo", "<foo/>", "none", " 2ab " )} => {N/A | void*(NOT NULL)} @n
	* @b priority	Middle
	* @b etc		none
	*/
static void UTcXmlHashLookup2P01()
{
	void * ret_val;
	xmlHashTablePtr table; /* the hash table */
	int n_table;
	xmlChar * name; /* the name of the userdata */
	int n_name;
	xmlChar * name2; /* a second name of the userdata */
	int n_name2;

	for (n_table = 0;n_table < gen_nb_xmlHashTablePtr;n_table++) {
		for (n_name = 0;n_name < gen_nb_const_xmlChar_ptr;n_name++) {
			for (n_name2 = 0;n_name2 < gen_nb_const_xmlChar_ptr;n_name2++) {
				table = gen_xmlHashTablePtr(n_table, 0);
				DTS_CHECK_NE_MESSAGE("xmlHashLookup2", table, NULL, "hash table is NULL");
				name = gen_const_xmlChar_ptr(n_name, 1);
				DTS_CHECK_NE_MESSAGE("xmlHashLookup2", name, NULL, "userdata is NULL");
				name2 = gen_const_xmlChar_ptr(n_name2, 2);
				DTS_CHECK_NE_MESSAGE("xmlHashLookup2", name2, NULL, "userdata is NULL");				
				/**
					 * @remarks   input1: [N/A, N/A] @n
				     *            {table of size 10 , userdata name("foo" ,"<foo/>" ,"none"," 2ab ")
					 *			  userdata name2("foo" ,"<foo/>" ,"none"," 2ab ")} => {N/A | void pointer} @n
				     */
				ret_val = xmlHashLookup2(table, (const xmlChar *)name, (const xmlChar *)name2);
				DTS_CHECK_EQ_MESSAGE("xmlHashLookup2", ret_val, 0, "xmlHashLookup2 Failed");
				desret_void_ptr(ret_val);
				des_xmlHashTablePtr(n_table, table, 0);
				des_const_xmlChar_ptr(n_name, (const xmlChar *)name, 1);
				des_const_xmlChar_ptr(n_name2, (const xmlChar *)name2, 2);
				xmlResetLastError();
			}
		}
	}
}
/**    
	* @test			UTcXmlHashLookup3P01
	* @brief		void *xmlHashLookup3(xmlHashTablePtr table, const xmlChar *name, const xmlChar *name2, const xmlChar *name3)
	* @desc			Positive Test for xmlHashLookup3
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Michel Anthony (michelj@samsung.com)
	* @return		void
	* @see			none
	* @remarks		input1: [Create table, free the hash table and its contents] @n
	*   			{xmlHashTablePtr(hash table), xmlChar *("foo", "<foo/>", "none", " 2ab " ), xmlChar *("foo", "<foo/>", "none", " 2ab " ), xmlChar *("foo", "<foo/>", "none", " 2ab " )} => {N/A | void*(NOT NULL)} @n
	* @b priority	Middle
	* @b etc		none
	*/
static void
UTcXmlHashLookup3P01()
{
	void * ret_val;
	xmlHashTablePtr table; /* the hash table */
	int n_table;
	xmlChar * name; /* the name of the userdata */
	int n_name;
	xmlChar * name2; /* a second name of the userdata */
	int n_name2;
	xmlChar * name3; /* a third name of the userdata */
	int n_name3;

	for (n_table = 0;n_table < gen_nb_xmlHashTablePtr;n_table++) {
		for (n_name = 0;n_name < gen_nb_const_xmlChar_ptr;n_name++) {
			for (n_name2 = 0;n_name2 < gen_nb_const_xmlChar_ptr;n_name2++) {
				for (n_name3 = 0;n_name3 < gen_nb_const_xmlChar_ptr;n_name3++) {
					table = gen_xmlHashTablePtr(n_table, 0);
					DTS_CHECK_NE_MESSAGE("xmlHashLookup3", table, NULL, "hash table is NULL");
					name = gen_const_xmlChar_ptr(n_name, 1);
					DTS_CHECK_NE_MESSAGE("xmlHashLookup3", name, NULL, "userdata is NULL");
					name2 = gen_const_xmlChar_ptr(n_name2, 2);
					DTS_CHECK_NE_MESSAGE("xmlHashLookup3", name2, NULL, "userdata is NULL");
					name3 = gen_const_xmlChar_ptr(n_name3, 3);
					DTS_CHECK_NE_MESSAGE("xmlHashLookup3", name3, NULL, "userdata is NULL");
					/**
					 * @remarks   input1: [N/A, N/A] @n
					*            {table of size 10 , userdata name("foo" ,"<foo/>" ,"none"," 2ab ")
					 *			  userdata name2("foo" ,"<foo/>" ,"none"," 2ab ") , userdata name2("foo" ,"<foo/>" ,"none"," 2ab ")}@n
					     *			  => {N/A | void pointer} @n
					*/
					ret_val = xmlHashLookup3(table, (const xmlChar *)name, (const xmlChar *)name2, (const xmlChar *)name3);
					DTS_CHECK_EQ_MESSAGE("xmlHashLookup3", ret_val, 0, "xmlHashLookup3 Failed");
					desret_void_ptr(ret_val);
					des_xmlHashTablePtr(n_table, table, 0);
					des_const_xmlChar_ptr(n_name, (const xmlChar *)name, 1);
					des_const_xmlChar_ptr(n_name2, (const xmlChar *)name2, 2);
					des_const_xmlChar_ptr(n_name3, (const xmlChar *)name3, 3);
					xmlResetLastError();
				}
			}
		}
	}
}
	/**    
	* @test			UTcXmlHashQLookupP01
	* @brief		void *xmlHashQLookup(xmlHashTablePtr table, const xmlChar *prefix, const xmlChar *name) 
	* @desc			Positive Test for xmlHashQLookup
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Michel Anthony (michelj@samsung.com)
	* @return		void
	* @see			none
	* @remarks		input1: [Create table, free the hash table and its contents] @n
	*   			{xmlHashTablePtr(hash table), xmlChar *("foo", "<foo/>", "none", " 2ab " ), xmlChar *("foo", "<foo/>", "none", " 2ab " )} => {N/A | void*(NOT NULL)} @n
	* @b priority	Middle
	* @b etc		none
	*/
static void
UTcXmlHashQLookupP01()
{
	void * ret_val;
	xmlHashTablePtr table; /* the hash table */
	int n_table;
	xmlChar * prefix; /* the prefix of the userdata */
	int n_prefix;
	xmlChar * name; /* the name of the userdata */
	int n_name;

	for (n_table = 0;n_table < gen_nb_xmlHashTablePtr;n_table++) {
		for (n_prefix = 0;n_prefix < gen_nb_const_xmlChar_ptr;n_prefix++) {
			for (n_name = 0;n_name < gen_nb_const_xmlChar_ptr;n_name++) {
				table = gen_xmlHashTablePtr(n_table, 0);
				DTS_CHECK_NE_MESSAGE("xmlHashQLookup", table, NULL, "hash table is NULL");
				prefix = gen_const_xmlChar_ptr(n_prefix, 1);
				DTS_CHECK_NE_MESSAGE("xmlHashQLookup", prefix, NULL, "gen_const_xmlChar_ptr returned NULL");
				name = gen_const_xmlChar_ptr(n_name, 2);
				DTS_CHECK_NE_MESSAGE("xmlHashQLookup", name, NULL, "userdata is NULL");
				/**
				 * @remarks   input1: [N/A, N/A] @n
				*            {table of size 10 , prefix("foo" ,"<foo/>" ,"none"," 2ab ") ,
				 *			   userdata name("foo" ,"<foo/>" ,"none"," 2ab ")}@n
				 *			   => {N/A | void pointer} @n
				*/
				ret_val = xmlHashQLookup(table, (const xmlChar *)prefix, (const xmlChar *)name);
				DTS_CHECK_EQ_MESSAGE("xmlHashQLookup", ret_val, 0, "xmlHashQLookup Failed");
				desret_void_ptr(ret_val);
				des_xmlHashTablePtr(n_table, table, 0);
				des_const_xmlChar_ptr(n_prefix, (const xmlChar *)prefix, 1);
				des_const_xmlChar_ptr(n_name, (const xmlChar *)name, 2);
				xmlResetLastError();
			}
		}
	}
}
/**    
	* @test			UTcXmlHashQLookup2P01
	* @brief		void *xmlHashQLookup2(xmlHashTablePtr table, const xmlChar *prefix, const xmlChar *name, const xmlChar *prefix2, const xmlChar *name2)
	* @desc			Positive Test for xmlHashQLookup2
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Michel Anthony (michelj@samsung.com)
	* @return		void
	* @see			none
	* @remarks		input1: [Create table, free the hash table and its contents] @n
	*   			{xmlHashTablePtr(hash table), xmlChar *("foo", "<foo/>", "none", " 2ab " ), xmlChar *("foo", "<foo/>", "none", " 2ab " ), xmlChar *("foo", "<foo/>", "none", " 2ab " ), xmlChar *("foo", "<foo/>", "none", " 2ab " )} => {N/A | void*(NOT NULL)} @n
	* @b priority	Middle
	* @b etc		none
	*/
static void
UTcXmlHashQLookup2P01()
{
	void * ret_val;
	xmlHashTablePtr table; /* the hash table */
	int n_table;
	xmlChar * prefix; /* the prefix of the userdata */
	int n_prefix;
	xmlChar * name; /* the name of the userdata */
	int n_name;
	xmlChar * prefix2; /* the second prefix of the userdata */
	int n_prefix2;
	xmlChar * name2; /* a second name of the userdata */
	int n_name2;

	for (n_table = 0;n_table < gen_nb_xmlHashTablePtr;n_table++) {
		for (n_prefix = 0;n_prefix < gen_nb_const_xmlChar_ptr;n_prefix++) {
			for (n_name = 0;n_name < gen_nb_const_xmlChar_ptr;n_name++) {
				for (n_prefix2 = 0;n_prefix2 < gen_nb_const_xmlChar_ptr;n_prefix2++) {
					for (n_name2 = 0;n_name2 < gen_nb_const_xmlChar_ptr;n_name2++) {
						table = gen_xmlHashTablePtr(n_table, 0);
						DTS_CHECK_NE_MESSAGE("xmlHashQLookup2", table, NULL, "hash table is NULL");
						prefix = gen_const_xmlChar_ptr(n_prefix, 1);
						DTS_CHECK_NE_MESSAGE("xmlHashQLookup2", table, NULL, "gen_const_xmlChar_ptr returned NULL");
						name = gen_const_xmlChar_ptr(n_name, 2);
						DTS_CHECK_NE_MESSAGE("xmlHashQLookup2", table, NULL, "userdata is NULL");
						prefix2 = gen_const_xmlChar_ptr(n_prefix2, 3);
						DTS_CHECK_NE_MESSAGE("xmlHashQLookup2", table, NULL, "gen_const_xmlChar_ptr returned NULL");
						name2 = gen_const_xmlChar_ptr(n_name2, 4);
						DTS_CHECK_NE_MESSAGE("xmlHashQLookup2", table, NULL, "userdata is NULL");
						/**
						     * @remarks   input1: [N/A, N/A] @n
						 *            {table of size 10 , prefix("foo" ,"<foo/>" ,"none"," 2ab ") ,
						     *			   userdata name("foo" ,"<foo/>" ,"none"," 2ab ") ,prefix2("foo" ,"<foo/>" ,"none"," 2ab ") ,@n
						     *			   userdata name1("foo" ,"<foo/>" ,"none"," 2ab ")}@n
						     *			   => {N/A | void pointer} @n
						     */
						ret_val = xmlHashQLookup2(table, (const xmlChar *)prefix, (const xmlChar *)name, (const xmlChar *)prefix2, (const xmlChar *)name2);
						DTS_CHECK_EQ_MESSAGE("xmlHashQLookup2", ret_val, 0, "xmlHashQLookup2 Failed");
						desret_void_ptr(ret_val);
						des_xmlHashTablePtr(n_table, table, 0);
						des_const_xmlChar_ptr(n_prefix, (const xmlChar *)prefix, 1);
						des_const_xmlChar_ptr(n_name, (const xmlChar *)name, 2);
						des_const_xmlChar_ptr(n_prefix2, (const xmlChar *)prefix2, 3);
						des_const_xmlChar_ptr(n_name2, (const xmlChar *)name2, 4);
						xmlResetLastError();
					}
				}
			}
		}
	}
}
	/**    
	* @test			UTcXmlHashSizeP01
	* @brief		int xmlHashSize(xmlHashTablePtr table)
	* @desc			Positive Test for xmlHashSize
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Michel Anthony (michelj@samsung.com)
	* @return		void
	* @see			none
	* @remarks		input1: [Create table, free the hash table and its contents] @n
	*   			{xmlHashTablePtr(hash table)} => {N/A | int(NOT -1 OR NOT NULL)} @n
	* @b priority	Middle
	* @b etc		none
	*/
static void
UTcXmlHashSizeP01()
{
	int ret_val;
	xmlHashTablePtr table; /* the hash table */
	int n_table;

	for (n_table = 0;n_table < gen_nb_xmlHashTablePtr;n_table++) {
		table = gen_xmlHashTablePtr(n_table, 0);
		DTS_CHECK_NE_MESSAGE("xmlHashSize", table, NULL, "hash table is NULL");
		/**
		* @remarks   input1: [N/A, N/A] @n
		*            {table of size 10} => {N/A | void pointer} @n
		*/
		ret_val = xmlHashSize(table);
		DTS_CHECK_EQ_MESSAGE("xmlHashSize", ret_val, 0, "xmlHashSize Failed");
		desret_int(ret_val);
		des_xmlHashTablePtr(n_table, table, 0);
		xmlResetLastError();
	}
}
/**    
	* @test			UTcXmlHashScanP01
	* @brief		
	* @desc			
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Michel Anthony (michelj@samsung.com)
	* @return		void
	* @see			none
	* @remarks		
	* @b priority	Middle
	* @b etc		none
	*/
static void
UTcXmlHashScanP01()
{

	/* missing type support */
	DTS_CHECK_EQ_MESSAGE("UTcXmlHashScanP01", 1, 1, "UTcXmlHashScanP01 Failed");
}
/**    
	* @test			UTcXmlHashScan3P01
	* @brief		void xmlHashScan3(xmlHashTablePtr table, const xmlChar *name, const xmlChar *name2, const xmlChar *name3, xmlHashScanner f, void *data)
	* @desc			Positive Test for xmlHashScan3
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Michel Anthony (michelj@samsung.com)
	* @return		void
	* @see			none
	* @remarks		input1: [Create table, free the hash table and its contents] @n
	*   			{xmlHashTablePtr(hash table), xmlChar *("test1"), xmlChar *("test2"), xmlChar *("test3"), xmlHashScanner, (void *)"xmlHashScan3} => {N/A} @n
	* @b priority	Middle
	* @b etc		none
	*/
static void
UTcXmlHashScan3P01()
{
	xmlHashTablePtr table; /* the hash table */
	xmlHashScanner f;
	xmlErrorPtr				pError;
	xmlResetLastError();

	/**
	 * @remarks   input1: [N/A, N/A] @n
	     *            {table of size 10 , prefix("foo" ,"<foo/>" ,"none"," 2ab ") ,
	     *			   userdata name("foo" ,"<foo/>" ,"none"," 2ab ") ,prefix2("foo" ,"<foo/>" ,"none"," 2ab ") ,@n
	     *			   userdata name1("foo" ,"<foo/>" ,"none"," 2ab ")}@n
	     *			   => {N/A | void pointer} @n
	     */

	table = xmlHashCreate(10);
	f = gen_xmlHashScanner(0, 3);
	DTS_CHECK_NE_MESSAGE("xmlHashScan3", f, NULL, "gen_xmlHashScanner returned NULL");

	xmlHashScan3(table,(const xmlChar *)"test1",(const xmlChar *)"test2",(const xmlChar *)"test3",f,(void *)"xmlHashScan3");
	pError = xmlGetLastError();
	DTS_CHECK_EQ_MESSAGE("xmlHashScan3", pError, 0, "checking the result for xmlHashScan3");


	xmlHashFree(table,NULL);
	if (pError != NULL)
		free( pError);
}
/**    
	* @test			UTcXmlHashScanFullP01
	* @brief		
	* @desc			
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Michel Anthony (michelj@samsung.com)
	* @return		void
	* @see			none
	* @remarks		
	* @b priority	Middle
	* @b etc		none
	*/
static void
UTcXmlHashScanFullP01()
{

	/* missing type support */
	DTS_CHECK_EQ_MESSAGE("UTcXmlHashScanFullP01", 1, 1, "checking the result for xmlHashScan3");
}
/**    
	* @test			UTcXmlHashScanFull3P01
	* @brief		
	* @desc			
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Michel Anthony (michelj@samsung.com)
	* @return		void
	* @see			none
	* @remarks		
	* @b priority	Middle
	* @b etc		none
	*/
static void
UTcXmlHashScanFull3P01()
{

	/* missing type support */
	DTS_CHECK_EQ_MESSAGE("UTcXmlHashScanFull3P01", 1, 1, "checking the result for xmlHashScan3");
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
        {UTcXmlHashCreateP01,1},
        {UTcXmlHashFreeP01,2},
        {UTcXmlHashAddEntryP01,3},
        {UTcXmlHashUpdateEntryP01,4},
        {UTcXmlHashAddEntry2P01,5},
        {UTcXmlHashUpdateEntry2P01,6},
        {UTcXmlHashAddEntry3P01,7},
        {UTcXmlHashUpdateEntry3P01,8},
        {UTcXmlHashRemoveEntryP01,9},
        {UTcXmlHashRemoveEntry2P01,10},
        
        {UTcXmlHashRemoveEntry3P01,11},
        {UTcXmlHashLookupP01,13},
        {UTcXmlHashLookup2P01,14},
        {UTcXmlHashLookup3P01,15},
        {UTcXmlHashQLookupP01,16},
        {UTcXmlHashQLookup2P01,17},
        {UTcXmlHashSizeP01,18},
        {UTcXmlHashScanP01,19},
        {UTcXmlHashScan3P01,20},
        
        {UTcXmlHashScanFullP01,21},
        {UTcXmlHashScanFull3P01,22},
	{ NULL, 0 },
	
};

