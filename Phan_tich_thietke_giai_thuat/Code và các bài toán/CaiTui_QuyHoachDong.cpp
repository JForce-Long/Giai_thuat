#include <iostream>
using namespace std;

int MaxV[50][50], W;
struct DoVat{
	int w, c;
};

int BagBest(DoVat dv[], int n, int b)
{
	int L, i;
	for(L=0; L<=b; L++)
		MaxV[0][L] = 0;
	for(i=0;i<=n; i++)
		MaxV[i][0] = 0;
	for(i=1; i<=n; i++)
		for(L=1; L<=b; L++)
			{
				MaxV[i][L] = MaxV[i-1][L];
				if((L>=dv[i].w) && ((MaxV[i-1][L-dv[i].w]+dv[i].c) > MaxV[i-1][L]))
					MaxV[i][L] = MaxV[i-1][L-dv[i].w]+dv[i].c;
			}
	return MaxV[n][b];
}

void Chon(DoVat dv[], int n, int b, int &W)
{
	int L = b, i = n;
	W =0;
	while((i!=0) && (L!=0))
	{
		if(MaxV[i][L]!=MaxV[i-1][L])
		{
			cout << i << " ";
			W += dv[i].w;
			L-= dv[i].w;
		}
		i--;
	}	
}
int main()
{
	DoVat item[50];
	int n, b, TongGiaTri=0;
	cout << "Nhap so do vat: ";
	cin >> n;
	for (int i=1; i<=n; i++)
	{
		cout << "Do vat " << i << ": \n";
		cout << "Gia tri: "; cin >> item[i].c;
		cout << "Trong luong: "; cin >> item[i].w;
		cout << endl;
	}
	cout << "Trong luong cai tui: ";
	cin >> b;
	
	int kq = BagBest(item, n,b);
	cout << "Gia tri cua tui sau khi chon: " << MaxV[n][b];
	cout << "\nCac do vat duoc chon: ";
	Chon(item,n,b, W);
	cout << "\nTrong luong do vat duoc chon: " << W;
	return 0;
}
