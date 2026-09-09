#include <iostream>
#include <string>
using namespace std;

int main()
{
    int N;

    // Nhập số lượng sinh viên N trong khoảng 2 đến 20
    do {
        cout << "Nhập số lượng sinh viên (2 đến 20): ";
        cin >> N;
        if (N < 2 || N > 20) {
            cout << "Đầu vào không hợp lệ! Vui lòng nhập một số từ 2 đến 20.\n";
        }
    } while (N < 2 || N > 20);

    // Xóa bộ nhớ đệm sau khi nhập số nguyên N
    cin.ignore();
     
    for (int i = 0; i < N; i++) {
        cout << "===========================================\n";
        cout << "=====ĐIỂM CỦA SINH VIÊN  =====\n";
        cout << "===========================================\n";
        cout << "Nhập điểm của sinh viên thứ " << i + 1 << ": ";
        int score;
        cin >> score;   
    if ( 0 <= score && score <= 10) {
        cout << "Điểm của sinh viên " << i + 1 << ": " << score << endl;
    } else {
        cout << "Số điểm không hợp lệ! Vui lòng nhập điểm từ 0 đến 10.\n";
        i--; // Giảm chỉ số i để nhập lại điểm cho sinh viên hiện tại 
    }
    
    }
     
    return 0;
}
     
    