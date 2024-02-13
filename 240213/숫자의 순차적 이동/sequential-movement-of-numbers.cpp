#include <iostream>
#include <climits>
#include <tuple>

#define MAX_N 20

using namespace std;

int n, m, board[MAX_N][MAX_N];
pair<int, int> num[MAX_N * MAX_N + 1];
int dx[] = {-1, 0, 1, 1, 1, 0, -1, -1};
int dy[] = {1, 1, 1, 0, -1, -1, -1, 0};

bool in_range(int x, int y) {
    return 0 <= x && x < n && 0 <= y && y < n;
}

void simulate(int x, int y) {
    int nxt = INT_MIN;
    pair<int, int> p;
    for (int d = 0; d < 8; d++) {
        int nx = x + dx[d];
        int ny = y + dy[d];
        if (!in_range(nx, ny)) continue;
        if (board[nx][ny] > nxt) {
            nxt = board[nx][ny];
            p = make_pair(nx, ny);
        }
    }
    
    swap(num[nxt], num[board[x][y]]);
    swap(board[p.first][p.second], board[x][y]);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> board[i][j];
            num[board[i][j]] = make_pair(i, j);
        }
    }

    while (m--) {
        for (int i = 1; i <= n * n; i++) {
            int x, y;
            tie(x, y) = num[i];
            simulate(x, y);
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            cout << board[i][j] << ' ';
        cout << '\n';
    }
    return 0;
}