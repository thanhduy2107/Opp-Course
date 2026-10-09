#include <iostream>
#include <string>
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
    Date birthdate; 
    string cccd; 

public: 
    // ===== Constructors =====
    Student() { name = ""; address = ""; birthdate = Date(); cccd = ""; }
    Student(string n) { name = n; address = ""; birthdate = Date(); cccd = ""; }
    Student(string n, string addr) { name = n; address = addr; birthdate = Date(); cccd = ""; }
    Student(string n, string addr, Date d) { name = n; address = addr; birthdate = d; cccd = ""; }
    Student(string n, string addr, Date d, string id) { name = n; address = addr; birthdate = d; cccd = id; }

    // ===== Methods =====
    void setStudentInfo(string n, string addr, Date d, string id) {
        name = n; address = addr; birthdate = d; cccd = id;
    }

    void getStudentInfo() {
        cout << "====================" << endl;
        cout << "=== Student Info ===" << endl;
        cout << "====================" << endl;
        cout << "Name: " << name << endl;
        cout << "Address: " << address << endl;
        cout << "Birthdate: " << birthdate.year << "/" << birthdate.month << "/" << birthdate.day << endl;
        cout << "CCCD: " << cccd << endl;
    }

    string getAddress() { return address; }
    int getBirthYear() { return birthdate.year; }
};

// ===== Trả về mảng sinh viên theo năm sinh =====
Student* getStudentsByYear(Student students[], int n, int year, int &count) {
    count = 0;
    for (int i = 0; i < n; i++) {
        if (students[i].getBirthYear() == year) count++;
    }

    Student* result = new Student[count];
    int idx = 0;
    for (int i = 0; i < n; i++) {
        if (students[i].getBirthYear() == year) {
            result[idx] = students[i];
            idx++;
        }
    }
    return result;
}

// ===== Trả về mảng sinh viên theo địa chỉ =====
Student* getStudentsByAddress(Student students[], int n, string addr, int &count) {
    count = 0;
    for (int i = 0; i < n; i++) {
        if (students[i].getAddress() == addr) count++;
    }

    Student* result = new Student[count];
    int idx = 0;
    for (int i = 0; i < n; i++) {
        if (students[i].getAddress() == addr) {
            result[idx] = students[i];
            idx++;
        }
    }
    return result;
}

// ===== Hàm hiển thị danh sách sinh viên =====
void display(Student* arr, int count) {
    for (int i = 0; i < count; i++) {
        arr[i].getStudentInfo();
    }
}

// ===== Main =====
int main() {
    Date d1(2007, 11, 20);
    Date d2(2005, 5, 15);
    Date d3(2006, 1, 1);

    Student students[3] = {
        Student("Duy", "Thu Duc", d1, "111"),
        Student("Hieu", "Binh Duong", d2, "222"),
        Student("Lan", "Ha Noi", d3, "333")
    };

    cout << "\n=== Tat ca sinh vien ===\n";
    for (int i = 0; i < 3; i++) students[i].getStudentInfo();

    // Tìm theo năm sinh
    int countYear;
    Student* byYear = getStudentsByYear(students, 3, 2006, countYear);
    cout << "\n=== Danh sach sinh vien nam 2006 ===\n";
    display(byYear, countYear);
    delete[] byYear;

    // Tìm theo địa chỉ (nhập từ bàn phím)
    string addr;
    cout << "\nNhap dia chi muon tim kiem: ";
    getline(cin, addr);

    int countAddr;
    Student* byAddr = getStudentsByAddress(students, 3, addr, countAddr);
    if (countAddr == 0) {
        cout << "Khong tim thay sinh vien nao o dia chi: " << addr << endl;
    } else {
        cout << "\n=== Danh sach sinh vien o " << addr << " ===\n";
        display(byAddr, countAddr);
    }
    delete[] byAddr;

    return 0;
}
