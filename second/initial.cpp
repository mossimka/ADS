#include <iostream>

using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(){
        this->next = nullptr;
    }
    Node(int newData) {
        this->data = newData;
        this->next = nullptr;
    }
};

class LinkedList {
    Node* head;  
public:
    LinkedList() {
        head = nullptr;
    }
    int front(){
        return head->data;
    }
    int back(){
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        return temp->data;
    }
    void insertAtTheEnd(int newData) {
        Node* newNode = new Node(newData);
        if (head == nullptr) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    void insertAtTheFront(int new_data) {
        Node* new_node = new Node(new_data);
        new_node->next = head;
        head = new_node;
    }
    void printList() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    int n;
    cin >> n;
    LinkedList list;
    for (int i = 0; i < n; i++) {
        int newData;
        cin >> newData;
        list.insertAtTheEnd(newData);
    }
    list.printList();
    
    return 0;
}
