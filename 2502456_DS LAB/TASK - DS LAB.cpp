
#include <iostream>
using namespace std;

class BST {
private:
    struct Node {
        int id;
        Node* left;
        Node* right;

        Node(int value) {
            id = value;
            left = NULL;
            right = NULL;
        }
    };

    Node* root;

    Node* insertNode(Node* node, int id, bool& inserted) {
        if (node == NULL) {
            inserted = true;
            return new Node(id);
        }

        if (id < node->id) {
            node->left = insertNode(node->left, id, inserted);
        } else if (id > node->id) {
            node->right = insertNode(node->right, id, inserted);
        }

        return node;
    }

    bool searchNode(Node* node, int id) const {
        if (node == NULL) {
            return false;
        }

        if (node->id == id) {
            return true;
        }

        if (id < node->id) {
            return searchNode(node->left, id);
        }

        return searchNode(node->right, id);
    }

    Node* minimumNode(Node* node) const {
        while (node != NULL && node->left != NULL) {
            node = node->left;
        }

        return node;
    }

    Node* deleteNode(Node* node, int id, bool& deleted) {
        if (node == NULL) {
            return NULL;
        }

        if (id < node->id) {
            node->left = deleteNode(node->left, id, deleted);
        } else if (id > node->id) {
            node->right = deleteNode(node->right, id, deleted);
        } else {
            deleted = true;

            if (node->left == NULL) {
                Node* temp = node->right;
                delete node;
                return temp;
            }

            if (node->right == NULL) {
                Node* temp = node->left;
                delete node;
                return temp;
            }

            Node* temp = minimumNode(node->right);
            node->id = temp->id;

            bool ignored = false;
            node->right = deleteNode(node->right, temp->id, ignored);
        }

        return node;
    }

    void inorder(Node* node) const {
        if (node == NULL) {
            return;
        }

        inorder(node->left);
        cout << node->id << " ";
        inorder(node->right);
    }

    void preorder(Node* node) const {
        if (node == NULL) {
            return;
        }

        cout << node->id << " ";
        preorder(node->left);
        preorder(node->right);
    }

    void postorder(Node* node) const {
        if (node == NULL) {
            return;
        }

        postorder(node->left);
        postorder(node->right);
        cout << node->id << " ";
    }

    int countNodes(Node* node) const {
        if (node == NULL) {
            return 0;
        }

        return 1 + countNodes(node->left) + countNodes(node->right);
    }

    int height(Node* node) const {
        if (node == NULL) {
            return -1;
        }

        int leftHeight = height(node->left);
        int rightHeight = height(node->right);

        if (leftHeight > rightHeight) {
            return leftHeight + 1;
        }

        return rightHeight + 1;
    }

    void destroy(Node* node) {
        if (node == NULL) {
            return;
        }

        destroy(node->left);
        destroy(node->right);
        delete node;
    }

public:
    BST() {
        root = NULL;
    }

    ~BST() {
        destroy(root);
    }

    bool insert(int id) {
        bool inserted = false;
        root = insertNode(root, id, inserted);
        return inserted;
    }

    bool search(int id) const {
        return searchNode(root, id);
    }

    bool remove(int id) {
        bool deleted = false;
        root = deleteNode(root, id, deleted);
        return deleted;
    }

    void displayInorder() const {
        inorder(root);
        cout << endl;
    }

    void displayPreorder() const {
        preorder(root);
        cout << endl;
    }

    void displayPostorder() const {
        postorder(root);
        cout << endl;
    }

    int getCount() const {
        return countNodes(root);
    }

    int getHeight() const {
        return height(root);
    }
};

int main() {
    BST inventory;

    int initialIDs[] = {55, 35, 75, 25, 45, 65, 85, 40, 50};

    for (int i = 0; i < 9; i++) {
        inventory.insert(initialIDs[i]);
    }

    int choice, id;

    do {
        cout << "\nHOSPITAL AND EMERGENCY INVENTORY MANAGEMENT SYSTEM\n";
        cout << "1. Insert Inventory ID\n";
        cout << "2. Search Inventory ID\n";
        cout << "3. Delete Inventory ID\n";
        cout << "4. Display Inorder Traversal\n";
        cout << "5. Display Preorder Traversal\n";
        cout << "6. Display Postorder Traversal\n";
        cout << "7. Count Total Nodes\n";
        cout << "8. Display Tree Height\n";
        cout << "9. Exit\n";
        cout << "Enter your choice: ";

        if (!(cin >> choice)) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Invalid input. Enter a number.\n";
            continue;
        }

        switch (choice) {
            case 1:
                cout << "Enter inventory ID to insert: ";
                if (!(cin >> id)) {
                    cin.clear();
                    cin.ignore(10000, '\n');
                    cout << "Invalid ID.\n";
                    break;
                }

                if (inventory.insert(id)) {
                    cout << "Inventory ID inserted successfully.\n";
                } else {
                    cout << "Duplicate ID rejected.\n";
                }
                break;

            case 2:
                cout << "Enter inventory ID to search: ";
                if (!(cin >> id)) {
                    cin.clear();
                    cin.ignore(10000, '\n');
                    cout << "Invalid ID.\n";
                    break;
                }

                if (inventory.search(id)) {
                    cout << "Inventory ID found.\n";
                } else {
                    cout << "Inventory ID not found.\n";
                }
                break;

            case 3:
                cout << "Enter inventory ID to delete: ";
                if (!(cin >> id)) {
                    cin.clear();
                    cin.ignore(10000, '\n');
                    cout << "Invalid ID.\n";
                    break;
                }

                if (inventory.remove(id)) {
                    cout << "Inventory ID deleted successfully.\n";
                } else {
                    cout << "Inventory ID not found.\n";
                }
                break;

            case 4:
                cout << "Inorder Traversal: ";
                inventory.displayInorder();
                break;

            case 5:
                cout << "Preorder Traversal: ";
                inventory.displayPreorder();
                break;

            case 6:
                cout << "Postorder Traversal: ";
                inventory.displayPostorder();
                break;

            case 7:
                cout << "Total Nodes: " << inventory.getCount() << endl;
                break;

            case 8:
                cout << "Tree Height: " << inventory.getHeight() << endl;
                break;

            case 9:
                cout << "Program terminated.\n";
                break;

            default:
                cout << "Invalid choice. Try again.\n";
        }

    } while (choice != 9);

    return 0;
}

