#include <iostream>
#include <queue>
#include <tuple>

#define MAX_N 10

using namespace std;

int n, m;
char board[MAX_N][MAX_N];
pair<int, int> blue, red;
bool visited[MAX_N][MAX_N][MAX_N][MAX_N];

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

tuple<int, int, int, int> get_next(int rx, int ry, int bx, int by, int d) {
    int orx, ory, obx, oby;
    orx = rx; ory = ry; obx = bx; oby = by;
    while (true) {
        int nx = rx + dx[d];
        int ny = ry + dy[d];
        if (board[nx][ny] == '#') break;
        rx = nx; ry = ny;
        if (board[nx][ny] == 'O') break;
    }

    while (true) {
        int nx = bx + dx[d];
        int ny = by + dy[d];
        if (board[nx][ny] == '#') break;
        bx = nx; by = ny;
        if (board[nx][ny] == 'O') break;
    }

    if (board[rx][ry] != 'O' && rx == bx && ry == by) {
        // 아래
        if (d == 0) {
            if (orx > obx) bx -= dx[d];
            else rx -= dx[d];
        }
        // 위
        else if (d == 1) {
            if (orx > obx) rx -= dx[d];
            else bx -= dx[d];
        }
        // 오른쪽
        else if (d == 2) {
            if (ory > oby) by -= dy[d];
            else ry -= dy[d];
        }
        // 왼쪽
        else {
            if (ory > oby) ry -= dy[d];
            else by -= dy[d];
        }
    }

    return make_tuple(rx, ry, bx, by);
}

int bfs() {
    // red, blue, move_time
    queue<tuple<int, int, int, int, int>> Q;
    int rx, ry, bx, by, moved;
    tie(rx, ry) = red;
    tie(bx, by) = blue;

    Q.push({rx, ry, bx, by, 0});
    visited[rx][ry][bx][by] = true;

    while (!Q.empty()) {
        tie(rx, ry, bx, by, moved) = Q.front(); Q.pop();
        if (moved == 10) return -1;

        for (int d = 0; d < 4; d++) {
            int nrx, nry, nbx, nby;
            tie(nrx, nry, nbx, nby) = get_next(rx, ry, bx, by, d);

            if (board[nbx][nby] == 'O') continue;
            if (visited[nrx][nry][nbx][nby]) continue;
            if (board[nrx][nry] == 'O') return moved + 1;

            visited[nrx][nry][nbx][nby] = true;
            Q.push({nrx, nry, nbx, nby, moved + 1});
        }
    }

    return -1;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> board[i][j];
            if (board[i][j] == 'B') {
                blue = make_pair(i, j);
                board[i][j] = '.';
            }
            else if (board[i][j] == 'R') {
                red = make_pair(i, j);
                board[i][j] = '.';
            }
        }
    }

    cout << bfs();

    return 0;
}