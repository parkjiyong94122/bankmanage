#include"String.h"

String::String()
{
	len = 0;
	str = NULL;
}
String::String(const char* s)
{
	len = strlen(s) + 1;
	str = new char[len];
	strcpy(str, s);
}
String::String(const String& s)
{
	len = s.len;
	str = new char[len];
	strcpy(str, s.str);
}
String& String::operator=(const String& s)
{
	if (str != NULL)
		delete str;

	len = s.len;
	str = new char[len];
	strcpy(str, s.str);

	return *this;
}
String String::operator+(const String& s)
{
	String newStr(strcat(str, s.str));

	return newStr;
}
String& String::operator+=(const String& s)
{
	len = len + s.len - 1;
	char* newstr = new char[len];
	newstr = strcat(str, s.str);
	delete str;

	str = newstr;

	return *this;
}
bool String::operator==(const String& s)
{
	return strcmp(s.str, str) ? false : true;
}

// 
//입출력을 위해 iostream 헤더파일을 사용
//입력 : istream class
//출력 : ostream class
//

//출력을 위한 << 연산자 오버로딩
ostream& operator<<(ostream& os, const String& s)
{
	os << s.str;
	return os;
}

//입력을 위한 >> 연산자 오버로딩
istream& operator>>(istream& is, String& s)
{
	char str[100];
	is >> s.str;
	s = String(str);

	return is;
}
String::~String()
{
	if (str != NULL)
		delete[]str;
}
