#include"exception.h"
#include<iostream>
using namespace std;

DepositException::DepositException(int money) : myMoney(money)
{}
void DepositException::ShowResult()
{
	cout << "�Ա� ���� : " << myMoney << "�� �Ա��� �� �����ϴ�." << endl;
}



WithdrawException::WithdrawException(int money) : myMoney(money)
{}
void WithdrawException::ShowResult()
{
	cout << "��� ���� : " << myMoney << "�� ����� �� �����ϴ�." << endl;
}

