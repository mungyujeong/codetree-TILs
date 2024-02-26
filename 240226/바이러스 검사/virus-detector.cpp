#include <iostream>

#define MAX_N 1'000'000

using namespace std;
using ll = long long;

ll n, arr[MAX_N], a, b, answer;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cin >> a >> b;
    for (int i = 0; i < n; i++) {
        answer++;
        arr[i] -= a;
        if (arr[i] < 0) arr[i] = 0;
        answer += arr[i] / b;
        if (arr[i] % b > 0) answer++;
    }

    cout << answer;
    return 0;
}