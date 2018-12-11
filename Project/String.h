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
	String();						//�Ű����� ���� ������
	String(const char* s);			//�Ű����� �ִ� ������
	String(const String& s);		//���������
	String& operator=(const String& s);
	String operator+(const String& s);
	String& operator+=(const String& s);
	bool operator==(const String& s);
	friend ostream& operator<<(ostream& os, const String& s);
	friend istream& operator>>(istream& is, String& s);
	~String();
};