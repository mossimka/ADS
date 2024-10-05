#include <iostream>
#include <deque>
#include <string>

using namespace std;

int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    deque<int> katsu, sakaya;

    for (int i = 0; i < n; ++i) {
        if (s[i] == 'K') {
            katsu.push_back(i);
        } else {
            sakaya.push_back(i);
        }
    }

    while (!katsu.empty() && !sakaya.empty()) {
        int k_index = katsu.front();
        int s_index = sakaya.front();
        katsu.pop_front();
        sakaya.pop_front();

        if (k_index < s_index) {
            katsu.push_back(k_index + n);
        } else {
            sakaya.push_back(s_index + n);
        }
    }

    if (!katsu.empty()) {
        cout << "KATSURAGI" << endl;
    } else {
        cout << "SAKAYANAGI" << endl;
    }

    return 0;
}
