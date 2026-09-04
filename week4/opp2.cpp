#include <iostream>
using namespace std;

void giaiphuongtrinhbac1( double a, double b) {
    if (a == 0) {
        if (b == 0) {
            cout << "Phuong trinh vo so nghiem" << endl;
        } else {
            cout << "Phuong trinh vo nghiem" << endl;
        }
    } else {
        double x = -b / a;
        cout << "Nghiem cua phuong trinh la: " << x << endl;
    }
}

int main() {
    double a, b;
    cout << "Nhap so a: ";
    cin >> a;
    cout << "Nhap so b: ";
    cin >> b;
    giaiphuongtrinhbac1(a, b);
    return 0;
}