#include <iostream>
#define N 5
#define Start 0
using namespace std;

int a[N], b[N], temp[N], gttu=100000, S=0;
int x[N][N] = {{0,3,5,2,6},
				{3,0,6,7,3},
				{5,6,0,5,4},
				{2,7,5,0,1},
				{6,3,4,1,0}};

void Khoitao()
{
	for(int i=0; i<N; i++)
	{
		b[i]=1;
		a[0] = Start;
		b[Start] =0;
	}
}

void luukq()
{
	for(int i=0; i<N;i++)
		temp[i] = a[i];
}

void xuat()
{
	cout <<"Gia tri toi uu = " << gttu << endl;
	for(int i=0; i<N; i++)
		cout << temp[i]<<" ";
	cout << Start;
	cout << endl;
}

int giatri()
{
	int S=0, start = Start;
	for(int i=1; i<N; i++)
	{
		S+=x[start][a[i]];
		start = a[i];
	}
	S+= x[start][a[0]];
	return S;
}
void NguoiDL(int i)
{
	for(int j = 0; j<N; j++)
	{
		if(b[j]==1)
		{
			a[i]=j;
			b[j]=0;
			if(i==(N-1))
			{
				if(giatri()<gttu)
				{
					gttu=giatri();
					luukq();
				}
			}
			else
				NguoiDL(i+1);
			b[j]=1;
		}
	}
}

int main()
{
	Khoitao();
	NguoiDL(0);
	
	return 0;
}
