#include <iostream>
using namespace std;

int main() {
    int a, b;
    cin >> a >> b;
// Tìm ước chung lớn nhất của hai số a và b
    while (b != 0) { // Sử dụng thuật toán Euclid để tìm ước chung lớn nhất
        // b != 0 nghĩa là còn số dư, tiếp tục chia
        int r = a % b;
        a = b;
        b = r;
    }

    cout << "Uoc chung lon nhat = " << a;

    return 0;
}