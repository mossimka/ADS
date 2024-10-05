#include <iostream>

using namespace std;

class Node {
public:
    string data;
    Node* next;

    Node(string data) {
        this->data = data;
        this->next = nullptr;
    }
};

class LinkedList {
    Node* head;
    Node* tail;

public:
    LinkedList() {
        head = nullptr;
        tail = nullptr;
    }

    // Insert node at the end
    void insertAtTheEnd(string newData) {
        Node* newNode = new Node(newData);
        if (head == nullptr) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }
    void shift(int key) {
        for (int i = 0; i < key; ++i) {
            Node* temp = head;
            head = head->next;
            tail->next = temp;
            temp->next = nullptr;
            tail = temp;
        }
    }
    void printList() {
        Node* current = head;
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
};

int main() {
    int size, dist;
    cin >> size >> dist;
    LinkedList list;
    for (int i = 0; i < size; ++i) {
        string word;
        cin >> word;
        list.insertAtTheEnd(word);
    }
    list.shift(dist);
    list.printList();
    return 0;
}

