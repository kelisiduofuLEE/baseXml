
#include "baseXml.h"
#include "strBase.h"
#include <cstring>
#include <iostream>


#ifdef _USEFSTREAM_
#include <fstream>
#endif


#ifdef	_WIN32
#include <Windows.h>
#include "StdAfx.h"
#elif	__linux
#include <unistd.h>
#endif

xmlBase::xmlBase(){
}

xmlBase::~xmlBase(){
}

xmlNode::xmlNode(void){
}

xmlNode::~xmlNode(void){
}

//strBase xmlDocument::xmlStatement = ;

xmlDocument::xmlDocument() :
	docPath(0),document(0) {

}

xmlDocument::xmlDocument(char *filePath) {
	splitting(filePath);
}

xmlDocument::~xmlDocument(){

}

void xmlDocument::xmlRead(){

}

void xmlDocument::setDocument(char *doc){
	document = doc;
}

//未判断相对路径和绝对路径
bool xmlDocument::splitting(char *fullPath){
	char *path = fullPath;	

	char *p = fullPath + std::strlen(path) - 1;
#ifdef _WIN32	
#	define DPCH		'\\'
#elif __linux
#	define DPCH		'/'
#endif
#	define CHEND	'\0'
	if(*p == CHEND || *p == DPCH){
		std::cout << "Error : no xml file!" << std::endl;	//error output
		return false;
	}

	while(*p != DPCH)
		p--;
	
	char *file = p;
	document = file;

	if(p == path){
		docPath = NULL;
		std::cout << "Message : the xml is in local path!" << std::endl;	//error output
	}
	else{
		docPath = fullPath;
	}
	return true;
}

bool xmlDocument::isFileExist(const char *fullPath){
	if(fullPath == NULL){		
		std::cout << "Error : file is nil!" << std::endl;	//error output
		return false;
	}
	else{
#ifdef	_USEFSTREAM_
		std::fstream fs;
		fs.open(fullPath,std::ios::in);

		if(fs)

#elif	_WIN32
		LPCWSTR fileName = reinterpret_cast<LPCWSTR>(fullPath);
		LPWIN32_FIND_DATAW findData;
		HANDLE hFind = FindFirstFile(fileName,findData);

		if(hFind == INVALID_HANDLE_VALUE)

#elif	__linux
		int ret = access(fullPath,0);

		if(ret == 0)

#endif
		{
			std::cout << "Error : file is not exist!" << std::endl;	//error output
			return false;
		}
		else {
			std::cout << "Error : file is exist!" << std::endl;	//error output
#ifdef	_USEFSTREAM_
			fs.close();

#elif	_WIN32
			CloseHandle(hFind);

#elif	__linux
			//do nothing;

#endif
		}
	}
	return true;
}

bool xmlDocument::isFileExist(){
	//fullPath
	if(docPath.c_str() == NULL){		
		std::cout << "Error : file is nil!" << std::endl;	//error output
		return false;
	}
	else
		return isFileExist(docPath.c_str());
}

void xmlDocument::read() {
	//isFileExist改变了docPath和file，不能使用const修饰this指针
	bool isExist = isFileExist(); 
	if(isExist){

	}
}

void xmlDocument::open(){
	
}