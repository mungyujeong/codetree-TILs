#include <iostream>
#include <climits>

#define MAX_N 10000

using namespace std;

int s, n, sum;
int arr[MAX_N];
int min_diff = INT_MAX;

int main() {
    cin >> n >> s;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        sum += arr[i];
    }
    int tmp = sum;
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            tmp -= arr[i];
            tmp -= arr[j];
            min_diff = min(min_diff, abs(tmp - s));
            tmp = sum;
        }
    }

    cout << min_diff;
    return 0;
}