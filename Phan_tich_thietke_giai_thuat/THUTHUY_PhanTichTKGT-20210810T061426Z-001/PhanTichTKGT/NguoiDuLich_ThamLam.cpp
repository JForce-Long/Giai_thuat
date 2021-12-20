#include <iostream>
#include <limits.h>
using namespace std;
int GTS(int a[][5], int n, int Ddau, int TOUR[])
{
	int v, k, w;
	int min;
	int COST;
	int daXet[100];
	for(k = 1; k<=n; k++)
	{
		daXet[k] = 0;
	}
	COST = 0;
	int i;
	v = Ddau;
	i = 1;
	TOUR[i] = v;
	daXet[v] = 1;
	
	while(i<n)
	{
		min = INT_MAX;
		for(k=1; k<=n; k++)
		{
			if(!daXet[k])
				if(min>a[v][k])
				{
					min = a[v][k];
					w=k;
				}
		}
		v=w;
		i++;
		TOUR[i]=v;
		daXet[v] = 1;
		COST +=min;
	}
	COST += a[v][Ddau];
	return COST;
}
void InMaTran(int a[][5], int n)
{
	for(int i = 1; i<=n;i++)
	{
		for(int j = 1; j<=n; j++)
		{
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
}
int main()
{
	int a [][5]= {0,3,5,2,6,
				  3,0,6,7,3,
				  5,6,0,5,4,
				  2,7,5,0,1,
				  6,3,4,1,0};
	int b [][5]= {0,1,6,3,2,
				  1,0,5,7,1,
				  6,5,0,6,3,
				  3,7,6,0,2,
				  2,1,3,2,0};
	int TOUR[100];
	
/*	cout << "Nhap so thanh pho n = ";
	cin >> n;
	cout << endl;
	
	for(int i = 1; i<=n;i++)
		for(int j = 1; j<=n; j++)
		{
			cout << "a["<<i<<"]["<<j<<"] = " ;
			cin >> a[i][j];
		}*/
		
	int kq = GTS(b, 5, 1, TOUR);
	cout << "Ket qua: ";
	for(int i = 1; i<=5; i++)
		cout << TOUR[i] << "-> ";
	cout << 1;
	cout << "\nChi phi la: " << kq;
	
	return 0;
}
