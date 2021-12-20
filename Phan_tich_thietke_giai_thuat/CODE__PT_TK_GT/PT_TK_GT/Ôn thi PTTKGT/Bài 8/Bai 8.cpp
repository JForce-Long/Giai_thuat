// Slide 7 trang 9
#include<stdio.h>
#include<conio.h>
#include<iostream>
#include<stdlib.h>
using namespace std;
#define MAX 100
int i,j,k,a,b,u,v,n,canh=1;
int mincost=0,G[MAX][MAX],goc[MAX];
int find(int i)//ham tim kiem diem goc cua i
{
 	while(goc[i])
 	{
		i=goc[i];
	}
 	return i;
}
int test(int i,int j)//ham test canh (u,v) khi duoc them vao cay khung co tao thanh chu trinh hay khong
{
 	if(i!=j)//neu i=!j thi khong tao thanh chu trinh
	{
  		goc[j]=i;
  		return 1;
	}
 return 0;
}
int main()
{
	freopen("input.txt","r",stdin);
	cin>>n;
 	for(i=1;i<=n;i++)
 	{
  		for(j=1;j<=n;j++)
  		{		
   			cin>>G[i][j];
   			if(G[i][j]==0)
    		G[i][j]=32000;
  		}
	}
	cout<<"Cay khung nho nhat tim duoc la: "<<endl;
 	while(canh<n)//khi chua tim duoc cay khung thi tiep tuc
 	{
 	int min = 32000;
	for(i=1;i<=n;i++)//Xet canh nho nhat trong cac canh de them vao cay khung
 	{		
  		for(j=1;j<=n;j++)
   		{
    		if(G[i][j]<min)
    		{
    			min=G[i][j];
    			a=u=i;
    			b=v=j;
    		}
 		}
 	}
	u=find(u);//tim diem goc cua u
	v=find(v);//tim diem goc cua v
	if(test(u,v))//neu canh u,v khong tao thanh chu trinh
	{
		cout<<"buoc "<<canh++<<" ("<<a<<","<<b<<") = "<<min<<endl;//in ra canh (u,v) va gia tri canh do
		mincost +=min;//cong gia tri canh (u,v) vao gia tri cay khung nho nhat
  	}
    G[a][b]=G[b][a]=32000;//xoa canh khoi do thi T
 	}
	cout<<"Cay khung nho nhat = "<<mincost;
	getch();
}
// Do phuc tap: O(n^3)
