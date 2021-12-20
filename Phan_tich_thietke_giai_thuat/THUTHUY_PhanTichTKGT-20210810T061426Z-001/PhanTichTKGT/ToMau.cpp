#include <iostream>
using namespace std;

int a[100][100];
int n; //So dinh
int sm = 0; //so mau su dung
int x[100];//ket qua

void Nhap()
{
	cout << "Nhap so dinh: ";
	cin >> n;
	for(int i = 1; i<= n; i++)
		for(int j=1; j<=n; j++)
		{
			cout << "a[" << i << "][" << j << "] = ";
			cin >> a[i][j];
		}
}

void ToMau()
{
	int kt;
	for(int i = 1; i<= n; i++)
	{
		if(!x[i])
		{
			sm++;
			x[i] = sm;
			for(int j = i+1; j<=n;j++)
			{
				if (a[i][j] == 0 && x[j] == 0)
				{
					kt = 1;
					for(int k = i+1; k< j; k++)
					{
						if(a[k][j] = 1 && x[i]==x[k])
						{
							kt = 0;
							break;
						}
					}
					if(kt==1)
						x[j] = sm;
				}
			}
		}
	}
}

void XuatKQ()
{
	for(int i=1; i<=sm; i++)
	{
		cout << "Mau " << i << ": ";
		for (int j = 1; j<=n; j++)
			if(x[j] == i)
				cout << j << " ";
		cout << endl;
	}
}
int main()
{
	Nhap();
	ToMau();
	XuatKQ();
	
	return 0;
}
