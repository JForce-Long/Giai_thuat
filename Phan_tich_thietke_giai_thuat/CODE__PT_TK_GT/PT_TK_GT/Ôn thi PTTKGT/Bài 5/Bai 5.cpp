//Slide 6 trang 11
#include<iostream>
#include<stdio.h>
using namespace std;
int n,G[100][100] = {0},kq[100],danhdau[100]={0};
void init()
{
    freopen("input.txt","r",stdin);
    cin>>n;
    for(int i=1;i<=n;i++)
	{
        for(int j=1;j<=n;j++)
		{
            cin>>G[i][j];
        }
    }
}
int Duyet(int s)
{
    int minn,total = 0;
    int u = s,v,i = 1;//bat dau tu dinh s
    kq[i] = u;//thu tu dinh dau tien la s, mang kq[] luu lai qua trinh
    danhdau[u] = 1;//danh dau dinh s la da xet
    while(i<n)//Khi chua di het cac thanh pho thi tiep tuc
	{
        minn = 32000;
        for(int k=1;k<=n;k++)//Chon thanh pho gan nhat tu thanh pho hien thoi
		{
            if(danhdau[k] == 0 && G[u][k] != 0)//neu thanh pho do chua xet
			{
                if(minn > G[u][k])//tim ra minn-thanh pho gan nhat
				{
                    v = k;//danh dau lai thanh pho 
                    minn = G[u][k];
                }
            }
        }
        i++;//tang so thu tu
        u = v;//thanh pho xet tiep theo la thanh pho vua tim ra
        kq[i] = u;//thu tu dinh tiep theo la u
        danhdau[u] = 1;//dinh u da xet
        total += minn;//cap nhat quang duong
    }
    total = total + G[u][s];
    return total;
}
void In(int s)
{
    cout<<"Tong duong di la: "<<Duyet(s)<<endl;
    for(int i=1;i<=n;i++)
	{
        cout<<kq[i]<<" - > ";
    }
    cout<<s;
}
main()
{
    init();
    In(1);
}
// Do phuc tap: O(n^2)
