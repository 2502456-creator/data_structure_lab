
#include <iostream>
#include <string>
using namespace std;

class Medicine {
public:
    string name;
    int medicineID;
    int expiryDate;
    Medicine* left;
    Medicine* right;

    Medicine(string n, int id, int date) {
        name = n;
        medicineID = id;
        expiryDate = date;
        left = NULL;
        right = NULL;
    }
};

class MinHeap {
private:
    Medicine* heap[100];
    int size;

public:
    MinHeap() {
        size = 0;
    }

    void heapifyUp(int index) {
        while (index > 0) {
            int parent = (index - 1) / 2;

            if (heap[index]->expiryDate < heap[parent]->expiryDate) {
                swap(heap[index], heap[parent]);
                index = parent;
            }
            else {
                break;
            }
        }
    }

    void insert(string name, int id, int date) {
        Medicine* newMedicine = new Medicine(name, id, date);

        heap[size] = newMedicine;
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
                 << " | Medicine ID: " << heap[i]->medicineID
                 << " | Expiry Date: " << heap[i]->expiryDate << endl;
        }
    }

    void heapifyDown(int index) {
        while (true) {
            int smallest = index;
            int left = 2 * index + 1;
            int right = 2 * index + 2;

            if (left < size &&
                heap[left]->expiryDate < heap[smallest]->expiryDate) {
                smallest = left;
            }

            if (right < size &&
                heap[right]->expiryDate < heap[smallest]->expiryDate) {
                smallest = right;
            }

            if (smallest != index) {
                swap(heap[index], heap[smallest]);
                index = smallest;
            }
            else {
                break;
            }
        }
    }

    void deleteNearestExpiry() {
        if (size == 0) {
            cout << "No medicines available!" << endl;
            return;
        }

        cout << "\nDeleted Medicine:\n";
        cout << "Name: " << heap[0]->name << endl;
        cout << "Medicine ID: " << heap[0]->medicineID << endl;
        cout << "Expiry Date: " << heap[0]->expiryDate << endl;

        delete heap[0];

        heap[0] = heap[size - 1];
        size--;

        if (size > 0) {
            heapifyDown(0);
        }
    }
};

int main() {
    MinHeap h;

    h.insert("Panadol", 101, 20261215);
    h.insert("Brufen", 102, 20261125);
    h.insert("Calpol", 103, 20270110);
    h.insert("Augmentin", 104, 20261201);
    h.insert("Disprin", 105, 20261130);
    h.insert("Flagyl", 106, 20270315);

    cout << "Original Medicine Min Heap:\n";
    h.display();

    h.deleteNearestExpiry();

    cout << "\nUpdated Medicine Min Heap:\n";
    h.display();

    return 0;
}

