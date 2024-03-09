#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
#include <queue>

#define MAX_N 20

using namespace std;

int n, board[MAX_N][MAX_N], answer, exp, level = 2;
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, 1, -1};
pair<int, int> cur;

bool in_range(int x, int y) {
    return 0 <= x && x < n && 0 <= y && y < n;
}

int bfs(int tx, int ty) {
    int dist[MAX_N][MAX_N] = {};
    int x, y;
    tie(x, y) = cur;
    queue<pair<int, int>> Q;
    Q.push({x, y});
    dist[x][y] = 1;

    while (!Q.empty()) {
        tie(x, y) = Q.front(); Q.pop();
        if (x == tx && y == ty) return dist[x][y] - 1;

        for (int d = 0; d < 4; d++) {
            int nx = x + dx[d];
            int ny = y + dy[d];
            if (!in_range(nx, ny)) continue;
            if (dist[nx][ny]) continue;
            if (board[nx][ny] > level) continue;
            dist[nx][ny] = dist[x][y] + 1;
            Q.push({nx, ny});
        }
    }

    return -1;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> board[i][j];
            if (board[i][j] == 9) {
                board[i][j] = 0;
                cur = make_pair(i, j);
            }
        }
    }

    while (true) {
        vector<tuple<int, int, int>> monster;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == 0) continue;
                if (board[i][j] >= level) continue;
                int dist = bfs(i, j);
                if (dist == -1) continue;
                monster.push_back({dist, i, j});
            }
        }

        if (monster.empty()) break;

        sort(monster.begin(), monster.end());
        int d, x, y;
        tie(d, x, y) = monster[0];
        answer += d;
        cur = make_pair(x, y);
        board[x][y] = 0;
        exp++;

        if (level == exp) {
            level++;
            exp = 0;
        }
    }

    cout << answer;
    return 0;
}