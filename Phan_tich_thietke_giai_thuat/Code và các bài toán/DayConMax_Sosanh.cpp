#include <iostream>
#include <math.h>
#include <limits.h>
#include <cstdlib>
#include <time.h>
#include <iomanip>
using namespace std;
int MaxSum =0;
int A[10000], N;

void Random(int a[], int n){
	for(int i=0; i<n; i++){
		a[i]=rand();
	}
}

int BruteForceNaice(int a[], int n)
{
	MaxSum = -INT_MAX;
	int s;
	for (int i =0; i<n; i++)
	{
		for(int j = i; j<n; j++)
		{
			s = 0;
			for (int k = i; k<=j; k++)
			{
				s = s+ a[k];
			}
			if (s>MaxSum)
				MaxSum = s;
		}
	}
	return MaxSum;
	
}
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
int main()
{
	cout << "Nhap so phan tu cua day: " ;
    cin >> N;

    cout << "Nhap day: " << endl;
    Random(A, N);
        for (int i=0; i<N; i++){
        cout << A[i] << " ";
    }
    
	cout << endl;
	clock_t start = clock();
	cout << "Ket qua 1: "<< BruteForceNaice(A,N);
	clock_t finish = clock();
    cout <<endl<< "Thoi gian thuc hien thuat toan 1 la: " << setprecision(7) << fixed << (double) (finish-start)/(CLOCKS_PER_SEC);

	cout << endl;
	clock_t start2 = clock();
	cout << "Ket qua 2: "<< MaxSubVector(A, 0, N);
	clock_t finish2 = clock();
    cout <<endl<< "Thoi gian thuc hien thuat toan 2 la: " << setprecision(7) << fixed << (double) (finish-start)/(CLOCKS_PER_SEC);
    
	return 0;
	
}
