#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Node {
public:
    char data;
    Node* next;

    Node(char data) {
        this->data = data;
        this->next = nullptr;
    }
};

class LinkedList {
    Node* head;
    Node* tail;
public:
    LinkedList() : head(nullptr), tail(nullptr) {}
    void insertAtTheEnd(char newData) {
        Node* newNode = new Node(newData);
        if (head == nullptr) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }
    void eraseFront() {
        if (head == nullptr) return;
        Node* temp = head;
        head = head->next;
        delete temp;
        if (head == nullptr) {
            tail = nullptr;
        }
    }
    void clear() {
        while (head != nullptr) {
            eraseFront();
        }
    }
    bool empty() {
        return head == nullptr;
    }
    void guests() {
        unordered_map<char, int> freq;
        vector<char> result;
        Node* current = head;

        while (current != nullptr) {
            freq[current->data]++;
            
            // Check for the most recent unique element
            char mostRecentUnique = '-1'; // Default value for no unique character
            for (auto it = freq.begin(); it != freq.end(); ++it) {
                if (it->second == 1) {
                    mostRecentUnique = it->first; // Update to the latest unique char
                }
            }
            
            result.push_back(mostRecentUnique);
            current = current->next;
        }
        
        for (const char& c : result) {
            cout << c << " ";
        }
        cout << endl;
    }

};

int main() {
    int num;
    cin >> num;
    for(int i = 0; i < num; i++) {
        int size;
        cin >> size;
        LinkedList list;
        for (int j = 0; j < size; ++j) {
            char data;
            cin >> data;
            list.insertAtTheEnd(data);
        }
        list.guests();
        list.clear();
    }
    
    return 0;
}