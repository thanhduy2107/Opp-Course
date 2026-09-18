#include <iostream>
#include <string>
using namespace std;

string fullname;
string studentID;
string email;
string hometown;

int main()
{
    cout << "Enter your full name: ";
    getline(cin, fullname);

    cout << "Enter your student ID: ";
    getline(cin, studentID);

    cout << "Enter your email: ";
    getline(cin, email);

    cout << "Enter your hometown: ";
    getline(cin, hometown);
    

    cout << "\n=== STUDENT INFO ===\n";
    cout << "Full Name : " << fullname << endl;
    cout << "Student ID: " << studentID << endl;
    cout << "Email     : " << email << endl;
    cout << "Hometown  : " << hometown << endl;

    return 0;
}
