#include <iostream>
using namespace std;

int main() {
    int a = 5;
    int& r = a;  // r là reference của a
    r = 10;  // thay đổi a thông qua r
    cout << a << endl;
    cout << r << endl;

// Using a reference to modify a variable
    int x = 3;
    int& y = x; // y là reference của x, & là ký hiệu của reference
    x = 7; // thay đổi x thông qua y
    y = 2; 
    cout << x << " " << y << endl;

    return 0;
}
