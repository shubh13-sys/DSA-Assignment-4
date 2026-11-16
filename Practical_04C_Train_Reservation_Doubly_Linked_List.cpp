#include <iostream>
#include <string>
using namespace std;

struct Node {
    string name;
    int trainNo;
    int seatNo;
    Node* prev;
    Node* next;

    Node(const string& passenger, int train, int seat)
        : name(passenger), trainNo(train), seatNo(seat),
          prev(nullptr), next(nullptr) {}
};

Node* head = nullptr;

void reserveSeat() {
    string passengerName;
    int trainNumber, seatNumber;

    cout << "Enter passenger name: ";
    cin >> passengerName;
    cout << "Enter train number: ";
    cin >> trainNumber;
    cout << "Enter seat number: ";
    cin >> seatNumber;

    Node* newNode = new Node(passengerName, trainNumber, seatNumber);
    if (head == nullptr) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next != nullptr)
            temp = temp->next;
        temp->next = newNode;
        newNode->prev = temp;
    }
    cout << "Seat reserved successfully.\n";
}

void display() {
    if (head == nullptr) {
        cout << "No reservations found.\n";
        return;
    }

    Node* temp = head;
    cout << "\n--- TRAIN RESERVATIONS ---\n";
    while (temp != nullptr) {
        cout << "Passenger: " << temp->name << endl;
        cout << "Train No: " << temp->trainNo << endl;
        cout << "Seat No: " << temp->seatNo << endl;
        cout << "-------------------\n";
        temp = temp->next;
    }
}

void cancelReservation() {
    if (head == nullptr) {
        cout << "No reservations found.\n";
        return;
    }

    int seat;
    cout << "Enter seat number to cancel: ";
    cin >> seat;

    Node* temp = head;
    while (temp != nullptr) {
        if (temp->seatNo == seat) {
            if (temp->prev != nullptr)
                temp->prev->next = temp->next;
            else
                head = temp->next;

            if (temp->next != nullptr)
                temp->next->prev = temp->prev;

            delete temp;
            cout << "Reservation cancelled successfully.\n";
            return;
        }
        temp = temp->next;
    }
    cout << "Seat not found.\n";
}

void clearReservations() {
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

int main() {
    int choice;
    do {
        cout << "\n--- TRAIN RESERVATION SYSTEM ---\n";
        cout << "1. Reserve Seat\n2. Display Reservations\n";
        cout << "3. Cancel Reservation\n4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1: reserveSeat(); break;
            case 2: display(); break;
            case 3: cancelReservation(); break;
            case 4: cout << "Exit\n"; break;
            default: cout << "Invalid choice\n";
        }
    } while (choice != 4);

    clearReservations();
    return 0;
}
