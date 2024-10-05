#include <iostream>
#include <cmath>
#include <cstdint>

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
    int getClosest(int key, int size) {
        Node* temp = head;
        int distance = INT32_MAX;
        int closestId = 0;
        int counter = 0;

        while (temp != nullptr) {
            int currentDistance = abs(temp->data - key);
            if (currentDistance < distance) {
                distance = currentDistance;
                closestId = counter;
            }
            temp = temp->next;
            counter++;
        }
        return closestId;
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

    int key;
    cin >> key;

    cout << list.getClosest(key, size) << endl;

    return 0;
}
