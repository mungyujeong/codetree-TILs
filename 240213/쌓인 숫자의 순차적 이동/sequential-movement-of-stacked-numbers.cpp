#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>

#define MAX_N 20

using namespace std;

int n, m, val[MAX_N][MAX_N], num[100];
pair<int, int> coord[MAX_N * MAX_N + 1];
vector<int> board[MAX_N][MAX_N];
int dx[] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dy[] = {0, 1, 1, 1, 0, -1, -1, -1};

bool in_range(int x, int y) {
    return 0 <= x && x < n && 0 <= y && y < n;
}

void simulate(int cur) {
    int x, y, rx, ry, max_val;
    tie(x, y) = coord[cur];

    // 이동 좌표 구하기
    max_val = 0;
    rx = x; ry = y;
    for (int d = 0; d < 8; d++) {
        int nx = x + dx[d];
        int ny = y + dy[d];
        if (!in_range(nx, ny)) continue;
        if (max_val < val[nx][ny]) {
            max_val = val[nx][ny];
            rx = nx; ry = ny;
        }
    }

    // 만약 주변에 아무 숫자가 없으면 안움직임
    if (max_val == 0) return;

    // 현재 숫자가 있는 idx 구하기
    vector<int> sub;
    int idx = 0;
    for (int i = 0; i < board[x][y].size(); i++) {
        if (board[x][y][i] == cur) {
            idx = i;
            sub.assign(board[x][y].begin() + i, board[x][y].end());

            // board, coord update
            for (auto j : sub) {
                board[rx][ry].push_back(j);
                coord[j] = make_pair(rx, ry);
            }

            // 기존 board[x][y] update
            int tmp = board[x][y].size() - idx;
            while (tmp--) {
                board[x][y].pop_back();
            }

            // val update
            if (board[x][y].empty()) val[x][y] = 0;
            else val[x][y] = *max_element(board[x][y].begin(), board[x][y].end());
            val[rx][ry] = *max_element(board[rx][ry].begin(), board[rx][ry].end());

            break;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; i++) 
        for (int j = 0; j < n; j++) {
            cin >> val[i][j]; // 최댓값 저장
            board[i][j].push_back(val[i][j]); // 숫자들 저장
            coord[val[i][j]] = make_pair(i, j); // 좌표 저장
        }
    
    for (int i = 0; i < m; i++) 
        cin >> num[i];
    
    for (int i = 0; i < m; i++) 
        simulate(num[i]);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (board[i][j].empty()) {
                cout << "None\n";
                continue;
            }
            for (int k = board[i][j].size() - 1; k >= 0; k--) 
                cout << board[i][j][k] << ' ';
            cout << '\n';
        }
    }
    return 0;
}