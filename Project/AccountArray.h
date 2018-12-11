
class account;

template <typename T>
class BoundCheckPointArray
{
private:
	T* accounts;
	int acclen;
public:
	BoundCheckPointArray(int len);
	T operator[](int len);
	void AccountCreate(int num, T account);
	~BoundCheckPointArray();
};