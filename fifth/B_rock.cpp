#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void heapify_up(vector<long long>& arr, long long v) { 
    while (v > 0 && arr[(v - 1) / 2] < arr[v]) {
        swap(arr[(v - 1) / 2], arr[v]);
        v = (v - 1) / 2;
    }
}

void heapify_down(vector<long long>& arr, long long n, long long i) {
    long long largest = i;
    long long left = 2 * i + 1;
    long long right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify_down(arr, n, largest);
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

void build_heap(vector<long long>& arr, int n) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify_down(arr, n, i);
    }
}

void break_stones(vector<long long>& arr, int n) {
    while(arr.size() > 1) {
        long long first = arr[0];
        pop(arr);
        long long second = arr[0];
        pop(arr);
        push(arr, first - second);
    }
}


int main(){
    int n;
    cin >> n;
    vector<long long> arr;
    for(int i = 0; i < n; ++i){
        long long num;
        cin >> num;
        arr.push_back(num);
    }
    build_heap(arr, n);
    break_stones(arr, n);
    cout << arr[0];
    return 0;
}