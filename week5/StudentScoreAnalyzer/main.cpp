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
    
    double scores[20]; // Mảng để lưu trữ điểm của sinh viên
    for (int i = 0; i < N; i++) {
        do {
        cout << "Nhập điểm của sinh viên thứ " << i + 1 << ": ";
        cin >> scores[i];   
        if (scores[i] < 0 || scores[i] > 10) {
            cout << "Số điểm không hợp lệ! Vui lòng nhập điểm từ 0 đến 10.\n";
            i--; // Giảm chỉ số i để nhập lại điểm cho sinh viên hiện tại 
        }
     } while (scores[i] < 0 || scores[i] > 10);
    
    }

    
// Hiển thị danh sách điểm của sinh viên
    cout << endl;
    cout << "===== ĐIỂM SINH VIÊN =====" << endl;

    for (int i = 0; i < N; i++) {
        cout << "Sinh viên " << i + 1 << ": " << scores[i] << endl;
    }


    // Bước 4: Kiểm tra PASS / FAIL
    cout << endl;
    cout << "===== KẾT QUẢ =====" << endl;

    for (int i = 0; i < N; i++) {

        if (scores[i] >= 5) {
            cout << "Sinh viên " << i + 1 << ": "
                 << scores[i] << " -> ĐẠT" << endl;
        }
        else {
            cout << "Sinh viên " << i + 1 << ": "
                 << scores[i] << " -> KHÔNG ĐẠT" << endl;
        }
    }

  