// Slide 11 trang 17
#include <iostream>
#include <stdio.h>
#include <conio.h>
using namespace std;
int a[8] = {-2,-2,-1,-1,1,1,2,2};
int b[8] = {-1,1,-2,2,-2,2,-1,1};// khoi tao mang 8 toa do 8 buoc co the di cua quan ma tu trai qua phai, tren xuong duoi
int kt=0,x,y,n,h[50][50];
void xuat() // ham in ket qua
{
	cout << endl << "Cach di thu " << ++kt << ":" << endl;
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=n;j++)
			printf("%d\t",h[i][j]);
		cout << endl;
	}
	getch();
}
void Try(int i,int x, int y)// ham quay lui
{
	int u,v;
	if (i>n*n) xuat(); // neu quan ma di het ban co thi in ket qua
	else
		for(int j=0;j<=7;j++)//neu khong thi tiep tuc chon buoc di tiep theo cho quan ma
		{
			u=x+a[j];// chuyen den toa do x,y tiep theo thoa man
			v=y+b[j];
			if(u>0&&u<=n&&v>0&&v<=n&&h[u][v]==0)// xet dieu kien de quan ma di duoc o tiep theo
			{
				h[u][v]=i;
				Try(i+1,u,v);// di den buoc thu i+1
				h[u][v]=0; // khoi tao lai o trong
			}
		}
}
int main()
{
	freopen("input.txt","r",stdin);
	cin >> n;
	cin >> x >> y;
	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++)
	   		h[i][j]=0;
	h[x][y]=1;
	Try(2,x,y);
	if (kt==0)
	cout << "Khong ton tai cach di thoa man";
	return 0;
 }
 // Do phuc tap O(8^n binh)
