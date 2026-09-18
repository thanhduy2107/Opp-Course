#include <iostream>
#include <string>
using namespace std;

struct Flower
{
    string name;
    double price;
    int quantity;
    string type;
};

Flower flowers[20];
int N;

// Task 1
void displayFlowers()
{
    for (int i = 0; i < N; i++)
    {
        cout << i + 1 << ". "
             << flowers[i].name << " - "
             << flowers[i].price << " - "
             << flowers[i].quantity << " - "
             << flowers[i].type << endl;
    }
}

// Task 2
void findMostExpensive()
{
    int maxIndex = 0;

    for (int i = 1; i < N; i++)
    {
        if (flowers[i].price > flowers[maxIndex].price)
        {
            maxIndex = i;
        }
    }

    cout << "Most expensive flower: "
         << flowers[maxIndex].name << " ("
         << flowers[maxIndex].price << ")" << endl;
}

// Task 3
void findCheapest()
{
    int minIndex = 0;

    for (int i = 1; i < N; i++)
    {
        if (flowers[i].price < flowers[minIndex].price)
        {
            minIndex = i;
        }
    }

    cout << "Cheapest flower: "
         << flowers[minIndex].name << " ("
         << flowers[minIndex].price << ")" << endl;
}

// Task 4
void findLargestQuantity()
{
    int maxIndex = 0;

    for (int i = 1; i < N; i++)
    {
        if (flowers[i].quantity > flowers[maxIndex].quantity)
        {
            maxIndex = i;
        }
    }

    cout << "Flower with largest quantity: "
         << flowers[maxIndex].name << " ("
         << flowers[maxIndex].quantity << ")" << endl;
}

// Task 5
int calculateTotalQuantity()
{
    int total = 0;

    for (int i = 0; i < N; i++)
    {
        total += flowers[i].quantity;
    }

    return total;
}

// Task 6
double calculateAveragePrice()
{
    double total = 0;

    for (int i = 0; i < N; i++)
    {
        total += flowers[i].price;
    }

    return total / N;
}

// Task 7
void countFlowersByType()
{
    string types[20];
    int counts[20];
    int typeCount = 0;

    for (int i = 0; i < N; i++)
    {
        int index = -1;

        for (int j = 0; j < typeCount; j++)
        {
            if (types[j] == flowers[i].type)
            {
                index = j;
                break;
            }
        }

        if (index == -1)
        {
            types[typeCount] = flowers[i].type;
            counts[typeCount] = 1;
            typeCount++;
        }
        else
        {
            counts[index]++;
        }
    }

    for (int i = 0; i < typeCount; i++)
    {
        cout << types[i] << ": "
             << counts[i] << endl;
    }
}

// Task 8
void findFlowersByType(string type)
{
    bool found = false;

    for (int i = 0; i < N; i++)
    {
        if (flowers[i].type == type)
        {
            cout << flowers[i].name << " - "
                 << flowers[i].price << " - "
                 << flowers[i].quantity << endl;

            found = true;
        }
    }

    if (!found)
    {
        cout << "No flower found with this type." << endl;
    }
}

// Task 9
void searchByName(string name)
{
    bool found = false;

    for (int i = 0; i < N; i++)
    {
        if (flowers[i].name == name)
        {
            cout << "Name: " << flowers[i].name << endl;
            cout << "Price: " << flowers[i].price << endl;
            cout << "Quantity: " << flowers[i].quantity << endl;
            cout << "Type: " << flowers[i].type << endl;

            found = true;
            break;
        }
    }

    if (!found)
    {
        cout << "Flower not found." << endl;
    }
}

// Task 10
bool flowerExists(string name)
{
    for (int i = 0; i < N; i++)
    {
        if (flowers[i].name == name)
        {
            return true;
        }
    }

    return false;
}

// Task 11
int countLowQuantity()
{
    int count = 0;

    for (int i = 0; i < N; i++)
    {
        if (flowers[i].quantity < 5)
        {
            count++;
        }
    }

    return count;
}

