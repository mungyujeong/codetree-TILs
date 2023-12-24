#include <iostream>
#include <algorithm>
#include <climits>

#define MAX_N 100000

using namespace std;

int n;
int arr[MAX_N];

int main() {
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    
    sort(arr, arr + n);

    if (n == 3) {
        cout << arr[0] * arr[1] * arr[2];
        return 0;
    }

    if (arr[0] >= 0 || arr[n - 1] < 0) {
        cout << arr[n - 1] * arr[n - 2] * arr[n - 3];
        return 0;
    }

    if (arr[n - 1] == 0) {
        cout << 0;
        return 0;
    }

    // if (arr[n - 1] < 0) {
    //     cout << arr[n - 1] * arr[n - 2] * arr[n - 3];
    //     return 0;
    // }

    int answer = INT_MIN;
    answer = max(answer, arr[n - 1] * arr[n - 2] * arr[n - 3]);
    answer = max(answer, arr[0] * arr[1] * arr[n - 1]);

    cout << answer;

    return 0;
}