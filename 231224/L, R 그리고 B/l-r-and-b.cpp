#include <iostream>
#include <queue>
#include <tuple>

using namespace std;

int grid[10][10];
bool visited[10][10];
int sx, sy, ex, ey, x, y;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
queue<pair<int, int>> q;

bool InRange(int x, int y) {
    return 0 <= x && x < 10 && 0 <= y && y < 10;
}

bool IsVisited(int x, int y) {
    return visited[x][y];
}

int main() {
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            char x;
            cin >> x;
            if (x == '.') grid[i][j] = 0;
            else if (x == 'L') {
                sx = i;
                sy = j;
            } else if (x == 'B') {
                ex = i;
                ey = j;
            } else grid[i][j] = -1;
        }
    }

    q.push({sx, sy});
    while(!q.empty()) {
        tie(x, y) = q.front();
        visited[x][y] = true;
        q.pop();
        // cout << x << " " << y << endl;
        for (int d = 0; d < 4; d++) {
            int nx = x + dx[d];
            int ny = y + dy[d];
            // cout << nx << " " << ny << endl;
            if (!InRange(nx, ny)) continue;
            if (!IsVisited(nx, ny) && grid[nx][ny] != -1) {
                q.push({nx, ny});
                grid[nx][ny] = grid[x][y] + 1;
                visited[nx][ny] = true;
            }
        }

    }

        // for (int i = 0; i < 10; i++) {
        //     for (int j = 0; j < 10; j++) {
        //         cout << grid[i][j] << " ";
        //     }
        //     cout << endl;
        // }
    cout << grid[ex][ey] - 1;

    return 0;
}