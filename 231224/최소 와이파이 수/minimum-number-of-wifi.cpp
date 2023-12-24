#include <iostream>

#define MAX_N 100

using namespace std;

int n, m;
int arr[MAX_N];
int rp[MAX_N];

int main() {
    cin >> n >> m;
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        if (arr[i] == 1) cnt++;
    }

    if (cnt == 1) {
        cout << 1;
        return 0;
    } else if (cnt == 0) {
        cout << 0;
        return 0;
    } else if (n <= m) {
        cout << 1;
        return 0;
    }

    int answer = 0;
    for (int i = 0; i < n; i++) {
        if (rp[i] == 1) continue;
        if (arr[i] == 1) {
            for (int j = i; j <= i + 2 * m; j++) {
                if (j >= n) break;
                rp[j] = 1;
            }
            answer++;
        }
    }

    cout << answer;
    return 0;
}