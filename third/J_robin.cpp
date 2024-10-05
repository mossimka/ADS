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

long long binarySearch(const vector<long long>& gold, long long n, long long h, long long max) {
    long long l = 0, r = max, res = r;
    while (l <= r) {
        int mid = l + (r - l) / 2;
        if(check(gold, h, mid)) {
            res = mid;
            r = mid - 1;
        } else{
            l = mid + 1;
        }
    }
    return res;
}

int main() {
    long long n, h;
    cin >> n >> h;
    vector<long long> gold(n);
    long long max = 1;
    for (int i = 0; i < n; i++) {
        cin >> gold[i];
        if(max < gold[i]){
            max = gold[i];
        }
    }
    cout << binarySearch(gold, n, h, max);
    return 0;
}
