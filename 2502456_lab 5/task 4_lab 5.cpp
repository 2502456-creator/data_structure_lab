#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    string song;
    Node* next;

    Node(string name) {
        song = name;
        next = NULL;
    }
};

int main() {
    Node* head = NULL;
    Node* tail = NULL;

    string songs[] = {
        "Song1", "Song2", "Song3",
        "Song4", "Song5"
    };

    for (int i = 0; i < 5; i++) {
        Node* newNode = new Node(songs[i]);

        if (head == NULL) {
            head = tail = newNode;
        }
        else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    tail->next = head;

    cout << "Music Playlist:\n";

    Node* temp = head;

    do {
        cout << temp->song << " ";
        temp = temp->next;
    } while (temp != head);

    cout << "\n\nPlaying Playlist for 2 Rounds:\n";

    for (int round = 1; round <= 2; round++) {
        cout << "\nRound " << round << ":\n";

        temp = head;

        for (int i = 0; i < 5; i++) {
            cout << "Playing: " << temp->song << endl;
            temp = temp->next;
        }
    }

    return 0;
}
