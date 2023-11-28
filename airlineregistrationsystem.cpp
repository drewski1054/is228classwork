#include <iostream>
#include <vector>
#include <string>

struct Booking {
    std::string passengerName;
    int flightNumber;
    // Add more booking details as needed
};

std::vector<Booking> bookings;

void addBooking() {
    Booking newBooking;
    std::cout << "Enter passenger name: ";
    std::cin >> newBooking.passengerName;
    std::cout << "Enter flight number: ";
    std::cin >> newBooking.flightNumber;
    bookings.push_back(newBooking);
    std::cout << "Booking added successfully.\n";
}

void removeBooking() {
    int flightNumber;
    std::cout << "Enter flight number to remove: ";
    std::cin >> flightNumber;

    for (auto it = bookings.begin(); it != bookings.end(); ++it) {
        if (it->flightNumber == flightNumber) {
            bookings.erase(it);
            std::cout << "Booking removed successfully.\n";
            return;
        }
    }
    std::cout << "Booking not found.\n";
}

int main() {
    while (true) {
        std::cout << "Airline Registration System\n";
        std::cout << "1. Add Booking\n";
        std::cout << "2. Remove Booking\n";
        std::cout << "3. Exit\n";
        std::cout << "Select an option: ";

        int choice;
        std::cin >> choice;

        switch (choice) {
            case 1:
                addBooking();
                break;
            case 2:
                removeBooking();
                break;
            case 3:
                return 0;
            default:
                std::cout << "Invalid option. Please try again.\n";
        }
    }
    return 0;
}
