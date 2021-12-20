#include <iostream>
using namespace std;

int s, e, s1, MaxS, MaxE;

void subMax(int a[], int n)
{
	MaxS = a[0];
	MaxE = a[0];
	s = e = s1 = 0;
	
	for(int i=1; i<n; i++)
	{
		if(MaxE>0)
			MaxE = MaxE + a[i];
		else
		{
			MaxE = a[i];
			s1 = i;
		}
		if(MaxE>MaxS)
		{
			MaxS = MaxE;
			e=i;
			s=s1;
		}
	}
}
	
int main()
{
//	int a[] = {13,-15,2,18,4,8,0,-5,-8};
//	subMax(a,9);
	
	int a[] = {-98,54,67,65,-879,78,65,21,-6,67};
	subMax(a,10);

	cout << "Day con lon nhat la: ";
	for(int i = s; i<=e; i++)
		cout << a[i] << " ";
	cout << "\nTong day = " << MaxS;
	return 0;
}
