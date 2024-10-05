#include <iostream>
#include <algorithm>

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

int height(Node* root) {
    if (root == nullptr) return 0;
    return 1 + max(height(root->ls), height(root->rs));
}

int diameter(Node* root, int& maxDiameter) {
    if (root == nullptr) return 0;
    int leftHeight = height(root->ls);
    int rightHeight = height(root->rs);
    maxDiameter = max(maxDiameter, leftHeight + rightHeight);
    diameter(root->ls, maxDiameter);
    diameter(root->rs, maxDiameter);

    return maxDiameter+1;
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
    int maxDiameter = 0;
    cout << diameter(root, maxDiameter);
    return 0;
}
