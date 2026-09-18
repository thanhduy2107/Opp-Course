#include <iostream>
using namespace std;

int main() {

    int x = 10;
    int& rx = x; // & là địa chỉ của biến x, rx là một tham chiếu đến x;
    rx = 20;
    cout << "x = " << x << endl;
    cout << "rx = " << rx << endl;

    return 0;
}
