#include <iostream>
#include <queue>

#define MAX_N 20

using namespace std;

int n, m, t, answer, board[MAX_N][MAX_N], marble[MAX_N][MAX_N];

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

bool in_range(int x, int y) {
    return 0 <= x && x < n && 0 <= y && y < n;
}

void update(int x, int y) {
    for (int d = 0; d < 4; d++) {
        int nx = x + dx[d];
        int ny = y + dy[d];
        if (!in_range(nx, ny)) continue;
        if (board[nx][ny] > board[x][y]) {
            marble[nx][ny]++;
            marble[x][y]--;
            return;
        }
    }
}

void move() {
    for (int i = 0; i < n; i++) 
        for (int j = 0; j < n; j++)
            if (marble[i][j] == 1)
                update(i, j);
    
    for (int i = 0; i < n; i++) 
        for (int j = 0; j < n; j++)
            if (marble[i][j] >= 2)
                marble[i][j] = 0;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m >> t;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> board[i][j];
    
    for (int i = 0; i < m; i++) {
        int r, c;
        cin >> r >> c;
        marble[r - 1][c - 1]++;
    }

    while (t--) {
        move();
    }

    for (int i = 0; i < n; i++) 
        for (int j = 0; j < n; j++)
            if (marble[i][j])
                answer++;
    
    cout << answer;
    
    return 0;
}