#include <iostream>
using namespace std;

int n, x[20], a[20], b[20], c[20], dem=0;

void KhoiTao()
{
	cout << "Nhap so hang (cot): ";
	cin >> n;
	
	for(int i=2; i<=2*n; i++)
	{
		b[i]=1;
	}
	for(int i=1-n; i<n; i++)
	{
		c[i] = 1;
	}
	for(int i=1; i<=n;i++)
	{
		a[i]=1;
	}
}


void Xuat(int x[])
{
	for(int i=1; i<=n; i++)
	{
		cout << "[" << i << "," << x[i] << "]"<< endl;
	}		
	
}

void Try(int i)
{
	for(int j=1; j<=n; j++)
	{
		if(a[j]&&b[i+j]&&c[i-j])
		{
			x[i] = j; a[j]=0;
			b[i+j] = 0; c[i-j] = 0;
			
			if(i<n)
			{
				Try(i+1);
			}
				
			else
			{
				dem++;
				Xuat(x);
				cout<<"---------\n";
			} 
				
			a[j]=1; b[i+j]=1; c[i-j]=1;
		}
	}
		
}

int main()
{
	
	KhoiTao();
	Try(1);
	cout << "\n Tong so cach dat quan Hau: " << dem<<endl;
	return 0;
}
