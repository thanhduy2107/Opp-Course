#include <iostream>
using namespace std;

void addExclaim(string& str) { // str là reference đến biến str, đảm bảo rằng biến được truyền vào không bị sao chép và có thể được sửa đổi trực tiếp
    str += "!!!";
}

int main() {
    string msg = "Good Day";
    addExclaim(msg); // Gọi hàm addExclaim để thêm dấu chấm than vào msg

    cout << msg << endl;

    return 0;
}
