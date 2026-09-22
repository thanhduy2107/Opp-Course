#include <iostream>
using namespace std;

void setFirstToZero(int arr[]) { // arr là con trỏ trỏ đến mảng arr, đảm bảo rằng mảng được truyền vào không bị sao chép và có thể được sửa đổi trực tiếp
    arr[0] = 0;
}

void incrementAll(int (&arr)[4]) { // &arr là reference đến mảng arr, đảm bảo rằng mảng được truyền vào không bị sao chép và có thể được sửa đổi trực tiếp
    for (int i = 0; i < 4; ++i) {
        arr[i] += 1;
    }
}

void setLastToTen(int& x) { // x là reference đến biến x, đảm bảo rằng biến được truyền vào không bị sao chép và có thể được sửa đổi trực tiếp
    x = 10;
}

int main() {

    // Bài 1
    int nums[4] = {1, 2, 3, 4};
    setFirstToZero(nums);
    incrementAll(nums);

    cout << "Bai 1: ";
    cout << nums[0] << " "
         << nums[1] << " "
         << nums[2] << " "
         << nums[3] << endl;


    // Bài 2
    int nums2[4] = {3, 5, 7, 9};
    setLastToTen(nums2[3]);
    cout << "Bai 2: ";
    for (int i = 0; i < 4; ++i) {
        cout << nums2[i] << " ";
    }

    cout << endl;

    return 0;
}