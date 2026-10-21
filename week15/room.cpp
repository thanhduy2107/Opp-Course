#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

//================ ROOM =================
class Room {
protected:
    string roomName;
    int maxAdult;
    int maxChild;
    double price;

public:
    Room() {
        roomName = "";
        maxAdult = 0;
        maxChild = 0;
        price = 0;
    }

    Room(string name, int adult, int child, double price) {
        roomName = name;
        maxAdult = adult;
        maxChild = child;
        this->price = price;
    }

    // Getter
    string getRoomName() {
        return roomName;
    }

    int getMaxAdult() {
        return maxAdult;
    }

    int getMaxChild() {
        return maxChild;
    }

    double getPrice() {
        return price;
    }

    // Setter
    void setRoomName(string name) {
        roomName = name;
    }

    void setMaxAdult(int adult) {
        maxAdult = adult;
    }

    void setMaxChild(int child) {
        maxChild = child;
    }

    void setPrice(double p) {
        price = p;
    }

    virtual void display() {
        cout << "Loai phong: " << roomName << endl;
        cout << "Nguoi lon toi da: " << maxAdult << endl;
        cout << "Tre em toi da: " << maxChild << endl;
        cout << "Gia phong: " << fixed << price << endl;
    }

    virtual double roomCost(int nights) = 0;

    virtual ~Room() {}
};

//================ STANDARD =================
class StandardRoom : public Room {
public:
    StandardRoom()
        : Room("Standard Room", 2, 1, 500000) {}

    double roomCost(int nights) override {
        return nights * price;
    }
};

//================ DELUXE =================
class DeluxeRoom : public Room {
public:
    DeluxeRoom()
        : Room("Deluxe Room", 2, 1, 800000) {}

    double roomCost(int nights) override {
        return nights * price;
    }
};

//================ LUXURY =================
class LuxuryRoom : public Room {
public:
    LuxuryRoom()
        : Room("Luxury Room", 4, 2, 1500000) {}

    double roomCost(int nights) override {
        return nights * price;
    }
};

//================ HOTEL =================
class Hotel {
private:
    vector<Room*> rooms;

public:
    void addRoom(Room* r) {
        rooms.push_back(r);
    }

    void showRooms() {
        cout << "\n===== DANH SACH PHONG =====\n";

        for (Room* r : rooms) {
            r->display();
            cout << "-------------------\n";
        }
    }

    void calculateRevenue(int nights) {
        double total = 0;

        for (Room* r : rooms) {
            total += r->roomCost(nights);
        }

        cout << "\nTong doanh thu "
             << nights
             << " dem = "
             << total
             << endl;
    }

    ~Hotel() {
        for (Room* r : rooms)
            delete r;
    }
};

//================ MAIN =================
int main() {

    Hotel hotel;

    hotel.addRoom(new StandardRoom());
    hotel.addRoom(new DeluxeRoom());
    hotel.addRoom(new LuxuryRoom());

    hotel.showRooms();

    hotel.calculateRevenue(3);

    return 0;
}