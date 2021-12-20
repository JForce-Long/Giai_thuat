// Slide 9 trang 26
#include <stdio.h>
#include <iostream>
using namespace std;
int main()
{
	freopen("input.txt","r",stdin);
	int n,i,j;
	int a[100];
	int s=1,e=1,s1=1;
	cin>>n;
	for(i=1;i<=n;i++) cin>>a[i];
	int maxs,maxe;
	maxs=a[1]; //tong lon nhat day con lien tiep tu a[1] den a[i]
	maxe=a[1]; //tong lon nhat day con lien tiep chua chinh a[i]
	for(i=2;i<=n;i++)
	{
		if(maxe>0) maxe=maxe+a[i]; // Neu maxe>0 thi cong them a[i] vao max e
		else
		{
			maxe=a[i]; // nguoc lai maxe=a[i]
			s1=i;
		}
		cout<<"buoc "<<i-1<<": maxe= "<<maxe;
		if(maxe>maxs)
		{
			maxs=maxe; // Neu maxe lon hon maxs thi gan maxs=maxe--di tim xem co day nay lon hon maxs khong
			e=i;s=s1; // chi so dau cuoi cua day
		}
		cout<<", maxs= "<<maxs<<endl;
	}
	cout<<"tong day con lon nhat la: "<<maxs<<endl;
	cout<<"day con lon nhat tu so thu "<<s<<" den so thu "<<e<<endl;
	cout<<"Day can tim la: ";
	for(i=s;i<=e;i++) cout<<a[i]<<" ";
}
// Do phuc tap: O(n)
