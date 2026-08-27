#include <iostream>
#include <string>
using namespace std;

int main()
{
    // Header
    cout << "==============================" << "\n";
    cout << "       MY FIRST C++ APP" << "\n";
    cout << "==============================" << "\n\n";

    // Student Information
    string name = "Thanh Duy";
    string school = "HCMUTE";
    string major = "Automotive Engineering";
    int startYear = 2025;
    int currentYear = 2026;

    // Constant
    const int MAX_AGE = 120;

    // Other data types
    int age = 19;
    double gpa = 8.5;
    char grade = 'A';

    // Calculations
    int birthYear = currentYear - age;
    int nextAge = age + 1;

    // Updating a variable
    int score = 80;
    score = 90;

    // Display information
    cout << "Name        : " << name << "\n";
    cout << "School      : " << school << "\n";
    cout << "Major       : " << major << "\n";
    cout << "Age         : " << age << "\n";
    cout << "GPA         : " << gpa << "\n";
    cout << "Grade       : " << grade << "\n\n";

    cout << "Birth Year  : " << birthYear << "\n";
    cout << "Next Age    : " << nextAge << "\n";

    cout << "Initial Score : 80\n";
    cout << "Updated Score : " << score << "\n";

    cout << "\nGoal: Become a better programmer!\n";

    cout << "==============================" << "\n";

    return 0;
}