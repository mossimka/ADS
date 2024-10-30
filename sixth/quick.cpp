#include <iostream>
#include <cstdlib>

using namespace std;

int partition(int* a, int n){
    int p = rand() % n;
    swap(a[p], a[0]);
    int x = a[0];
    int l = 1, r = n - 1;
    while (l <= r) {
        if (a[l] <= x) {
            l++;
        } else {
            swap(a[l], a[r]);
            r--;
        }
    }
    swap(a[0], a[r]);
    return r;
}

void quick_sort(int* a, int n){
    if (n <= 1) return;
    int p = partition(a, n);
    quick_sort(a, p);
    quick_sort(a + p + 1, n - p - 1);
}

int a[1000005], n;

int main(){
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    quick_sort(a, n);
    for (int i = 0; i < n; ++i) {
        cout << a[i] << " ";
    }
    cout << endl;
}
