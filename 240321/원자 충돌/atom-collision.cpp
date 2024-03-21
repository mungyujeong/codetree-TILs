#include <iostream>
#include <vector>
#include <tuple>

#define MAX_N 50

using namespace std;

int n, m, k, answer;
vector<tuple<int, int, int>> board[MAX_N][MAX_N], nxt_board[MAX_N][MAX_N];
int dx[] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dy[] = {0, 1, 1, 1, 0, -1, -1, -1};

void Initialize() {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            nxt_board[i][j].clear();
}

void Move(int x, int y) {
    for (auto e : board[x][y]) {
        int mass, s, d;
        tie(mass, s, d) = e;
        int move_times = s % n;
        int nx = x + dx[d] * move_times;
        int ny = y + dy[d] * move_times;

        if (nx >= n) nx -= n;
        if (ny >= n) ny -= n;
        if (nx < 0) nx += n;
        if (ny < 0) ny += n;

        nxt_board[nx][ny].push_back({mass, s, d});
    }    
}

void Plus(int x, int y) {
    vector<tuple<int, int, int>> tmp = board[x][y];
    int total_mass = 0;
    int total_speed = 0;
    bool is_cross = false;
    
    for (auto atom : tmp) {
        int mass, s, d;
        tie(mass, s, d) = atom;
        total_mass += mass;
        total_speed += s;
        if (d % 2 == 1) is_cross = true;
    }

    board[x][y].clear();

    total_mass /= 5;
    total_speed /= (int)tmp.size();

    if (total_mass == 0) return;

    if (!is_cross) 
        for (int nd = 0; nd < 8; nd += 2)
            board[x][y].push_back({total_mass, total_speed, nd});
    else 
        for (int nd = 1; nd < 8; nd += 2)
            board[x][y].push_back({total_mass, total_speed, nd});
}

void Print() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            // if (board[i][j].empty()) continue;
            for (auto atom : board[i][j]) {
                int a, b, c;
                tie(a, b, c) = atom;
                cout << "(" << i << ' ' << j << ' ' << a << ' ' << b << ' ' << c << ")";
            }
            cout << "||";
        }
        cout << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m >> k;
    for (int i = 0; i < m; i++) {
        int x, y, mass, s, d;
        cin >> x >> y >> mass >> s >> d;
        board[x - 1][y - 1].push_back({mass, s, d});
    }

    while (k--) {
        Initialize();
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (!board[i][j].empty()) 
                    Move(i, j);

        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                board[i][j] = nxt_board[i][j];

        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (board[i][j].size() > 1) 
                    Plus(i, j);
        // Print();
    }

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (!board[i][j].empty())
                for (auto atom : board[i][j]) {
                    int mass;
                    tie(mass, ignore, ignore) = atom;
                    answer += mass;
                }
                    
    cout << answer;
    return 0;
}