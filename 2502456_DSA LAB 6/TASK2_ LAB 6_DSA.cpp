
#include <iostream>
#include <string>
using namespace std;

class ActionStack {
private:
    string actions[10];
    int top;

public:
    ActionStack() {
        top = -1;
    }

    void push(string action) {
        if (top == 9) {
            cout << "Stack is full!" << endl;
            return;
        }
        actions[++top] = action;
    }

    void pop() {
        if (top == -1) {
            cout << "Stack is empty!" << endl;
            return;
        }

        cout << "Undo action: " << actions[top] << endl;
        top--;
    }

    void display() {
        if (top == -1) {
            cout << "No actions remaining." << endl;
            return;
        }

        cout << "Actions (TOP to bottom):" << endl;
        for (int i = top; i >= 0; i--) {
            cout << actions[i] << endl;
        }
    }

    void showTop() {
        if (top == -1) {
            cout << "Stack is empty!" << endl;
        } else {
            cout << "Current TOP action: "
                 << actions[top] << endl;
        }
    }
};

int main() {
    ActionStack editor;

    editor.push("Type Hello");
    editor.push("Type World");
    editor.push("Add !");
    editor.push("Delete !");

    editor.display();

    cout << "\nPerforming two Undo operations:" << endl;
    editor.pop();
    editor.pop();

    editor.showTop();

    cout << "\nRemaining actions:" << endl;
    editor.display();

    return 0;
}

