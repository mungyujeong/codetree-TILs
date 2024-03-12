#include <iostream>
#include <queue>
#include <tuple>

#define MAX_N 51

using namespace std;

int n, m, q, board[MAX_N][MAX_N], answer;
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
bool changed;

bool in_range(int x, int y) {
    return 1 <= x && x <= n && 1 <= y && y <= m;
}

void rotate(int row, int d, int k) {
    while (k--) {
        // 시계방향
        if (d == 0) {
            int tmp = board[row][m];
            for (int i = m; i > 1; i--)
                board[row][i] = board[row][i - 1];
            board[row][1] = tmp;
        }
        else {
            int tmp = board[row][1];
            for (int i = 1; i < m; i++)
                board[row][i] = board[row][i + 1];
            board[row][m] = tmp;
        }
    }
}

void bfs(int cx, int cy) {
    queue<pair<int, int>> Q;
    int visited[MAX_N][MAX_N] = {};
    int cur = board[cx][cy];
    int cnt = 0;

    Q.push({cx, cy});
    visited[cx][cy] = 1;

    while (!Q.empty()) {
        int x, y;
        tie(x, y) = Q.front(); Q.pop();
        for (int d = 0; d < 4; d++) {
            int nx = x + dx[d];
            int ny = y + dy[d];
            if (!in_range(nx, ny)) continue;
            if (visited[nx][ny]) continue;
            if (board[nx][ny] == cur) {
                Q.push({nx, ny});
                board[nx][ny] = 0;
                cnt++;
            }
            visited[nx][ny] = 1;
        }
    }

    if (cnt != 0) {
        board[cx][cy] = 0;
        changed = true;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m >> q;
    for (int i = 1; i <= n; i++) 
        for (int j = 1; j <= m; j++)
            cin >> board[i][j];
    
    while (q--) {
        int x, d, k;
        cin >> x >> d >> k;
        for (int i = x; i <= n; i+=x) 
            rotate(i, d, k);

        changed = false;

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (board[i][j] == 0) continue;
                bfs(i, j);
            }
        }

        int avg = 0;
        if (!changed) {
            int cnt = 0;
            for (int i = 1; i <= n; i++) {
                for (int j = 1; j <= m; j++) {
                    if (board[i][j]) {
                        avg += board[i][j];
                        cnt++;
                    }
                }
            }
            avg /= cnt;
        }

        if (avg) {
            for (int i = 1; i <= n; i++) 
                for (int j = 1; j <= m; j++)
                    if (board[i][j]) {
                        if (board[i][j] > avg) board[i][j] -= 1;
                        else if (board[i][j] < avg) board[i][j] += 1;
                    }
        } 
    }

    for (int i = 1; i <= n; i++) 
        for (int j = 1; j <= m; j++) 
            if (board[i][j])
                answer += board[i][j];

    cout << answer;
    return 0;
}