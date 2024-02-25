#include <iostream>
#include <queue>
#include <tuple>

#define MAX_N 50

using namespace std;

int n, m, board[MAX_N][MAX_N];
// 북 동 남 서
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

bool in_range(int x, int y) {
    return 0 <= x && x < n && 0 <= y && y < m;
}

int simulate(int x, int y, int d) {
    int answer = 1;
    queue<tuple<int, int, int>> Q;
    bool visited[MAX_N][MAX_N] = {};

    Q.push({x, y, d});
    visited[x][y] = true;

    while (!Q.empty()) {
        tie(x, y, d) = Q.front(); Q.pop();
        int cnt = 0;
        int nd = d;
        bool moved = false;
        while (cnt < 4) {
            cnt++;
            nd = (nd + 3) % 4;
            int nx = x + dx[nd];
            int ny = y + dy[nd];
            if (board[nx][ny] == 1) continue;
            if (visited[nx][ny]) continue;
            
            answer++;
            visited[nx][ny] = true;
            Q.push({nx, ny, nd});
            moved = true;
            break;
        }
        
        // 모두 돌았는데 인도이거나 방문한 곳일 경우
        // 1칸 후진
        if (!moved) {
            int nx = x - dx[d];
            int ny = y - dy[d];
            if (board[nx][ny] == 1) break;
            Q.push({nx, ny, d});
        }
    }

    return answer;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    int x, y, d;
    cin >> x >> y >> d;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> board[i][j];
    
    cout << simulate(x, y, d);

    return 0;
}