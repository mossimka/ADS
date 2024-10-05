#include <iostream>

using namespace std;

int binarySearch(int P[], int size, int line) {
    int l = 0, r = size - 1;
    int mid;
    while (l <= r) {
        mid = l + (r - l) / 2;
        if (P[mid] > line) {
            r = mid - 1;
        } else if(P[mid] < line){
            l = mid + 1;
        } else{
            return mid+1;
        }
    }
    return l+1;
}

int main() {
    int n, m;
    cin >> n >> m;
    int P[n];
    int num;
    cin >> num;
    P[0] = num;
    for (int i = 1; i < n; ++i) {
        cin >> num;
        P[i] = P[i - 1] + num;
    }
    
    int line;
    for (int j = 0; j < m; ++j) {
        cin >> line;
        cout << binarySearch(P, n, line) << endl;
    }
    
    return 0;
}
