#include "StdAfx.h"
#include "strBase.h"
#include <iostream>
#include <cstring>


strBase::baseType strBase:: nilData = {0, 0, {'0'}};

strBase::strBase(void):
	baseData(&nilData),
	stZero(0) {
}

strBase::strBase(const strBase &other) :
	stZero(0) {
	init(other.length());
	memcpy(start(),other.data(),other.length());
}

//strBase::strBase(const char *other) :
//	stZero(0) {
//	init(std::strlen(other));
//	memcpy(start(),other,strlen(other));
//}
	
strBase::strBase(const char *other, const strBase::size_type length) :
	stZero(0) {
		size_type type;
	if(length == 0)
		type = std::strlen(other);
	else
		type = length;
	
	init(type);
	memcpy(start(),other, type);
}

strBase::~strBase(void){
	if(isNil())
		delete baseData;
}

strBase & strBase::operator=(strBase &other){
	if(this == &other)
		return *this;
	size_type temp_size = other.size();
	if(isNil())
		init(temp_size);
	memcpy(baseData->str_, other.c_str(),temp_size);
	return *this;
}


strBase & strBase::operator=(char *other){
	if(other == NULL)
		return *this;
	size_type tmpSize = std::strlen(other);
	if(isNil())
		init(tmpSize);
	memcpy(baseData->str_, other, tmpSize);
	return *this;
}

char strBase::operator[](int index){
	size_type temIndex = (size_type)index;
	if(temIndex >= stZero && size() < temIndex){
		std::cout << "ERROR : Access is invalid" << std::endl;
		return '\0';
	}
	return data()[index];
}

strBase operator+(strBase &a, strBase &b){
	strBase tmp;
	tmp.reserve(a.length() + b.length());
	tmp += a;
	tmp += b;
	return tmp;//append(a, b);
}

strBase operator+(char * a, strBase &b){
	strBase tmp;
	tmp.reserve(strlen(a) + b.length());
	tmp += a;
	tmp += b;
	return tmp;//append(a, b);
}

strBase operator+(strBase &a, char * b){
	strBase tmp;
	tmp.reserve(a.length() + strlen(b));
	tmp += a;
	tmp += b;
	return tmp;//append(a, b);
}

void strBase::append(strBase &add, size_type len){
	size_type newSize = size() + len;
	size_type old_cap  = capacity();
	if(newSize > capacity()){
		reserve(newSize);
	}
	memmove(finish(), add.data(),len);
	set_size(newSize);
	return;
}

//void strBase::append(char *add, size_type len){
//
//}

strBase & strBase::operator+=(strBase &add){
	append(add, add.size());
	return *this;
}

strBase & strBase::operator+=(char * add){
	strBase tmp(add);
	append(tmp, tmp.size());
	return *this;
}

void strBase::reserve(size_type cap){
	if(cap > capacity()){
		strBase temp;//  = baseData;
		temp.init(length(), cap);
		memcpy(temp.start(), data(),length());
		swap(temp);
	}
	return;
}