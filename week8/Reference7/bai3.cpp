#include <iostream>
using namespace std;

void swapStr(string& a, string& b) {
    string temp = a;
    a = b;
    b = temp;
}

int main() {
    string x = "cat";
    string y = "dog";

    swapStr(x, y);

    cout << x << " " << y << endl;

    return 0;
}