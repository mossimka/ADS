#include <iostream>

using namespace std;

class Node {
public:
    Node* prev;
    Node* next;
    string data;
    Node(string data) {
        this->prev = nullptr;
        this->next = nullptr;
        this->data = data;
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
            newNode->prev = tail;
            tail->next = newNode;
            tail = newNode;
        }
    }

    void insertAtTheFront(string newData) {
        Node* newNode = new Node(newData);
        if (head == nullptr) {
            head = newNode;
            tail = newNode;
        } else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }

    bool empty() {
        return head == nullptr;
    }

    string front() {
        return head->data;
    }

    string back() {
        return tail->data;
    }

    void eraseFront() {
        if (head == nullptr) return;
        Node* temp = head;
        head = head->next;
        if (head == nullptr) {
            tail = nullptr;
        } else {
            head->prev = nullptr;
        }
        delete temp;
    }

    void eraseBack() {
        if (tail == nullptr) return;
        Node* temp = tail;
        tail = tail->prev;
        if (tail == nullptr) {
            head = nullptr;
        } else {
            tail->next = nullptr;
        }
        delete temp;
    }

    void clear() {
        while (head != nullptr) {
            eraseFront();
        }
    }
};

int main() {
    string command;
    LinkedList list;
    while (cin >> command) {
        if (command == "add_front") {
            string thingName;
            cin >> thingName;
            list.insertAtTheFront(thingName);
            cout << "ok" << endl;
        }
        if (command == "add_back") {
            string thingName;
            cin >> thingName;
            list.insertAtTheEnd(thingName);
            cout << "ok" << endl;
        }
        if (command == "erase_front") {
            if (list.empty()) {
                cout << "error" << endl;
            } else {
                cout << list.front() << endl;
                list.eraseFront();
            }
        }
        if (command == "erase_back") {
            if (list.empty()) {
                cout << "error" << endl;
            } else {
                cout << list.back() << endl;
                list.eraseBack();
            }
        }
        if (command == "front") {
            if (list.empty()) {
                cout << "error" << endl;
            } else {
                cout << list.front() << endl;
            }
        }
        if (command == "back") {
            if (list.empty()) {
                cout << "error" << endl;
            } else {
                cout << list.back() << endl;
            }
        }
        if (command == "clear") {
            list.clear();
            cout << "ok" << endl;
        }
        if (command == "exit") {
            cout << "goodbye" << endl;
            break;
        }
    }
    return 0;
}
