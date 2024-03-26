#include <iostream>
#include <vector>
#include <tuple>

#define MAX_N 99

using namespace std;

int n, m, h, k, t, answer, cur_x, cur_y, cur_d;
vector<int> runner[MAX_N][MAX_N], nxt_runner[MAX_N][MAX_N];
int dir[MAX_N][MAX_N];
int rev_dir[MAX_N][MAX_N];
bool tree[MAX_N][MAX_N];
bool is_front = true;
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

bool InRange(int x, int y) {
    return 0 <= x && x < n && 0 <= y && y < n;
}

int Dist(int x, int y, int tx, int ty) {
    return abs(x - tx) + abs(y - ty);
}

void Move() {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            nxt_runner[i][j].clear();

    for (int x = 0; x < n; x++) {
        for (int y = 0; y < n; y++) {
            if (runner[x][y].empty()) continue;
            if (Dist(x, y, cur_x, cur_y) > 3) continue;
            for (auto d : runner[x][y]) {
                int nx = x + dx[d];
                int ny = y + dy[d];
                if (!InRange(nx, ny)) {
                    d = (d + 2) % 4;
                    nx = x + dx[d];
                    ny = y + dy[d];
                }

                if (nx == cur_x && ny == cur_y)
                    nxt_runner[x][y].push_back(d);
                else 
                    nxt_runner[nx][ny].push_back(d);
            }
        }
    }

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            runner[i][j] = nxt_runner[i][j];
}

void Catch() {
    int cnt = 0;

    if (is_front)
        cur_d = dir[cur_x][cur_y];
    else
        cur_d = rev_dir[cur_x][cur_y];

    cur_x += dx[cur_d];
    cur_y += dy[cur_d];
    
    if (cur_x == 0 && cur_y == 0)
        is_front = false;

    for (int i = 0; i < 3; i++) {
        int nx = cur_x + dx[cur_d] * i;
        int ny = cur_y + dy[cur_d] * i;
        if (!InRange(nx, ny)) continue;
        if (tree[nx][ny]) continue;
        if (runner[nx][ny].empty()) continue;

        cnt += runner[nx][ny].size();
        runner[nx][ny].clear();
    }

    answer += cnt * t;
}

void Init() {
    int d = 0; 
    int dist = 1;
    int x, y;
    x = cur_x; y = cur_y;

    while (x || y) {
        for (int i = 0; i < dist; i++) {
            dir[x][y] = d;
            x += dx[d]; y += dy[d];
            rev_dir[x][y] = (d < 2) ? (d + 2) : (d - 2);

            if (!x && !y) break;
        }

        d = (d + 1) % 4;
        if (d % 2 == 0) dist++;
    }
}

void Print() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) 
            cout << dir[i][j] << ' ';
        cout << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m >> h >> k;
    cur_x = cur_y = n / 2;
    cur_d = 0;
    for (int i = 0; i < m; i++) {
        int x, y, d;
        cin >> x >> y >> d;
        runner[x - 1][y - 1].push_back(d);
    }
    for (int i = 0; i < h; i++) {
        int x, y;
        cin >> x >> y;
        tree[x - 1][y - 1] = true;
    }

    Init();

    while (k--) {
        t++;
        Move();
        Catch();
    }

    // Move();
    // Catch();

    // Print();
    cout << answer;
    return 0;
}