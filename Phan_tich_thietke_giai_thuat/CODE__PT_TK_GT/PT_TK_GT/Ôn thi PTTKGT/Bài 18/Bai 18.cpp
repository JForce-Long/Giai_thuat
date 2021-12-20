#include<iostream>
#include<stdio.h>
using namespace std;
int n,a[100][100];
int danhdau[100] = {0};
int kq[100],x[100];
int minn;

void Init()
{
    freopen("input.txt","r",stdin);
    cin>>n;
    for(int i=1;i<=n;i++)
	{
        for(int j=1;j<=n;j++)
		{
            cin>>a[i][j];
            if(a[i][j] == 0) a[i][j] = 32000;
        }
    }
    danhdau[1] = 1;
    x[1] = 1;
    minn = 32000;
}

void check()//ham check ket qua toi uu nhat
{
    int s = 0;
    for(int i=1;i<= n-1;i++)
	{
        s += a[x[i]][x[i+1]];//tinh do dai duong di qua tung thanh pho
    }
    s += a[x[n]][1];//quay lai thanh pho 1
    if(s<minn)//neu duong di toi uu hon
	{
        minn = s;//gan minn bang ket qua do dai duong di
        for(int i=1;i<=n;i++) kq[i] = x[i];//luu lai duong di vao mang kq[]
    }
}

void Back(int i)
{
    for(int j=2;j<=n;j++)//vong lap for xet het cac thanh pho
	{
        if(danhdau[j] == 0)//neu thanh pho chua xet
		{
            x[i] = j;//xet thanh pho do, them vao duong di
            danhdau[j] = 1;//danh dau la da xet
            if(i == n) check();//khi tim ra 1 duong di thi check xem duong di co toi uu khong
            else Back(i+1);//khi chua tim duoc duong di thi tiep tuc xet thanh pho i+1
            danhdau[j] = 0;//khoi tao lai thanh pho la chua xet
        }
    }
}

void Result()
{
    cout<<"Tong chi phi la: "<<minn<<endl;
    cout<<1;
    for(int i=2;i<=n;i++) cout<<" -> "<<kq[i];
}

main()
{
    Init();
    Back(2);
    Result();
}
// Do phuc tap: O(n^n)
