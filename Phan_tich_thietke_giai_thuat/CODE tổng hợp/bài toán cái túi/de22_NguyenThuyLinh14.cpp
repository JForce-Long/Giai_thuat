#include <stdio.h>
#include <conio.h>
#include <iostream>
using namespace std;

void xuat(int Value[50][100], int n, int L)
{
	cout<< endl;
	for(int i = 0; i<= n; i++)
	{
		for(int j = 0; j<= L; j++)
		{
			cout<< Value[i][j]<<"     ";
		}
		cout<< endl;
	}
}
void createtable(int Value[50][100],int W[], int V[], int n, int S)
{// i la so do vat, j caan nang
	for(int i = 0; i<= n; i++)
	{
		for(int j = 0; j<= S; j++)
		{
			if(i == 0 || j == 0)
			{
				Value[i][j] = 0;
				continue;
			}
			if(j< W[i])//neu j nho hon can nang cua vat i
			{
				Value[i][j] = Value[i-1][j];//ta ha gia tri vat tren xuong
				continue;
			}
			int x = j - W[i];
			if(Value[i-1][j] > V[i] + Value[i-1][x])
				Value[i][j] = Value[i-1][j];
			else 
				Value[i][j] = V[i] + Value[i-1][x];
		}
	}
}
void truyVet(int Value[50][100],int W[], int V[], int n, int S)
{
	cout<< "Cac vat nen chon la: ";
	int j = S;
	for(int i = n; i>0; i--)
	{
			if(Value[i][j] != Value[i-1][j])
			{
				cout<< i<<"   \t";
				j -= W[i];// tru di so can cua vat thu i
			}
			if(Value[i][j] == 0)
				return;
	}
}
int main()
{
	int S,n;
	cout << "Nhap tong khoi luong: "; cin >> S;
	cout << "Nhap so do vat: "; cin>> n;
	cout << endl;
	int W[100], V[100];
	for(int i = 1; i<= n; i++)
	{
		cout<< "Nhap can nang [" << i <<"]:"; cin >> W[i];
		cout<< "Nhap gia tri [" << i <<"]:"; cin >> V[i];
	}
	int Value[50][100];// tao mang value de luu gia tri bang

	createtable(Value,W,V,n,S);
	xuat(Value,n,S);
	
	cout << endl;
	
	truyVet(Value,W,V,n,S);

	getch();
	return 0;
}
