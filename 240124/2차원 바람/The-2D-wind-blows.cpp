#include <iostream>
#include <queue>
#include <tuple>

#define MAX_N 100

using namespace std;

int n, m, Q, r1, c1, r2, c2;
int board[MAX_N + 1][MAX_N + 1];
int dx[] = {0, 1, -1, 0, 0};
int dy[] = {0, 0, 0, 1, -1};

void wind() {
    int tmp = board[r1][c2];
    for (int i = c2; i > c1; i--)
        board[r1][i] = board[r1][i - 1];
    
    int tmp2 = board[r2][c2];
    for (int i = r2; i > r1 + 1; i--)
        board[i][c2] = board[i - 1][c2];
    board[r1 + 1][c2] = tmp;

    int tmp3 = board[r2][c1];
    for (int i = c1; i < c2 - 1; i++) 
        board[r2][i] = board[r2][i + 1];
    board[r2][c2 - 1] = tmp2;

    for (int i = r1; i < r2 - 1; i++)
        board[i][c1] = board[i + 1][c1];
    board[r2 - 1][c1] = tmp3;
}

void average() {
    int tmp[MAX_N + 1][MAX_N + 1];
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            tmp[i][j] = board[i][j];
    
    for (int i = r1; i <= r2; i++) {
        for (int j = c1; j <= c2; j++) {
            int avg = 0;
            int cnt = 0;
            for (int d = 0; d < 5; d++) {
                int nx = i + dx[d];
                int ny = j + dy[d];
                if (nx < 1 || ny < 1 || nx > n || ny > m) continue;
                avg += board[nx][ny];
                cnt++;
            }
            avg /= cnt;
            tmp[i][j] = avg;
        }
    }

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            board[i][j] = tmp[i][j];
}

void Simulate() {
    wind();
    average();
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m >> Q;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> board[i][j];
    
    for (int i = 0; i < Q; i++) {
        cin >> r1 >> c1 >> r2 >> c2;
        Simulate();
    }
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++)
            cout << board[i][j] << ' ';
        cout << endl;
    }
}