#include <iostream>
using namespace std;

int main() {
    string s = "Hello";
    string& r = s;

    r += " World";

    cout << s << endl;
    cout << r << endl;

    return 0;
}
