// Slide 12 trang 9
#include <iostream>
#include <stdio.h>
#include <conio.h>
using namespace std;
int G[10][10];
int n,s,t;
int kt=0;
int daxet[10],truoc[10];
void Init()
{
	freopen("input.txt","r",stdin);
	int i,j;
	cin>>n;
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			cin>>G[i][j];			
		}
	}
	cout<<" \n So dinh: "<<n<<endl;
	cout<<" Ma tran ke la: "<<endl;
		for(i=1;i<=n;i++)
	{
		cout<<endl;
		for(j=1;j<=n;j++)
		{
			cout<<" "<<G[i][j];
		}
	}
}
void xuat()
{
	cout<<"Duong di tu "<<s<<" den "<<t<<" la: "; 
	int j = t;
	cout<<t<<"<="; 
	while(truoc[j]!=s)
	{ 
	  	cout<<truoc[j]<<"<="; 
	 	j=truoc[j]; 
 	} 
 	cout<<s; 
 	cout<<endl;
}
void DFS(int s)//vong quay lui
{
	int u;
	daxet[s]=1;//da duyet diem dau
	for(u=1;u<=n;u++)
	{
		if(G[s][u]==1&&daxet[u]==0)//xet diem chua duyet ke voi dinh dang xet
		{
			truoc[u]=s;//gan dinh truoc diem u trong duong di la s
			if(u==t) // neu xet den dinh t la diem cuoi
			{
				kt=1; //bien kiem tra dung
				xuat(); //in ra ket qua
			}
			else DFS(u);// neu chua den diem cuoi thi tiep tuc xet
			daxet[u]=0;// khi xet xong 1 ket qua khoi tao lai cac dinh la chua xet
		}
	}
}
int main()
{
	s=2;
	t=5;
	for (int u=1; u<=n;u++) daxet[u]=0;
	Init();
	cout<<endl;
	DFS(s);	
	if(kt==0)
	{ 
 	 	cout<<"Khong co duong di tu "<<s<< " den "<<t; 
 	} 
}
// do phuc tap: O(n^n)
