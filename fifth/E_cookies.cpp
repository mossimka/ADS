#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void heapify_up(vector<long long>& arr, long long v){
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

void push_box(vector<long long>& boxes, long long cookies, long long k){
    if(boxes.size() < k){
        push(boxes, cookies);
    } else if(k > 0 && boxes[0] < cookies) {
        pop(boxes);
        push(boxes, cookies);
    }
}

int main(){
    long long n, k;
    cin >> n >> k;
    vector<long long> boxes;
    
    for(long long i = 0; i < n; ++i){
        string com;
        cin >> com;
        if(com == "print"){
            long long sum = 0;
            for(long long cookies : boxes){
                sum += cookies;
            }
            cout << sum << endl;
        }
        if(com == "insert"){
            long long cookies;
            cin >> cookies;
            push_box(boxes, cookies, k);
        }
    }
    return 0;
}
