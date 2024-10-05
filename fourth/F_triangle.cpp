#include <iostream>

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

int countTriangles(Node* current){
    if (current == nullptr) {
        return 0;
    }
    int count = 0;
    if (current->ls != nullptr && current->rs != nullptr) {
        count = 1;
    }
    return count + countTriangles(current->ls) + countTriangles(current->rs);
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
    cout << countTriangles(root);
    return 0;
}
