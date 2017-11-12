// strBase.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;


int _tmain(int argc, _TCHAR* argv[])
{
	string str = " ";
	str = str + "world";
	str = "hello" + str;
	cout << str << endl;
	while(1);

	return 0;
}

