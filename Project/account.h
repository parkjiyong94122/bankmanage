#define MAX_ACCOUNT 5
#include <cstring>
#include "AccountArray.h"
#include "exception.h"
#ifndef IOSTREAM
#include <iostream>
using namespace std;
#endif !IOSTREAM

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
	int ReturnId();
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
