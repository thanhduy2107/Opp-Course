#include <iostream>
#include <string>
#include <cfloat>
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
    cout << "===== EXCELLENT STUDENTS =====" << endl;
    cout << "Number of excellent students: " << excellent << endl;

    
    // Đếm số học sinh trong khoảng điểm
    double a, b; // biến để lưu trữ khoảng điểm, điểm thập phân
    int rangeCount = 0;

    cout << endl;
    cout << "===== SCORE RANGE =====" << endl;

    cout << "Enter minimum score: ";
    cin >> a;

    cout << "Enter maximum score: ";
    cin >> b;

    // Nếu người dùng nhập ngược
    if (a > b) {
        double temp = a; // Lưu giá trị của a vào biến tạm thời
        a = b; // Gán giá trị của b cho a
        b = temp; // Gán giá trị của biến tạm thời cho b
    }

    for (int i = 0; i < N; i++) {
        if (scores[i] >= a && scores[i] <= b) {
            rangeCount++;
        }
    }
    cout << "Students in range: " << rangeCount << endl;

    // Tính điểm trung bình và liệt kê sinh viên có điểm trên trung bình
 double sum = 0;

    for (int i = 0; i < N; i++) {
        sum += scores[i];
    }

    double average = sum / N;

    cout << endl;
    cout << "=====  ABOVE AVERAGE =====" << endl;
    cout << "Average score: " << average << endl;

    cout << "Students above average:" << endl;

    for (int i = 0; i < N; i++) {
        if (scores[i] > average) {
            cout << "Student " << i + 1 << ": " << scores[i] << endl;
        }
    }

// Tìm sinh viên có điểm cao thứ hai
 double secondHighest = -1; // Khởi tạo biến secondHighest với giá trị -1 để kiểm tra nếu không có điểm cao thứ hai

    for (int i = 1; i < N; i++) {

        if (scores[i] > highest) { // Nếu điểm hiện tại lớn hơn điểm cao nhất
            secondHighest = highest; // Cập nhật secondHighest với giá trị của highest trước đó
            highest = scores[i]; // Cập nhật highest với giá trị điểm hiện tại
        }
        else if (scores[i] > secondHighest && scores[i] < highest) {
            secondHighest = scores[i];
        }
    }

    cout << endl;
    cout << "===== HIGHEST SCORES =====" << endl;
    cout << "Highest score: " << highest << endl;

    if (secondHighest != -1) {
        cout << "Second highest score: "
             << secondHighest << endl;
    }
    else {
        cout << "There is no second different score."
             << endl;
    }


    // Tìm kiếm điểm của sinh viên
double x; // Biến để lưu trữ điểm cần tìm kiếm
    bool found = false; // Biến để kiểm tra xem điểm có được tìm thấy hay không

    cout << endl;
    cout << "===== SEARCH FOR A SCORE =====" << endl;

    cout << "Enter score to search: ";
    cin >> x;

    cout << "Found at:" << endl;

    for (int i = 0; i < N; i++) {

        if (scores[i] == x) {
            cout << "Student " << i + 1 << endl;
            found = true;
        }
    }

    if (!found) {
        cout << "Score not found." << endl;
    }

    // Tần suất xuất hiện của các điểm
     int frequency = 0; // Biến để đếm tần suất xuất hiện của điểm x

    cout << endl;
    cout << "===== SCORE FREQUENCY =====" << endl;

    cout << "Enter score: ";
    cin >> x;

    for (int i = 0; i < N; i++) {

        if (scores[i] == x) {
            frequency = frequency + 1; // Tăng biến đếm tần suất xuất hiện của điểm x
        }
    }

    cout << "Score " << x   << " appears " << frequency << " times." << endl;

    
    // Tìm sinh viên rớt môn đầu tiên
    bool failFound = false;

    cout << endl;
    cout << "===== FIRST FAILING STUDENT ====="
         << endl;

    for (int i = 0; i < N; i++) {

        if (scores[i] < 5) {

            cout << "First failing student:"
                 << endl;

            cout << "Student " << i + 1
                 << ": " << scores[i] << endl;

            failFound = true;

            break;
        }
    }

    if (!failFound) {
        cout << "All students pass!" << endl;
    }
