#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

// ===== Lớp Employee =====
class Employee {
protected:
    string cccd;
    string sdt;
    string address;
public:
    Employee() : cccd(""), sdt(""), address("") {}
    Employee(string c, string s, string a) : cccd(c), sdt(s), address(a) {}

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
    HourlyEmployee() : Employee(), soGioLamViec(0), donGia(0.0) {}
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
    MonthlyEmployee() : Employee(), luongCoBan(0.0), phuCap(0.0), heSoThuong(0.0) {}
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
    Employee e("079123456789", "0901200343", "Ho Chi Minh");
    HourlyEmployee h("079876543212", "0909988776", "Da Nang", 160, 50000);
    MonthlyEmployee m("079987654321", "0903040405", "Ha Noi", 20000000, 2000000, 1.2);

    cout << "--- Thông tin Employee ---" << endl;
    e.displayInfo();
    cout << endl;

    cout << "--- Thông tin HourlyEmployee ---" << endl;
    h.displayInfo();
    cout << endl;

    cout << "--- Thông tin MonthlyEmployee ---" << endl;
    m.displayInfo();
    cout << endl;

    return 0;
}
