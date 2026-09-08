#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
// Tính giai thừa của n
// long long để tránh tràn số khi n lớn,gt là biến lưu trữ kết quả giai thừa
    long long gt = 1;

    for (int i = 1; i <= n; i++) {
        gt = gt * i;
    }

    cout << n << "Giai thua cua " << n << " la: " << gt;

    return 0;
}