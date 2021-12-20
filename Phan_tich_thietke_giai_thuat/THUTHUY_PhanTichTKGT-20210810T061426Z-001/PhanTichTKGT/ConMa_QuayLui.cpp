#include <iostream>
#include <conio.h>
using namespace std;

int a[] = {1,2,2,1,-1,-2,-2,-1};
int b[] = {2,1,-1,-2,-2,-1,1,2};
int h[20][20], n, sophuongan =0;

void KhoiTao()
{
	cout << "Nhap so hang(cot): ";
	cin >> n;
	
	int i, j;
	for(i=0; i<n;i++)
		for(j=0; j<n; j++)
			h[i][j]=0;
}

void Xuat()
{
	int i, j;
	for(i=0; i<n; i++)
	{
		for (j=0; j<n; j++)
			cout << h[i][j] << "\t";
		cout << endl;
	}
}

void Try(int i, int x, int y)
{
	int u, v;
	for(int k =0; k<8; k++)
	{
		u = x + a[k];
		v = y + b[k];
		if((u>=0)&&(v>=0) &&(u<n)&&(v<n)&&(h[u][v]==0))
		{
			h[u][v]=i;
			if(i<n*n)
				Try(i+1,u,v);
			else
			{
				cout << "Phuong an " << ++sophuongan<<endl;
				Xuat();
				getch();
			}
			h[u][v]=0;
		}
	}
}

int main()
{
	KhoiTao();
	h[0][0] = 1;
	Try(2,0,0);

	if (sophuongan==0)
		cout << "Khong ton tai cach di thoa man";
	else
		cout << "Co tat ca " << sophuongan << " cach di thoa man";
	return 0;
}
