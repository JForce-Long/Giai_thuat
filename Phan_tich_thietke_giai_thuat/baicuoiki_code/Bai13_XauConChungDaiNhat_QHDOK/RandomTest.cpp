#include <bits/stdc++.h>
#define Min 48
#define Max  122



using namespace std;
int random(){
    return Min + rand() % (Max + 1 - Min);
}
long long Rand()
{
    return Min + ((long long)rand() * (RAND_MAX + 1) * (RAND_MAX + 1) * (RAND_MAX + 1) +
                (long long)rand() * (RAND_MAX + 1) * (RAND_MAX + 1) +
                (long long)rand() * (RAND_MAX + 1) +
                rand()) % (Max - Min + 1);
}

int main(){
	fstream f;                      // (2)
	f.open("RandomTest.IN", ios::out);
	int n;
	int m;
	cin>>n>>m;
	//f<<n<<endl;
	srand((int)time(0));
    int A[n], B[m];
    for(int i = 0; i < n; ++i){
       A[i] = Rand();
       f<<(char)A[i];
       //f<<i<<" ";
    }
    f<<endl;
    for(int i = 0; i < m; ++i){
       B[i] = Rand();
       f<<(char)B[i];
       //f<<i<<" ";
    }
    
	return 0;
}
