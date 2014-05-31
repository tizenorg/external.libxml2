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
#include <sys/types.h>
#include <sys/stat.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>

#ifdef DEBUG_MEM_LEAK
extern "C"
{
	extern void MemStartSaveCallStack(void);
	extern void MemEndSaveCallStack(void);
	extern void MemPrintCurrentIndex(void);
	extern void MemTraceAllocMemInfo(void);
}
#endif
#ifdef OSP_MEM_ALLOC_INFO
#include "matrix.h"
#endif

static int quiet = 0;
static int sax2 = 0;
static int repeat = 0;
static int callbacks = 0;


/***************************************************************************
 * SUTsSax
 ***************************************************************************/
xmlSAXHandlerV1 emptySAXHandlerV1Struct = {
	NULL, /* internalSubset */
	NULL, /* isStandalone */
	NULL, /* hasInternalSubset */
	NULL, /* hasExternalSubset */
	NULL, /* resolveEntity */
	NULL, /* getEntity */
	NULL, /* entityDecl */
	NULL, /* notationDecl */
	NULL, /* attributeDecl */
	NULL, /* elementDecl */
	NULL, /* unparsedEntityDecl */
	NULL, /* setDocumentLocator */
	NULL, /* startDocument */
	NULL, /* endDocument */
	NULL, /* startElement */
	NULL, /* endElement */
	NULL, /* reference */
	NULL, /* characters */
	NULL, /* ignorableWhitespace */
	NULL, /* processingInstruction */
	NULL, /* comment */
	NULL, /* xmlParserWarning */
	NULL, /* xmlParserError */
	NULL, /* xmlParserError */
	NULL, /* getParameterEntity */
	NULL, /* cdataBlock; */
	NULL, /* externalSubset; */
	1
};
xmlSAXHandlerV1Ptr emptySAXHandlerV1 = &emptySAXHandlerV1Struct;
xmlSAXHandler emptySAXHandlerStruct = {
	NULL, /* internalSubset */
	NULL, /* isStandalone */
	NULL, /* hasInternalSubset */
	NULL, /* hasExternalSubset */
	NULL, /* resolveEntity */
	NULL, /* getEntity */
	NULL, /* entityDecl */
	NULL, /* notationDecl */
	NULL, /* attributeDecl */
	NULL, /* elementDecl */
	NULL, /* unparsedEntityDecl */
	NULL, /* setDocumentLocator */
	NULL, /* startDocument */
	NULL, /* endDocument */
	NULL, /* startElement */
	NULL, /* endElement */
	NULL, /* reference */
	NULL, /* characters */
	NULL, /* ignorableWhitespace */
	NULL, /* processingInstruction */
	NULL, /* comment */
	NULL, /* xmlParserWarning */
	NULL, /* xmlParserError */
	NULL, /* xmlParserError */
	NULL, /* getParameterEntity */
	NULL, /* cdataBlock; */
	NULL, /* externalSubset; */
	1,
	NULL,
	NULL, /* startElementNs */
	NULL, /* endElementNs */
	NULL  /* xmlStructuredErrorFunc */
};
xmlSAXHandlerPtr emptySAXHandler = &emptySAXHandlerStruct;

/************************************************************************
 *									*
 *				Debug Handlers				*
 *									*
 ************************************************************************/
/**
 * isStandaloneDebug:
 * @ctxt:  An XML parser context
 *
 * Is this document tagged standalone ?
 *
 * Returns 1 if true
 */
static int
isStandaloneDebug(void *ctx ATTRIBUTE_UNUSED)
{
	callbacks++;
	if (quiet)
		return(0);
	#ifdef DISABLE_STDOUT
	fprintf(stdout, "SAX.isStandalone()\n");
	#endif
	return(0);
}
/**
 * hasInternalSubsetDebug:
 * @ctxt:  An XML parser context
 *
 * Does this document has an internal subset
 *
 * Returns 1 if true
 */
static int
hasInternalSubsetDebug(void *ctx ATTRIBUTE_UNUSED)
{
	callbacks++;
	if (quiet)
		return(0);
	#ifdef DISABLE_STDOUT
	fprintf(stdout, "SAX.hasInternalSubset()\n");
	#endif
	return(0);
}
/**
 * hasExternalSubsetDebug:
 * @ctxt:  An XML parser context
 *
 * Does this document has an external subset
 *
 * Returns 1 if true
 */
static int
hasExternalSubsetDebug(void *ctx ATTRIBUTE_UNUSED)
{
	callbacks++;
	if (quiet)
		return(0);
	#ifdef DISABLE_STDOUT
	fprintf(stdout, "SAX.hasExternalSubset()\n");
	#endif
	return(0);
}
/**
 * internalSubsetDebug:
 * @ctxt:  An XML parser context
 *
 * Does this document has an internal subset
 */
static void
internalSubsetDebug(void *ctx ATTRIBUTE_UNUSED, const xmlChar *name,
                    const xmlChar *ExternalID, const xmlChar *SystemID)
{
	callbacks++;
	if (quiet)
		return;
	#ifdef DISABLE_STDOUT
	fprintf(stdout, "SAX.internalSubset(%s,", name);
	if (ExternalID == NULL)
		fprintf(stdout, " ,");
	else
		fprintf(stdout, " %s,", ExternalID);
	if (SystemID == NULL)
		fprintf(stdout, " )\n");
	else
		fprintf(stdout, " %s)\n", SystemID);
	#endif
}
/**
 * externalSubsetDebug:
 * @ctxt:  An XML parser context
 *
 * Does this document has an external subset
 */
static void
externalSubsetDebug(void *ctx ATTRIBUTE_UNUSED, const xmlChar *name,
                    const xmlChar *ExternalID, const xmlChar *SystemID)
{
	callbacks++;
	if (quiet)
		return;
	#ifdef DISABLE_STDOUT	
	fprintf(stdout, "SAX.externalSubset(%s,", name);
	if (ExternalID == NULL)
		fprintf(stdout, " ,");
	else
		fprintf(stdout, " %s,", ExternalID);
	if (SystemID == NULL)
		fprintf(stdout, " )\n");
	else
		fprintf(stdout, " %s)\n", SystemID);
	#endif
}
/**
 * resolveEntityDebug:
 * @ctxt:  An XML parser context
 * @publicId: The public ID of the entity
 * @systemId: The system ID of the entity
 *
 * Special entity resolver, better left to the parser, it has
 * more context than the application layer.
 * The default behaviour is to NOT resolve the entities, in that case
 * the ENTITY_REF nodes are built in the structure (and the parameter
 * values).
 *
 * Returns the xmlParserInputPtr if inlined or NULL for DOM behaviour.
 */
static xmlParserInputPtr
resolveEntityDebug(void *ctx ATTRIBUTE_UNUSED, const xmlChar *publicId, const xmlChar *systemId)
{
	callbacks++;
	if (quiet)
		return(NULL);
	/* xmlParserCtxtPtr ctxt = (xmlParserCtxtPtr) ctx; */

	#ifdef DISABLE_STDOUT
	fprintf(stdout, "SAX.resolveEntity(");
	if (publicId != NULL)
		fprintf(stdout, "%s", (char *)publicId);
	else
		fprintf(stdout, " ");
	if (systemId != NULL)
		fprintf(stdout, ", %s)\n", (char *)systemId);
	else
		fprintf(stdout, ", )\n");
	#endif
	/*********
	    if (systemId != NULL) {
	        return(xmlNewInputFromFile(ctxt, (char *) systemId));
	    }
	 *********/
	return(NULL);
}
/**
 * getEntityDebug:
 * @ctxt:  An XML parser context
 * @name: The entity name
 *
 * Get an entity by name
 *
 * Returns the xmlParserInputPtr if inlined or NULL for DOM behaviour.
 */
static xmlEntityPtr
getEntityDebug(void *ctx ATTRIBUTE_UNUSED, const xmlChar *name)
{
	callbacks++;
	if (quiet)
		return(NULL);
	#ifdef DISABLE_STDOUT
	fprintf(stdout, "SAX.getEntity(%s)\n", name);
	#endif
	return(NULL);
}

/**
 * getParameterEntityDebug:
 * @ctxt:  An XML parser context
 * @name: The entity name
 *
 * Get a parameter entity by name
 *
 * Returns the xmlParserInputPtr
 */
static xmlEntityPtr
getParameterEntityDebug(void *ctx ATTRIBUTE_UNUSED, const xmlChar *name)
{
	callbacks++;
	if (quiet)
		return(NULL);
	#ifdef DISABLE_STDOUT
	fprintf(stdout, "SAX.getParameterEntity(%s)\n", name);
	#endif
	return(NULL);
}
/**
 * entityDeclDebug:
 * @ctxt:  An XML parser context
 * @name:  the entity name
 * @type:  the entity type
 * @publicId: The public ID of the entity
 * @systemId: The system ID of the entity
 * @content: the entity value (without processing).
 *
 * An entity definition has been parsed
 */
static void
entityDeclDebug(void *ctx ATTRIBUTE_UNUSED, const xmlChar *name, int type,
                const xmlChar *publicId, const xmlChar *systemId, xmlChar *content)
{
	const xmlChar *NULLstr = BAD_CAST "(NULL)";
	/* not all libraries handle printing NULL pointers nicely */
	if (publicId == NULL)
		publicId = NULLstr;
	if (systemId == NULL)
		systemId = NULLstr;
	if (content == NULL)
		content = (xmlChar *)NULLstr;
	callbacks++;
	if (quiet)
		return;
	#ifdef DISABLE_STDOUT
	fprintf(stdout, "SAX.entityDecl(%s, %d, %s, %s, %s)\n",
	        name, type, publicId, systemId, content);
	#endif
}
/**
 * attributeDeclDebug:
 * @ctxt:  An XML parser context
 * @name:  the attribute name
 * @type:  the attribute type
 *
 * An attribute definition has been parsed
 */
static void
attributeDeclDebug(void *ctx ATTRIBUTE_UNUSED, const xmlChar * elem,
                   const xmlChar * name, int type, int def,
                   const xmlChar * defaultValue, xmlEnumerationPtr tree)
{
	callbacks++;
	if (quiet)
		return;
	#ifdef DISABLE_STDOUT
	if (defaultValue == NULL)
		fprintf(stdout, "SAX.attributeDecl(%s, %s, %d, %d, NULL, ...)\n",
		        elem, name, type, def);
	else
		fprintf(stdout, "SAX.attributeDecl(%s, %s, %d, %d, %s, ...)\n",
		        elem, name, type, def, defaultValue);
	#endif
	xmlFreeEnumeration(tree);
}
/**
 * elementDeclDebug:
 * @ctxt:  An XML parser context
 * @name:  the element name
 * @type:  the element type
 * @content: the element value (without processing).
 *
 * An element definition has been parsed
 */
static void
elementDeclDebug(void *ctx ATTRIBUTE_UNUSED, const xmlChar *name, int type,
                 xmlElementContentPtr content ATTRIBUTE_UNUSED)
{
	callbacks++;
	if (quiet)
		return;
	#ifdef DISABLE_STDOUT
	fprintf(stdout, "SAX.elementDecl(%s, %d, ...)\n",
	        name, type);
	#endif
}
/**
 * notationDeclDebug:
 * @ctxt:  An XML parser context
 * @name: The name of the notation
 * @publicId: The public ID of the entity
 * @systemId: The system ID of the entity
 *
 * What to do when a notation declaration has been parsed.
 */
static void
notationDeclDebug(void *ctx ATTRIBUTE_UNUSED, const xmlChar *name,
                  const xmlChar *publicId, const xmlChar *systemId)
{
	callbacks++;
	if (quiet)
		return;
	#ifdef DISABLE_STDOUT
	fprintf(stdout, "SAX.notationDecl(%s, %s, %s)\n",
	        (char *) name, (char *) publicId, (char *) systemId);
	#endif
}
/**
 * unparsedEntityDeclDebug:
 * @ctxt:  An XML parser context
 * @name: The name of the entity
 * @publicId: The public ID of the entity
 * @systemId: The system ID of the entity
 * @notationName: the name of the notation
 *
 * What to do when an unparsed entity declaration is parsed
 */
static void
unparsedEntityDeclDebug(void *ctx ATTRIBUTE_UNUSED, const xmlChar *name,
                        const xmlChar *publicId, const xmlChar *systemId,
                        const xmlChar *notationName)
{
	const xmlChar *NULLstr = BAD_CAST "(NULL)";

	if (publicId == NULL)
		publicId = NULLstr;
	if (systemId == NULL)
		systemId = NULLstr;
	if (notationName == NULL)
		notationName = NULLstr;
	callbacks++;
	if (quiet)
		return;
	#ifdef DISABLE_STDOUT
	fprintf(stdout, "SAX.unparsedEntityDecl(%s, %s, %s, %s)\n",
	        (char *) name, (char *) publicId, (char *) systemId,
	        (char *) notationName);
	#endif
}

/**
 * setDocumentLocatorDebug:
 * @ctxt:  An XML parser context
 * @loc: A SAX Locator
 *
 * Receive the document locator at startup, actually xmlDefaultSAXLocator
 * Everything is available on the context, so this is useless in our case.
 */
static void
setDocumentLocatorDebug(void *ctx ATTRIBUTE_UNUSED, xmlSAXLocatorPtr loc ATTRIBUTE_UNUSED)
{
	callbacks++;
	if (quiet)
		return;
	#ifdef DISABLE_STDOUT
	fprintf(stdout, "SAX.setDocumentLocator()\n");
	#endif
}
/**
 * startDocumentDebug:
 * @ctxt:  An XML parser context
 *
 * called when the document start being processed.
 */
static void
startDocumentDebug(void *ctx ATTRIBUTE_UNUSED)
{
	callbacks++;
	if (quiet)
		return;
	#ifdef DISABLE_STDOUT
	fprintf(stdout, "SAX.startDocument()\n");
	#endif
}

/**
 * endDocumentDebug:
 * @ctxt:  An XML parser context
 *
 * called when the document end has been detected.
 */
static void
endDocumentDebug(void *ctx ATTRIBUTE_UNUSED)
{
	callbacks++;
	if (quiet)
		return;
	#ifdef DISABLE_STDOUT
	fprintf(stdout, "SAX.endDocument()\n");
	#endif
}

/**
 * startElementDebug:
 * @ctxt:  An XML parser context
 * @name:  The element name
 *
 * called when an opening tag has been processed.
 */
static void
startElementDebug(void *ctx ATTRIBUTE_UNUSED, const xmlChar *name, const xmlChar **atts)
{
	int i;

	callbacks++;
	if (quiet)
		return;
	#ifdef DISABLE_STDOUT
	fprintf(stdout, "SAX.startElement(%s", (char *) name);
	if (atts != NULL) {
		for (i = 0;(atts[i] != NULL);i++) {
			fprintf(stdout, ", %s='", atts[i++]);
			if (atts[i] != NULL)
				fprintf(stdout, "%s'", atts[i]);
		}
	}
	fprintf(stdout, ")\n");
	#endif
}

/**
 * endElementDebug:
 * @ctxt:  An XML parser context
 * @name:  The element name
 *
 * called when the end of an element has been detected.
 */
static void
endElementDebug(void *ctx ATTRIBUTE_UNUSED, const xmlChar *name)
{
	callbacks++;
	if (quiet)
		return;
	#ifdef DISABLE_STDOUT
	fprintf(stdout, "SAX.endElement(%s)\n", (char *) name);
	#endif
}
/**
 * charactersDebug:
 * @ctxt:  An XML parser context
 * @ch:  a xmlChar string
 * @len: the number of xmlChar
 *
 * receiving some chars from the parser.
 * Question: how much at a time ???
 */
static void
charactersDebug(void *ctx ATTRIBUTE_UNUSED, const xmlChar *ch, int len)
{
	char output[40];
	int i;

	callbacks++;
	if (quiet)
		return;
	for (i = 0;(i<len) && (i < 30);i++)
		output[i] = ch[i];
	output[i] = 0;
	#ifdef DISABLE_STDOUT
	fprintf(stdout, "SAX.characters(%s, %d)\n", output, len);
	#endif
}

/**
 * referenceDebug:
 * @ctxt:  An XML parser context
 * @name:  The entity name
 *
 * called when an entity reference is detected.
 */
static void
referenceDebug(void *ctx ATTRIBUTE_UNUSED, const xmlChar *name)
{
	callbacks++;
	if (quiet)
		return;
	#ifdef DISABLE_STDOUT
	fprintf(stdout, "SAX.reference(%s)\n", name);
	#endif
}

/**
 * ignorableWhitespaceDebug:
 * @ctxt:  An XML parser context
 * @ch:  a xmlChar string
 * @start: the first char in the string
 * @len: the number of xmlChar
 *
 * receiving some ignorable whitespaces from the parser.
 * Question: how much at a time ???
 */
static void
ignorableWhitespaceDebug(void *ctx ATTRIBUTE_UNUSED, const xmlChar *ch, int len)
{
	char output[40];
	int i;

	callbacks++;
	if (quiet)
		return;
	for (i = 0;(i<len) && (i < 30);i++)
		output[i] = ch[i];
	output[i] = 0;
	#ifdef DISABLE_STDOUT
	fprintf(stdout, "SAX.ignorableWhitespace(%s, %d)\n", output, len);
	#endif
}

