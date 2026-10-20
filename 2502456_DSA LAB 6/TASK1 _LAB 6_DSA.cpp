
#include <iostream>
#include <string>
using namespace std;

class BrowserStack {
private:
    string pages[10];
    int top;

public:
    BrowserStack() {
        top = -1;
    }

    void push(string page) {
        if (top == 9) {
            cout << "Stack is full!" << endl;
            return;
        }
        pages[++top] = page;
    }

    void pop() {
        if (top == -1) {
            cout << "Stack is empty!" << endl;
            return;
        }

        cout << "Back button pressed. Removed: "
             << pages[top] << endl;
        top--;
    }

    void display() {
        if (top == -1) {
            cout << "No browsing history." << endl;
            return;
        }

        cout << "Browsing history (TOP to bottom):" << endl;
        for (int i = top; i >= 0; i--) {
            cout << pages[i] << endl;
        }
    }

    void showTop() {
        if (top == -1) {
            cout << "Stack is empty!" << endl;
        } else {
            cout << "Current TOP page: " << pages[top] << endl;
        }
    }
};

int main() {
    BrowserStack browser;

    browser.push("Google");
    browser.push("YouTube");
    browser.push("Facebook");
    browser.push("GitHub");

    browser.display();

    browser.pop();

    browser.showTop();

    cout << "\nRemaining browsing history:" << endl;
    browser.display();

    return 0;
}

