#include"exception.h"
#include<iostream>
using namespace std;

DepositException::DepositException(int money) : myMoney(money)
{}
void DepositException::ShowResult()
{
	cout << "입금 오류 : " << myMoney << "를 입금할 수 없습니다." << endl;
}



WithdrawException::WithdrawException(int money) : myMoney(money)
{}
void WithdrawException::ShowResult()
{
	cout << "출금 오류 : " << myMoney << "를 출금할 수 없습니다." << endl;
}

