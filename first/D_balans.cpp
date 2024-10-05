#include <iostream>
#include <stack>
using namespace std;

bool isBalanced(const string& s) {
    stack<char> letters;
    
    for (char c : s) {
        if (!letters.empty() && letters.top() == c) {
            letters.pop();
        } else {
            letters.push(c);
        }
    }
    return letters.empty();
}

int main() {
    string s;
    cin >> s;
    
    if (isBalanced(s)) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
    
    return 0;
}
