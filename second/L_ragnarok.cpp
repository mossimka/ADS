#include <iostream> 
#include <climits> 
 
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
    void solve() { 
        int prevSum = head->data; 
        Node* current = head->next; 
        int max = INT_MIN; 
        while(current != nullptr) { 
            if (prevSum < 0) { 
                if (prevSum > max) 
                max = prevSum; 
                prevSum = current->data; 
            } 
            else { 
                if (prevSum > max) 
                max = prevSum; 
                prevSum += current->data; 
            } 
            current = current->next; 
        } 
        if(prevSum > max){
           cout << prevSum;  
        } else cout << max;
    } 
}; 
 
int main() { 
    LinkedList list; 
    int n;
    cin >> n; 
    int temp; 
    for(int i = 0; i < n; i++) { 
        cin >> temp; 
        list.insertAtTheEnd(temp); 
    } 
    list.solve(); 
    return 0; 
}