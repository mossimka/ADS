#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

bool check(const vector<long long>& arr, long long f, long long size) {
    long long count = 0;
    for (int i : arr) {
        count += (i + size - 1) / size;
    }
    return count <= f;
}

long long binarySearch(const vector<long long>& gifts, long long f, long long l, long long r) {
    long long res = r;
    while (l <= r) {
        int mid = l + (r - l) / 2;
        if (check(gifts, f, mid)) {
            res = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    return res;
}

int main() {
    long long n, f;
    cin >> n >> f;
    if(pow(n,2) <= f){
        cout << 1;
        return 0;
    }
    vector<long long> gifts(n);
    for (int i = 0; i < n; i++) {
        cin >> gifts[i];
    }
    cout << binarySearch(gifts, f, 1, *max_element(gifts.begin(), gifts.end()));
    return 0;
}
