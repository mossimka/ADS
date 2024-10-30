#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

void heapify_down(vector<int>& arr, int size, int i) {
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < size && arr[left] < arr[smallest]) {
        smallest = left;
    }
    if (right < size && arr[right] < arr[smallest]) {
        smallest = right;
    }
    if (smallest != i) {
        swap(arr[i], arr[smallest]);
        heapify_down(arr, size, smallest);
    }
}

void build_heap(vector<int>& arr, int size) {
    for (int i = size / 2 - 1; i >= 0; --i) {
        heapify_down(arr, size, i);
    }
}

void heap_sort(vector<int>& arr, int size) {
    build_heap(arr, size);
    for (int i = size - 1; i >= 0; --i) {
        swap(arr[i], arr[0]);
        heapify_down(arr, i, 0);
    }
}

vector<int> find_similarity(vector<int>& first, vector<int>& second) {
    unordered_map<int, int> countFirst, countSecond;
    for (int num : first) {
        countFirst[num]++;
    }
    for (int num : second) {
        countSecond[num]++;
    }
    vector<int> res;
    for (auto entry : countFirst) {
        int num = entry.first;
        int count = min(entry.second, countSecond[num]);
        for (int i = 0; i < count; ++i) {
            res.push_back(num);
        }
    }
    return res;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> first(n), second(m);

    for (int i = 0; i < n; ++i) {
        cin >> first[i];
    }
    for (int i = 0; i < m; ++i) {
        cin >> second[i];
    }

    heap_sort(first, n);
    heap_sort(second, m);
    vector<int> res = find_similarity(first, second);
    
    for (int num : res) {
        cout << num << ' ';
    }
    return 0;
}
