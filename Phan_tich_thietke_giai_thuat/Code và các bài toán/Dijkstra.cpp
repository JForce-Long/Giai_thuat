#include <iostream>
#include <limits.h>
using namespace std;

void xuatdd(int s, int k, int Dd[])
{
	int i;
	cout << "\nDuong di ngan nhat tu " << s << " den " << k << " la: ";
	i = k;
	while(i!=s)
	{
		cout << i << "<--";
		i = Dd[i];
	}
	cout << s;
}
void Dijkstra(int a[][6], int n, int s)
{
	int Ddnn[100];
	int i, k , Dht, Min;
	int Daxet[100], L[100];
	for (i=1; i<=n;i++)
	{
		Daxet[i]= 0;
		L[i]=INT_MAX;
	}
	Daxet[s]=1;
	L[s]=0;
	Dht = s;
	int h = 1;
	while(h<= n-1)
	{
		Min = INT_MAX;
		for(i=1;i<=n;i++)
			if(!Daxet[i])
			{
				if(L[Dht] + a[Dht][i] < L[i])
				{
					L[i] = L[Dht] + a[Dht][i];
					Ddnn[i] = Dht;
				}
				if(L[i]<Min)
				{
					Min = L[i];
					k = i;
				}
			}
		xuatdd(s,k,Ddnn);
		cout << "\nTrong so: " << L[k];
		Dht = k;
		Daxet[Dht] = 1;
		h++;
	}
}
void InMaTran(int a[][6], int n)
{
	for(int i = 0; i<n;i++)
	{
		for(int j = 0; j<n; j++)
		{
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
}
int main()
{
	int a[][6]= {0,20,15,0,80,0,
				 40,0,0,0,10,30,
				 20,4,0,0,0,10,
				 36,18,15,0,0,0,
				 0,0,90,15,0,0,
				 0,0,45,4,10,0};
	Dijkstra(a, 6, 1);
	return 0;
}
