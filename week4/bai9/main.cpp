#include <iostream>
using namespace std;

int main() {
    int x, n;
    cout << "Nhap so : ";
    cin >> x;
    cout << "Nhap so mu: ";
    cin >> n;
    

    long long result = 1;

    for (int i = 1; i <= n; i++) {
        result = result * x; // Tính lũy thừa của x^n bằng cách nhân x với chính nó n lần
    }

    cout << " Luy thua của " << x << "^" << n << " la: " << result;

    return 0;
}