#include <iostream>
#include <vector>

using namespace std;

void heapify_down(vector<int>& arr, long long v, long long i) {
    long long largest = i;
    long long left = 2 * i + 1;
    long long right = 2 * i + 2;

    if (left < v && arr[left] > arr[largest])
        largest = left;
    if (right < v && arr[right] > arr[largest])
        largest = right;
    
    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify_down(arr, v, largest);
    }
}

void build_heap(vector<int>& arr, long long n) {
    for (long long i = n / 2 - 1; i >= 0; --i) {
        heapify_down(arr, n, i);
    }
}

void heap_sort(vector<int>& arr, long long n) {
    build_heap(arr, n);
    for (long long i = n - 1; i >= 0; --i) {
        swap(arr[0], arr[i]);
        heapify_down(arr, i, 0);
    }
}

int binary_search_closest(const vector<int>& arr, int l, int r, int key) {
    int result;
    while (l <= r) {
        int mid = l + (r - l) / 2;
        if (arr[mid] > key) {
            result = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    return result;
}

int main() {
    long long n;
    cin >> n;
    vector<int> letters;
    for (int i = 0; i < n; ++i) {
        char c;
        cin >> c;
        letters.push_back((int)c);
    }
    heap_sort(letters, n);

    char x;
    cin >> x;
    int index = binary_search_closest(letters, 0, n - 1, (int)x);
    cout << (char)letters[index];

    return 0;
}
