#include <iostream>
using namespace std;
int n, a[10], b[10];

void Khoitao()
{
	cout << "Nhap n: ";
	cin >>n;
	for(int i=1; i<=n; i++)
	{
		b[i]=1;			
	}

}
void Xuat()
{
	for(int i=1; i<=n; i++)
		cout << a[i] <<" ";
	cout << endl;
	
}
void Try(int i)
{
	for(int j=1;j<=n;j++)
	{
		if(b[j])
		{
			a[i]=j;
			b[j]=0;
			if(i<n)
				Try(i+1);
			else
				Xuat();
			b[j]=1;
		}
	}
}

int main()
{
	Khoitao();
	Try(1);
	
}
