#include <iostream>
#include <vector>
#include <string>

struct Booking {
    std::string passengerName;
    int flightNumber;
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

void displayAllBookings() {
    if (bookings.empty()) {
        std::cout << "There are no bookings to display.\n";
        return;
    }
    for (const auto& booking : bookings) {
        std::cout << "Passenger Name: " << booking.passengerName 
                  << ", Flight Number: " << booking.flightNumber << "\n";
    }
}

void searchBooking() {
    int flightNumber;
    std::cout << "Enter flight number to search: ";
    std::cin >> flightNumber;

    bool found = false;
    for (const auto& booking : bookings) {
        if (booking.flightNumber == flightNumber) {
            std::cout << "Booking found: Passenger Name: " << booking.passengerName 
                      << ", Flight Number: " << booking.flightNumber << "\n";
            found = true;
            break;
        }
    }
    if (!found) {
        std::cout << "No booking found for the given flight number.\n";
    }
}

void updateBooking() {
    int flightNumber;
    std::cout << "Enter flight number of the booking to update: ";
    std::cin >> flightNumber;

    for (auto& booking : bookings) {
        if (booking.flightNumber == flightNumber) {
            std::cout << "Enter new passenger name: ";
            std::cin >> booking.passengerName;
            std::cout << "Booking updated successfully.\n";
            return;
        }
    }
    std::cout << "No booking found with the given flight number.\n";
}

int main() {
    int choice;

    do {
        std::cout << "\nAirline Registration System\n";
        std::cout << "1. Add Booking\n";
        std::cout << "2. Remove Booking\n";
        std::cout << "3. Display All Bookings\n";
        std::cout << "4. Search Booking\n";
        std::cout << "5. Update Booking\n";
        std::cout << "6. Exit\n";
        std::cout << "Select an option: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                addBooking();
                break;
            case 2:
                removeBooking();
                break;
            case 3:
                displayAllBookings();
                break;
            case 4:
                searchBooking();
                break;
            case 5:
                updateBooking();
                break;
            case 6:
                std::cout << "Exiting the program.\n";
                break;
            default:
                std::cout << "Invalid option. Please try again.\n";
        }
    } while (choice != 6);

    return 0;
}
