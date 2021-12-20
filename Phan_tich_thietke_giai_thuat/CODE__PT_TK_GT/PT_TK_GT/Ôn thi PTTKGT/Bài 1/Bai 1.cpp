//Slide 4 trang 34
#include<iostream>
#include<stdio.h>
#include<time.h>
#include <conio.h>
#include<stdlib.h>
using namespace std;
int n,a[100];
void QuickSort(int l,int r)
{
    if(l>=r) return;
    int i = l, j =r;
    int mid = a[(l+r)/2];//chon phan tu o giua
    cout<<"mid = "<<mid<<endl;
    do{
        while(mid > a[i]) i++;//Duyet tu vi tri tiep theo sang phai tim vi tri phan tu i dau tien >= mid
        while(mid < a[j]) j--;//Duyet tu phai theo sang trai tim vi tri phan tu j dau tien < mid
        cout<<" i = " <<i<<" ; j = "<<j<<endl;
        if(i<=j)//Neu i nho hon j thi doi cho
		{
            swap(a[i],a[j]);
            i++;
            j--;
        }
    }while(i<j);//tiep tuc duyet den khi j<i
    for(int i=1;i<=n;i++) cout<<a[i]<<" ";
    cout<<endl;
    getch();
    if(l<j) QuickSort(l,j);//Thuc hien quicksort voi cac doan con, khi l<j
    if(i<r) QuickSort(i,r);//Thuc hien quicksort voi cac doan con, khi i<r
}
main()
{
    freopen("input.txt","r",stdin);
    cin>>n;
    for(int i=1;i<=n;i++)
	{
        cin>>a[i];
        cout<<a[i]<<" ";
    }
    cout<<endl;
    QuickSort(1,n);
    cout<<"ket qua: "<<endl;
    for(int i=1;i<=n;i++)
	{
        cout<<a[i]<<" ";
    }
}
// Do phuc tap: O(nlog(n))
