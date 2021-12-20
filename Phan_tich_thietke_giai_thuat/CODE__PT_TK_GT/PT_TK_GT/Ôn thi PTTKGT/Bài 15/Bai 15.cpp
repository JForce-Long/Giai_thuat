// Slide 11 trang 8
#include<conio.h>
#include<stdio.h>
#include<iostream>
using namespace std;
int x[9],a[9];
int b[16],c[16];
int init()
{
	for(int i=1;i<=8;i++)// khoi tao cac hang rong va cac cot trong
	{
		x[i]=0;
		a[i]=1;
	}
	for(int i=1;i<=15;i++)//khoi tao 2 duong cheo
	{
		b[i]=1; // duong cheo nguoc
		c[i]=1; // duong cheo thuan
	}
	return 0;
}
int printkq() // in ket qua
{
	for(int i=1;i<=7;i++) cout<<x[i]<<"-";
	cout<<x[8];
	cout<<endl;
	return 0;
}
int thu(int i)// vong quay lui
{
	for(int j=1;j<=8;j++)
	{
		if(a[j]&&b[i+j-1]&&c[i-j+8])
		{
			x[i]=j;
			a[j]=0;
			b[i+j-1]=0;
			c[i-j+8]=0;
			if(i<8)
				thu(i+1);// neu chua xep duoc quan hau thu 8 thi tiep tuc vong lap
			else
			{
				printkq();// in ra ket qua khi xep du 8 quan hau
			}
			a[j]=1; // khoi tao lai gia tri cho cac cot va duong cheo
			b[i+j-1]=1;
			c[i-j+8]=1;
		}
	}	
}
int main()
{
	init();
	thu(1);
	return 0;
}
// Do phuc tap O(8!)
