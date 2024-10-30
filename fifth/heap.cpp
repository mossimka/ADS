#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void heapify_up(vector<int>& arr, int v) { 
    while (v > 0 && arr[(v - 1) / 2] > arr[v]) {
        swap(arr[(v - 1) / 2], arr[v]);
        v = (v - 1) / 2;
    }
}

void heapify_down(vector<int>& arr, int v, int i) {
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < v && arr[left] < arr[smallest])
        smallest = left;

    if (right < v && arr[right] < arr[smallest])
        smallest = right;

    if (smallest != i) {
        swap(arr[i], arr[smallest]);
        heapify_down(arr, v, smallest);
    }
}

void buildHeap(vector<int>& arr, int n) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify_down(arr, n, i);
    }
}

void push(vector<int>& arr, int data) {
    arr.push_back(data);
    heapify_up(arr, arr.size() - 1);
}

void pop(vector<int>& arr) {
    if (arr.size() == 0) return;
    
    swap(arr[0], arr[arr.size() - 1]);
    arr.pop_back();
    heapify_down(arr, arr.size(), 0);
}

int main() {
    int n;
    cin >> n;
    vector<int> arr;

    for (int i = 0; i < n; ++i) {
        int num;
        cin >> num;
        arr.push_back(num);
    }
    buildHeap(arr, n);
    return 0;
}
