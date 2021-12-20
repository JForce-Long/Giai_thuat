#include<iostream>
#include<math.h>
using namespace std;

int power(int a, int n)
{
    if(n==0) 
    return 1;
    else if(n%2 == 0)
        return power(a*a, n/2); //ham chan
        else
        return a*power(a*a, n/2); //ham le
}

int main()
{
    cout << "ket qua: " << power(2, 6);
    return 0;
}
