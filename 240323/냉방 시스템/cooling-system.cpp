#include <iostream>
#include <vector>
#include <tuple>
#include <queue>

#define MAX_N 20
#define INVALID make_tuple(-1, -1, -1, -1)

using namespace std;

int n, m, k, board[MAX_N][MAX_N], minute;
bool wall[MAX_N][MAX_N][MAX_N][MAX_N];
bool visited[MAX_N][MAX_N];
vector<pair<int, int>> office;
vector<tuple<int, int, int>> air;
int dx[] = {0, -1, 0, 1};
int dy[] = {-1, 0, 1, 0};

bool InRange(int x, int y) {
    return 0 <= x && x < n && 0 <= y && y < n;
}

bool CanGo(int x, int y, int nx, int ny) {
    return InRange(nx, ny) && !visited[nx][ny] && !wall[x][y][nx][ny];
}

tuple<int, int, int, int> Front(int x, int y, int d, int val) {
    int nx = x + dx[d];
    int ny = y + dy[d];
    if (CanGo(x, y, nx, ny)) {
        visited[nx][ny] = true;
        board[nx][ny] += val;
        return make_tuple(nx, ny, d, val - 1);
    }

    return INVALID;
}

tuple<int, int, int, int> Cross(int x, int y, int d, int nd, int val) {
    int nx = x + dx[nd];
    int ny = y + dy[nd];
    if (CanGo(x, y, nx, ny)) {
        auto front = Front(nx, ny, d, val);
        if ((front != INVALID)) return front;
    }

    return INVALID;
}

void Wind(int x, int y, int d) {
    int nx, ny;
    int val = 5;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            visited[i][j] = false;

    queue<tuple<int, int, int, int>> Q;
    board[x][y] += val--;

    Q.push({x, y, d, val});
    visited[x][y] = true;
    
    while (!Q.empty()) {
        tie(x, y, d, val) = Q.front(); Q.pop();
        if (val == 0) continue;

        // 정방향
        auto front = Front(x, y, d, val);
        if ((front != INVALID))
            Q.push(front);
            
        // 대각선1
        auto cross = Cross(x, y, d, (d + 1) % 4, val);
        if ((cross != INVALID))
            Q.push(cross);

        // 대각선2
        cross = Cross(x, y, d, (d + 3) % 4, val);
        if ((cross != INVALID))
            Q.push(cross);
    }
}

void Propagation() {
    int x, y, d;
    for (auto a : air) {
        tie(x, y, d) = a;
        Wind(x + dx[d], y + dy[d], d);
    }
}

void Mix() {
    int nxt_board[MAX_N][MAX_N];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            nxt_board[i][j] = board[i][j];
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int cur = board[i][j];
            for (int d = 0; d < 4; d++) {
                int nx = i + dx[d];
                int ny = j + dy[d];
                if (!InRange(nx, ny)) continue;
                if (wall[i][j][nx][ny]) continue; // 벽이 있으면 pass
                if (cur > board[nx][ny]) {
                    int diff = (cur - board[nx][ny]) / 4;
                    nxt_board[i][j] -= diff;
                    nxt_board[nx][ny] += diff;
                }
            }
        }
    }

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            board[i][j] = nxt_board[i][j];
}

void Decrease() {
    int x, y;
    x = y = n - 1;
    for (int d = 0; d < 4; d++) {
        while (true) {
            int nx = x + dx[d];
            int ny = y + dy[d];
            if (!InRange(nx, ny)) break;
            if (board[nx][ny] > 0) board[nx][ny]--;
            x = nx; y = ny;
        }
    }
}

bool Check() {
    int x, y;
    for (auto i : office) {
        tie(x, y) = i;
        if (board[x][y] < k) return true;
    }
    return false;
}

void Print() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            cout << board[i][j] << ' ';
        cout << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m >> k;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int x;
            cin >> x;
            if (x == 1) office.push_back({i, j});
            else if (x > 1) air.push_back({i, j, x - 2});
        }
    }

    for (int i = 0; i < m; i++) {
        int x, y, s, nx, ny;
        cin >> x >> y >> s;
        x--; y--;
        if (s == 0) {
            nx = x + dx[1];
            ny = y + dy[1];
        }
        else if (s == 1) {
            nx = x + dx[0];
            ny = y + dy[0];
        }
        wall[x][y][nx][ny] = true;
        wall[nx][ny][x][y] = true;
    }

    while (Check() && minute <= 100) {
        Propagation();
        Mix();
        Decrease();
        minute++;
    }
    // Propagation();
    // Print();

    if (minute > 100) cout << -1;
    else cout << minute;

    return 0;
}