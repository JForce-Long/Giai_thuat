#include <iostream>
#define n 6
#define Start 0
#define VC 1000
using namespace std;
int a[n], b[n], luu[n], gttu=1000, S=0, Cmin;
int A[n][n]={{0,1,2,7,5},
             {1,0,4,4,3},
             {2,4,0,1,2},
             {7,4,1,0,3},
             {5,3,2,3,0},};

int findCmin()
{
	int i, j;
	int Cmin = 100000;
	for(i=0; i<n; i++)
		for(j=0; j<n; j++)
			if(Cmin > A[i][j])
				Cmin = A[i][j];
	return Cmin;	
}

void init()
{
	for(int i=0; i<n; i++)
		b[i] =1;
	a[0] = Start;
	b[Start] =0;
	Cmin = findCmin();
}

void luukq()
{
	for(int i=0; i<n; i++)
		luu[i]=a[i];
}

void Xuat()
{
	cout <<"Gia tri toi uu = " << gttu << endl;
	for(int i=0; i<n; i++)
	cout << luu[i]+1 << " ";
	cout <<Start + 1;
	cout <<endl;
}

void Try(int i, int start)
{
	int j, Tong, g, tmp=S;
	for(j=0; j<n; j++)
	{
		if((b[j]==1)&&(A[start][j]!=VC))
		{
			a[i]=j;
			b[j]=0;
			S+=A[start][a[i]];
			if(i==n-1)
			{
				Tong = S+ A[a[i]][a[0]];
				if(Tong<gttu)
				{
					gttu=Tong;
					luukq();
				}
				else
				{
					g=S+Cmin*(n-i+1);
					if(g<gttu)
						Try(i+1, a[i]);
				}
				b[j]=1;
				S-=A[start][a[i]];
			}
		}
	}
}

int main()
{
	init();
	Try(1, Start);
	Xuat();
	return 0;
}
