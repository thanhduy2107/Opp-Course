#include <iostream>
using namespace std;

void swapValues(int* x, int* y) { // * là con trỏ, x và y là địa chỉ của biến a và b
    int temp = *x; // *x là giá trị của biến a, *y là giá trị của biến b
    *x = *y;
    *y = temp;
}

int main() {
    int a = 5;
    int b = 10;
    cout << "Before: a = " << a << ", b = " << b << endl;
    swapValues(&a, &b); // & là địa chỉ của biến a và b, truyền địa chỉ của a và b vào hàm swapValues
    cout << "After:  a = " << a << ", b = " << b << endl;

    return 0;
}