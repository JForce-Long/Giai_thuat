#include <iostream>
using namespace std;

int LuyThua(int x, int n)
{
	if(n==1)
		return x;
	else
		return LuyThua(x,n-1)*x;
}

int UCLN1(int a, int b)
{
	if (b==0)
		return a;
	else 
		return UCLN1(b, a%b);
}
int UCLN2(int a, int b)
{
	if(a==b)
		return a;
	else 
	{
		if(a>b) return UCLN2(a-b, b);
		else 
			return UCLN2(b-a,a);
	}
}

int giaiThua(int n)
{
	if (n == 0)
		return 1;
	else 
		return n*giaiThua(n-1);
}

int Sum(int a[], int n)
{
	if (n==1)
		return a[0];
	else
		return Sum(a,n-1) + a[n-1];
		
}
int Tich(int a[], int n)
{
	if(n==1)
		return a[0];
	else 
		return Tich(a,n-1)*a[n-1];
}
int solangoi;
int Max(int a[], int n)
{
	solangoi+=1;
    if (n == 1)
        return a[0];
  
    if (Max(a, n-1) > a[n-1])
        return Max(a, n-1);
    else
        return a[n-1];
}

int Min(int a[], int n)
{
    if (n == 1)
        return a[0];
  
    if (Min(a, n-1) < a[n-1])
        return Min(a, n-1);
    else
        return a[n-1];
}
int main ()
{
	//cout << LuyThua(2,5);
	//cout << giaiThua(3);
	
	/*int a, b;
	cout << "Nhap a: "; cin >> a;
	cout << "Nhap b: "; cin >> b;
	cout << "UCLN cua a va b: " << UCLN1(a,b);*/
	
	int a[100], n;
	cout << "Nhap so ptu cua mang n = " ; cin >> n;
	cout << "Nhap mang: ";
	for(int i=0; i<n; i++)
	{
		cin >> a[i];
	}
	//cout << "Tong = "<<Sum(a,n);
	//cout << "Tich = "<<Tich(a,n);
	cout << "Gia tri Max = " << Max(a,n);
	cout << "\nGia tri Min = " << Min(a,n);
	cout << "So lan goi: " << solangoi;
	return 0;
}
