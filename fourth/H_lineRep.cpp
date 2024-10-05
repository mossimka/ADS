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

void lineSum(Node* root, int& cumulativeSum) {
    if (root == nullptr) {
        return;
    }
    lineSum(root->rs, cumulativeSum);

    cumulativeSum += root->data;
    root->data = cumulativeSum;

    lineSum(root->ls, cumulativeSum);
}

void printDescending(Node* root) {
    if (root == nullptr) {
        return;
    }
    printDescending(root->rs);
    cout << root->data << " ";
    printDescending(root->ls);
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
    int cumulativeSum = 0;
    lineSum(root, cumulativeSum);
    printDescending(root);
    
    return 0;
}
