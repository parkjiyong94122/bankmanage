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
			cout << "보통 계좌 : 1		신용 계좌 : 2        ::";
			cin >> num2;

			switch (num2)
			{
			case 1:
				cout << " 계좌 ID : ";
				cin >> in_num;
				cout << " 이름	  : ";
				cin >> name;
				cout << " 입금액  : ";
				cin >> money;
				cout << " 이율    : ";
				cin >> rate;
				bank.CreateAccounts(new NormalAccount(in_num, money, name, rate));
				break;

			case 2:
				cout << " 계좌 ID : ";
				cin >> in_num;
				cout << " 이름	  : ";
				cin >> name;
				cout << " 입금액  : ";
				cin >> money;
				cout << " 이율    : ";
				cin >> rate;
				cout << " 등급    : ";
				cin >> special;
				bank.CreateAccounts(new HighCreditAccount(in_num, money, name, rate, special));
				break;

			}
		}
		else if (num == 2)
		{
			cout << "[입금]" << endl;
			cout << "계좌 ID :";
			cin >> in_num;
			cout << "입금액:";
			cin >> money;
			bank.DepositAccounts(in_num, money);
		}
		else if (num == 3)
		{
			cout << "[출금]" << endl;
			cout << "계좌 ID :";
			cin >> in_num;
			cout << "출금액:";
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
			cout << "올바른 숫자를 입력하세요 " << endl;
	}
	return 0;
}

