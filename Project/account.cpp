#include "account.h"

account::account(int num = 0, int mon = 0, String nam = NULL)
{
	number = num;
	money = mon;
	String str(nam);
}

account::account(account &copy) : number(copy.number), money(copy.money)
{
	String str(copy.name);
	str = name;
}
void account::CallAccount()const
{
	cout << "계좌ID  :" << number << endl << "이름 :" << name << endl << "입금액 :" << money << endl;
}
int account::compare(int num)
{
	if (number == num)
		return 1;
	else
		return 0;
}
void account::Deposit(int mon)  throw (DepositException)
{
	if (mon < 0)
	{
		DepositException expn(mon);
		throw expn;
	}
	money += mon;
}
void account::Withdraw(int mon) throw (WithdrawException)
{
	if (money < mon)
	{
		WithdrawException expn(mon);
		throw expn;
	}
	money -= mon;
}
int account::ReturnId()
{
	return number;
}
account::~account()
{
	cout << "삭제됨 " << endl;
	delete name;
}

NormalAccount::NormalAccount(int num, int mon, String nam, double rate) : account(num, mon, nam), interestRate(rate*0.01)
{}
void NormalAccount::Deposit(int mon)
{
	account::Deposit(mon);
	account::Deposit((int)(mon*interestRate));
}
void NormalAccount::CallAccount() const
{
	account::CallAccount();
	cout << "이자율 : " << interestRate * 100 << endl;
}

HighCreditAccount::HighCreditAccount(int num, int mon, String nam, double rate, char special) : account(num, mon, nam), specialRate(special), interestRate(rate*0.01)
{
	if (special == 'A')
		interestRate += 0.7;
	else if (special == 'B')
		interestRate += 0.4;
	else if (special == 'C')
		interestRate += 0.2;
}
void HighCreditAccount::Deposit(int mon)
{
	account::Deposit(mon);
	account::Deposit((int)(mon*interestRate));
}
void HighCreditAccount::CallAccount() const
{
	account::CallAccount();
	cout << "이자율 : " << interestRate * 100 << endl;
	cout << "고객등급 : " << specialRate << endl;
}

