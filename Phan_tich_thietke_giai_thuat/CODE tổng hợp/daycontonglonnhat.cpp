#include<iostream>
#include<conio.h>
using namespace std;
int dau,cuoi,temp=0,a[100],n;
//ham nhap gia tri cua mang
void Nhap()
{
	
	cout<<"Moi ban nhap vao so phan tu cua mang :";
	cin>>n;
	cout<<"\t \t"<<"Moi nhap tung phan tu cua mang "<<endl;
	
	for(int i=1;i<=n;i++)
	{
		cout<<"A["<<i<<"]=";
		cin>>a[i];
	}
}
//ham xuat ra cac gia tri cua mang
void Xuat()
{
	cout<<"Day vua moi nhap la:"<<endl;
	for(int i=1;i<=n;i++)
	{
		cout<<a[i]<<"\t";
	}
	cout<<endl;
}
//ham xac dinh day con voi vi tri da cuoi 
void Dayconlonnhat()
{
	int sum=0;
	int max=0;
	for(int i=1;i<=n;i++)
	{
		sum=a[1];
		
		sum=+a[i];
		if(sum > max)
		{
			max=sum;	
			dau=temp;
			cuoi=i;		
		}
		if(sum<0)
		{
			temp=i+1;
			sum=0;
		}
		
		
	}
}
//xuat ra mang con co tong lon nhat
void Xuat_Mang()
{
	cout<<"Day con co gia tri lon nhat la "<<endl;
	 for(int i=dau;i<=cuoi;i++)
      {
    	cout<<a[i]<<"\t";
      }
}
int main()
{
	Nhap();
	Xuat();
	Dayconlonnhat();
    Xuat_Mang();	
	getch();
	return 0;
}
