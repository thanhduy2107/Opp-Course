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

// Task 5
    cout << "\n===== Task 5 =====\n";

    int totalQuantity = 0;

    for (int i = 0; i < N; i++)
    {
        totalQuantity += flowers[i].quantity;
    }

    cout << "Total quantity: " << totalQuantity << endl;

// Task 6
    cout << "\n===== Task 6 =====\n";

    double totalPrice = 0;

    for (int i = 0; i < N; i++)
    {
        totalPrice += flowers[i].price;
    }

    double averagePrice = totalPrice / N;

    cout << "Average price: " << averagePrice << endl;

// Task 7
    cout << "\n===== Task 7 =====\n";

    bool counted[20] = {false};

    for (int i = 0; i < N; i++)
    {
        if (counted[i])
        {
            continue;
        }

        int count = 1;

        for (int j = i + 1; j < N; j++)
        {
            if (flowers[i].type == flowers[j].type)
            {
                count++;
                counted[j] = true;
            }
        }

        cout << flowers[i].type << " : " << count << endl;
    }

    // Task 8
    cout << "\n===== Task 8 =====\n";

    string searchType = "Rose";
    bool foundType = false;

    for (int i = 0; i < N; i++)
    {
        if (flowers[i].type == searchType)
        {
            cout << flowers[i].name << endl;
            foundType = true;
        }
    }

    if (!foundType)
    {
        cout << "No flower found." << endl;
    }
   
    // Task 9
    cout << "\n===== Task 9 =====\n";

    string searchName = "Tulip";
    bool foundName = false;

    for (int i = 0; i < N; i++)
    {
        if (flowers[i].name == searchName)
        {
            cout << "Found!" << endl;
            cout << "Name: " << flowers[i].name << endl;
            cout << "Price: " << flowers[i].price << endl;
            cout << "Quantity: " << flowers[i].quantity << endl;
            cout << "Type: " << flowers[i].type << endl;

            foundName = true;
            break;
        }
    }

    if (!foundName)
    {
        cout << "Flower not found!" << endl;
    }

    // Task 10
    cout << "\n===== Task 10 =====\n";

    string checkName = "Lily";
    bool exists = false;

    for (int i = 0; i < N; i++)
    {
        if (flowers[i].name == checkName)
        {
            exists = true;
            break;
        }
    }

    if (exists)
    {
        cout << "Yes, flower exists." << endl;
    }
    else
    {
        cout << "No, flower does not exist." << endl;
    }

    // Task 11
    cout << "\n===== Task 11 =====\n";

    int lowQuantityCount = 0;

    for (int i = 0; i < N; i++)
    {
        if (flowers[i].quantity < 5)
        {
            lowQuantityCount++;
        }
    }

    cout << "Flowers with quantity < 5: "
         << lowQuantityCount << endl;

    // Task 12
    cout << "\n===== Task 12 =====\n";

    double minPrice = 8.0;
    double maxPrice = 12.0;

    int priceRangeCount = 0;

    for (int i = 0; i < N; i++)
    {
        if (flowers[i].price >= minPrice && flowers[i].price <= maxPrice)
        {
            priceRangeCount++;
        }
    }

    cout << "Flowers from " << minPrice << " to " << maxPrice << ": "
         << priceRangeCount << endl;

     // Task 13
    cout << "\n===== Task 13 =====\n";

    double totalValue = 0;

    for (int i = 0; i < N; i++)
    {
        totalValue += flowers[i].price * flowers[i].quantity;
    }

    cout << "Total value: " << totalValue << endl;

     // Task 14
    cout << "\n===== Task 14 =====\n";

    int valuableIndex = 0;

    for (int i = 1; i < N; i++)
    {
        double currentValue =
            flowers[i].price * flowers[i].quantity;

        double maxValue =
            flowers[valuableIndex].price *
            flowers[valuableIndex].quantity;

        if (currentValue > maxValue)
        {
            valuableIndex = i;
        }
    }

    cout << "Most valuable flower: "
         << flowers[valuableIndex].name << endl;

    cout << "Value: "
         << flowers[valuableIndex].price *
            flowers[valuableIndex].quantity << endl;

  // Task 15
    cout << "\n===== Task 15 =====\n";

    Flower temp;

    for (int i = 0; i < N - 1; i++)
    {
        for (int j = 0; j < N - i - 1; j++)
        {
            if (flowers[j].price > flowers[j + 1].price)
            {
                temp = flowers[j];
                flowers[j] = flowers[j + 1];
                flowers[j + 1] = temp;
            }
        }
    }

    for (int i = 0; i < N; i++)
    {
        cout << flowers[i].name
             << " - "
             << flowers[i].price << endl;
    }

