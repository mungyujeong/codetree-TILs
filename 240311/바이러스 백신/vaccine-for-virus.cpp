#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <tuple>
#include <climits>

#define MAX_N 50

using namespace std;

int n, m, board[MAX_N][MAX_N], visited[MAX_N][MAX_N], answer = INT_MAX;
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
vector<pair<int, int>> hospital, virus;

bool in_range(int x, int y) {
    return 0 <= x && x < n && 0 <= y && y < n;
}

bool check() {
    int max_val = 0;
    int x, y;
    for (auto p : virus) {
        tie (x, y) = p;
        if (visited[x][y] == INT_MAX) return false;
        max_val = max(max_val, visited[x][y]);
    }
    answer = min(answer, max_val);
    return true;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> board[i][j];
            if (board[i][j] == 1) board[i][j] = -1;
            else if (board[i][j] == 2) {
                hospital.push_back({i, j});
                board[i][j] = INT_MAX;
            }
            else {
                virus.push_back({i, j});
                board[i][j] = INT_MAX;
            }
        }
    }

    vector<int> comb(hospital.size(), 0);
    fill(comb.end() - m, comb.end(), 1);
    do {
        int x, y;
        queue<pair<int, int>> Q;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                visited[i][j] = board[i][j];

        for (int i = 0; i < comb.size(); i++)
            if (comb[i]) {
                // cout << i << ' ';
                tie(x, y) = hospital[i];
                Q.push(hospital[i]);
                visited[x][y] = 1;
            }
        // cout << endl;
        
        while (!Q.empty()) {
            tie(x, y) = Q.front(); Q.pop();
            for (int d = 0; d < 4; d++) {
                int nx = x + dx[d];
                int ny = y + dy[d];
                if (!in_range(nx, ny)) continue;
                if (visited[nx][ny] == -1) continue;
                if (visited[nx][ny] <= visited[x][y] + 1) continue;
                visited[nx][ny] = visited[x][y] + 1;
                Q.push({nx, ny});
            }
        }

        check(); 

    } while (next_permutation(comb.begin(), comb.end()));

    if (answer == INT_MAX) cout << -1;
    else if (answer == 0) cout << 0;
    else cout << answer - 1;

    return 0;
}