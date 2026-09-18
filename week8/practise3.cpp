#include <iostream>
#include <string>
using namespace std;

int main() {

    // 1. Get Length (length() and size())
    string s = "Hello C++";

    cout << "1. Get Length:" << endl;
    cout << s.length() << endl;
    cout << s.size() << endl;


    // 2. Check if Empty (empty())
    string s1 = "";
    string s2 = "Hi";

    cout << "\n2. Check if Empty:" << endl;
    cout << s1.empty() << endl;
    cout << s2.empty() << endl;


    // 3. Find a Substring (find())
    string text = "I love C++";

    size_t pos = text.find("C++");

    cout << "\n3. Find a Substring:" << endl;

    if (pos != string::npos) {
        cout << "Found at: " << pos << endl;
    }
    else {
        cout << "Not found!" << endl;
    }


    // 4. Get a Substring (substr())
    string s3 = "Hello World";

    string part1 = s3.substr(0, 5);
    string part2 = s3.substr(6, 5);

    cout << "\n4. Get a Substring:" << endl;
    cout << part1 << endl;
    cout << part2 << endl;


    // 5. Append Text (append())
    string s4 = "Hello";

    s4.append(" C++");

    cout << "\n5. Append Text:" << endl;
    cout << s4 << endl;


    // 6. Insert Text (insert())
    string s5 = "Hello World";

    s5.insert(5, ", C++");

    cout << "\n6. Insert Text:" << endl;
    cout << s5 << endl;


    // 7. Erase Characters (erase())
    string s6 = "Hello World";

    s6.erase(5, 6);

    cout << "\n7. Erase Characters:" << endl;
    cout << s6 << endl;


    // 8. Replace Text (replace())
    string s7 = "I like Java";

    s7.replace(7, 4, "C++"); // 7 is the starting index, 4 is the length of the substring to be replaced

    cout << "\n8. Replace Text:" << endl;
    cout << s7 << endl;


    // 9. Compare Strings (compare())
    string str1 = "apple";
    string str2 = "apple";
    string str3 = "banana";

    cout << "\n9. Compare Strings:" << endl;
    cout << str1.compare(str2) << endl;
    cout << str1.compare(str3) << endl;
    cout << str3.compare(str1) << endl;


    return 0;
}
