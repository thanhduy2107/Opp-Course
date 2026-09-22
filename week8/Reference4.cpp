#include <iostream>
using namespace std;

int main() {
    // Bài 1
    int n = 7;
    int& r = n;
    r = 15;
    cout << n << " " << r << endl;

    // Bài 2
    int a = 10;
    int& x = a;
    x += 5;
    cout << a << endl;


    // Bài 3
    int b = 4;
    int c = 9;
    int& refB = b; // refB là reference của b
    int& refC = c; // refC là reference của c
    int temp = refB; // temp là biến tạm để lưu giá trị của refB
    refB = refC; // refB nhận giá trị của refC
    refC = temp; // refC nhận giá trị của temp (giá trị ban đầu của refB)
    cout << b << " " << c << endl;


    // Bài 4
    int d = 5;
    int copyD = d;  // Truyền giá trị: mô phỏng bằng biến copy
    copyD = 100;
    cout << "After changeValue: " << d << endl; 
    // Reference
    int& refD = d; // refD là reference của d
    refD = 200;
    cout << "After changeRef: " << d << endl;

    return 0;
}