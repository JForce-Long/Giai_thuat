#include <iostream>
using namespace std;

struct Canh
{
	int d, c, w;
};
	double Lowcost[100];
	int Closest[100];
void Swap (Canh &a, Canh &b)
{
	Canh temp = a;
	a = b; 
	b = temp;
}

void SapXep(Canh a[], int m)
{
	int i, j;
	for (i = 0; i<m-1; i++)
		for(j = i+1; j< m; j++)
		{
			if(a[i].w > a[j].w)
				Swap(a[i], a[j]);
		}
	
}

void Nhap(Canh a[], int m)
{
	for (int i=0; i<m; i++)
	{
		cout << "Nhap dinh dau, dinh cuoi va trong so cua canh thu " << i+1 << ": ";
		cin >> a[i].d >> a[i].c >> a[i].w;
	}
}

void Prim(Canh a[], int m, int n)
{
	int i, j, k, Min;
	for(i = 1; i<n; i++)
	{
		Lowcost[i] = a[i].w;
		Closest[i] = 1;
	}
	for(i = 1; i<n;i++)
	{
		Min = Lo
	}
}

void inCayKhung(Canh a[], int n)
{
	for(int i=0; i<n-1; i++)
		cout << a[i].d << " " << a[i].c << " " << a[i].w << endl;
}

int main()
{
	return 0;
}
