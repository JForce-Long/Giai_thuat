#include <bits/stdc++.h>

using namespace std;
struct CongViec
{
	int Start;
	int End;
};

int main()
{
	CongViec cv[100], tg;
	int n, i, j, d;
	cout<<"Nhap so cong viec: ";
	cin>>n;
	cout<<"Nhap time: "<<endl;
	for(i=0; i<n-1; i++)
	cin>>cv[i].Start>>cv[i].End;
	//-------Sap xep ----------
	//sap xep 1
//	for(i=0; i<n-1; j++)
//		for(j=i+1; j<n; j++)
//		if(cv[i].Start > cv[j].Start)
//		{
//			tg=cv[i];
//			cv[i]=cv[j];
//			cv[j]=tg;
//		}
	
	//sap xep 3
//	for(i=0; i<n-1; j++)
//		for(j=i+1; j<n; j++)
//		if(cv[i].End > cv[j].End)
//		{
//			tg=cv[i];
//			cv[i]=cv[j];
//			cv[j]=tg;
//		}
	
	cout<<"Danh sach cong viec duoc chon: "<<endl;
	cout<<cv[0].Start<<" "<<cv[0].End<<endl;
	d=0;
	for(i=1; i<n; i++)
		if(cv[i].Start > cv[d].End)
		{
			cout<<cv[i].Start<<" "<<cv[i].End<<endl;
			d=i; 
		}
}
