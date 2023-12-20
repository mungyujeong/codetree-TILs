#include <iostream>

#define MAX_N 100
#define OFFSET 100

using namespace std;

int n;
int arr[MAX_N + OFFSET + 1] = {0, };
int answer = 0;

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x1, x2;
        cin >> x1 >> x2;
        for (int j = x1 + OFFSET; j < x2 + OFFSET; j++) {
            arr[j]++;
        }
    }

    for (int j = 0; j < MAX_N + OFFSET + 1; j++) {
        if (arr[j] > 1) {
            answer = max(answer, arr[j]);
        }
    }
    cout << answer;
    return 0;
}