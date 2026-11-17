
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Node {
public:
    int flightNo;
    string destination;
    string departureTime;
    Node* left;
    Node* right;

    Node(int no, string dest, string time) {
        flightNo = no;
        destination = dest;
        departureTime = time;
        left = NULL;
        right = NULL;
    }
};

Node* insert(Node* root, int no, string dest, string time) {
    if (root == NULL)
        return new Node(no, dest, time);

    if (no < root->flightNo)
        root->left = insert(root->left, no, dest, time);
    else if (no > root->flightNo)
        root->right = insert(root->right, no, dest, time);

    return root;
}

Node* search(Node* root, int no) {
    if (root == NULL || root->flightNo == no)
        return root;

    if (no < root->flightNo)
        return search(root->left, no);

    return search(root->right, no);
}

Node* findMin(Node* root) {
    if (root == NULL)
        return NULL;

    while (root->left != NULL)
        root = root->left;

    return root;
}

Node* findMax(Node* root) {
    if (root == NULL)
        return NULL;

    while (root->right != NULL)
        root = root->right;

    return root;
}

Node* deleteNode(Node* root, int no) {
    if (root == NULL)
        return root;

    if (no < root->flightNo)
        root->left = deleteNode(root->left, no);

    else if (no > root->flightNo)
        root->right = deleteNode(root->right, no);

    else {
        if (root->left == NULL) {
            Node* temp = root->right;
            delete root;
            return temp;
        }
        else if (root->right == NULL) {
            Node* temp = root->left;
            delete root;
            return temp;
        }

        Node* temp = findMin(root->right);

        root->flightNo = temp->flightNo;
        root->destination = temp->destination;
        root->departureTime = temp->departureTime;

        root->right = deleteNode(root->right, temp->flightNo);
    }

    return root;
}

void inorder(Node* root) {
    if (root == NULL)
        return;

    inorder(root->left);

    cout << root->flightNo << " "
         << root->destination << " "
         << root->departureTime << endl;

    inorder(root->right);
}

void preorder(Node* root) {
    if (root == NULL)
        return;

    cout << root->flightNo << " ";

    preorder(root->left);
    preorder(root->right);
}

void postorder(Node* root) {
    if (root == NULL)
        return;

    postorder(root->left);
    postorder(root->right);

    cout << root->flightNo << " ";
}

int countNodes(Node* root) {
    if (root == NULL)
        return 0;

    return 1 + countNodes(root->left)
             + countNodes(root->right);
}

int height(Node* root) {
    if (root == NULL)
        return 0;

    return 1 + max(height(root->left),
                   height(root->right));
}

void displayTree(Node* root, int space = 0) {
    if (root == NULL)
        return;

    space += 5;

    displayTree(root->right, space);

    cout << endl;

    for (int i = 5; i < space; i++)
        cout << " ";

    cout << root->flightNo << endl;

    displayTree(root->left, space);
}

int main() {
    Node* root = NULL;

    root = insert(root, 50, "London", "08:00");
    root = insert(root, 30, "Dubai", "09:00");
    root = insert(root, 70, "Istanbul", "10:00");
    root = insert(root, 20, "Doha", "11:00");
    root = insert(root, 40, "Paris", "12:00");
    root = insert(root, 60, "Tokyo", "13:00");
    root = insert(root, 80, "NewYork", "14:00");
    root = insert(root, 10, "Beijing", "15:00");
    root = insert(root, 25, "Riyadh", "16:00");
    root = insert(root, 35, "Rome", "17:00");
    root = insert(root, 45, "Berlin", "18:00");
    root = insert(root, 65, "Toronto", "19:00");

    cout << "All Flight Records:\n";
    inorder(root);

    int key = 60;

    Node* result = search(root, key);

    cout << "\nSearching Flight " << key << ":\n";

    if (result != NULL) {
        cout << "Flight Found: "
             << result->flightNo << " "
             << result->destination << " "
             << result->departureTime << endl;
    }
    else {
        cout << "Flight Not Found\n";
    }

    cout << "\nDeleting Flight 10 (Leaf Node)\n";
    root = deleteNode(root, 10);

    cout << "Deleting Flight 20 (One Child)\n";
    root = deleteNode(root, 20);

    cout << "Deleting Flight 50 (Two Children)\n";
    root = deleteNode(root, 50);

    cout << "\nInorder Traversal:\n";
    inorder(root);

    cout << "\nPreorder Traversal:\n";
    preorder(root);

    cout << "\n\nPostorder Traversal:\n";
    postorder(root);

    cout << "\n\nMinimum Flight Number: ";
    Node* minNode = findMin(root);

    if (minNode != NULL)
        cout << minNode->flightNo;

    cout << "\nMaximum Flight Number: ";
    Node* maxNode = findMax(root);

    if (maxNode != NULL)
        cout << maxNode->flightNo;

    cout << "\nTotal Flights: "
         << countNodes(root);

    cout << "\nTree Height: "
         << height(root);

    cout << "\n\nFinal BST Structure:\n";
    displayTree(root);

    return 0;
}

