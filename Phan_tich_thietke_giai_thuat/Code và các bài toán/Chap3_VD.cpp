#include <iostream>
#include <math.h>
using namespace std;

void VD1()
{
	//Cho so nguyen a co khong qua 100 chu so 
	//va so nguyen b, 1 <= b <= 9. Tinh c = axb.

	int n, a[1000], b;
    cout << "Nhap so chu so cua a: ";
    cin >> n;
    cout << "Nhap so a: ";
    for (int i = n-1; i >= 0; i--)
    {
        cin >> a[i];
    }
    cout << "Nhap so b: ";
    cin >> b;
    int nho = 0, tg, c[101];

    for (int j = 0; j < n; j++)
    {
        tg = b * a[j] + nho;
        c[j] = tg % 10;
        nho = tg / 10;
    }

    if (nho >0)
    {
        n++;
        c[n-1] = nho;
    }

    for (int i = n-1; i >= 0; i--)
    {
        cout << c[i];
    }
}

void VD2()
{
	//giai pt bac 2
	float a, b, c, x1, x2;
	cout << "Nhap a = ";
	cin >> a ;
	cout << "Nhap b = ";
	cin >> b ;
	cout << "Nhap c = ";
	cin >> c ;
	
	float delta = b*b - 4*a*c;
	if(delta < 0)
		cout << "PT vo nghiem";
	else if(delta == 0)
	{
		x1=x2 = -b/(2*a);
		cout << "PT co nghiem kep: x1= x2= " << x1;
	}
	else
	{
		x1 = (-b + sqrt(delta))/(2*a);
		x2 = (-b - sqrt(delta))/(2*a);
		cout << "\nPT co 2 nghiem: x1 = " <<x1 <<", x2 = "<<x2;
	}
}

void VD3a()
{
	//Cho day a[n] tim xem gia tri x co trong day hay ko
	int n, a[n], x;
	cout << "Nhap n: ";
	cin >> n;
	cout << "Nhap day a:";
	for (int i=0;i<n;i++)
	{
		cin >> a[i];
	}
	cout << "Nhap so can tim x= ";
	cin >> x;
	
	int k = -1;
	for(int i =0; i <n; i++)
	{
		if(a[i]==x)
			k = i+1;
	}
	
	if(k==-1)
	 cout << "Khong tim thay x trong day!";
	else
		cout << "vi tri cua x: " << k;
}

int TK_NhiPhan(int A[], int N, int X) 
{
  int R = N - 1; 
  int L = 0; 
  while (R >= L) 
  {
	    int mid = (L + R) / 2; 
	 
	    if (A[mid] == X)
	      return mid;
	    if (A[mid] > X)
	      R = mid - 1;
	    if (A[mid] < X)
	      L = mid + 1;
  	}
  	return -1;
}
void VD3b()
{
	//Cho day a[n] da sap xep tang dan, tim xem trong day co gtri x hay ko
	//su dung TK nhi phan
	int n, a[100],  x;
	cout << "Nhap n: ";
	cin >> n;
	cout << "Nhap day a da sap xep tang dan: ";
	for (int i=0; i<n; i++)
	{
		cin >> a[i];
	}
	cout << "Nhap so can tim x= ";
	cin >> x;
	
	int k= TK_NhiPhan(a, n, x);
	
  	if(k==-1)
	 cout << "Khong tim thay x trong day!";
	else
		cout << "vi tri cua x: " << k+1;
}


int main()
{
	//VD1();
	VD2();
	//VD3a();
	//VD3b();
	return 0;
}
