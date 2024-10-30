#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

void merge(vector<int>& vec, int left, int mid, int right){
    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<int> L(n1), R(n2);
    for(int  i = 0; i < n1; ++i){
        L[i] = vec[left + i];
    }
    for(int j = 0; j < n2; ++j){
        R[j] = vec[mid + 1 + j];
    }

    int i = 0, j = 0;
    int k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            vec[k] = L[i];
            i++;
        }
        else {
            vec[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1) {
        vec[k] = L[i];
        i++;
        k++;
    }
    while (j < n2) {
        vec[k] = R[j];
        j++;
        k++;
    }
}
void merge_sort(vector<int>& vec, int left, int right){
    if(left >= right){
        return;
    }

    int mid = left + (right - left) / 2;
    merge_sort(vec, left, mid);
    merge_sort(vec, mid + 1, right);
    merge(vec, left, mid, right);
}

vector<int> find_similarity(vector<int>& first, vector<int>& second) {
    unordered_map<int, int> countFirst, countSecond;
    for (int num : first) {
        countFirst[num]++;
    }
    for (int num : second) {
        countSecond[num]++;
    }
    vector<int> res;
    for (auto entry : countFirst) {
        int num = entry.first;
        int count = min(entry.second, countSecond[num]);
        for (int i = 0; i < count; ++i) {
            res.push_back(num);
        }
    }
    return res;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> first(n), second(m);

    for (int i = 0; i < n; ++i) {
        cin >> first[i];
    }
    for (int i = 0; i < m; ++i) {
        cin >> second[i];
    }

    merge_sort(first, 0, n-1);
    merge_sort(second, 0, m-1);
    vector<int> res = find_similarity(first, second);
    
    for (int num : res) {
        cout << num << ' ';
    }
    return 0;
}
