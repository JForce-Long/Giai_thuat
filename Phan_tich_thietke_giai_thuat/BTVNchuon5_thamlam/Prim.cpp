#include <iostream>
using namespace std;

int m = 25;
int n = 12;
struct canh
{
    int d;
    int c;
    int w;
};

void doicho(canh &a, canh &b)
{
    canh tmp = a;
    a = b;
    b = tmp;

}
void sapxep(canh a[])
{
    int i, j;
    for (i = 0; i < m - 1; i++)
    {
        for (j = i + 1; i< m; j++)
        {
            if (a[i].w > a[j].w)
            {
                doicho(a[i], a[j]);               
            }
        }
    }
}
void nhap(canh a[])
{
    for (int i = 0; i < m; i++)
    {
        cout << "Nhap dinh dau, dinh cuoi va trong so cua canh thu " << i + 1 << ": ";
        cin >> a[i].d >> a[i].c >> a[i].w;
    }
}
void khoitao(int daxet[])
{
    for (int i = 0; i < n; i++)
    {
        daxet[i] = 0;
    }
}
void Prim(canh E[], canh T[], int daxet[])
{
    int k, trong_so, j;
    k = 0; T[k] = E[0]; trong_so = E[0].w; daxet[E[0].d - 1] = 1; daxet[E[0].c - 1] = 1;
    while (k < n - 2)
    {
        j = 1; while (daxet[E[j].d - 1] == daxet[E[j].c - 1]) j++;
        k += 1; T[k] = E[j]; trong_so += T[k].w; daxet[E[j].d - 1] = 1; daxet[E[j].c - 1] = 1;
    }
}
void incaykhung(canh T[])
{
    for (int i = 0; i < n - 1; i++)
    {
        cout << T[i].d << " " << T[i].c << " " << T[i].w << endl;
    }
}
int main()
{
    canh E[11];
    canh T[7 - 1];
    int trong_so, k, j;
    int daxet[7];
    nhap(E);
    khoitao(daxet);
    sapxep(E);
    Prim(E, T, daxet);
    incaykhung(T);
    return 0;
    
}

