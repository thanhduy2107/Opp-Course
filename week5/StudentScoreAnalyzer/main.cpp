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


    // Kiểm tra PASS / FAIL
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

  // Tính tỷ lệ đỗ
  int đạt = 0;
    int không_đạt = 0;

    for (int i = 0; i < N; i++) {

        if (scores[i] >= 5) {
            đạt = đạt + 1; // Tăng biến đếm số sinh viên đỗ
        }
        else {
            không_đạt = không_đạt + 1; // Tăng biến đếm số sinh viên không đỗ
        }
    }

    double passRate = (double)đạt / N * 100;// Lấy số người đỗ/tổng số sinh viên*100 để ra tỷ lệ phần trăm
    cout << endl;
    cout << "===== STATISTICS =====" << endl;

    cout << "Đạt : " << đạt << " students" << endl;
    cout << "Không đạt : " << không_đạt << " students" << endl;
    cout << "Tỷ lệ đỗ: " << passRate << "%" << endl;

// Tìm sinh viên có điểm cao vào thấp nhất
 double highest = scores[0];
    double lowest = scores[0];

    for (int i = 1; i < N; i++) {

        if (scores[i] > highest) {
            highest = scores[i];
        }

        if (scores[i] < lowest) {
            lowest = scores[i];
        }
    }

    cout << endl;
    cout << "===== HIGHEST AND LOWEST =====" << endl;

    cout << "Highest score: " << highest << endl;
    cout << "Lowest score : " << lowest << endl;

cout << endl;
    cout << "===== CLASSIFICATION =====" << endl;

    for (int i = 0; i < N; i++) {

        cout << "Student " << i + 1 << ": "
             << scores[i] << " -> ";

        if (scores[i] >= 9) {
            cout << "Excellent";
        }
        else if (scores[i] >= 8) {
            cout << "Very Good";
        }
        else if (scores[i] >= 6.5) {
            cout << "Good";
        }
        else if (scores[i] >= 5) {
            cout << "Average";
        }
        else {
            cout << "Fail";
        }

        cout << endl;
    }

// Đếm số học sinh xuất xắc
    int excellent = 0;

    for (int i = 0; i < N; i++) {
        if (scores[i] >= 9) {
            excellent++;
        }
    }

    cout << endl;
    cout << "===== 1. EXCELLENT STUDENTS =====" << endl;
    cout << "Number of excellent students: " << excellent << endl;


    
    