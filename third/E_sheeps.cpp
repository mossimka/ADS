#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

bool check(const vector<int>& arr, int n, int k, int len) {
    int count = 0;
    for (int i : arr) {
        if (len >= i) {
            count++;
        }
    }
    return count >= k;
}
int BinarySearchLength(const vector<int>& arr, int n, int k, int min, int max) {
    int low = min;
    int high = max;
    int res = high;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (check(arr, n, k, mid)) {
            res = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return res;
}

int main() {
    int n, k;
    cin >> n >> k;
    int min = INT_MAX, max = INT_MIN;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        int cd[4];
        for (int j = 0; j < 4; j++) {
            cin >> cd[j];
        }
        arr[i] = std::max(cd[2], cd[3]);
        min = std::min(min, arr[i]);
        max = std::max(max, arr[i]);
    }
    cout << BinarySearchLength(arr, n, k, min, max) << endl;

    return 0;
}
