

#include <iostream>
using namespace std;

#define MAX 5

class CircularQueue {
    int arr[MAX];
    int front, rear, count;

public:
    CircularQueue() {
        front = rear = -1;
        count = 0;
    }

    void enqueue(int packet) {
        if (count == MAX) {
            cout << "Buffer is full!\n";
            return;
        }

        if (count == 0)
            front = 0;

        rear = (rear + 1) % MAX;
        arr[rear] = packet;
        count++;

        cout << "Packet " << packet << " added.\n";
    }

    void dequeue() {
        if (count == 0) {
            cout << "Buffer is empty!\n";
            return;
        }

        cout << "Packet " << arr[front]
             << " transmitted.\n";

        if (count == 1) {
            front = rear = -1;
        } else {
            front = (front + 1) % MAX;
        }
        count--;
    }

    void display() {
        if (count == 0) {
            cout << "No packets waiting.\n";
            return;
        }

        cout << "Waiting packets: ";
        for (int i = 0; i < count; i++)
            cout << arr[(front + i) % MAX] << " ";
        cout << "\n";
    }
};

int main() {
    CircularQueue q;

    q.enqueue(201);
    q.enqueue(202);
    q.enqueue(203);
    q.display();

    q.dequeue();
    q.enqueue(204);
    q.enqueue(205);
    q.enqueue(206);

    q.display();
    return 0;
}

