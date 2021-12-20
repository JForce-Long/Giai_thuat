#include<iostream>
#include<stdio.h>
using namespace std;
int const maxx = 100;
int n,b;
int w[maxx],v[maxx];
int x[maxx] = {0};
int kq[maxx]={0};
int W,V;

void Init()
{
    freopen("input.txt","r",stdin);
    cin>>n>>b;
    for(int i=1;i<=n;i++) cin>>w[i]>>v[i];
    V = -1;
}

void check()//ham check
{
    int sumw = 0;
    int sumv = 0;
    for(int i=1;i<=n;i++)
	{
        sumw += x[i]*w[i];//tong khoi luong cua truong hop dang xet
        sumv += x[i]*v[i];//tong gia tri cua truong hop dang xet
    }
    if(sumw <= b)//neu thoa man xep vua vao tui
	{
        if(sumv > V)//thoa man gia tri lon hon gia tri lon nhat truoc do
		{
            V = sumv;//cap nhat gia tri lon nhat
            W = sumw;//cap nhat khoi luong lon nhat
            for(int i=1;i<=n;i++) kq[i] = x[i];//luu lai cac do vat duoc chon
        }
    }
}

void back(int i)
{
    for(int j=0;j<=1;j++)//Ham sinh ra day nhi phan de thu lan luot tat ca cac truong hop
	{
        x[i] = j;// voi gia tri x[i]=1 la vat i duoc chon, x[i]=0 la vat i khong duoc chon
        if(i == n) check();//khi tao xong 1 truong hop thi check
        else back(i+1);
    }
}

void Result()//in ra ket qua bai toan
{
    cout<<"Max W = "<<W<<" , Max V = "<<V<<endl;
    cout<<"Cac Do vat duoc chon la: ";
    for(int i=1;i<=n;i++)
	{
        if(kq[i] == 1) cout<<i<<" ";
    }
}

main()
{
    Init();
    back(1);
    Result();
}
// Do phuc tap: O(n)
