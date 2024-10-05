#include <iostream> 

using namespace  std; 
 
bool check(int n, int a[], long long m, int k){ 
    long long count = 0; 
    long long sum = 0; 
    for(int i = 0; i < n; i++){ 
        if(a[i] > m){ 
            return false; 
        }else if (sum + a[i] > m){ 
            sum = a[i]; 
            count++; 
        }else{ 
            sum += a[i]; 
        } 
    } 
    count++; 
    return count <= k; 
} 
 
int main(){ 
    int n;
    cin >> n; 
    int k; 
    cin >> k; 
    int a[n]; 
    long long l = 0; 
    long long r = 0; 
    for(int i = 0; i < n; i++){ 
        cin >> a[i]; 
        r += a[i]; 
    } 
    long long ans = 0; 
    while(l <= r){ 
        long long mid = l + (r - l) / 2; 
        if(check(n,a,mid,k)){ 
            ans = mid; 
            r = mid - 1; 
        }else{ 
            l = mid + 1; 
        } 
    } 
    cout << ans; 
    return 0; 
}