#include <iostream>
using namespace std;

// Nhập các số a,b,c
int main() {
    int a, b, c;
    cout << "Nhap 3 so nguyen: ";
    cin >> a >> b >> c;


    int max = a;

    if (b > max)
        max = b;

    if (c > max)
        max = c;
    // In ra số lớn nhất

    cout << "So lon nhat: " << max;

    return 0;
}