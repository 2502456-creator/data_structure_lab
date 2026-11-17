#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    string website;
    Node* prev;
    Node* next;

    Node(string name) {
        website = name;
        prev = NULL;
        next = NULL;
    }
};

int main() {
    Node* head = NULL;
    Node* tail = NULL;

    string sites[] = {
        "Google", "YouTube", "Facebook",
        "Instagram", "Wikipedia"
    };

    for (int i = 0; i < 5; i++) {
        Node* newNode = new Node(sites[i]);

        if (head == NULL) {
            head = tail = newNode;
        }
        else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    cout << "Browser History (First to Last):\n";

    Node* temp = head;

    while (temp != NULL) {
        cout << temp->website << " ";
        temp = temp->next;
    }

    cout << "\n\nBrowser History (Last to First):\n";

    temp = tail;

    while (temp != NULL) {
        cout << temp->website << " ";
        temp = temp->prev;
    }

    return 0;
}
