#include <iostream>
using namespace std;

int n, x[10];
void Xuat()
{
	for(int i=0; i<n; i++)
		cout << x[i];
	cout << endl;
}

void Try(int i)
{
	for(int j=0; j<=2; j++) //0 truoc 1 sau
	{
		x[i] = j;
		x[i] != x[i+1];
		if(i<n)
			Try(i+1);
		else
			Xuat();
	}
}

int main()
{
	cout << "Nhap n: ";
	cin >> n;
	Try(0);
	return 0;
}
