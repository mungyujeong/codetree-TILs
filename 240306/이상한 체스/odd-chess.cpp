#include <iostream>
#include <vector>
#include <tuple>

#define MAX_N 8

using namespace std;

int n, m, board[MAX_N][MAX_N], grid[MAX_N][MAX_N], chess, answer = 100;
vector<tuple<int, int, int>> v;
// 상 하 좌 우
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
vector<vector<vector<int>>> dir = {
    {{0}, {1}, {2}, {3}},
    {{0, 1}, {2, 3}},
    {{0, 3}, {1, 3}, {1, 2}, {0, 2}},
    {{0, 2, 3}, {0, 1, 3}, {1, 2, 3}, {0, 1, 2}},
    {{0, 1, 2, 3}}
};

bool in_range(int x, int y) {
    return 0 <= x && x < n && 0 <= y && y < m;
}

void move(int x, int y, int d) {
    grid[x][y] = 1;
    int nx, ny;
    nx = x; ny = y;
    while (true) {
        nx += dx[d];
        ny += dy[d];
        if (!in_range(nx, ny) || board[nx][ny] == 6) break;

        grid[nx][ny] = 1;
    }
}

void backtracking(int depth) {
    if (depth == chess) {
        int cnt = 0;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (grid[i][j] == 0)
                    cnt++;
        
        answer = min(answer, cnt);
        return;
    }

    int backup[MAX_N][MAX_N];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            backup[i][j] = grid[i][j];
    
    int x, y, val;
    tie(x, y, val) = v[depth];
    for (auto d : dir[val - 1]) {
        for (auto g : d) 
            move(x, y, g);

        backtracking(depth + 1);
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                grid[i][j] = backup[i][j];
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> board[i][j];
            if (board[i][j] == 6) grid[i][j] = 1;
            else if (board[i][j] != 0) {
                v.push_back({i, j, board[i][j]});
                chess++;
            }
        }
    }

    backtracking(0);

    cout << answer;
    return 0;
}