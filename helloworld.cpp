#include <iostream>
#include <string>
using namespace std;

// Khai báo struct Computer
struct Computer {
    int id;
    string model;
    int ram;
    int year;
};

int main() {

    // Tạo 5 máy tính
    Computer computer[5];

    // Nhập thông tin 5 máy
    for (int i = 0; i < 5; i++) {

        cout << "\n--- Nhap thong tin may thu "
             << i + 1 << " ---" << endl;

        cout << "Nhap ID: ";
        cin >> computer[i].id;

        cout << "Nhap Model: ";
        cin >> computer[i].model;

        cout << "Nhap RAM: ";
        cin >> computer[i].ram;

        cout << "Nhap nam san xuat: ";
        cin >> computer[i].year;
    }


    // 1. Thống kê máy cùng Model
    string modelCanTim;

    cout << "\nNhap Model can thong ke: ";
    cin >> modelCanTim;

    int countModel = 0;

    for (int i = 0; i < 5; i++) {

        if (computer[i].model == modelCanTim) {
            countModel++;
        }
    }

    cout << "So may cung Model "
         << modelCanTim << " la: "
         << countModel << endl;


    // 2. Thống kê máy cùng năm
    int yearCanTim;

    cout << "\nNhap nam can thong ke: ";
    cin >> yearCanTim;

    int countYear = 0;

    for (int i = 0; i < 5; i++) {

        if (computer[i].year == yearCanTim) {
            countYear++;
        }
    }

    cout << "So may cung nam "
         << yearCanTim << " la: "
         << countYear << endl;


    // 3. Thống kê máy theo RAM
    int ramCanTim;

    cout << "\nNhap RAM can thong ke: ";
    cin >> ramCanTim;

    int countRam = 0;

    for (int i = 0; i < 5; i++) {

        if (computer[i].ram == ramCanTim) {
            countRam++;
        }
    }

    cout << "So may co RAM "
         << ramCanTim << " GB la: "
         << countRam << endl;


    // 4. Thống kê số máy theo từng năm
    cout << "\n===== THONG KE THEO NAM =====" << endl;

    for (int i = 0; i < 5; i++) {

        int count = 0;
        bool daCo = false;

        // Kiểm tra năm này đã thống kê chưa
        for (int k = 0; k < i; k++) {

            if (computer[i].year == computer[k].year) {
                daCo = true;
            }
        }

        // Nếu chưa thống kê thì đếm
        if (daCo == false) {

            for (int j = 0; j < 5; j++) {

                if (computer[i].year == computer[j].year) {
                    count++;
                }
            }

            cout << "Nam "
                 << computer[i].year
                 << " co "
                 << count
                 << " may" << endl;
        }
    }

    return 0;
}