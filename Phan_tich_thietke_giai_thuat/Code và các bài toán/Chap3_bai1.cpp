#include <iostream>
using namespace std;

int main()
{
	int a1, b1, c1, a2, b2, c2;
	double d, dx, dy, x, y;
	
	cout << "Nhap a1: "; cin >> a1;
	cout << "Nhap b1: "; cin >> b1;
	cout << "Nhap c1: "; cin >> c1;
	
	cout << "Nhap a2: "; cin >> a2;
	cout << "Nhap b2: "; cin >> b2;
	cout << "Nhap c2: "; cin >> c2;
	
	d = a1*b2 - a2*b1;
	dx = c1*b2 - c2*b1;
	dy = a1*c2-a2*c1;
	
	if (d == 0) {
        if (dx + dy == 0)
            cout <<"He PT co vo so nghiem";
        else
            cout << "He PT vo nghiem";
    }
    else {
        x = dx / d;
        y = dy / d;
        cout << "He phuong trinh co nghiem: x= "<<x <<", y="<< y;
    }
    return 0;
}
