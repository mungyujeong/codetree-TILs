#include <iostream>

#define MAX_N 200

using namespace std;

int n, r, c;
int board[MAX_N + 1][MAX_N + 1];
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

void bomb(int sx, int sy) {
    int sz = board[sx][sy];
    board[sx][sy] = 0;
    if (sz < 2) return;

    for (int d = 0; d < 4; d++) {
        int x = sx; int y = sy;
        for (int i = 0; i < sz - 1; i++) {
            x += dx[d];
            y += dy[d];
            if (x < 1 || y < 1 || x > n || y > n) break;
            board[x][y] = 0;
        }
    }
}

void gravity() {
    int tmp[MAX_N + 1][MAX_N + 1];
    
    for (int i = 1; i <= n; i++) { // 열
        int tmp_idx = n;
        for (int j = n; j >= 1; j--)  // 행
            if (board[j][i] != 0)
                tmp[tmp_idx--][i] = board[j][i];
    }

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            board[i][j] = tmp[i][j];
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++)    
        for (int j = 1; j <= n; j++)
            cin >> board[i][j];

    cin >> r >> c;   

    bomb(r, c);
    gravity();

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++)
            cout << board[i][j] << ' ';
        cout << endl;
    }
}