/**
 * processingInstructionDebug:
 * @ctxt:  An XML parser context
 * @target:  the target name
 * @data: the PI data's
 * @len: the number of xmlChar
 *
 * A processing instruction has been parsed.
 */
static void
processingInstructionDebug(void *ctx ATTRIBUTE_UNUSED, const xmlChar *target,
                           const xmlChar *data)
{
	callbacks++;
	if (quiet)
		return;
	#ifdef DISABLE_STDOUT
	if (data != NULL)
		fprintf(stdout, "SAX.processingInstruction(%s, %s)\n",
		        (char *) target, (char *) data);
	else
		fprintf(stdout, "SAX.processingInstruction(%s, NULL)\n",
		        (char *) target);
	#endif
}
/**
 * cdataBlockDebug:
 * @ctx: the user data (XML parser context)
 * @value:  The pcdata content
 * @len:  the block length
 *
 * called when a pcdata block has been parsed
 */
static void
cdataBlockDebug(void *ctx ATTRIBUTE_UNUSED, const xmlChar *value, int len)
{
	callbacks++;
	if (quiet)
		return;
	#ifdef DISABLE_STDOUT
	fprintf(stdout, "SAX.pcdata(%.20s, %d)\n",
	        (char *) value, len);
	#endif
}

/**
 * commentDebug:
 * @ctxt:  An XML parser context
 * @value:  the comment content
 *
 * A comment has been parsed.
 */
static void
commentDebug(void *ctx ATTRIBUTE_UNUSED, const xmlChar *value)
{
	callbacks++;
	if (quiet)
		return;
	#ifdef DISABLE_STDOUT
	fprintf(stdout, "SAX.comment(%s)\n", value);
	#endif
}
/**
 * warningDebug:
 * @ctxt:  An XML parser context
 * @msg:  the message to display/transmit
 * @...:  extra parameters for the message display
 *
 * Display and format a warning messages, gives file, line, position and
 * extra parameters.
 */
static void
warningDebug(void *ctx ATTRIBUTE_UNUSED, const char *msg, ...)
{
	va_list args;

	callbacks++;
	if (quiet)
		return;
	#ifdef DISABLE_STDOUT
	va_start(args, msg);
	fprintf(stdout, "SAX.warning: ");
	vfprintf(stdout, msg, args);
	va_end(args);
	#endif
}

/**
 * errorDebug:
 * @ctxt:  An XML parser context
 * @msg:  the message to display/transmit
 * @...:  extra parameters for the message display
 *
 * Display and format a error messages, gives file, line, position and
 * extra parameters.
 */
static void
errorDebug(void *ctx ATTRIBUTE_UNUSED, const char *msg, ...)
{
	va_list args;

	callbacks++;
	if (quiet)
		return;
	#ifdef DISABLE_STDOUT
	va_start(args, msg);
	fprintf(stdout, "SAX.error: ");
	vfprintf(stdout, msg, args);
	va_end(args);
	#endif
}

/**
 * fatalErrorDebug:
 * @ctxt:  An XML parser context
 * @msg:  the message to display/transmit
 * @...:  extra parameters for the message display
 *
 * Display and format a fatalError messages, gives file, line, position and
 * extra parameters.
 */
static void
fatalErrorDebug(void *ctx ATTRIBUTE_UNUSED, const char *msg, ...)
{
	va_list args;

	callbacks++;
	if (quiet)
		return;
	#ifdef DISABLE_STDOUT
	va_start(args, msg);
	fprintf(stdout, "SAX.fatalError: ");
	vfprintf(stdout, msg, args);
	va_end(args);
	#endif
}


xmlSAXHandler debugSAXHandlerStruct = {
	internalSubsetDebug,
	isStandaloneDebug,
	hasInternalSubsetDebug,
	hasExternalSubsetDebug,
	resolveEntityDebug,
	getEntityDebug,
	entityDeclDebug,
	notationDeclDebug,
	attributeDeclDebug,
	elementDeclDebug,
	unparsedEntityDeclDebug,
	setDocumentLocatorDebug,
	startDocumentDebug,
	endDocumentDebug,
	startElementDebug,
	endElementDebug,
	referenceDebug,
	charactersDebug,
	ignorableWhitespaceDebug,
	processingInstructionDebug,
	commentDebug,
	warningDebug,
	errorDebug,
	fatalErrorDebug,
	getParameterEntityDebug,
	cdataBlockDebug,
	externalSubsetDebug,
	1,
	NULL,
	NULL,
	NULL,
	NULL
};
xmlSAXHandlerPtr debugSAXHandler = &debugSAXHandlerStruct;

/*
 * SAX2 specific callbacks
 */
/**
 * startElementNsDebug:
 * @ctxt:  An XML parser context
 * @name:  The element name
 *
 * called when an opening tag has been processed.
 */
static void
startElementNsDebug(void *ctx ATTRIBUTE_UNUSED,
                    const xmlChar *localname,
                    const xmlChar *prefix,
                    const xmlChar *URI,
                    int nb_namespaces,
                    const xmlChar **namespaces,
                    int nb_attributes,
                    int nb_defaulted,
                    const xmlChar **attributes)
{
	int i;

	callbacks++;
	if (quiet)
		return;
	#ifdef DISABLE_STDOUT
	fprintf(stdout, "SAX.startElementNs(%s", (char *) localname);
	if (prefix == NULL)
		fprintf(stdout, ", NULL");
	else
		fprintf(stdout, ", %s", (char *) prefix);
	if (URI == NULL)
		fprintf(stdout, ", NULL");
	else
		fprintf(stdout, ", '%s'", (char *) URI);
	fprintf(stdout, ", %d", nb_namespaces);

	if (namespaces != NULL) {
		for (i = 0;i < nb_namespaces * 2;i++) {
			fprintf(stdout, ", xmlns");
			if (namespaces[i] != NULL)
				fprintf(stdout, ":%s", namespaces[i]);
			i++;
			fprintf(stdout, "='%s'", namespaces[i]);
		}
	}
	fprintf(stdout, ", %d, %d", nb_attributes, nb_defaulted);
	if (attributes != NULL) {
		for (i = 0;i < nb_attributes;i += 5) {
			if (attributes[i + 1] != NULL)
				fprintf(stdout, ", %s:%s='", attributes[i + 1], attributes[i]);
			else
				fprintf(stdout, ", %s='", attributes[i]);
			fprintf(stdout, "%.4s...', %d", attributes[i + 3],
			        (int)(attributes[i + 4] - attributes[i + 3]));
		}
	}
	fprintf(stdout, ")\n");
	#endif
}

/**
 * endElementDebug:
 * @ctxt:  An XML parser context
 * @name:  The element name
 *
 * called when the end of an element has been detected.
 */
static void
endElementNsDebug(void *ctx ATTRIBUTE_UNUSED,
                  const xmlChar *localname,
                  const xmlChar *prefix,
                  const xmlChar *URI)
{
	callbacks++;
	if (quiet)
		return;
	#ifdef DISABLE_STDOUT
	fprintf(stdout, "SAX.endElementNs(%s", (char *) localname);
	if (prefix == NULL)
		fprintf(stdout, ", NULL");
	else
		fprintf(stdout, ", %s", (char *) prefix);
	if (URI == NULL)
		fprintf(stdout, ", NULL)\n");
	else
		fprintf(stdout, ", '%s')\n", (char *) URI);
	#endif
}

xmlSAXHandler debugSAX2HandlerStruct = {
	internalSubsetDebug,
	isStandaloneDebug,
	hasInternalSubsetDebug,
	hasExternalSubsetDebug,
	resolveEntityDebug,
	getEntityDebug,
	entityDeclDebug,
	notationDeclDebug,
	attributeDeclDebug,
	elementDeclDebug,
	unparsedEntityDeclDebug,
	setDocumentLocatorDebug,
	startDocumentDebug,
	endDocumentDebug,
	NULL,
	NULL,
	referenceDebug,
	charactersDebug,
	ignorableWhitespaceDebug,
	processingInstructionDebug,
	commentDebug,
	warningDebug,
	errorDebug,
	fatalErrorDebug,
	getParameterEntityDebug,
	cdataBlockDebug,
	externalSubsetDebug,
	XML_SAX2_MAGIC,
	NULL,
	startElementNsDebug,
	endElementNsDebug,
	NULL
};

xmlSAXHandlerPtr debugSAX2Handler = &debugSAX2HandlerStruct;

#define gen_nb_xmlParserCtxtPtr 1
static xmlParserCtxtPtr gen_xmlParserCtxtPtr(int no, int nr ATTRIBUTE_UNUSED)
{
	if (no == 0) return(xmlNewParserCtxt());
	if (no == 1) return(xmlCreateMemoryParserCtxt("<doc/>", 6));
	return(NULL);
}
static void des_void_ptr(int no ATTRIBUTE_UNUSED, void *val ATTRIBUTE_UNUSED, int nr ATTRIBUTE_UNUSED)
{
}
#define gen_nb_const_xmlChar_ptr 4

static xmlChar *gen_const_xmlChar_ptr(int no, int nr ATTRIBUTE_UNUSED)
{
	if (no == 0) return((xmlChar *) "<foo>");
	if (no == 1) return((xmlChar *) "<foo/>");
	if (no == 2) return((xmlChar *) " none ");
	if (no == 3) return((xmlChar *) " 2ab ");
	return(NULL);
}
static void des_const_xmlChar_ptr(int no ATTRIBUTE_UNUSED, const xmlChar *val ATTRIBUTE_UNUSED, int nr ATTRIBUTE_UNUSED)
{
}
static void desret_xmlEntityPtr(xmlEntityPtr val)
{
	if (val != NULL) {
		xmlUnlinkNode((xmlNodePtr) val);
		xmlFreeNode((xmlNodePtr) val);
	}
}

#if 0
/**    
	* @test			UTcSaxP01
	* @brief		int xmlSAXUserParseFile (xmlSAXHandlerPtr sax, void * user_data, const char * filename)
					int xmlParseChunk (xmlParserCtxtPtr ctxt, const char * chunk, int size,int terminate)
	* @desc			Positive Test for parsing an XML file and call the given SAX handler routines
					Positive test for Parsing a Chunk of memory
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Michel Anthony (michelj@samsung.com)
	* @return		void
	* @see			none
	* @remarks		input1: [1.Sax Handler is created with NULL callbacks, N/A]	@n
		 			{emptySAXHandler,NULL, const char * pFilename} => {N/A |0}	@n
					input2: [1.Sax Handler is created with NULL callbacks, N/A]	@n
		 			{xmlParserCtxtPtr(ctxt), const char *(filename), int(size), int(terminate)} => {N/A |0 if no error}	@n	
	* @b priority	Middle
	* @b etc		none
	*/
static void
UTcSaxP01()
{
	FILE*  file = NULL;
	int i =0;
	int ret = 0;
	int res;
	const char *pChar;
	xmlParserCtxtPtr ctxt = NULL;
	char *pFileBuffer = NULL;
	unsigned char pByte[5];
	const char *pFilename = LIBXML2TESTXML;
	struct stat sb;
	int  size = 0;
	char Buff[64] = {0,};
	int readlen =0;
	
	file = fopen(pFilename, "r");
	if(file == NULL) {
		DTS_FAIL("UTcSaxP01", "file Construct() failed in pre-condition");
		return;
	}
	if (stat(pFilename, &sb) == -1) {
		perror("stat");
		return;
	}

	snprintf(Buff, 63, "File size: %lld bytes\n", (long long) sb.st_size);
	DTS_PRINT("UTcSaxP01", Buff);	
	size = (int)sb.st_size;

	pFileBuffer = (char *)calloc(1, size +1);
	if (pFileBuffer == NULL) {
		fclose(file);
		DTS_FAIL("UTcSaxP01", "ByteBuffer Construct() failed in pre-condition");
	}

	readlen = fread(pFileBuffer, 1, size, file);
	if (readlen != size) {
		free(pFileBuffer);
		fclose(file);
		DTS_FAIL("UTcSaxP01", "file Read() failed");
	}

	memcpy(pByte, pFileBuffer, 4);
	size = size - 4;
	pChar = (char *)(pByte);

	/*
	 * Create xmlSAXHandlerPtr with Empty callbacks
	 */
	ctxt = xmlCreatePushParserCtxt(emptySAXHandler, NULL,pChar, 4, pFilename);
	DTS_CHECK_NE_MESSAGE("UTcSaxP01", (void *)ctxt, (void *)NULL, "Status of allocating parser context\n");	

	//byteData.Flip();
	for (i =0; size-i >=4 ;i=i+4) {
		memcpy(pByte, pFileBuffer+i, 4);
		res = xmlParseChunk(ctxt, (char *)(pByte), 4,0);
		DTS_CHECK_EQ_MESSAGE("UTcSaxP01", (void *)res, (void *)0, "Failed xmlParseChunk");	

	}

	if (NULL == ctxt) {
		free(pFileBuffer);
		fclose( file);
		DTS_FAIL("UTcSaxP01", "Parsing chunk failed");
	}

	//res = xmlParseChunk(ctxt, pChar, 0, 1);
	// MT_CHECK_MESSAGE2(res != 0, "Failed xmlParseChunk");
	xmlFreeParserCtxt(ctxt);
	//file->Remove(pFilename);

	for (i = 0; i<4;i++) {

		/**
		 * @remarks   input1: [1.Sax Handler is created with NULL callbacks, N/A]	@n
		 *					{emptySAXHandler,NULL, pFilename} => {N/A |0}	@n
		 */
		res = xmlSAXUserParseFile(emptySAXHandler, NULL, pFilename);
		DTS_CHECK_EQ_MESSAGE("UTcSaxP01", (void *)res, (void *)0, "Failed xmlParseChunk");	

	}

	free(pFileBuffer);
	fclose( file);	
	/**
	 * @post Cleanup function for the XML library.
	 */
	//if(pByte)
	//	delete pByte;
}
/**    
	* @test			UTcSaxP02
	* @brief		int xmlSAXUserParseFile (xmlSAXHandlerPtr sax, void * user_data, const char * filename)
					int xmlParseChunk (xmlParserCtxtPtr ctxt, const char * chunk, int size,int terminate)
	* @desc			Positive Test for parsing an XML file and call the given SAX handler routines
					Positive test for Parsing a Chunk of memory
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Michel Anthony (michelj@samsung.com)
	* @return		void
	* @see			none
	* @remarks		input1: [1.Sax Handler is created with NULL callbacks, N/A]	@n
					{emptySAXHandler,NULL, const char *pFilename} => {N/A |0}	@n
					input2: [1.Sax Handler is created with NULL callbacks, N/A]	@n
		 			{xmlParserCtxtPtr(ctxt), const char *(chunk), int(size), int(terminate)} => {N/A |0 if no error}	@n	
	* @b priority	Middle
	* @b etc		none
	*/
	#if 0
static void
UTcSaxP02()
{
	File*  file = new File();
	FileAttributes attr;
	int ret = 0;
	int res;
	const char *pChar;
	xmlParserCtxtPtr ctxt = NULL;
	ByteBuffer byteData;
	//byte *pByte = new byte(5);
	unsigned char pByte[5];
         //Target
	const char *pFilename = LIBXML2TESTXML;

#if 0

	result r = file->Construct(pFilename, L"r");
	if (r != E_SUCCESS) {
		delete file;
		file = NULL;
		MT_FAIL("file Construct() failed in pre-condition");
	}
	r = file->GetAttributes(pFilename,attr);
	int  size = (int)attr.GetFileSize();

	r = byteData.Construct(size);
	if (r != E_SUCCESS) {
		delete file;
		file = NULL;
		MT_FAIL("ByteBuffer Construct() failed in pre-condition");
	}

	r = file->Read(byteData);
	if (r != E_SUCCESS) {
		delete file;
		file = NULL;
		MT_FAIL("file Read() failed");
	}
	byteData.Flip();

	r = byteData.GetArray(pByte,0,4);
	size = size - 4;
	MT_CHECK_MESSAGE2(r == E_SUCCESS, "Failed byteData.GetArray()");
	pChar = (char *)(pByte);
#endif

/** TODO GOPAL write code to read from the file **/
	/*
	 * Create xmlSAXHandlerPtr with Empty callbacks
	 */
	ctxt = xmlCreatePushParserCtxt(debugSAXHandler, NULL,pChar, 4, pFilename);
	MT_CHECK_MESSAGE2(ctxt != NULL, "Status of allocating parser context\n");

	//byteData.Flip();
	for (int i =0; size-i >=4 ;i=i+4) {
		r = byteData.GetArray(pByte,0,4);
		if (r != E_SUCCESS) {
			break;
		}
		res = xmlParseChunk(ctxt, (char *)(pByte), 4,0);
		MT_CHECK_MESSAGE2(res == 0, "Failed xmlParseChunk");

	}

	if (NULL == ctxt) {
		delete file;
		file = NULL;
		MT_FAIL("Parsing chunk failed");
	}

	//res = xmlParseChunk(ctxt, pChar, 0, 1);
	// MT_CHECK_MESSAGE2(res != 0, "Failed xmlParseChunk");
	xmlFreeParserCtxt(ctxt);
	//file->Remove(pFilename);

	for (int i = 0; i<4;i++) {

		/**
		 * @remarks   input1: [1.Sax Handler is created with NULL callbacks, N/A]	@n
		 *					{emptySAXHandler,NULL, pFilename} => {N/A |0}	@n
		 */
		res = xmlSAXUserParseFile(debugSAXHandler, NULL, pFilename);
		MT_CHECK_MESSAGE2(res == 0, "xmlSAXUserParseFile returned error %d\n", res);

	}
	delete file;
	/**
	 * @post Cleanup function for the XML library.
	 */
	//if(pByte)
	//	delete pByte;
}
/**    
	* @test			UTcSaxP03
	* @brief		int xmlSAXUserParseFile (xmlSAXHandlerPtr sax, void * user_data, const char * filename)
					int xmlParseChunk (xmlParserCtxtPtr ctxt, const char * chunk, int size,int terminate)
	* @desc			Positive Test for parsing an XML file and call the given SAX handler routines
					Positive test for Parsing a Chunk of memory
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Michel Anthony (michelj@samsung.com)
	* @return		void
	* @see			none
	* @remarks		input1: [1.Sax Handler is created with NULL callbacks, N/A]	@n
		 			{emptySAXHandler,NULL, const char * pFilename} => {N/A |0}	@n
					input2: [1.Sax Handler is created with NULL callbacks, N/A]	@n
		 			{xmlParserCtxtPtr(sax), const char *(chunk), int(size), int(terminate)} => {N/A |0 if no error}	@n	
	* @b priority	Middle
	* @b etc		none
	*/
