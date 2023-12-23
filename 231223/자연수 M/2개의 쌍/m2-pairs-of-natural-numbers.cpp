#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> v;
int n;

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        for (int j = 0; j < x; j++)
            v.push_back(y);
    }

    sort(v.begin(), v.end());
    int answer = 0;
    for (int i = 0; i < v.size() / 2; i++) {
        answer = max(answer, v[i] + v[v.size() - i - 1]);
    }
    cout << answer;
    return 0;
}