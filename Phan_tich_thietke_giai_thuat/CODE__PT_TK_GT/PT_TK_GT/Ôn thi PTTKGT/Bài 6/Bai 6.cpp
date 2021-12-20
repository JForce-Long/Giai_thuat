// Slide 6 trang 18
#include<conio.h>
#include<io.h>
#include<iostream>
#define Max 100
#define TRUE 1
#define FALSE 0
using namespace std;
int n,s,z;
char chon;
int truoc[Max],d[Max],G[Max][Max];
int final[Max];
void Init()
{
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
		for(j=1;j<=n;j++)
		{
			cout<<" "<<G[i][j];
			if(G[i][j]==0&&i!=j)
			G[i][j]=32000;
		}
	}
	cout<<endl;
}
void Result()
{
	int i,j;
	cout<<"Duong di ngan nhat tu "<<s<<" den "<<z<<" la "<<endl;
	i=z;
while(i!=s)
{
	cout<<" "<<i<<"<=";
	i=truoc[i];
}
	cout<<" "<<s;
	cout<<endl;
	cout<<" Do dai duong di la "<< d[z];
}
void Dijkstra(){
	int v,u,minp;
	cin>>s>>z;//tim duong di ngan nhat tu dinh s den dinh z
	for(v=1;v<=n;v++)
	{
		d[v]=G[s][v];//tao nhan cho cac dinh la do dai duong di tu s den v
		truoc[v]=s;// mang truoc[] luu lai duong di
		final[v]=FALSE;
	}

	truoc[s]=0;
	d[s]=0;
	final[s]=TRUE;//dinh s da xet
	while(!final[z])//neu chua xet den dinh z thi tiep tuc
	{
		minp=32000;
		for(v=1;v<=n;v++)
		{
			if((!final[v])&&(minp>d[v]))//tim dinh co nhan nho nhat(khoang cach den s nho nhat) de them vao tap da xet
			{
				u=v;
				minp=d[v];
			}
		}
			final[u]=TRUE;//danh dau dinh co nhan nho nhat vua tim duoc la da xet
			if(!final[z])//neu chua xet den dinh z
			{
				for(v=1;v<=n;v++)
				{
					if((!final[v])&&(d[u]+G[u][v]<d[v]))//gan lai nhan cho cac dinh chua xet
					{
						d[v]=d[u]+G[u][v];
						// nhan dinh v se duoc gan lai neu khoang cach tu s den v lon hon khoang cach tu s den u + u den v
						truoc[v]=u;// danh dau lai duong di
					}
				}
			}
		}

}
int main()
{
    freopen("input.txt","r",stdin);
	Init();
	Dijkstra();
	Result();
	getch();

	return 0;

}
// Do phuc tap: O(n^2)
