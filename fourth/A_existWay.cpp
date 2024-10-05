#include <iostream>
#include <vector>

using namespace std;

class Node {
public:
    int data;
    Node* ls;
    Node* rs;
    Node() {
        data = 0;
        ls = nullptr;
        rs = nullptr;
    }
    Node(int data) {
        this->data = data;
        ls = nullptr;
        rs = nullptr;
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

bool pathExist(string path, Node* root){
    vector<char> v{path.begin(), path.end()};
    Node* current = root;
    for(char move:v){
        if(move == 'R' && current->rs != nullptr){
            current = current->rs;
            continue;
        }
        if(move == 'L' && current->ls != nullptr){
            current = current->ls;
            continue;
        }
        return false;
    }
    return true;
};
int main () {
    int n, m;
    cin >> n >> m;
    Node* root = nullptr;
    for(int i = 0; i < n; ++i){
        int new_data;
        cin >> new_data;
        root = insert(new_data, root);
    }
    string path;
    for(int j = 0; j < m; j++){
        cin >> path;
        if(pathExist(path, root)){
            cout << "YES" << endl;
        } else{
            cout << "NO" << endl;
        }
    }
    return 0;
}
