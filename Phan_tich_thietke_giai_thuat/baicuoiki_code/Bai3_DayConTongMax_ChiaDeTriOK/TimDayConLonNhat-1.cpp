/*
Mo ta thuat toan:
MaxLeftVector se xet tu phan tu ben phai
MaxRightVector se xet tu phan tu ben trai
MaxSubVector se duoc lua chon tu Tong ben trai lon nhat, Tong ben phai lon nhat va tong cua MaxLeftVector + MaxRightVector
*/
#include<iostream>
#include<fstream>
#include<conio.h>
using namespace std;
#define max 100
int a[max];
int n;
int t1, t2;
void Nhap(char input[])
{
	fstream in;
	in.open(input);
	in >> n;
	for (int i = 0; i<n; i++)
	{
		in >> a[i];
	}
}
// Lay gia tri lon hon
int Max(int a, int b)
{
	if (a > b)
		return a;
	else
		return b;
}
int MaxLeftVector(int i, int j,int &dau) //tinh tong nua trai
{
	int MaxSum = INT_MIN;
	int Sum = 0;
	for (int k = j; k >= i; k--)
	{
		Sum += a[k];
		if (MaxSum < Sum) { MaxSum = Sum; dau = k; }
	}
	return MaxSum;
}
int  MaxRightVector(int i, int j,int &cuoi) //tinh tong nua phai
{
	int MaxSum = -INT_MAX;
	int Sum = 0;
	for (int k = i; k <= j; k++)
	{
		Sum += a[k]; // Tinh tong k phan tu tu i den j	
		if (MaxSum < Sum) { MaxSum = Sum; cuoi= k; }
	}
	return MaxSum;
}
int MaxSubVector(int i, int j,int &dau,int &cuoi)//tong lon nhat
{
	int dau1, dau2,dau3,cuoi3, cuoi1, cuoi2;
	if (i == j) { // Khi chi con 1 phan tu thi tra ve phan tu do (tong cua 1 phan tu la chinh no)
		dau = i; cuoi = i; return a[i];
	}
	else
	{
		int m = (i + j) / 2;
		int wl, wr, wm;
		wl = MaxSubVector(i, m, dau1, cuoi1); // Tong lon nhat ben trai
		wr = MaxSubVector(m + 1, j, dau2, cuoi2); // Tong lon nhat ben phai
		wm = MaxLeftVector(i, m,dau3) + MaxRightVector(m + 1, j,cuoi3); // Tong lon nhat cua 2 day tren
		// Tim tong lon nhat
		int maxTam = Max(Max(wl, wr), wm); // Lay gia tri tong lon nhat 
		// Luu vet chuoi lon nhat
		if (maxTam == wl){ dau = dau1; cuoi = cuoi1; }
		else if (maxTam == wr){ dau = dau2; cuoi = cuoi2; }
		else if (maxTam == wm){ dau = dau3; cuoi = cuoi3; }
		return maxTam;
	}
}
int main()
{
	int dau, cuoi;
	Nhap("input.txt");
	MaxSubVector(0, n - 1,dau,cuoi);
	// Hien thi ket qua
	cout << "Day con lon nhat:";
	for (int i = dau; i <= cuoi; i++)
	{
		cout << " " << a[i]; 
	}
	return 0;
}
