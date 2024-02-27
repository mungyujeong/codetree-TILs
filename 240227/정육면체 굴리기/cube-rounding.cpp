#include <iostream>
#include <queue>
#include <tuple>

#define MAX_N 20

using namespace std;

int n, m, x, y, k, board[MAX_N][MAX_N], dir;
int dice[] = {0, 0, 0, 0, 0, 0, 0};
int up = 1;
int front = 2;
int r = 3;
int dx[] = {0, 0, 0, -1, 1};
int dy[] = {0, 1, -1, 0, 0};

bool in_range(int x, int y) {
    return 0 <= x && x < n && 0 <= y && y < m;
}

void simulate() {
    int nx = x + dx[dir];
    int ny = y + dy[dir];
    if (!in_range(nx, ny)) return;

    // 주사위 업데이트
    if (dir == 1) {
        tie(up, front, r) = make_tuple(7 - r, front, up);
    }
    else if (dir == 2) {
        tie(up, front, r) = make_tuple(r, front, 7 - up);
    }
    else if (dir == 3) {
        tie(up, front, r) = make_tuple(front, 7 - up, r);
    }
    else {
        tie(up, front, r) = make_tuple(7 - front, up, r);
    }

    int bottom = 7 - up;

    if (board[nx][ny] == 0) {
        board[nx][ny] = dice[bottom];
        dice[bottom] = 0;
    }
    else {
        dice[bottom] = board[nx][ny];
        board[nx][ny] = 0;
    }

    cout << dice[up] << '\n';
    x = nx; y = ny;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m >> x >> y >> k;
    for (int i = 0; i < n; i++)
        for (int j =0 ; j < m; j++)
            cin >> board[i][j];
    
    for (int i = 0; i < k; i++) {
        cin >> dir;
        simulate();
    }

    return 0;
}