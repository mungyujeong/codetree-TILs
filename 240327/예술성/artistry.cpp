#include <iostream>
#include <queue>
#include <tuple>
#include <vector>

#define MAX_N 29

using namespace std;

int n, board[MAX_N][MAX_N], len[MAX_N * MAX_N][MAX_N * MAX_N], group[MAX_N][MAX_N], answer, group_cnt[MAX_N * MAX_N], group_val[MAX_N * MAX_N];
int nxt_board[MAX_N][MAX_N];
bool visited[MAX_N][MAX_N];
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

void Init() {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            group[i][j] = -1;
            visited[i][j] = false;
            nxt_board[i][j] = 0;
        }
    
    for (int i = 0; i < MAX_N * MAX_N; i++) {
        group_cnt[i] = 0;
        group_val[i] = 0;
    }

    for (int i = 0; i < MAX_N * MAX_N; i++) {
        for (int j = 0; j < MAX_N * MAX_N; j++)
            len[i][j] = 0;
    }
}

bool InRange(int x, int y) {
    return 0 <= x && x < n && 0 <= y && y < n;
}

void BFS(int x, int y, int idx) {
    queue<pair<int, int>> Q;

    Q.push({x, y});
    int val = board[x][y];
    group[x][y] = idx;

    while (!Q.empty()) {
        tie(x, y) = Q.front(); Q.pop();
        for (int d = 0; d < 4; d++) {
            int nx = x + dx[d];
            int ny = y + dy[d];
            if (!InRange(nx, ny)) continue;
            if (group[nx][ny] != -1) continue;
            if (board[nx][ny] != val) continue;
            group[nx][ny] = idx;
            Q.push({nx, ny});
        }
    }
}

int Grouping() {
    Init();

    int idx = 1;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (group[i][j] == -1) 
                BFS(i, j, idx++);
    
    return idx;
}

void GetScore(int x, int y, int gidx) {
    queue<pair<int, int>> Q;
    
    int cnt = 1;
    int val = board[x][y];
    group_val[gidx] = val;
    Q.push({x, y});
    visited[x][y] = true;

    while (!Q.empty()) {
        tie(x, y) = Q.front(); Q.pop();
        for (int d = 0; d < 4; d++) {
            int nx = x + dx[d];
            int ny = y + dy[d];
            if (!InRange(nx, ny)) continue;
            if (visited[nx][ny]) continue;
            if (group[nx][ny] != gidx) {
                len[gidx][group[nx][ny]]++;
            }
            else {
                cnt++;
                Q.push({nx, ny});
                visited[nx][ny] = true;
            }
        }
    }

    group_cnt[gidx] = cnt;
}

void Scoring(int idx) {
    bool group_visited[MAX_N * MAX_N] = {};
    
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            if (group_visited[group[i][j]]) continue;
            GetScore(i, j, group[i][j]);
            group_visited[group[i][j]] = true;
        }
    
    for (int i = 1; i <= idx; i++)
        for (int j = i; j <= idx; j++)
            if (len[i][j])
                answer += (group_cnt[i] + group_cnt[j]) * group_val[i] * group_val[j] * len[i][j];
}

void CounterClock(int idx) {
    int tmp[MAX_N][MAX_N];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            tmp[i][j] = board[i][j];
    
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            nxt_board[n - 1 - j][i] = tmp[i][j];
}

void Clock(int x, int y, int idx) {
    vector<vector<int>> tmp(idx, vector<int>(idx));
    for (int i = x; i < x + idx; i++)
        for (int j = y; j < y + idx; j++)
            tmp[i - x][j - y] = board[i][j];
    
    for (int i = 0; i < idx; i++)
        for (int j = 0; j < idx; j++)
            nxt_board[j + x][idx - 1 - i + y] = tmp[i][j];
}

void Rotate() {
    int idx = n / 2;
    CounterClock(idx);

    Clock(0, 0, idx);
    Clock(idx + 1, 0, idx);
    Clock(0, idx + 1, idx);
    Clock(idx + 1, idx + 1, idx);

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            board[i][j] = nxt_board[i][j];
}

void Print(int idx) {
    cout << "===========\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            cout << board[i][j] << ' ';
        cout << endl;
    }

    for (int i = 1; i <= idx; i++) {
        for (int j = i + 1; j <= idx; j++)
            cout << len[i][j] << ' ';
        cout << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> board[i][j];
    
    int idx = Grouping();
    Scoring(idx - 1);
    // Rotate();
    // Print(idx - 1);
    for (int i = 0; i < 3; i++) {
        Rotate();
        idx = Grouping();
        Scoring(idx - 1);
    }

    cout << answer;
    return 0;
}