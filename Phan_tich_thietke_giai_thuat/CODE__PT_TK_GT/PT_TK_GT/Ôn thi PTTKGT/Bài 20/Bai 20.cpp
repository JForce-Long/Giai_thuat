#include <bits/stdc++.h>
using namespace std;
int n, b, w[1000], c[1000];
int max1=0;
int x[1000], res[1000], sumc=0, sumw=0;

void Try(int i)
{
    for(int j = 0; j<=1; j++)
    {
        if(sumw+j*w[i]<=b)//Neu khoi luong khi them vat thu i ma lon hon khoi luong tui thi thoat nhanh
        {
            x[i]=j;                 //gan x[i] bang tung gia tri 0 va 1
            sumc+=(c[i]*x[i]);        //tong gia tri nhan duoc den vat thu i dua theo chi so x[i]
            sumw+=(w[i]*x[i]);        //tong trong luong nhan duoc den vat thu i dua theo chi so x[i]
            if(i==n)                //xem duyet het cac do vat chua
            {
                if(sumc>max1)       //xem xet rang tong khoi luong cac vat duoc chon <=b va tong gia tri dang la lon nhat
                {
                    for(int t=1; t<=n; t++) res[t]=x[t]; //gan vecto lon nhat bang cac chi so x[t] da chon
                    max1=sumc;          //gan lai gia tri lon nhat luc nay la sumc
                }
            }
            else Try(i+1);          //neu chua duyet het thi duyet tiep phan tu tiep theo
            sumc-=(c[i]*x[i]);        //tra lai tong gia tri ban dau khi chua chon vat thu i
            sumw-=(w[i]*x[i]);
        }
    }
}
int main()
{
    freopen("input.txt","r",stdin);
    cin>>n>>b;
    for(int i = 1; i<=n; i++) cin>>w[i]>>c[i];
    Try(1);
    cout<<"Gia tri lon nhat la: "<<max1<<endl;
    cout<<"Cac vat duoc chon la: "<<endl;
    for(int i = 1; i<=n; i++) if(res[i]==1) cout<<w[i]<<" "<<c[i]<<endl;
    cout<<endl;
}
