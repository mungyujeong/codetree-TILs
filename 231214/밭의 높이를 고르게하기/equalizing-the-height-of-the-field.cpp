#include <iostream>
#include <climits>

#define MAX_NUM 100

using namespace std;

int n, h, t, min_sum = INT_MAX;
int arr[MAX_NUM];

int main() {
    cin >> n >> h >> t;
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    
    for (int i = 0; i <= n - t; i++) {
        int sum = 0;
        for (int j = i; j < i + t; j++) {
            sum += abs(t - arr[j]);
        }
        cout << endl;
        min_sum = min(min_sum, sum);
    }
    cout << min_sum;
    return 0;
}