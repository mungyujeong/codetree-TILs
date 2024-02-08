#include <iostream>
#include <queue>
#include <vector>
#include <tuple>

#define MAX_N 105

using namespace std;

int n, board[MAX_N][MAX_N], answer;
// 우 하 좌 상
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
// convert to 1
int cto1[] = {3, 2, 1, 0};
int cto2[] = {1, 0, 3, 2};

bool in_range(int x, int y) {
    return 1 <= x && x <= n && 1 <= y && y <= n;
}

void simulate(int x, int y, int d) {
    queue<tuple<int, int, int>> Q;
    int t = 0;

    Q.push({x, y, d});
    while (!Q.empty()) {
        t++;
        tie (x, y, d) = Q.front(); Q.pop();
        int nx = x + dx[d];
        int ny = y + dy[d];
        if (!in_range(nx, ny)) break;
        if (board[nx][ny] == 1) d = cto1[d];
        if (board[nx][ny] == 2) d = cto2[d];
        Q.push({nx, ny, d});
    }

    answer = max(answer, t);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            cin >> board[i][j];
    
    // case
    vector<pair<pair<int, int>, pair<int, int>>> v = {
        {{0, 1}, {0, n}},
        {{1, n + 1}, {1, n + 1}},
        {{n + 1, 1}, {n + 1, 1}},
        {{1, 0}, {n, 0}},
    };

    for (auto i : v) {
        pair<int, int> st, en;
        tie(st, en) = i;
        int d = (d + 1) % 4;
        
        if (st.first == en.first) 
            for (int j = st.second; j <= en.second; j++) 
                simulate(st.first, j, d);
        else 
            for (int j = st.first; j <= en.first; j++)
                simulate(j, st.second, d);
    }

    cout << answer;
    return 0;
}