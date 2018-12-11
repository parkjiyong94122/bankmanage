
class account;
class BoundCheckPointArray
{
private:
	account** accounts;
	int acclen;
public:
	BoundCheckPointArray(int len);
	account* operator[](int len);
	void AccountCreate(int num, account* account);
	~BoundCheckPointArray();
};