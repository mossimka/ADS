#include <iostream>

using namespace std;

class Node {
public:
    int data;
    int multiplicity;
    Node* rs;
    Node* ls;
    Node() {
        data = 0;
        rs = nullptr;
        ls = nullptr;
    }
    Node(int data) {
        this->data = data;
        this->multiplicity = 1;
        rs = nullptr;
        ls = nullptr;
    }
};

Node* insert(int data, Node* current) {
    if (current == nullptr) {
        return new Node(data);
    }
    if (data == current->data) {
        current->multiplicity += 1;
    } else if (data < current->data) {
        current->ls = insert(data, current->ls);
    } else {
        current->rs = insert(data, current->rs);
    }
    return current;
}

Node* find(int key, Node* current) {
    if (current == nullptr || current->data == key) {
        return current;
    }
    if (key < current->data) {
        return find(key, current->ls);
    } else {
        return find(key, current->rs);
    }
}

int getMultiplicity(int data, Node* root) {
    Node* node = find(data, root);
    if (node == nullptr) {
        return 0;
    }
    return node->multiplicity;
}

// smallest node in right subtree
Node* getSuccessor(Node* curr) {
    curr = curr->rs;
    while (curr != nullptr && curr->ls != nullptr) {
        curr = curr->ls;
    }
    return curr;
}

Node* delNode(Node* root, int x) {
    if (root == nullptr)
        return root;
    if (x < root->data)
        root->ls = delNode(root->ls, x);
    else if (x > root->data)
        root->rs = delNode(root->rs, x);
    else {
        if (root->ls == nullptr) {
            Node* temp = root->rs;
            delete root;
            return temp;
        }
        if (root->rs == nullptr) {
            Node* temp = root->ls;
            delete root;
            return temp;
        }
        Node* succ = getSuccessor(root);
        root->data = succ->data;
        root->multiplicity = succ->multiplicity;
        root->rs = delNode(root->rs, succ->data);
    }
    return root;
}

Node* deleteNode(int data, Node* root) {
    Node* toDel = find(data, root);
    if (toDel == nullptr) {
        return root;
    }
    if (toDel->multiplicity > 1) {
        toDel->multiplicity -= 1;
        return root;
    }
    return delNode(root, data);
}

int main() {
    int n;
    cin >> n;
    Node* root = nullptr;
    for (int i = 0; i < n; ++i) {
        string com;
        cin >> com;
        int new_data;
        cin >> new_data;
        if (com == "insert") {
            root = insert(new_data, root);
        } else if (com == "cnt") {
            cout << getMultiplicity(new_data, root) << endl;
        } else if (com == "delete") {
            root = deleteNode(new_data, root);
        }
    }
    return 0;
}
