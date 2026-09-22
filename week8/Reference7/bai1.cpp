#include <iostream>
using namespace std;

int main() {
    string s = "Hello";
    string& r = s; // r là reference của s, đảm bảo rằng biến được truyền vào không bị sao chép và có thể được sửa đổi trực tiếp

    r += " World"; // Thay đổi giá trị của r cũng sẽ thay đổi giá trị của s

    cout << s << endl;
    cout << r << endl;

    return 0;
}
