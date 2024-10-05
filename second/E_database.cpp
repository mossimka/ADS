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

public:
    LinkedList() {
        head = nullptr;
    }
    void insertAtTheFront(string new_data) {
        Node* new_node = new Node(new_data);
        new_node->next = head;
        head = new_node;
    }
    void deleteDuplicates() {
        Node* current = head;
        while (current != nullptr) {
            Node* runner = current;
            while (runner->next != nullptr) {
                if (runner->next->data == current->data) {
                    Node* temp = runner->next;
                    runner->next = runner->next->next;
                    delete temp; 
                } else {
                    break;
                }
            }
            current = current->next;
        }
    }
    int size(){
        Node* current = head;
        int counter = 0;
        while(current != nullptr){
            counter++;
            current = current->next;
        }
        return counter;
    }
    void printList() {
            Node* current = head;
            while (current != nullptr) {
                cout << current->data << endl;
                current = current->next;
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
        list.insertAtTheFront(word);
    }
    list.deleteDuplicates();
    cout << "All in all: " << list.size() << "\nStudents:\n";
    list.printList();
    return 0;
}