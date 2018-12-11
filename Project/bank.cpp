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
		cout << "���� ID ���� ������ �Ұ����մϴ�." << endl;
	}
	else
	{
		//accounts[account_num] = account;
		accounts.AccountCreate(account_num, account);
		account_num++;
	}
	//���� id ����
}
//�Ա�
int ControlBank::DepositAccounts(int num, int money)
{
	int sel_count = AccountCompare(num);
	if (sel_count == -1)
	{
		cout << "�ùٸ� ID �� �Է����ּ��� " << endl;
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
//���
int ControlBank::WithdrawAccounts(int num, int money)
{
	int sel_count = AccountCompare(num);
	if (sel_count == -1)
	{
		cout << "�ùٸ� ID �� �Է����ּ��� " << endl;
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
//Ȯ��
void ControlBank::ShowAllAccounts()
{
	for (int cur = 0; cur < account_num; cur++)
	{
		accounts[cur]->CallAccount();
	}
}
//����
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
	cout << "1. ���� ���� " << endl;
	cout << "2. �Ա�" << endl;
	cout << "3. ���" << endl;
	cout << "4. �������� ��ü ���" << endl;
	cout << "5. ���α׷� ����" << endl << endl;

	cout << "���� : ";
}