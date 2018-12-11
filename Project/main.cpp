#include"bank.h"


int main(void)
{
	int num, num2, in_num, money;
	double rate;
	char special;
	char name[30];

	ControlBank bank;

	int account_num = 0;

	while (1)
	{
		call_menu();
		cin >> num;

		if (num == 1)
		{
			cout << "���� ���� : 1		�ſ� ���� : 2        ::";
			cin >> num2;

			switch (num2)
			{
			case 1:
				cout << " ���� ID : ";
				cin >> in_num;
				cout << " �̸�	  : ";
				cin >> name;
				cout << " �Աݾ�  : ";
				cin >> money;
				cout << " ����    : ";
				cin >> rate;
				bank.CreateAccounts(new NormalAccount(in_num, money, name, rate));
				break;

			case 2:
				cout << " ���� ID : ";
				cin >> in_num;
				cout << " �̸�	  : ";
				cin >> name;
				cout << " �Աݾ�  : ";
				cin >> money;
				cout << " ����    : ";
				cin >> rate;
				cout << " ���    : ";
				cin >> special;
				bank.CreateAccounts(new HighCreditAccount(in_num, money, name, rate, special));
				break;

			}
		}
		else if (num == 2)
		{
			cout << "[�Ա�]" << endl;
			cout << "���� ID :";
			cin >> in_num;
			cout << "�Աݾ�:";
			cin >> money;
			bank.DepositAccounts(in_num, money);
		}
		else if (num == 3)
		{
			cout << "[���]" << endl;
			cout << "���� ID :";
			cin >> in_num;
			cout << "��ݾ�:";
			cin >> money;
			bank.WithdrawAccounts(in_num, money);
		}
		else if (num == 4)
		{
			bank.ShowAllAccounts();
		}
		else if (num == 5)
		{
			bank.DeleteAccounts();
			break;
		}
		else
			cout << "�ùٸ� ���ڸ� �Է��ϼ��� " << endl;
	}
	return 0;
}

