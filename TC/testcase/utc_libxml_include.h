
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

#ifndef __UTC_LIBXML_INCLUDE_H__
#define __UTC_LIBXML_INCLUDE_H__

#include <tet_api.h>
#include <libxml/hash.h>
#include <libxml/HTMLtree.h>
#include <libxml/tree.h>
#include <libxml/encoding.h>
#include <libxml/xmlmemory.h>

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include <errno.h>
#include <assert.h>

#if 0
void printmsg(char * pFmt, ...)
{
	char in_str[64];
	va_list   ap;
	va_start(ap, pFmt); 
	vsnprintf(in_str,64, pFmt, ap);
	tet_printf("%s:%s\n","[TETware]",in_str);\
	
}

int dts_check_ne(char* apiName, void *actual, void *expected )
{
	if(actual != expected){
		tet_result(TET_PASS);
		return 1;
	}else{
		tet_printf("Testing API %s actual %0x expected %0x " ,apiName, actual, expected);
		tet_result(TET_FAIL);
		return -1;	
	}
}

int dts_check_ne_message(char* apiName, void *actual, void *expected, char *message )
{

	if(actual != expected)
	{
		tet_result(TET_PASS);
		return 1;
	}
	else
	{
		tet_printf("Testing API %s actual %0x expected %0x " ,apiName, actual, expected);
		tet_printf("%s: %s" ,apiName, message);
		tet_result(TET_FAIL);
		return -1;
	}
}

int dts_check_eq(char* apiName, void *actual, void *expected )
{

	if(actual == expected){
		tet_result(TET_PASS);
		return 1;
	}else{
		tet_printf("Testing API %s actual %0x expected %0x " ,apiName, actual, expected);
		tet_result(TET_FAIL);
		return -1;	
	}
}

int dts_check_eq_message(char* apiName, void *actual, void *expected, char *message )
{

	if((int)actual == (int)expected)
	{
		tet_result(TET_PASS);
		return 1;
	}
	else
	{
		tet_printf("Testing API %s actual %0x expected %0x " ,apiName, actual, expected);
		tet_printf("%s: %s" ,apiName, message);
		tet_result(TET_FAIL);
		return -1;
	}
}


int dts_check_gt_message(char* apiName, void *actual, void *expected, char *message )
{

	if((int)actual > (int)expected)
	{
		tet_result(TET_PASS);
		return 1;
	}
	else
	{
		tet_printf("Testing API %s actual %0x expected %0x " ,apiName, actual, expected);
		tet_printf("%s: %s" ,apiName, message);
		tet_result(TET_FAIL);
		return -1;
	}
}

int dts_check_gte_message(char* apiName, void *actual, void *expected, char *message )
{

	if((int)actual >= (int)expected)
	{
		tet_result(TET_PASS);
		return 1;
	}
	else
	{
		tet_printf("Testing API %s actual %0x expected %0x " ,apiName, actual, expected);
		tet_printf("%s: %s" ,apiName, message);
		tet_result(TET_FAIL);
		return -1;
	}
}

int dts_check_lt_message(char* apiName, void *actual, void *expected, char *message )
{

	if((int)actual < (int)expected)
	{
		tet_result(TET_PASS);
		return 1;
	}
	else
	{
		tet_printf("Testing API %s actual %0x expected %0x " ,apiName, actual, expected);
		tet_printf("%s: %s" ,apiName, message);
		tet_result(TET_FAIL);
		return -1;
	}
}

int dts_check_lte_message(char* apiName, void *actual, void *expected, char *message )
{

	if((int)actual <= (int)expected)
	{
		tet_result(TET_PASS);
		return 1;
	}
	else
	{
		tet_printf("Testing API %s actual %0x expected %0x " ,apiName, actual, expected);
		tet_printf("%s: %s" ,apiName, message);
		tet_result(TET_FAIL);
		return -1;
	}
}


void dts_assert_message(char* apiName, void *expression, char *message )
{

	if((int)expression)
	{
		tet_printf("Testing API asserted %s %s" ,apiName, message);
		assert((int)expression);
	}
}

void dts_message(char* apiName, char *message )
{
	tet_printf("%s: %s" ,apiName, message);
}

void dts_fail(char* apiName, char *message )
{
	tet_printf("%s: %s" ,apiName, message);
	tet_result(TET_FAIL);
	tet_exit(-1);
}

void dts_pass(char* apiName, char *message )
{
	tet_printf("%s: %s" ,apiName, message);
	tet_result(TET_PASS);
}

#define DTS_CHECK_NE(apiname, actual, expected) dts_check_ne(apiname, actual, expected)

#define DTS_CHECK_NE_MESSAGE(apiname, actual, expected, message) dts_check_ne_message(apiname, actual, expected, message)

#define DTS_CHECK_EQ(apiname, actual, expected) dts_check_eq(apiname, actual, expected)

