
#include <iostream>
#include <string>
using namespace std;

class Order {
public:
    int orderID;
    string customerName;
    int amount;
    Order* left;
    Order* right;

    Order(int id, string name, int a) {
        orderID = id;
        customerName = name;
        amount = a;
        left = NULL;
        right = NULL;
    }
};

class MaxHeap {
private:
    Order* heap[100];
    int size;

public:
    MaxHeap() {
        size = 0;
    }

    void heapifyUp(int index) {
        while (index > 0) {
            int parent = (index - 1) / 2;

            if (heap[index]->amount > heap[parent]->amount) {
                swap(heap[index], heap[parent]);
                index = parent;
            }
            else {
                break;
            }
        }
    }

    void insert(int id, string name, int amount) {
        Order* newOrder = new Order(id, name, amount);

        heap[size] = newOrder;
        heapifyUp(size);
        size++;
    }

    void heapifyDown(int index) {
        while (true) {
            int largest = index;
            int left = 2 * index + 1;
            int right = 2 * index + 2;

            if (left < size &&
                heap[left]->amount > heap[largest]->amount) {
                largest = left;
            }

            if (right < size &&
                heap[right]->amount > heap[largest]->amount) {
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

    int deleteRoot() {
        int deletedAmount = heap[0]->amount;

        delete heap[0];

        heap[0] = heap[size - 1];
        size--;

        if (size > 0) {
            heapifyDown(0);
        }

        return deletedAmount;
    }

    void heapSort() {
        int sorted[100];
        int n = size;

        for (int i = 0; i < n; i++) {
            sorted[i] = deleteRoot();
        }

        cout << "\nOrder Amounts in Ascending Order:\n";

        for (int i = n - 1; i >= 0; i--) {
            cout << sorted[i] << " ";
        }

        cout << endl;
    }
};

int main() {
    MaxHeap h;

    h.insert(101, "Ali", 5000);
    h.insert(102, "Ahmed", 12000);
    h.insert(103, "Sara", 3000);
    h.insert(104, "Ayesha", 9000);
    h.insert(105, "Usman", 7000);
    h.insert(106, "Fatima", 15000);

    h.heapSort();

    return 0;
}

