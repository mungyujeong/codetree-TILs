#include <iostream>
#include <climits>
#include <vector>
#include <algorithm>

#define MAX_N 15
#define MAX_X 1000

using namespace std;

int n, answer = INT_MIN;
vector<pair<int, int>> v;

void MaxLine(int depth, int count, int endpoint) {
    if (depth == n) {
        answer = max(answer, count);
        return;
    }

    for (int i = depth; i < n; i++) {
        if (endpoint < v[i].first) 
            MaxLine(i + 1, count + 1, v[i].second);
    }
    return;
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x1, x2;
        cin >> x1 >> x2;
        v.push_back({x1, x2});
    }
    sort(v.begin(),  v.end());

    MaxLine(0, 0, 0);

    cout << answer;
    return 0;
}