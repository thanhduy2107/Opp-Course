#include <iostream>
#include <string>
using namespace std;

const int MAX_MOBILES = 100;
const int MAX_ORDERS = 100;
const int MAX_ITEMS = 20;

struct Mobile {
    int id;
    string brand;
    string model;
    int year;
    double price;
};

struct OrderItem {
    int mobileId;
    int quantity;
};

struct Order {
    int id;
    string customerName;
    string date;

    OrderItem items[MAX_ITEMS];  
    int numItems;
};

struct Shop {
    string name;
    string address;
    string phone;

    Mobile mobiles[MAX_MOBILES]; // Lưu tất cả điện thoại shop đang bán
    int numMobiles;

    Order orders[MAX_ORDERS]; // Lưu tất cả đơn hàng
    int numOrders;
};

void inputMobile(Mobile& mobile) {
    cout << "Nhap ID dien thoai: ";
    cin >> mobile.id;

    cin.ignore();

    cout << "Nhap hang: ";
    getline(cin, mobile.brand);

    cout << "Nhap model: ";
    getline(cin, mobile.model);

    cout << "Nhap nam san xuat: ";
    cin >> mobile.year;

    cout << "Nhap gia: ";
    cin >> mobile.price;
}

void outputMobile(const Mobile& mobile) {
    cout << "ID: " << mobile.id << endl;
    cout << "Hang: " << mobile.brand << endl;
    cout << "Model: " << mobile.model << endl;
    cout << "Nam san xuat: " << mobile.year << endl;
    cout << "Gia: " << mobile.price << endl;
}

int findMobile(const Shop& shop, int id) {  
    for (int i = 0; i < shop.numMobiles; i++) {
        if (shop.mobiles[i].id == id) {
            return i;
        }
    }

    return -1; 
}

void addMobile(Shop& shop) {
    if (shop.numMobiles >= MAX_MOBILES) {
        cout << "Danh sach dien thoai da day!\n";
        return;
    }

    Mobile mobile;

    inputMobile(mobile);

    if (findMobile(shop, mobile.id) != -1) {
        cout << "ID dien thoai da ton tai!\n";
        return;
    }

    shop.mobiles[shop.numMobiles] = mobile;
    shop.numMobiles++;

    cout << "Them dien thoai thanh cong!\n";
}

void deleteMobile(Shop& shop) {
    int id;

    cout << "Nhap ID dien thoai can xoa: ";
    cin >> id;

    int index = findMobile(shop, id);

    if (index == -1) {
        cout << "Khong tim thay dien thoai!\n";
        return;
    }

    for (int i = index; i < shop.numMobiles - 1; i++) {
        shop.mobiles[i] = shop.mobiles[i + 1];
    }

    shop.numMobiles--;

    cout << "Xoa dien thoai thanh cong!\n";
}

void createOrder(Shop& shop) {
    if (shop.numOrders >= MAX_ORDERS) {
        cout << "Danh sach order da day!\n";
        return;
    }

    Order order;

    cout << "Nhap ID order: ";
    cin >> order.id;

    cin.ignore();

    cout << "Nhap ten khach hang: ";
    getline(cin, order.customerName);

    cout << "Nhap ngay dat hang (YYYY-MM-DD): ";
    getline(cin, order.date);

    cout << "Nhap so luong loai dien thoai: ";
    cin >> order.numItems;

    if (order.numItems > MAX_ITEMS) {
        cout << "So luong dien thoai qua lon!\n";
        return;
    }

    for (int i = 0; i < order.numItems; i++) {
        cout << "\nDien thoai thu " << i + 1 << endl;

        cout << "Nhap ID dien thoai: ";
        cin >> order.items[i].mobileId;

        if (findMobile(shop, order.items[i].mobileId) == -1) {
            cout << "Dien thoai khong ton tai!\n";
            i--;
            continue;
        }

        cout << "Nhap so luong: ";
        cin >> order.items[i].quantity;
    }

    shop.orders[shop.numOrders] = order;
    shop.numOrders++;

    cout << "Tao order thanh cong!\n";
}

int findOrder(const Shop& shop, int id) {
    for (int i = 0; i < shop.numOrders; i++) {
        if (shop.orders[i].id == id) {
            return i;
        }
    }

    return -1;
}

void editOrder(Shop& shop) {
    int id;

    cout << "Nhap ID order can sua: ";
    cin >> id;

    int index = findOrder(shop, id);

    if (index == -1) {
        cout << "Khong tim thay order!\n";
        return;
    }

    cin.ignore();

    cout << "Nhap ten khach hang moi: ";
    getline(cin, shop.orders[index].customerName);

    cout << "Nhap ngay moi (YYYY-MM-DD): ";
    getline(cin, shop.orders[index].date);

    cout << "Nhap so luong loai dien thoai moi: ";
    cin >> shop.orders[index].numItems;

    for (int i = 0; i < shop.orders[index].numItems; i++) {
        cout << "\nDien thoai thu " << i + 1 << endl;

        cout << "Nhap ID dien thoai: ";
        cin >> shop.orders[index].items[i].mobileId;

        cout << "Nhap so luong: ";
        cin >> shop.orders[index].items[i].quantity;
    }

    cout << "Chinh sua order thanh cong!\n";
}

void statisticOrderByMonth(const Shop& shop) {
    int month;

    cout << "Nhap thang can thong ke: ";
    cin >> month;

    int count = 0;

    cout << "\nDanh sach order trong thang " << month << ":\n";

    for (int i = 0; i < shop.numOrders; i++) {
        string date = shop.orders[i].date;

        if (date.length() >= 7) {
            int orderMonth = stoi(date.substr(5, 2));

            if (orderMonth == month) {
                cout << "Order ID: " << shop.orders[i].id << endl;
                cout << "Khach hang: "
                     << shop.orders[i].customerName << endl;
                cout << "Ngay: "
                     << shop.orders[i].date << endl;
                cout << "----------------------\n";

                count++;
            }
        }
    }

    cout << "Tong so order: " << count << endl;
}

void showMobiles(const Shop& shop) {
    cout << "\n===== DANH SACH DIEN THOAI =====\n";

    for (int i = 0; i < shop.numMobiles; i++) {
        cout << "\nDien thoai " << i + 1 << endl;
        outputMobile(shop.mobiles[i]);
    }
}

int main() {
    Shop shop;

    shop.name = "My Phone Shop";
    shop.address = "Ho Chi Minh City";
    shop.phone = "0123456789";

    shop.numMobiles = 0;
    shop.numOrders = 0;

    int choice;

    do {
        cout << "\n========== QUAN LY SHOP DIEN THOAI ==========\n";
        cout << "1. Them moi dien thoai\n";
        cout << "2. Xoa dien thoai\n";
        cout << "3. Tao moi order\n";
        cout << "4. Chinh sua order\n";
        cout << "5. Thong ke order theo thang\n";
        cout << "6. Xem danh sach dien thoai\n";
        cout << "0. Thoat\n";
        cout << "=============================================\n";

        cout << "Nhap lua chon: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addMobile(shop);
                break;

            case 2:
                deleteMobile(shop);
                break;

            case 3:
                createOrder(shop);
                break;

            case 4:
                editOrder(shop);
                break;

            case 5:
                statisticOrderByMonth(shop);
                break;

            case 6:
                showMobiles(shop);
                break;

            case 0:
                cout << "Ket thuc chuong trinh!\n";
                break;

            default:
                cout << "Lua chon khong hop le!\n";
        }

    } while (choice != 0);

    return 0;
}