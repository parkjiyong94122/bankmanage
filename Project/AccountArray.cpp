#include"AccountArray.h"
#include<iostream>
using namespace std;

BoundCheckPointArray::BoundCheckPointArray(int len) : acclen(len)
{
	accounts = new account*[len];
}
account* BoundCheckPointArray::operator[](int idx)
{
	if (idx < 0 || idx > acclen)
	{
		cout << "더 이상 계좌를 개설할 수 없습니다." << endl;
		exit(1);
	}
	return accounts[idx];
}
void BoundCheckPointArray::AccountCreate(int num, account* account)
{
	accounts[num] = account;
}
BoundCheckPointArray::~BoundCheckPointArray()
{
	delete[] accounts;
}