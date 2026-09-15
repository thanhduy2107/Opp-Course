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

// Task 5
void searchScore(double scores[], int n, double x)
{
    bool found = false;

    cout << "Found at:" << endl;

    for (int i = 0; i < n; i++)
    {
        if (scores[i] == x)
        {
            cout << "Student " << i + 1 << endl;
            found = true;
        }
    }

    if (!found)
    {
        cout << "Score not found!" << endl;
    }
}

// Task 6
int countScoreFrequency(double scores[], int n, double x)
{
    int count = 0;

    for (int i = 0; i < n; i++)
    {
        if (scores[i] == x)
        {
            count++;
        }
    }

    return count;
}

// Task 7
void findFirstFailing(double scores[], int n)
{
    for (int i = 0; i < n; i++)
    {
        if (scores[i] < 5)
        {
            cout << "First failing student:" << endl;
            cout << "Student " << i + 1 << ": " << scores[i] << endl;
            return;
        }
    }

    cout << "All students pass!" << endl;
}

// Task 8
void compareAdjacent(double scores[], int n)
{
    for (int i = 1; i < n; i++)
    {
        if (scores[i] > scores[i - 1])
        {
            cout << "Student " << i + 1
                 << " improved compared to Student "
                 << i << endl;
        }
    }
}

// Task 9
int longestPassStreak(double scores[], int n)
{
    int currentStreak = 0;
    int longestStreak = 0;

    for (int i = 0; i < n; i++)
    {
        if (scores[i] >= 5)
        {
            currentStreak++;

            if (currentStreak > longestStreak)
            {
                longestStreak = currentStreak;
            }
        }
        else
        {
            currentStreak = 0;
        }
    }

    return longestStreak;
    