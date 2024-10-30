#include <iostream>
#include <vector>

using namespace std;

void heapify_down(vector<int>& arr, long long v, long long i){
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

void build_heap(vector<int>& arr, long long n){
    for(long long i = n / 2 - 1; i >= 0; --i){
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

int main(){
    long long n;
    cin >> n;
    vector<int> vowels;
    vector<int> consonants;
    long long vls = 0, cts = 0;
    for(int i = 0; i < n; ++i){
        char c;
        cin >> c;
        if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u'){
            vowels.push_back((int)c);
            vls++;
        } else{
            consonants.push_back((int)c);
            cts++;
        }
    }

    heap_sort(vowels, vls);
    heap_sort(consonants, cts);
    for(long long i = 0; i < vls; ++i){
        cout << (char)vowels[i];
    }
    for(long long i = 0; i < cts; ++i){
        cout << (char)consonants[i];
    }

    return 0;
}
