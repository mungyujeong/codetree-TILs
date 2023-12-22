#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;

int n, k;
unordered_map<long long, long long> m;
vector<long long> v;

int main() {
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        m[x]++;
    }
    int max_count = 0;
    for (auto i : m) {
        if (max_count == i.second) {
            v.push_back(i.first);
        } else if (max_count < i.second) {
            v.clear();
            max_count = i.second;
            v.push_back(i.first);
        }
    }
    sort(v.begin(), v.end(), greater<>());

    for (auto i : v)
        cout << i << " ";

    return 0;
}