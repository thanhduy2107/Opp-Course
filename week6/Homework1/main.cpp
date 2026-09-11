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

// Task 3
void showAboveAverage(double scores[], int n)
{
    double sum = 0;

    for (int i = 0; i < n; i++)
    {
        sum += scores[i];
    }

    double average = sum / n;

    cout << "Average score: " << average << endl;
    cout << endl;
    cout << "Students above average:" << endl;

    for (int i = 0; i < n; i++)
    {
        if (scores[i] > average)
        {
            cout << "Student " << i + 1 << ": " << scores[i] << endl;
        }
    }
}

// Task 4
double findSecondHighest(double scores[], int n)
{
    double highest = scores[0];
    double secondHighest = scores[0];

    for (int i = 1; i < n; i++)
    {
        if (scores[i] > highest)
        {
            secondHighest = highest;
            highest = scores[i];
        }
        else if (scores[i] > secondHighest && scores[i] < highest)
        {
            secondHighest = scores[i];
        }
    }

    return secondHighest;
}
