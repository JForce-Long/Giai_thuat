//Slide 4 trang 11
#include<stdio.h>
#include<iostream>
using namespace std;
void Merge(int a[],int left,int mid,int right)//ham tron cac doan da sap xep
{
	int i=left,j=mid+1,k=left;
	int b[20];
	while(i<=mid && j<=right)//Khi xet het 1 trong 2 doan thi dung
	{
		if(a[i]<a[j])//neu a[i]<b[j] them a[i] vao trong day b[], tang bien dem i 
		{
			b[k]=a[i];
			i++;
		}
		else// nguoc lai them a[j] vao trong day b[], tang bien dem j
		{
			b[k]=a[j];
			j++;
		}
		k++;//tang bien k
	}
	if(i>mid) // neu day i het truoc thi dua toan bo day j vao b[]
	{
		for(int t=j;t<=right;t++) 
		{
			b[k]=a[t];
			k++;
		}
	}
	else//nguoc lai dua toan bo day i vao b[]
	{
		for(int t=i;t<=mid;t++) 
		{
			b[k]=a[t];
			k++;
		}
	}
	for(int i=left;i<=right;i++) a[i]=b[i];//gan lai day b[] da sap xep vao day a[]
}
void MergeSort(int a[],int l,int r)//Tien hanh chia nho doan can sap xep
{
	if(l>=r) return;
	int mid=(l+r)/2;//tim diem chinh giua de chia
	MergeSort(a,l,mid);//Tiep tuc chia nho cac doan den khi con 1 phan tu
	MergeSort(a,mid+1,r);
	Merge(a,l,mid,r);//Tron cac doan da duoc sap xep
}
int main()
{
	int n,a[20];
	freopen("input.txt","r",stdin);
	cin>>n;
	for(int i=1;i<=n;i++) {cin>>a[i];cout<<a[i]<<" ";}
	cout<<endl;
	MergeSort(a,1,n);
	for(int i=1;i<=n;i++) cout<<a[i]<<" ";
}
//Do phuc tap: O(nlog(n))
