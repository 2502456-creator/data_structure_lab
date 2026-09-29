#include <iostream>
using namespace std;

class Node
{
public:
    string patientID;
    Node* next;
};

void addPatient(Node*& head, string id)
{
    Node* newNode = new Node();

    newNode->patientID = id;
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

void displayPatients(Node* head)
{
    Node* current = head;

    cout << "Waiting Patients: ";

    while (current != NULL)
    {
        cout << current->patientID << " -> ";
        current = current->next;
    }

    cout << "NULL" << endl;
}

void removeFirstPatient(Node*& head)
{
    if (head == NULL)
    {
        cout << "No patients in queue." << endl;
        return;
    }

    Node* temp = head;

    cout << "Patient " << head->patientID
         << " is being served." << endl;

    head = head->next;

    delete temp;
}

int main()
{
    Node* head = NULL;

    addPatient(head, "P101");
    addPatient(head, "P102");
    addPatient(head, "P103");
    addPatient(head, "P104");

    displayPatients(head);

    removeFirstPatient(head);

    cout << "Updated Queue: ";
    displayPatients(head);

    return 0;
}
