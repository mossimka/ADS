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

Node* insert(int parent, int son, Node* root, int leftOrRight){
    if(root == nullptr){
        root = new Node(parent);
    }
    Node* current = root;
    queue<Node*> q;
    q.push(root);
    while(parent != current->data){
        int levelSize = q.size();
        for(int i = 0; i < levelSize; ++i){
            current = q.front();
            if(q.front()->data == parent){
                break;
            }
            q.pop();
            if(current->ls != nullptr) q.push(current->ls);
            if(current->rs != nullptr) q.push(current->rs);
            
        }
    }
    Node* newNode = new Node(son);
    if(leftOrRight == 0){
        current->ls = newNode;
    }
    if(leftOrRight){
        current->rs = newNode;
    }
    return root;
};

int maxLevelWidth(Node* root){
    queue<Node*> q;
    q.push(root);
    int max = 0;
    while(!q.empty()){
        int levelSize = q.size();
        int levelSum = 0;
        for(int i = 0; i < levelSize; ++i){
            Node* current = q.front();
            q.pop();
            levelSum += 1; 
            if(current->ls != nullptr) q.push(current->ls);
            if(current->rs != nullptr) q.push(current->rs);
        }
        if(levelSum > max){
            max = levelSum;
        }
    }
    return max;
}

int main(){
    int n;
    cin >> n;
    Node* root = nullptr;

    int parent, son, leftOrRight;
    for(int i = 0; i < n-1; ++i){
        cin >> parent >> son >> leftOrRight;
        root = insert(parent, son, root, leftOrRight);
    }
    cout << maxLevelWidth(root);
    return 0;
}