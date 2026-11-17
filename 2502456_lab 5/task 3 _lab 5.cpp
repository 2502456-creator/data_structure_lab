#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    string name;
    Node* next;

    Node(string player) {
        name = player;
        next = NULL;
    }
};

int main() {
    Node* head = NULL;
    Node* tail = NULL;

    string players[] = {
        "Ali", "Ahmed", "Sara", "Usman", "Ayesha"
    };

    for (int i = 0; i < 5; i++) {
        Node* newNode = new Node(players[i]);

        if (head == NULL) {
            head = tail = newNode;
        }
        else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    tail->next = head;

    cout << "Game Player Turns:\n";

    Node* temp = head;

    do {
        cout << temp->name << " ";
        temp = temp->next;
    } while (temp != head);

    cout << "\n\nAfter the last player, turn returns to: ";
    cout << temp->name;

    return 0;
}
