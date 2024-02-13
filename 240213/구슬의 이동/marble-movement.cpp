#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>

#define MAX_N 50

using namespace std;

int n, m, t, k, answer;
int ascii_dir[128];
// U L D R
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, -1, 0, 1};
vector<tuple<int, int, int>> board[MAX_N][MAX_N];
vector<tuple<int, int, int>> nxt_board[MAX_N][MAX_N];

bool in_range(int x, int y) {
    return 0 <= x && x < n && 0 <= y && y < n;
}

void move(int x, int y) {
    for (auto i : board[x][y]) {
        int spd, num, dir, nx, ny;
        tie(spd, num, dir) = i;
        nx = x; ny = y;
        // spd 만큼 이동
        for (int j = 0; j < spd; j++) {
            if (!in_range(nx + dx[dir], ny + dy[dir])) {
                dir = (dir + 2) % 4;
            }
            nx += dx[dir];
            ny += dy[dir];
        }

        nxt_board[nx][ny].push_back({spd, num, dir});
    }
}

void simulate() {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            nxt_board[i][j].clear();

    // (i, j)에 있는 구슬들 이동
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            if (board[i][j].empty()) continue;
            move(i, j);
        }

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            board[i][j] = nxt_board[i][j];

    // k보다 많으면 v값 정렬 후 삭제
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (board[i][j].size() > k) {
                // 내림차순 정렬
                sort(board[i][j].begin(), board[i][j].end(), greater<tuple<int, int, int>>());
                while (board[i][j].size() != k) {
                    board[i][j].pop_back();
                }
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ascii_dir['U'] = 0;
    ascii_dir['L'] = 1;
    ascii_dir['D'] = 2;
    ascii_dir['R'] = 3;

    cin >> n >> m >> t >> k;
    for (int i = 0; i < m; i++) {
        int r, c, v; char d;
        cin >> r >> c >> d >> v;
        board[r - 1][c - 1].push_back({v, i + 1, ascii_dir[d]});
    }

    while (t--) {
        simulate();
    }

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) 
            answer += board[i][j].size();
    
    cout << answer;

    return 0;
}