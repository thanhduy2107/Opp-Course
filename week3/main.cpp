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

    // Nhập dữ liệu cho 20 sinh viên
    for (int i = 0; i < 20; i++)
    {

        cout << "==============================" << "\n";
        cout << "Nhập thông tin sinh viên" << "\n";
        cout << "==============================" << "\n";
        cout << "Nhập thông tin cho sinh viên thứ " << (i + 1) << "\n";

        cout << "Nhập tên sinh viên " << ": ";
        getline(cin, names[i]);
       
        cout << "Nhập ID cho sinh viên thứ " << (i + 1) << ": ";
        getline(cin, ids[i]);

        cout << "Nhập số điện thoại cho sinh viên thứ " << (i + 1) << ": ";
        getline(cin, phones[i]);
    }
    cout << "Tổng số học sinh đã nhập: " << N << endl;
    
    // Hiển thị thông tin của 20 sinh viên
    for (int i = 0; i < 20; i++)
    {
        cout << "==============================" << "\n";
        cout << "Thông tin sinh viên thứ " << (i + 1) << "\n";
        cout << "Tên: " << names[i] << "\n";
        cout << "ID: " << ids[i] << "\n";
        cout << "Số điện thoại: " << phones[i] << "\n";
    }


    return 0;
}
