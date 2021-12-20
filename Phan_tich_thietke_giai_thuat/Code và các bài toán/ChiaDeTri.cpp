#include <iostream>
using namespace std;

int TKNP(int a[], int l, int r, int x)
{
	if(l>r)
		return 0;
	int mid = (l+r)/2;
	if (x==a[mid])
		return mid;
	if (x<a[mid])
		return TKNP(a, l, mid-1,x);
	return TKNP(a, mid+1, r, x);
}

int Min(int a[], int l, int r)
{
	int min, min1, min2;
	
	if(l==r)
		min = a[l];
	else
	{	int mid = (l+r)/2;
		min1 = Min(a, l, mid);
		min2 = Min(a, mid+1 , r);
		if(min1<min2)
			min = min1;
		else 
			min = min2;
	}
	return min;	
}
void Merge(int a[], int l, int t, int r)
{
	int i = l;
	int j = t+1;
	int p = l;
	int c[100];
	while(i<=t && j<=r)
	{
		if(a[i]<a[j])
		{
			c[p] = a[i];
			i++;
		}
		else 
		{
			c[p] = a[j];
			j++;
		}
		p++;
	}
	
	while(i<=t)
	{
		c[p] = a[i];
		i++;
		p++;
	}
	
	while (j<=r)
	{
		c[p] = a[j];
		j++;
		p++;
	}
	
	for(i=l; i<=r; i++)
	{
		a[i] = c[i];
	}
}

void MergeSort(int a[], int l, int r)
{
	if(l>=r)
		return;
		
	int mid = (l+r)/2;
	
	MergeSort(a,l,mid);
	MergeSort(a,mid+1,r);
	
	Merge(a,l,mid,r);
		
}
void Swap(int &a, int &b)
{
	int temp = a;
	a = b;
	b = temp;
}
int Partition(int a[], int l, int r)
{
	int x = a[l];
	int i = l+1;
	int j = r;
	while(i<j)
	{
		while((i<j) && (a[i]<x))
			i++;
		while ((j>=i) && (a[j]>=x))
			j--;
		if(i<j)
			Swap(a[i], a[j]);
	}
	Swap(a[l],a[j]);
	return j;
}
void QuickSort(int a[], int l, int r)
{
	if(l<r)
	{
		int temp = Partition(a, l ,r);
		QuickSort(a,l,temp-1);
		QuickSort(a,temp+1,r);
	}
}
int main()
{
	int a1[7] = {1,5,3,45,-12,21,30};
	int a2[7] = {1,5,3,45,53,77,89};
	//cout << TKNP(a2,0,6,21);
	//cout << "Gia tri nho nhat: " << Min(a1,0,6);
	
	//MergeSort(a1,0,6);
	QuickSort(a1,0,6);
	for (int i =0;i<7;i++)
		cout << a1[i] << " ";
		
	return 0;
}
