#include <iostream>
#include <math.h>
using namespace std;

void Nhan(int N, int X[], int Y[])
{
	int nho = 0, tg;
	int R [2*N] = { };

    for (int i = 0; i < N; i++)
    {
    	for (int j = 0; j < N; j++)
    	{
	        tg = Y[i] * X[j] + nho + R[i+j];
	        R[i+j] = tg % 10;
	        nho = tg / 10;
        }
        if (nho >0)
    	{
	        R[N-1] += nho;
    	}
    }
    for (int i= 2*N-2; i >= 0; i--)
    {
        cout << R[i];
    }
}
int main()
{
	int n, a[100], b[100];
    cout << "Nhap so chu so cua a va b: ";
    cin >> n;
    cout << "Nhap so a: ";
    for (int i = n-1; i >= 0; i--)
    {
        cin >> a[i];
    }
    cout << "Nhap so b: ";
    for (int i = n-1; i >= 0; i--)
    {
        cin >> b[i];
    }
    Nhan(n, a, b);
    return 0;
}
