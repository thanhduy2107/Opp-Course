#include <iostream>
#include <string>
using namespace std;

void showScore(string name, double score)
{
    cout << "Student: " << name << endl;
    cout << "Score  : " << score << endl;

    if (score >= 5)
    {
        cout << "Keep going!" << endl;
    }
    else
    {
        cout << "Try harder!" << endl;
    }
}

int main()
{
    string studentName;
    double studentScore;

    cout << "Enter student name: ";
    getline(cin, studentName);

    cout << "Enter student score: ";
    cin >> studentScore;

    showScore(studentName, studentScore);

    return 0;
}