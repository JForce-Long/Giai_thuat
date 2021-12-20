#include <iostream>
using namespace std;

struct DoVat{
	int w, c;
	bool Chon;
};
void Swap(DoVat &a, DoVat &b)
{
	DoVat temp = a;
	a = b;
	b = a;
}

void SapXep1(DoVat dv[], int &n)
{
	for(int i = 0; i<n-1; i++)
		for(int j = i+1; j<n; j++)
			if(dv[i].c < dv[j].c)
				Swap(dv[i], dv[j]);
}
void SapXep2(DoVat dv[], int &n)
{
	for(int i = 0; i<n-1; i++)
		for(int j = i+1; j<n; j++)
			if(dv[i].w > dv[j].w)
				Swap(dv[i], dv[j]);
}

void SapXep3(DoVat dv[], int &n)
{
	for(int i = 0; i<n-1; i++)
		for(int j = i+1; j<n; j++)
			if((float)(dv[i].c/dv[i].w) < (float)(dv[j].c/dv[j].w) )
				Swap(dv[i], dv[j]);
}

void Greedy(DoVat dv[], int n, int b, int &TongGiaTri)
{
	SapXep3(dv,n);
	int TongTrongLuong = 0;
	for(int i = 0; i<n; i++)
	{
		if ((TongTrongLuong+dv[i].w) < b)
		{
			TongTrongLuong += dv[i].w;
			TongGiaTri += dv[i].c;
			dv[i].Chon = true;
		}
		else dv[i].Chon = false;
	}
}

int main()
{
	DoVat item[10];
	int n, b, TongGiaTri=0;
	cout << "Nhap so do vat: ";
	cin >> n;
	for (int i=0; i<n; i++)
	{
		cout << "Do vat " << i+1 << ": \n";
		cout << "Gia tri: "; cin >> item[i].c;
		cout << "Trong luong: "; cin >> item[i].w;
	}
	cout << "Trong luong cai tui: ";
	cin >> b;
	
	Greedy(item, n, b, TongGiaTri);
	cout << "Ket qua: \n";
	for (int i=0; i<n; i++)
	{
		cout << "Do vat " << i+1 << ": " << item[i].Chon << endl;
	}
	cout << "Tong gia tri: " << TongGiaTri;
	return 0;
}
