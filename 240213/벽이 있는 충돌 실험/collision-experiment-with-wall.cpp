#include <iostream>
#include <queue>

#define MAX_N 50

using namespace std;

int t, n, m, cnt[MAX_N][MAX_N], board[MAX_N][MAX_N];
// U R D L
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
int ascii_dir[128];
queue<int> dir[MAX_N][MAX_N];

bool in_range(int x, int y) {
    return 0 <= x && x < n && 0 <= y && y < n;
}

void move(int x, int y) {
    int d = dir[x][y].front(); dir[x][y].pop();
    int nx = x + dx[d];
    int ny = y + dy[d];
    if (!in_range(nx, ny)) { // 벽에 부딪힐 경우
        d = (d + 2) % 4;
        dir[x][y].push(d);
        cnt[x][y]++;
    }
    else {
        cnt[nx][ny]++;
        dir[nx][ny].push(d);
    }
}

void simulate() {
    for (int i = 0; i < n; i++) 
        for (int j = 0; j < n; j++) 
            cnt[i][j] = 0;

    // 구슬 이동
    for (int i = 0; i < n; i++) 
        for (int j = 0; j < n; j++) 
            if (board[i][j])
                move(i, j);

    for (int i = 0; i < n; i++) 
        for (int j = 0; j < n; j++) 
            board[i][j] = cnt[i][j];    
    
    // 겹쳐있으면 삭제
    for (int i = 0; i < n; i++) 
        for (int j = 0; j < n; j++) 
            if (board[i][j] >= 2) {
                board[i][j] = 0;
                while (!dir[i][j].empty()) dir[i][j].pop();
            }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ascii_dir['U'] = 0;
    ascii_dir['R'] = 1;
    ascii_dir['D'] = 2;
    ascii_dir['L'] = 3;

    cin >> t;

    while (t--) {
        cin >> n >> m;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++) {
                board[i][j] = cnt[i][j] = 0;
                while (!dir[i][j].empty()) dir[i][j].pop();
            }

        for (int i = 0; i < m; i++) {
            int x, y;
            char d;
            cin >> x >> y >> d;
            board[x - 1][y - 1]++; // 구슬 개수
            dir[x - 1][y - 1].push(ascii_dir[d]); // 구슬 방향 큐로 저장 (먼저 들어온 구슬이 먼저 나감)
        }
        
        int limit = 2 * n; // 2번 이동하면 안만나는지 확인 가능
        while (limit--) {
            // for (int i = 0; i < n; i++) {
            //     for (int j = 0; j < n; j++)
            //         cout << board[i][j] << ' ';
            //     cout << endl;
            // }
            simulate();
        }

        int answer = 0;
        for (int i = 0; i < n; i++) 
            for (int j = 0; j < n; j++)
                if (board[i][j])
                    answer++;

        cout << answer << '\n';
    }
    return 0;
}