#include"bank.h"

account::account(int num, int mon, char* nam)
{
	number = num;
	money = mon;
	int len = strlen(nam) + 1;
	name = new char[len];
	strcpy(name, nam);
}
account::account(account &copy) : number(copy.number), money(copy.money)
{
	int len = strlen(copy.name) + 1;
	name = new char[len];
	strcpy(name, copy.name);
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
void account::Deposit(int mon)
{
	money += mon;
}
void account::Withdraw(int mon)
{
	if (money < mon)
		cout << "잔액이 부족합니다." << endl;
	else
		money -= mon;
}
account::~account()
{
	cout << "삭제됨 " << endl;
	delete name;
}

NormalAccount::NormalAccount(int num, int mon, char* nam, double rate) : account(num, mon, nam), interestRate(rate*0.01)
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

HighCreditAccount::HighCreditAccount(int num, int mon, char* nam, double rate, char special) : account(num, mon, nam), specialRate(special), interestRate(rate*0.01)
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


ControlBank::ControlBank() :account_num(0)
{}
int ControlBank::AccountCompare(int num)
{
	for (int cur = 0; cur < account_num; cur++)
	{
		if (accounts[cur]->compare(num) == 1)
			return cur;
	}
	return -1;
}
void ControlBank::CreateAccounts(account* account)
{
	if (account_num < MAX_ACCOUNT)
	{
		int sel_count = AccountCompare(account_num);
		if (sel_count != -1)
		{
			cout << "동일 ID 계좌 생성이 불가능합니다." << endl;
		}
		else
		{
			accounts[account_num] = account;
			account_num++;
		}
	}
	else
	{
		cout << "더 이상 계좌 생성이 불가능합니다." << endl;
	}
	//동일 id 제외
}
//입금
void ControlBank::DepositAccounts(int num, int money)
{
	int sel_count = AccountCompare(num);
	if (sel_count == -1)
	{
		cout << "올바른 ID 를 입력해주세요 " << endl;
	}
	else
	{
		accounts[sel_count]->Deposit(money);
	}
}
//출금
void ControlBank::WithdrawAccounts(int num, int money)
{
	int sel_count = AccountCompare(num);
	if (sel_count == -1)
	{
		cout << "올바른 ID 를 입력해주세요 " << endl;
	}
	else
	{
		accounts[sel_count]->Withdraw(money);
	}
}
//확인
void ControlBank::ShowAllAccounts()
{
	for (int cur = 0; cur < account_num; cur++)
	{
		accounts[cur]->CallAccount();
	}
}
//삭제
void ControlBank::DeleteAccounts()
{
	for (int cur = 0; cur < account_num; cur++)
	{
		delete accounts[cur];
	}
}

void call_menu()
{
	cout << "---------Menu---------" << endl;
	cout << "1. 계좌 개설 " << endl;
	cout << "2. 입금" << endl;
	cout << "3. 출금" << endl;
	cout << "4. 계좌정보 전체 출력" << endl;
	cout << "5. 프로그램 종료" << endl << endl;

	cout << "선택 : ";
}