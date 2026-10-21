#include <iostream>
#include <cmath>
using namespace std;

//================== LỚP CHA ==================
class PT {
protected:
    double a, b, c;

public:
    PT() {
        a = b = c = 0;
    }

    PT(double a, double b, double c = 0) {
        this->a = a;
        this->b = b;
        this->c = c;
    }

    // Getter
    double getA() { return a; }
    double getB() { return b; }
    double getC() { return c; }

    // Setter
    void setA(double a) { this->a = a; } // Đặt giá trị cho a
    void setB(double b) { this->b = b; }
    void setC(double c) { this->c = c; }

    virtual void solve() = 0; // phương thức thuần ảo

    virtual ~PT() {} // Destructor ảo để giải phóng bộ nhớ cho các lớp con
};

// PT BẬC 1
class PTB1 : public PT {
public:
    PTB1(double a, double b) : PT(a, b) {} // : PT(a, b) {} // Gọi constructor của lớp cha PT

    void solve() override { // override: ghi đè phương thức thuần ảo solve() của lớp cha PT
        cout << "\nPhuong trinh: "
             << a << "x + " << b << " = 0\n";

        if (a == 0) {
            if (b == 0)
                cout << "Vo so nghiem\n";
            else
                cout << "Vo nghiem\n";
        }
        else {
            double x = -b / a;
            cout << "Nghiem x = " << x << endl;
        }
    }
};

//================== PT BẬC 2 ==================
class PTB2 : public PT {
public:
    PTB2(double a, double b, double c)
        : PT(a, b, c) {}

    void solve() override { // override: ghi đè phương thức thuần ảo solve() của lớp cha PT
        cout << "\nPhuong trinh: "
             << a << "x^2 + "
             << b << "x + "
             << c << " = 0\n";

        if (a == 0) {
            cout << "Day la PT bac 1\n";

            if (b == 0) {
                if (c == 0)
                    cout << "Vo so nghiem\n";
                else
                    cout << "Vo nghiem\n";
            }
            else {
                cout << "x = " << -c / b << endl;
            }
            return;
        }

        double delta = b * b - 4 * a * c;

        if (delta < 0) {
            cout << "Vo nghiem\n";
        }
        else if (delta == 0) {
            double x = -b / (2 * a);
            cout << "Nghiem kep x = " << x << endl;
        }
        else {
            double x1 = (-b + sqrt(delta)) / (2 * a);
            double x2 = (-b - sqrt(delta)) / (2 * a);

            cout << "x1 = " << x1 << endl;
            cout << "x2 = " << x2 << endl;
        }
    }
};

//================== MAIN ==================
int main() {
    PT* ds[2];

    ds[0] = new PTB1(2, -4);
    ds[1] = new PTB2(1, -5, 6);

    for (int i = 0; i < 2; i++) {
        ds[i]->solve(); // Gọi phương thức solve() của từng đối tượng trong mảng ds
        cout << "-----------------\n";
    }

    for (int i = 0; i < 2; i++) {
        delete ds[i]; // Giải phóng bộ nhớ cho các đối tượng được tạo bằng new
    }

    return 0;
}