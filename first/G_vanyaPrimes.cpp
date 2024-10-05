#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    const int MAX = 100000;
    vector<bool> prime(MAX, true);
    vector<int> primes;
    vector<int> superprimes;
    prime[0] = prime[1] = false;
    for (int i=2; i<MAX; i++) {
        if (prime[i]) {
            primes.push_back(i);
            if (primes.size() > 1 && prime[primes.size()]) {
                superprimes.push_back(i);
            }
            if (superprimes.size() >= n) break;
            for (int j = i * i; j < MAX; j += i){
                prime[j] = false;
            }
        }
    }
    cout << superprimes[n - 1];
    return 0;
}