//Slide 6 trang 6
#include<stdio.h>
#include<iostream>
#include<algorithm>
using namespace std;
int n,b,chosse[100];
struct tui
{
	int w;
	int v;
};tui a[100];
bool kt(tui a,tui b)//ham dieu kien sap xep
{
	return (a.v/a.w > b.v/b.w);
}
int main()
{
    freopen("input.txt","r",stdin);
	cin>>n>>b;
	for(int i=1;i<=n;i++) cin>>a[i].w>>a[i].v;
	sort(a+1,a+1+n,kt);//sap xep do vat theo thu tu gia tri/khoi luong giam dan
	for(int i=1;i<=n;i++) cout<<a[i].w<<" "<<a[i].v<<endl;
	int m=0,c=0;
	int vt=0;
	for(int i=1;i<=n;i++)
	{
		if(m+a[i].w<=b) //chon do vat tu cao xuong thap sao cho tong khoi luong nho hon tui
		{
			m=m+a[i].w;//cong  khoi luong
			c=c+a[i].v;//cong gia tri
			vt++;
			chosse[vt] = i;//luu lai do vat duoc chon
		}
	}
	cout<<"khoi luong va gia tri lon nhat co the mang la: "<<endl;
	cout<<"m = "<<m<<" va c = "<<c<<endl;
	cout<<"cac vat duoc chon la: "<<endl;
	for(int i=1;i<=vt;i++) cout<<a[chosse[i]].w<<" "<<a[chosse[i]].v<<endl;
}
// Do phuc tap: O(n)
