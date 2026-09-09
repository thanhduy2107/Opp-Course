#include <iostream>
using namespace std;

int main() {
    int a, b;
    cin >> a >> b;

    int x = a;
    int y = b;

    while (y != 0) {
        // Tìm BCNN (Bội chung nhỏ nhất) của hai số a và b
        int r = x % y; // x % y là phần dư của phép chia x cho y
        x = y; // x = y, tiếp tục tìm BCNN với y và phần dư r
        y = r; // Khi y = r, nếu r = 0 thì x là BCNN, nếu r != 0 thì tiếp tục vòng lặp
    }

    int gcd = x; // GCD (Greatest Common Divisor) là ước chung lớn nhất của hai số a và b, được tìm thấy bằng thuật toán Euclid. Khi vòng lặp kết thúc, x sẽ chứa giá trị GCD.
    int lcm = a * b / gcd; // BCNN (Least Common Multiple) được tính bằng công thức: BCNN(a, b) = (a * b) / GCD(a, b)

    cout << "BCNN = " << lcm;

    return 0;
}