

#include <iostream>
using namespace std;

#define MAX 5

class PriorityQueue {
    int id[MAX], priority[MAX];
    int count;

public:
    PriorityQueue() {
        count = 0;
    }

    void enqueue(int patientID, int p) {
        if (count == MAX) {
            cout << "Queue is full!\n";
            return;
        }

        id[count] = patientID;
        priority[count] = p;
        count++;

        cout << "Patient P" << patientID
             << " added with priority " << p << ".\n";
    }

    void treatPatient() {
        if (count == 0) {
            cout << "No patients waiting.\n";
            return;
        }

        int best = 0;
        for (int i = 1; i < count; i++) {
            if (priority[i] < priority[best])
                best = i;
        }

        cout << "Treating patient P" << id[best]
             << " (Priority " << priority[best] << ")\n";

        for (int i = best; i < count - 1; i++) {
            id[i] = id[i + 1];
            priority[i] = priority[i + 1];
        }
        count--;
    }

    void display() {
        if (count == 0) {
            cout << "No patients waiting.\n";
            return;
        }

        cout << "Waiting patients:\n";
        for (int i = 0; i < count; i++)
            cout << "P" << id[i]
                 << " - Priority " << priority[i] << "\n";
    }
};

int main() {
    PriorityQueue q;

    q.enqueue(101, 3);
    q.enqueue(102, 1);
    q.enqueue(103, 2);

    q.display();
    q.treatPatient();
    q.display();

    return 0;
}

