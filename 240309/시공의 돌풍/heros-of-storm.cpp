#include <iostream>
#include <vector>
#include <tuple>

#define MAX_N 50

using namespace std;

int n, m, t, board[MAX_N][MAX_N], answer;
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
vector<pair<int, int>> v;

bool in_range(int x, int y) {
    return 0 <= x && x < n && 0 <= y && y < m;
}

void move_dust() {
    int nxt[MAX_N][MAX_N] = {};

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (board[i][j] != -1) {
                int tmp = board[i][j] / 5;
                for (int d = 0; d < 4; d++) {
                    int nx = i + dx[d];
                    int ny = j + dy[d];
                    if (!in_range(nx, ny)) continue;
                    if (board[nx][ny] == -1) continue;
                    nxt[nx][ny] += tmp;
                    board[i][j] -= tmp;
                }            
            }
        }
    }

    for (int i = 0; i < n; i++) 
        for (int j = 0; j < m; j++)
            board[i][j] += nxt[i][j];
}

void clean() {
    int x, y, tmp;

    // 반시계
    tie(x, y) = v[0];
    for (int i = x - 1; i >= 1; i--)
        board[i][0] = board[i - 1][0];
    for (int i = 0; i < m - 1; i++)
        board[0][i] = board[0][i + 1];
    for (int i = 0; i < x; i++) 
        board[i][m - 1] = board[i + 1][m - 1];
    for (int i = m - 1; i >= 1; i--)
        board[x][i] = board[x][i - 1];
    board[x][1] = 0;

    // 시계
    tie(x, y) = v[1];
    for (int i = x + 1; i < n - 1; i++)
        board[i][0] = board[i + 1][0];
    for (int i = 0; i < m - 1; i++)
        board[n - 1][i] = board[n - 1][i + 1];
    for (int i = n - 1; i >= x; i--)
        board[i][m - 1] = board[i - 1][m - 1];
    for (int i = m - 1; i >= 1; i--)
        board[x][i] = board[x][i - 1];
    board[x][1] = 0;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m >> t;
    for (int i = 0; i < n; i++) 
        for (int j = 0; j < m; j++) {
            cin >> board[i][j];
            if (board[i][j] == -1)
                v.push_back({i, j});
        }
    
    while (t--) {
        move_dust();
        clean();
    }

    for (int i = 0; i < n; i++) 
        for (int j = 0; j < m; j++)
            if (board[i][j] != -1)
                answer += board[i][j];
                
    cout << answer;
    return 0;
}