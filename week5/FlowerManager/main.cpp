#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

struct Flower
{
    string name;
    double price;
    int quantity;
    string type;
};

int main()
{
    Flower flowers[20] =
    {
        {"Rose", 12.5, 10, "Rose"},
        {"Tulip", 8.0, 15, "Tulip"},
        {"Lily", 15.0, 5, "Lily"},
        {"Daisy", 6.5, 12, "Daisy"},
        {"Sunflower", 10.0, 8, "Sunflower"}
    };

    int N = 5;

    cout << fixed << setprecision(1); // Đặt định dạng số thập phân với 1 chữ số sau dấu thập phân

    // Task 1
    cout << "\n===== TASK 1 =====\n";

    for (int i = 0; i < N; i++)
    {
        cout << i + 1 << ". "
             << flowers[i].name << " - "
             << flowers[i].price << " - "
             << flowers[i].quantity << " - "
             << flowers[i].type << endl;
    }


    