// Slide 10 trang 2
#include<iostream>
#include<string.h>
using namespace std;
#define max 50
char b[max][max];
int Max(int a, int b)
{
    if(a>b) return a;
    return b;
}
string LCS(string x, string y )
{
    int n= x.length();
    int m= y.length();// phan tu chuoi bat dau tu 0
    int c[max][max];
    for(int i =  1; i <=n; i++)
    {        
        for(int j =  1; j <= m; j++)
        {
            if(!i||!j) // Gan cac hang cot dau tien bang 0
            {
                c[i][j]=0;
            }          
            if (x[i-1]==y[j-1]) 
			{
                c[i][j]= c[i-1][j-1]+1; // phan tu thu x[i-1] = y[j-1] thi gan o cheo phai tren cong them 1
            }            
            else
            {
                c[i][j]=Max(c[i][j-1],c[i-1][j]); // neu khong bang thi gia tri tai c[i][j] la gia tri lon hon cua 1 trong 2 o lien ke nho hon             
            }           
        }	        
    }
	for(int i=0;i<=n;i++)
		{
		for(int j=0;j<=m;j++)
			{
				cout<<c[i][j]<<" "; //in ra qua trinh lua chon
			}
			cout<<endl;
		}
	string s;
    int i =n, j=m;
    while(i>=1&&j>=1) // Truy vet ket qua
	{   	
        if(x[i-1]==y[j-1]) 
        {
           s+=x[i-1];
           --i;
           --j;
        }
        else
		{
	        if (c[i][j]==c[i-1][j])
	        {
	   			--i;
	        }
	        else 
	        {
	        	--j;
	        }       	
		} 
    }
    return s;        
}
int main()
{
	freopen("input.txt","r",stdin);
	string x,y;
    cin>>x>>y;
    string s= LCS(x,y);  
    for(int i= s.length()-1 ;i >= 0; i--)
    {
        cout<<s[i];
        
    }
}
// Do phuc tap: O(n^2)
