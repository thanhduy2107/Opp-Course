#include <iostream>
#include <string>
using namespace std;

int main()
{
    int N;

    // Nhập số lượng sinh viên N trong khoảng 2 đến 20
    do {
        cout << "Enter the number of students (2 to 20): ";
        cin >> N;
        if (N < 2 || N > 20) {
            cout << "Invalid input! Please enter a number between 2 and 20.\n";
        }
    } while (N < 2 || N > 20);

    // Xóa bộ nhớ đệm sau khi nhập số nguyên N
    cin.ignore();

    // Khai báo mảng để lưu trữ dữ liệu
    string names[20];
    string studentIDs[20];
    string phoneNumbers[20];

    // Vòng lặp nhập thông tin sinh viên
    cout << "\n--- ENTER STUDENT INFORMATION ---\n";
    for (int i = 0; i < N; i++) {
        cout << "\nStudent " << i + 1 << ":\n";
        
        cout << "  Name: ";
        getline(cin, names[i]);

        cout << "  ID: ";
        getline(cin, studentIDs[i]);

        cout << "  Phone: ";
        getline(cin, phoneNumbers[i]);
    }

    // In giao diện danh sách sinh viên
    cout << "\n========================================\n";
    cout << "            STUDENT LIST\n";
    cout << "========================================\n\n";

    // Vòng lặp in thông tin sinh viên
    for (int i = 0; i < N; i++) {
        cout << "Student " << i + 1 << ":\n";
        cout << "  Name:  " << names[i] << "\n";
        cout << "  ID:    " << studentIDs[i] << "\n";
        cout << "  Phone: " << phoneNumbers[i] << "\n\n";
    }

    return 0;

}