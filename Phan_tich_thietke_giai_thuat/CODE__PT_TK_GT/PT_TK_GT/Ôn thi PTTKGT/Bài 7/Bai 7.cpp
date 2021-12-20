// Slide 7 trang 2
#include<conio.h>
#include<io.h>
#include<iostream>
using namespace std;
int G[100][100];
int n;
int kiemtra[100],canh[100][2],c,ketqua,tong[100];
void Init()
{
	int i,j;
	cin>>n;
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			cin>>G[i][j];			
		}
	}
	cout<<" \n So dinh: "<<n<<endl;
	cout<<" Ma tran trong so la: "<<endl;
	for(i=1;i<=n;i++)
	{
		cout<<endl;
		for(j=1;j<=n;j++)
		{
			cout<<" "<<G[i][j];
			if(G[i][j]==0) G[i][j]=32000;
		}
	}
}

void Prim()
{
    int top,min,u;
    int a[100];
    c=0;ketqua=0;
    cout<<endl;
    cin>>u;
    cout<<"Dinh bat dau xet: "<<u;
    for(int i = 1; i<=n; i++) kiemtra[i]=0;
    top=1;a[top]=u;//mang a luu cac dinh cua cay khung can tim
	kiemtra[u]=1; //Danh dau dinh bat dau xet la da xet
    int dau, cuoi;
    while(c<n-1) 
    {
        min=32000;//so min lon
        for(int i = 1; i<=top; i++)  //Tim ra canh co trong so nho nhat trong cac canh noi tu cac dinh da xet toi cac dinh chua xet
        {
            int t = a[i];//Xet lan luot tung dinh da duoc them vao cay khung
            for(int j = 1; j<=n; j++)//lan luot kiem tra cac canh de tim ra canh nho nhat
            {
                if(kiemtra[j]==0 && min>G[t][j])
                {
                    min = G[t][j];//khi tim ra canh nho hon gan min= canh nho hon
                    dau = t;cuoi = j;// luu lai canh nho nhat tim duoc voi dinh dau va dinh cuoi
                }
            }
        }
        kiemtra[cuoi]=1; //danh dau dinh co canh nho nhat noi voi mot trong cac dinh da xet la da xet
        c++;canh[c][1]=dau;canh[c][2]=cuoi;//mang 2 chieu luu lai qua trinh duyet cay
        tong[top]=ketqua+min;ketqua+=min;//tong gia tri cay
		top++;a[top]=cuoi;//G[dau][cuoi]=32000; //them dinh vua tim ra vao cay khung can tim
    }
}
void Xuat()
{
	cout<<endl;
    cout<<"Cac buoc tim cay khung:"<<endl;
    for(int i = 1; i<=c; i++)
        cout<<canh[i][1]<<" - "<<canh[i][2]<<" : "<<tong[i]<<endl;
    cout<<"Do dai cay khung nho nhat la: "<<ketqua<<endl;
}
int main()
{
	freopen("input.txt","r",stdin);
	Init();
    Prim();
    Xuat();
}

// do phuc tap cua thuat toan la O(n^3)



