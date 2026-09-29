#include <iostream>
using namespace std;

class Node
{
public:
    string productID;
    Node* next;
};

void addProduct(Node*& head, string id)
{
    Node* newNode = new Node();

    newNode->productID = id;
    newNode->next = NULL;

    if (head == NULL)
    {
        head = newNode;
        return;
    }

    Node* current = head;

    while (current->next != NULL)
    {
        current = current->next;
    }

    current->next = newNode;
}

void displayCart(Node* head)
{
    Node* current = head;

    cout << "Shopping Cart: ";

    while (current != NULL)
    {
        cout << current->productID << " -> ";
        current = current->next;
    }

    cout << "NULL" << endl;
}

void removeProduct(Node*& head, string id)
{
    if (head == NULL)
    {
        cout << "Cart is empty." << endl;
        return;
    }

    if (head->productID == id)
    {
        Node* temp = head;
        head = head->next;
        delete temp;

        cout << "Product " << id << " removed." << endl;
        return;
    }

    Node* current = head;

    while (current->next != NULL)
    {
        if (current->next->productID == id)
        {
            Node* temp = current->next;

            current->next = temp->next;

            delete temp;

            cout << "Product " << id << " removed." << endl;
            return;
        }

        current = current->next;
    }

    cout << "Product " << id << " not found." << endl;
}

int main()
{
    Node* head = NULL;

    addProduct(head, "P101");
    addProduct(head, "P205");
    addProduct(head, "P310");
    addProduct(head, "P415");

    displayCart(head);

    string productToRemove;

    cout << "Remove Product: ";
    cin >> productToRemove;

    removeProduct(head, productToRemove);

    displayCart(head);

    return 0;
}
