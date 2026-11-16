#include <iostream>
#include <string>
using namespace std;

struct Node {
    string name;
    long long number;
    Node* next;
    Node(const string& caller, long long phone)
        : name(caller), number(phone), next(nullptr) {}
};

Node* head = nullptr;

void addCall() {
    string callerName;
    long long phoneNumber;

    cout << "Enter caller name: ";
    cin >> callerName;
    cout << "Enter phone number: ";
    cin >> phoneNumber;

    Node* newNode = new Node(callerName, phoneNumber);
    if (head == nullptr) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next != nullptr)
            temp = temp->next;
        temp->next = newNode;
    }
    cout << "Call added successfully.\n";
}

void displayCalls() {
    if (head == nullptr) {
        cout << "Call log is empty.\n";
        return;
    }

    Node* temp = head;
    cout << "\n--- CALL LOG ---\n";
    while (temp != nullptr) {
        cout << "Name: " << temp->name << endl;
        cout << "Number: " << temp->number << endl;
        cout << "----------------\n";
        temp = temp->next;
    }
}

void deleteCall() {
    if (head == nullptr) {
        cout << "Call log is empty.\n";
        return;
    }

    Node* temp = head;
    head = head->next;
    delete temp;
    cout << "Call deleted successfully.\n";
}

void clearCallLog() {
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

int main() {
    int choice;
    do {
        cout << "\n--- CALL LOG MANAGEMENT ---\n";
        cout << "1. Add Call\n2. Display Calls\n3. Delete Call\n4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1: addCall(); break;
            case 2: displayCalls(); break;
            case 3: deleteCall(); break;
            case 4: cout << "Exit\n"; break;
            default: cout << "Invalid choice\n";
        }
    } while (choice != 4);

    clearCallLog();
    return 0;
}
