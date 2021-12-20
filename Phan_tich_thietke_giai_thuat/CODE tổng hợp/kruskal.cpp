#include<stdio.h>
#include<conio.h>
#include<iostream>
using namespace std;
#define max 50;
#define true 1;
#define false 0;

int n, m, min1, connect;
int head[500], feat[500],w[500];//mang chua dau cuoi va do dai cac canh cua do thi
int head1[50], feat1[50], father[50];

void Init(void)
{
 freopen("kruskal.txt", "r",stdin);
 cin>>n>>m;
 cout<<"So dinh do thi: "<< n <<endl;
 cout<<"So canh do thi:" << m <<endl;
 //nh?p danh sách k?
 for (int i = 1; i <= m; i++){
  cin>>head[i]>>feat[i]>>w[i];
 }
}

void heap(int first, int last)
{
	int j, k, t1, t2, t3;
	j=first;
	while(j<=(last/2))
	{
		if (( 2 * j < last) && (w[2 * j +1] < w[2 * j]))
		{
			k = 2*j +1;
		}
		else k = 2*j;
		if (w[k] < w[j])
		{
			t1 = head[j];
			t2 = feat[j];
			t3 = w[j];
			head[j] = head[k];
			feat[j] = feat[k];
			w[j] = w[k];
			head[k] = t1;
			feat[k] = t2;
			w[k] = t3;
			j = k;
			
		}
		else (j = last);
	}
}

int find(int i)
{
	int tro = i;
	while (father[tro] > 0) tro = father[tro];
	return (tro);
}

void Union(int i, int j)
{
 int x = father[i] + father[j];
 if (father[i] > father[j]) {
  father[i] = j;
  father[j] = x;
 }
 else {
  father[j] = i;
  father[i] = x;
 }
}


void kruskal(void)
{
	int last, u, v, r1, r2, ncanh, ndinh;
	for(int i =0; i<= n; i++)
	{
		father[i]=-1;
	}
	//su dung thuat toan vun dong de sap xep cac canh theo thu tu khong giam ve do dai
	for(int i = m/2; i>0;i--)
	{
		heap(i,m);
		last = m, ncanh = 0, ndinh = 0, min1 = 0, connect = true;
	}
	//lua chon canh bo sung vao cay khung
	while (ndinh < (n-1) && ncanh < m)
	{
		ncanh = ncanh+1;
		u = head[1];
		v = feat[1];
		//tim goc cua phan hoach 1 va 2
		r1 = find(u);
		r2 = find(v);
	if (r1 != r2) //neu hai goc khác nhau thì canh dang xét có the thêm duoc vào do thi.
    {
        ndinh = ndinh + 1;
        Union(r1, r2);
        head1[ndinh] = u;
        feat1[ndinh] = v;
        min1 = min1 + w[1];
    }
    head[1] = head[last];
    feat[1] = feat[last];
    w[1] = w[last];
    last = last - 1;
    Heap(1, last);	
	}
	if (ndinh != n - 1) connect = FALSE;
}

void Result(void)
{
    cout<<"Do dai cay khung nho nhat:"<< min1<<endl;
    cout<<"Cac canh cua cay khung nho nhat:"<<endl;
    for (int i = 1; i < n; i++)
    cout<< head1[i]<<" "<<feat1[i]<<endl;
}

void main(void){
 Init();
 Krusal();
 Result();
 getch();
}
