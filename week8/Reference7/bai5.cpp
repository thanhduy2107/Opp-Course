#include <iostream>
using namespace std;

int main() {
    string s = "Hello";
    string r = s;
    string& ref = s;

    r += "!!!";
    ref += "??";

    cout << "s: " << s << endl;
    cout << "r: " << r << endl;
    cout << "ref: " << ref << endl;

    return 0;
}