#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int main() {

    // ==============================
    // 1. STUDENT PROFILE
    // ==============================

    string fullName;
    string studentID;
    string email;
    string hometown;

    cout << "===== 1. STUDENT PROFILE =====" << endl;

    cout << "Enter full name: ";
    getline(cin, fullName);

    cout << "Enter Student ID: ";
    getline(cin, studentID);

    cout << "Enter Email: ";
    getline(cin, email);

    cout << "Enter Hometown: ";
    getline(cin, hometown);

    cout << "\n===== STUDENT PROFILE =====" << endl;
    cout << "Full name : " << fullName << endl;
    cout << "Student ID: " << studentID << endl;
    cout << "Email     : " << email << endl;
    cout << "Hometown  : " << hometown << endl;
    cout << "===========================" << endl;


    // ==============================
    // 2. GREETING MESSAGE
    // ==============================

    string name;

    cout << "\n===== 2. GREETING MESSAGE =====" << endl;

    cout << "Enter your name: ";
    getline(cin, name);

    string message = "Hello, " + name + "!";
           message += "\nWelcome to C++ programming!";

    cout << message << endl;


    // ==============================
    // 3. INITIALS
    // ==============================

    cout << "\n===== 3. INITIALS =====" << endl;

    string initials = ""; 

    if (!fullName.empty()) { // !fullName.empty() là kiểm tra xem chuỗi fullName có rỗng hay không
        initials += toupper(fullName[0]); // Lấy chữ cái đầu tiên của tên và chuyển sang chữ hoa
    }

    for (int i = 1; i < fullName.length(); i++) {

        if (fullName[i - 1] == ' ' && fullName[i] != ' ') { // Kiểm tra nếu ký tự trước là khoảng trắng và ký tự hiện tại không phải là khoảng trắng
            initials += '.'; // Thêm dấu chấm vào chuỗi initials
            initials += toupper(fullName[i]); // Lấy chữ cái đầu tiên của từ tiếp theo và chuyển sang chữ hoa
        }
    }

    cout << "Initials: " << initials << endl;


    // ==============================
    // 4. FIND A WORD
    // ==============================

    string sentence;
    string word;

    cout << "\n===== 4. FIND A WORD =====" << endl;

    cout << "Enter a sentence: ";
    getline(cin, sentence);

    cout << "Enter a word to find: ";
    getline(cin, word);

    size_t pos = sentence.find(word);

    if (pos != string::npos) {
        cout << "The word \"" << word
             << "\" is found at position "
             << pos << "." << endl;
    }
    else {
        cout << "The word \"" << word
             << "\" is not found." << endl;
    }


    // ==============================
    // 5. CREATE A USERNAME
    // ==============================

    int birthYear;

    cout << "\n===== 5. CREATE A USERNAME =====" << endl;

    cout << "Enter your birth year: ";
    cin >> birthYear;

    string username = "";

    // Remove spaces and convert letters to lowercase
    for (char c : fullName) {

        if (c != ' ') {
            username += tolower(c);
        }
    }

    // Add birth year
    username += to_string(birthYear);

    cout << "Username: " << username << endl;


    return 0;
}