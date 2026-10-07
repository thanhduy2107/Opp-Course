#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Food {
private:
    string id;
    string name;
    double price;
    int quantity;
public:
    Food(string id, string name, double price, int quantity); // constructor
    void input(); // nhập thông tin
    void display() const; // hiển thị thông tin
    void setPrice(double newPrice); // cập nhật giá
    bool reduceQuantity(int amount); // giảm số lượng
    bool isAvailable() const; // kiểm tra còn hàng
    string getId() const; // lấy mã món
    string getName() const; // lấy tên món
    double getPrice() const; // lấy giá món
    int getQuantity() const; // lấy số lượng
};

// Định nghĩa các hàm của class Food
Food::Food(string id, string name, double price, int quantity) { // Dấu 2 chấm (::) để định nghĩa hàm thành viên của lớp Food
    this->id = id;
    this->name = name;
    this->price = price;
    this->quantity = quantity;
}

void Food::input() { // Dấu 2 chấm (::) để định nghĩa hàm thành viên của lớp Food
    cout << "Nhập mã món: ";
    cin >> id;
    cout << "Nhập tên món: ";
    cin.ignore();
    getline(cin, name);
    cout << "Nhập giá: ";
    cin >> price;
    cout << "Nhập số lượng: ";
    cin >> quantity;
}

void Food::display() const { // Dấu 2 chấm (::) để định nghĩa hàm thành viên của lớp Food
    cout << "Mã món: " << id << endl;
    cout << "Tên món: " << name << endl;
    cout << "Giá: " << price << endl;
    cout << "Số lượng: " << quantity << endl;
}

void Food::setPrice(double newPrice) { // Dấu 2 chấm (::) để định nghĩa hàm thành viên của lớp Food
    if (newPrice > 0)
        price = newPrice;
}

bool Food::reduceQuantity(int amount) { // Dấu 2 chấm (::) để định nghĩa hàm thành viên của lớp Food
    if (amount > 0 && quantity >= amount) {
        quantity -= amount;
        return true;
    }
    return false;
}

bool Food::isAvailable() const { // Dấu 2 chấm (::) để định nghĩa hàm thành viên của lớp Food
    return quantity > 0;
}

string Food::getId() const { return id; } // Dấu 2 chấm (::) để định nghĩa hàm thành viên của lớp Food
string Food::getName() const { return name; }
double Food::getPrice() const { return price; }
int Food::getQuantity() const { return quantity; }

// Chương trình main
int main() {
    Food f1("F001", "Burger", 30000, 50);
    Food f2("F002", "Pizza", 50000, 30);

    f1.display(); // gọi hàm public
    f2.display();

    cout << "Nhập thông tin món ăn mới: " << endl;
    Food f3("", "", 0, 0);
    f3.input();
    f3.display();

    f1.setPrice(35000);
    f1.reduceQuantity(10);
    cout << "Sau khi cập nhật món ăn: " << endl;
    f1.display();

    return 0;
}
