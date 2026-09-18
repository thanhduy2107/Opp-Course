#include <iostream>
#include <string>
using namespace std;

int main() {

    // ==============================
    // 1. INSERT A STRING
    // ==============================

    string original = "Hello World!";
    string insertText = "C++";

    original.insert(6, insertText);

    cout << "===== 1. INSERT A STRING =====" << endl;
    cout << "Result: " << original << endl;


    // ==============================
    // 2. FIND A SUBSTRING
    // ==============================

    string text = "I love C++ programming";
    string substring = "C++";

    size_t pos = text.find(substring);

    cout << "\n===== 2. FIND A SUBSTRING =====" << endl;

    if (pos != string::npos) {
        cout << "Position: " << pos << endl;
    }
    else {
        cout << "Substring not found." << endl;
    }


    // ==============================
    // 3. COUNT CHARACTERS
    // ==============================

    string text2 = "Hello C++";

    int countAll = text2.length();
    int countWithoutSpaces = 0;

    for (char c : text2) {
        if (c != ' ') {
            countWithoutSpaces++;
        }
    }

    cout << "\n===== 3. COUNT CHARACTERS =====" << endl;
    cout << "Count all characters: " << countAll << endl;
    cout << "Count without spaces: " << countWithoutSpaces << endl;


    // ==============================
    // 4. REPLACE A SUBSTRING
    // ==============================

    string sentence = "I like Java";

    size_t javaPos = sentence.find("Java");

    if (javaPos != string::npos) {
        sentence.replace(javaPos, 4, "C++");
    }

    cout << "\n===== 4. REPLACE A SUBSTRING =====" << endl;
    cout << "Result: " << sentence << endl;


    // ==============================
    // 5. EXTRACT A SUBSTRING
    // ==============================

    string text3 = "Computer Science";

    int startPosition = 9;
    int length = 7;

    string result = text3.substr(startPosition, length);

    cout << "\n===== 5. EXTRACT A SUBSTRING =====" << endl;
    cout << "Result: " << result << endl;


    return 0;
}
