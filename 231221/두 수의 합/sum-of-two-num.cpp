#include <iostream>
#include <unordered_map>

#define MAX_N 100000

using namespace std;

int n, k;
int arr[MAX_N];
int answer = 0;
unordered_map<int, int> m;

int main() {
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        if (k - arr[i] == arr[i]) m[k - arr[i]] = 1;
        else m[k - arr[i]] += 1;
    }

    for (int i = 0; i < n; i++) {
        // answer += m[arr[i]];
        if (m[arr[i]]) {
            answer += m[arr[i]];
        }
    }

    cout << answer / 2;

    return 0;
}