#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    int sum = 0;
// Kiểm tra xem n có phải là số hoàn hảo hay không
// Số hoàn hảo là số mà tổng các ước số của nó (ngoại trừ chính nó) bằng chính nó
    for (int i = 1; i < n; i++) {
        if (n % i == 0) {
            sum = sum + i;
        }
    }
// Nếu sum = n thì n là số hoàn hảo.
    if (sum == n)
        cout << n << " la so hoan hao";
    else
        cout << n << " khong phai so hoan hao";

    return 0;
}