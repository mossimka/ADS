#include <iostream>

using namespace std;

class Node {
public:
    int data;
    int multiplicity;
    Node* rs;
    Node* ls;
    Node(){
        data = 0;
        rs = nullptr;
        ls = nullptr;
    }
    Node(int data){
        this->data = data;
        this->multiplicity = 1;
        rs = nullptr;
        ls = nullptr;
    }
};

Node* insert (int data, Node* current) {
    if(current == nullptr){
        current = new Node(data);
        return current;
    }
    if(data == current->data){
        current->multiplicity += 1;
    }
    if(data < current->data){
        current->ls = insert(data, current->ls);
    }
    else if(data > current->data){
        current->rs = insert(data, current->rs);
    }
    return current;
}

Node* find(int key, Node* current){
    if(current->data == key){
        return current;
    }
    if(current->data > key){
        find(key, current->ls);
    }
    if(current->data < key){
        find(key, current->rs);
    }
}

int getMultiplicity(int data, Node* root){
    return find(data, root)->multiplicity;
}

Node* getSuccessor(Node* curr){
    curr = curr->rs;
    while (curr != nullptr && curr->ls != nullptr)
        curr = curr->ls;
    return curr;
}

Node* delNode(Node* root, int x){
    if (root == NULL)
        return root;
    if (root->data > x)
        root->ls = delNode(root->ls, x);
    else if (root->data < x)
        root->rs = delNode(root->rs, x);
    else {
        if (root->ls == NULL) {
            Node* temp = root->rs;
            delete root;
            return temp;
        }
        if (root->rs == NULL) {
            Node* temp = root->ls;
            delete root;
            return temp;
        }
        Node* succ = getSuccessor(root);
        root->data = succ->data;
        root->rs = delNode(root->rs, succ->data);
    }
    return root;
}

Node* deleteNode(int data, Node* root){
    Node* toDel = find(data, root);
    if(toDel->multiplicity > 1){
        toDel->multiplicity -= 1;
        return root;
    }
    return delNode(root, data);
}

int main () {
    int n;
    cin >> n;
    Node* root = nullptr;
    for(int i = 0; i < n; ++i){
        string com;
        cin >> com;
        int new_data;
        cin >> new_data;
        if(com == "insert"){
            root = insert(new_data, root);
        }
        if(com == "cnt"){
            cout << getMultiplicity(new_data, root) << endl;
        }
        if(com == "delete"){
            root = deleteNode(new_data, root);
        }
    }
    return 0;
}
