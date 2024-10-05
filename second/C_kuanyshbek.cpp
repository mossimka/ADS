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
    void printList() {
        Node* current = head;
        int i=0;
        while (current != nullptr) {
            if(i%2==0){
                cout << current->data << " ";
            }
            current = current->next;
            i++;
        }
    }
};

int main() {
    int size;
    cin >> size;
    LinkedList list;
    for (int i = 0; i < size; ++i) {
        string word;
        cin >> word;
        list.insertAtTheEnd(word);
    }
    list.printList();
    return 0;
}