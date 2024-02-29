#include <iostream>
#include <queue>
#include <vector>
#include <tuple>
#include <algorithm>

#define MAX_N 8

using namespace std;

int n, m, board[MAX_N][MAX_N], backup[MAX_N][MAX_N], answer;
vector<pair<int, int>> v, fire;

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

bool in_range(int x, int y) {
    return 0 <= x && x < n && 0 <= y && y < m;
}

int bfs() {
    int x, y;
    int result = 0;
    queue<pair<int, int>> Q;
    for (auto i : fire)
        Q.push(i);

    while (!Q.empty()) {
        tie(x, y) = Q.front(); Q.pop();
        for (int d = 0; d < 4; d++) {
            int nx = x + dx[d];
            int ny = y + dy[d];
            if (!in_range(nx, ny)) continue;
            if (board[nx][ny] == 1 || board[nx][ny] == 2) continue;
            board[nx][ny] = 2;
            Q.push({nx, ny});
        }
    }

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (board[i][j] == 0) 
                result++;

    return result;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            cin >> board[i][j];
            backup[i][j] = board[i][j];

            if (board[i][j] == 0) 
                v.push_back({i, j});
            else if (board[i][j] == 2)
                fire.push_back({i, j});
        }

    vector<int> comb(v.size(), 0);
    fill(comb.end() - 3, comb.end(), 1);
    do {
        int x, y;
        for (int i = 0; i < comb.size(); i++) {
            if (comb[i] == 0) continue;
            tie(x, y) = v[i];
            board[x][y] = 1;
        }

        answer = max(answer, bfs());
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                board[i][j] = backup[i][j];
    } while (next_permutation(comb.begin(), comb.end()));

    cout << answer;
    return 0;
}