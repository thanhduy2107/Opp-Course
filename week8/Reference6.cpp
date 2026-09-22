#include <iostream>
#include <vector>
using namespace std;

void insertSubarray(vector<int>& arr, const vector<int>& sub, int index) {
    arr.insert(arr.begin() + index, sub.begin(), sub.end()); // Sử dụng phương thức insert của vector để chèn sub vào arr tại vị trí index
}

int main() {
    vector<int> nums = {1, 2, 3, 4, 5}; // Vị trí là 0, 1, 2, 3, 4
    vector<int> sub = {9, 9};
    int pos = 2; // Vị trí chèn sub vào nums

    insertSubarray(nums, sub, pos); // Gọi hàm insertSubarray để chèn sub vào nums tại vị trí pos

    cout << "nums after insertion: ";

    for (int x : nums) {
        cout << x << " "; // In ra các phần tử của nums sau khi chèn sub
    }

    return 0;
}