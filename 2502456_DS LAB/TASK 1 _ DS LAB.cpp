
#include <iostream>
#include <string>
#include <limits>
using namespace std;

struct StaffNode {
    string name;
    StaffNode* left;
    StaffNode* right;

    StaffNode(string n) {
        name = n;
        left = NULL;
        right = NULL;
    }
};

void displayStaff(StaffNode* root) {
    if (root == NULL)
        return;

    cout << "Staff: " << root->name << endl;

    cout << "Left Child: ";
    if (root->left != NULL)
        cout << root->left->name;
    else
        cout << "NULL";

    cout << endl;

    cout << "Right Child: ";
    if (root->right != NULL)
        cout << root->right->name;
    else
        cout << "NULL";

    cout << "\n\n";

    displayStaff(root->left);
    displayStaff(root->right);
}

void deleteStaffTree(StaffNode* root) {
    if (root == NULL)
        return;

    deleteStaffTree(root->left);
    deleteStaffTree(root->right);
    delete root;
}

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

        if (id < node->id)
            node->left = insertNode(node->left, id, inserted);
        else if (id > node->id)
            node->right = insertNode(node->right, id, inserted);

        return node;
    }

    bool searchNode(Node* node, int id, int& visits) const {
        if (node == NULL)
            return false;

        visits++;

        if (node->id == id)
            return true;

        if (id < node->id)
            return searchNode(node->left, id, visits);

        return searchNode(node->right, id, visits);
    }

    Node* minimumNode(Node* node) const {
        while (node != NULL && node->left != NULL)
            node = node->left;

        return node;
    }

    Node* deleteNode(Node* node, int id, bool& deleted) {
        if (node == NULL)
            return NULL;

        if (id < node->id) {
            node->left = deleteNode(node->left, id, deleted);
        }
        else if (id > node->id) {
            node->right = deleteNode(node->right, id, deleted);
        }
        else {
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

            Node* successor = minimumNode(node->right);
            node->id = successor->id;

            bool ignored = false;
            node->right = deleteNode(
                node->right, successor->id, ignored
            );
        }

        return node;
    }

    void inorder(Node* node) const {
        if (node == NULL)
            return;

        inorder(node->left);
        cout << node->id << " ";
        inorder(node->right);
    }

    void destroy(Node* node) {
        if (node == NULL)
            return;

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

    bool search(int id, int& visits) const {
        visits = 0;
        return searchNode(root, id, visits);
    }

    bool remove(int id) {
        bool deleted = false;
        root = deleteNode(root, id, deleted);
        return deleted;
    }

    int getMinimum() const {
        Node* temp = minimumNode(root);
        return temp->id;
    }

    void displayInorder() const {
        inorder(root);
        cout << endl;
    }
};

void searchTest(BST& tree, int id) {
    int visits = 0;
    bool found = tree.search(id, visits);

    cout << "Searching ID " << id << ": ";

    if (found)
        cout << "ID found";
    else
        cout << "ID not found";

    cout << ", Node visits: " << visits << endl;
}

void fillBST(BST& tree) {
    int ids[] = {48, 28, 68, 18, 38, 58, 78};

    for (int i = 0; i < 7; i++)
        tree.insert(ids[i]);
}

void deletionTest(int type) {
    BST tree;
    fillBST(tree);

    if (type == 1) {
        cout << "\nLeaf Node Deletion Test\n";
        tree.remove(18);
        cout << "Deleted ID: 18\n";
    }
    else if (type == 2) {
        cout << "\nOne Child Deletion Test\n";
        tree.remove(18);
        tree.remove(28);
        cout << "Deleted ID: 28\n";
    }
    else {
        cout << "\nTwo Children Deletion Test\n";
        tree.remove(28);
        cout << "Deleted ID: 28\n";
    }

    cout << "Remaining IDs: ";
    tree.displayInorder();
}

int main() {
    cout << "UNIVERSITY STAFF MANAGEMENT SYSTEM\n";

    cout << "\nGENERAL BINARY TREE\n";

    StaffNode* staff = new StaffNode("Vice Chancellor");
    staff->left = new StaffNode("Registrar");
    staff->right = new StaffNode("Treasurer");
    staff->left->left = new StaffNode("Admissions Officer");
    staff->left->right = new StaffNode("HR Manager");
    staff->right->left = new StaffNode("IT Manager");
    staff->right->right = new StaffNode("Library Manager");

    displayStaff(staff);
    deleteStaffTree(staff);

    cout << "\nBINARY SEARCH TREE\n";

    BST tree;
    fillBST(tree);

    for (int i = 1; i <= 3; i++) {
        int id;

        cout << "Enter additional staff ID " << i << ": ";
        cin >> id;

        if (tree.insert(id))
            cout << "ID inserted successfully.\n";
        else
            cout << "Duplicate ID rejected.\n";
    }

    cout << "\nSEARCH TESTS\n";

    searchTest(tree, 48);
    searchTest(tree, 999);

    int smallest = tree.getMinimum();

    if (smallest > numeric_limits<int>::min())
        searchTest(tree, smallest - 1);
    else
        cout << "Cannot test a smaller integer ID.\n";

    cout << "\nDELETE STAFF ID\n";

    int id;
    cout << "Enter ID to delete: ";
    cin >> id;

    if (tree.remove(id))
        cout << "ID deleted successfully.\n";
    else
        cout << "ID not found.\n";

    cout << "IDs in ascending order: ";
    tree.displayInorder();

    cout << "\nDELETION CASE TESTS\n";

    deletionTest(1);
    deletionTest(2);
    deletionTest(3);

    return 0;
}