static void
UTcSaxP03()
{
	File*  file = new File();
	FileAttributes attr;
	int ret = 0;
	int res;
	const char *pChar;
	xmlParserCtxtPtr ctxt = NULL;
	ByteBuffer byteData;
	//byte *pByte = new byte(5);
	unsigned char pByte[5];
	
	const char *pFilename = LIBXML2TESTXML;


	result r = file->Construct(pFilename, L"r");
	if (r != E_SUCCESS) {
		delete file;
		file = NULL;
		MT_FAIL("file Construct() failed in pre-condition");
	}
	r = file->GetAttributes(pFilename,attr);
	int  size = (int)attr.GetFileSize();

	r = byteData.Construct(size);
	if (r != E_SUCCESS) {
		delete file;
		file = NULL;
		MT_FAIL("ByteBuffer Construct() failed in pre-condition");
	}

	r = file->Read(byteData);
	if (r != E_SUCCESS) {
		delete file;
		file = NULL;
		MT_FAIL("file Read() failed");
	}
	byteData.Flip();

	r = byteData.GetArray(pByte,0,4);
	size = size - 4;
	MT_CHECK_MESSAGE2(r == E_SUCCESS, "Failed byteData.GetArray()");
	pChar = (char *)(pByte);

	/*
	 * Create xmlSAXHandlerPtr with Empty callbacks
	 */
	ctxt = xmlCreatePushParserCtxt(debugSAX2Handler, NULL,pChar, 4, pFilename);
	MT_CHECK_MESSAGE2(ctxt != NULL, "Status of allocating parser context\n");

	//byteData.Flip();
	for (int i =0; size-i >=4 ;i=i+4) {
		r = byteData.GetArray(pByte,0,4);
		if (r != E_SUCCESS) {
			break;
		}
		res = xmlParseChunk(ctxt, (char *)(pByte), 4,0);
		MT_CHECK_MESSAGE2(res == 0, "Failed xmlParseChunk");

	}

	if (NULL == ctxt) {
		delete file;
		file = NULL;
		MT_FAIL("Parsing chunk failed");
	}

	//res = xmlParseChunk(ctxt, pChar, 0, 1);
	// MT_CHECK_MESSAGE2(res != 0, "Failed xmlParseChunk");
	xmlFreeParserCtxt(ctxt);
	//file->Remove(pFilename);

	for (int i = 0; i<4;i++) {

		/**
		 * @remarks   input1: [1.Sax Handler is created with NULL callbacks, N/A]	@n
		 *					{emptySAXHandler,NULL, pFilename} => {N/A |0}	@n
		 */
		res = xmlSAXUserParseFile(debugSAX2Handler, NULL, pFilename);
		MT_CHECK_MESSAGE2(res == 0, "xmlSAXUserParseFile returned error %d\n", res);

	}
	delete file;
	/**
	 * @post Cleanup function for the XML library.
	 */
	//if(pByte)
	//	delete pByte;
}


static void ParseFSMstartElementNs(void * ctx,
                           const xmlChar * localname,
                           const xmlChar * prefix,
                           const xmlChar * URI,
                           int nb_namespaces,
                           const xmlChar ** namespaces,
                           int nb_attributes,
                           int nb_defaulted,
                           const xmlChar ** attributes) {
	#ifdef DISABLE_PRINTF
	printf("startElementNs: name = '%s' prefix = '%s' uri = (%p)'%s'\n", localname, prefix, URI, URI);
	#endif
	for (int indexNamespace = 0; indexNamespace < nb_namespaces; ++indexNamespace) {
		const xmlChar *prefix = namespaces[indexNamespace*2];
		const xmlChar *nsURI = namespaces[indexNamespace*2+1];
		#ifdef DISABLE_PRINTF
		printf("  namespace: name='%s' uri=(%p)'%s'\n", prefix, nsURI, nsURI);
		#endif
	}

	unsigned int index = 0;
	for (int indexAttribute = 0;
	                indexAttribute < nb_attributes;
	                ++indexAttribute, index += 5) {
		const xmlChar *localname = attributes[index];
		const xmlChar *prefix = attributes[index+1];
		const xmlChar *nsURI = attributes[index+2];
		const xmlChar *valueBegin = attributes[index+3];
		const xmlChar *valueEnd = attributes[index+4];

	}
}

static void ParseFSMendElementNs(void * ctx,
                         const xmlChar * localname,
                         const xmlChar * prefix,
                         const xmlChar * URI) {
	#ifdef DISABLE_PRINTF
	printf("endElementNs: name = '%s' prefix = '%s' uri = '%s'\n", localname, prefix, URI);
	#endif
}

/** Display and format an error messages, callback.
   ctx:  an XML parser context
   msg:  the message to display/transmit
   ...:  extra parameters for the message display
   */
static void ParseFSMerror(void * ctx,
                  const char * msg,
                  ...) {
	va_list args;
	va_start(args, msg);
	#ifdef DISABLE_PRINTF
	vprintf(msg, args);
	#endif
	va_end(args);
}

/** Display and format a warning messages, callback.
   ctx:  an XML parser context
   msg:  the message to display/transmit
   ...:  extra parameters for the message display
   */
static void ParseFSMwarning(void * ctx,
                    const char * msg,
                    ...) {
	va_list args;
	va_start(args, msg);
	vprintf(msg, args);
	va_end(args);
}

/**    
	* @test			UTcSaxP04
	* @brief		int xmlSAXUserParseMemory (xmlSAXHandlerPtr sax, void * user_data, const char * buffer, int size)
	* @desc			Positive test to parse an XML in-memory buffer and call the given SAX handler routines.
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Michel Anthony (michelj@samsung.com)
	* @return		void
	* @see			none
	* @remarks		input1: [1.Sax Handler is created and callbacks are assigned, N/A]	@n
	 				{xmlSAXHandlerPtr debugSAX2Handler,const char * xmlIn,size of xmlIn} => {N/A |0}	@n
	* @b priority	Middle
	* @b etc		none
	*/
static void
UTcSaxP04()
{

	char xmlIn[] =
	        "<test:Plan xmlns:test='http://test.org/schema'>"
	        "<test:Case name='test1' emptyAttribute='' test:ns_id='auio'>"
	        "</test:Case>"
	        "</test:Plan>";

	

	/*
	 * Create xmlSAXHandlerPtr with SAX2 related callbacks
	 */
	xmlSAXHandler saxHandler;
	memset(&saxHandler, 0, sizeof(saxHandler));

	saxHandler.initialized = XML_SAX2_MAGIC;
	saxHandler.startElementNs = ParseFSMstartElementNs;
	saxHandler.endElementNs = ParseFSMendElementNs;
	saxHandler.warning = ParseFSMwarning;
	saxHandler.error = ParseFSMerror;

	/**
	 * @remarks   input1: [1.Sax Handler is created and callbacks are assigned, N/A]	@n
	 *					{debugSAX2Handler,fsm,xmlIn,size of xmlIn} => {N/A |0}	@n
	 */
	int result = xmlSAXUserParseMemory(debugSAX2Handler, &saxHandler, xmlIn, strlen(xmlIn));
	MT_CHECK_MESSAGE2(result == 0, "Failed to parse document.");

	/**
	 * @post Cleanup function for the XML library.
	 */
}
/**    
	* @test			UTcSaxP05
	* @brief		void initxmlDefaultSAXHandler (xmlSAXHandlerV1 * hdlr, int warning)
	* @desc			Positive Test for Initializing the default XML SAX version 1 handler
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Michel Anthony (michelj@samsung.com)
	* @return		void
	* @see			none
	* @remarks		input1: [N/A, N/A] @n
	*   			{emptySAXHandlerV1,int(0)} => {N/A |N/A}	@n
					input2: [N/A, N/A] @n
	*   			{xmlSAXHandlerV1 * saxHandlerV1,int(0)} => {N/A |N/A}	@n
					input3: [N/A, N/A] @n
	*   			{xmlSAXHandlerV1 * saxHandlerV2,int(0)} => {N/A |N/A}	@n
	* @b priority	Middle
	* @b etc		none
	*/
static void
UTcSaxP05()
{
	xmlSAXHandlerV1* saxHandlerV1;
	xmlSAXHandlerV1* saxHandlerV2;
	
	saxHandlerV1 =(xmlSAXHandlerV1 *) xmlMemMalloc(sizeof(xmlSAXHandlerV1));
	saxHandlerV2 =(xmlSAXHandlerV1 *) xmlMemMalloc(sizeof(xmlSAXHandlerV1));

	/**
	 * @remarks   input1: [N/A, N/A]	@n
	 *					{emptySAXHandlerV1,0} => {N/A |N/A}	@n
	 */
	initxmlDefaultSAXHandler(emptySAXHandlerV1,0);
	MT_CHECK_MESSAGE2(emptySAXHandlerV1 != NULL, "initxmlDefaultSAXHandler failed\n");

	/**
	 * @remarks   input2: [N/A, N/A]	@n
	 *					{saxHandlerV1,0} => {N/A |N/A}	@n
	 */
	initxmlDefaultSAXHandler(saxHandlerV1,0);
	MT_CHECK_MESSAGE2(saxHandlerV1 != NULL, "initxmlDefaultSAXHandler failed\n");

	/**
	 * @remarks   input3: [N/A, N/A]	@n
	 *					{saxHandlerV2,0} => {N/A |N/A}	@n
	 */
	initxmlDefaultSAXHandler(saxHandlerV2,1);
	MT_CHECK_MESSAGE2(saxHandlerV2 != NULL, "initxmlDefaultSAXHandler failed\n");

	xmlMemFree(saxHandlerV1);
	xmlMemFree(saxHandlerV2);
	xmlFree(emptySAXHandlerV1);
}
/**    
	* @test			UTcSaxP06
	* @brief		int	xmlSAXDefaultVersion (int version)
					int	xmlSAX2IsStandalone	(void * ctx)
					int	xmlSAX2HasInternalSubset (void * ctx)
					int	xmlSAX2HasExternalSubset (void * ctx)
					const xmlChar *	xmlSAX2GetPublicId	(void * ctx)
					const xmlChar *	xmlSAX2GetPublicId	(void * ctx)
					int	xmlSAX2GetLineNumber (void * ctx)
					int	xmlSAX2GetColumnNumber	(void * ctx)
					void xmlSAX2CDataBlock (void * ctx, const xmlChar * value, int len)
					void xmlSAX2Comment (void * ctx, const xmlChar * value)
					void xmlSAX2EndElement (void * ctx, const xmlChar * name)
	* @desc			Positive test for Setting the default version of SAX used globally by the library
					Positive test for checking if the document is tagged for standalone
					Positive test for checking if document has an internal subset
					Positive test for checking if document has an external subset
					Positive test for checking if it Provides the public ID 
					Positive test for Providing the line number of the current parsing point.
					Positive test for Providing the column number of the current parsing point
					Positive test for xmlSAX2CDataBlock
					Positive test for checking if A xmlSAX2Comment has been parsed.
					Positive test for checking if end of file is detected
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Michel Anthony (michelj@samsung.com)
	* @return		void
	* @see			none
	* @remarks		input1: [1.calling xmlSAXDefaultVersion Api, N/A]	@n
	 				{1} => {N/A | 2}	@n
					input2: [1.Calling  xmlSAX2IsStandalone Api, N/A]	@n
	 				{ctxt} => {N/A | 0}	@n
					input3: [1.Calling  xmlSAX2HasInternalSubset Api, N/A]	@n
	 				{ctxt} => {N/A | 1}	@n
					input4: [1.Calling  xmlSAX2HasInternalSubset Api, N/A]	@n
	 				{ctxt} => {N/A | 0}	@n
					input5: [1.Calling  xmlSAX2GetPublicId Api, N/A]	@n
	 				{ctxt} => {N/A | xmlChar pointer}	@n
					input6: [1.Calling  xmlSAX2GetSystemId Api, N/A]	@n
	 				{ctxt} => {N/A |const  xmlChar pointer}	@n
					input7: [1.Calling  xmlSAX2GetLineNumber Api, N/A]	@n
					{ctxt} => {N/A |1}	@n
					input8: [1.Calling  xmlSAX2GetColumnNumber Api, N/A]	@n
					{ctxt} => {N/A |1}	@n
					 input9: [1.Calling  xmlSAX2CDataBlock Api, N/A]	@n
					{ctxt,"Case",4} => {N/A |N/A}	@n
					input10: [1.Calling  xmlSAX2Comment Api, N/A]	@n
					{ctxt,"test"} => {N/A |N/A}	@n
					input11: [1.Calling  xmlSAX2EndElement Api, N/A]	@n
					{ctxt,""test""} => {N/A |N/A}	@n
	* @b priority	Middle
	* @b etc		none
	*/
