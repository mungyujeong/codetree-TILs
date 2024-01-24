#include <iostream>

#define MAX_N 20

using namespace std;

int n, answer;
int dx[] = {-1, -1, 1, 1};
int dy[] = {1, -1, -1, 1};
int board[MAX_N][MAX_N];

int get_sum(int x, int y, int w, int h) {
    int cnt = 0;

    for (int i = 0; i < w; i++) {
        int nx = x + dx[0];
        int ny = y + dy[0];
        if (nx < 0 || nx >= n || ny < 0 || ny >= n) return -1;
        cnt += board[nx][ny];
        x = nx;
        y = ny;
    }

    for (int i = 0; i < h; i++) {
        int nx = x + dx[1];
        int ny = y + dy[1];
        if (nx < 0 || nx >= n || ny < 0 || ny >= n) return -1;
        cnt += board[nx][ny];
        x = nx;
        y = ny;
    }

    for (int i = 0; i < w; i++) {
        int nx = x + dx[2];
        int ny = y + dy[2];
        if (nx < 0 || nx >= n || ny < 0 || ny >= n) return -1;
        cnt += board[nx][ny];
        x = nx;
        y = ny;
    }

    for (int i = 0; i < h; i++) {
        int nx = x + dx[3];
        int ny = y + dy[3];
        if (nx < 0 || nx >= n || ny < 0 || ny >= n) return -1;
        cnt += board[nx][ny];
        x = nx;
        y = ny;
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