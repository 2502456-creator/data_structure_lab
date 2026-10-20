
#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    string patientID;
    Node* next;

    Node(string id) {
        patientID = id;
        next = NULL;
    }
};

class PatientStack {
private:
    Node* top;

public:
    PatientStack() {
        top = NULL;
    }

    void push(string id) {
        Node* newNode = new Node(id);
        newNode->next = top;
        top = newNode;
    }

    void pop() {
        if (top == NULL) {
            cout << "Stack is empty!" << endl;
            return;
        }

        Node* temp = top;
        cout << "Handled patient request: "
             << temp->patientID << endl;

        top = top->next;
        delete temp;
    }

    void showTop() {
        if (top == NULL) {
            cout << "Stack is empty!" << endl;
        } else {
            cout << "Current TOP request: "
                 << top->patientID << endl;
        }
    }

    void display() {
        if (top == NULL) {
            cout << "No patient requests!" << endl;
            return;
        }

        Node* current = top;

        cout << "Patient requests (TOP to bottom):" << endl;

        while (current != NULL) {
            cout << current->patientID << endl;
            current = current->next;
        }
    }

    ~PatientStack() {
        while (top != NULL) {
            Node* temp = top;
            top = top->next;
            delete temp;
        }
    }
};

int main() {
    PatientStack hospital;

    hospital.push("P101");
    hospital.push("P102");
    hospital.push("P103");
    hospital.push("P104");

    hospital.display();

    cout << "\nPerforming POP operation:" << endl;
    hospital.pop();

    hospital.showTop();

    cout << "\nRemaining patient requests:" << endl;
    hospital.display();

    return 0;
}

