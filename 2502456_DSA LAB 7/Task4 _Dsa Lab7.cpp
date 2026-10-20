

#include <iostream>
using namespace std;

#define MAX 5

class Deque {
    int arr[MAX];
    int front, rear, count;

public:
    Deque() {
        front = rear = -1;
        count = 0;
    }

    void insertFront(int value) {
        if (count == MAX) {
            cout << "Deque is full!\n";
            return;
        }

        if (count == 0)
            front = rear = 0;
        else
            front = (front - 1 + MAX) % MAX;

        arr[front] = value;
        count++;
        cout << value << " inserted at front.\n";
    }

    void insertRear(int value) {
        if (count == MAX) {
            cout << "Deque is full!\n";
            return;
        }

        if (count == 0)
            front = rear = 0;
        else
            rear = (rear + 1) % MAX;

        arr[rear] = value;
        count++;
        cout << value << " inserted at rear.\n";
    }

    void removeFront() {
        if (count == 0) {
            cout << "Deque is empty!\n";
            return;
        }

        cout << arr[front] << " removed from front.\n";
        if (count == 1)
            front = rear = -1;
        else
            front = (front + 1) % MAX;

        count--;
    }

    void removeRear() {
        if (count == 0) {
            cout << "Deque is empty!\n";
            return;
        }

        cout << arr[rear] << " removed from rear.\n";
        if (count == 1)
            front = rear = -1;
        else
            rear = (rear - 1 + MAX) % MAX;

        count--;
    }

    void display() {
        if (count == 0) {
            cout << "Deque is empty!\n";
            return;
        }

        cout << "Front -> ";
        for (int i = 0; i < count; i++)
            cout << arr[(front + i) % MAX] << " ";
        cout << "<- Rear\n";
    }
};

int main() {
    Deque d;

    d.insertRear(301);
    d.insertRear(302);
    d.insertFront(300);

    d.display();

    d.removeFront();
    d.display();

    d.removeRear();
    d.display();

    return 0;
}