static void
UTcSaxP06()
{
	xmlParserCtxtPtr ctxt;
	xmlSAXHandler *saxHandler;
	xmlErrorPtr				pError;
	const xmlChar * result_char = NULL;
	String StrTest = "test";
	String xmlIn =
	        "<test:Plan xmlns:test='http://test.org/schema'>"
	        "<test:Case name='test1' emptyAttribute='' test:ns_id='auio'>"
	        "</test:Case>"
	        "</test:Plan>";
	const xmlChar *sTest[3];
	sTest[0] = (xmlChar *) "testtwice";
	sTest[1] = NULL;
	sTest[2] = NULL;
	
	const char *pData = _StringConverter::CopyToCharArrayN(xmlIn);
	saxHandler =(xmlSAXHandler *) xmlMemMalloc(sizeof(xmlSAXHandler));
	
	memset(saxHandler, 0, sizeof(xmlSAXHandler));

	xmlSAX2InitDefaultSAXHandler(saxHandler,0);
	MT_CHECK_MESSAGE2(saxHandler != NULL, "xmlSAX2InitDefaultSAXHandler failed\n");

	/**
	 * @remarks   input1: [1.calling xmlSAXDefaultVersion Api, N/A]	@n
	 *					{1} => {N/A | 2}	@n
	 */
	int result = xmlSAXDefaultVersion(1);
	MT_CHECK_MESSAGE2(result == 2, "xmlSAXDefaultVersion failed\n");


	result = xmlSAXDefaultVersion(2);
	MT_CHECK_MESSAGE2(result == 1, "xmlSAXDefaultVersion failed\n");

	result = xmlSAXDefaultVersion(3);
	MT_CHECK_MESSAGE2(result == -1, "xmlSAXDefaultVersion failed\n");
	
	ctxt = xmlCreatePushParserCtxt(saxHandler,(void *)"test:case",(const char *)"test",xmlIn.GetLength(),pData );
	MT_CHECK_MESSAGE2(ctxt != NULL, "Status of allocating parser context\n");


	xmlSAX2StartDocument(ctxt);

	ctxt->myDoc->intSubset = xmlCreateIntSubset(ctxt->myDoc, (const xmlChar*)"intsubset",(const xmlChar*)"foo", (const xmlChar*)"foo");
	ctxt->myDoc->intSubset->attributes = (void *)"test";

	xmlResetLastError();
	xmlSAX2StartElement(ctxt,(const xmlChar *)"test", (const xmlChar **)sTest);
	pError = xmlGetLastError();
	MT_CHECK_MESSAGE("checking the result for xmlSAX2StartElement", pError == NULL);

	/**
	 * @remarks   input2: [1.Calling  xmlSAX2IsStandalone Api, N/A]	@n
	 *					{ctxt} => {N/A | 0}	@n
	 */

	result = xmlSAX2IsStandalone(ctxt);
	MT_CHECK_MESSAGE2(result == 0, "xmlSAX2IsStandalone failed\n");

	/**
	 * @remarks   input3: [1.Calling  xmlSAX2HasInternalSubset Api, N/A]	@n
	 *					{ctxt} => {N/A | 1}	@n
	 */
	result = xmlSAX2HasInternalSubset(ctxt);
	MT_CHECK_MESSAGE2(result == 1, "xmlSAX2HasInternalSubset failed\n");

	/**
	 * @remarks   input4: [1.Calling  xmlSAX2HasInternalSubset Api, N/A]	@n
	 *					{ctxt} => {N/A | 0}	@n
	 */
	result = xmlSAX2HasExternalSubset(ctxt);
	MT_CHECK_MESSAGE2(result == 0, "xmlSAX2HasExternalSubset failed\n");

	xmlResetLastError();
	ctxt->inSubset = 1;
	xmlSAX2EntityDecl(ctxt,(const xmlChar *)"test", 1,(const xmlChar *)"test",(const xmlChar *)"test", (xmlChar *)"hello");
	pError = xmlGetLastError();
	MT_CHECK_MESSAGE("checking the result for xmlSAX2EntityDecl", pError == NULL);

	xmlResetLastError();

#ifdef FEATURE_TODO
	/**
	 * @remarks   input5: [1.Calling  xmlSAX2GetPublicId Api, N/A]	@n
	 *					{ctxt} => {N/A | xmlChar pointer}	@n
	 */
	result_char = xmlSAX2GetPublicId(ctxt);
	MT_CHECK_MESSAGE2(result_char != NULL, "xmlSAX2GetPublicId failed\n");
	xmlFree((void *)result_char);
#endif
	/**
	 * @remarks   input6: [1.Calling  xmlSAX2GetSystemId Api, N/A]	@n
	 *					{ctxt} => {N/A |const  xmlChar pointer}	@n
	 */
	result_char = xmlSAX2GetSystemId(ctxt);
	MT_CHECK_MESSAGE2(result_char != NULL, "xmlSAX2GetSystemId failed\n");
	xmlFree((void *)result_char);
	/**
	 * @remarks   input7: [1.Calling  xmlSAX2GetLineNumber Api, N/A]	@n
	 *					{ctxt} => {N/A |1}	@n
	 */

	result = xmlSAX2GetLineNumber(ctxt);
	MT_CHECK_MESSAGE2(result == 1, "xmlSAX2HasInternalSubset failed\n");

	/**
	 * @remarks   input8: [1.Calling  xmlSAX2GetColumnNumber Api, N/A]	@n
	 *					{ctxt} => {N/A |1}	@n
	 */
	result = xmlSAX2GetColumnNumber(ctxt);
	MT_CHECK_MESSAGE2(result == 1, "xmlSAX2HasInternalSubset failed\n");

	/**
	 * @remarks   input9: [1.Calling  xmlSAX2CDataBlock Api, N/A]	@n
	 *					{ctxt,"Case",4} => {N/A |N/A}	@n
	 */
	xmlResetLastError();
	xmlSAX2CDataBlock(ctxt,(const xmlChar *)"test",4);
	pError = xmlGetLastError();
	 MT_CHECK_MESSAGE("checking the result for xmlSAX2EndDocument", pError == NULL);

	/**
	 * @remarks   input10: [1.Calling  xmlSAX2Comment Api, N/A]	@n
	 *					{ctxt,"test"} => {N/A |N/A}	@n
	 */
	xmlResetLastError();
	xmlSAX2Comment(ctxt,(const xmlChar *)"test");
	pError = xmlGetLastError();
	MT_CHECK_MESSAGE("checking the result for xmlSAX2EndDocument", pError == NULL);

	/**
	 * @remarks   input11: [1.Calling  xmlSAX2EndElement Api, N/A]	@n
	 *					{ctxt,""test""} => {N/A |N/A}	@n
	 */
	xmlResetLastError();
	xmlSAX2EndElement(ctxt,(const xmlChar *)"test");
	pError = xmlGetLastError();
	MT_CHECK_MESSAGE("checking the result for xmlSAX2EndDocument", pError == NULL);


	xmlResetLastError();
	xmlSAX2EndDocument(ctxt);
	pError = xmlGetLastError();
	MT_CHECK_MESSAGE("checking the result for xmlSAX2EndDocument", pError == NULL);

	/**
	 * @post Cleanup function for the XML library.
	 */
	if(pData != NULL)
		delete pData;

	/*if(sTest != NULL)
		delete sTest;
	xmlFreeDtd(ctxt->myDoc->intSubset);*/

	//xmlFreeDoc(ctxt->myDoc);
	xmlFreeParserCtxt(ctxt);
	xmlMemFree(saxHandler);

	//if(pError != NULL)
	//	delete pError;
}
/**    
	* @test			UTcSaxP07
	* @brief		void xmlSAX2EntityDecl (void * ctx, const xmlChar * name, int type, const xmlChar * publicId, const xmlChar * systemId, xmlChar * content)
					void xmlSAX2UnparsedEntityDecl (void * ctx, const xmlChar * name, const xmlChar * publicId, const xmlChar * systemId, const xmlChar * notationName)
					void xmlSAX2EntityDecl (void * ctx, const xmlChar * name, int type, const xmlChar * publicId, const xmlChar * systemId, xmlChar * content)
					void xmlSAX2UnparsedEntityDecl (void * ctx, const xmlChar * name, const xmlChar * publicId, const xmlChar * systemId, const xmlChar * notationName)
					xmlEntityPtr xmlSAX2GetEntity (void * ctx, const xmlChar * name)
					xmlEntityPtr xmlSAX2GetParameterEntity (void * ctx, const xmlChar * name)
					xmlEntityPtr xmlSAX2GetEntity (void * ctx, const xmlChar * name)
					xmlEntityPtr xmlSAX2GetEntity (void * ctx, const xmlChar * name)
	* @desc			Positive Test for checking if an entity definition has been parsed
					Positive Test for xmlSAX2UnparsedEntityDecl
					Positive Test for getting entity name
					Positive Test for Getting a parameter entity by name			
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Michel Anthony (michelj@samsung.com)
	* @return		void
	* @see			none
	* @remarks		input1: [1.calling xmlSAX2EntityDecl Api, N/A]	@n
	 				{ctxt,const xmlChar * "foo",const xmlChar * "foo"} => {N/A |N/A}	@n
					input2: [1.calling xmlSAX2UnparsedEntityDecl Api, N/A]	@n
	 				{ctxt,const xmlChar * "foo",const xmlChar * "foo",const xmlChar * "foo"} => {N/A |N/A}	@n
					 input3: [1.calling xmlSAX2EntityDecl Api, N/A]	@n
					{ctxt,const xmlChar * "foo",1,const xmlChar * "foo",const xmlChar * "foo",const xmlChar * "foo"} => {N/A |N/A}	@n
					 input4: [1.calling xmlSAX2UnparsedEntityDecl Api, N/A]	@n
					{ctxt,const xmlChar * "foo",const xmlChar * "foo",const xmlChar * "foo",const xmlChar * "foo"} => {N/A |N/A}	@n
					input5: [1.calling xmlSAX2GetEntity Api, N/A]	@n
					{ctxt,const xmlChar * "foo",const xmlChar * "foo",const xmlChar * "foo",const xmlChar * "foo"} => {N/A |xmlEntityPtr}	@n
					input6: [1.calling xmlSAX2GetParameterEntity Api, N/A]	@n
					{ctxt,const xmlChar *"foo"} => {N/A |NULL}	@n
					 input7: [1.calling xmlSAX2GetEntity Api, N/A]	@n
					{ctxt,const xmlChar *"foo"} => {N/A |xmlEntityPtr}	@n
					input8: [1.calling xmlSAX2GetEntity Api, N/A]	@n
					{ctxt,const xmlChar * "foo"} => {N/A |xmlEntityPtr}	@n
	* @b priority	Middle
	* @b etc		none
	*/

static void
UTcSaxP07()
{
	xmlParserCtxtPtr		ctxt;
	xmlSAXHandler			*pSaxHandler = NULL;
	xmlErrorPtr				pError;

	xmlResetLastError();
	pSaxHandler =(xmlSAXHandler *) xmlMemMalloc(sizeof(xmlSAXHandler));
	String xmlIn =
	        "<test:Plan xmlns:test='http://test.org/schema'>"
	        "<test:Case name='test1' emptyAttribute='' test:ns_id='auio'>"
	        "</test:Case>"
	        "</test:Plan>";

	memset(pSaxHandler, 0, sizeof(xmlSAXHandler));
	
	const char *pData = _StringConverter::CopyToCharArrayN(xmlIn);

	xmlSAX2InitDefaultSAXHandler(pSaxHandler,0);
	MT_CHECK_MESSAGE2(pSaxHandler != NULL, "xmlSAX2InitDefaultSAXHandler failed\n");

	ctxt = xmlCreatePushParserCtxt(pSaxHandler,(void *)"test:case",(const char *)"test",xmlIn.GetLength(), pData);
	MT_CHECK_MESSAGE2(ctxt != NULL, "Status of allocating parser context\n");

	xmlResetLastError();
	xmlSAX2Reference(ctxt, (const xmlChar*)"foo");
	pError = xmlGetLastError();
	MT_CHECK_MESSAGE("checking the result for xmlFreeEntitiesTable", pError == NULL);

	xmlResetLastError();
	ctxt->myDoc = xmlReadMemory("<!DOCTYPE foo []> <foo/>", 24, "test", NULL, 0);

	xmlSAX2ProcessingInstruction(ctxt, (const xmlChar*)"foo", (const xmlChar*)"foo");
	pError = xmlGetLastError();
	MT_CHECK_MESSAGE("checking the result for xmlFreeEntitiesTable", pError == NULL);

	xmlResetLastError();
	ctxt->inSubset = 1;
	/**
	 * @remarks   input1: [1.calling xmlSAX2EntityDecl Api, N/A]	@n
	 *					{ctxt,"foo","foo"} => {N/A |N/A}	@n
	 */
	xmlSAX2EntityDecl(ctxt, (const xmlChar*)"foo", 1, (const xmlChar*)"foo", (const xmlChar*)"foo", (xmlChar*)"foo");
	pError = xmlGetLastError();
	MT_CHECK_MESSAGE("checking the result for xmlFreeEntitiesTable", pError == NULL);

	xmlResetLastError();

	/**
	 * @remarks   input2: [1.calling xmlSAX2UnparsedEntityDecl Api, N/A]	@n
	 *					{ctxt,"foo","foo","foo"} => {N/A |N/A}	@n
	 */
	xmlSAX2UnparsedEntityDecl(ctxt, (const xmlChar*)"foo", (const xmlChar*)"foo", (const xmlChar*)"foo", (const xmlChar*)"foo");
	pError = xmlGetLastError();
	MT_CHECK_MESSAGE("checking the result for xmlFreeEntitiesTable", pError == NULL);

	xmlResetLastError();
	ctxt->inSubset = 2;
	/**
	 * @remarks   input3: [1.calling xmlSAX2EntityDecl Api, N/A]	@n
	 *					{ctxt,"foo",1,"foo","foo","foo"} => {N/A |N/A}	@n
	 */
	xmlSAX2EntityDecl(ctxt, (const xmlChar*)"foo", 1, (const xmlChar*)"foo", (const xmlChar*)"foo", (xmlChar*)"foo");
	pError = xmlGetLastError();
	MT_CHECK_MESSAGE("checking the result for xmlFreeEntitiesTable", pError == NULL);

	xmlResetLastError();
	/**
	 * @remarks   input4: [1.calling xmlSAX2UnparsedEntityDecl Api, N/A]	@n
	 *					{ctxt,"foo","foo","foo","foo"} => {N/A |N/A}	@n
	 */
	xmlSAX2UnparsedEntityDecl(ctxt, (const xmlChar*)"foo", (const xmlChar*)"foo", (const xmlChar*)"foo", (const xmlChar*)"foo");
	pError = xmlGetLastError();
	MT_CHECK_MESSAGE("checking the result for xmlFreeEntitiesTable", pError == NULL);

	/**
	 * @remarks   input5: [1.calling xmlSAX2GetEntity Api, N/A]	@n
	 *					{ctxt,"foo","foo","foo","foo"} => {N/A |xmlEntityPtr}	@n
	 */
	xmlEntityPtr pEntity = xmlSAX2GetEntity(ctxt, (const xmlChar*)"foo");
	MT_CHECK_MESSAGE("checking the result for xmlSAX2GetEntity", pEntity != NULL);
	//if (pEntity != NULL)
	//	delete pEntity;
	/**
	 * @remarks   input6: [1.calling xmlSAX2GetParameterEntity Api, N/A]	@n
	 *					{ctxt,"foo"} => {N/A |NULL}	@n
	 */
	ctxt->inSubset = 1;
	pEntity = xmlSAX2GetParameterEntity(ctxt, (const xmlChar*)"foo");
	MT_CHECK_MESSAGE("checking the result for xmlSAX2GetEntity", pEntity == NULL);
	/*if (pEntity != NULL)
		delete pEntity;*/
	/**
	 * @remarks   input7: [1.calling xmlSAX2GetEntity Api, N/A]	@n
	 *					{ctxt,"foo"} => {N/A |xmlEntityPtr}	@n
	 */
	ctxt->inSubset = 1;
	pEntity = xmlSAX2GetEntity(ctxt, (const xmlChar*)"foo");
	MT_CHECK_MESSAGE("checking the result for xmlSAX2GetEntity", pEntity != NULL);
	/*if (pEntity != NULL)
		delete pEntity;*/
	/**
	 * @remarks   input8: [1.calling xmlSAX2GetEntity Api, N/A]	@n
	 *					{ctxt,"foo"} => {N/A |xmlEntityPtr}	@n
	 */
	ctxt->inSubset = 0;
	pEntity = xmlSAX2GetEntity(ctxt, (const xmlChar*)"foo");
	MT_CHECK_MESSAGE("checking the result for xmlSAX2GetEntity", pEntity != NULL);
	/*if (pEntity != NULL)
		delete pEntity;*/
	xmlSAX2EndDocument(ctxt);
	/**
	 * @post Cleanup function for the XML library.
	 */
	delete pData;
	//xmlMemFree(ctxt->myDoc);
	xmlFreeDoc(ctxt->myDoc);
	xmlFreeParserCtxt(ctxt);
	xmlMemFree(pSaxHandler);
}
/**    
	* @test			UTcSaxP08
	* @brief		xmlParserInputPtr xmlSAX2ResolveEntity (void * ctx,const xmlChar * publicId, const xmlChar * systemId)
	* @desc			Positive Test for checking the functionality of the entity loader, to control the loading of external entities
	* @b developer	kyung-eun park(kyung-eun.park@samsung.com), Seong-Yeol Park(seongyeol.park@samsung.com)
	* @b tester		Michel Anthony (michelj@samsung.com)
	* @return		void
	* @see			none
	* @remarks		input1: [1.xmlParserCtxtPtr is created, N/A]	@n
					{ctxt,const xmlChar * "foo",const xmlChar * "foo"} => {N/A |xmlParserInputPtr}	@n
	* @b priority	Middle
	* @b etc		none
	*/
static void
UTcSaxP08()
{
	xmlEntityPtr ret_val = NULL;
	xmlErrorPtr				pError;
	xmlParserCtxtPtr ctxt = NULL; /* the user data (XML parser context) */
	int n_ctx;
	xmlChar * name = NULL; /* The entity name */
	int n_name;

	

	for (n_ctx = 0;n_ctx < gen_nb_xmlParserCtxtPtr;n_ctx++) {
		for (n_name = 0;n_name < gen_nb_const_xmlChar_ptr;n_name++) {

			ctxt = gen_xmlParserCtxtPtr(n_ctx, 0);
			name = gen_const_xmlChar_ptr(n_name, 1);


			xmlResetLastError();
			xmlSAX2NotationDecl(ctxt, (const xmlChar *)name, (const xmlChar *)name, (const xmlChar *)name);
			pError = xmlGetLastError();
			MT_CHECK_MESSAGE("checking the result for xmlSAX2NotationDecl", pError == NULL);

			ret_val = xmlSAX2GetParameterEntity(ctxt, (const xmlChar *)name);
			MT_CHECK_MESSAGE("checking the result for xmlSAX2GetParameterEntity", ret_val == NULL);

			xmlResetLastError();
			/**
			 * @remarks   input1: [1.xmlParserCtxtPtr is created, N/A]	@n
			 *					{ctxt,"foo","foo"} => {N/A |xmlParserInputPtr}	@n
			 */
			xmlParserInputPtr parserInputPtr = xmlSAX2ResolveEntity(ctxt,(const xmlChar *)name,(const xmlChar *)name);
			MT_CHECK_MESSAGE("checking the result for xmlSAX2ResolveEntity", parserInputPtr == NULL);

			xmlResetLastError();
			xmlSAX2AttributeDecl(ctxt,(const xmlChar *)name,(const xmlChar*)"xml:id",1,1,(const xmlChar *)name,NULL);
			xmlResetLastError();

			/*xmlFreeInputStream(parserInputPtr);
			xmlFree(name);*/
			xmlFreeDoc(ctxt->myDoc);
			xmlFreeParserCtxt(ctxt);
					
		}
	}
	/**
	 * @post Cleanup function for the XML library.
	 */

}

