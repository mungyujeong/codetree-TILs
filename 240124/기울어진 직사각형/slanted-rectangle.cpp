#include <iostream>

#define MAX_N 20

using namespace std;

int n, answer;
int dx[] = {-1, -1, 1, 1};
int dy[] = {1, -1, -1, 1};
int board[MAX_N][MAX_N];

int get_sum(int x, int y, int w, int h) {
    int cnt = 0;
    int move_dist[] = {w, h, w, h};

    for (int d = 0; d < 4; d++) {
        for (int i = 0; i < move_dist[d]; i++) {
            x += dx[d];
            y += dy[d];
            if (x < 0 || y < 0 || x >= n || y >= n) return -1;
            cnt += board[x][y];
        }
    }

    return cnt;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> board[i][j];

    for (int i = 0; i < n; i++) 
        for (int j = 0; j < n; j++) 
            for (int k = 1; k < n; k++) 
                for (int l = 1; l < n; l++) 
                    answer = max(answer, get_sum(i, j, k, l));
        
    cout << answer;
}