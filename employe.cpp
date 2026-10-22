#include <iostream>
using namespace std;

struct Node {
    int id;
    Node* left;
    Node* right;

    Node(int value) {
        id = value;
        left = right = nullptr;
    }
};

Node* insert(Node* root, int id) {
    if (root == nullptr)
        return new Node(id);

    if (id < root->id)
        root->left = insert(root->left, id);
    else if (id > root->id)
        root->right = insert(root->right, id);

    return root;
}

void inorder(Node* root) {
    if (root != nullptr) {
        inorder(root->left);
        cout << root->id << " ";
        inorder(root->right);
    }
}

bool search(Node* root, int id) {
    if (root == nullptr)
        return false;

    if (root->id == id)
        return true;

    if (id < root->id)
        return search(root->left, id);

    return search(root->right, id);
}

int main() {
    Node* root = nullptr;
    int ids[] = {50, 30, 70, 20, 40, 60, 80};

    for (int id : ids)
        root = insert(root, id);

    cout << "Employee IDs in sorted order: ";
    inorder(root);
    cout << endl;

    int key;
    cout << "Enter employee ID to search: ";
    cin >> key;

    if (search(root, key))
        cout << "Employee ID found.\n";
    else
        cout << "Employee ID not found.\n";

    return 0;
}
