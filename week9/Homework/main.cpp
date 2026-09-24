#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cctype>

using namespace std;

// =========================
// STRUCT ĐƠN HÀNG
// =========================

struct Order {
    string code;
    string customerName;
    string phone;
    string address;
    string foodName;
    int quantity;
    string status;
};


// =========================
// TASK 1
// Nhập và hiển thị tên cửa hàng
// =========================

void task1() {
    string shopName;

    cout << "\n===== TASK 1 =====\n";
    cout << "Nhap ten cua hang: ";
    getline(cin, shopName);

    cout << "Chao mung den voi " << shopName << "!\n";
}


// =========================
// HÀM CHUẨN HÓA CHUỖI
// Dùng cho TASK 2
// =========================

string normalizeString(string s) { // Hàm chuẩn hóa
    string result = "";
    bool spaceBefore = false;

    for (char c : s) {
        if (isspace(static_cast<unsigned char>(c))) {
            if (!result.empty()) {
                spaceBefore = true;
            }
        }
        else {
            if (spaceBefore && !result.empty()) {
                result += ' ';
            }

            result += c;
            spaceBefore = false;
        }
    }

    bool newWord = true;

    for (char &c : result) {
        if (c == ' ') {
            newWord = true;
        }
        else {
            if (newWord) {
                c = toupper(static_cast<unsigned char>(c));
                newWord = false;
            }
            else {
                c = tolower(static_cast<unsigned char>(c));
            }
        }
    }

    return result;
}


// =========================
// TASK 2
// Chuẩn hóa tên món ăn
// =========================

void task2() {
    string foodName;

    cout << "\n===== TASK 2 =====\n";
    cout << "Nhap ten mon an: ";
    getline(cin, foodName);

    string result = normalizeString(foodName); // Hàm chuẩn hóa

    cout << "Ten mon sau khi chuan hoa: " << result << endl;
}


// =========================
// TASK 3
// Tạo mã đơn hàng
// =========================

void task3() {
    string customerName;
    string phone;

    cout << "\n===== TASK 3 =====\n";

    cout << "Nhap ten khach hang: ";
    getline(cin, customerName);

    cout << "Nhap so dien thoai: ";
    getline(cin, phone);

    string namePart = "";

    for (char c : customerName) {
        if (isalpha(static_cast<unsigned char>(c))) {  
            namePart += toupper(static_cast<unsigned char>(c));
        }
    }

    if (namePart.length() > 3) {
        namePart = namePart.substr(0, 3);
    }

    string phonePart;

    if (phone.length() >= 4) {
        phonePart = phone.substr(phone.length() - 4);
    }
    else {
        phonePart = phone;
    }

    string orderCode = "DH-" + namePart + "-" + phonePart;

    cout << "Ma don hang: " << orderCode << endl;
}


// =========================
// DANH SÁCH MÓN ĂN
// Dùng cho TASK 4
// =========================

vector<string> foodMenu = {
    "Banh mi",
    "Pho bo",
    "Com tam",
    "Bun cha",
    "Hamburger",
    "Pizza",
    "Ga ran",
    "Tra sua",
    "Ca phe",
    "Miy y"
};


// =========================
// TASK 4
// Kiểm tra món ăn
// =========================

void task4() {
    string foodName;

    cout << "\n===== TASK 4 =====\n";

    cout << "Nhap ten mon an can kiem tra: ";
    getline(cin, foodName);

    string searchFood = normalizeString(foodName);

    bool found = false;

    for (string food : foodMenu) {
        if (normalizeString(food) == searchFood) {
            found = true;
            break;
        }
    }

    if (found) {
        cout << "Mon an co trong danh sach cua cua hang.\n";
    }
    else {
        cout << "Mon an khong co trong danh sach.\n";
    }
}


// =========================
// DANH SÁCH ĐƠN HÀNG
// Dùng cho TASK 6, 7, 9, 10
// =========================

vector<Order> orders = {
    {
        "DH-AN-1234",
        "Nguyen Van An",
        "0912341234",
        "12 Nguyen Trai, Quan 1",
        "Banh mi",
        2,
        "Dang chuan bi"
    },

    {
        "DH-BI-5678",
        "Tran Thi Binh",
        "0987655678",
        "25 Le Loi, Quan 1",
        "Pho bo",
        1,
        "Dang giao"
    },

    {
        "DH-AN-2468",
        "Nguyen Van An",
        "0912342468",
        "12 Nguyen Trai, Quan 1",
        "Banh mi",
        1,
        "Dang chuan bi"
    },

    {
        "DH-CA-1357",
        "Le Van Can",
        "0909121357",
        "50 Hai Ba Trung, Quan 3",
        "Com tam",
        2,
        "Hoan thanh"
    },

    {
        "DH-LI-8642",
        "Pham Thi Linh",
        "0978128642",
        "80 Dien Bien Phu, Binh Thanh",
        "Bun cha",
        1,
        "Da huy"
    }
};


// =========================
// TASK 6
// Thay đổi trạng thái đơn hàng
// =========================

