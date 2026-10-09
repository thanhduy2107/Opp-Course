#include <iostream>
#include <string>
using namespace std;

class Fish {
private:
    int id;
    string name;
    string color;
    string characteristics;

public:
    // ===== Constructors =====

    Fish() { id = 0; name = "Unknown"; color = "Unknown"; characteristics = "None"; }
    Fish(int id) { this->id = id; name = "Unknown"; color = "Unknown"; characteristics = "None"; }
    Fish(int id, string name) { this->id = id; this->name = name; color = "Unknown"; characteristics = "None"; }
    Fish(int id, string name, string color) { this->id = id; this->name = name; this->color = color; characteristics = "None"; }
    Fish(int id, string name, string color, string characteristics) {
        this->id = id;
        this->name = name;
        this->color = color;
        this->characteristics = characteristics;

    }

    // ===== Getter Methods =====
    int getId() { return id; }
    string getName() { return name; }
    string getColor() { return color; }
    string getCharacteristics() { return characteristics; }

    // ===== Setter Methods =====
    void setId(int id) { this->id = id; }
    void setName(string name) { this->name = name; }
    void setColor(string color) { this->color = color; }
    void setCharacteristics(string characteristics) { this->characteristics = characteristics; }

    void displayInfo() {
        cout << "====================" << endl;
        cout << "=== Fish Info ===" << endl;
        cout << "====================" << endl;
        cout << "ID: " << id << endl;
        cout << "Name: " << name << endl;
        cout << "Color: " << color << endl;
        cout << "Characteristics: " << characteristics << endl;
    }
};

// Main function
int main() {
    Fish fish1;
    Fish fish2(101);
    Fish fish3(102, "Guppy");
    Fish fish4(103, "Angelfish", "Silver");
    Fish fish5(104, "Clownfish", "Orange and white", "Famous from Finding Nemo");

    cout << "\n=== All Fish ===\n";
    fish1.displayInfo();
    fish2.displayInfo();
    fish3.displayInfo();
    fish4.displayInfo();
    fish5.displayInfo();

// Update fish1 information
    fish1.setId(100);
    fish1.setName("Betta");
    fish1.setColor("Red");
    fish1.setCharacteristics("Aggressive and colorful");

    cout << "\n === Updated Fish Information === \n";
    fish1.displayInfo();

// Information of the updated project
    cout << "\n === Information of the updated project === \n";
    cout << "Updated Fish ID: " << fish1.getId() << endl;
    cout << "Updated Fish Name: " << fish1.getName() << endl;
    cout << "Updated Fish Color: " << fish1.getColor() << endl;
    cout << "Updated Fish Characteristics: " << fish1.getCharacteristics() << endl;
    cout << "\n";

// Verify the updated information of fish1
    cout << "\n === Verifying the updated information of fish1 === \n";
    fish1.displayInfo();

    return 0;
}