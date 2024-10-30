#include <iostream>
#include <vector>

using namespace std;

bool greater_than(const vector<int>& f, const vector<int>& s) {
    long long sum1 = 0, sum2 = 0, size = f.size();
    
    for (int i = 0; i < size; ++i) {
        sum1 += f[i];
        sum2 += s[i];
    }

    if (sum1 > sum2) {
        return true;
    } else if (sum1 < sum2) {
        return false;
    }

    for (int i = 0; i < size; ++i) {
        if (f[i] > s[i]) return false;
        if (f[i] < s[i]) return true;
    }

    return false;
}

void merge(vector<vector<int>>& vec, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<vector<int>> L(n1), R(n2);
    for (int i = 0; i < n1; ++i) {
        L[i] = vec[left + i];
    }
    for (int j = 0; j < n2; ++j) {
        R[j] = vec[mid + 1 + j];
    }

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (greater_than(L[i], R[j])) {
            vec[k] = L[i];
            i++;
        } else {
            vec[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        vec[k] = L[i];
        i++;
        k++;
    }
    while (j < n2) {
        vec[k] = R[j];
        j++;
        k++;
    }
}

void merge_sort(vector<vector<int>>& vec, int left, int right) {
    if (left >= right) {
        return;
    }
    int mid = left + (right - left) / 2;
    merge_sort(vec, left, mid);
    merge_sort(vec, mid + 1, right);
    merge(vec, left, mid, right);
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> vecs(n);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            int num;
            cin >> num;
            vecs[i].push_back(num);
        }
    }

    merge_sort(vecs, 0, n - 1);

    for (const vector<int>& vec : vecs) {
        for (int num : vec) {
            cout << num << ' ';
        }
        cout << endl;
    }

    return 0;
}
