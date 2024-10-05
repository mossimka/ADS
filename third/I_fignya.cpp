#include <iostream>

using namespace std;

bool binarySearch(int arr[], int l, int r, int key) {
    if (l > r) {
        return false;
    }
    int mid = l + (r - l) / 2;
    if (key == arr[mid]) {
        return true;
    }
    if (key > arr[mid]) {
        return binarySearch(arr, mid + 1, r, key);
    }
    return binarySearch(arr, l, mid - 1, key);
}

int main() {
    int size;
    cin >> size;
    int arr[size];
    for(int i = 0; i < size; ++i){
        cin >> arr[i];
    }
    int key;
    cin >> key;
    if(binarySearch(arr, 0, size - 1, key)){
        cout << "Yes";
    } else {
        cout << "No";
    }

    return 0;
}
