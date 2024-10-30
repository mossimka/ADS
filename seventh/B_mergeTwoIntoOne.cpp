#include <iostream>
#include <vector>

using namespace std;

vector<int> merge(vector<int>& f, vector<int>& s, int n, int m){
    int i = 0, j = 0;
    vector<int> res;
    while(i < n && j < m){
        if(f[i] < s[j]){
            res.push_back(f[i]);
            i++;
        } else{
            res.push_back(s[j]);
            j++;
        }
    }
    while(i < n){
        res.push_back(f[i]);
        i++;
    }
    while(j < m){
        res.push_back(s[j]);
        j++;
    }
    return res;
}

int main(){
    int n;
    cin >> n;
    vector<int> first;
    for(int i = 0; i < n; ++i){
        int num;
        cin >> num;
        first.push_back(num);
    }
    int m;
    cin >> m;
    vector<int> second;
    for(int j = 0; j < m; ++j){
        int num;
        cin >> num;
        second.push_back(num);
    }
    vector<int> res = merge(first, second, n, m);
    int size = res.size();
    for(int i = 0; i < size; ++i){
        cout << res[i] << ' ';
    }
}