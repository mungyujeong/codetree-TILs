#include <iostream>
#include <queue>
#include <tuple>

#define MAX_N 100

using namespace std;

int n, d, answer;
char board[MAX_N][MAX_N][2];
// 동 남 서 북
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

bool InRange(int x, int y) {
    return 0 <= x && x < n && 0 <= y && y < n;
}

bool IsWall(int x, int y, int dir) {
    int nx = x + dx[dir];
    int ny = y + dy[dir];
    if (board[nx][ny][0] == '#') return true;
    return false;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int x, y;
    cin >> n;
    cin >> x >> y;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> board[i][j][0];
    
    queue<tuple<int, int, int>> Q;
    Q.push({x - 1, y - 1, 0});
    board[x - 1][y - 1][0] = '1';
    board[x - 1][y - 1][1] = '0';
    while (!Q.empty()) {
        tie(x, y, d) = Q.front(); Q.pop();
        int nx = x + dx[d];
        int ny = y + dy[d];
        if (!InRange(nx, ny)) {
            cout << answer + 1;
            return 0;
        }
        if (board[nx][ny][0] == '#') {
            Q.push({x, y, (d + 3) % 4});
            board[x][y][1] = ((d + 3) % 4) + '0';
            continue;
        }
        if (board[nx][ny][0] == '1' && 
            board[nx][ny][1] == board[x][y][1]) continue;
        if (!IsWall(nx, ny, (d + 1) % 4))
            d = (d + 1) % 4;
        Q.push({nx, ny, d});
        board[nx][ny][0] = '1';
        board[nx][ny][1] = d + '0';
        answer++;
    }

    if (InRange(x, y)) answer = -1;
    cout << answer;
    return 0;
}