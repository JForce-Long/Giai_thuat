#include <iostream>
using namespace std;

int d[10][10], p[10][10];

void Floyd(int a[10][10], int n)
{
	int i,j,k;
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
		{
			d[i][j] = a[i][j];
			p[i][j] = 0;
		}
	for(k=1; k<=n; k++)
		for(i=1; i<=n;i++)
			if(d[i][k]>0 && d[i][k]<999)
				for(j=1;j<=n;j++)
					if(d[k][j]>0 && d[k][j]<999)
						if(d[i][k]+d[k][j]<d[i][j])
						{
							d[i][j] = d[i][k] + d[k][j];
							p[i][j] = k;
						}
}

int main()
{
	int n, a[10][10];
	cout << "Nhap n = "; cin >>n;
	for(int i=1;i<=n;i++)
	{	
		for(int j=1;j<=n;j++)
		{
			cout << "a[" << i <<"]["<<j<<"] = ";
			cin >> a[i][j];
		}
	}
	Floyd(a,n);
	cout << "d: \n";
	for(int i=1;i<=n;i++)
	{	
		for(int j=1;j<=n;j++)
		{
			cout << d[i][j] <<" ";
		}
		cout << endl;
	}
		
	cout << "\np: \n";
	for(int i=1;i<=n;i++)
	{	
		for(int j=1;j<=n;j++)
		{
			cout << p[i][j] <<" ";
		}
		cout << endl;
	}
	return 0;
}
