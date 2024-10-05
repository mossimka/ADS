#include <iostream> 
#include <cstdint> 
using namespace std; 
 
int minSubArr(int n, int k){ 
    int arr[n]; 
    int beg = 0; 
    int end = 0; 
    int sum = 0; 
    int minLength = n+1; 
    for (int i = 0; i < n; i++){ 
        cin >> arr[i]; 
    } 
    while(end < n){ 
        sum += arr[end]; 
        end++; 
        while(sum >= k){ 
            minLength = min(minLength, end - beg); 
            sum -= arr[beg]; 
            beg++; 
        } 
    }
    return minLength;    
} 
int main(){ 
    int n; 
    cin >> n; 
    int k; 
    cin >> k;
    cout << minSubArr(n, k); 
}