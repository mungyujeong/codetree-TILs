#include <iostream>
#include <vector>
#include <climits>
#include <tuple>

using namespace std;

vector<pair<int, int>> v;
vector<int> index;
int n, m;
int answer = INT_MAX;

int SquareDist(pair<int, int> a, pair<int, int> b) {
    int x1, x2, y1, y2;
    tie(x1, y1) = a;
    tie(x2, y2) = b;
    return (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
}

int Calc() {
    int dist = INT_MIN;

    for (int i = 0; i < m - 1; i++) {
        for (int j = i + 1; j < m; j++) {
            dist = max(dist, SquareDist(v[index[i]], v[index[j]]));
        }
    }

    return dist;
}

void Dist(int depth, int cnt) {
    if (cnt == m) {
        // for (auto i : index) 
        //     cout << i << " ";
        // cout << endl;
        answer = min(answer, Calc());
        return;
    }

    if (depth == n)
        return;

    index.push_back(depth);
    Dist(depth + 1, cnt + 1);
    index.pop_back();
    Dist(depth + 1, cnt);
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        v.push_back({x, y});
    }

    Dist(0, 0);

    cout << answer;
    return 0;
}