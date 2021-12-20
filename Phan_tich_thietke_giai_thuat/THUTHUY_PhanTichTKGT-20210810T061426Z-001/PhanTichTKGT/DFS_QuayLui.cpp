#include <iostream>
#include <fstream>
#define n 6
using namespace std;

int daxet[n], Truoc[10], s, t;
int a[n][n]={0,1,1,0,1,0,
			0,0,0,0,0,1,
			0,1,0,0,1,0,
			1,0,1,0,1,0,
			0,0,0,0,0,1,
			1,1,0,1,0,0}; 

void KhoiTao()
{
	for(int i=1; i<=n; i++)
	{
		daxet[i]=0;
		Truoc[i]=0;
		
	}
}

void Xuat()
{
	cout << t << "<--";
	int j=t;
	while(Truoc[j]!=s);
	{
		cout << Truoc[j]<<"<--";
		j=Truoc[j];
	}
	cout << s << endl;
}

void DFS(int s)
{
	int u;
	daxet[s]=1;
	for(u=1; u<=n; u++)
	{
		if(a[s][u]&& !daxet[u])
		{
			Truoc[u] = s;
			if(u==t)
				Xuat();
			else 
				DFS(u);
			daxet[u]=0;
		}
	}
}

int main()
{
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<n; j++)
		{
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
	cout << "Dinh bat dau: "; cin >> s;
	cout <<"Dinh ket thuc: "; cin >> t;
	DFS(s);
	return 0;
}

