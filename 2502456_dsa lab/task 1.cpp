
#include <iostream>
#include <string>
using namespace std;

class Student {
public:
    string name;
    int rollNo;
    int marks;
    Student* left;
    Student* right;

    Student(string n, int r, int m) {
        name = n;
        rollNo = r;
        marks = m;
        left = NULL;
        right = NULL;
    }
};

class MaxHeap {
private:
    Student* heap[100];
    int size;

public:
    MaxHeap() {
        size = 0;
    }

    void heapifyUp(int index) {
        while (index > 0) {
            int parent = (index - 1) / 2;

            if (heap[index]->marks > heap[parent]->marks) {
                swap(heap[index], heap[parent]);
                index = parent;
            }
            else {
                break;
            }
        }
    }

    void insert(string name, int rollNo, int marks) {
        Student* newStudent = new Student(name, rollNo, marks);

        heap[size] = newStudent;
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
                 << " | Roll No: " << heap[i]->rollNo
                 << " | Marks: " << heap[i]->marks << endl;
        }
    }

    void heapifyDown(int index) {
        while (true) {
            int largest = index;
            int left = 2 * index + 1;
            int right = 2 * index + 2;

            if (left < size &&
                heap[left]->marks > heap[largest]->marks) {
                largest = left;
            }

            if (right < size &&
                heap[right]->marks > heap[largest]->marks) {
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

    void deleteHighest() {
        if (size == 0) {
            cout << "Heap is empty!" << endl;
            return;
        }

        cout << "\nDeleted Student: "
             << heap[0]->name
             << " | Marks: " << heap[0]->marks << endl;

        delete heap[0];

        heap[0] = heap[size - 1];
        size--;

        if (size > 0) {
            heapifyDown(0);
        }
    }
};

int main() {
    MaxHeap h;

    h.insert("Ali", 101, 85);
    h.insert("Ahmed", 102, 95);
    h.insert("Sara", 103, 78);
    h.insert("Ayesha", 104, 92);
    h.insert("Usman", 105, 88);
    h.insert("Fatima", 106, 98);

    cout << "Original Max Heap:\n";
    h.display();

    h.deleteHighest();

    cout << "\nUpdated Max Heap:\n";
    h.display();

    return 0;
}

