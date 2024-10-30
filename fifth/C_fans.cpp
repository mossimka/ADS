#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void heapify_up(vector<long long>& arr, long long v){
    while(v > 0 && arr[(v - 1) / 2] < arr[v]){
        swap(arr[(v-1)/2], arr[v]);
        v = (v-1)/2; 
    }
}

void heapify_down(vector<long long>& arr, long long n, long long i){
    long long largest = i;
    long long left = i * 2 + 1;
    long long right = i * 2 + 2;

    if(left < n && arr[largest] < arr[left]){
        largest = left;
    }
    if (right < n && arr[largest] < arr[right]){
        largest = right;
    }
    if(largest != i){
        swap(arr[i], arr[largest]);
        heapify_down(arr, n, largest);
    }
}

void build_heap(vector<long long>& arr, long long n){
    for(long long i = (n - 1) / 2; i >= 0; --i){
        heapify_down(arr, n, i);
    }
}

void push(vector<long long>& arr, long long data){
    arr.push_back(data);
    heapify_up(arr, arr.size() - 1);
}

void pop(vector<long long>& arr){
    if(arr.size() == 0) return;

    swap(arr[0], arr[arr.size() - 1]);
    arr.pop_back();
    heapify_down(arr, arr.size(), 0);
}

long long fansMoney(vector<long long> arr, long long k){
    long long sum = 0;
    while(k != 0 && arr[0] > 0){
        long long num = arr[0];
        sum += num;
        pop(arr);
        push(arr, num-1);
        k--;
    }
    return sum;
}

int main(){
    long long n, k;
    cin >> n >> k;
    vector<long long> arr;
    for(long long i = 0; i < n; ++i){
        long long num;
        cin >> num;
        arr.push_back(num);
    }
    build_heap(arr, n);
    cout << fansMoney(arr, k);
    return 0;
}
