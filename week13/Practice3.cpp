#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
using namespace std;

// ===== Lớp Employee =====
class Employee {
protected:
    string cccd;
    string sdt;
    string address;
public:
    Employee(string c, string s, string a) : cccd(c), sdt(s), address(a) {}
    void displayInfo() const {
        cout << "CCCD: " << cccd << endl;
        cout << "SDT: " << sdt << endl;
        cout << "Address: " << address << endl;
    }
    string getAddress() const { return address; }
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
    vector<HourlyEmployee> dsHourly = {
        HourlyEmployee("079876543212", "0909988776", "Da Nang", 160, 50000),
        HourlyEmployee("079111111111", "0901111111", "Ha Noi", 180, 60000)
    };

    vector<MonthlyEmployee> dsMonthly = {
        MonthlyEmployee("079987654321", "0903040405", "Da Nang", 20000000, 2000000, 1.2),
        MonthlyEmployee("079222222222", "0902222222", "Ho Chi Minh", 15000000, 1000000, 0.8)
    };

    // Hiển thị danh sách
    cout << "--- Danh sách HourlyEmployee ---" << endl;
    for (auto &h : dsHourly) { h.displayInfo(); cout << endl; }

    cout << "--- Danh sách MonthlyEmployee ---" << endl;
    for (auto &m : dsMonthly) { m.displayInfo(); cout << endl; }

    // 1. Tổng lương
    double tongLuong = 0;
    for (auto &h : dsHourly) tongLuong += h.tinhLuong();
    for (auto &m : dsMonthly) tongLuong += m.tinhLuong();
    cout << ">>> Tổng lương: " << tongLuong << endl;

    // 2. Tìm cao nhất / thấp nhất
    Employee* maxNV = nullptr; Employee* minNV = nullptr;
    double maxLuong = -1e9, minLuong = 1e9;

    for (auto &h : dsHourly) {
        if (h.tinhLuong() > maxLuong) { maxLuong = h.tinhLuong(); maxNV = &h; }
        if (h.tinhLuong() < minLuong) { minLuong = h.tinhLuong(); minNV = &h; }
    }
    for (auto &m : dsMonthly) {
        if (m.tinhLuong() > maxLuong) { maxLuong = m.tinhLuong(); maxNV = &m; }
        if (m.tinhLuong() < minLuong) { minLuong = m.tinhLuong(); minNV = &m; }
    }

    cout << "\n>>> Nhân viên lương cao nhất:" << endl;
    if (maxNV) maxNV->displayInfo();
    cout << "\n>>> Nhân viên lương thấp nhất:" << endl;
    if (minNV) minNV->displayInfo();

    // 3. Đếm số lượng
    cout << "\n>>> Số lượng HourlyEmployee: " << dsHourly.size() << endl;
    cout << ">>> Số lượng MonthlyEmployee: " << dsMonthly.size() << endl;

    // 4. Tìm nhân viên ở Da Nang
    cout << "\n>>> Nhân viên ở Da Nang:" << endl;
    for (auto &h : dsHourly) if (h.getAddress() == "Da Nang") h.displayInfo();
    for (auto &m : dsMonthly) if (m.getAddress() == "Da Nang") m.displayInfo();

    // 5. Lương trung bình
    double avgLuong = tongLuong / (dsHourly.size() + dsMonthly.size());
    cout << "\n>>> Nhân viên có lương > trung bình (" << avgLuong << "):" << endl;
    cout << fixed << setprecision(2);
    for (auto &h : dsHourly) if (h.tinhLuong() > avgLuong) h.displayInfo();
    for (auto &m : dsMonthly) if (m.tinhLuong() > avgLuong) m.displayInfo();

    // 6. Sắp xếp giảm dần theo lương
    vector<pair<double, Employee*>> all;
    for (auto &h : dsHourly) all.push_back({h.tinhLuong(), &h});
    for (auto &m : dsMonthly) all.push_back({m.tinhLuong(), &m});

    sort(all.begin(), all.end(), [](auto &a, auto &b) {
        return a.first > b.first;
    });

    cout << "\n>>> Danh sách nhân viên sắp xếp theo lương giảm dần:" << endl;
    for (auto &p : all) {
        p.second->displayInfo();
        cout << "Lương: " << fixed << setprecision(2) << p.first << endl << endl;
    }

    return 0;
}

