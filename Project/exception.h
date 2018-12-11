class AccountException
{
public:
	virtual void ShowResult() = 0;
};

class DepositException : public AccountException
{
private:
	int myMoney;
public:
	DepositException(int money);
	void ShowResult();
};

class WithdrawException : public AccountException
{
private:
	int myMoney;
public:
	WithdrawException(int money);
	void ShowResult();
};