// Task 12
int countFlowersInPriceRange(double minPrice, double maxPrice)
{
    int count = 0;

    for (int i = 0; i < N; i++)
    {
        if (flowers[i].price >= minPrice &&
            flowers[i].price <= maxPrice)
        {
            count++;
        }
    }

    return count;
}

// Task 13
double calculateTotalValue()
{
    double total = 0;

    for (int i = 0; i < N; i++)
    {
        total += flowers[i].price * flowers[i].quantity;
    }

    return total;
}

// Task 14
void findMostValuable()
{
    int maxIndex = 0;

    for (int i = 1; i < N; i++)
    {
        double currentValue =
            flowers[i].price * flowers[i].quantity;

        double maxValue =
            flowers[maxIndex].price *
            flowers[maxIndex].quantity;

        if (currentValue > maxValue)
        {
            maxIndex = i;
        }
    }

    cout << "Most valuable flower: "
         << flowers[maxIndex].name << endl;

    cout << "Total value: "
         << flowers[maxIndex].price *
            flowers[maxIndex].quantity << endl;
}

// Task 15
void sortByPrice()
{
    for (int i = 0; i < N - 1; i++)
    {
        for (int j = i + 1; j < N; j++)
        {
            if (flowers[i].price > flowers[j].price)
            {
                Flower temp = flowers[i];
                flowers[i] = flowers[j];
                flowers[j] = temp;
            }
        }
    }
}

// Task 16
void sortByName()
{
    for (int i = 0; i < N - 1; i++)
    {
        for (int j = i + 1; j < N; j++)
        {
            if (flowers[i].name > flowers[j].name)
            {
                Flower temp = flowers[i];
                flowers[i] = flowers[j];
                flowers[j] = temp;
            }
        }
    }
}

// Task 17
void findTop3Expensive()
{
    Flower temp[20];

    for (int i = 0; i < N; i++)
    {
        temp[i] = flowers[i];
    }

    for (int i = 0; i < N - 1; i++)
    {
        for (int j = i + 1; j < N; j++)
        {
            if (temp[i].price < temp[j].price)
            {
                Flower x = temp[i];
                temp[i] = temp[j];
                temp[j] = x;
            }
        }
    }

    int limit = N < 3 ? N : 3;

    for (int i = 0; i < limit; i++)
    {
        cout << i + 1 << ". "
             << temp[i].name << " - "
             << temp[i].price << endl;
    }
}

// Task 18
void searchByKeyword(string keyword)
{
    bool found = false;

    for (int i = 0; i < N; i++)
    {
        if (flowers[i].name.find(keyword) != string::npos)
        {
            cout << flowers[i].name << " - "
                 << flowers[i].price << " - "
                 << flowers[i].quantity << endl;

            found = true;
        }
    }

    if (!found)
    {
        cout << "No flower found." << endl;
    }
}

// Task 19
void averageQuantityByType()
{
    string types[20];
    int totalQuantity[20];
    int counts[20];
    int typeCount = 0;

    for (int i = 0; i < N; i++)
    {
        int index = -1;

        for (int j = 0; j < typeCount; j++)
        {
            if (types[j] == flowers[i].type)
            {
                index = j;
                break;
            }
        }

        if (index == -1)
        {
            types[typeCount] = flowers[i].type;
            totalQuantity[typeCount] = flowers[i].quantity;
            counts[typeCount] = 1;
            typeCount++;
        }
        else
        {
            totalQuantity[index] += flowers[i].quantity;
            counts[index]++;
        }
    }

    for (int i = 0; i < typeCount; i++)
    {
        double average =
            (double)totalQuantity[i] / counts[i];

        cout << types[i] << ": "
             << average << endl;
    }
}

// Task 20
void generateReport()
{
    cout << "===== FLOWER SHOP REPORT =====" << endl;

    cout << "Total flowers: " << N << endl;

    cout << "Total quantity: "
         << calculateTotalQuantity() << endl;

    cout << "Average price: "
         << calculateAveragePrice() << endl;

    cout << "Flowers by type:" << endl;

    countFlowersByType();
}

