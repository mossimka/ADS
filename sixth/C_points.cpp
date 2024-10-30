#include <iostream>
#include <vector>
#include <cstdlib>
#include <cstdint>

using namespace std;

int partition(vector<long long>& vec, int start, int end){
    int p = start + rand() % (end - start + 1);
    swap(vec[start], vec[p]);
    long long x = vec[start];
    int l = start + 1, r = end;
    while (l <= r) {
        if (x > vec[l]) {
            l++;
        } else {
            swap(vec[l], vec[r]);
            r--;
        }
    }
    swap(vec[start], vec[r]);
    return r; 
}

void quick_sort(vector<long long>& vec, int start, int end){
    if(start >= end){
        return;
    }
    int p = partition(vec, start, end);
    quick_sort(vec, start, p);
    quick_sort(vec, p + 1, end);
}

int main(){
    int n;
    cin >> n;
    vector<long long> vec;
    for(int  i = 0; i < n; ++i) {
        long long coord;
        cin >> coord;
        vec.push_back(coord);
    }
    quick_sort(vec, 0, n-1);

    vector<pair<long long, long long>> points;
    long long min_dist = INT64_MAX;
    for(int i = 0; i < n - 1; ++i){
        long long first = vec[i], second = vec[i + 1];
        long long dist = abs(second - first);
        if(dist < min_dist){
            min_dist = dist;
            points.clear();
            points.push_back({first, second});
        } else if(dist == min_dist){
            points.push_back({first, second});
        }
    }
    for(auto p:points){
        cout << p.first << ' ' << p.second << ' ';
    }
    return 0;
}
