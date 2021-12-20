#include <iostream>
#include <math.h>
#include <limits.h>
using namespace std;
int MaxSum =0;

int MaxLeftVector(int a[], int i, int j, int &l)
{
	MaxSum = a[j];
	int Sum = a[j];
	for (int k=j-1; k>=i; k--)
	{
		Sum += a[k];
		if(Sum>MaxSum) 
		{
			MaxSum=Sum;
			l = k;
		}
	}
	return MaxSum;
}

int MaxRightVector(int a[], int i, int j, int &r)
{
	MaxSum = a[i];
	int Sum = a[i];
	for (int k=i+1; k<=j; k++)
	{
		Sum = Sum + a[k];
		if(Sum>MaxSum) 
		{
			MaxSum=Sum;
			r = k;
		}
	}
	return MaxSum;
}

int MaxSubVector(int a[], int i, int j, int &l, int &r)
{
	int l1, r1, l2, r2, l3, r3;
	int WL, WR, WM, m;
	if(i==j)
	{	dau = i;
		cuoi = i;
		return a[i];
	}
	else
	{
		m = (i+j)/2;
		WL = MaxSubVector(a, i, m,l1, r1);
		WR = MaxSubVector(a, m+1, j, l2, r2);
		WM = MaxLeftVector(a, i, m, l3) + MaxRightVector(a, m+1, j, r3);
		int temp = max(WM,max(WL,WR));
		if (temp == WL)
		{
			l = l1;
			r = r1;
		}
		else if(temp == WR)
		{
			l = l2;
			r = r2;
		}
		else if(temp == WM)
		{
			l = l3;
			r  = r3;
		}
		return temp;
			
	}
}

int main()
{
	int l, r;
	int a[] = {1000,-54,-67,65,-879,78,65,21,-6,67};
	cout << MaxSubVector(a, 0, 9,dau, cuoi);
	cout << endl <<"Bat dau tu " << dau << " den " << cuoi;
	//cout << BruteForceNaice(a,10);

	return 0;
	
}
