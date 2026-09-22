#include <iostream>
#include <algorithm>
using namespace std;

void toUpperCase(string& str) { // str là reference đến biến str, đảm bảo rằng biến được truyền vào không bị sao chép và có thể được sửa đổi trực tiếp
    for (char& c : str) {
        c = toupper(c);
    }
}

int main() {
    string text = "c++ is fun";

    toUpperCase(text);

    cout << text << endl;

    return 0;
}
