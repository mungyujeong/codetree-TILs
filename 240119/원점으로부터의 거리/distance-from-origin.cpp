#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
vector<pair<int, int>> v;

bool cmp(pair<int, int> a, pair<int, int> b) {
    if (a.first == b.first) return a.second < b.second;
    return a.first < b.first;
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int x, y;
        cin >> x >> y;
        v.push_back({abs(x) + abs(y), i});
    }
    sort(v.begin(), v.end(), cmp);
    for (auto i : v)
        cout << i.second << '\n';
    return 0;
}