#include <iostream>
#include <vector>
using namespace std;

class Food {
public:
    string id;
    string name;
    double price;
    int quantity;

    void input() {
        cout << "Nhap ten: ";
        getline(cin, name);
        cout << "Nhap gia: ";
        cin >> price;
        cin.ignore(); // Xóa ký tự newline còn lại trong bộ đệm
        quantity = 0;
    }

    void display() {
        cout << name << " - "
             << price << " (" << quantity << ")" << endl;
    }
};

int main() {
    vector<Food> menu(3); // Tạo danh sách 3 món ăn

    // Nhap 3 mon an
    for (int i = 0; i < 3; i++) {
        menu[i].input(); // Gọi hàm input() để nhập thông tin món ăn
    }

    cout << "\n=== Danh sach mon an ===\n";
    for (auto &f : menu) { // Dùng reference để tránh copy 
        f.display();
    }

    // Tim mon an theo ten
    string searchName;
    cout << "\nNhap ten mon an can tim: ";
    getline(cin, searchName);

    bool found = false; 
    for (auto &f : menu) { // Dùng reference để có thể cập nhật giá
        if (f.name == searchName) {
            cout << "Tim thay: ";
            f.display();
            found = true;

            // Cap nhat gia
            cout << "Nhap gia moi: ";
            cin >> f.price;
            cout << "Gia da cap nhat!\n";
            break; // Dừng vòng lặp sau khi tìm thấy món ăn
        }
    }

    if (!found) {
        cout << "Khong tim thay mon an.\n";
    }

    cout << "\n=== Danh sach sau cap nhat ===\n";
    for (auto &f : menu) {
        f.display();
    }

    return 0;
}