#define DTS_CHECK_EQ_MESSAGE(apiname, actual, expected, message) dts_check_eq_message(apiname, actual, expected, message)

#define DTS_CHECK_GT_MESSAGE(apiname, actual, expected, message) dts_check_gt_message(apiname, actual, expected, message)

#define DTS_CHECK_LT_MESSAGE(apiname, actual, expected, message) dts_check_lt_message(apiname, actual, expected, message)

#define DTS_CHECK_GTE_MESSAGE(apiname, actual, expected, message) dts_check_gte_message(apiname, actual, expected, message)

#define DTS_CHECK_LTE_MESSAGE(apiname, actual, expected, message) dts_check_lte_message(apiname, actual, expected, message)

#define DTS_ASSERT_MESSAGE(apiname, expression, message) dts_assert_message(apiname, expression, message)


#define DTS_PRINT(apiname, message) dts_message(apiname, message)

#define DTS_FAIL(apiname, message) dts_fail(apiname, message)

#define DTS_PASS(apiname, message) dts_pass(apiname, message)

#else
#define DTS_CHECK_NE(apiname, actual, expected) dts_check_ne(apiname, actual, expected)
#define DTS_CHECK_NE_MESSAGE(apiname, actual, expected, message) dts_check_ne(apiname, actual, expected, message)

#define DTS_CHECK_EQ(apiname, actual, expected) dts_check_eq(apiname, actual, expected)

#define DTS_CHECK_EQ_MESSAGE(apiname, actual, expected, message) dts_check_eq(apiname, actual, expected, message)

#define DTS_CHECK_GT_MESSAGE(apiname, actual, expected, message) dts_check_gt(apiname, actual, expected, message)

#define DTS_CHECK_LT_MESSAGE(apiname, actual, expected, message) dts_check_lt(apiname, actual, expected, message)

#define DTS_CHECK_GTE_MESSAGE(apiname, actual, expected, message) dts_check_ge_(apiname, actual, expected, message)

#define DTS_CHECK_LTE_MESSAGE(apiname, actual, expected, message) dts_check_le(apiname, actual, expected, message)

#define DTS_ASSERT_MESSAGE(apiname, expression, message) { if(expression) dts_fail(apiname,message);	}


#define DTS_PRINT(apiname, message) dts_message(apiname, message)

#define DTS_FAIL(apiname, message) dts_fail(apiname, message)

#define DTS_PASS(apiname, message) dts_pass(apiname, message)

#endif

#define XML_TRUE 1
#define XML_FALSE 0

//#define UTSHOME "/HomeExt"
//#define UTSHOME "/home/gopal/git/tet-root-i386/contrib/libxml/res"
#define UTSHOME "./res"

#define UTSXMLHOME UTSHOME"/UTsXml"

#define HOMESCHEMA UTSXMLHOME"/valid/schema.xsd"
#define HOMESCHEMAXML UTSXMLHOME"/valid/schema.xml"


#define RECxml19980210 UTSXMLHOME"/valid/REC-xml-19980210.xml"
#define TESTRECxml19980210 UTSXMLHOME"/test/valid/REC-xml-19980210.xml"
//#define  HOMERECxml19980210 UTSHOME"/REC-xml-19980210.xml"
#define  HOMERECxml19980210 RECxml19980210


#define ENT2 UTSXMLHOME"/valid/ent2"
#define HOMEENT2 UTSHOME"/ent2"
//#define HOMEENT2 ENT2


#define TESTXML UTSXMLHOME"/valid/test.xml"
#define TESTXML1 UTSXMLHOME"/test.xml"

//#define XHTML1STRICTDTD UTSXMLHOME"/valid/xhtml1-strict.dtd"
#define XHTML1STRICTDTD UTSXMLHOME"/test/valid/dtds/xhtml1-strict.dtd"
#define TESTXHTML1STRICTDTD UTSXMLHOME"/test/valid/dtds/xhtml1-strict.dtd"

//#define HOMEXHTML1STRICTDTD UTSHOME"/xhtml1-strict.dtd"
#define HOMEXHTML1STRICTDTD XHTML1STRICTDTD


#define MISSINGXML "missing.xml"

#define LIBXML2TESTXML UTSXMLHOME"/libXml2Test.xml"

#define IOTESTTXT	UTSHOME"/IoTest.txt"
#define IOTEST1TXT 	UTSHOME"/IoTest1.txt"

#define	REMOTE1GOOD	"http://localhost/"
#define	REMOTE1BAD	"http:http://http"
#define	REMOTE2GOOD	"ftp://localhost/foo"



const char *gen_fileoutput(int no, int nr ATTRIBUTE_UNUSED) {
    if (no == 0) return(MISSINGXML);
    if (no == 1) return("<foo/>");
    if (no == 2) return(REMOTE2GOOD);
    if (no == 3) return(REMOTE1GOOD);
    if (no == 4) return(REMOTE1BAD);
    return(NULL);
}


#endif

