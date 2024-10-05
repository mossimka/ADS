#include <iostream>

using namespace std;

class Node{
public:
    int data;
    Node* next;

    Node(int data){
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
    void insertAtTheEnd(int newData) {
        Node* newNode = new Node(newData);
        if (head == nullptr) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }
    void insertAtTheFront(int newData) {
        Node* newNode = new Node(newData);
        newNode->next = head;
        head = newNode;
    }
    void insertAtThePosition(int newData, int position){
        Node* newNode = new Node(newData);
        Node* current = head;
        for(int i = 1; i < position; ++i){
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }
    void printList(){
        Node* current = head;
        while(current != nullptr){
            cout << current->data << ' ';
            current = current->next;
        }
        cout << endl;
    }
};

int main(){
    int size;
    cin >> size;
    LinkedList list;
    for(int i = 0; i<size; i++){
        int num;
        cin >> num;
        list.insertAtTheEnd(num);
    }
    int extra, position;
    cin >> extra >> position;
    if(position == 0){
        list.insertAtTheFront(extra);
    } else {
        list.insertAtThePosition(extra, position);
    }
    list.printList();
    return 0;
}