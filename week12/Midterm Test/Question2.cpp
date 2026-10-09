#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

// ===== Category Class =====
class Category {
private:
    int categoryId;
    string categoryName;
    string description;

public:
    Category() : categoryId(0), categoryName("Unknown"), description("None") {}
    Category(int id, string name, string desc)
        : categoryId(id), categoryName(name), description(desc) {}

    int getCategoryId() const { return categoryId; } // const là để đảm bảo rằng phương thức này không thay đổi trạng thái của đối tượng. Nó có thể được gọi trên các đối tượng hằng (const objects) và giúp ngăn chặn việc vô tình thay đổi dữ liệu thành viên của lớp.
    string getCategoryName() const { return categoryName; }
    string getDescription() const { return description; }

    void displayInfo() const {
        cout << "====================" << endl;
        cout << "=== Category Info ===" << endl;
        cout << "====================" << endl;
        cout << "Category ID: " << categoryId << endl;
        cout << "Category Name: " << categoryName << endl;
        cout << "Description: " << description << endl;
    }
};

// ===== Fish Class =====
class Fish {
private:
    int id;
    string name;
    string color;
    string characteristics;
    int categoryId; 

public:
    // Original constructors preserved
    Fish() { id = 0; name = "Unknown"; color = "Unknown"; characteristics = "None"; categoryId = 0; }
    Fish(int id) { this->id = id; name = "Unknown"; color = "Unknown"; characteristics = "None"; categoryId = 0; }
    Fish(int id, string name) { this->id = id; this->name = name; color = "Unknown"; characteristics = "None"; categoryId = 0; }
    Fish(int id, string name, string color) { this->id = id; this->name = name; this->color = color; characteristics = "None"; categoryId = 0; }
    Fish(int id, string name, string color, string characteristics) {
        this->id = id;
        this->name = name;
        this->color = color;
        this->characteristics = characteristics;
        categoryId = 0;
    }
    // Extended constructor with category
    Fish(int id, string name, string color, string characteristics, int categoryId) {
        this->id = id;
        this->name = name;
        this->color = color;
        this->characteristics = characteristics;
        this->categoryId = categoryId;
    }

    // Getter methods
    int getId() const { return id; }
    string getName() const { return name; }
    string getColor() const { return color; }
    string getCharacteristics() const { return characteristics; }
    int getCategoryId() const { return categoryId; } // Thêm getter cho categoryId


    // Setter methods
    void setId(int id) { this->id = id; }
    void setName(string name) { this->name = name; }
    void setColor(string color) { this->color = color; }
    void setCharacteristics(string characteristics) { this->characteristics = characteristics; }
    void setCategoryId(int categoryId) { this->categoryId = categoryId; }

    void displayInfo() const {
        cout << "====================" << endl;
        cout << "=== Fish Info ===" << endl;
        cout << "====================" << endl;
        cout << "ID: " << id << endl;
        cout << "Name: " << name << endl;
        cout << "Color: " << color << endl;
        cout << "Characteristics: " << characteristics << endl;
        cout << "Category ID: " << categoryId << endl;
    }
};

// ===== Main Function =====
int main() {
    // Categories
    Category cat1(1, "Freshwater", "Fish that live in rivers and lakes");
    Category cat2(2, "Saltwater", "Fish that live in oceans");
    Category cat3(3, "Tropical", "Colorful ornamental fish for aquariums");

    cout << "\n=== Categories ===\n";
    cat1.displayInfo();
    cat2.displayInfo();
    cat3.displayInfo();

    Fish fish1;
    Fish fish2(101);
    Fish fish3(102, "Guppy");
    Fish fish4(103, "Angelfish", "Silver", "Beautiful and peaceful", 1);
    Fish fish5(104, "Clownfish", "Orange and white", "Famous from Finding Nemo", 2);

    // Update fish1 info
    fish1.setId(100);
    fish1.setName("Betta");
    fish1.setColor("Red");
    fish1.setCharacteristics("Aggressive and colorful");
    fish1.setCategoryId(3);

    // Add 10 more fish
    vector<Fish> fishes = {
        fish1, fish2, fish3, fish4, fish5,
        Fish(105, "Goldfish", "Gold", "Classic ornamental fish", 1),
        Fish(106, "Neon Tetra", "Blue and red", "Tiny and glowing", 3),
        Fish(107, "Oscar", "Black and orange", "Large and intelligent", 1),
        Fish(108, "Discus", "Yellow", "Round and colorful", 3),
        Fish(109, "Swordtail", "Green", "Long tail fin", 1),
        Fish(110, "Molly", "Black", "Hardy and adaptable", 1),
        Fish(111, "Mandarinfish", "Multicolor", "Exotic saltwater fish", 2),
        Fish(112, "Butterflyfish", "Yellow and black", "Flat-bodied saltwater fish", 2),
        Fish(113, "Parrotfish", "Green and blue", "Saltwater reef fish", 2),
        Fish(114, "Zebra Danio", "Striped", "Fast swimmer", 1)
    };

    cout << "\n=== All Fish ===\n";
    for (const auto& f : fishes) { // auto& f để tránh sao chép đối tượng Fish, sử dụng tham chiếu để truy cập trực tiếp vào các đối tượng trong vector.
        f.displayInfo();
    }

    // Group fish by color
    cout << "\n=== Fish Grouped by Color ===\n";
    map<string, vector<Fish>> fishByColor;
    for (const auto& f : fishes) {
        fishByColor[f.getColor()].push_back(f);
    }
    for (const auto& pair : fishByColor) {
        cout << "\nColor: " << pair.first << endl;
        for (const auto& f : pair.second) {
            cout << " - " << f.getName() << endl;
        }
    }

    // Group fish by category
    cout << "\n=== Fish by Category ===\n";
    map<int, vector<Fish>> fishByCategory;
    for (const auto& f : fishes) {
        fishByCategory[f.getCategoryId()].push_back(f);
    }
    for (const auto& pair : fishByCategory) {
        cout << "\nCategory ID: " << pair.first << endl;
        for (const auto& f : pair.second) {
            cout << " - " << f.getName() << endl;
        }
    }

    return 0;
}
