//Slide 5 trang 8
#include <iostream>
#include <algorithm>
using namespace std;
int a[1000];
int dau1,cuoi1,dau2,cuoi2,sub1,sub2;
int Wmax=0;
int maxrightvector(int i,int j)//Tim mang con lon nhat tu giua sang phai
{
	int maxsum = -999999;
	int sum = 0;
	dau2 = cuoi2 = i;
	for(int k = i;k<=j;k++)
	{
		sum = sum + a[k];
		if (sum>=maxsum) 
		{
			cuoi2=k;//danh dau lai can phai
		}
		maxsum = max(sum,maxsum);		
	}
	return maxsum;
}
int maxleftvector(int i,int j)//Tim mang con lon nhat tu giua sang trai
{
	int maxsum = -999999;
	int sum = 0;
	dau1=cuoi1=j;
	for(int k = j;k>=i;k--)
	{
		sum = sum + a[k];
		if (sum>=maxsum) 
		{
		dau1=k;//danh dau lai can trai
		}
		maxsum = max(sum,maxsum);
	}
	return maxsum;
}
int maxsubvector(int i,int j)
{
	if(i==j) return a[i];
	else
	{
		int WL,WR,WM,mid,W;
		mid = (i+j)/2;
		//tinh mang con lon nhat cua moi nua mang 1 cach de quy
		WL = maxsubvector(i,mid);//mang con lon nhat ben trai
		WR = maxsubvector(mid+1,j);//mang con lon nhat ben phai
		WM = maxleftvector(i,mid) + maxrightvector(mid+1,j);//mang con lon nhat tinh tu giua cong ra 2 ben
		W = max(WL,max(WR,WM));//tra ve ket qua la mang con lon nhat trong 3 mang left,right,mid
		Wmax=max(Wmax,W);//Danh dau lai chuoi lon nhat
		if(W==WM&&W==Wmax)//danh dau lai 2 can cua day de truy vet
		{
			sub1=dau1;
			sub2=cuoi2;
		}
		return Wmax;
	}
}
main()
{
	freopen("input.txt","r",stdin);
	int n;
	cin>>n;
	int i;
	for(i=1;i<=n;i++) cin>>a[i];
	maxsubvector(1,n);
	cout<<"day con lien tiep co tong lon nhat la "<<sub1<<" --> "<<sub2<<endl;
	cout<<"tong lon nhat la "<<maxsubvector(1,n);
	
}
//Do phuc tap: O(nlogn)
