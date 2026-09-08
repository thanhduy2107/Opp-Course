#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    int count = 0;

    while (n > 0) {
        count = count +1;
        // lấy chữ số cuối cùng của n,phép chia lấy dư (%) sẽ trả về phần dư của phép chia.
        // Ví dụ, nếu n = 123, thì digit = 3
        n /= 10;
    }

    cout << "So chu so: " << count;

    return 0;
}