#include <iostream>
#include <string>
using namespace std;

const int MAX_AGE = 110;

int main() {
    string name;
    int age;

    cout << "What is your name? ";
    cin >> name;

    cout << "How old are you? ";
    cin >> age;

    cout << "Hello, " << name << "! You're " << age << " years old.";
    cout << "This is a simple C++ program." << "\n";

    return 0;
}
