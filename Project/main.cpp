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
	account(int num, int mon, char* nam)
	{
		number = num;
		money = mon;
		int len = strlen(nam) + 1;
		name = new char[len];
		strcpy(name, nam);
	}
	void CallAccount()
	{
		cout << "계좌ID  :" << number << endl << "이름 :" << name << endl << "입금액 :" << money << endl;
	}
	int compare(int num)
	{
		if (number == num)
			return 1;
		else
			return 0;
	}
	void Deposit(int mon)
	{
		money += mon;
	}
	int Withdraw(int mon)
	{
		if (money < mon)
			return 0;
		else
			money -= mon;
	}
	~account()
	{
		cout << "삭제됨 " << endl;
		delete name;
	}

};

int main(void)
{
	int num, in_num, money;
	char name[30];
	account *accounts[MAX_ACCOUNT];
	int account_num = 0;

	while (1)
	{
		call_menu();
		cin >> num;

		if (num == 1)
		{
			if (account_num < MAX_ACCOUNT)
			{
				cout << " 계좌 ID : ";
				cin >> in_num;
				cout << " 이름	  : ";
				cin >> name;
				cout << " 입금액  : ";
				cin >> money;

				accounts[account_num] = new account(in_num, money, name);

				for (int cur = 0; cur < account_num; cur++)
				{
					if (accounts[cur]->compare(in_num) == 1)
					{
						delete accounts[account_num];
						account_num--;
						cout << "동일 ID 계좌 생성이 불가능합니다." << endl;
					}
				}
				account_num++;
			}
			else
				cout << "더 이상 계좌생성이 불가능합니다." << endl;
		}
		else if (num == 2)
		{
			cout << "[입금]" << endl;
			cout << "계좌 ID :";
			cin >> in_num;
			cout << "입금액:";
			cin >> money;
			for (int cur = 0; cur < account_num; cur++)
			{
				if (accounts[cur]->compare(in_num) == 1)
					accounts[cur]->Deposit(money);

				else if (cur == account_num - 1)
					cout << "올바른 ID 를 입력해주세요 ";
			}
		}
		else if (num == 3)
		{
			cout << "[출금]" << endl;
			cout << "계좌 ID :";
			cin >> in_num;
			cout << "출금액:";
			cin >> money;
			for (int cur = 0; cur < account_num; cur++)
			{
				if (accounts[cur]->compare(in_num) == 1)
				{
					if (accounts[cur]->Withdraw(money) == 0)
						cout << "금액이 부족합니다." << endl;
				}
				else if (cur == account_num - 1)
					cout << "올바른 ID 를 입력해주세요 ";
			}
		}
		else if (num == 4)
		{
			for (int cur = 0; cur < account_num; cur++)
			{
				accounts[cur]->CallAccount();
			}
		}
		else if (num == 5)
		{
			for (int cur = 0; cur < account_num; cur++)
			{
				delete accounts[cur];
			}
			break;
		}
		else
			cout << "올바른 숫자를 입력하세요 " << endl;
	}
	return 0;
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