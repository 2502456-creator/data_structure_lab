
#include <iostream>
#include <string>
#include <queue>
#include <algorithm>
using namespace std;

class Node {
public:
    int id;
    string location;
    string severity;
    int height;
    Node* left;
    Node* right;

    Node(int i, string loc, string sev) {
        id = i;
        location = loc;
        severity = sev;
        height = 1;
        left = NULL;
        right = NULL;
    }
};

int getHeight(Node* root) {
    if (root == NULL)
        return 0;

    return root->height;
}

int getBalance(Node* root) {
    if (root == NULL)
        return 0;

    return getHeight(root->left) - getHeight(root->right);
}

Node* rightRotate(Node* y) {
    Node* x = y->left;
    Node* T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = 1 + max(getHeight(y->left),
                        getHeight(y->right));

    x->height = 1 + max(getHeight(x->left),
                        getHeight(x->right));

    return x;
}

Node* leftRotate(Node* x) {
    Node* y = x->right;
    Node* T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = 1 + max(getHeight(x->left),
                        getHeight(x->right));

    y->height = 1 + max(getHeight(y->left),
                        getHeight(y->right));

    return y;
}

Node* insert(Node* root, int id,
             string location, string severity) {

    if (root == NULL)
        return new Node(id, location, severity);

    if (id < root->id)
        root->left = insert(root->left, id, location, severity);

    else if (id > root->id)
        root->right = insert(root->right, id, location, severity);

    else
        return root;

    root->height = 1 + max(getHeight(root->left),
                           getHeight(root->right));

    int balance = getBalance(root);

    if (balance > 1 && id < root->left->id)
        return rightRotate(root);

    if (balance < -1 && id > root->right->id)
        return leftRotate(root);

    if (balance > 1 && id > root->left->id) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    if (balance < -1 && id < root->right->id) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

Node* search(Node* root, int id) {
    if (root == NULL || root->id == id)
        return root;

    if (id < root->id)
        return search(root->left, id);

    return search(root->right, id);
}

Node* findMin(Node* root) {
    if (root == NULL)
        return NULL;

    while (root->left != NULL)
        root = root->left;

    return root;
}

Node* deleteNode(Node* root, int id) {
    if (root == NULL)
        return root;

    if (id < root->id)
        root->left = deleteNode(root->left, id);

    else if (id > root->id)
        root->right = deleteNode(root->right, id);

    else {
        if (root->left == NULL || root->right == NULL) {
            Node* temp;

            if (root->left != NULL)
                temp = root->left;
            else
                temp = root->right;

            delete root;
            return temp;
        }

        Node* temp = findMin(root->right);

        root->id = temp->id;
        root->location = temp->location;
        root->severity = temp->severity;

        root->right = deleteNode(root->right, temp->id);
    }

    root->height = 1 + max(getHeight(root->left),
                           getHeight(root->right));

    int balance = getBalance(root);

    if (balance > 1 && getBalance(root->left) >= 0)
        return rightRotate(root);

    if (balance > 1 && getBalance(root->left) < 0) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    if (balance < -1 && getBalance(root->right) <= 0)
        return leftRotate(root);

    if (balance < -1 && getBalance(root->right) > 0) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

void inorder(Node* root) {
    if (root == NULL)
        return;

    inorder(root->left);

    cout << root->id << " "
         << root->location << " "
         << root->severity << endl;

    inorder(root->right);
}

void levelOrder(Node* root) {
    if (root == NULL)
        return;

    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        Node* temp = q.front();
        q.pop();

        cout << temp->id << " ";

        if (temp->left != NULL)
            q.push(temp->left);

        if (temp->right != NULL)
            q.push(temp->right);
    }
}

void displayBalance(Node* root) {
    if (root == NULL)
        return;

    displayBalance(root->left);

    cout << "ID: " << root->id
         << " Height: " << root->height
         << " Balance Factor: " << getBalance(root)
         << endl;

    displayBalance(root->right);
}

void displayTree(Node* root, int space = 0) {
    if (root == NULL)
        return;

    space += 5;

    displayTree(root->right, space);

    cout << endl;

    for (int i = 5; i < space; i++)
        cout << " ";

    cout << root->id << endl;

    displayTree(root->left, space);
}

int main() {
    Node* root = NULL;

    root = insert(root, 30, "Islamabad", "High");
    root = insert(root, 20, "Lahore", "Medium");
    root = insert(root, 40, "Karachi", "High");
    root = insert(root, 10, "Peshawar", "Critical");
    root = insert(root, 25, "Quetta", "Low");
    root = insert(root, 35, "Multan", "Medium");
    root = insert(root, 50, "Sialkot", "High");
    root = insert(root, 5, "Murree", "Low");
    root = insert(root, 15, "Faisalabad", "Critical");
    root = insert(root, 27, "Swat", "Medium");
    root = insert(root, 45, "Gilgit", "High");
    root = insert(root, 60, "Hunza", "Critical");

    cout << "Inorder Traversal:\n";
    inorder(root);

    int key = 35;

    Node* result = search(root, key);

    cout << "\nSearching Emergency ID " << key << ":\n";

    if (result != NULL) {
        cout << "Record Found: "
             << result->id << " "
             << result->location << " "
             << result->severity << endl;
    }
    else {
        cout << "Record Not Found\n";
    }

    cout << "\nDeleting Emergency ID 20\n";
    root = deleteNode(root, 20);

    cout << "\nInorder Traversal After Deletion:\n";
    inorder(root);

    cout << "\nLevel Order Traversal (BFS):\n";
    levelOrder(root);

    cout << "\n\nHeight and Balance Factor:\n";
    displayBalance(root);

    cout << "\nFinal Balanced AVL Tree:\n";
    displayTree(root);

    return 0;
}

