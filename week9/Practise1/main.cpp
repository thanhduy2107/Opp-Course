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

// ======================================================
// 4. TÌM MÓN ĂN THEO MÃ HOẶC TÊN
// ======================================================

void findFood(const Restaurant& restaurant) {

    string keyword;

    cin.ignore();

    cout << "Nhap ma hoac ten mon can tim: ";
    getline(cin, keyword);

    bool found = false;

    for (int i = 0; i < restaurant.foodCount; i++) {

        if (restaurant.food[i].id == keyword ||
            restaurant.food[i].name == keyword) {

            cout << "\nTim thay mon an:\n";

            cout << "Ma mon: "
                 << restaurant.food[i].id << endl;

            cout << "Ten mon: "
                 << restaurant.food[i].name << endl;

            cout << "Don gia: "
                 << restaurant.food[i].price << endl;

            cout << "So luong: "
                 << restaurant.food[i].quantity << endl;

            found = true;
        }
    }

    if (!found) {
        cout << "Khong tim thay mon an!\n"; 
    }
}

// ======================================================
// 5. CẬP NHẬT GIÁ HOẶC SỐ LƯỢNG MÓN ĂN
// ======================================================

void updateFood(Restaurant& restaurant) {

    string id;

    cout << "Nhap ma mon can cap nhat: ";
    cin >> id;

    for (int i = 0; i < restaurant.foodCount; i++) { 

        if (restaurant.food[i].id == id) {

            cout << "Nhap gia moi: ";
            cin >> restaurant.food[i].price;

            cout << "Nhap so luong moi: ";
            cin >> restaurant.food[i].quantity;

            cout << "Cap nhat thanh cong!\n";

            return;
        }
    }

    cout << "Khong tim thay mon an!\n";
}

// ======================================================
// 6. TẠO ĐƠN HÀNG MỚI
// ======================================================

void createOrder(Restaurant& restaurant) {

    if (restaurant.orderCount >= MAX_ORDER) {
        cout << "Danh sach don hang da day!\n";
        return;
    }

    Order newOrder;

    cout << "Nhap ma don hang: ";
    cin >> newOrder.id;

    for (int i = 0; i < restaurant.orderCount; i++) {

        if (restaurant.orders[i].id == newOrder.id) {
            cout << "Ma don hang da ton tai!\n";
            return;
        }
    }

    cin.ignore();

    cout << "Nhap ten khach hang: ";
    getline(cin, newOrder.customerName);

    cout << "Nhap dia chi giao hang: ";
    getline(cin, newOrder.address);

    cout << "Nhap so luong mon trong don: ";
    cin >> newOrder.itemCount;

    if (newOrder.itemCount <= 0 || newOrder.itemCount > MAX_ITEM) { // Món quá 100 và dưới 0, trả về giá trị không hợp lệ

        cout << "So luong mon khong hop le!\n";
        return;
    }

    for (int i = 0; i < newOrder.itemCount; i++) {

        cout << "\nMon thu " << i + 1 << endl;

        cout << "Nhap ma mon: ";
        cin >> newOrder.items[i].foodId;

        bool found = false;

        for (int j = 0; j < restaurant.foodCount; j++) {

            if (restaurant.food[j].id ==
                newOrder.items[i].foodId) {

                found = true;

                cout << "Ten mon: "
                     << restaurant.food[j].name << endl;

                cout << "So luong dat: ";
                cin >> newOrder.items[i].quantity;

                break;
            }
        }

        if (!found) {

            cout << "Mon an khong ton tai!\n";

            i--;
        }
    }

    newOrder.status = "Pending";

    restaurant.orders[restaurant.orderCount] = newOrder;

    restaurant.orderCount++;

    cout << "Tao don hang thanh cong!\n";
}

// ======================================================
// 7. KIỂM TRA MÓN ĂN CÓ TỒN TẠI VÀ ĐỦ SỐ LƯỢNG
// ======================================================

bool checkFoodQuantity(
    const Restaurant& restaurant,
    string foodId,
    int quantity
) {

    for (int i = 0; i < restaurant.foodCount; i++) {

        if (restaurant.food[i].id == foodId) {

            if (restaurant.food[i].quantity >= quantity) {
                return true;
            }

            return false;
        }
    }

    return false;
}


// ======================================================
// 8. TÍNH TỔNG TIỀN CỦA ĐƠN HÀNG
// ======================================================

double calculateOrderTotal(
    const Restaurant& restaurant,
    const Order& order
) {

    double total = 0;

    for (int i = 0; i < order.itemCount; i++) {

        for (int j = 0; j < restaurant.foodCount; j++) {

            if (restaurant.food[j].id ==
                order.items[i].foodId) {

                total += restaurant.food[j].price
                       * order.items[i].quantity;

                break;
            }
        }
    }

    return total;
}

// ======================================================
// 9. HIỂN THỊ DANH SÁCH ĐƠN HÀNG
// ======================================================

void showOrders(const Restaurant& restaurant) {

    if (restaurant.orderCount == 0) {

        cout << "Chua co don hang nao!\n";

        return;
    }

    cout << "\n========== DANH SACH DON HANG ==========\n";

    for (int i = 0; i < restaurant.orderCount; i++) {

        cout << "\nDon hang " << i + 1 << endl;

        cout << "Ma don: "
             << restaurant.orders[i].id << endl;

        cout << "Khach hang: "
             << restaurant.orders[i].customerName << endl;

        cout << "Dia chi: "
             << restaurant.orders[i].address << endl;

        cout << "Trang thai: "
             << restaurant.orders[i].status << endl;

        cout << "Cac mon:\n";

        for (int j = 0;
             j < restaurant.orders[i].itemCount;
             j++) {

            cout << "- Ma mon: "
                 << restaurant.orders[i].items[j].foodId
                 << ", So luong: "
                 << restaurant.orders[i].items[j].quantity
                 << endl;
        }

        cout << "Tong tien: "
             << calculateOrderTotal(
                    restaurant,
                    restaurant.orders[i]
                )
             << endl;
    }
}

