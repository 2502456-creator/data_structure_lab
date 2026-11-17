#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    string image;
    Node* prev;
    Node* next;

    Node(string name) {
        image = name;
        prev = NULL;
        next = NULL;
    }
};

int main() {
    Node* head = NULL;
    Node* tail = NULL;

    string images[] = {
        "Image1.jpg", "Image2.jpg", "Image3.jpg",
        "Image4.jpg", "Image5.jpg"
    };

    for (int i = 0; i < 5; i++) {
        Node* newNode = new Node(images[i]);

        if (head == NULL) {
            head = tail = newNode;
        }
        else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    cout << "Image Gallery (First to Last):\n";

    Node* temp = head;

    while (temp != NULL) {
        cout << temp->image << " ";
        temp = temp->next;
    }

    cout << "\n\nImage Gallery (Last to First):\n";

    temp = tail;

    while (temp != NULL) {
        cout << temp->image << " ";
        temp = temp->prev;
    }

    return 0;
}
