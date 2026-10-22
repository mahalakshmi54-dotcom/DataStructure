#include <iostream>
using namespace std;

struct Node {
    int coach;
    Node* next;
};

Node* head = nullptr;

void addBeginning(int x) {
    Node* p = new Node{x, head};
    head = p;
}

void addEnd(int x) {
    Node* p = new Node{x, nullptr};

    if (head == nullptr) {
        head = p;
        return;
    }

    Node* temp = head;
    while (temp->next != nullptr)
        temp = temp->next;

    temp->next = p;
}

void removeCoach(int x) {
    Node* temp = head;
    Node* prev = nullptr;

    while (temp != nullptr && temp->coach != x) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == nullptr) {
        cout << "Coach not found.\n";
        return;
    }

    if (prev == nullptr)
        head = temp->next;
    else
        prev->next = temp->next;

    delete temp;
    cout << "Coach removed.\n";
}

void display() {
    Node* temp = head;
    while (temp != nullptr) {
        cout << "Coach" << temp->coach << " -> ";
        temp = temp->next;
    }
    cout << "NULL\n";
}

int main() {
    addEnd(1);
    addEnd(2);
    addEnd(3);
    addEnd(4);

    cout << "Initial train: ";
    display();

    addBeginning(0);
    cout << "After adding at beginning: ";
    display();

    addEnd(5);
    cout << "After adding at end: ";
    display();

    removeCoach(3);
    cout << "After removing Coach3: ";
    display();

    return 0;
}
