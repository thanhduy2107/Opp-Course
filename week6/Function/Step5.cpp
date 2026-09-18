// Step 5: Create a function to analyze scores
#include <iostream>
using namespace std;

struct ScoreInfo
{
    double sum;
    double average;
    int count;
    double maxScore;
    double minScore;
};

ScoreInfo analyzeScores(double scores[], int n) // Hàm analyzeScores để phân tích điểm số
{
    ScoreInfo result; // Khởi tạo struct ScoreInfo để lưu kết quả

    result.sum = 0; // Tính tổng điểm
    result.count = n; // Số lượng điểm

    if (n == 0)
    {
        result.average = 0;
        result.maxScore = 0;
        result.minScore = 0;
        return result;
    }

    result.maxScore = scores[0];
    result.minScore = scores[0];

    for (int i = 0; i < n; i++)
    {
        result.sum += scores[i]; // Tính tổng điểm

        if (scores[i] > result.maxScore)
        {
            result.maxScore = scores[i];
        }

        if (scores[i] < result.minScore)
        {
            result.minScore = scores[i];
        }
    }

    result.average = result.sum / result.count;

    return result;
}

int main()
{
    double scores[] = {8.5, 7.0, 9.5, 6.0, 8.0};
    int n = 5;

    ScoreInfo info = analyzeScores(scores, n);

    cout << "Total: " << info.sum << endl;
    cout << "Average: " << info.average << endl;
    cout << "Max score: " << info.maxScore << endl;
    cout << "Min score: " << info.minScore << endl;

    return 0;
}