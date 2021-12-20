#include <iostream>
using namespace std;

struct subarray {
    int s;
    int e;
    int max;
};

subarray subMax(int a[], int n)
{
    subarray res;
    
    int maxS = a[0];
    int maxE = a[0];
    int s, e, s1;
    s = e = s1 = 0;
    
    for(int i=1; i<n; i++)
    {
        if(maxE > 0) maxE = maxE + a[i];
        else{
            maxE = a[i];
            s1 = i;
        }
        
        if(maxE > maxS){
            maxS = maxE;
            e = i;
            s = s1;
        }
    }
    
    res.s = s;
    res.e = e;
    res.max = maxS;
    return res;
}

int main() {
    int n = 10;
    int arr[] = {-98,54,67,65,-879,78,65,21,-6,67};
    
    subarray res = subMax(arr, n);
    for(int i=res.s; i<=res.e; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
    cout << res.max << endl;
}
