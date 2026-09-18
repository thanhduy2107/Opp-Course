#include <iostream>
using namespace std;

int main() {
    int a = 5;
    int& r = a;  // r là reference của a
    r = 10;  // thay đổi a thông qua r
    cout << a << endl;
    cout << r << endl;

// Using 
    int x = 3;
    int& y = x;

    x = 7;
    y = 2;

    cout << x << " " << y << endl;

    return 0;
}
