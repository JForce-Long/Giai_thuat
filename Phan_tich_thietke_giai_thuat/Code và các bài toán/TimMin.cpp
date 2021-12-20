#include <iostream>
using namespace std;

int Min(int a[], int l, int r)
{
	int min, min1, min2;
	
	if(l==r)
		min = a[l];
	else
	{	int mid = (l+r)/2;
		min1 = Min(a, l, mid);
		min2 = Min(a, mid+1 , r);
		if(min1<min2)
			min = min1;
		else 
			min = min2;
	}
	return min;	
}

int main()
{
	int a[7] = {1,5,3,45,32,21,-15};
	cout << "Gia tri nho nhat: " << Min(a,0,6);
	return 0;
}
