/*
 *	xmlÎÄµµÊ±Ê÷ÐÎ½á¹¹µÄÎÄ¼þ¡£Ò»¸öxmlÎÄµµ°üº¬element£¬attribute£¬text£¬
 *	element°üº¬attributeºÍtextºÍÆäËûelement£¬attribute°üº¬keyºÍvalue¡£
 *	xml±ØÐëÒªÓÐ¹Ø±Õ±êÇ©£¬ÉùÃ÷²»ÊÇxmlÎÄµµµÄ×é³É²¿·Ö£¬²»ÐèÒª¹Ø±Õ±êÇ©¡£±êÇ©¶Ô´óÐ¡Ð´Ãô¸Ð¡£
 *	xml±êÇ©ÊÇÒ»¶ÔÒ»Æ¥ÅäµÄ¹ØÏµ£¬¿ÉÒÔÇ¶Ì×£¬µ«ÊÇÔÚÒ»¶Ô±êÇ©ÄÚÇ¶Ì×£¬±ØÐë°üº¬Ò»¶Ô¡£
 *	xmlÎÄµµ±ØÐë°üº¬¸ùÔªËØ¡£ÊÇÆäËûÔªËØµÄ¸¸Ç×£¬ÆäËûÔªËØÒ²¿ÉÒÔÓµÓÐ×ÓÔªËØ¡£
 *	xmlµÄattribute°üº¬Ò»¸ö¼üÖµ¶Ô£¬ÐÎÈç£ºkey="val"£¬Öµ±ØÐë¼Ó""
 *	xmlÎÄµµÖÐ'<'£¬'&'ÊÇ·Ç·¨×Ö·û£¬Ó¦¸ÃÓÃÊµÌåÒýÓÃ&lt;ºÍ&amp;À´Ìæ´ú¡£
 *	xmlµÄ×¢ÊÍ£ºÐÎÈç<!-- This is a comment -->
 *	xmlÎÄµµÖÐ£¬¿Õ¸ñ¶¼»á±»±£Áô¡£
 *	xmlÖÐµÄÊôÐÔ×îºÃ²»ÒªÊ¹ÓÃ£¬ÊôÐÔ×îºÃÊÂÄÇÐ©ÓëÊý¾ÝÎÞ¹ØµÄ£¬±ÈÈçÔªÊý¾Ý£¨ÃèÊöÊý¾ÝµÄÊý¾Ý£©
 *	<?xml version="1.0" encoding="ISO-8859-1"?> ±íÊ¾°æ±¾£¬×Ö·û±àÂë
 *	
 */


#pragma once



#include "strBase.h"

#ifndef	XMLCHARATERSET_HAND
#	define XMLCHARATERSET_HAND
#		define		XMLFILEHANDER		"<?xml"
#		define		COMMENTHANDER		"<!--"
#		define		DTDHANDER			"<!"
#		define		CDATAHANDER			"<![CDATA["

#endif

#ifndef	XMLCHARATERSET_END
#	define XMLCHARATERSET_END
#		define		XMLFILEEND			"?>"
#		define		COMMENTEND			"-->"
#		define		FIELDEND			">"

#endif

#ifndef	XMLLABELSET
#	define XMLLABELSET
#		define		TABLEHANDFRONT		"<"
#		define		TABLEHANDTAIL		">"
#		define		TABLEENDFRONT		"</"
#		define		TABLEENDTAIL		">"

#endif

class xmlElement;
class xmlDocument;
class xmlDocument;
class xmlNode;
class xmlAttribute;
class xmlText;

class xmlText{
public:
	xmlText();

	~xmlText();

private:
	strBase textData;

};

class xmlAttribute :
	public xmlNode {
public:
	xmlAttribute(void);

	virtual ~xmlAttribute();

	typedef unsigned int uint_t;

	bool isEnd() const {
		return end;
	}

private:
	strBase key;

	strBase value;

	uint_t attrNum;

	xmlAttribute *nextAttr;

	bool end;

};

class xmlBase {
public:
	xmlBase();

	virtual ~xmlBase();

	virtual void xmlPrint() = 0;

	virtual bool xmlParse() = 0;

	virtual void xmlRead() = 0;

private:
	
};

class xmlNode :
	public xmlBase {
public:
	xmlNode(void);

	typedef size_t size_type;
	
	virtual ~xmlNode(void);
	
private:

};

class xmlDocument{
public:
	typedef unsigned int uint_t;
	typedef size_t	size_type;

	xmlDocument(void);

	xmlDocument(char *filePath);

	virtual ~xmlDocument(void);
	
	static strBase xmlStatement;

	virtual void xmlPrint();
	
	void read();

	virtual void xmlRead();

	const char *getDocument() const{
		return document.c_str();
	}
	
	bool isFileExist(const char *fullPath);

	void open();

private:
	void setDocument(char *doc);

	bool splitting(char *fullPath);

	bool isFileExist();

	strBase document;

	strBase docPath;

	//strBase docStart;

	//strBase docEnd;

	xmlElement *rootElement;
	
};

class xmlElement :
	public xmlNode {
public:
	typedef unsigned int uint_t;

	xmlElement();

	virtual ~xmlElement();

private:
	strBase label;

	xmlText *text;

	uint_t childNum;

	xmlElement *childElementPtr;//µÚÒ»¸ö×ÓÔªËØ

	xmlElement *nextElementPtr; //ÏÂÒ»¸öÐÖµÜÔªËØ

	xmlElement *prevElementPtr; //Ç°Ò»¸öÐÖµÜÔªËØ

	xmlAttribute *attribute;
	
	//xmlNode *firstElement;
};