#endif
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
	{UTcSaxP01,1},
	#if 0
	{UTcSaxP02,2},
	{UTcSaxP03,4},
	{UTcSaxP04,5},
	{UTcSaxP05,6},
	{UTcSaxP06,7},
	{UTcSaxP07,8},
	{UTcSaxP08,9},
	#endif
	{ NULL, 0 },
	
};


#else

static int call_tests = 0;
static int function_tests = 0;
static xmlChar chartab[1024];

#define gen_nb_void_ptr 2

static void *gen_void_ptr(int no ATTRIBUTE_UNUSED, int nr ATTRIBUTE_UNUSED) {
    return(NULL);
}
static void desret_const_xmlChar_ptr(const xmlChar *val ATTRIBUTE_UNUSED) {
}

static void desret_int(int val) {
	DTS_CHECK_EQ_MESSAGE("desret_int", (void *)val, (void *)0, "desret_int Failed");
}

static void desret_xmlParserInputPtr(xmlParserInputPtr val) {
    xmlFreeInputStream(val);
}

static void
test_docbDefaultSAXHandlerInit(void) {
    int test_ret = 0;

#if defined(LIBXML_DOCB_ENABLED)
#ifdef LIBXML_DOCB_ENABLED
    int mem_base;

        mem_base = xmlMemBlocks();

        docbDefaultSAXHandlerInit();
	 DTS_CHECK_EQ_MESSAGE("test_docbDefaultSAXHandlerInit", (void *)1, (void *)1, "docbDefaultSAXHandlerInit Failed");
        call_tests++;
        xmlResetLastError();
        if (mem_base != xmlMemBlocks()) {
            printf("Leak of %d blocks found in docbDefaultSAXHandlerInit",
	           xmlMemBlocks() - mem_base);
	    test_ret++;
            printf("\n");
        }
    function_tests++;
#endif
#endif

//    return(test_ret);
}


static void
test_htmlDefaultSAXHandlerInit(void) {
    int test_ret = 0;

#if defined(LIBXML_HTML_ENABLED)
#ifdef LIBXML_HTML_ENABLED
    int mem_base;

        mem_base = xmlMemBlocks();

        htmlDefaultSAXHandlerInit();
	DTS_CHECK_EQ_MESSAGE("test_htmlDefaultSAXHandlerInit", (void *)1, (void *)1, "htmlDefaultSAXHandlerInit Failed");
        call_tests++;
        xmlResetLastError();
        if (mem_base != xmlMemBlocks()) {
            printf("Leak of %d blocks found in htmlDefaultSAXHandlerInit",
	           xmlMemBlocks() - mem_base);
	    test_ret++;
            printf("\n");
        }
    function_tests++;
#endif
#endif

   // return(test_ret);
}


static void
test_xmlDefaultSAXHandlerInit(void) {
    int test_ret = 0;

    int mem_base;

        mem_base = xmlMemBlocks();

        xmlDefaultSAXHandlerInit();
	DTS_CHECK_EQ_MESSAGE("test_xmlDefaultSAXHandlerInit", (void *)1, (void *)1, "xmlDefaultSAXHandlerInit Failed");
        call_tests++;
        xmlResetLastError();
        if (mem_base != xmlMemBlocks()) {
            printf("Leak of %d blocks found in xmlDefaultSAXHandlerInit",
	           xmlMemBlocks() - mem_base);
	    test_ret++;
            printf("\n");
        }
    function_tests++;

   // return(test_ret);
}

#define gen_nb_xmlElementContentPtr 1
static xmlElementContentPtr gen_xmlElementContentPtr(int no ATTRIBUTE_UNUSED, int nr ATTRIBUTE_UNUSED) {
    return(NULL);
}
static void des_xmlElementContentPtr(int no ATTRIBUTE_UNUSED, xmlElementContentPtr val, int nr ATTRIBUTE_UNUSED) {
    if (val != NULL)
        xmlFreeElementContent(val);
}
static void desret_xmlElementContentPtr(xmlElementContentPtr val) {
    if (val != NULL)
        xmlFreeElementContent(val);
}

#define gen_nb_xmlEnumerationPtr 1
static xmlEnumerationPtr gen_xmlEnumerationPtr(int no ATTRIBUTE_UNUSED, int nr ATTRIBUTE_UNUSED) {
    return(NULL);
}
static void des_xmlEnumerationPtr(int no ATTRIBUTE_UNUSED, xmlEnumerationPtr val ATTRIBUTE_UNUSED, int nr ATTRIBUTE_UNUSED) {
}

#define gen_nb_int 4

static int gen_int(int no, int nr ATTRIBUTE_UNUSED) {
    if (no == 0) return(0);
    if (no == 1) return(1);
    if (no == 2) return(-1);
    if (no == 3) return(122);
    return(-1);
}

static void des_int(int no ATTRIBUTE_UNUSED, int val ATTRIBUTE_UNUSED, int nr ATTRIBUTE_UNUSED) {
}

#define gen_nb_xmlChar_ptr 2

static xmlChar *gen_xmlChar_ptr(int no, int nr ATTRIBUTE_UNUSED) {
    if (no == 0) return(&chartab[0]);
    return(NULL);
}
static void des_xmlChar_ptr(int no ATTRIBUTE_UNUSED, xmlChar *val ATTRIBUTE_UNUSED, int nr ATTRIBUTE_UNUSED) {
}

#define gen_nb_FILE_ptr 2

static FILE *gen_FILE_ptr(int no, int nr ATTRIBUTE_UNUSED) {
    if (no == 0) return(fopen("test.out", "a+"));
    return(NULL);
}
static void des_FILE_ptr(int no ATTRIBUTE_UNUSED, FILE *val, int nr ATTRIBUTE_UNUSED) {
    if (val != NULL) fclose(val);
}

static void
test_xmlSAX2AttributeDecl(void) {
    int test_ret = 0;

    int mem_base;
    void * ctx; /* the user data (XML parser context) */
    int n_ctx;
    xmlChar * elem; /* the name of the element */
    int n_elem;
    xmlChar * fullname; /* the attribute name */
    int n_fullname;
    int type; /* the attribute type */
    int n_type;
    int def; /* the type of default value */
    int n_def;
    xmlChar * defaultValue; /* the attribute default value */
    int n_defaultValue;
    xmlEnumerationPtr tree; /* the tree of enumerated value set */
    int n_tree;

    for (n_ctx = 0;n_ctx < gen_nb_void_ptr;n_ctx++) {
    for (n_elem = 0;n_elem < gen_nb_const_xmlChar_ptr;n_elem++) {
    for (n_fullname = 0;n_fullname < gen_nb_const_xmlChar_ptr;n_fullname++) {
    for (n_type = 0;n_type < gen_nb_int;n_type++) {
    for (n_def = 0;n_def < gen_nb_int;n_def++) {
    for (n_defaultValue = 0;n_defaultValue < gen_nb_const_xmlChar_ptr;n_defaultValue++) {
    for (n_tree = 0;n_tree < gen_nb_xmlEnumerationPtr;n_tree++) {
        mem_base = xmlMemBlocks();
        ctx = gen_void_ptr(n_ctx, 0);
        elem = gen_const_xmlChar_ptr(n_elem, 1);
        fullname = gen_const_xmlChar_ptr(n_fullname, 2);
        type = gen_int(n_type, 3);
        def = gen_int(n_def, 4);
        defaultValue = gen_const_xmlChar_ptr(n_defaultValue, 5);
        tree = gen_xmlEnumerationPtr(n_tree, 6);

        xmlSAX2AttributeDecl(ctx, (const xmlChar *)elem, (const xmlChar *)fullname, type, def, (const xmlChar *)defaultValue, tree);
 	DTS_CHECK_EQ_MESSAGE("test_xmlSAX2AttributeDecl", (void *)1, (void *)1, "xmlSAX2AttributeDecl Failed");
	
        call_tests++;
        des_void_ptr(n_ctx, ctx, 0);
        des_const_xmlChar_ptr(n_elem, (const xmlChar *)elem, 1);
        des_const_xmlChar_ptr(n_fullname, (const xmlChar *)fullname, 2);
        des_int(n_type, type, 3);
        des_int(n_def, def, 4);
        des_const_xmlChar_ptr(n_defaultValue, (const xmlChar *)defaultValue, 5);
        des_xmlEnumerationPtr(n_tree, tree, 6);
        xmlResetLastError();
        if (mem_base != xmlMemBlocks()) {
            printf("Leak of %d blocks found in xmlSAX2AttributeDecl",
	           xmlMemBlocks() - mem_base);
	    test_ret++;
            printf(" %d", n_ctx);
            printf(" %d", n_elem);
            printf(" %d", n_fullname);
            printf(" %d", n_type);
            printf(" %d", n_def);
            printf(" %d", n_defaultValue);
            printf(" %d", n_tree);
            printf("\n");
        }
    }
    }
    }
    }
    }
    }
    }
    function_tests++;

   // return(test_ret);
}


static void
test_xmlSAX2CDataBlock(void) {
    int test_ret = 0;

    int mem_base;
    void * ctx; /* the user data (XML parser context) */
    int n_ctx;
    xmlChar * value; /* The pcdata content */
    int n_value;
    int len; /* the block length */
    int n_len;

    for (n_ctx = 0;n_ctx < gen_nb_void_ptr;n_ctx++) {
    for (n_value = 0;n_value < gen_nb_const_xmlChar_ptr;n_value++) {
    for (n_len = 0;n_len < gen_nb_int;n_len++) {
        mem_base = xmlMemBlocks();
        ctx = gen_void_ptr(n_ctx, 0);
        value = gen_const_xmlChar_ptr(n_value, 1);
        len = gen_int(n_len, 2);

        xmlSAX2CDataBlock(ctx, (const xmlChar *)value, len);
		DTS_CHECK_EQ_MESSAGE("test_xmlSAX2CDataBlock", (void *)1, (void *)1, "xmlSAX2CDataBlock Failed");
        call_tests++;
        des_void_ptr(n_ctx, ctx, 0);
        des_const_xmlChar_ptr(n_value, (const xmlChar *)value, 1);
        des_int(n_len, len, 2);
        xmlResetLastError();
        if (mem_base != xmlMemBlocks()) {
            printf("Leak of %d blocks found in xmlSAX2CDataBlock",
	           xmlMemBlocks() - mem_base);
	    test_ret++;
            printf(" %d", n_ctx);
            printf(" %d", n_value);
            printf(" %d", n_len);
            printf("\n");
        }
    }
    }
    }
    function_tests++;

//    return(test_ret);
}


static void
test_xmlSAX2Characters(void) {
    int test_ret = 0;

    int mem_base;
    void * ctx; /* the user data (XML parser context) */
    int n_ctx;
    xmlChar * ch; /* a xmlChar string */
    int n_ch;
    int len; /* the number of xmlChar */
    int n_len;

    for (n_ctx = 0;n_ctx < gen_nb_void_ptr;n_ctx++) {
    for (n_ch = 0;n_ch < gen_nb_const_xmlChar_ptr;n_ch++) {
    for (n_len = 0;n_len < gen_nb_int;n_len++) {
        mem_base = xmlMemBlocks();
        ctx = gen_void_ptr(n_ctx, 0);
        ch = gen_const_xmlChar_ptr(n_ch, 1);
        len = gen_int(n_len, 2);

        xmlSAX2Characters(ctx, (const xmlChar *)ch, len);
		DTS_CHECK_EQ_MESSAGE("test_xmlSAX2Characters", (void *)1, (void *)1, "xmlSAX2Characters Failed");
        call_tests++;
        des_void_ptr(n_ctx, ctx, 0);
        des_const_xmlChar_ptr(n_ch, (const xmlChar *)ch, 1);
        des_int(n_len, len, 2);
        xmlResetLastError();
        if (mem_base != xmlMemBlocks()) {
            printf("Leak of %d blocks found in xmlSAX2Characters",
	           xmlMemBlocks() - mem_base);
	    test_ret++;
            printf(" %d", n_ctx);
            printf(" %d", n_ch);
            printf(" %d", n_len);
            printf("\n");
        }
    }
    }
    }
    function_tests++;

   // return(test_ret);
}


static void
test_xmlSAX2Comment(void) {
    int test_ret = 0;

    int mem_base;
    void * ctx; /* the user data (XML parser context) */
    int n_ctx;
    xmlChar * value; /* the xmlSAX2Comment content */
    int n_value;

    for (n_ctx = 0;n_ctx < gen_nb_void_ptr;n_ctx++) {
    for (n_value = 0;n_value < gen_nb_const_xmlChar_ptr;n_value++) {
        mem_base = xmlMemBlocks();
        ctx = gen_void_ptr(n_ctx, 0);
        value = gen_const_xmlChar_ptr(n_value, 1);

        xmlSAX2Comment(ctx, (const xmlChar *)value);
		DTS_CHECK_EQ_MESSAGE("xmlSAX2Comment", (void *)1, (void *)1, "xmlSAX2Comment Failed");
        call_tests++;
        des_void_ptr(n_ctx, ctx, 0);
        des_const_xmlChar_ptr(n_value, (const xmlChar *)value, 1);
        xmlResetLastError();
        if (mem_base != xmlMemBlocks()) {
            printf("Leak of %d blocks found in xmlSAX2Comment",
	           xmlMemBlocks() - mem_base);
	    test_ret++;
            printf(" %d", n_ctx);
            printf(" %d", n_value);
            printf("\n");
        }
    }
    }
    function_tests++;

   // return(test_ret);
}


static void
test_xmlSAX2ElementDecl(void) {
    int test_ret = 0;

    int mem_base;
    void * ctx; /* the user data (XML parser context) */
    int n_ctx;
    xmlChar * name; /* the element name */
    int n_name;
    int type; /* the element type */
    int n_type;
    xmlElementContentPtr content; /* the element value tree */
    int n_content;

    for (n_ctx = 0;n_ctx < gen_nb_void_ptr;n_ctx++) {
    for (n_name = 0;n_name < gen_nb_const_xmlChar_ptr;n_name++) {
    for (n_type = 0;n_type < gen_nb_int;n_type++) {
    for (n_content = 0;n_content < gen_nb_xmlElementContentPtr;n_content++) {
        mem_base = xmlMemBlocks();
        ctx = gen_void_ptr(n_ctx, 0);
        name = gen_const_xmlChar_ptr(n_name, 1);
        type = gen_int(n_type, 2);
        content = gen_xmlElementContentPtr(n_content, 3);

        xmlSAX2ElementDecl(ctx, (const xmlChar *)name, type, content);
	DTS_CHECK_EQ_MESSAGE("xmlSAX2ElementDecl", (void *)1, (void *)1, "xmlSAX2ElementDecl Failed");
        call_tests++;
        des_void_ptr(n_ctx, ctx, 0);
        des_const_xmlChar_ptr(n_name, (const xmlChar *)name, 1);
        des_int(n_type, type, 2);
        des_xmlElementContentPtr(n_content, content, 3);
        xmlResetLastError();
        if (mem_base != xmlMemBlocks()) {
            printf("Leak of %d blocks found in xmlSAX2ElementDecl",
	           xmlMemBlocks() - mem_base);
	    test_ret++;
            printf(" %d", n_ctx);
            printf(" %d", n_name);
            printf(" %d", n_type);
            printf(" %d", n_content);
            printf("\n");
        }
    }
    }
    }
    }
    function_tests++;

    //return(test_ret);
}


static void
test_xmlSAX2EndDocument(void) {
    int test_ret = 0;

    int mem_base;
    void * ctx; /* the user data (XML parser context) */
    int n_ctx;

    for (n_ctx = 0;n_ctx < gen_nb_void_ptr;n_ctx++) {
        mem_base = xmlMemBlocks();
        ctx = gen_void_ptr(n_ctx, 0);

        xmlSAX2EndDocument(ctx);
		DTS_CHECK_EQ_MESSAGE("xmlSAX2EndDocument", (void *)1, (void *)1, "xmlSAX2EndDocument Failed");
        call_tests++;
        des_void_ptr(n_ctx, ctx, 0);
        xmlResetLastError();
        if (mem_base != xmlMemBlocks()) {
            printf("Leak of %d blocks found in xmlSAX2EndDocument",
	           xmlMemBlocks() - mem_base);
	    test_ret++;
            printf(" %d", n_ctx);
            printf("\n");
        }
    }
    function_tests++;

    return(test_ret);
}


static void
test_xmlSAX2EndElement(void) {
    int test_ret = 0;

#if defined(LIBXML_SAX1_ENABLED) || defined(LIBXML_HTML_ENABLED) || defined(LIBXML_WRITER_ENABLED) || defined(LIBXML_DOCB_ENABLED)
#ifdef LIBXML_SAX1_ENABLED
    int mem_base;
    void * ctx; /* the user data (XML parser context) */
    int n_ctx;
    xmlChar * name; /* The element name */
    int n_name;

    for (n_ctx = 0;n_ctx < gen_nb_void_ptr;n_ctx++) {
    for (n_name = 0;n_name < gen_nb_const_xmlChar_ptr;n_name++) {
        mem_base = xmlMemBlocks();
        ctx = gen_void_ptr(n_ctx, 0);
        name = gen_const_xmlChar_ptr(n_name, 1);

        xmlSAX2EndElement(ctx, (const xmlChar *)name);
		DTS_CHECK_EQ_MESSAGE("xmlSAX2EndElement", (void *)1, (void *)1, "xmlSAX2EndElement Failed");
        call_tests++;
        des_void_ptr(n_ctx, ctx, 0);
        des_const_xmlChar_ptr(n_name, (const xmlChar *)name, 1);
        xmlResetLastError();
        if (mem_base != xmlMemBlocks()) {
            printf("Leak of %d blocks found in xmlSAX2EndElement",
	           xmlMemBlocks() - mem_base);
	    test_ret++;
            printf(" %d", n_ctx);
            printf(" %d", n_name);
            printf("\n");
        }
    }
    }
    function_tests++;
#endif
#endif

   // return(test_ret);
}


