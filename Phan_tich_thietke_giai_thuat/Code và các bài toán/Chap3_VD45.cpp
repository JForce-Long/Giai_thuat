#include<iostream>
#include<conio.h>
#define MAX 100
using namespace std;

void nhap(int a[MAX][MAX],int n)
{
   int i,j;
   for(i=0;i<n;i++)
     for(j=0;j<n;j++)
      {
          cout << "a[" <<i << "][" << j << "] = ";
          cin >> a[i][j];
      }
}

void xuat(int a[MAX][MAX],int n)
    {
        int i,j;
        for(i=0;i<n;i++)
            {
              for(j=0;j<n;j++)
                cout << a[i][j] << " ";
              cout << endl;
            }
     }

void tich(int a[MAX][MAX],int b[MAX][MAX],int t[MAX][MAX],int n)
    {
        int i,j,k;
        for(i=0;i<n;i++)
            for(j=0;j<n;j++)
                {
                    t[i][j]=0;
                    for(k=0;k<n;k++)
                        t[i][j]+=a[i][k]*b[k][j];
                }
    }
float dinhThuc(int a[MAX][MAX],int n)
{
	int d =0;
	
}
int main()
  {
    int a[MAX][MAX],b[MAX][MAX],t[MAX][MAX];
    int n;

    cout << "Nhap cap cua ma tran n = ";
    cin >> n;
	
	cout << "Nhap A:\n";
    nhap(a,n);
    cout << "A:\n"; 
	xuat(a,n);

    cout << "Nhap B:\n";
    nhap(b,n);
    cout <<"B:\n";
	xuat(b,n);

    tich(a,b,t,n);
	cout << "Tich cua 2 ma tran la:\n";
	xuat(t,n);
	return 0;
  } 
