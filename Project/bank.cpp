#include"bank.h"

ControlBank::ControlBank() :account_num(0), accounts(MAX_ACCOUNT)
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
	int sel_count = AccountCompare(account->ReturnId());
	if (sel_count != -1)
	{
		cout << "동일 ID 계좌 생성이 불가능합니다." << endl;
	}
	else
	{
		//accounts[account_num] = account;
		accounts.AccountCreate(account_num, account);
		account_num++;
	}
	//동일 id 제외
}
//입금
int ControlBank::DepositAccounts(int num, int money)
{
	int sel_count = AccountCompare(num);
	if (sel_count == -1)
	{
		cout << "올바른 ID 를 입력해주세요 " << endl;
	}
	else
	{
		try
		{
			accounts[sel_count]->Deposit(money);
		}
		catch (AccountException & expn)
		{
			expn.ShowResult();
			return 1;
		}
		return 0;
	}
}
//출금
int ControlBank::WithdrawAccounts(int num, int money)
{
	int sel_count = AccountCompare(num);
	if (sel_count == -1)
	{
		cout << "올바른 ID 를 입력해주세요 " << endl;
	}
	else
	{
		try
		{
			accounts[sel_count]->Withdraw(money);
		}
		catch (AccountException & expn)
		{
			expn.ShowResult();
			return 1;
		}
		return 0;
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