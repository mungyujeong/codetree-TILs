#include <iostream>
#include <queue>
#include <tuple>

#define MAX_N 100

using namespace std;

int n, r, c, board[MAX_N][MAX_N], x, y;
// 상하좌우
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
queue<pair<int, int>> Q;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> r >> c;
    for (int i = 0; i < n; i++) 
        for (int j = 0; j < n; j++) 
            cin >> board[i][j];
        
    Q.push({r - 1, c - 1});
    while (!Q.empty()) {
        tie(x, y) = Q.front(); Q.pop();
        cout << board[x][y] << ' ';
        for (int d = 0; d < 4; d++) {
            int nx = x + dx[d];
            int ny = y + dy[d];
            if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
            if (board[nx][ny] <= board[x][y]) continue;
            Q.push({nx, ny});
            break;
        }
    }
}