#include <iostream>
#include <string>
using namespace std;

struct Book {
    int id;
    string name;
    string author;

    void inputInfo() { // Hàm void inputInfo() để nhập thông tin sách
        cin >> id;
        cin >> name;
        cin >> author;
    }

    void outputInfo() { // Hàm void outputInfo() để xuất thông tin sách
        cout << "Book ID: " << id << endl;
        cout << "Book Name: " << name << endl;
        cout << "Author: " << author << endl;
    }
};

struct Library { // Cấu trúc Library để quản lý thông tin thư viện và sách
    int idLibrary;
    string nameLibrary;
    int numBooks;
    Book books[100];

    void inputLibrary() { // Hàm void inputLibrary() để nhập thông tin thư viện và sách
        cin >> idLibrary;
        cin >> nameLibrary;
        cin >> numBooks;

        for (int i = 0; i < numBooks; i++) {
            books[i].inputInfo(); // Nhập thông tin sách thứ i
        }
    }

    void outputLibrary() { // Hàm void outputLibrary() để xuất thông tin thư viện và sách
        cout << "Library ID: " << idLibrary << endl;
        cout << "Library Name: " << nameLibrary << endl;
        cout << "Number of books: " << numBooks << endl;

        for (int i = 0; i < numBooks; i++) {
            cout << "Book " << i + 1 << ":" << endl;
            books[i].outputInfo(); // Xuất thông tin sách thứ i
        }
    }

    void addBook(Book a) { // Hàm void addBook() để thêm sách vào thư viện
        books[numBooks] = a;
        numBooks++;
    }

    void getBookInfo(int idBook) { // Hàm void getBookInfo() để lấy thông tin của một cuốn sách theo ID
        for (int i = 0; i < numBooks; i++) {
            if (books[i].id == idBook) { // Nếu tìm thấy sách có ID trùng với idBook, xuất thông tin sách đó
                books[i].outputInfo();
                return;
            }
        }

        cout << "Book not found!" << endl;
    }

    Book getBook(int idBook) { // Hàm Book getBook() để trả về một cuốn sách theo ID
        for (int i = 0; i < numBooks; i++) {
            if (books[i].id == idBook) { // Nếu tìm thấy sách có ID trùng với idBook, trả về cuốn sách đó
                return books[i];
            }
        }

        return Book{-1, "", ""};
    }

    Book* getBooks() { // Hàm Book* getBooks() để trả về con trỏ đến mảng sách

        return books;
    }
};

int main() {
    Library library;

    library.inputLibrary(); // Nhập thông tin thư viện và sách

    cout << "\n===== LIBRARY INFORMATION =====" << endl;
    library.outputLibrary(); // Xuất thông tin thư viện và sách

    return 0;
}

