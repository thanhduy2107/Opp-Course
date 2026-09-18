// Step 2: Create a function to display the student ID
#include <iostream>
using namespace std;    
void showStudentID(int id)
{
    cout << "Student ID: " << id << endl;
}

int main()
{
    int id;

    cout << "Enter student ID: ";
    cin >> id;

    showStudentID(id);

    return 0;
}
