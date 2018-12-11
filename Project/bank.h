#pragma once
#define MAX_ACCOUNT 100
#include <iostream>
#include <cstring>

using namespace std;
void call_menu();


class account
{
private:
	int money;
	int number;
	char* name;

public:
	account(int num, int mon, char* nam);
	account(account &copy);
	virtual void CallAccount()const;
	int compare(int num);
	virtual void Deposit(int mon);
	void Withdraw(int mon);
	~account();
};
class NormalAccount : public account
{
private:
	double interestRate;
public:
	NormalAccount(int num, int mon, char* nam, double rate);
	void Deposit(int mon);
	void CallAccount() const;
};

class HighCreditAccount : public account
{
private:
	double interestRate;
	char specialRate;
public:
	HighCreditAccount(int num, int mon, char* nam, double rate, char special);
	void Deposit(int mon);
	void CallAccount() const;
};
class ControlBank
{
private:
	account * accounts[MAX_ACCOUNT];
	int account_num;
public:
	ControlBank();
	int AccountCompare(int num);
	void CreateAccounts(account* account);
	//�Ա�
	void DepositAccounts(int num, int money);
	//���
	void WithdrawAccounts(int num, int money);
	//Ȯ��
	void ShowAllAccounts();
	//����
	void DeleteAccounts();
};
