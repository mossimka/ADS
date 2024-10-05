#include <iostream>
#include <set>

using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int data) {
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
    
    void mode(int size) {
        set<int, greater<int>> modes;
        int max = 1;
        for (int i = 0; i < size; i++) {
            Node* current = head;
            int key = current->data;
            current = current->next;
            int counter = 1;
            
            while (current != nullptr) {
                if (current->data == key) {
                    counter++;
                }
                current = current->next;
            }
            if (counter > max) {
                max = counter;
                modes.clear();
                modes.insert(key);
            } else if (counter == max) {
                modes.insert(key);
            }
            head = head->next;
        }
        for (int el : modes) {
            cout << el << ' ';
        }
    }
};

int main() {
    int size;
    cin >> size;
    LinkedList list;
    for (int i = 0; i < size; ++i) {
        int num;
        cin >> num;
        list.insertAtTheEnd(num);
    }
    list.mode(size);
    return 0;
}
