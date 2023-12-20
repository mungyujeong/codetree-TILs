#include <iostream>

#define MAX_N 100

using namespace std;

int n;
int arr[MAX_N + 1];
int answer;

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x1, x2;
        cin >> x1 >> x2;
        for (int j = x1; j <= x2; j++) {
            arr[j]++;
        }
    }

    for (int i = 0; i < MAX_N + 1; i++) {
        answer = max(answer, arr[i]);
    }

    cout << answer;
    return 0;
}