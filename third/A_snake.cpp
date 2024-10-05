#include <iostream>

using namespace std;

int binarySearch(int arr[], int l, int r, int key) {
    if (l > r) {
        return -1;
    }
    int mid = l + (r - l) / 2;
    if (key == arr[mid]) {
        return mid;
    }
    if (key > arr[mid]) {
        return binarySearch(arr, l, mid - 1, key);
    }
    return binarySearch(arr, mid + 1, r, key);
}

int main() {
    int t, num;
    cin >> t;
    int toFind[t];
    for (int i = 0; i < t; ++i) {
        cin >> num;
        toFind[i] = num;
    }
    int n, m;
    cin >> n >> m;
    int arr[n * m];
    for (int i = 0; i < n; ++i) {
        int temp[m];
        for (int j = 0; j < m; ++j) {
            cin >> temp[j];
        }
        if (i % 2 == 0) {
            for (int j = 0; j < m; ++j) {
                arr[i * m + j] = temp[j];
            }
        } else {
            for (int j = 0; j < m; ++j) {
                arr[i * m + j] = temp[m - 1 - j];
            }
        }
    }

    int r = n * m - 1, l = 0;
    for (int i = 0; i < t; ++i) {
        int position = binarySearch(arr, l, r, toFind[i]);
        if (position == -1) {
            cout << -1 << endl;
        } else {
            if ((position / m) % 2 == 0) {
                cout << position / m << " " << position % m << endl;
            } else {
                cout << position / m << " " << abs(position % m - (m - 1)) << endl;
            }
        }
    }
}
