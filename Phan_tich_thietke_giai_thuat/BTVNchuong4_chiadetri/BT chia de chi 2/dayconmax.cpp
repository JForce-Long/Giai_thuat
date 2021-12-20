#include<iostream>
#include<math.h>
using namespace std;

int a[] = {2, -3, 9, -7, 6, 8, -5, 4};

int MaxLeftVector(int a[], int i, int j, int &dau)
{
    int MaxSum = a[j];
    int Sum = a[j];
    for(int k = j-1; k >= i; k--)
    {
        Sum += a[k];
        if(Sum > MaxSum) 
		{
			MaxSum = Sum;
			dau = k;
		}			
    }
    return MaxSum;
}

int MaxRightVector(int a[], int i, int j, int &cuoi)
{
    int MaxSum = a[i];
    int Sum = a[i];
    for(int k = i+1; k <= j; k++)
    {
        Sum += a[k];
        if(Sum > MaxSum)
		{
			MaxSum = Sum;
			cuoi = k;
		}
    }
    return MaxSum;
}

int MaxSubVector(int a[], int i, int j, int &dau, int &cuoi)
{
    int dau1, dau2, dau3, cuoi3, cuoi1, cuoi2;
    if(i==j)
	{
		dau = i;
		cuoi = i;
		return a[i];
	}
    else
    {
        int n=(i+j)/2;
		int WL, WR, WM; 
        WL = MaxSubVector(a, i, n, dau1, cuoi1);
        WR = MaxSubVector(a, n+1, j, dau2, cuoi2);
        WM = MaxLeftVector(a, i, n, dau3) + MaxRightVector(a, n+1, j, cuoi3);
        int GT_Max = max(WM, max(WL, WR));
		
		if (GT_Max == WL)
        {
            dau = dau1;
            cuoi = cuoi1;
        }
        else if (GT_Max == WR)
        {
            dau = dau2;
            cuoi = cuoi2;
        }
        else if (GT_Max == WM)
        {
            dau = dau3;
            cuoi = cuoi3;
        }
        return GT_Max;
    }
    
}

int main()
{
	int dau, cuoi;
    cout<<MaxSubVector(a, 0, 7, dau, cuoi)<<" = ";
	for (int i = dau; i <= cuoi; i++)
    {
        cout << a[i] << ' ';
    }

    return 0;
}