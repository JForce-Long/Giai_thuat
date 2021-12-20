//Slide 7 trang 18
#include <iostream>
#include <stdio.h>
using namespace std;
int a[100][100];
int n;
int danhdau[100] = {0}, m[100] = {0}, sm=1;
void nhap()
{
    cin>>n;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            cin>>a[i][j];
}
void tomau()
{
    m[1] = 1;//mau dinh 1 la mau 1---m[v]=x : mau cua dinh v la x
    for(int u = 2; u <= n; u++)//xet tu dinh so 2
	{
        for(int i=1;i<=n;i++) danhdau[i] = 0;
        for(int v = 1; v <= n; v++)
		{
            if(a[u][v] != 0 && m[v] != 0) danhdau[m[v]] = 1;//neu dinh nao ke voi dinh dang xet va da duoc to mau thi danh dau mau do da duoc to
        }
        int x = 0;
        for(int i = 1; i <= sm; i++)//xet cac mau da to
		{
            if(danhdau[i] == 0) //tim mau nho nhat trong cac mau da to chua to cho cac dinh ke voi dinh dang xet
			{ x = i;break; }//neu tim thay thi to mau cho dinh do
        }
        if(x == 0)//neu khong tim thay thi tang so mau len va to cho dinh dang xet
		{
            sm++;
            x = sm;
        }
        m[u] = x;//to mau cho dinh dang xet
    }
}
void xuat()//Xuat ra ket qua
{
    cout<<"So mau can dung la: "<<sm<<endl;
    for(int i = 1; i <= sm; i++)
	{
        cout<<" mau "<<i<< " co dinh la: ";
        for(int j = 1; j <= n; j++)
		{
            if(m[j] == i) cout<<j<<" ";//in ra cac dinh to mau i
        }
        cout<<endl;
    }
}
int main()
{
    freopen("input.txt", "r", stdin);
    nhap();
    tomau();
    xuat();
}
//Do phuc tap: O(n^2)
