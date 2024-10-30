#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void heapify_up(vector<long long>& arr, long long v) { 
    while (v > 0 && arr[(v - 1) / 2] > arr[v]) {
        swap(arr[(v - 1) / 2], arr[v]);
        v = (v - 1) / 2;
    }
}

void heapify_down(vector<long long>& arr, long long v, long long i) {
    long long smallest = i;
    long long left = 2 * i + 1;
    long long right = 2 * i + 2;

    if (left < v && arr[left] < arr[smallest])
        smallest = left;

    if (right < v && arr[right] < arr[smallest])
        smallest = right;

    if (smallest != i) {
        swap(arr[i], arr[smallest]);
        heapify_down(arr, v, smallest);
    }
}

void buildHeap(vector<long long>& arr, long long n) {
    for (long long i = n / 2 - 1; i >= 0; i--) {
        heapify_down(arr, n, i);
    }
}

void push(vector<long long>& arr, long long data) {
    arr.push_back(data);
    heapify_up(arr, arr.size() - 1);
}

void pop(vector<long long>& arr) {
    if (arr.size() == 0) return;
    
    swap(arr[0], arr[arr.size() - 1]);
    arr.pop_back();
    heapify_down(arr, arr.size(), 0);
}

long long minSum(vector<long long>& arr, long long n){
    long long sum = 0;
    while(arr.size() > 1){
        long long first = arr[0];
        pop(arr);
        long long second = arr[0];
        pop(arr);
        long long newEl = first + second;
        sum += newEl;
        push(arr, newEl);
    }
    return sum;
}

int main() {
    long long n;
    cin >> n;
    vector<long long> arr;

    for (long long i = 0; i < n; ++i) {
        long long num;
        cin >> num;
        arr.push_back(num);
    }
    buildHeap(arr, n);

    cout << minSum(arr, n);
    return 0;
}
