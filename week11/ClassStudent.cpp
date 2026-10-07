#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Date {
public:
    int year, month, day;
    Date() { year = 0; month = 0; day = 0; }
    Date(int y, int m, int d) { year = y; month = m; day = d; }
};

class Student {
private:
    string name;
    string address;  
    Date birthdate; // yyyy/mm/dd
    string cccd; 

public: 
    // ===== Constructors =====
    Student() {
        name = ""; address = ""; birthdate = Date(); cccd = "";
    }
    Student(string n) {
        name = n; address = ""; birthdate = Date(); cccd = "";
    }  
    Student(string n, string addr) {
        name = n; address = addr; birthdate = Date(); cccd = "";
    }
    Student(string n, string addr, Date d) {
        name = n; address = addr; birthdate = d; cccd = "";
    }
    Student(string n, string addr, Date d, string id) {
        name = n; address = addr; birthdate = d; cccd = id;
    }
    
    // ===== Methods =====
    void setStudentInfo(string n) { name = n; }
    void setStudentInfo(string n, string addr) { name = n; address = addr; }
    void setStudentInfo(string n, string addr, Date d) { name = n; address = addr; birthdate = d; }
    void setStudentInfo(string n, string addr, Date d, string id) { name = n; address = addr; birthdate = d; cccd = id; }

    void getStudentInfo() {
        cout << "====================" << endl;
        cout << "=== Student Info ===" << endl;
        cout << "====================" << endl;
        cout << "Name: " << name << endl;
        cout << "Address: " << address << endl;
        cout << "Birthdate: " << birthdate.year << "/" << birthdate.month << "/" << birthdate.day << endl;
        cout << "CCCD: " << cccd << endl;
        cout << "====================" << endl;
    }

    string getCCCD() { return cccd; }
    string getAddress() { return address; }
    int getBirthYear() { return birthdate.year; }
};

// ===== Helper Functions =====

// Tìm sinh viên theo địa chỉ
vector<Student> getStudentsByAddress(vector<Student> students, string addr) {
    vector<Student> result;
    for (auto &s : students) { // Duyệt qua từng sinh viên, gán con trỏ s vào từng phần tử của vector students
        if (s.getAddress() == addr) result.push_back(s);
    }
    return result;
}

// Thống kê số lượng sinh viên theo năm sinh
void countStudentsByYear(vector<Student> students) {
    cout << "\n===== Thong ke theo nam sinh =====\n";
    for (int year = 1999; year <= 2010; year++) {
        int count = 0;
        for (auto &s : students) { // Duyệt qua từng sinh viên, gán con trỏ s vào từng phần tử của vector students
            if (s.getBirthYear() == year) count++; // s.getBirthYear() gọi phương thức getBirthYear() của đối tượng Student mà con trỏ s đang trỏ tới
        }
        if (count > 0) {
            cout << "Nam " << year << ": " << count << " sinh vien\n";
        }
    }
}

// Thống kê theo tỉnh/thành phố
void countStudentsByProvince(vector<Student> students) {
    cout << "\n===== Thong ke theo dia chi =====\n";
    vector<string> provinces = {"Thu Duc", "Ha Noi", "Binh Duong", "Da Nang"};
    for (auto &p : provinces) { // Duyệt qua từng tỉnh/thành phố, gán con trỏ p vào từng phần tử của vector provinces
        int count = 0;
        for (auto &s : students) { // Duyệt qua từng sinh viên, gán con trỏ s vào từng phần tử của vector students
            if (s.getAddress() == p) count++;
        }
        if (count > 0) {
            cout << p << ": " << count << " sinh vien\n";
        }
    }
}

// ===== Main =====
int main() {
    Student student1;                          // không tham số
    Student student2("Huong");                 // 1 tham số
    Student student3("An", "Vo Van Ngan");     // 2 tham số

    Date d(2007, 11, 20);
    Student student4("Duy", "Thu Duc", d, "034123456789"); // 4 tham số

    Date d2(2005, 5, 15);
    Student student5("Hieu", "Binh Duong", d2, "034987654321"); // 4 tham số

    Date d3(2006, 8, 10);
    Student student6("Lan", "Ha Noi", d3, "034111222333"); // 4 tham số
     
    Date d4(2008, 3, 5);
    Student student7("Minh", "Da Nang", d4, "034444555666"); // 4 tham số

    vector<Student> students = {student2, student3, student4, student5, student6, student7};



    // In thông tin
    for (auto &s : students) s.getStudentInfo();

    // Nhập địa chỉ muốn tìm kiếm
    string addr;
    cout << "\nNhap dia chi muon tim kiem: ";
    getline(cin, addr); // dùng getline để nhập cả cụm từ

    vector<Student> found = getStudentsByAddress(students, addr);
    if (found.empty()) {
        cout << "Khong tim thay sinh vien nao o dia chi: " << addr << endl;
    } else {
        cout << "\nDanh sach sinh vien o dia chi " << addr << ":\n";
        for (auto &s : found) s.getStudentInfo();
    }

    // Thống kê
    countStudentsByYear(students);
    countStudentsByProvince(students);

    return 0;
}
