#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    int reverse = 0;

    while (n > 0) {
        // Lấy chữ số cuối cùng của n,phép chia lấy dư (%) sẽ trả về phần dư của phép chia.
        // Ví dụ, nếu n = 123, thì digit = 3
        int digit = n % 10;
        // Thêm chữ số này vào số đảo ngược
        // Ví dụ, nếu reverse = 0, thì reverse = 0 * 10 + 3 = 3
        reverse = reverse * 10 + digit;
        // Loại bỏ chữ số cuối cùng của n
        // Ví dụ, nếu n = 123, thì n = 123 / 10 = 12
        n /= 10;
    }

    cout << "So dao nguoc: " << reverse;

    return 0;
}