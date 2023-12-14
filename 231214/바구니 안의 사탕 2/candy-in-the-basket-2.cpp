#include <iostream>

#define MAX_N 100

using namespace std;

int n, k, max_x;
int basket[MAX_N + 1] = {0, };

int main() {
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        int index, candy;
        cin >> candy >> index;
        basket[index] = candy;
        max_x = max(max_x, index);
    }

    if (max_x <= k) {
        int sum = 0;
        for (int i = 1; i <= max_x; i++) {
            sum += basket[i];
        }
        cout << sum;
        return 0;
    }

    int max_sum = 0;
    for (int c = k + 1; c <= max_x; c++) {
        int sum = 0;
        for (int j = c - k; j <= c + k; j++) {
            if (j > 100) break;
            sum += basket[j];
        }
        max_sum = max(max_sum, sum);
    }

    cout << max_sum;
    return 0;
}