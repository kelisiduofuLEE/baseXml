/*
 *	xml�ĵ�ʱ���νṹ���ļ���һ��xml�ĵ�����element��attribute��text��
 *	element����attribute��text������element��attribute����key��value��
 *	xml����Ҫ�йرձ�ǩ����������xml�ĵ�����ɲ��֣�����Ҫ�رձ�ǩ����ǩ�Դ�Сд���С�
 *	xml��ǩ��һ��һƥ��Ĺ�ϵ������Ƕ�ף�������һ�Ա�ǩ��Ƕ�ף��������һ�ԡ�
 *	xml�ĵ����������Ԫ�ء�������Ԫ�صĸ��ף�����Ԫ��Ҳ����ӵ����Ԫ�ء�
 *	xml��attribute����һ����ֵ�ԣ����磺key="val"��ֵ�����""
 *	xml�ĵ���'<'��'&'�ǷǷ��ַ���Ӧ����ʵ������&lt;��&amp;�������
 *	xml��ע�ͣ�����<!-- This is a comment -->
 *	xml�ĵ��У��ո񶼻ᱻ������
 *	xml�е�������ò�Ҫʹ�ã������������Щ�������޹صģ�����Ԫ���ݣ��������ݵ����ݣ�
 *	<?xml version="1.0" encoding="ISO-8859-1"?> ��ʾ�汾���ַ�����
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

	xmlElement *childElementPtr;//��һ����Ԫ��

	xmlElement *nextElementPtr; //��һ���ֵ�Ԫ��

	xmlElement *prevElementPtr; //ǰһ���ֵ�Ԫ��

	xmlAttribute *attribute;
	
	//xmlNode *firstElement;
};