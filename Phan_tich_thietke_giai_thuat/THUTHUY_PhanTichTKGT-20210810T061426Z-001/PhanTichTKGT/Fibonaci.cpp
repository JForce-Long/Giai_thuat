#include <iostream>
using namespace std;

int DPFib(int n)
{
	int F[n];
	F[0] = 0; F[1] = 1;
	if (n>1)
	{
		for (int k=2; k<=n; k++)
			F[k] = F[k-1] + F[k-2];
	}
	return F[n];
}
int DPFib2(int n)
{
	int Fk2 = 0, Fk1 = 1, k=2, tg;
	while(k<=n)
	{
		tg = Fk1;
		Fk1 = Fk1+Fk2;
		Fk2 = tg;
		k = k+1;
	}
	return Fk1;
}
int main()
{
	int n;
	cout << "Nhap n = "; cin >> n;
	//cout << "Kq = " << DPFib(n);
	cout << "Kq = " << DPFib2(n);
	return 0;
}
