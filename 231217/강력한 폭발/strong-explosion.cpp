#include <iostream>
#include <climits>
#include <vector>

#define MAX_N 20

using  namespace std;

int n, answer = INT_MIN;
int bomb_size;
int count;
int grid[MAX_N][MAX_N];

vector<pair<int, int>> bomb;

bool InRange(int x, int y) {
    return 0 <= x && x < n && 0 <= y && y < n;
}

void SelectSpace(int bomb_type, int x, int y) {
    if (bomb_type == 0) {
        int dx[4] = {1, 2, -1, -2};
        int dy[4] = {0, 0, 0, 0};
        for (int d = 0; d < 4; d++) {
            int nx = x + dx[d];
            int ny = y + dy[d];
            if (InRange(nx, ny)) {
                grid[nx][ny] = 1;
            }
        }
    } else if (bomb_type == 1) {
        int dx[4] = {1, -1, 0, 0};
        int dy[4] = {0, 0, 1, -1};
        for (int d = 0; d < 4; d++) {
            int nx = x + dx[d];
            int ny = y + dy[d];
            if (InRange(nx, ny)) {
                grid[nx][ny] = 1;
            }
        }
    } else {
        int dx[4] = {1, 1, -1, -1};
        int dy[4] = {1, -1, 1, -1};
        for (int d = 0; d < 4; d++) {
            int nx = x + dx[d];
            int ny = y + dy[d];
            if (InRange(nx, ny)) {
                grid[nx][ny] = 1;
            }
        }
    }
    return;
}

int GetCount() {
    int cnt = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (grid[i][j] == 1)
                cnt++;
    return cnt;
}

void GetSpace(int depth) {
    if (depth == bomb_size) {
        count = GetCount();
        answer = max(answer, count);
        return;
    }

    int bx = bomb[depth].first;
    int by = bomb[depth].second;

    for (int bomb_type = 0; bomb_type < 3; bomb_type++) {

        // tmp <= grid copy
        int tmp[MAX_N][MAX_N];
        for (int i = 0; i < MAX_N; i++)
            for (int j = 0; j < MAX_N; j++)
                tmp[i][j] = grid[i][j];

        SelectSpace(bomb_type, bx, by);
        GetSpace(depth + 1);

        // grid 원상복귀
        for (int i = 0; i < MAX_N; i++)
            for (int j = 0; j < MAX_N; j++)
                grid[i][j] = tmp[i][j];
    }
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
            if (grid[i][j] == 1) 
                bomb.push_back({i, j});
        }
    bomb_size = bomb.size();
    GetSpace(0);

    cout << answer;
    
    return 0;
}