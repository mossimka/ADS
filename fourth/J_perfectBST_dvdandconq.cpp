#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

void simulatePerfectBST(const vector<int>& arr, int start, int end) {
    if (start > end) {
        return;
    }
    int mid = start + (end - start) / 2;
    cout << arr[mid] << " ";

    simulatePerfectBST(arr, start, mid - 1);
    simulatePerfectBST(arr, mid + 1, end);
}

int main() {
    int n;
    cin >> n;
    int size = pow(2, n) - 1;
    vector<int> Array(size);
    for(int i = 0; i < size; ++i){
        cin >> Array[i];
    }
    sort(Array.begin(), Array.end());
    simulatePerfectBST(Array, 0, Array.size() - 1);
    cout << endl;

    return 0;
}
