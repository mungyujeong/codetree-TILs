#include <iostream>
#include <unordered_map>

#define MAX_N 100000

using namespace std;

long long n, k;
long long arr[MAX_N];
int answer = 0;
unordered_map<long long, long long> m;
unordered_map<long long, long long> cnt;

int main() {
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        m[arr[i]] = k - arr[i];
        cnt[arr[i]]++;
    }

    int answer = 0;
    for (int i = 0; i < MAX_N; i++) {
        // cout << arr[i] << " " << m[arr[i]] << endl;
        if (cnt.find(arr[i]) != cnt.end() && cnt[m[arr[i]]] > 0) {
            if (m[arr[i]] == arr[i]) {
                cnt[m[arr[i]]]--;
                answer += cnt[m[arr[i]]];
                // cout << "cnt: " << cnt[m[arr[i]]] << " " << cnt[arr[i]] << endl;
                // cnt[arr[i]]--;
            } else {
                answer += cnt[m[arr[i]]];
                // cout << "cnt: " << cnt[m[arr[i]]] << " " << cnt[arr[i]] << endl;
                cnt[m[arr[i]]]--;
                cnt[arr[i]]--;
            }
        }
    }

    cout << answer;

    return 0;
}