#include <iostream>
#include <queue>
#include <tuple>
#include <cmath>

#define MAX_N 101

using namespace std;

int n, m, board[MAX_N][MAX_N], r, c, cnt;
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

bool InRange(int x, int y) {
    return 1 <= x && x <= n && 1 <= y && y <= n;
}

void simulate(int time) {
    int dist = pow(2, time - 1);
    int tmp[MAX_N][MAX_N];

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            tmp[i][j] = board[i][j];

    for (int x = 1; x <= n; x++) {
        for (int y = 1; y <= n; y++) {
            if (!board[x][y]) continue;
            for (int d = 0; d < 4; d++) {
                int nx = x + dx[d] * dist;
                int ny = y + dy[d] * dist;
                if (!InRange(nx, ny)) continue;
                if (board[nx][ny]) continue;
                tmp[nx][ny] = 1;
            }
        }
    }

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            board[i][j] = tmp[i][j];
}

int main() {
    cin >> n >> m >> r >> c;
    board[r][c] = 1;

    for (int t = 1; t <= m; t++) 
        simulate(t);

    for (int i = 1; i <= n; i++) 
        for (int j = 1; j <= n; j++)
            if (board[i][j])
                cnt++;

    cout << cnt;
    return 0;
}