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
#include <libxml/pattern.h>



static xmlDocPtr api_doc = NULL;
static xmlDtdPtr api_dtd = NULL;
static xmlNodePtr api_root = NULL;
static xmlAttrPtr api_attr = NULL;
static xmlNsPtr api_ns = NULL;

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

static void
free_api_doc(void) {
    xmlFreeDoc(api_doc);
    api_doc = NULL;
    api_dtd = NULL;
    api_root = NULL;
    api_attr = NULL;
    api_ns = NULL;
}

#define gen_nb_xmlPatternPtr 1
static xmlPatternPtr gen_xmlPatternPtr(int no ATTRIBUTE_UNUSED, int nr ATTRIBUTE_UNUSED) {
 //   return(NULL);
    return (xmlPatterncompile((const xmlChar*)"1.0", NULL, 0, NULL));
}

static void des_xmlPatternPtr(int no ATTRIBUTE_UNUSED, xmlPatternPtr val , int nr ATTRIBUTE_UNUSED) {
	if (val)
		xmlFreePattern(val);
}

#define gen_nb_xmlNodePtr 2
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

static void desret_int(int val ATTRIBUTE_UNUSED) {
}

static void UTcxmlFreePatternP01()
{
	xmlPatternPtr comp; /* the precompiled pattern */
    int n_comp;
	for (n_comp = 0;n_comp < gen_nb_xmlPatternPtr;n_comp++) {
		comp = gen_xmlPatternPtr(n_comp, 0);
   		xmlFreePattern(comp);
		DTS_CHECK_EQ_MESSAGE("xmlFreePattern", (void *)comp, (void *)NULL, "xmlFreePattern Failed");
		}
}

static void UTcxmlFreePatternListP01()
{
	xmlPatternPtr comp; /* the precompiled pattern */
    int n_comp;
	for (n_comp = 0;n_comp < gen_nb_xmlPatternPtr;n_comp++) {
		comp = gen_xmlPatternPtr(n_comp, 0);
		xmlFreePatternList(comp);
		DTS_CHECK_EQ_MESSAGE("xmlFreePatternList", (void *)comp, (void *)NULL, "xmlFreePatternList Failed");
		}

}

static void UTcxmlPatterncompileP01()
{
	xmlPatternPtr comp;
	comp = xmlPatterncompile((const xmlChar*)"1.0", NULL, 0, NULL);
	DTS_CHECK_EQ_MESSAGE("xmlPatterncompile", (void *)comp, (void *)NULL, "xmlPatterncompile Failed");
}

static void UTcxmlPatternMatchP01()
{
	int ret_val;
    xmlPatternPtr comp; /* the precompiled pattern */
    int n_comp;
    xmlNodePtr node; /* a node */
    int n_node;

    for (n_comp = 0;n_comp < gen_nb_xmlPatternPtr;n_comp++) {
    for (n_node = 0;n_node < gen_nb_xmlNodePtr;n_node++) {
        comp = gen_xmlPatternPtr(n_comp, 0);
        node = gen_xmlNodePtr(n_node, 1);

        ret_val = xmlPatternMatch(comp, node);
	DTS_CHECK_EQ_MESSAGE("xmlPatternMatch", (void *)ret_val, (void *)-1, "xmlPatternMatch Failed");
        desret_int(ret_val);
        des_xmlPatternPtr(n_comp, comp, 0);
        des_xmlNodePtr(n_node, node, 1);
        xmlResetLastError();
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
	{UTcxmlFreePatternP01,1},
	{UTcxmlFreePatternListP01,2},
	{UTcxmlPatterncompileP01,3},
	{UTcxmlPatternMatchP01,4},
	{ NULL, 0 },
	
};

