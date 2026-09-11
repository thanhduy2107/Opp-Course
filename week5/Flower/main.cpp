#include <iostream>
#include <string>
#include <iomanip> // bao gồm thư viện iomanip để sử dụng setw và setprecision
using namespace std;

int main()
{
    // Khai báo các mảng, tối đa 20 loại hoa
    string name[20]; // Mảng lưu tên hoa, 20 ký tự 
    double price[20];
    int quantity[20];
    string type[20];

    int N;

    
// Nhập số lượng hoa, từ 1 đến 20
    
    do
    {
        cout << "How many flowers? ";
        cin >> N;

        if (N < 1 || N > 20)
        {
            cout << "Invalid! Please enter from 1 to 20.\n";
        }

    } while (N < 1 || N > 20);


    
    //  Nhập thông tin cho từng loại hoa
    
    for (int i = 0; i < N; i++)
    {
        cout << "\nFlower " << i + 1 << ":\n";

        cin.ignore();

        cout << "Name: ";
        getline(cin, name[i]);

        // Nhập price và kiểm tra price > 0
        do
        {
            cout << "Price: ";
            cin >> price[i];

            if (price[i] <= 0)
            {
                cout << "Price must be greater than 0!\n";
            }

        } while (price[i] <= 0);


        // Nhập quantity và kiểm tra quantity >= 0
        do
        {
            cout << "Quantity: ";
            cin >> quantity[i];

            if (quantity[i] < 0)
            {
                cout << "Quantity cannot be negative!\n";
            }

        } while (quantity[i] < 0);


        cin.ignore(); // xóa ký tự newline còn lại trong bộ đệm trước khi nhập chuỗi tiếp theo

        cout << "Type: ";
        getline(cin, type[i]);
    }



    // Hiển thị danh sách hoa
    
    cout << "\n\n===== FLOWER SHOP =====\n";

    cout << left
         << setw(5) << "No" // Số thứ tự, setw là width, căn trái
         << setw(20) << "Name" // Tên hoa
         << setw(10) << "Price"
         << setw(10) << "Qty"
         << setw(15) << "Type"
         << endl;

    cout << "------------------------------------------------------------\n";

    for (int i = 0; i < N; i++)
    {
        cout << left
             << setw(5) << i + 1
             << setw(20) << name[i]
             << setw(10) << fixed << setprecision(1) << price[i]
             << setw(10) << quantity[i]
             << setw(15) << type[i]
             << endl;
    }


   
    // 4. Tim hoa đắt nhất và rẻ nhất, lưu chỉ số của hoa đắt nhất và rẻ nhất
    int maxIndex = 0;
    int minIndex = 0;

    for (int i = 1; i < N; i++)
    {
        if (price[i] > price[maxIndex])
        {
            maxIndex = i;
        }

        if (price[i] < price[minIndex])
        {
            minIndex = i;
        }
    }



    // 5. Tính tổng số lượng và giá trung bình của các loại hoa
    int totalQuantity = 0;
    double totalPrice = 0;

    for (int i = 0; i < N; i++)
    {
        totalQuantity += quantity[i];
        totalPrice += price[i];
    }

    double averagePrice = totalPrice / N;



    // In ra kết quả phân tích
   
    cout << "\n----- ANALYSIS -----\n";

    cout << "Most expensive flower: "
         << name[maxIndex]
         << " (" << price[maxIndex] << ")\n";

    cout << "Cheapest flower: "
         << name[minIndex]
         << " (" << price[minIndex] << ")\n";

    cout << "Total quantity: "
         << totalQuantity << endl;

    cout << "Average price: "
         << fixed << setprecision(1) // Đặt định dạng số thập phân với 1 chữ số sau dấu chấm
         << averagePrice << endl;


    
    // Đếm số lượng hoa theo từng loại, sử dụng mảng boolean để đánh dấu loại đã được đếm
    
    cout << "\n----- COUNT BY TYPE -----\n";

    // Mảng đánh dấu loại đã được đếm
    bool counted[20] = {false}; // Khởi tạo tất cả các giá trị trong mảng counted là false

    for (int i = 0; i < N; i++)
    {
        if (counted[i] == true) // Nếu loại hoa đã được đếm, bỏ qua
        {
            continue;
        }

        int count = 1;

        for (int j = i + 1; j < N; j++) // Duyệt qua các hoa còn lại
        {
            if (type[i] == type[j])
            {
                count++;
                counted[j] = true;
            }
        }

        cout << type[i] << " : " << count << endl;
    }


    
    // Tìm kiếm hoa theo tên
    
    char choice;

    do
    {
        string searchName;
        bool found = false;

        cout << "\nEnter flower name to search: ";
        getline(cin, searchName);

        for (int i = 0; i < N; i++)
        {
            if (name[i] == searchName)
            {
                cout << "\nFound!\n";
                cout << "Price: " << price[i] << endl;
                cout << "Quantity: " << quantity[i] << endl;
                cout << "Type: " << type[i] << endl;

                found = true;
                break;
            }
        }

        if (found == false)
        {
            cout << "Flower not found!\n";
        }

        cout << "\nDo you want to search again? (y/n): ";
        cin >> choice;
        cin.ignore();

    } while (choice == 'y' || choice == 'Y');


    cout << "\nProgram finished!\n";

    return 0;
}