int main()
{
    cout << "How many flowers? ";
    cin >> N;

    while (N < 1 || N > 20)
    {
        cout << "Invalid! Enter N from 1 to 20: ";
        cin >> N;
    }

    for (int i = 0; i < N; i++)
    {
        cout << endl;
        cout << "Flower " << i + 1 << endl;

        cout << "Name: ";
        cin >> flowers[i].name;

        cout << "Price: ";
        cin >> flowers[i].price;

        while (flowers[i].price <= 0)
        {
            cout << "Price must be > 0. Enter again: ";
            cin >> flowers[i].price;
        }

        cout << "Quantity: ";
        cin >> flowers[i].quantity;

        while (flowers[i].quantity < 0)
        {
            cout << "Quantity must be >= 0. Enter again: ";
            cin >> flowers[i].quantity;
        }

        cout << "Type: ";
        cin >> flowers[i].type;
    }

    cout << endl;

    cout << "===== TASK 1 =====" << endl;
    displayFlowers();

    cout << endl;
    cout << "===== TASK 2 =====" << endl;
    findMostExpensive();

    cout << endl;
    cout << "===== TASK 3 =====" << endl;
    findCheapest();

    cout << endl;
    cout << "===== TASK 4 =====" << endl;
    findLargestQuantity();

    cout << endl;
    cout << "===== TASK 5 =====" << endl;
    cout << "Total quantity: "
         << calculateTotalQuantity() << endl;

    cout << endl;
    cout << "===== TASK 6 =====" << endl;
    cout << "Average price: "
         << calculateAveragePrice() << endl;

    cout << endl;
    cout << "===== TASK 7 =====" << endl;
    countFlowersByType();

    cout << endl;
    cout << "===== TASK 8 =====" << endl;

    string type;
    cout << "Enter type: ";
    cin >> type;

    findFlowersByType(type);

    cout << endl;
    cout << "===== TASK 9 =====" << endl;

    string name;
    cout << "Enter flower name: ";
    cin >> name;

    searchByName(name);

    cout << endl;
    cout << "===== TASK 10 =====" << endl;

    cout << "Enter flower name: ";
    cin >> name;

    if (flowerExists(name))
    {
        cout << "Flower exists." << endl;
    }
    else
    {
        cout << "Flower does not exist." << endl;
    }

    cout << endl;
    cout << "===== TASK 11 =====" << endl;
    cout << "Flowers with quantity < 5: "
         << countLowQuantity() << endl;

    cout << endl;
    cout << "===== TASK 12 =====" << endl;

    double minPrice, maxPrice;

    cout << "Enter minimum price: ";
    cin >> minPrice;

    cout << "Enter maximum price: ";
    cin >> maxPrice;

    cout << "Flowers in range: "
         << countFlowersInPriceRange(minPrice, maxPrice)
         << endl;

    cout << endl;
    cout << "===== TASK 13 =====" << endl;
    cout << "Total value: "
         << calculateTotalValue() << endl;

    cout << endl;
    cout << "===== TASK 14 =====" << endl;
    findMostValuable();

    cout << endl;
    cout << "===== TASK 15 =====" << endl;
    sortByPrice();
    displayFlowers();

    cout << endl;
    cout << "===== TASK 16 =====" << endl;
    sortByName();
    displayFlowers();

    cout << endl;
    cout << "===== TASK 17 =====" << endl;
    findTop3Expensive();

    cout << endl;
    cout << "===== TASK 18 =====" << endl;

    string keyword;
    cout << "Enter keyword: ";
    cin >> keyword;

    searchByKeyword(keyword);

    cout << endl;
    cout << "===== TASK 19 =====" << endl;
    averageQuantityByType();

    cout << endl;
    cout << "===== TASK 20 =====" << endl;
    generateReport();

    return 0;
}