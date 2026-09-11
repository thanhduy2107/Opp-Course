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


    // Task 2
    cout << "\n===== TASK 2 =====\n";

    int maxIndex = 0;

    for (int i = 1; i < N; i++)
    {
        if (flowers[i].price > flowers[maxIndex].price)
        {
            maxIndex = i;
        }
    }

    cout << "Most expensive: "
         << flowers[maxIndex].name
         << " (" << flowers[maxIndex].price << ")" << endl;

    // Task 3
    cout << "\n===== TASK 3 =====\n";

    int minIndex = 0;

    for (int i = 1; i < N; i++)
    {
        if (flowers[i].price < flowers[minIndex].price)
        {
            minIndex = i;
        }
    }

    cout << "Cheapest: "
         << flowers[minIndex].name
         << " (" << flowers[minIndex].price << ")" << endl;
     
  // Task 4
    cout << "\n===== Task 4 =====\n";

    int largestIndex = 0;

    for (int i = 1; i < N; i++)
    {
        if (flowers[i].quantity > flowers[largestIndex].quantity)
        {
            largestIndex = i;
        }
    }

    cout << "Largest quantity: "
         << flowers[largestIndex].name
         << " (" << flowers[largestIndex].quantity << ")" << endl;

