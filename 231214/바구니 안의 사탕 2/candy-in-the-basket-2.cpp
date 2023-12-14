#include <iostream>

#define MAX_N 100

using namespace std;

int n, k, max_x;
int basket[MAX_N + 1] = {0, };

int main() {
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        int index, num;
        cin >> num >> index;
        basket[index] = num;
        max_x = max(max_x, index);
    }

    if (n <= k) {
        int sum;
        for (int i = 0; i < MAX_N; i++) {
            sum += basket[i];
        }
        cout << sum;
        return 0;
    }

    int max_sum = 0;
    for (int c = k + 1; c <= max_x; c++) {
        int sum = 0;
        for (int j = c - k; j <= c + k; j++) {
            sum += basket[j];
        }
        max_sum = max(max_sum, sum);
    }

    cout << max_sum;
    return 0;
}