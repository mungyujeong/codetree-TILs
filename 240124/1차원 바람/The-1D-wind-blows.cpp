#include <iostream>
#include <queue>
#include <vector>
#include <tuple>

#define MAX_N 100

using namespace std;

int n, m, Q, r;
char d;
int board[MAX_N][MAX_N];
vector<pair<int, int>> v;

void wind(int row, int dir) { 

    int tmp;
    // left
    if (dir == 1) {
        tmp = board[row][m - 1];

        for (int i = m - 1; i >= 1; i--)
            board[row][i] = board[row][i - 1];
        board[row][0] = tmp;
    }
    // right
    else {
        tmp = board[row][0];
        for (int i = 0; i < m; i++)
            board[row][i] = board[row][i + 1];
        board[row][m - 1] = tmp;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m >> Q;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> board[i][j];
    
    for (int i = 0; i < Q; i++) {
        cin >> r >> d;
        if (d == 'L') v.push_back({r - 1, 1});
        else v.push_back({r - 1, -1});
    }

    for (int i = 0; i < v.size(); i++) {
        queue<pair<int, char>> q;
        q.push(v[i]);
        int visited[MAX_N] = {};

        while (!q.empty()) {
            tie(r, d) = q.front(); q.pop();
            visited[r] = 1;
            wind(r, d);
            for (auto i : {r - 1, r + 1}) {
                if (visited[i]) continue;
                if (i < 0 || i >= n) continue;

                bool possible = false;
                for (int j = 0; j < m; j++) 
                    if (board[i][j] == board[r][j]) 
                        possible = true;
                    
                if (possible)
                    q.push({i, -d});
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            cout << board[i][j] << ' ';
        cout << endl;
    }
}