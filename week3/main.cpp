#include <iostream>
#include <string>
using namespace std;

int main()
{
    const int N = 20;

    // Tạo 3 mảng
    string names[N];
    string ids[N];
    string phones[N];

    // Nhập dữ liệu cho 3 sinh viên đầu tiên
    names[0] = "Nguyen Van A";
    ids[0] = "23110001";
    phones[0] = "0901234567";

    names[1] = "Tran Thi B";
    ids[1] = "23110002";
    phones[1] = "0912345678";

    names[2] = "Le Van C";
    ids[2] = "23110003";
    phones[2] = "0923456789";

    names[3] = "Pham Thi D";
    ids[3] = "23110004";
    phones[3] = "0934567890";

    names[4] = "Hoang Van E";
    ids[4] = "23110005";
    phones[4] = "0945678901";


    // In dữ liệu
    cout << "Student 1: "
         << names[0] << " - "
         << ids[0] << " - "
         << phones[0] << endl;

    cout << "Student 2: "
         << names[1] << " - "
         << ids[1] << " - "
         << phones[1] << endl;

    cout << "Student 3: "
         << names[2] << " - "
         << ids[2] << " - "
         << phones[2] << endl;

    cout << "Student 4: "
         << names[3] << " - "
         << ids[3] << " - "
         << phones[3] << endl;

    cout << "Student 5: "
            << names[4] << " - "
            << ids[4] << " - "
            << phones[4] << endl;
            

    return 0;
}