#include <iostream>
#include <queue>

using namespace std;

class Node {
public:
    int data;
    Node* ls;
    Node* rs;
    Node(){
        data = 0;
        ls = nullptr;
        rs = nullptr;
    }
    Node(int data){
        this->data = data;
        ls = nullptr;
        rs = nullptr;
    }
};

Node* insert(int data, Node* root){
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
};

int height(Node* current){
    if (current == nullptr)
        return 0;
    
    int lDepth = height(current->ls);
    int rDepth = height(current->rs);

    return max(lDepth, rDepth) + 1;
};
void levelSums(Node* root){
    queue<Node*> q;
    q.push(root);
    while(!q.empty()){
        int levelSize = q.size();
        int levelSum = 0;
        for(int i = 0; i < levelSize; ++i){
            Node* current = q.front();
            q.pop();
            levelSum += current->data; 
            if(current->ls != nullptr) q.push(current->ls);
            if(current->rs != nullptr) q.push(current->rs);
        }
        cout << levelSum << ' ';
    }
}

int main(){
    int n;
    cin >> n;
    Node* root = nullptr;
    for(int i = 0; i < n; ++i){
        int new_data;
        cin >> new_data;
        root = insert(new_data, root);
    }
    cout << height(root) << endl;
    levelSums(root);
    return 0;
}