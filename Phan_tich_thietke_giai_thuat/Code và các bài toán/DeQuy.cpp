#include <iostream>
using namespace std;

int giaiThua(int n)
{
	if (n == 0)
		return 1;
	else 
		return n*giaiThua(n-1);
}

int main()
{
	cout << giaiThua(3);
	return 0;
}	