void task6() {
    string code;
    string newStatus;

    cout << "\n===== TASK 6 =====\n";

    cout << "Nhap ma don hang: ";
    getline(cin, code);

    cout << "Nhap trang thai moi:\n";
    cout << "1. Dang chuan bi\n";
    cout << "2. Dang giao\n";
    cout << "3. Hoan thanh\n";
    cout << "4. Da huy\n";

    int choice;
    cout << "Lua chon: ";
    cin >> choice;
    cin.ignore();

    switch (choice) {
        case 1:
            newStatus = "Dang chuan bi";
            break;

        case 2:
            newStatus = "Dang giao";
            break;

        case 3:
            newStatus = "Hoan thanh";
            break;

        case 4:
            newStatus = "Da huy";
            break;

        default:
            cout << "Trang thai khong hop le.\n";
            return;
    }

    bool found = false;

    for (Order &order : orders) {
        if (order.code == code) {
            order.status = newStatus;
            found = true;

            cout << "Cap nhat trang thai thanh cong!\n";
            cout << "Ma don: " << order.code << endl;
            cout << "Trang thai moi: " << order.status << endl;

            break;
        }
    }

    if (!found) {
        cout << "Khong tim thay don hang.\n";
    }
}


// =========================
// TASK 7
// Tìm đơn hàng theo tên khách
// =========================

void task7() {
    string keyword;

    cout << "\n===== TASK 7 =====\n";

    cout << "Nhap tu khoa ten khach hang: ";
    getline(cin, keyword);

    string lowerKeyword = keyword;

    transform(
        lowerKeyword.begin(),
        lowerKeyword.end(),
        lowerKeyword.begin(),
        [](unsigned char c) {
            return tolower(c);
        }
    );

    bool found = false;

    for (const Order &order : orders) {
        string customer = order.customerName;

        transform(
            customer.begin(),
            customer.end(),
            customer.begin(),
            [](unsigned char c) {
                return tolower(c);
            }
        );

        if (customer.find(lowerKeyword) != string::npos) {
            found = true;

            cout << "\nMa don: " << order.code;
            cout << "\nKhach hang: " << order.customerName;
            cout << "\nMon an: " << order.foodName;
            cout << "\nSo luong: " << order.quantity;
            cout << "\nTrang thai: " << order.status << endl;
        }
    }

    if (!found) {
        cout << "Khong tim thay don hang phu hop.\n";
    }
}


// =========================
// TASK 9
// Thống kê món ăn bán chạy
// =========================

void task9() {
    string foodName;

    cout << "\n===== TASK 9 =====\n";

    cout << "Nhap ten mon an: ";
    getline(cin, foodName);

    string searchFood = normalizeString(foodName);

    int count = 0;
    int totalQuantity = 0;

    for (const Order &order : orders) {
        if (normalizeString(order.foodName) == searchFood) {
            count++;
            totalQuantity += order.quantity;
        }
    }

    cout << "\nMon an: " << searchFood << endl;
    cout << "So don hang co mon nay: " << count << endl;
    cout << "Tong so luong da ban: " << totalQuantity << endl;
}


// =========================
// TASK 10
// Tạo thông báo giao hàng
// =========================

void task10() {
    string customerName;
    string orderCode;
    string address;

    cout << "\n===== TASK 10 =====\n";

    cout << "Nhap ten khach hang: ";
    getline(cin, customerName);

    cout << "Nhap ma don hang: ";
    getline(cin, orderCode);

    cout << "Nhap dia chi: ";
    getline(cin, address);

    string notification =
        "Don hang " + orderCode +
        " cua " + customerName +
        " dang duoc giao den " + address +
        ". Cam on ban!";

    cout << "\nThong bao giao hang:\n";
    cout << notification << endl;
}


// =========================
// MENU CHÍNH
// =========================

void showMenu() {
    cout << "\n====================================\n";
    cout << "       QUAN LY CUA HANG DO AN\n";
    cout << "====================================\n";
    cout << "1. Nhap va hien thi ten cua hang\n";
    cout << "2. Chuan hoa ten mon an\n";
    cout << "3. Tao ma don hang\n";
    cout << "4. Kiem tra mon an\n";
    cout << "5. Bo qua\n";
    cout << "6. Thay doi trang thai don hang\n";
    cout << "7. Tim don hang theo ten khach\n";
    cout << "8. Bo qua\n";
    cout << "9. Thong ke mon an ban chay\n";
    cout << "10. Tao thong bao giao hang\n";
    cout << "0. Thoat\n";
    cout << "====================================\n";
}


// =========================
// MAIN
// =========================

int main() {

    int choice;

    do {
        showMenu();

        cout << "Nhap lua chon: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {

            case 1:
                task1();
                break;

            case 2:
                task2();
                break;

            case 3:
                task3();
                break;

            case 4:
                task4();
                break;

            case 5:
                cout << "\nTask 5 da duoc bo qua.\n";
                break;

            case 6:
                task6();
                break;

            case 7:
                task7();
                break;

            case 8:
                cout << "\nTask 8 da duoc bo qua.\n";
                break;

            case 9:
                task9();
                break;

            case 10:
                task10();
                break;

            case 0:
                cout << "\nKet thuc chuong trinh.\n";
                break;

            default:
                cout << "\nLua chon khong hop le!\n";
        }

    } while (choice != 0);

    return 0;
}