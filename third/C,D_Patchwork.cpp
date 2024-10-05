#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int binarySearchLeft(vector<int>& vec, int l, int r, int key) {
    while (l < r) {
        int mid = l + (r - l) / 2;
        if (vec[mid] >= key) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    return l;
}

int binarySearchRight(vector<int>& vec, int l, int r, int key) {
    while (l < r) {
        int mid = l + (r - l) / 2;
        if (vec[mid] > key) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    return l;
}
int countEls(vector<int>& vec, int l1, int r1, int l2, int r2) {
    int n = vec.size();
    int left1 = binarySearchLeft(vec, 0, n, l1);
    int right1 = binarySearchRight(vec, 0, n, r1);
    int count1 = right1 - left1;
    int left2 = binarySearchLeft(vec, 0, n, l2);
    int right2 = binarySearchRight(vec, 0, n, r2);
    int count2 = right2 - left2;
    int overlap_l = max(l1, l2);
    int overlap_r = min(r1, r2);

    int overlap_count = 0;
    if (overlap_l <= overlap_r) {
        int left_overlap = binarySearchLeft(vec, 0, n, overlap_l);
        int right_overlap = binarySearchRight(vec, 0, n, overlap_r);
        overlap_count = right_overlap - left_overlap;
    }
    return count1 + count2 - overlap_count;
}

int main() {
    int n, q;
    cin >> n >> q;
    vector<int> vec(n);
    for (int i = 0; i < n; i++) {
        cin >> vec[i];
    }

    sort(vec.begin(), vec.end());
    
    int l1, r1, l2, r2;
    vector<int> results(q);
    for (int i = 0; i < q; ++i) {
        cin >> l1 >> r1 >> l2 >> r2;
        int count = countEls(vec, l1, r1, l2, r2);
        results[i] = count;
    }
    for (int res : results) {
        cout << res << endl;
    }
    
    return 0;
}
