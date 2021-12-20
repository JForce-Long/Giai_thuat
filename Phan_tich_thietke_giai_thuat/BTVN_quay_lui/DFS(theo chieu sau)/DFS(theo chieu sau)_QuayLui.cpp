#include <iostream>

using namespace std;

int G[10][10];
int n, s, t; //start and target
int visited[10], before[10];

void Init()
{
    freopen("input.txt","r",stdin);
    int i, j;
    cin>>n;
    for(i = 1; i <= n; i++)
    {
        for(j = 1; j <= n; j++)
        {
            cin>>G[i][j];
        }
    }
    cout<<" \n So dinh: "<<n<<endl;
    cout<<" Ma tran ke: ";
    for(i = 1; i <= n; i++)
    {
        cout<<endl;
        for(j = 1; j <= n; j++)
        {
            cout<<"\t"<<G[i][j];
        }
    }
    cout<<endl;
}
void res()
{
    int j = t;
    cout<<t<<"<-";
    while(before[j] != s)
    {
        cout<<before[j]<<"<-";
        j=before[j];
    }
    cout<<s;
    cout<<endl;
}
void DFS(int s)   //backtracking
{
    int u;
    visited[s] = 1;   //da duyet diem dau
    for(u = 1; u <= n; u++)
    {
        if(G[s][u] == 1 && visited[u] == 0)  //k? và chua du?c tham
        {
            before[u] = s;  //gan dinh truoc diem u trong duong di la s
            if(u == t) // neu xet den dinh t la diem cuoi
            {
                res(); //in ra ket qua
            }
            else
            {
                DFS(u);// neu chua den diem cuoi thi tiep tuc xet
            }
            visited[u] = 0;// khi xet xong 1 ket qua khoi tao lai cac dinh la chua xet
        }
    }
}
int main()
{
    s = 1;
    t = 4;
    for (int u = 1; u <= n; u++)
    {
        visited[u]=0;
    }
    Init();
    cout<<endl;
    cout<<"Cach di tu dinh "<<s<<" den dinh "<<t<<" la: "<<endl;
    DFS(s);
}
// do phuc tap: O(n^n)
