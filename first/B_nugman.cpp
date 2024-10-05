#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> vec(n), res(n, -1);
    stack<int> stck;

    for (int i = 0; i < n; ++i) {
        cin >> vec[i];
        while (!stck.empty() && vec[stck.top()] > vec[i]) {
            stck.pop();
        }
        if (!stck.empty()) {
            res[i] = vec[stck.top()];
        }
        stck.push(i);
    }

    for (int i = 0; i < n; ++i) {
        cout << res[i] << " ";
    }
    return 0;
}