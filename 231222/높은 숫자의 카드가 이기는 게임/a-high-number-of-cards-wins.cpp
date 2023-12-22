#include <iostream>
#include <climits>

#define MAX_N 50000

using namespace std;

int n;
bool arr[MAX_N + 1] = {false, };
int answer = 0;

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        arr[x] = true;
    }

    int curr = 0;
    for (int i = 1; i <= 2 * n; i++) {
        // cout << arr[i] << endl;
        if (arr[i]) curr = i;
        else {
            if (curr < i) {
                answer++;
                curr = INT_MAX;
            }
        }
    }
    cout << answer;
    return 0;
}