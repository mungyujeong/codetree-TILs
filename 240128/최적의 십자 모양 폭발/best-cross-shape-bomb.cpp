#include <iostream>

#define MAX_N 50

using namespace std;

int n, board[MAX_N][MAX_N], tmp[MAX_N][MAX_N], answer;
int dx[] = {0, 1, -1, 0};
int dy[] = {1, 0, 0, -1};

void initialize() {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            tmp[i][j] = board[i][j];
}

bool InRange(int x, int y) {
    return 0 <= x && x < n && 0 <= y && y < n;
}

void bomb(int x, int y) {
    tmp[x][y] = 0;
    for (int i = 1; i < board[x][y]; i++) {
        for (int d = 0; d < 4; d++) {
            int nx = x + dx[d] * i;
            int ny = y + dy[d] * i;
            if (!InRange(nx, ny)) continue;
            if (tmp[nx][ny] == 0) continue;
            tmp[nx][ny] = 0;
        }
    }
}

void gravity() {
    for (int i = 0; i < n; i++) {
        int arr[MAX_N] = {};
        int idx = 0;
        for (int j = n - 1; j >= 0; j--) 
            if (tmp[j][i])
                arr[idx++] = tmp[j][i];
        
        for (int j = 0; j < n; j++)
            tmp[n - j - 1][i] = arr[j];
    }
}

int find_pair() {
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (tmp[i][j] == 0) continue;
            for (int d = 0; d < 2; d++) {
                int ni = i + dx[d];
                int nj = j + dy[d];
                if (!InRange(ni, nj)) continue;
                if (tmp[ni][nj] == tmp[i][j]) cnt++;
            }
        }
    }

    return cnt;
}

void pr() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            cout << tmp[i][j] << ' ';
        cout << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    for (int i = 0; i < n; i++) 
        for (int j = 0; j < n; j++) 
            cin >> board[i][j];
        
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            initialize();
            bomb(i, j);
            gravity();
            answer = max(answer, find_pair());
        }
    }

    cout << answer;
}