#include <iostream>
#include <vector>

using namespace std;

class Node {
public:
    int data;
    Node* rs;
    Node* ls;
    Node(){
        data = 0;
        rs = nullptr;
        ls = nullptr;
    }
    Node(int data){
        this->data = data;
        rs = nullptr;
        ls = nullptr;
    }
};

Node* insert (int data, Node* root) {
    if(root == nullptr){
        root = new Node(data);
        return root;
    }
    if(data < root->data){
        root->ls = insert(data, root->ls);
    }
    else if(data > root->data){
        root->rs = insert(data, root->rs);
    }
    return root;
}

int height (Node* current){
    if(current == nullptr){
        return 0;
    }
    return 1 + height(current->ls) + height(current->rs);
}

int main () {
    int n;
    cin >> n;
    Node* root = nullptr;
    for(int i = 0; i < n; ++i){
        int new_data;
        cin >> new_data;
        root = insert(new_data, root);
    }
    int nodeToFind;
    cin >> nodeToFind;
    Node* current = root;
    while(current != nullptr && current->data != nodeToFind){
        if(nodeToFind < current->data){
            current = current->ls;
        } else {
            current = current->rs;
        }
    }
    if(current != nullptr) {
        cout << height(current);
    }
    return 0;
}
