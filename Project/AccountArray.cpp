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
		cout << "�� �̻� ���¸� ������ �� �����ϴ�." << endl;
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