#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

// Kiểm tra xem n có phải là số đối xứng hay không
// Số đối xứng là số mà khi đảo ngược các chữ số của nó vẫn giữ nguyên giá trị
    int original = n;
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

    if (original == reverse)
        cout << "La so doi xung";
    else
        cout << "Khong phai so doi xung";

    return 0;
}