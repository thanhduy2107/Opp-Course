#include <iostream>
#include <string>
using namespace std;

int main() {

    // 1. Declare and Initialize Strings
    string s1 = "Hello";
    string s2 = "C++";

    cout << "1. Declare and Initialize Strings:" << endl;
    cout << s1 << endl;
    cout << s2 << endl;

    // 2. Input a String
    string name;

    cout << "\n2. Input a String:" << endl;
    cout << "Enter your name: ";
    getline(cin, name);

    cout << "Hello, " << name << "!" << endl;

    // 3. String Concatenation
    string first = "Hello";
    string second = "World";

    string message = first + " " + second + "!";

    cout << "\n3. String Concatenation:" << endl;
    cout << message << endl;

    // 4. Get String Length
    string s = "Hello C++";

    cout << "\n4. String Length:" << endl;
    cout << "Length: " << s.length() << endl;

    // 5. Access a Character
    cout << "\n5. Access a Character:" << endl;
    cout << "First character: " << s[0] << endl;
    cout << "Third character: " << s[2] << endl;

    // 6. Find a Substring
    string text = "I love C++";

    size_t pos = text.find("C++");

    cout << "\n6. Find a Substring:" << endl;

    if (pos != string::npos) { // Check if substring is found 
        cout << "Found at position: " << pos << endl;
    }
    else {
        cout << "Not found!" << endl;
    }

    // 7. Get a Substring
    string text2 = "Hello C++ World";

    string part = text2.substr(6, 3);

    cout << "\n7. Get a Substring:" << endl;
    cout << part << endl;

    // 8. Compare Strings
    string str1 = "apple";
    string str2 = "apple";

    cout << "\n8. Compare Strings:" << endl;

    if (str1.compare(str2) == 0) { // Check if strings are equal
        cout << "The strings are equal." << endl;
    }
    else {
        cout << "The strings are different." << endl;
    }

    return 0;
}

