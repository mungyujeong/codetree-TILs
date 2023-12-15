#include <iostream>
#include <climits>

#define MAX_N 100

using namespace std;

int n, answer = INT_MIN;
int x[MAX_N];
int y[MAX_N];

int IsValid(int i, int j, int k) {
    if (x[i] == x[j] && y[i] == y[k]) return true;
    if (x[i] == x[j] && y[j] == y[k]) return true;
    if (x[i] == x[k] && y[i] == y[j]) return true;
    if (x[i] == x[k] && y[k] == y[j]) return true;
    if (x[j] == x[k] && y[j] == y[i]) return true;
    if (x[j] == x[k] && y[k] == y[i]) return true;

    return false;
}

int GetValue(int i, int j, int k) {
    return abs((x[i] * y[j] + x[j] * y[k] + x[k] * y[i]) - (x[j] * y[i] + x[k] * y[j] + x[i] * y[k]));
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> x[i] >> y[i];

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            for (int k = j + 1; k < n; k++) {
                if (IsValid(i, j, k)) {
                    answer = max(answer, GetValue(i, j, k));
                }
            }
        }
    }
    cout << answer;
    return 0;
}