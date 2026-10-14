#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

// ===== Lớp Employee =====
class Employee {
private:
    string cccd;
    string sdt;
    string address;
public:
    Employee() : cccd(""), sdt(""), address("") {}
    Employee(string c, string s, string a) : cccd(c), sdt(s), address(a) {}

    double tinhLuong() const { return 0.0; } // mặc định
    void displayInfo() const {
        cout << "CCCD: " << cccd << endl;
        cout << "SDT: " << sdt << endl;
        cout << "Address: " << address << endl;
    }
};

// ===== Lớp HourlyEmployee =====
class HourlyEmployee : public Employee {
private:
    int soGioLamViec;
    double donGia;
public:
    HourlyEmployee(string c, string s, string a, int g, double d)
        : Employee(c, s, a), soGioLamViec(g), donGia(d) {}

    double tinhLuong() const { return soGioLamViec * donGia; }

    void displayInfo() const {
        Employee::displayInfo();
        cout << "Số giờ làm việc: " << soGioLamViec << endl;
        cout << "Đơn giá: " << fixed << setprecision(2) << donGia << endl;
        cout << "Lương: " << fixed << setprecision(2) << tinhLuong() << endl;
    }
};

// ===== Lớp MonthlyEmployee =====
class MonthlyEmployee : public Employee {
private:
    double luongCoBan;
    double phuCap;
    double heSoThuong;
public:
    MonthlyEmployee(string c, string s, string a, double lcb, double pc, double hs)
        : Employee(c, s, a), luongCoBan(lcb), phuCap(pc), heSoThuong(hs) {}

    double tinhLuong() const { return luongCoBan + phuCap + (luongCoBan * heSoThuong); }

    void displayInfo() const {
        Employee::displayInfo();
        cout << "Lương cơ bản: " << fixed << setprecision(2) << luongCoBan << endl;
        cout << "Phụ cấp: " << fixed << setprecision(2) << phuCap << endl;
        cout << "Hệ số thưởng: " << fixed << setprecision(2) << heSoThuong << endl;
        cout << "Lương: " << fixed << setprecision(2) << tinhLuong() << endl;
    }
};

// ===== Hàm main =====
int main() {
    // Quản lý từng loại nhân viên riêng
    vector<Employee> dsEmployee;
    vector<HourlyEmployee> dsHourly;
    vector<MonthlyEmployee> dsMonthly;

    dsEmployee.push_back(Employee("079123456789", "0901200343", "Ho Chi Minh"));
    dsHourly.push_back(HourlyEmployee("079876543212", "0909988776", "Da Nang", 160, 50000));
    dsMonthly.push_back(MonthlyEmployee("079987654321", "0903040405", "Ha Noi", 20000000, 2000000, 1.2));

    cout << "--- Danh sách Employee ---" << endl;
    for (auto &e : dsEmployee) {
        e.displayInfo();
        cout << endl;
    }

    cout << "--- Danh sách HourlyEmployee ---" << endl;
    for (auto &h : dsHourly) {
        h.displayInfo();
        cout << endl;
    }

    cout << "--- Danh sách MonthlyEmployee ---" << endl;
    for (auto &m : dsMonthly) {
        m.displayInfo();
        cout << endl;
    }

    // Tính tổng lương
    double tongLuong = 0;
    for (auto &h : dsHourly) tongLuong += h.tinhLuong();
    for (auto &m : dsMonthly) tongLuong += m.tinhLuong();

    cout << ">>> Tổng lương của tất cả nhân viên: " << fixed << setprecision(2) << tongLuong << endl;

    return 0;
}
