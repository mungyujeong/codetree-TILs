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
    }

    int answer = 0;

    for (int i = 0; i < n; i++) {
        answer += cnt[k - arr[i]];
        cnt[arr[i]]++;
    }

    cout << answer;

    return 0;
}