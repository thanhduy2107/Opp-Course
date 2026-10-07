#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Book {
private:
    string bookId;
    string title;
    string author;
    int year;
public:
    Book(string bookId, string title, string author, int year);
    void input();
    void display() const;
    string getBookId() const;
    string getTitle() const;
    string getAuthor() const;
    int getYear() const;
};

// Định nghĩa các hàm của class Book
Book::Book(string bookId, string title, string author, int year) {
    this->bookId = bookId;
    this->title = title;
    this->author = author;
    this->year = year;
}

void Book::input() {
    cout << "Mã sách: ";
    cin >> bookId;
    cin.ignore();
    cout << "Tên sách: ";
    getline(cin, title);
    cout << "Tác giả: ";
    getline(cin, author);
    cout << "Năm xuất bản: ";
    cin >> year;
}

void Book::display() const {
    cout << bookId << "\t" << title << "\t" << author << "\t" << year << endl;
}

string Book::getBookId() const { return bookId; }
string Book::getTitle() const { return title; }
string Book::getAuthor() const { return author; }
int Book::getYear() const { return year; }

// Chương trình chính
int main() {
    vector<Book> library;
    int choice;

    do {
        cout << "\n===== QUẢN LÝ SÁCH THƯ VIỆN =====" << endl;
        cout << "1. Thêm sách" << endl;
        cout << "2. Hiển thị danh sách sách" << endl;
        cout << "3. Tìm sách theo mã sách" << endl;
        cout << "4. Thoát" << endl;
        cout << "Chọn chức năng: ";
        cin >> choice;

        if (choice == 1) {
            Book b("", "", "", 0);
            cout << "Nhập thông tin sách:" << endl;
            b.input();
            library.push_back(b);
            cout << "Đã thêm sách thành công!" << endl;
        } else if (choice == 2) {
            cout << "\n===== DANH SÁCH SÁCH =====" << endl;
            cout << "Mã sách\tTên sách\tTác giả\tNăm" << endl;
            for (const auto& b : library) {
                b.display();
            }
        } else if (choice == 3) {
            string id;
            cout << "Nhập mã sách cần tìm: ";
            cin >> id;
            bool found = false;
            for (const auto& b : library) {
                if (b.getBookId() == id) {
                    cout << "Thông tin sách:" << endl;
                    cout << "Tên sách: " << b.getTitle() << endl;
                    cout << "Tác giả: " << b.getAuthor() << endl;
                    cout << "Năm xuất bản: " << b.getYear() << endl;
                    found = true;
                    break;
                }
            }
            if (!found) cout << "Không tìm thấy sách có mã " << id << endl;
        }
    } while (choice != 4);

    cout << "Chương trình kết thúc." << endl;
    return 0;
}
