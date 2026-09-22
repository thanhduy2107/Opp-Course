#include <iostream>
using namespace std;

void changeFirstChar(string& str) {
    str[0] = 'J';
}

int main() {
    string name = "python";

    changeFirstChar(name);

    cout << name << endl;

    return 0;
}
