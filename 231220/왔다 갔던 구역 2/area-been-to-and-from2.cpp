#include <iostream>

#define MAX_N 100
#define OFFSET 1000

using namespace std;

int n;
int arr[MAX_N + OFFSET + 1];
int x[MAX_N + 1];
char c[MAX_N + 1];
int curr_x = OFFSET;

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x[i] >> c[i];
    }

    for (int i = 0; i < n; i++) {
        if (c[i] == 'L') {
            for (int j = curr_x - x[i]; j < curr_x; j++) {
                arr[j]++;
            }
            curr_x = curr_x - x[i];
        } else {
            for (int j = curr_x; j < curr_x + x[i]; j++) {
                arr[j]++;
            }
            curr_x = curr_x + x[i];
        }
    }

    int answer = 0;
    for (int i = 0; i < MAX_N + OFFSET + 1; i++) {
        if (arr[i] > 1) answer++;
        // cout << arr[i] << " ";
        // if (i == OFFSET) cout << "| offset: ";
    }
    cout << answer;

    return 0;
}