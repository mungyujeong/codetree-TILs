#include <iostream>
#include <unordered_map>

using namespace std;

int n;
unordered_map<long long, long long> m;

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        long long x, y;
        cin >> x >> y;
        if (m.find(x) != m.end()) {
            if (m[x] > y)
                m[x] = y;
        } else {
            m[x] = y;
        }
    }
    long long answer = 0;
    for (auto i : m) {
        answer += i.second;
    }

    cout << answer;
    return 0;
}