#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main() {
    int n;
    cin >> n;
    const int MAX = 1000000;
    vector<bool> prime(MAX + 1, true);
    prime[0] = prime[1] = false;
    for (int i = 2; i * i <= MAX; ++i) {
        if (prime[i]) {
            for (int j = i * i; j <= MAX; j += i) {
                prime[j] = false;
            }
        }
    }
    if (prime[n]) {
        cout << "YES";
    } else {
        cout << "NO";
    }

    return 0;
}