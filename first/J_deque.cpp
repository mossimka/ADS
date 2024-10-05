#include <iostream>
#include <deque>

using namespace std;

int main(){
    char com;
    int n;
    deque<int> deq;
    cin >> com;
    bool emp = false;
    while(com != '!'){
        if (com == '+' || com == '-') {
            cin >> n;
        }

        switch (com)
        {
        case '+':
            deq.push_front(n);
            cin >> com;
            break;
        case '-':
            deq.push_back(n);
            cin >> com;
            break;
        case '*':
            if(!deq.empty()){
                cout << deq.front()+deq.back() << '\n';
                if(!deq.empty()) deq.pop_front();
                if(!deq.empty()) deq.pop_back();
                cin >> com;
            }
            else {
                cout << "error\n";
                cin >> com;
            }
            break;
        default:
            break;
        }
    }
    return 0;
}