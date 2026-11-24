
#include <iostream>
#include <string>
using namespace std;

class Patient {
public:
    string name;
    int patientID;
    int priority;
    Patient* left;
    Patient* right;

    Patient(string n, int id, int p) {
        name = n;
        patientID = id;
        priority = p;
        left = NULL;
        right = NULL;
    }
};

class MaxHeap {
private:
    Patient* heap[100];
    int size;

public:
    MaxHeap() {
        size = 0;
    }

    void heapifyUp(int index) {
        while (index > 0) {
            int parent = (index - 1) / 2;

            if (heap[index]->priority > heap[parent]->priority) {
                swap(heap[index], heap[parent]);
                index = parent;
            }
            else {
                break;
            }
        }
    }

    void insert(string name, int id, int priority) {
        Patient* newPatient = new Patient(name, id, priority);

        heap[size] = newPatient;
        heapifyUp(size);
        size++;
    }

    void display() {
        if (size == 0) {
            cout << "Heap is empty!" << endl;
            return;
        }

        for (int i = 0; i < size; i++) {
            cout << "Name: " << heap[i]->name
                 << " | Patient ID: " << heap[i]->patientID
                 << " | Priority: " << heap[i]->priority << endl;
        }
    }

    void displayHighestPriority() {
        if (size == 0) {
            cout << "No patients available!" << endl;
            return;
        }

        cout << "\nPatient with Highest Priority:\n";
        cout << "Name: " << heap[0]->name << endl;
        cout << "Patient ID: " << heap[0]->patientID << endl;
        cout << "Priority: " << heap[0]->priority << endl;
    }

    void heapifyDown(int index) {
        while (true) {
            int largest = index;
            int left = 2 * index + 1;
            int right = 2 * index + 2;

            if (left < size &&
                heap[left]->priority > heap[largest]->priority) {
                largest = left;
            }

            if (right < size &&
                heap[right]->priority > heap[largest]->priority) {
                largest = right;
            }

            if (largest != index) {
                swap(heap[index], heap[largest]);
                index = largest;
            }
            else {
                break;
            }
        }
    }

    void deleteHighestPriority() {
        if (size == 0) {
            cout << "No patients available!" << endl;
            return;
        }

        cout << "\nTreated Patient: " << heap[0]->name
             << " | Priority: " << heap[0]->priority << endl;

        delete heap[0];

        heap[0] = heap[size - 1];
        size--;

        if (size > 0) {
            heapifyDown(0);
        }
    }

    void displayNextPatient() {
        if (size == 0) {
            cout << "No patients remaining!" << endl;
            return;
        }

        cout << "\nNext Patient for Treatment:\n";
        cout << "Name: " << heap[0]->name << endl;
        cout << "Patient ID: " << heap[0]->patientID << endl;
        cout << "Priority: " << heap[0]->priority << endl;
    }
};

int main() {
    MaxHeap h;

    h.insert("Ali", 101, 4);
    h.insert("Ahmed", 102, 8);
    h.insert("Sara", 103, 3);
    h.insert("Ayesha", 104, 9);
    h.insert("Usman", 105, 6);
    h.insert("Fatima", 106, 7);

    cout << "Hospital Emergency Patient List:\n";
    h.display();

    h.displayHighestPriority();

    h.deleteHighestPriority();

    cout << "\nUpdated Patient List:\n";
    h.display();

    h.displayNextPatient();

    return 0;
}

