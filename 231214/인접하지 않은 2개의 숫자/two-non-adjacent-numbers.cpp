#include <iostream>
#include <climits>

#define MAX_N 100

using namespace std;

int n;
int arr[MAX_N];
int max_sum = INT_MIN;

int main() {
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    
    for (int i = 0; i < n - 2; i++) 
        for (int j = i + 2; j < n; j++) 
            max_sum = max(max_sum, arr[i] + arr[j]);
        
    cout << max_sum;
    return 0;
}