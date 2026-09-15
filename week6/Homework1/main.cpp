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
    double secondHighest = -1;

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

}

// Task 10
void scoreDistribution(double scores[], int n)
{
    int range1 = 0;
    int range2 = 0;
    int range3 = 0;
    int range4 = 0;
    int range5 = 0;

    for (int i = 0; i < n; i++)
    {
        if (scores[i] >= 0 && scores[i] < 5)
        {
            range1++;
        }
        else if (scores[i] >= 5 && scores[i] < 6.5)
        {
            range2++;
        }
        else if (scores[i] >= 6.5 && scores[i] < 8)
        {
            range3++;
        }
        else if (scores[i] >= 8 && scores[i] < 9)
        {
            range4++;
        }
        else if (scores[i] >= 9 && scores[i] <= 10)
        {
            range5++;
        }
    }

    cout << "===== SCORE DISTRIBUTION =====" << endl;
    cout << "0 - <5   : " << range1 << endl;
    cout << "5 - <6.5 : " << range2 << endl;
    cout << "6.5 - <8 : " << range3 << endl;
    cout << "8 - <9   : " << range4 << endl;
    cout << "9 - 10   : " << range5 << endl;
}

int main()
{
    double scores[] = {
        5.0, 7.5, 8.0, 4.5, 6.5,
        7.0, 7.5, 9.0, 5.5, 8.5
    };

    int n = 10;

    cout << "===== TASK 1 =====" << endl;
    cout << "Number of excellent students: "
         << countExcellent(scores, n) << endl;

    cout << endl;
    cout << "===== TASK 2 =====" << endl;

    double a, b;

    cout << "Enter minimum score: ";
    cin >> a;

    cout << "Enter maximum score: ";
    cin >> b;

    cout << "Students in range: "
         << countInRange(scores, n, a, b) << endl;

    cout << endl;
    cout << "===== TASK 3 =====" << endl;
    showAboveAverage(scores, n);

    cout << endl;
    cout << "===== TASK 4 =====" << endl;
    cout << "Second highest score: "
         << findSecondHighest(scores, n) << endl;

    cout << endl;
    cout << "===== TASK 5 =====" << endl;

    double x;

    cout << "Enter score to search: ";
    cin >> x;

    searchScore(scores, n, x);

    cout << endl;
    cout << "===== TASK 6 =====" << endl;

    cout << "Enter score: ";
    cin >> x;

    cout << "Score " << x << " appears "
         << countScoreFrequency(scores, n, x)
         << " times." << endl;

    cout << endl;
    cout << "===== TASK 7 =====" << endl;
    findFirstFailing(scores, n);

    cout << endl;
    cout << "===== TASK 8 =====" << endl;
    compareAdjacent(scores, n);

    cout << endl;
    cout << "===== TASK 9 =====" << endl;
    cout << "Longest pass streak: "
         << longestPassStreak(scores, n)
         << " students" << endl;

    cout << endl;
    cout << "===== TASK 10 =====" << endl;
    scoreDistribution(scores, n);

    return 0;
}