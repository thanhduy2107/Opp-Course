#include <iostream>
using namespace std;

// Task 1
int countExcellent(double scores[], int n)
{
    int count = 0;

    for (int i = 0; i < n; i++)
    {
        if (scores[i] >= 9.0)
        {
            count++;
        }
    }

    return count;
}
// Task 2
int countInRange(double scores[], int n, double a, double b)
{
    int count = 0;

    for (int i = 0; i < n; i++)
    {
        if (scores[i] >= a && scores[i] <= b)
        {
            count++;
        }
    }

    return count;
}
