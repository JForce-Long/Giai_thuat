
#include<conio.h>
#include<io.h>
#include<iostream>
using namespace std;
int G[100][100];
int n;
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
	cout<<" Ma tran trong so la: "<<endl;
	for(i=1;i<=n;i++)
	{
		cout<<endl;
		for(j=1;j<=n;j++)//xet xem giua 2 dinh ke nhau co duong di hay k
		{
			cout<<" "<<G[i][j];
			if(G[i][j]==0&&i!=j) G[i][j]=32000;//neu khong co thi dat gia tri la vo cung
		}
	}
}

int main()
{
	Init();
	int d[n][n],p[n][n];
	int i,j,k;
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
		{
			d[i][j]=G[i][j];
			p[i][j]=0;
		}
	for(k=1;k<=n;k++)//Xet voi tung dinh xem no co la trung gian cho cap dinh i,j nao khong
		for(i=1;i<=n;i++)
			if(d[i][k]>0&&d[i][k]<32000)//Xet xem co ton tai duong di nao tu i den k hay khong
				for(j=1;j<=n;j++)
					if(d[k][j]>0&&d[k][j]<32000)//xet xem co duong di tu k den j hay khong
						if(d[i][k]+d[k][j]<d[i][j])
						{
							d[i][j]=d[i][k]+d[k][j];//neu khoang cach i,k + k,j nho hon i,j thi gan d(i,j) bang tong khoang cach
							p[i][j]=k; // duong di ngan nhat tu i den j co di qua dinh k, luu vao ma tran p
						}
    cout<<endl;
    cout<<"Ma tran d: ";
	for(i=1;i<=n;i++)
	{
		cout<<endl;
		for(j=1;j<=n;j++)
		{
			cout<<" "<<d[i][j];
		}
	}
	cout<<endl;
	cout<<"Ma tran p: ";
	for(i=1;i<=n;i++)
	{
		cout<<endl;
		for(j=1;j<=n;j++)
		{
			cout<<" "<<p[i][j];
		}
	}
	cout<<endl;
	cout<<"duong di ngan nhat tu 1 den 3 la: ";
	int s[100],dem;
	dem=0;
	i=1;j=3;
	s[dem]=j;
	while(p[i][j]!=0)//truy vet ket qua
	{
		k=p[i][j];
		dem++;
		s[dem]=k;
		j=k;
	}
	dem++;s[dem]=i;
	cout<<endl;
	for (i=dem;i>=0;i--) cout<<s[i]<<"->";	
}
// Do phuc tap: O(n^3)



