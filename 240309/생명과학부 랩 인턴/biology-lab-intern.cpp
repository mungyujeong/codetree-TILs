#include <iostream>
#include <tuple>
#include <vector>

#define MAX_N 100

using namespace std;

int n, m, k, x, y, s, d, b, answer;
tuple<int, int, int> board[MAX_N][MAX_N];
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, 1, -1};

bool in_range(int x, int y) {
    return 0 <= x && x < n && 0 <= y && y < m;
}

void get_mold(int pos) {
    int size;
    for (int i = 0; i < n; i++) {
        tie(ignore, ignore, size) = board[i][pos];
        if (size == 0) continue;
        answer += size;
        board[i][pos] = {};
        return;
    }
}

void move_mold() {
    int speed, dir, size, move_time;
    vector<tuple<int, int, int>> nxt_mold[MAX_N][MAX_N];
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            tie(speed, dir, size) = board[i][j];
            if (size == 0) continue;
            board[i][j] = {};
            x = i; y = j;

            if (dir == 0 || dir == 1) {
                move_time = speed % (2 * (n - 1));
                while (move_time--) {
                    x += dx[dir];
                    y += dy[dir];
                    if (!in_range(x, y)) {
                        dir == 0 ? dir = 1 : dir = 0;
                        x += dx[dir] * 2;
                        y += dy[dir] * 2;
                    }
                }
            }
            else {
                move_time = speed % (2 * (m - 1));
                while (move_time--) {
                    x += dx[dir];
                    y += dy[dir];
                    if (!in_range(x, y)) {
                        dir == 2 ? dir = 3 : dir = 2;
                        x += dx[dir] * 2;
                        y += dy[dir] * 2;
                    }
                }
            }

            nxt_mold[x][y].push_back({speed, dir, size});
            // if (b < size) nxt_mold[x][y] = make_tuple(speed, dir, size);
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (nxt_mold[i][j].size() == 0) continue;
            int max_size = 0;
            for (int t = 0; t < nxt_mold[i][j].size(); t++) {
                tie (speed, dir, size) = nxt_mold[i][j][t];
                if (max_size < size) {
                    max_size = size;
                    board[i][j] = nxt_mold[i][j][t];
                }
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m >> k;
    for (int i = 0; i < k; i++) {
        cin >> x >> y >> s >> d >> b;
        board[x - 1][y - 1] = make_tuple(s, d - 1, b);
    }

    for (int pos = 0; pos < m; pos++) {
        get_mold(pos);
        move_mold();
    }

    cout << answer;
    return 0;
}