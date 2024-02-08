#include <iostream>
#include <queue>
#include <vector>
#include <tuple>

#define MAX_N 101

using namespace std;

int n, m, k, board[MAX_N][MAX_N], answer, apple[MAX_N][MAX_N];
queue<pair<int, int>> Q;
vector<pair<char, int>> com;
// U D R L
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, 1, -1};
int ascii_dir[128];

bool in_range(int x, int y) {
    return 1 <= x && x <= n && 1 <= y && y <= n;
}

void simulate() {
    int x, y, p, qx, qy;
    char d;
    Q.push({1, 1});
    board[1][1] = 1;
    x = y = 1; // 현재 위치

    // p 만큼 이동
    for (auto i : com) {
        tie(d, p) = i;
        while (p--) {
            answer++;
            x += dx[ascii_dir[d]];
            y += dy[ascii_dir[d]];
            if (!in_range(x, y)) return; 
            if (!apple[x][y]) {
                tie(qx, qy) = Q.front();
                Q.pop();
                board[qx][qy] = 0;
            }
            if (board[x][y]) return;
            apple[x][y] = 0;
            board[x][y] = 1;
            Q.push({x, y});
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ascii_dir['U'] = 0;
    ascii_dir['D'] = 1;
    ascii_dir['R'] = 2;
    ascii_dir['L'] = 3;

    cin >> n >> m >> k;
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        apple[x][y] = 1; // 사과 위치    
    }

    for (int i = 0; i < k; i++) {
        char d;
        int p;
        cin >> d >> p;
        com.push_back({d, p});
    }

    simulate();

    cout << answer;
    return 0;
}