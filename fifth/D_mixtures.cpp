#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void heapify_up(vector<long  long>& arr, long long v){
    while(v > 0 && arr[v] < arr[(v-1)/2]){
        swap(arr[v], arr[(v-1)/2]);
        v = (v-1)/2;
    }
}

void heapify_down(vector<long long>& arr, long long n, long long i){
    long long smallest = i;
    long long left = i * 2 + 1;
    long long right = i * 2 + 2;

    if(left < n && arr[smallest] > arr[left]){
        smallest = left;
    }
    if(right < n && arr[smallest] > arr[right]){
        smallest = right;
    }
    if(smallest != i){
        swap(arr[i], arr[smallest]);
        heapify_down(arr, n, smallest);
    }
}

void push(vector<long long>& arr, long long data){
    arr.push_back(data);
    heapify_up(arr, arr.size()-1);
}

void pop(vector<long long>& arr){
    if(arr.size() == 0) return;

    swap(arr[0], arr[arr.size() - 1]);
    arr.pop_back();
    heapify_down(arr, arr.size(), 0);
}

void build_heap(vector<long long>& arr, long long n){
    for(long long i = (n - 1)/2; i >= 0 ; --i){
        heapify_down(arr, n, i);
    }
}

long long mix(vector<long long>& arr, long long m){
    long long count = 0;
    while(arr[0] < m){
        if(arr.size() == 1){
            return -1;
        }
        long long least = arr[0];
        pop(arr);
        long long sec_least= arr[0];
        pop(arr);
        push(arr, least + sec_least * 2);
        count++;
    }
    return count;
}

int main(){
    long long n, m;
    cin >> n >> m;
    vector<long long> arr;
    for(long long i = 0; i < n; ++i){
        long long density;
        cin >> density;
        arr.push_back(density);
    }
    build_heap(arr, n);

    cout << mix(arr, m);
}