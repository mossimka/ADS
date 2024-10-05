#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int binarySearch(const vector<int>& fighters, int power, int l, int r) {
    while (l <= r) {
        int mid = l + (r - l) / 2;
        if (fighters[mid] > power) {
            r = mid - 1; 
        } else {
            l = mid + 1;
        }
    }
    return l;
}
int countBefore(const vector<int>& fighters, int pos) {
    int sum = 0;
    for (int i = 0; i < pos; i++) {
        sum += fighters[i];
    }
    return sum;
}

int main() {
    int n;
    cin >> n;
    vector<int> fighters(n);
    for (int i = 0; i < n; i++) {
        cin >> fighters[i];
    }
    sort(fighters.begin(), fighters.end());

    int rounds;
    cin >> rounds;

    for (int i = 0; i < rounds; ++i) {
        int power;
        cin >> power;
        int res = binarySearch(fighters, power, 0, n - 1);
        cout << res << " " << countBefore(fighters, res) << endl;
    }

    return 0;
}
