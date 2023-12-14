#include <iostream>
#include <climits>

#define MAX_N 100

using namespace std;

int k, n;
int arr[MAX_N];

int main() {
    cin >> n >> k;
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    
    int max_num = INT_MIN;
    for (int i = 0; i <= n - k; i++) {
        int sum = 0;
        for (int j = i; j < i + k; j++) {
            sum += arr[j];
        }
        max_num = max(max_num, sum);
    }

    cout << max_num;
    return 0;
}