#include <iostream>
#include <string>
using namespace std;

// Interface (abstract class)
class IFood {
public:
    virtual string getName() const = 0; // Hàm thuần ảo, không có định nghĩa
    virtual double getPrice() const = 0;
    virtual int getQuantity() const = 0;
    virtual void setPrice(double p) = 0;
    virtual ~IFood() {} // destructor ảo
};

// Encapsulated class implementing IFood
class Food : public IFood {
private:
    string name;
    double price;
    int quantity;
public:
    Food(string n, double p, int q) {
        name = n;
        price = (p > 0) ? p : 0;       // kiểm tra dữ liệu
        quantity = (q >= 0) ? q : 0;   // không cho số lượng âm
    }

    // Implement interface methods
    string getName() const override { return name; }
    double getPrice() const override { return price; }
    int getQuantity() const override { return quantity; }

    void setPrice(double p) override {
        if (p > 0) price = p;
    }
};

// Demo
int main() {
    IFood* burger = new Food("Burger", 10000, 2);

    cout << burger->getName() << " - "
         << burger->getPrice() << " VND - "
         << burger->getQuantity() << " pcs" << endl;

    burger->setPrice(-5000); // không hợp lệ, bị chặn
    cout << "Updated price: " << burger->getPrice() << endl;

    delete burger;
    return 0;
}
