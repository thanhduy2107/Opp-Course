// Step 4: Create a function to find the larger of two numbers
#include <iostream>
using namespace std;

int maxValue(int a, int b) // Hàm maxValue để tìm giá trị lớn hơn
{
    if (a > b)
    {
        return a;
    }
    else
    {
        return b;
    }
}

int main()
{
    int a, b;

    cout << "Enter first number: ";
    cin >> a;

    cout << "Enter second number: ";
    cin >> b;

    int result = maxValue(a, b); // Gọi hàm maxValue để tìm giá trị lớn hơn

    cout << "Larger value = " << result << endl;

    return 0;
}