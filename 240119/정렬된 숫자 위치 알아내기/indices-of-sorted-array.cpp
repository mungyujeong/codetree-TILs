#include <iostream>
#include <algorithm>
#include <vector>

#define MAX_N 1'000

using namespace std;

int n;
vector<pair<int, int>> v;
int answer[MAX_N];

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        v.push_back({x, i});
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < n; i++)
        answer[v[i].second] = i + 1;
    
    for (int i = 0; i < n; i++)
        cout << answer[i] << ' ';
    return 0;
}