#include <iostream>
#include <string.h>
using namespace std;
int c[50][50];
char x[50], y[50];
int m,n;

void LCS()
{
	int i,j;
	for(i = 0; i <= m; i++)
		c[i][0] = 0;
	for(j = 0; j <= n; j++)
		c[0][j]=0;
	for(i = 0; i <= m-1; i++)
		for(j = 0; j <= n-1; j++)
		{
			if(x[i]==y[j])
			{
				c[i][j] = c[i-1][j-1]+1;
			}
			else
				if(c[i-1,j]>=c[i,j-1])
					c[i][j]=c[i-1][j];
				else
					c[i][j]=c[i][j-1];
		}
}

int main()
{
	cout << "X = "; cin >> x;
	cout << "Y = "; cin >>y;
	m = strlen(x);
	n=strlen(y);
	
	LCS();
	for(int i = 1; i <= m; i++)
	{
		for(int j = 1; j <= n; j++)
		{
			cout << c[i][j];
		}
		cout << endl;
	}
	return 0;
}
