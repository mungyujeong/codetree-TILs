#include <iostream>

#define MAX_N 200

using namespace std;

int board[MAX_N][MAX_N];
int n, m, col;
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

void bomb() {
    for (int i = 0; i < n; i++) {
        if (board[i][col] == 0) continue;

        int times = board[i][col] - 1;
        board[i][col] = 0;

        for (int d = 0; d < 4; d++) {
            int sx = i;
            int sy = col;
            for (int t = 0; t < times; t++) {
                sx += dx[d];
                sy += dy[d];
                if (sx < 0 || sy < 0 || sx >= n || sy >= n) break;
                board[sx][sy] = 0;    
            }
        }

        break;
    }
}

void gravity() {
    int tmp[MAX_N][MAX_N] = {};

    for (int c = 0; c < n; c++) {
        int tmp_idx = n - 1;
        for (int row = n - 1; row >= 0; row--) {
            if (board[row][c] == 0) continue;
            tmp[tmp_idx--][c] = board[row][c];
        }
    }

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            board[i][j] = tmp[i][j];
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> board[i][j];
    
    for (int i = 0; i < m; i++) {
        cin >> col;
        col--;

        bomb();
        gravity();
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            cout << board[i][j] << ' ';
        cout << endl;
    }
}