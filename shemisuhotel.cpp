
#include <iostream>
#include <string>

using namespace std;

const int MAX_ROOMS = 10; // Maximum number of rooms in the hotel

// Room structure to store room details
struct Room {
    int roomNumber;
    bool isBooked;
    string customerName;
    string customerPhone;
    int customerID;
    double price; // Price in Birr

    Room() : roomNumber(0), isBooked(false), price(0.0), customerID(0) {} // Default constructor
};

// Hotel class to manage the booking system
class Hotel {
private:
    Room rooms[MAX_ROOMS]; // Fixed-size array to store room details
    int roomCount;         // Current number of rooms added to the hotel

public:
    Hotel() : roomCount(0) {} // Initialize room count to 0

    // Add a new room
    void addRoom(int roomNumber, double price) {
        if (roomCount < MAX_ROOMS) {
            rooms[roomCount].roomNumber = roomNumber;
            rooms[roomCount].isBooked = false;
            rooms[roomCount].price = price;
            roomCount++;
        } else {
            cout << "Cannot add more rooms. Hotel is at full capacity.\n";
        }
    }

    // Display available rooms
    void displayAvailableRooms() {
        cout << "\nAvailable Rooms:\n";
        bool found = false;
        for (int i = 0; i < roomCount; i++) {
            if (!rooms[i].isBooked) {
                cout << "Room Number: " << rooms[i].roomNumber << ", Price: " << rooms[i].price << " Birr" << endl;
                found = true;
            }
        }
        if (!found) {
            cout << "No rooms available.\n";
        }
    }

    // Book a room
    void bookRoom(int roomNumber) {
        for (int i = 0; i < roomCount; i++) {
            if (rooms[i].roomNumber == roomNumber) {
                if (rooms[i].isBooked) {
                    cout << "Room " << roomNumber << " is already booked.\n";
                } else {
                    cout << "Enter Customer ID: ";
                    cin >> rooms[i].customerID;
                    cin.ignore();
                    cout << "Enter Customer Name: ";
                    getline(cin, rooms[i].customerName);
                    cout << "Enter Customer Phone: ";
                    getline(cin, rooms[i].customerPhone);
                    cout << "Enter Room Price: ";
                    cin >> rooms[i].price; // Taking price input during booking
                    rooms[i].isBooked = true;
                    cout << "Room " << roomNumber << " has been successfully booked.\n";
                }
                return;
            }
        }
        cout << "Room " << roomNumber << " does not exist.\n";
    }

    // Display all booked room details
    void displayBookedRooms() {
        cout << "\nBooked Rooms:\n";
        bool found = false;
        for (int i = 0; i < roomCount; i++) {
            if (rooms[i].isBooked) {
                cout << "Room Number: " << rooms[i].roomNumber
                     << "\nCustomer ID: " << rooms[i].customerID
                     << "\nCustomer Name: " << rooms[i].customerName
                     << "\nCustomer Phone: " << rooms[i].customerPhone
                     << "\nPrice: " << rooms[i].price << " Birr\n\n";
                found = true;
            }
        }
        if (!found) {
            cout << "No rooms are currently booked.\n";
        }
    }
};

int main() {
    Hotel hotel;
    int choice, roomNumber;
    double price;

    // Add some initial rooms to the hotel
    hotel.addRoom(1, 500);
    hotel.addRoom(2, 500);
    hotel.addRoom(3, 500);
    hotel.addRoom(4, 500);

    do {
        cout << "\nHotel Management System\n";
        cout << "1. Display Available Rooms\n";
        cout << "2. Book a Room\n";
        cout << "3. Display Booked Rooms\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

switch (choice) {
            case 1:
                hotel.displayAvailableRooms();
                break;
            case 2:
                cout << "Enter Room Number to Book: ";
                cin >> roomNumber;
                hotel.bookRoom(roomNumber);
                break;
            case 3:
                hotel.displayBookedRooms();
                break;
            case 4:
                cout << "Exiting the system.\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 4);

    return 0;
}