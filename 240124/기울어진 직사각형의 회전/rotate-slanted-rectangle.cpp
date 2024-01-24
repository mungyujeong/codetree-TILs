#include <iostream>

#define MAX_N 100

using namespace std;

int n, r, c, dir;
int m[4];
int board[MAX_N + 1][MAX_N + 1];
int dx[] = {-1, -1, 1, 1};
int dy[] = {1, -1, -1, 1};

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            cin >> board[i][j];
    
    cin >> r >> c >> m[0] >> m[1] >> m[2] >> m[3] >> dir;

    if (dir == 0) {
        int tmpx = r - 1;
        int tmpy = c + 1;
        int tmp = board[r][c];
        for (int t = 3; t >= 0; t--) {
            for (int i = 0; i < m[t]; i++) {
                int nx = r - dx[t];
                int ny = c - dy[t];
                board[r][c] = board[nx][ny];
                r = nx;
                c = ny;
            }
        }

        board[tmpx][tmpy] = tmp;
    }
    else {
        int tmpx = r - 1;
        int tmpy = c - 1;
        int tmp = board[r][c];
        for (int t = 0; t < 4; t++) {
            for (int i = 0; i < m[t]; i++) {
                int nx = r + dx[t];
                int ny = c + dy[t];
                board[r][c] = board[nx][ny];
                r = nx;
                c = ny;
            }
        }

        board[tmpx][tmpy] = tmp;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++)
            cout << board[i][j] << ' ';
        cout << endl;
    }
}