static void
test_xmlSAX2EndElementNs(void) {
    int test_ret = 0;

    int mem_base;
    void * ctx; /* the user data (XML parser context) */
    int n_ctx;
    xmlChar * localname; /* the local name of the element */
    int n_localname;
    xmlChar * prefix; /* the element namespace prefix if available */
    int n_prefix;
    xmlChar * URI; /* the element namespace name if available */
    int n_URI;

    for (n_ctx = 0;n_ctx < gen_nb_void_ptr;n_ctx++) {
    for (n_localname = 0;n_localname < gen_nb_const_xmlChar_ptr;n_localname++) {
    for (n_prefix = 0;n_prefix < gen_nb_const_xmlChar_ptr;n_prefix++) {
    for (n_URI = 0;n_URI < gen_nb_const_xmlChar_ptr;n_URI++) {
        mem_base = xmlMemBlocks();
        ctx = gen_void_ptr(n_ctx, 0);
        localname = gen_const_xmlChar_ptr(n_localname, 1);
        prefix = gen_const_xmlChar_ptr(n_prefix, 2);
        URI = gen_const_xmlChar_ptr(n_URI, 3);

        xmlSAX2EndElementNs(ctx, (const xmlChar *)localname, (const xmlChar *)prefix, (const xmlChar *)URI);
		DTS_CHECK_EQ_MESSAGE("xmlSAX2EndElementNs", (void *)1, (void *)1, "xmlSAX2EndElementNs Failed");
        call_tests++;
        des_void_ptr(n_ctx, ctx, 0);
        des_const_xmlChar_ptr(n_localname, (const xmlChar *)localname, 1);
        des_const_xmlChar_ptr(n_prefix, (const xmlChar *)prefix, 2);
        des_const_xmlChar_ptr(n_URI, (const xmlChar *)URI, 3);
        xmlResetLastError();
        if (mem_base != xmlMemBlocks()) {
            printf("Leak of %d blocks found in xmlSAX2EndElementNs",
	           xmlMemBlocks() - mem_base);
	    test_ret++;
            printf(" %d", n_ctx);
            printf(" %d", n_localname);
            printf(" %d", n_prefix);
            printf(" %d", n_URI);
            printf("\n");
        }
    }
    }
    }
    }
    function_tests++;

  //  return(test_ret);
}


static void
test_xmlSAX2EntityDecl(void) {
    int test_ret = 0;

    int mem_base;
    void * ctx; /* the user data (XML parser context) */
    int n_ctx;
    xmlChar * name; /* the entity name */
    int n_name;
    int type; /* the entity type */
    int n_type;
    xmlChar * publicId; /* The public ID of the entity */
    int n_publicId;
    xmlChar * systemId; /* The system ID of the entity */
    int n_systemId;
    xmlChar * content; /* the entity value (without processing). */
    int n_content;

    for (n_ctx = 0;n_ctx < gen_nb_void_ptr;n_ctx++) {
    for (n_name = 0;n_name < gen_nb_const_xmlChar_ptr;n_name++) {
    for (n_type = 0;n_type < gen_nb_int;n_type++) {
    for (n_publicId = 0;n_publicId < gen_nb_const_xmlChar_ptr;n_publicId++) {
    for (n_systemId = 0;n_systemId < gen_nb_const_xmlChar_ptr;n_systemId++) {
    for (n_content = 0;n_content < gen_nb_xmlChar_ptr;n_content++) {
        mem_base = xmlMemBlocks();
        ctx = gen_void_ptr(n_ctx, 0);
        name = gen_const_xmlChar_ptr(n_name, 1);
        type = gen_int(n_type, 2);
        publicId = gen_const_xmlChar_ptr(n_publicId, 3);
        systemId = gen_const_xmlChar_ptr(n_systemId, 4);
        content = gen_xmlChar_ptr(n_content, 5);

        xmlSAX2EntityDecl(ctx, (const xmlChar *)name, type, (const xmlChar *)publicId, (const xmlChar *)systemId, content);
		DTS_CHECK_EQ_MESSAGE("xmlSAX2EntityDecl", (void *)1, (void *)1, "xmlSAX2EntityDecl Failed");
        call_tests++;
        des_void_ptr(n_ctx, ctx, 0);
        des_const_xmlChar_ptr(n_name, (const xmlChar *)name, 1);
        des_int(n_type, type, 2);
        des_const_xmlChar_ptr(n_publicId, (const xmlChar *)publicId, 3);
        des_const_xmlChar_ptr(n_systemId, (const xmlChar *)systemId, 4);
        des_xmlChar_ptr(n_content, content, 5);
        xmlResetLastError();
        if (mem_base != xmlMemBlocks()) {
            printf("Leak of %d blocks found in xmlSAX2EntityDecl",
	           xmlMemBlocks() - mem_base);
	    test_ret++;
            printf(" %d", n_ctx);
            printf(" %d", n_name);
            printf(" %d", n_type);
            printf(" %d", n_publicId);
            printf(" %d", n_systemId);
            printf(" %d", n_content);
            printf("\n");
        }
    }
    }
    }
    }
    }
    }
    function_tests++;

   // return(test_ret);
}


static void
test_xmlSAX2ExternalSubset(void) {
    int test_ret = 0;

    int mem_base;
    void * ctx; /* the user data (XML parser context) */
    int n_ctx;
    xmlChar * name; /* the root element name */
    int n_name;
    xmlChar * ExternalID; /* the external ID */
    int n_ExternalID;
    xmlChar * SystemID; /* the SYSTEM ID (e.g. filename or URL) */
    int n_SystemID;

    for (n_ctx = 0;n_ctx < gen_nb_void_ptr;n_ctx++) {
    for (n_name = 0;n_name < gen_nb_const_xmlChar_ptr;n_name++) {
    for (n_ExternalID = 0;n_ExternalID < gen_nb_const_xmlChar_ptr;n_ExternalID++) {
    for (n_SystemID = 0;n_SystemID < gen_nb_const_xmlChar_ptr;n_SystemID++) {
        mem_base = xmlMemBlocks();
        ctx = gen_void_ptr(n_ctx, 0);
        name = gen_const_xmlChar_ptr(n_name, 1);
        ExternalID = gen_const_xmlChar_ptr(n_ExternalID, 2);
        SystemID = gen_const_xmlChar_ptr(n_SystemID, 3);

        xmlSAX2ExternalSubset(ctx, (const xmlChar *)name, (const xmlChar *)ExternalID, (const xmlChar *)SystemID);
		DTS_CHECK_EQ_MESSAGE("xmlSAX2ExternalSubset", (void *)1, (void *)1, "xmlSAX2ExternalSubset Failed");
        call_tests++;
        des_void_ptr(n_ctx, ctx, 0);
        des_const_xmlChar_ptr(n_name, (const xmlChar *)name, 1);
        des_const_xmlChar_ptr(n_ExternalID, (const xmlChar *)ExternalID, 2);
        des_const_xmlChar_ptr(n_SystemID, (const xmlChar *)SystemID, 3);
        xmlResetLastError();
        if (mem_base != xmlMemBlocks()) {
            printf("Leak of %d blocks found in xmlSAX2ExternalSubset",
	           xmlMemBlocks() - mem_base);
	    test_ret++;
            printf(" %d", n_ctx);
            printf(" %d", n_name);
            printf(" %d", n_ExternalID);
            printf(" %d", n_SystemID);
            printf("\n");
        }
    }
    }
    }
    }
    function_tests++;

//    return(test_ret);
}


static void
test_xmlSAX2GetColumnNumber(void) {
    int test_ret = 0;

    int mem_base;
    int ret_val;
    void * ctx; /* the user data (XML parser context) */
    int n_ctx;

    for (n_ctx = 0;n_ctx < gen_nb_void_ptr;n_ctx++) {
        mem_base = xmlMemBlocks();
        ctx = gen_void_ptr(n_ctx, 0);

        ret_val = xmlSAX2GetColumnNumber(ctx);
		DTS_CHECK_EQ_MESSAGE("xmlSAX2GetColumnNumber", (void *)1, (void *)1, "xmlSAX2GetColumnNumber Failed");
        desret_int(ret_val);
        call_tests++;
        des_void_ptr(n_ctx, ctx, 0);
        xmlResetLastError();
        if (mem_base != xmlMemBlocks()) {
            printf("Leak of %d blocks found in xmlSAX2GetColumnNumber",
	           xmlMemBlocks() - mem_base);
	    test_ret++;
            printf(" %d", n_ctx);
            printf("\n");
        }
    }
    function_tests++;

 //   return(test_ret);
}


static void
test_xmlSAX2GetEntity(void) {
    int test_ret = 0;

    int mem_base;
    xmlEntityPtr ret_val;
    void * ctx; /* the user data (XML parser context) */
    int n_ctx;
    xmlChar * name; /* The entity name */
    int n_name;

    for (n_ctx = 0;n_ctx < gen_nb_void_ptr;n_ctx++) {
    for (n_name = 0;n_name < gen_nb_const_xmlChar_ptr;n_name++) {
        mem_base = xmlMemBlocks();
        ctx = gen_void_ptr(n_ctx, 0);
        name = gen_const_xmlChar_ptr(n_name, 1);

        ret_val = xmlSAX2GetEntity(ctx, (const xmlChar *)name);
		DTS_CHECK_EQ_MESSAGE("xmlSAX2GetEntity", (void *)1, (void *)1, "xmlSAX2GetEntity Failed");
        desret_xmlEntityPtr(ret_val);
        call_tests++;
        des_void_ptr(n_ctx, ctx, 0);
        des_const_xmlChar_ptr(n_name, (const xmlChar *)name, 1);
        xmlResetLastError();
        if (mem_base != xmlMemBlocks()) {
            printf("Leak of %d blocks found in xmlSAX2GetEntity",
	           xmlMemBlocks() - mem_base);
	    test_ret++;
            printf(" %d", n_ctx);
            printf(" %d", n_name);
            printf("\n");
        }
    }
    }
    function_tests++;

    //return(test_ret);
}


static void
test_xmlSAX2GetLineNumber(void) {
    int test_ret = 0;

    int mem_base;
    int ret_val;
    void * ctx; /* the user data (XML parser context) */
    int n_ctx;

    for (n_ctx = 0;n_ctx < gen_nb_void_ptr;n_ctx++) {
        mem_base = xmlMemBlocks();
        ctx = gen_void_ptr(n_ctx, 0);

        ret_val = xmlSAX2GetLineNumber(ctx);
		DTS_CHECK_EQ_MESSAGE("xmlSAX2GetLineNumber", (void *)1, (void *)1, "xmlSAX2GetLineNumber Failed");
        desret_int(ret_val);
        call_tests++;
        des_void_ptr(n_ctx, ctx, 0);
        xmlResetLastError();
        if (mem_base != xmlMemBlocks()) {
            printf("Leak of %d blocks found in xmlSAX2GetLineNumber",
	           xmlMemBlocks() - mem_base);
	    test_ret++;
            printf(" %d", n_ctx);
            printf("\n");
        }
    }
    function_tests++;

    //return(test_ret);
}


static void
test_xmlSAX2GetParameterEntity(void) {
    int test_ret = 0;

    int mem_base;
    xmlEntityPtr ret_val;
    void * ctx; /* the user data (XML parser context) */
    int n_ctx;
    xmlChar * name; /* The entity name */
    int n_name;

    for (n_ctx = 0;n_ctx < gen_nb_void_ptr;n_ctx++) {
    for (n_name = 0;n_name < gen_nb_const_xmlChar_ptr;n_name++) {
        mem_base = xmlMemBlocks();
        ctx = gen_void_ptr(n_ctx, 0);
        name = gen_const_xmlChar_ptr(n_name, 1);

        ret_val = xmlSAX2GetParameterEntity(ctx, (const xmlChar *)name);
		DTS_CHECK_EQ_MESSAGE("xmlSAX2GetParameterEntity", (void *)1, (void *)1, "xmlSAX2GetParameterEntity Failed");
        desret_xmlEntityPtr(ret_val);
        call_tests++;
        des_void_ptr(n_ctx, ctx, 0);
        des_const_xmlChar_ptr(n_name, (const xmlChar *)name, 1);
        xmlResetLastError();
        if (mem_base != xmlMemBlocks()) {
            printf("Leak of %d blocks found in xmlSAX2GetParameterEntity",
	           xmlMemBlocks() - mem_base);
	    test_ret++;
            printf(" %d", n_ctx);
            printf(" %d", n_name);
            printf("\n");
        }
    }
    }
    function_tests++;

    //return(test_ret);
}


static void
test_xmlSAX2GetPublicId(void) {
    int test_ret = 0;

    int mem_base;
    const xmlChar * ret_val;
    void * ctx; /* the user data (XML parser context) */
    int n_ctx;

    for (n_ctx = 0;n_ctx < gen_nb_void_ptr;n_ctx++) {
        mem_base = xmlMemBlocks();
        ctx = gen_void_ptr(n_ctx, 0);

        ret_val = xmlSAX2GetPublicId(ctx);
		DTS_CHECK_EQ_MESSAGE("xmlSAX2GetPublicId", (void *)1, (void *)1, "xmlSAX2GetPublicId Failed");
        desret_const_xmlChar_ptr(ret_val);
        call_tests++;
        des_void_ptr(n_ctx, ctx, 0);
        xmlResetLastError();
        if (mem_base != xmlMemBlocks()) {
            printf("Leak of %d blocks found in xmlSAX2GetPublicId",
	           xmlMemBlocks() - mem_base);
	    test_ret++;
            printf(" %d", n_ctx);
            printf("\n");
        }
    }
    function_tests++;

    //return(test_ret);
}


static void
test_xmlSAX2GetSystemId(void) {
    int test_ret = 0;

    int mem_base;
    const xmlChar * ret_val;
    void * ctx; /* the user data (XML parser context) */
    int n_ctx;

    for (n_ctx = 0;n_ctx < gen_nb_void_ptr;n_ctx++) {
        mem_base = xmlMemBlocks();
        ctx = gen_void_ptr(n_ctx, 0);

        ret_val = xmlSAX2GetSystemId(ctx);
		DTS_CHECK_EQ_MESSAGE("xmlSAX2GetSystemId", (void *)1, (void *)1, "xmlSAX2GetSystemId Failed");
        desret_const_xmlChar_ptr(ret_val);
        call_tests++;
        des_void_ptr(n_ctx, ctx, 0);
        xmlResetLastError();
        if (mem_base != xmlMemBlocks()) {
            printf("Leak of %d blocks found in xmlSAX2GetSystemId",
	           xmlMemBlocks() - mem_base);
	    test_ret++;
            printf(" %d", n_ctx);
            printf("\n");
        }
    }
    function_tests++;

  //  return(test_ret);
}


static void
test_xmlSAX2HasExternalSubset(void) {
    int test_ret = 0;

    int mem_base;
    int ret_val;
    void * ctx; /* the user data (XML parser context) */
    int n_ctx;

    for (n_ctx = 0;n_ctx < gen_nb_void_ptr;n_ctx++) {
        mem_base = xmlMemBlocks();
        ctx = gen_void_ptr(n_ctx, 0);

        ret_val = xmlSAX2HasExternalSubset(ctx);
		DTS_CHECK_EQ_MESSAGE("xmlSAX2HasExternalSubset", (void *)1, (void *)1, "xmlSAX2HasExternalSubset Failed");
        desret_int(ret_val);
        call_tests++;
        des_void_ptr(n_ctx, ctx, 0);
        xmlResetLastError();
        if (mem_base != xmlMemBlocks()) {
            printf("Leak of %d blocks found in xmlSAX2HasExternalSubset",
	           xmlMemBlocks() - mem_base);
	    test_ret++;
            printf(" %d", n_ctx);
            printf("\n");
        }
    }
    function_tests++;

    //return(test_ret);
}


static void
test_xmlSAX2HasInternalSubset(void) {
    int test_ret = 0;

    int mem_base;
    int ret_val;
    void * ctx; /* the user data (XML parser context) */
    int n_ctx;

    for (n_ctx = 0;n_ctx < gen_nb_void_ptr;n_ctx++) {
        mem_base = xmlMemBlocks();
        ctx = gen_void_ptr(n_ctx, 0);

        ret_val = xmlSAX2HasInternalSubset(ctx);
		DTS_CHECK_EQ_MESSAGE("xmlSAX2HasInternalSubset", (void *)1, (void *)1, "xmlSAX2HasInternalSubset Failed");
        desret_int(ret_val);
        call_tests++;
        des_void_ptr(n_ctx, ctx, 0);
        xmlResetLastError();
        if (mem_base != xmlMemBlocks()) {
            printf("Leak of %d blocks found in xmlSAX2HasInternalSubset",
	           xmlMemBlocks() - mem_base);
	    test_ret++;
            printf(" %d", n_ctx);
            printf("\n");
        }
    }
    function_tests++;

//    return(test_ret);
}


