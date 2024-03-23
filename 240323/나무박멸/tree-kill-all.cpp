#include <iostream>
#include <queue>
#include <vector>
#include <tuple>

#define MAX_N 20
#define ROCK -1
#define DELETED -2

using namespace std;

int n, m, k, c, answer, board[MAX_N][MAX_N], year[MAX_N][MAX_N];

bool InRange(int x, int y) {
    return 0 <= x && x < n && 0 <= y && y < n;
}

tuple<int, int, int> DeletedTree(int cur_x, int cur_y) {
    int dx[] = {-1, 1, 1, -1};
    int dy[] = {1, 1, -1, -1};
    int x, y, val;
    val = board[cur_x][cur_y];
    
    for (int d = 0; d < 4; d++) {
        x = cur_x; y = cur_y;
        for (int dist = 1; dist <= k; dist++) {
            int nx = x + dx[d] * dist;
            int ny = y + dy[d] * dist;
            if (!InRange(nx, ny)) break;
            if (board[nx][ny] <= 0) break;
            val += board[nx][ny];
        }
    }

    return make_tuple(val, -cur_x, -cur_y);
}

tuple<int, int, int> FindMaximumPosition() {
    auto result = make_tuple(0, -100, -100);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (board[i][j] > 0) {
                auto val = DeletedTree(i, j);
                if (result < val)
                    result = val;
            }
        }
    }

    return result;
}

void Remove(tuple<int, int, int> result) {
    int val, cur_x, cur_y, x, y;
    tie(val, cur_x, cur_y) = result;
    cur_x = -cur_x; cur_y = -cur_y;
    board[cur_x][cur_y] = 0;
    year[cur_x][cur_y] = c;

    answer += val;

    int dx[] = {-1, 1, 1, -1};
    int dy[] = {1, 1, -1, -1};
    
    for (int d = 0; d < 4; d++) {
        x = cur_x; y = cur_y;
        for (int dist = 1; dist <= k; dist++) {
            int nx = x + dx[d] * dist;
            int ny = y + dy[d] * dist;
            if (!InRange(nx, ny)) break;
            board[nx][ny] = 0;
            year[nx][ny] = c;
            if (board[nx][ny] <= 0) continue;
        }
    }
}

void Delete() {
    auto result = FindMaximumPosition();
    int a, b, c;
    tie(a, b, c) = result;
    cout << a << ' ' << b << ' ' << c << endl;
    Remove(result);
}

void Copy() {
    int nxt_board[MAX_N][MAX_N];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            nxt_board[i][j] = board[i][j];
    
    int dx[] = {1, -1, 0, 0};
    int dy[] = {0, 0, 1, -1};

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (board[i][j] > 0) {
                int cnt = 0;
                for (int d = 0; d < 4; d++) {
                    int nx = i + dx[d];
                    int ny = j + dy[d];
                    if (!InRange(nx, ny)) continue;
                    if (year[nx][ny]) continue;
                    if (board[nx][ny] != 0) continue;
                    cnt++;
                }

                for (int d = 0; d < 4; d++) {
                    int nx = i + dx[d];
                    int ny = j + dy[d];
                    if (!InRange(nx, ny)) continue;
                    if (year[nx][ny]) continue;
                    if (board[nx][ny] != 0) continue;
                    nxt_board[nx][ny] += board[i][j] / cnt;
                }
            }
        }
    }

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            board[i][j] = nxt_board[i][j];
}

void Grow() {
    int nxt_board[MAX_N][MAX_N];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            nxt_board[i][j] = board[i][j];

    int dx[] = {1, -1, 0, 0};
    int dy[] = {0, 0, 1, -1};

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (board[i][j] > 0) {
                int cnt = 0;
                for (int d = 0; d < 4; d++) {
                    int nx = i + dx[d];
                    int ny = j + dy[d];
                    if (!InRange(nx, ny)) continue;
                    if (year[nx][ny]) continue;
                    if (board[nx][ny] > 0) cnt++;
                }
                nxt_board[i][j] = board[i][j] + cnt;
            }
        }
    }

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            board[i][j] = nxt_board[i][j];
}

void Update() {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (year[i][j] > 0)
                year[i][j]--;
}

void Print() {
    cout << "============\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) 
            cout << board[i][j] << ' ';
        cout << endl;
    }
}

void asdf() {
    cout << "============\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) 
            cout << year[i][j] << ' ';
        cout << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m >> k >> c;
    c++;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> board[i][j];
    
    while (m--) {
        Update();
        Grow();
        // Print();
        Copy();
        // Print();
        Delete();
        // asdf();
        // Print();
    }
    // Grow();
    // Copy();
    // Delete();
    // Print();
    cout << answer;
    return 0;
}