#include<iostream>
#include<stdio.h>
using namespace std;
int n,a[100][100];
int danhdau[100] = {0};
int kq[100],x[100],T[100];
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
    x[1] = 1;
    minn = 32000;
    danhdau[1] = 1;
}

void check()
{
    if(T[n] + a[x[n]][1] < minn)//Neu tong do dai duong di toi uu hon
	{
        for(int k = 1;k<=n;k++) kq[k] = x[k];//luu lai duong di vao mang kq[]
        minn = T[n] + a[x[n]][1];//gan minn bang do dai duong di toi uu hon
    }
}

void Back(int i)
{
    for(int j=2;j<=n;j++)//Xet het cac thanh pho
	{
        if(danhdau[j] == 0)//Neu thanh pho chua xet
		{
            x[i] = j;//xet thanh pho do,them vao duong di
            T[i] = T[i-1] + a[x[i-1]][j];//cap nhat do dai duong di
            if(T[i] < minn)//neu xet den thanh pho nao do ma do dai duong di da lon hon min thi thoat nhanh
			{
                danhdau[j] = 1;//danh dau lai thanh pho la da xet
                if(i == n) check();//neu xet qua het tat ca cac thanh pho thi check xem duong di co toi uu khong
                else Back(i+1);//nguoc lai tiep tuc xet thanh pho i+1
                danhdau[j] = 0;//khoi tao lai thanh pho la chua xet
            }
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
