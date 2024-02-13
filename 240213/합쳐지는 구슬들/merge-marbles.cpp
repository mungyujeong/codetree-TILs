#include <iostream>
#include <vector>
#include <tuple>

#define MAX_N 50

using namespace std;

int n, m, t, answer, weight, ascii_dir[128];
// U R D L
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
vector<tuple<int, int, int>> board[MAX_N][MAX_N];
vector<tuple<int, int, int>> nxt_board[MAX_N][MAX_N];

bool in_range(int x, int y) {
    return 0 <= x && x < n && 0 <= y && y < n;
}

void move(int x, int y) {
    for (auto i : board[x][y]) {
        int dir, w, num;
        tie(dir, w, num) = i;
        
        int nx = x + dx[dir];
        int ny = y + dy[dir];
        if (!in_range(nx, ny)) {
            dir = (dir + 2) % 4;
            nxt_board[x][y].push_back({dir, w, num});
        }
        else {
            nxt_board[nx][ny].push_back({dir, w, num});
        }
    }
}

void Sum(int x, int y) {
    int max_dir, sum_w, max_num;
    max_dir = sum_w = max_num = 0;
    for (auto i : nxt_board[x][y]) {
        int dir, w, num;
        tie(dir, w, num) = i;
        sum_w += w;
        if (max_num < num) {
            max_dir = dir;
            max_num = num;
        }
    } 
    nxt_board[x][y].clear();
    nxt_board[x][y].push_back({max_dir, sum_w, max_num});
}

void simulate() {
    for (int i = 0; i < n; i++)     
        for (int j = 0; j < n; j++)
            nxt_board[i][j].clear();

    // 이동
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (board[i][j].empty()) continue;
            move(i, j);
        }
    }

    // 합치기
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (nxt_board[i][j].empty()) continue;
            if (nxt_board[i][j].size() < 2) continue;
            Sum(i, j);
        }
    }

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            board[i][j] = nxt_board[i][j];
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ascii_dir['U'] = 0;
    ascii_dir['R'] = 1;
    ascii_dir['D'] = 2;
    ascii_dir['L'] = 3;

    cin >> n >> m >> t;
    for (int i = 0; i < m; i++) {
        int r, c, w; char d;
        cin >> r >> c >> d >> w;
        board[r - 1][c - 1].push_back({ascii_dir[d], w, i + 1});
    }

    while (t--) {
        simulate();
    }

    for (int i = 0; i < n; i++) 
        for (int j = 0; j < n; j++) {
            answer += board[i][j].size();
            for (auto k : board[i][j]) {
                int w;
                tie (ignore, w, ignore) = k;
                weight = max(weight, w);
            }
        }
    
    cout << answer << ' ' << weight;
    
    return 0;
}