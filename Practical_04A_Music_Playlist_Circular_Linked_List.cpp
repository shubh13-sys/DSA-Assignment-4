#include <iostream>
#include <string>
using namespace std;

struct Node {
    string song;
    Node* next;
    Node(const string& name) : song(name), next(nullptr) {}
};

Node* last = nullptr;

void addSong() {
    string songName;
    cout << "Enter song name (one word): ";
    cin >> songName;

    Node* newNode = new Node(songName);
    if (last == nullptr) {
        last = newNode;
        newNode->next = newNode;
    } else {
        newNode->next = last->next;
        last->next = newNode;
        last = newNode;
    }
    cout << "Song added successfully.\n";
}

void display() {
    if (last == nullptr) {
        cout << "Playlist is empty.\n";
        return;
    }

    Node* temp = last->next;
    cout << "\nPlaylist:\n";
    do {
        cout << temp->song << endl;
        temp = temp->next;
    } while (temp != last->next);
}

void deleteSong() {
    if (last == nullptr) {
        cout << "Playlist is empty.\n";
        return;
    }

    string name;
    cout << "Enter song to delete: ";
    cin >> name;

    Node* current = last->next;
    Node* previous = last;

    do {
        if (current->song == name) {
            if (current == last && current->next == last) {
                last = nullptr;
            } else {
                previous->next = current->next;
                if (current == last)
                    last = previous;
            }
            delete current;
            cout << "Song deleted successfully.\n";
            return;
        }
        previous = current;
        current = current->next;
    } while (current != last->next);

    cout << "Song not found.\n";
}

void playNext() {
    static Node* current = nullptr;

    if (last == nullptr) {
        cout << "Playlist is empty.\n";
        current = nullptr;
        return;
    }

    if (current == nullptr)
        current = last->next;
    else {
        // If the current node was deleted, restart at the first song.
        bool exists = false;
        Node* temp = last->next;
        do {
            if (temp == current) exists = true;
            temp = temp->next;
        } while (temp != last->next);
        if (!exists) current = last->next;
        else current = current->next;
    }

    cout << "Now Playing: " << current->song << endl;
}

void clearPlaylist() {
    if (last == nullptr) return;
    Node* first = last->next;
    last->next = nullptr;
    while (first != nullptr) {
        Node* nextNode = first->next;
        delete first;
        first = nextNode;
    }
    last = nullptr;
}

int main() {
    int choice;
    do {
        cout << "\n--- MUSIC PLAYLIST ---\n";
        cout << "1. Add Song\n2. Delete Song\n3. Display Playlist\n";
        cout << "4. Play Next Song\n5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1: addSong(); break;
            case 2: deleteSong(); break;
            case 3: display(); break;
            case 4: playNext(); break;
            case 5: cout << "Exit\n"; break;
            default: cout << "Invalid choice\n";
        }
    } while (choice != 5);

    clearPlaylist();
    return 0;
}
