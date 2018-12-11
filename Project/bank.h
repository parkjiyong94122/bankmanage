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
	//입금
	int DepositAccounts(int num, int money);
	//출금
	int WithdrawAccounts(int num, int money);
	//확인
	void ShowAllAccounts();
	//삭제
	void DeleteAccounts();
};
