// Slide 9 trang 14
#include <stdio.h>
#include <iostream>
using namespace std;
int main()
{
	freopen("input.txt","r",stdin);
	int F[100][100];
	int w[100];
	int c[100];
	int b,n,i,L;
	cin>>b;
	cin>>n;
	for (i=1;i<=n;i++)
	{
		cin>>w[i];
		cin>>c[i];
	}
	for(L=0;L<=b;L++) F[0][L]=0;
	for(i=0;i<=n;i++) F[i][0]=0;
	for(i=1;i<=n;i++)
	for(L=1;L<=b;L++)//chi mang them do vat thu i khi gia tri tui luc mang i-1 do vat o trong luong tui L-w[i] +c[i] lon hon khi k mang do vat i
	{
		F[i][L]=F[i-1][L];	
		if((L>=w[i])&&(F[i-1][L-w[i]]+c[i]>F[i-1][L]))
			F[i][L]=F[i-1][L-w[i]]+c[i];
	}
	for(i=0;i<=n;i++)
	{
		for(L=0;L<=b;L++) cout<<F[i][L]<<" ";//in ra qua trinh thuc hien
		cout<<endl;
	}
	cout<<endl;
	cout<<"Khoi luong lon nhat co the mang la: "<<F[n][b]<<endl;
	int j=n,k=b;
	cout<<"Cac do vat duoc chon la: ";
	while(j!=0&&k!=0)
	{
		if(F[j][k]!=F[j-1][k])
		{
			cout<<j<<" ";
			k-=w[j];
		}
		j--;
	}	
}
// DO phuc tap: O(n^2)
