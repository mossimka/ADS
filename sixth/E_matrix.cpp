#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

int partition(vector<int>& vec, int start, int end) {
    int p = start + rand() % (end - start + 1);
    swap(vec[start], vec[p]);
    int x = vec[start];
    int l = start + 1, r = end;
    
    while (l <= r) {
        if (x < vec[l]) {
            l++;
        } else {
            swap(vec[l], vec[r]);
            r--;
        }
    }
    swap(vec[start], vec[r]);
    return r;
}

void quick_sort(vector<int>& vec, int start, int end) {
    if (start >= end) return;
    int p = partition(vec, start, end);
    quick_sort(vec, start, p - 1);
    quick_sort(vec, p + 1, end);
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> vec(m, vector<int>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            int num;
            cin >> num;
            vec[j][i] = num;
        }
    }

    for (int j = 0; j < m; ++j) {
        quick_sort(vec[j], 0, n - 1);
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cout << vec[j][i] << ' ';
        }
        cout << endl;
    }

    return 0;
}
