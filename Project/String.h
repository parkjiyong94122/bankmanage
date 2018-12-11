#pragma once
#include<iostream>
#include <cstring>


using namespace std;


class String
{
private:
	int len;
	char* str;
public:
	String();						//매개변수 없는 생성자
	String(const char* s);			//매개변수 있는 생성자
	String(const String& s);		//복사생성자
	String& operator=(const String& s);
	String operator+(const String& s);
	String& operator+=(const String& s);
	bool operator==(const String& s);
	friend ostream& operator<<(ostream& os, const String& s);
	friend istream& operator>>(istream& is, String& s);
	~String();
};