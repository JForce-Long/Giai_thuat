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
	for(int j=0; j<=1; j++)
	{
		x[i] = j;
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
