#include <iostream>
#include <cmath>
#include <map>

using namespace std;

int main() {
    int n;
    cin >> n;
    map<int, int> divs;
    
    for (int i = 2; i*i <= n; i++) {
        while (n % i == 0) {
            divs[i]++;
            n /= i;
        }
        if (n == 1) {
            break;
        }
    }
    
    if (n != 1) {
        divs[n] = 1;
    }

    // Proper iteration over the map
    for (const auto& element : divs) {
        int fact = element.first;
        int power = element.second;
        cout << fact << "^" << power << " ";
    }
    cout << endl; // To end the output line properly
    return 0;
}
