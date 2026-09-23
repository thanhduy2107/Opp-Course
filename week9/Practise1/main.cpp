#include <iostream>
#include <string>
using namespace std;

const int MAX_FOOD = 100;
const int MAX_ORDER = 100;
const int MAX_ITEM = 20;

struct Food {
    string id;
    string name;
    double price;
    int quantity;
};

struct OrderItem {
    string foodId;
    int quantity;
};

struct Order {
    string id;
    string customerName;
    string address;

    OrderItem items[MAX_ITEM];
    int itemCount;

    string status;
};


struct Restaurant {
    string name;
    string address;
    string phone;

    Food food[MAX_FOOD];
    int foodCount;

    Order orders[MAX_ORDER];
    int orderCount;
};

// ======================================================
// 1. NHẬP THÔNG TIN CỬA HÀNG
// ======================================================

void inputRestaurant(Restaurant& restaurant) {

    cin.ignore();

    cout << "Nhap ten cua hang: ";
    getline(cin, restaurant.name);

    cout << "Nhap dia chi: ";
    getline(cin, restaurant.address);

    cout << "Nhap so dien thoai: ";
    getline(cin, restaurant.phone);

    restaurant.foodCount = 0;
    restaurant.orderCount = 0;

    cout << "Nhap thong tin cua hang thanh cong!\n";
}

// ======================================================
// 2. THÊM MÓN ĂN MỚI
// ======================================================

void addFood(Restaurant& restaurant) {

    if (restaurant.foodCount >= MAX_FOOD) {  // Dùng hàm restaurant.foooCount để xem danh sách món ăn đã đầy chưa
        cout << "Danh sach mon an da day!\n";
        return;
    }

    Food newFood;

    cout << "Nhap ma mon: ";
    cin >> newFood.id;

    for (int i = 0; i < restaurant.foodCount; i++) {

        if (restaurant.food[i].id == newFood.id) {
            cout << "Ma mon da ton tai!\n";
            return;
        }
    }

    cin.ignore();

    cout << "Nhap ten mon: ";
    getline(cin, newFood.name);

    cout << "Nhap don gia: ";
    cin >> newFood.price;

    cout << "Nhap so luong: ";
    cin >> newFood.quantity;

    restaurant.food[restaurant.foodCount] = newFood;

    restaurant.foodCount++;

    cout << "Them mon an thanh cong!\n";
}

// ======================================================
// 3. HIỂN THỊ DANH SÁCH MÓN ĂN
// ======================================================

void showFoods(const Restaurant& restaurant) {

    if (restaurant.foodCount == 0) {
        cout << "Chua co mon an nao!\n";
        return;
    }

    cout << "\n========== DANH SACH MON AN ==========\n";

    for (int i = 0; i < restaurant.foodCount; i++) {

        cout << "\nMon " << i + 1 << endl;

        cout << "Ma mon: "
             << restaurant.food[i].id << endl;

        cout << "Ten mon: "
             << restaurant.food[i].name << endl;

        cout << "Don gia: "
             << restaurant.food[i].price << endl;

        cout << "So luong: "
             << restaurant.food[i].quantity << endl;
    }
}