static void
test_xmlSAX2IgnorableWhitespace(void) {
    int test_ret = 0;

    int mem_base;
    void * ctx; /* the user data (XML parser context) */
    int n_ctx;
    xmlChar * ch; /* a xmlChar string */
    int n_ch;
    int len; /* the number of xmlChar */
    int n_len;

    for (n_ctx = 0;n_ctx < gen_nb_void_ptr;n_ctx++) {
    for (n_ch = 0;n_ch < gen_nb_const_xmlChar_ptr;n_ch++) {
    for (n_len = 0;n_len < gen_nb_int;n_len++) {
        mem_base = xmlMemBlocks();
        ctx = gen_void_ptr(n_ctx, 0);
        ch = gen_const_xmlChar_ptr(n_ch, 1);
        len = gen_int(n_len, 2);

        xmlSAX2IgnorableWhitespace(ctx, (const xmlChar *)ch, len);
		DTS_CHECK_EQ_MESSAGE("xmlSAX2IgnorableWhitespace", (void *)1, (void *)1, "xmlSAX2IgnorableWhitespace Failed");
        call_tests++;
        des_void_ptr(n_ctx, ctx, 0);
        des_const_xmlChar_ptr(n_ch, (const xmlChar *)ch, 1);
        des_int(n_len, len, 2);
        xmlResetLastError();
        if (mem_base != xmlMemBlocks()) {
            printf("Leak of %d blocks found in xmlSAX2IgnorableWhitespace",
	           xmlMemBlocks() - mem_base);
	    test_ret++;
            printf(" %d", n_ctx);
            printf(" %d", n_ch);
            printf(" %d", n_len);
            printf("\n");
        }
    }
    }
    }
    function_tests++;

    //return(test_ret);
}


#define gen_nb_xmlSAXHandler_ptr 1
static xmlSAXHandler * gen_xmlSAXHandler_ptr(int no ATTRIBUTE_UNUSED, int nr ATTRIBUTE_UNUSED) {
    return(NULL);
}
static void des_xmlSAXHandler_ptr(int no ATTRIBUTE_UNUSED, xmlSAXHandler * val ATTRIBUTE_UNUSED, int nr ATTRIBUTE_UNUSED) {
}

static void
test_xmlSAX2InitDefaultSAXHandler(void) {
    int test_ret = 0;

    int mem_base;
    xmlSAXHandler * hdlr; /* the SAX handler */
    int n_hdlr;
    int warning; /* flag if non-zero sets the handler warning procedure */
    int n_warning;

    for (n_hdlr = 0;n_hdlr < gen_nb_xmlSAXHandler_ptr;n_hdlr++) {
    for (n_warning = 0;n_warning < gen_nb_int;n_warning++) {
        mem_base = xmlMemBlocks();
        hdlr = gen_xmlSAXHandler_ptr(n_hdlr, 0);
        warning = gen_int(n_warning, 1);

        xmlSAX2InitDefaultSAXHandler(hdlr, warning);
		DTS_CHECK_EQ_MESSAGE("xmlSAX2InitDefaultSAXHandler", (void *)1, (void *)1, "xmlSAX2InitDefaultSAXHandler Failed");
        call_tests++;
        des_xmlSAXHandler_ptr(n_hdlr, hdlr, 0);
        des_int(n_warning, warning, 1);
        xmlResetLastError();
        if (mem_base != xmlMemBlocks()) {
            printf("Leak of %d blocks found in xmlSAX2InitDefaultSAXHandler",
	           xmlMemBlocks() - mem_base);
	    test_ret++;
            printf(" %d", n_hdlr);
            printf(" %d", n_warning);
            printf("\n");
        }
    }
    }
    function_tests++;

   // return(test_ret);
}


static void
test_xmlSAX2InitDocbDefaultSAXHandler(void) {
    int test_ret = 0;

#if defined(LIBXML_DOCB_ENABLED)
    int mem_base;
    xmlSAXHandler * hdlr; /* the SAX handler */
    int n_hdlr;

    for (n_hdlr = 0;n_hdlr < gen_nb_xmlSAXHandler_ptr;n_hdlr++) {
        mem_base = xmlMemBlocks();
        hdlr = gen_xmlSAXHandler_ptr(n_hdlr, 0);

        xmlSAX2InitDocbDefaultSAXHandler(hdlr);
		DTS_CHECK_EQ_MESSAGE("xmlSAX2InitDocbDefaultSAXHandler", (void *)1, (void *)1, "xmlSAX2InitDocbDefaultSAXHandler Failed");
        call_tests++;
        des_xmlSAXHandler_ptr(n_hdlr, hdlr, 0);
        xmlResetLastError();
        if (mem_base != xmlMemBlocks()) {
            printf("Leak of %d blocks found in xmlSAX2InitDocbDefaultSAXHandler",
	           xmlMemBlocks() - mem_base);
	    test_ret++;
            printf(" %d", n_hdlr);
            printf("\n");
        }
    }
    function_tests++;
#endif

   //return(test_ret);
}


static void
test_xmlSAX2InitHtmlDefaultSAXHandler(void) {
    int test_ret = 0;

#if defined(LIBXML_HTML_ENABLED)
    int mem_base;
    xmlSAXHandler * hdlr; /* the SAX handler */
    int n_hdlr;

    for (n_hdlr = 0;n_hdlr < gen_nb_xmlSAXHandler_ptr;n_hdlr++) {
        mem_base = xmlMemBlocks();
        hdlr = gen_xmlSAXHandler_ptr(n_hdlr, 0);

        xmlSAX2InitHtmlDefaultSAXHandler(hdlr);
		DTS_CHECK_EQ_MESSAGE("xmlSAX2InitHtmlDefaultSAXHandler", (void *)1, (void *)1, "xmlSAX2InitHtmlDefaultSAXHandler Failed");
        call_tests++;
        des_xmlSAXHandler_ptr(n_hdlr, hdlr, 0);
        xmlResetLastError();
        if (mem_base != xmlMemBlocks()) {
            printf("Leak of %d blocks found in xmlSAX2InitHtmlDefaultSAXHandler",
	           xmlMemBlocks() - mem_base);
	    test_ret++;
            printf(" %d", n_hdlr);
            printf("\n");
        }
    }
    function_tests++;
#endif

   // return(test_ret);
}


static void
test_xmlSAX2InternalSubset(void) {
    int test_ret = 0;

    int mem_base;
    void * ctx; /* the user data (XML parser context) */
    int n_ctx;
    xmlChar * name; /* the root element name */
    int n_name;
    xmlChar * ExternalID; /* the external ID */
    int n_ExternalID;
    xmlChar * SystemID; /* the SYSTEM ID (e.g. filename or URL) */
    int n_SystemID;

    for (n_ctx = 0;n_ctx < gen_nb_void_ptr;n_ctx++) {
    for (n_name = 0;n_name < gen_nb_const_xmlChar_ptr;n_name++) {
    for (n_ExternalID = 0;n_ExternalID < gen_nb_const_xmlChar_ptr;n_ExternalID++) {
    for (n_SystemID = 0;n_SystemID < gen_nb_const_xmlChar_ptr;n_SystemID++) {
        mem_base = xmlMemBlocks();
        ctx = gen_void_ptr(n_ctx, 0);
        name = gen_const_xmlChar_ptr(n_name, 1);
        ExternalID = gen_const_xmlChar_ptr(n_ExternalID, 2);
        SystemID = gen_const_xmlChar_ptr(n_SystemID, 3);

        xmlSAX2InternalSubset(ctx, (const xmlChar *)name, (const xmlChar *)ExternalID, (const xmlChar *)SystemID);
		DTS_CHECK_EQ_MESSAGE("xmlSAX2InternalSubset", (void *)1, (void *)1, "xmlSAX2InternalSubset Failed");
        call_tests++;
        des_void_ptr(n_ctx, ctx, 0);
        des_const_xmlChar_ptr(n_name, (const xmlChar *)name, 1);
        des_const_xmlChar_ptr(n_ExternalID, (const xmlChar *)ExternalID, 2);
        des_const_xmlChar_ptr(n_SystemID, (const xmlChar *)SystemID, 3);
        xmlResetLastError();
        if (mem_base != xmlMemBlocks()) {
            printf("Leak of %d blocks found in xmlSAX2InternalSubset",
	           xmlMemBlocks() - mem_base);
	    test_ret++;
            printf(" %d", n_ctx);
            printf(" %d", n_name);
            printf(" %d", n_ExternalID);
            printf(" %d", n_SystemID);
            printf("\n");
        }
    }
    }
    }
    }
    function_tests++;

    //return(test_ret);
}


static void
test_xmlSAX2IsStandalone(void) {
    int test_ret = 0;

    int mem_base;
    int ret_val;
    void * ctx; /* the user data (XML parser context) */
    int n_ctx;

    for (n_ctx = 0;n_ctx < gen_nb_void_ptr;n_ctx++) {
        mem_base = xmlMemBlocks();
        ctx = gen_void_ptr(n_ctx, 0);

        ret_val = xmlSAX2IsStandalone(ctx);
	DTS_CHECK_EQ_MESSAGE("xmlSAX2IsStandalone", (void *)1, (void *)1, "xmlSAX2IsStandalone Failed");
        desret_int(ret_val);
        call_tests++;
        des_void_ptr(n_ctx, ctx, 0);
        xmlResetLastError();
        if (mem_base != xmlMemBlocks()) {
            printf("Leak of %d blocks found in xmlSAX2IsStandalone",
	           xmlMemBlocks() - mem_base);
	    test_ret++;
            printf(" %d", n_ctx);
            printf("\n");
        }
    }
    function_tests++;

   // return(test_ret);
}


static void
test_xmlSAX2NotationDecl(void) {
    int test_ret = 0;

    int mem_base;
    void * ctx; /* the user data (XML parser context) */
    int n_ctx;
    xmlChar * name; /* The name of the notation */
    int n_name;
    xmlChar * publicId; /* The public ID of the entity */
    int n_publicId;
    xmlChar * systemId; /* The system ID of the entity */
    int n_systemId;

    for (n_ctx = 0;n_ctx < gen_nb_void_ptr;n_ctx++) {
    for (n_name = 0;n_name < gen_nb_const_xmlChar_ptr;n_name++) {
    for (n_publicId = 0;n_publicId < gen_nb_const_xmlChar_ptr;n_publicId++) {
    for (n_systemId = 0;n_systemId < gen_nb_const_xmlChar_ptr;n_systemId++) {
        mem_base = xmlMemBlocks();
        ctx = gen_void_ptr(n_ctx, 0);
        name = gen_const_xmlChar_ptr(n_name, 1);
        publicId = gen_const_xmlChar_ptr(n_publicId, 2);
        systemId = gen_const_xmlChar_ptr(n_systemId, 3);

        xmlSAX2NotationDecl(ctx, (const xmlChar *)name, (const xmlChar *)publicId, (const xmlChar *)systemId);
	DTS_CHECK_EQ_MESSAGE("xmlSAX2NotationDecl", (void *)1, (void *)1, "xmlSAX2NotationDecl Failed");
        call_tests++;
        des_void_ptr(n_ctx, ctx, 0);
        des_const_xmlChar_ptr(n_name, (const xmlChar *)name, 1);
        des_const_xmlChar_ptr(n_publicId, (const xmlChar *)publicId, 2);
        des_const_xmlChar_ptr(n_systemId, (const xmlChar *)systemId, 3);
        xmlResetLastError();
        if (mem_base != xmlMemBlocks()) {
            printf("Leak of %d blocks found in xmlSAX2NotationDecl",
	           xmlMemBlocks() - mem_base);
	    test_ret++;
            printf(" %d", n_ctx);
            printf(" %d", n_name);
            printf(" %d", n_publicId);
            printf(" %d", n_systemId);
            printf("\n");
        }
    }
    }
    }
    }
    function_tests++;

   // return(test_ret);
}


static void
test_xmlSAX2ProcessingInstruction(void) {
    int test_ret = 0;

    int mem_base;
    void * ctx; /* the user data (XML parser context) */
    int n_ctx;
    xmlChar * target; /* the target name */
    int n_target;
    xmlChar * data; /* the PI data's */
    int n_data;

    for (n_ctx = 0;n_ctx < gen_nb_void_ptr;n_ctx++) {
    for (n_target = 0;n_target < gen_nb_const_xmlChar_ptr;n_target++) {
    for (n_data = 0;n_data < gen_nb_const_xmlChar_ptr;n_data++) {
        mem_base = xmlMemBlocks();
        ctx = gen_void_ptr(n_ctx, 0);
        target = gen_const_xmlChar_ptr(n_target, 1);
        data = gen_const_xmlChar_ptr(n_data, 2);

        xmlSAX2ProcessingInstruction(ctx, (const xmlChar *)target, (const xmlChar *)data);
	DTS_CHECK_EQ_MESSAGE("xmlSAX2ProcessingInstruction", (void *)1, (void *)1, "xmlSAX2ProcessingInstruction Failed");
        call_tests++;
        des_void_ptr(n_ctx, ctx, 0);
        des_const_xmlChar_ptr(n_target, (const xmlChar *)target, 1);
        des_const_xmlChar_ptr(n_data, (const xmlChar *)data, 2);
        xmlResetLastError();
        if (mem_base != xmlMemBlocks()) {
            printf("Leak of %d blocks found in xmlSAX2ProcessingInstruction",
	           xmlMemBlocks() - mem_base);
	    test_ret++;
            printf(" %d", n_ctx);
            printf(" %d", n_target);
            printf(" %d", n_data);
            printf("\n");
        }
    }
    }
    }
    function_tests++;

   // return(test_ret);
}


static void
test_xmlSAX2Reference(void) {
    int test_ret = 0;

    int mem_base;
    void * ctx; /* the user data (XML parser context) */
    int n_ctx;
    xmlChar * name; /* The entity name */
    int n_name;

    for (n_ctx = 0;n_ctx < gen_nb_void_ptr;n_ctx++) {
    for (n_name = 0;n_name < gen_nb_const_xmlChar_ptr;n_name++) {
        mem_base = xmlMemBlocks();
        ctx = gen_void_ptr(n_ctx, 0);
        name = gen_const_xmlChar_ptr(n_name, 1);

        xmlSAX2Reference(ctx, (const xmlChar *)name);
	DTS_CHECK_EQ_MESSAGE("xmlSAX2Reference", (void *)1, (void *)1, "xmlSAX2Reference Failed");
        call_tests++;
        des_void_ptr(n_ctx, ctx, 0);
        des_const_xmlChar_ptr(n_name, (const xmlChar *)name, 1);
        xmlResetLastError();
        if (mem_base != xmlMemBlocks()) {
            printf("Leak of %d blocks found in xmlSAX2Reference",
	           xmlMemBlocks() - mem_base);
	    test_ret++;
            printf(" %d", n_ctx);
            printf(" %d", n_name);
            printf("\n");
        }
    }
    }
    function_tests++;

  //  return(test_ret);
}


static void
test_xmlSAX2ResolveEntity(void) {
    int test_ret = 0;

    int mem_base;
    xmlParserInputPtr ret_val;
    void * ctx; /* the user data (XML parser context) */
    int n_ctx;
    xmlChar * publicId; /* The public ID of the entity */
    int n_publicId;
    xmlChar * systemId; /* The system ID of the entity */
    int n_systemId;

    for (n_ctx = 0;n_ctx < gen_nb_void_ptr;n_ctx++) {
    for (n_publicId = 0;n_publicId < gen_nb_const_xmlChar_ptr;n_publicId++) {
    for (n_systemId = 0;n_systemId < gen_nb_const_xmlChar_ptr;n_systemId++) {
        mem_base = xmlMemBlocks();
        ctx = gen_void_ptr(n_ctx, 0);
        publicId = gen_const_xmlChar_ptr(n_publicId, 1);
        systemId = gen_const_xmlChar_ptr(n_systemId, 2);

        ret_val = xmlSAX2ResolveEntity(ctx, (const xmlChar *)publicId, (const xmlChar *)systemId);
	DTS_CHECK_EQ_MESSAGE("xmlSAX2ResolveEntity", (void *)1, (void *)1, "xmlSAX2ResolveEntity Failed");
        desret_xmlParserInputPtr(ret_val);
        call_tests++;
        des_void_ptr(n_ctx, ctx, 0);
        des_const_xmlChar_ptr(n_publicId, (const xmlChar *)publicId, 1);
        des_const_xmlChar_ptr(n_systemId, (const xmlChar *)systemId, 2);
        xmlResetLastError();
        if (mem_base != xmlMemBlocks()) {
            printf("Leak of %d blocks found in xmlSAX2ResolveEntity",
	           xmlMemBlocks() - mem_base);
	    test_ret++;
            printf(" %d", n_ctx);
            printf(" %d", n_publicId);
            printf(" %d", n_systemId);
            printf("\n");
        }
    }
    }
    }
    function_tests++;

    //return(test_ret);
}


