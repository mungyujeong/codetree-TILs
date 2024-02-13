#include <iostream>

#define MAX_N 100

using namespace std;

int n, m, k, answer, board[MAX_N][MAX_N];

void rotate() {
    int tmp[MAX_N][MAX_N] = {};
    for (int i = 0; i < n; i++) 
        for (int j = 0; j < n; j++) 
            tmp[i][j] = board[i][j];
        
    for (int i = 0; i < n; i++) 
        for (int j = 0; j < n; j++) 
            board[j][n - 1 - i] = tmp[i][j];
}

void gravity() {
    for (int col = 0; col < n; col++) {
        int tmp[MAX_N] = {};
        int idx = 0;
        for (int row = n - 1; row >= 0; row--) {
            if (board[row][col] == 0) continue;
            tmp[idx++] = board[row][col];
            board[row][col] = 0;
        }

        for (int row = n - 1; row >= 0; row--) 
            board[row][col] = tmp[n - row - 1];
    }
}

bool bomb() {
    bool possible = false;
    for (int col = 0; col < n; col++) {
        int st, en, cnt, num;
        st = en = cnt = num = 0;
        for (int row = 0; row < n; row++) {
            if (board[row][col] == 0) {
                if (cnt >= m) {
                    possible = true;
                    for (int i = st; i <= en; i++)
                        board[i][col] = 0;
                }
                num = cnt = st = en = 0;
            }
            else if (board[row][col] == num) {
                cnt++;
                en = row;
            }
            else {
                if (cnt >= m) {
                    possible = true;
                    for (int i = st; i <= en; i++)
                        board[i][col] = 0;
                }
                cnt = 1;
                st = en = row;
                num = board[row][col];
            }
        }
        if (cnt >= m) {
            possible = true;
            for (int i = st; i <= en; i++)
                board[i][col] = 0;
        }
    }

    return possible;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m >> k;
    for (int i = 0; i < n; i++) 
        for (int j = 0; j < n; j++) 
            cin >> board[i][j];
            
    // bomb() -> gravity 반복
    // rotate()
    while (k--) {
        if (bomb()) gravity();
        rotate();
        gravity();
    }

    // 다 끝나도 터뜨릴 수 있으면 bomb() -> gravity 반복
    while (bomb()) {
        gravity();
    }

    for (int i = 0; i < n; i++) 
        for (int j = 0; j < n; j++)
            if (board[i][j])
                answer++;

    cout << answer;
    return 0;
}