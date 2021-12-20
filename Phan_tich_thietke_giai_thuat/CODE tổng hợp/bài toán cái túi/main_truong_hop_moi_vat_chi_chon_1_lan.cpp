#include <stdio.h>
#include <conio.h>
#include <iostream>

using namespace std;
void xuat(int K[50][100], int n, int T)
//T la gia tri bat ki cua vat
{
	cout<< endl;
	for(int i = 0; i<= n; i++)
	{
		for(int j = 0; j<= T; j++)
		{
			cout<< K[i][j]<<"  ";
		}
		cout<< endl;
	}
}
void taoBang(int K[50][100],int weight[], int worth[], int n, int W)
{
	for(int i = 0; i<= n; i++)
	{
		for(int j = 0; j<= W; j++)
		{
			if(i == 0 || j == 0)
			{
				K[i][j] = 0;
				continue;
			
			}
			if(j< weight[i])
			{
				K[i][j] = K[i-1][j];
				continue;
			}
			int x = j-weight[i];
			if(K[i-1][j] > worth[i]+K[i-1][x])
				K[i][j] = K[i-1][j];
			else 
				K[i][j] = worth[i]+K[i-1][x];
		}
	}
}
void truyVet(int K[50][100],int weight[], int worth[], int n, int W)
{
	cout<< "Cac vat nen chon la: ";
	int j = W;
	for(int i = n; i>0; i--)
	{
			if(K[i][j] != K[i-1][j])
			{
				cout<< i<<"\t";
				j -= weight[i];
			}
			if(K[i][j] == 0)
				return;
	}
}
int main()
{
	int W; cout<< "Nhap tong khoi luong: "; cin >> W;
	int n; cout << "Nhap so do vat: "; cin>> n;
	int weight[100], worth[100];
	for(int i = 1; i<= n; i++)
	{
		cout<< "Nhap weight[" << i <<"]:"; cin >> weight[i];
		cout<< "Nhap worth[" << i <<"]:"; cin >> worth[i];
	}
	int K[50][100];//là bang k

	taoBang(K,weight,worth,n,W);
	xuat(K,n,W);
	truyVet(K,weight,worth,n,W);

	getch();
	return 0;
}
