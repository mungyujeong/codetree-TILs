#include <iostream>
#include <queue>
#include <tuple>

#define MAX_N 20

using namespace std;

int n, m, answer;
int board[MAX_N][MAX_N];
queue<pair<int, int>> Q;
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

void bfs(int sx, int sy, int k) {
    int visited[MAX_N][MAX_N] = {};
    int gold = 0;
    Q.push({sx, sy});
    visited[sx][sy] = 1;
    int x, y;
    while (!Q.empty()) {
        tie(x, y) = Q.front(); Q.pop();
        if (board[x][y] == 1) gold++;
        for (int d = 0; d < 4; d++) {
            int nx = x + dx[d];
            int ny = y + dy[d];
            if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
            if (visited[nx][ny]) continue;
            if (visited[x][y] > k) continue;
            visited[nx][ny] = visited[x][y] + 1;
            Q.push({nx, ny});
        }
    }
    // gold -= ((k * k) + ((k + 1) * (k + 1)));
    // answer = max(answer, gold);
    if (gold * m - ((k * k) + ((k + 1) * (k + 1))) >= 0) {
        // cout << k << ": " << gold << " x, y: " << x << ' ' << y << endl;
        answer = max(answer, gold);

    }
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) 
        for (int j = 0; j < n; j++) 
            cin >> board[i][j];
        
    int max_k = (n - 1) * 2;
    for (int k = 0; k <= max_k; k++) 
        for (int i = 0; i < n; i++) 
            for (int j = 0; j < n; j++) 
                bfs(i, j, k);                

    cout << answer;
    return 0;
}