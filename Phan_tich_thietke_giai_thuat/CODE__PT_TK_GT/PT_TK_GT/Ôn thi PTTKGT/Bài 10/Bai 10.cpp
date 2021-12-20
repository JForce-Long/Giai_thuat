//SLide 7 trang 24
#include <iostream>
#include <stdio.h>
#include<algorithm>
using namespace std;
int n,chon[100],dem=1;
struct node
{
    int u;
    int v;
};node arr[100];
bool cmp(node &a, node &b)
{
    return a.v<b.v;
}
void Init()
{
    freopen("input.txt","r",stdin);
    cin>>n;
    for(int i=1;i<=n;i++)
	{
        cin>>arr[i].u>>arr[i].v;
    }
}
main()
{
    Init();
    sort(arr+1,arr+n+1,cmp);//sap xep cong viec theo chieu tang dan dau mut phai-diem ket thuc cong viec
    chon[1] = 1;
    int t = 1;
    for(int i=2;i<=n;i++)//duyet tu danh sach cac cong viec da duoc sap xep
	{
        if(arr[i].u > arr[t].v) //neu diem bat dau cua cong viec sau lon hon diem ket thuc cua cong viec truoc thi chon
		{
            t = i;
            dem++;
            chon[dem] = t;
        }
    }
    cout<<"so cong viec lam duoc = "<<dem<<endl;//in ra ket qua
    for(int i = 1;i <= dem; i++){
        cout<<chon[i]<<" ";
    }
}

