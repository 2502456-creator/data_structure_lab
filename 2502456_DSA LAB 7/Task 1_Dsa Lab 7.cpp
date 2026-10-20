
#include <iostream>
using namespace std;

#define MAX 5

class Queue {
    int arr[MAX];
    int front, rear;

public:
    Queue() {
        front = rear = -1;
    }

    void enqueue(int token) {
        if (rear == MAX - 1) {
            cout << "Queue Overflow!\n";
            return;
        }

        if (front == -1)
            front = 0;

        arr[++rear] = token;
        cout << "Customer " << token << " added.\n";
    }

    void dequeue() {
        if (front == -1) {
            cout << "Queue Underflow! No customers.\n";
            return;
        }

        cout << "Customer " << arr[front] << " served.\n";

        if (front == rear)
            front = rear = -1;
        else
            front++;
    }

    void display() {
        if (front == -1) {
            cout << "No waiting customers.\n";
            return;
        }

        cout << "Waiting customers: ";
        for (int i = front; i <= rear; i++)
            cout << arr[i] << " ";
        cout << endl;
    }

    void count() {
        cout << "Waiting customers: "
             << (front == -1 ? 0 : rear - front + 1)
             << endl;
    }
};

int main() {
    Queue q;

    q.enqueue(101);
    q.enqueue(102);
    q.enqueue(103);

    q.display();
    q.count();

    q.dequeue();

    q.display();
    q.count();

    return 0;
}



