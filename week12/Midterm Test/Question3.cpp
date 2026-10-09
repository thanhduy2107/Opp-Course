#include <iostream>
#include <string>
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

    int getCategoryId() const { return categoryId; }
    string getCategoryName() const { return categoryName; }
    string getDescription() const { return description; }

    void displayInfo() const {
        cout << "Category ID: " << categoryId
             << " | Name: " << categoryName
             << " | Desc: " << description << endl;
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
    Fish() : id(0), name("Unknown"), color("Unknown"), characteristics("None"), categoryId(0) {}
    Fish(int id, string name, string color, string characteristics, int categoryId)
        : id(id), name(name), color(color), characteristics(characteristics), categoryId(categoryId) {}

    int getCategoryId() const { return categoryId; }

    void displayInfo() const {
        cout << "Fish ID: " << id
             << " | Name: " << name
             << " | Color: " << color
             << " | Characteristics: " << characteristics
             << " | CategoryID: " << categoryId << endl;
    }
};

// ===== FishShop Class =====
class FishShop {
private:
    int id;
    string name;
    string address;
    string owner;
    string startDate;
    Category categories[4];   // mảng 4 category
    Fish fishes[40];          // mảng 40 fish (10 mỗi category)
    int categoryCount;
    int fishCount;

public:
    FishShop(int id, string name, string address, string owner, string startDate)
        : id(id), name(name), address(address), owner(owner), startDate(startDate),
          categoryCount(0), fishCount(0) {}

    void addCategory(const Category& c) {
        if (categoryCount < 4) categories[categoryCount++] = c;
    }

    void addFish(const Fish& f) {
        if (fishCount < 40) fishes[fishCount++] = f;
    }

    void displayInfo() const {
        cout << "\n=== Fish Shop Info ===\n";
        cout << "ID: " << id << " | Name: " << name
             << " | Address: " << address
             << " | Owner: " << owner
             << " | Start Date: " << startDate << endl;
        cout << "Total Categories: " << categoryCount
             << " | Total Fishes: " << fishCount << endl;
    }

    void displayCategories() const {
        cout << "\n=== Categories ===\n";
        for (int i = 0; i < categoryCount; i++) {
            categories[i].displayInfo();
        }
    }

    void displayFishes() const {
        cout << "\n=== Fishes by Category ===\n";
        for (int c = 0; c < categoryCount; c++) {
            cout << "\n--- " << categories[c].getCategoryName() << " Fishes ---\n";
            for (int i = 0; i < fishCount; i++) {
                if (fishes[i].getCategoryId() == categories[c].getCategoryId()) {
                    fishes[i].displayInfo();
                }
            }
        }
    }
};

// ===== Main =====
int main() {
    FishShop shop(1, "Duy's Fish Shop", "Thu Duc, HCMC", "Duy", "2020-01-01");

    // 4 categories
    Category cat1(1, "Freshwater", "Fish that live in rivers and lakes");
    Category cat2(2, "Saltwater", "Fish that live in oceans");
    Category cat3(3, "Tropical", "Colorful ornamental fish for aquariums");
    Category cat4(4, "Rare", "Special rare ornamental fish");

    shop.addCategory(cat1);
    shop.addCategory(cat2);
    shop.addCategory(cat3);
    shop.addCategory(cat4);

    // 40 fishes (10 per category)
    // Freshwater
    shop.addFish(Fish(101, "Goldfish", "Gold", "Classic ornamental fish", 1));
    shop.addFish(Fish(102, "Angelfish", "Silver", "Graceful fins", 1));
    shop.addFish(Fish(103, "Oscar", "Black and orange", "Large and intelligent", 1));
    shop.addFish(Fish(104, "Swordtail", "Green", "Long tail fin", 1));
    shop.addFish(Fish(105, "Molly", "Black", "Hardy and adaptable", 1));
    shop.addFish(Fish(106, "Zebra Danio", "Striped", "Fast swimmer", 1));
    shop.addFish(Fish(107, "Platy", "Orange", "Small and peaceful", 1));
    shop.addFish(Fish(108, "Corydoras", "Brown", "Bottom-dwelling catfish", 1));
    shop.addFish(Fish(109, "Pleco", "Dark", "Algae eater", 1));
    shop.addFish(Fish(110, "Koi", "Orange and white", "Symbol of luck", 1));

    // Saltwater
    shop.addFish(Fish(201, "Clownfish", "Orange and white", "Famous from Nemo", 2));
    shop.addFish(Fish(202, "Mandarinfish", "Multicolor", "Exotic saltwater fish", 2));
    shop.addFish(Fish(203, "Butterflyfish", "Yellow and black", "Flat-bodied saltwater fish", 2));
    shop.addFish(Fish(204, "Parrotfish", "Green and blue", "Saltwater reef fish", 2));
    shop.addFish(Fish(205, "Surgeonfish", "Blue", "Known as Dory", 2));
    shop.addFish(Fish(206, "Lionfish", "Red and white", "Venomous spines", 2));
    shop.addFish(Fish(207, "Wrasse", "Colorful", "Reef cleaner", 2));
    shop.addFish(Fish(208, "Hawkfish", "Red", "Perches on corals", 2));
    shop.addFish(Fish(209, "Gobies", "Small", "Sand dwellers", 2));
    shop.addFish(Fish(210, "Damselfish", "Blue", "Common reef fish", 2));

    // Tropical
    shop.addFish(Fish(301, "Betta", "Red", "Aggressive and colorful", 3));
    shop.addFish(Fish(302, "Guppy", "Blue", "Small and lively", 3));
    shop.addFish(Fish(303, "Neon Tetra", "Blue and red", "Tiny and glowing", 3));
    shop.addFish(Fish(304, "Discus", "Yellow", "Round and colorful", 3));
    shop.addFish(Fish(305, "Ram Cichlid", "Blue and gold", "Peaceful cichlid", 3));
    shop.addFish(Fish(306, "Killifish", "Multicolor", "Bright patterns", 3));
    shop.addFish(Fish(307, "Barb", "Orange", "Active schooling fish", 3));
    shop.addFish(Fish(308, "Loach", "Brown", "Bottom dweller", 3));
    shop.addFish(Fish(309, "Arowana", "Silver", "Large tropical fish", 3));
    shop.addFish(Fish(310, "Flowerhorn", "Pink", "Unique head shape", 3));

    // Rare
    shop.addFish(Fish(401, "Dragonfish", "Dark", "Rare deep-sea fish", 4));
    shop.addFish(Fish(402, "Arapaima", "Green", "Largest freshwater fish", 4));
    shop.addFish(Fish(403, "Sturgeon", "Gray", "Source of caviar", 4));
    shop.addFish(Fish(404, "Piranha", "Silver", "Sharp teeth", 4));
    shop.addFish(Fish(405, "Electric Eel", "Brown", "Generates electricity", 4));
    shop.addFish(Fish(406, "Giant Gourami", "White", "Large ornamental fish", 4));
    shop.addFish(Fish(407, "Napoleon Wrasse", "Blue", "Rare reef giant", 4));
    shop.addFish(Fish(408, "Leaf Fish", "Brown", "Camouflaged predator", 4));
    shop.addFish(Fish(409, "Tiger Shovelnose Catfish", "Striped", "Rare catfish", 4));
    shop.addFish(Fish(410, "Freshwater Stingray", "Gray", "Rare and flat-bodied", 4));

    // Display shop info, categories, and fishes
    shop.displayInfo();
    shop.displayCategories();
    shop.displayFishes();

    return 0;
}