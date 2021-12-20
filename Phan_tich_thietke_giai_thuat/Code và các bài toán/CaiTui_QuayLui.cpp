#include <iostream>
using namespace std;
#define n 6
#define b 20
int x[n], luu[n], gt=0;

struct DoVat
{
	int c;
	int w;
};

DoVat dv[n];

int KhoiLuong()
{
	int kl =0;
	for (int i=0; i<n; i++)
		if(x[i]!=0)
			kl+=dv[i].w;
	return kl;
}

int GiaTri()
{
	int gt = 0;
	for(int i=0; i<n; i++)
		if(x[i]!=0)
			gt+=dv[i].c;
	return gt;
}

void luukq()
{
	for(int i=0; i<n; i++)
		luu[i] = x[i];
}

void Xuat()
{
	for(int i=0; i<n; i++)
		if(luu[i]==1)
			cout <<"Chon vat thu " << i << "\t"<<dv[i].c
					<<"\t"<<dv[i].w<<"\n";
}

void CaiTui(int i)
{
	int j;
	for(j=0; j<=n; j++)
	{
		x[i]=j;
		if(i<n-1)
			CaiTui(i+1);
		else
			if((GiaTri()>gt)&&(KhoiLuong()<=b))
			{
				gt=GiaTri();
				luukq();
			}
	}
}

int main()
{
	int L, i;
	cout << "Nhap gt va trong luong cac do vat: \n";
	for(i=0; i<n; i++)
		cin >> dv[i].c >> dv[i].w;
	CaiTui(0);
	cout << "Gia tri toi uu: " << gt << endl;
	Xuat();
	
	return 0;
}

