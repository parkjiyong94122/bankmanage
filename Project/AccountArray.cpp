#include"AccountArray.h"
#include<iostream>
using namespace std;

template <typename T>
BoundCheckPointArray<T>::BoundCheckPointArray(int len) : acclen(len)
{
	accounts = new T[len];
}

template <typename T>
T BoundCheckPointArray<T>::operator[](int idx)
{
	if (idx < 0 || idx > acclen)
	{
		cout << "�� �̻� ���¸� ������ �� �����ϴ�." << endl;
		exit(1);
	}
	return accounts[idx];
}

template <typename T>
void BoundCheckPointArray<T>::AccountCreate(int num, T account)
{
	accounts[num] = account;
}

template <typename T>
BoundCheckPointArray<T>::~BoundCheckPointArray()
{
	delete[] accounts;
}