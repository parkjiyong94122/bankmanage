#define MAX_ACCOUNT 5
#include "account.h"


void call_menu();

class ControlBank
{
private:
	BoundCheckPointArray accounts;
	int account_num;
public:
	ControlBank();
	int AccountCompare(int num);
	void CreateAccounts(account* account);
	//�Ա�
	int DepositAccounts(int num, int money);
	//���
	int WithdrawAccounts(int num, int money);
	//Ȯ��
	void ShowAllAccounts();
	//����
	void DeleteAccounts();
};