#define gen_nb_xmlSAXLocatorPtr 1
static xmlSAXLocatorPtr gen_xmlSAXLocatorPtr(int no ATTRIBUTE_UNUSED, int nr ATTRIBUTE_UNUSED) {
    return(NULL);
}
static void des_xmlSAXLocatorPtr(int no ATTRIBUTE_UNUSED, xmlSAXLocatorPtr val ATTRIBUTE_UNUSED, int nr ATTRIBUTE_UNUSED) {
}

static void
test_xmlSAX2SetDocumentLocator(void) {
    int test_ret = 0;

    int mem_base;
    void * ctx; /* the user data (XML parser context) */
    int n_ctx;
    xmlSAXLocatorPtr loc; /* A SAX Locator */
    int n_loc;

    for (n_ctx = 0;n_ctx < gen_nb_void_ptr;n_ctx++) {
    for (n_loc = 0;n_loc < gen_nb_xmlSAXLocatorPtr;n_loc++) {
        mem_base = xmlMemBlocks();
        ctx = gen_void_ptr(n_ctx, 0);
        loc = gen_xmlSAXLocatorPtr(n_loc, 1);

        xmlSAX2SetDocumentLocator(ctx, loc);
	DTS_CHECK_EQ_MESSAGE("xmlSAX2SetDocumentLocator", (void *)1, (void *)1, "xmlSAX2SetDocumentLocator Failed");
        call_tests++;
        des_void_ptr(n_ctx, ctx, 0);
        des_xmlSAXLocatorPtr(n_loc, loc, 1);
        xmlResetLastError();
        if (mem_base != xmlMemBlocks()) {
            printf("Leak of %d blocks found in xmlSAX2SetDocumentLocator",
	           xmlMemBlocks() - mem_base);
	    test_ret++;
            printf(" %d", n_ctx);
            printf(" %d", n_loc);
            printf("\n");
        }
    }
    }
    function_tests++;

   // return(test_ret);
}


static void
test_xmlSAX2StartDocument(void) {
    int test_ret = 0;

    int mem_base;
    void * ctx; /* the user data (XML parser context) */
    int n_ctx;

    for (n_ctx = 0;n_ctx < gen_nb_void_ptr;n_ctx++) {
        mem_base = xmlMemBlocks();
        ctx = gen_void_ptr(n_ctx, 0);

        xmlSAX2StartDocument(ctx);
	DTS_CHECK_EQ_MESSAGE("xmlSAX2StartDocument", (void *)1, (void *)1, "xmlSAX2StartDocument Failed");
        call_tests++;
        des_void_ptr(n_ctx, ctx, 0);
        xmlResetLastError();
        if (mem_base != xmlMemBlocks()) {
            printf("Leak of %d blocks found in xmlSAX2StartDocument",
	           xmlMemBlocks() - mem_base);
	    test_ret++;
            printf(" %d", n_ctx);
            printf("\n");
        }
    }
    function_tests++;

 //   return(test_ret);
}

/* cut and pasted from autogenerated to avoid troubles */
#define gen_nb_const_xmlChar_ptr_ptr 1
static xmlChar ** gen_const_xmlChar_ptr_ptr(int no ATTRIBUTE_UNUSED, int nr ATTRIBUTE_UNUSED) {
    return(NULL);
}
static void des_const_xmlChar_ptr_ptr(int no ATTRIBUTE_UNUSED, const xmlChar ** val ATTRIBUTE_UNUSED, int nr ATTRIBUTE_UNUSED) {
}


static void
test_xmlSAX2StartElement(void) {
    int test_ret = 0;

#if defined(LIBXML_SAX1_ENABLED) || defined(LIBXML_HTML_ENABLED) || defined(LIBXML_WRITER_ENABLED) || defined(LIBXML_DOCB_ENABLED)
#ifdef LIBXML_SAX1_ENABLED
    int mem_base;
    void * ctx; /* the user data (XML parser context) */
    int n_ctx;
    xmlChar * fullname; /* The element name, including namespace prefix */
    int n_fullname;
    xmlChar ** atts; /* An array of name/value attributes pairs, NULL terminated */
    int n_atts;

    for (n_ctx = 0;n_ctx < gen_nb_void_ptr;n_ctx++) {
    for (n_fullname = 0;n_fullname < gen_nb_const_xmlChar_ptr;n_fullname++) {
    for (n_atts = 0;n_atts < gen_nb_const_xmlChar_ptr_ptr;n_atts++) {
        mem_base = xmlMemBlocks();
        ctx = gen_void_ptr(n_ctx, 0);
        fullname = gen_const_xmlChar_ptr(n_fullname, 1);
        atts = gen_const_xmlChar_ptr_ptr(n_atts, 2);

        xmlSAX2StartElement(ctx, (const xmlChar *)fullname, (const xmlChar **)atts);
	DTS_CHECK_EQ_MESSAGE("xmlSAX2StartElement", (void *)1, (void *)1, "xmlSAX2StartElement Failed");
        call_tests++;
        des_void_ptr(n_ctx, ctx, 0);
        des_const_xmlChar_ptr(n_fullname, (const xmlChar *)fullname, 1);
        des_const_xmlChar_ptr_ptr(n_atts, (const xmlChar **)atts, 2);
        xmlResetLastError();
        if (mem_base != xmlMemBlocks()) {
            printf("Leak of %d blocks found in xmlSAX2StartElement",
	           xmlMemBlocks() - mem_base);
	    test_ret++;
            printf(" %d", n_ctx);
            printf(" %d", n_fullname);
            printf(" %d", n_atts);
            printf("\n");
        }
    }
    }
    }
    function_tests++;
#endif
#endif

    //return(test_ret);
}


static void
test_xmlSAX2StartElementNs(void) {
    int test_ret = 0;

    int mem_base;
    void * ctx; /* the user data (XML parser context) */
    int n_ctx;
    xmlChar * localname; /* the local name of the element */
    int n_localname;
    xmlChar * prefix; /* the element namespace prefix if available */
    int n_prefix;
    xmlChar * URI; /* the element namespace name if available */
    int n_URI;
    int nb_namespaces; /* number of namespace definitions on that node */
    int n_nb_namespaces;
    xmlChar ** namespaces; /* pointer to the array of prefix/URI pairs namespace definitions */
    int n_namespaces;
    int nb_attributes; /* the number of attributes on that node */
    int n_nb_attributes;
    int nb_defaulted; /* the number of defaulted attributes. */
    int n_nb_defaulted;
    xmlChar ** attributes; /* pointer to the array of (localname/prefix/URI/value/end) attribute values. */
    int n_attributes;

    for (n_ctx = 0;n_ctx < gen_nb_void_ptr;n_ctx++) {
    for (n_localname = 0;n_localname < gen_nb_const_xmlChar_ptr;n_localname++) {
    for (n_prefix = 0;n_prefix < gen_nb_const_xmlChar_ptr;n_prefix++) {
    for (n_URI = 0;n_URI < gen_nb_const_xmlChar_ptr;n_URI++) {
    for (n_nb_namespaces = 0;n_nb_namespaces < gen_nb_int;n_nb_namespaces++) {
    for (n_namespaces = 0;n_namespaces < gen_nb_const_xmlChar_ptr_ptr;n_namespaces++) {
    for (n_nb_attributes = 0;n_nb_attributes < gen_nb_int;n_nb_attributes++) {
    for (n_nb_defaulted = 0;n_nb_defaulted < gen_nb_int;n_nb_defaulted++) {
    for (n_attributes = 0;n_attributes < gen_nb_const_xmlChar_ptr_ptr;n_attributes++) {
        mem_base = xmlMemBlocks();
        ctx = gen_void_ptr(n_ctx, 0);
        localname = gen_const_xmlChar_ptr(n_localname, 1);
        prefix = gen_const_xmlChar_ptr(n_prefix, 2);
        URI = gen_const_xmlChar_ptr(n_URI, 3);
        nb_namespaces = gen_int(n_nb_namespaces, 4);
        namespaces = gen_const_xmlChar_ptr_ptr(n_namespaces, 5);
        nb_attributes = gen_int(n_nb_attributes, 6);
        nb_defaulted = gen_int(n_nb_defaulted, 7);
        attributes = gen_const_xmlChar_ptr_ptr(n_attributes, 8);

        xmlSAX2StartElementNs(ctx, (const xmlChar *)localname, (const xmlChar *)prefix, (const xmlChar *)URI, nb_namespaces, (const xmlChar **)namespaces, nb_attributes, nb_defaulted, (const xmlChar **)attributes);
	DTS_CHECK_EQ_MESSAGE("xmlSAX2StartElementNs", (void *)1, (void *)1, "xmlSAX2StartElementNs Failed");
        call_tests++;
        des_void_ptr(n_ctx, ctx, 0);
        des_const_xmlChar_ptr(n_localname, (const xmlChar *)localname, 1);
        des_const_xmlChar_ptr(n_prefix, (const xmlChar *)prefix, 2);
        des_const_xmlChar_ptr(n_URI, (const xmlChar *)URI, 3);
        des_int(n_nb_namespaces, nb_namespaces, 4);
        des_const_xmlChar_ptr_ptr(n_namespaces, (const xmlChar **)namespaces, 5);
        des_int(n_nb_attributes, nb_attributes, 6);
        des_int(n_nb_defaulted, nb_defaulted, 7);
        des_const_xmlChar_ptr_ptr(n_attributes, (const xmlChar **)attributes, 8);
        xmlResetLastError();
        if (mem_base != xmlMemBlocks()) {
            printf("Leak of %d blocks found in xmlSAX2StartElementNs",
	           xmlMemBlocks() - mem_base);
	    test_ret++;
            printf(" %d", n_ctx);
            printf(" %d", n_localname);
            printf(" %d", n_prefix);
            printf(" %d", n_URI);
            printf(" %d", n_nb_namespaces);
            printf(" %d", n_namespaces);
            printf(" %d", n_nb_attributes);
            printf(" %d", n_nb_defaulted);
            printf(" %d", n_attributes);
            printf("\n");
        }
    }
    }
    }
    }
    }
    }
    }
    }
    }
    function_tests++;

   // return(test_ret);
}


static void
test_xmlSAX2UnparsedEntityDecl(void) {
    int test_ret = 0;

    int mem_base;
    void * ctx; /* the user data (XML parser context) */
    int n_ctx;
    xmlChar * name; /* The name of the entity */
    int n_name;
    xmlChar * publicId; /* The public ID of the entity */
    int n_publicId;
    xmlChar * systemId; /* The system ID of the entity */
    int n_systemId;
    xmlChar * notationName; /* the name of the notation */
    int n_notationName;

    for (n_ctx = 0;n_ctx < gen_nb_void_ptr;n_ctx++) {
    for (n_name = 0;n_name < gen_nb_const_xmlChar_ptr;n_name++) {
    for (n_publicId = 0;n_publicId < gen_nb_const_xmlChar_ptr;n_publicId++) {
    for (n_systemId = 0;n_systemId < gen_nb_const_xmlChar_ptr;n_systemId++) {
    for (n_notationName = 0;n_notationName < gen_nb_const_xmlChar_ptr;n_notationName++) {
        mem_base = xmlMemBlocks();
        ctx = gen_void_ptr(n_ctx, 0);
        name = gen_const_xmlChar_ptr(n_name, 1);
        publicId = gen_const_xmlChar_ptr(n_publicId, 2);
        systemId = gen_const_xmlChar_ptr(n_systemId, 3);
        notationName = gen_const_xmlChar_ptr(n_notationName, 4);

        xmlSAX2UnparsedEntityDecl(ctx, (const xmlChar *)name, (const xmlChar *)publicId, (const xmlChar *)systemId, (const xmlChar *)notationName);
	DTS_CHECK_EQ_MESSAGE("xmlSAX2UnparsedEntityDecl", (void *)1, (void *)1, "xmlSAX2UnparsedEntityDecl Failed");
        call_tests++;
        des_void_ptr(n_ctx, ctx, 0);
        des_const_xmlChar_ptr(n_name, (const xmlChar *)name, 1);
        des_const_xmlChar_ptr(n_publicId, (const xmlChar *)publicId, 2);
        des_const_xmlChar_ptr(n_systemId, (const xmlChar *)systemId, 3);
        des_const_xmlChar_ptr(n_notationName, (const xmlChar *)notationName, 4);
        xmlResetLastError();
        if (mem_base != xmlMemBlocks()) {
            printf("Leak of %d blocks found in xmlSAX2UnparsedEntityDecl",
	           xmlMemBlocks() - mem_base);
	    test_ret++;
            printf(" %d", n_ctx);
            printf(" %d", n_name);
            printf(" %d", n_publicId);
            printf(" %d", n_systemId);
            printf(" %d", n_notationName);
            printf("\n");
        }
    }
    }
    }
    }
    }
    function_tests++;

  //  return(test_ret);
}


static void
test_xmlSAXDefaultVersion(void) {
    int test_ret = 0;

#if defined(LIBXML_SAX1_ENABLED)
#ifdef LIBXML_SAX1_ENABLED
    int mem_base;
    int ret_val;
    int version; /* the version, 1 or 2 */
    int n_version;

    for (n_version = 0;n_version < gen_nb_int;n_version++) {
        mem_base = xmlMemBlocks();
        version = gen_int(n_version, 0);

        ret_val = xmlSAXDefaultVersion(version);
	DTS_CHECK_EQ_MESSAGE("xmlSAXDefaultVersion", (void *)1, (void *)1, "xmlSAXDefaultVersion Failed");
     //   desret_int(ret_val);
        call_tests++;
        des_int(n_version, version, 0);
        xmlResetLastError();
        if (mem_base != xmlMemBlocks()) {
            printf("Leak of %d blocks found in xmlSAXDefaultVersion",
	           xmlMemBlocks() - mem_base);
	    test_ret++;
            printf(" %d", n_version);
            printf("\n");
        }
    }
    function_tests++;
#endif
#endif

    //return(test_ret);
}

static void
test_xmlSAXVersion(void) {
    int test_ret = 0;

    int mem_base;
    int ret_val;
    xmlSAXHandler * hdlr; /* the SAX handler */
    int n_hdlr;
    int version; /* the version, 1 or 2 */
    int n_version;

    for (n_hdlr = 0;n_hdlr < gen_nb_xmlSAXHandler_ptr;n_hdlr++) {
    for (n_version = 0;n_version < gen_nb_int;n_version++) {
        mem_base = xmlMemBlocks();
        hdlr = gen_xmlSAXHandler_ptr(n_hdlr, 0);
        version = gen_int(n_version, 1);

        ret_val = xmlSAXVersion(hdlr, version);
	DTS_CHECK_EQ_MESSAGE("xmlSAXVersion", (void *)1, (void *)1, "xmlSAXVersion Failed");
      //  desret_int(ret_val);
        call_tests++;
        des_xmlSAXHandler_ptr(n_hdlr, hdlr, 0);
        des_int(n_version, version, 1);
        xmlResetLastError();
        if (mem_base != xmlMemBlocks()) {
            printf("Leak of %d blocks found in xmlSAXVersion",
	           xmlMemBlocks() - mem_base);
	    test_ret++;
            printf(" %d", n_hdlr);
            printf(" %d", n_version);
            printf("\n");
        }
    }
    }
    function_tests++;

   // return(test_ret);
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
	{test_docbDefaultSAXHandlerInit,1},
	{test_htmlDefaultSAXHandlerInit,2},
	{test_xmlDefaultSAXHandlerInit,3},
	{test_xmlSAX2AttributeDecl,4},
	{test_xmlSAX2CDataBlock,5},
	{test_xmlSAX2Characters,6},
	{test_xmlSAX2Comment,7},
	{test_xmlSAX2ElementDecl,8},
	{test_xmlSAX2EndDocument,9},
	{test_xmlSAX2EndElement,10},
	
	{test_xmlSAX2EndElementNs,11},
	{test_xmlSAX2EntityDecl,12},
	{test_xmlSAX2ExternalSubset,13},
	{test_xmlSAX2GetColumnNumber,14},
	{test_xmlSAX2GetEntity,15},
	{test_xmlSAX2GetLineNumber,16},
	{test_xmlSAX2GetParameterEntity,17},
	{test_xmlSAX2GetPublicId,18},
	{test_xmlSAX2GetSystemId,19},
	{test_xmlSAX2HasExternalSubset,20},
	
	{test_xmlSAX2HasInternalSubset,21},
	{test_xmlSAX2IgnorableWhitespace,22},
	{test_xmlSAX2InitDefaultSAXHandler,23},
	{test_xmlSAX2InitDocbDefaultSAXHandler,24},
	{test_xmlSAX2InitHtmlDefaultSAXHandler,25},
	{test_xmlSAX2InternalSubset,26},
	{test_xmlSAX2IsStandalone,27},
	{test_xmlSAX2NotationDecl,28},
	{test_xmlSAX2ProcessingInstruction,29},
	{test_xmlSAX2Reference,30},
	
	{test_xmlSAX2ResolveEntity,31},
	{test_xmlSAX2SetDocumentLocator,32},
	{test_xmlSAX2StartDocument,33},
	{test_xmlSAX2StartElement,34},
	{test_xmlSAX2StartElementNs,35},
	{test_xmlSAX2UnparsedEntityDecl,36},
	{test_xmlSAXDefaultVersion,37},
	{test_xmlSAXVersion,38},
	{ NULL, 0 },
	
};


#endif

