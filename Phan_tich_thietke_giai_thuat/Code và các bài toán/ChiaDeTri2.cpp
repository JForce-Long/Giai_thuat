#include <iostream>
#include <math.h>
using namespace std;
int MaxSum =0;

int MaxLeftVector(int a[], int i, int j)
{
	MaxSum = a[j];
	int Sum = a[j];
	for (int k=j-1; k>=i; k--)
	{
		Sum += a[k];
		if(Sum>MaxSum) 
			MaxSum=Sum;
	}
	return MaxSum;
}

int MaxRightVector(int a[], int i, int j)
{
	MaxSum = a[i];
	int Sum = a[i];
	for (int k=i+1; k<=j; k++)
	{
		Sum = Sum + a[k];
		if(Sum>MaxSum) 
			MaxSum=Sum;
	}
	return MaxSum;
}

int MaxSubVector(int a[], int i, int j)
{
	int WL, WR, WM, m;
	if(i==j)
		return a[i];
	else
	{
		m = (i+j)/2;
		WL = MaxSubVector(a, i, m);
		WR = MaxSubVector(a, m+1, j);
		WM = MaxLeftVector(a, i, m) + MaxRightVector(a, m+1, j);
		return max(WM,max(WL,WR));
	}
}

int power(int a, int n)
{
	if(n==0)
		return 1;
	else if(n%2 ==0)
		return power(a*a, n/2);
	else
		return a*power(a*a, n/2);
}

void Swap(int &a, int &b)
{
	int temp = a;
	a = b;
	b = temp;
}
void Exchange(int a[], int i, int j, int m)
{
	for(int p = 0; p<= m-1; p++)
		Swap(a[i+p], a[j+p]);
}
void Transpose(int a[], int n, int m)
{
	int i = m;
	int j = n - m;
	//m = m+1;
	while (i!=j)
	{
		if(i>j)
		{
			Exchange(a, m-i, m, j);
			i = i-j;
		}
		else
		{
			j = j-i;
			Exchange(a, m-i, m+j, i);
		}
	}
	Exchange(a, m-i, m, i);
}
void InMang(int a[], int n)
{
	for (int i=0; i <n; i++)
	{	cout << a[i] << " ";}
	cout <<endl; 
}
int main()
{
	/*int a[] = {-98,54,67,65,-879,78,65,21,-6,67};
	cout << MaxSubVector(a, 0, 9);*/
	//cout << power(2,5);
	int a[] = {3,5,8,9,4,2,7,5,3,9,8};
	int m;
	cout << "Nhap so phan tu hoan doi: ";
	cin >> m;
	Transpose(a,11,m);
	//cout << "Ket qua: ";
	//InMang(a,11);
	return 0;
	
}
