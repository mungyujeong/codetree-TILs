#include <iostream>
#include <vector>
#include <tuple>

#define MAX_N 4

using namespace std;

int m, t, px, py, dead[MAX_N][MAX_N];
vector<int> board[MAX_N][MAX_N], nxt_board[MAX_N][MAX_N], tmp[MAX_N][MAX_N];

void Egg() {
    for (int i = 0; i < MAX_N; i++)
        for (int j = 0; j < MAX_N; j++)
            nxt_board[i][j].clear();

    for (int i = 0; i < MAX_N; i++)
        for (int j = 0; j < MAX_N; j++)
            if (!board[i][j].empty())
                for (auto d : board[i][j])
                    nxt_board[i][j].push_back(d);
}

bool InRange(int x, int y) {
    return 0 <= x && x < MAX_N && 0 <= y && y < MAX_N;
}

void Move(int x, int y, int d) {
    int dx[] = {-1, -1, 0, 1, 1, 1, 0, -1};
    int dy[] = {0, -1, -1, -1, 0, 1, 1, 1};

    int od = d;

    while (true) {
        int nx = x + dx[d];
        int ny = y + dy[d];
        if (!InRange(nx, ny) || dead[nx][ny] || (nx == px && ny == py)) {
            d = (d + 1) % 8;
        }
        else {
            tmp[nx][ny].push_back(d);
            break;
        }

        if (od == d) {
            tmp[x][y].push_back(od);
            break;
        }
    }
}

void MonsterMove() {
    for (int i = 0; i < MAX_N; i++)
        for (int j = 0; j < MAX_N; j++)
            tmp[i][j].clear();

    for (int i = 0; i < MAX_N; i++)
        for (int j = 0; j < MAX_N; j++)
            if (!board[i][j].empty()) {
                for (auto d : board[i][j])
                    Move(i, j, d);
            }
    
    for (int i = 0; i < MAX_N; i++)
        for (int j = 0; j < MAX_N; j++)
            board[i][j] = tmp[i][j];
}

int Eat(vector<int> dir) {
    // 상 좌 하 우
    int dx[] = {-1, 0, 1, 0};
    int dy[] = {0, -1, 0, 1};
    bool visited[MAX_N][MAX_N] = {};
    
    int x = px, y = py;
    int cnt = 0;
    for (auto d : dir) {
        x += dx[d];
        y += dy[d];
        if (!InRange(x, y)) {
            x -= dx[d];
            y -= dy[d];
            continue;
        }
        if (visited[x][y]) continue;
        cnt += board[x][y].size();
        visited[x][y] = true;
    }

    return cnt;
}

void PackmanMove() {
    // 상 좌 하 우
    int dx[] = {-1, 0, 1, 0};
    int dy[] = {0, -1, 0, 1};

    vector<int> dir = {-1, -1, -1};
    int max_val = -1;

    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
            for (int k = 0; k < 4; k++) {
                int cnt = 0;
                cnt = Eat({i, j, k});
                
                if (cnt > max_val) {
                    max_val = cnt;
                    dir = {i, j, k};                
                }
            }
    // cout << max_val << endl;
    // for (auto d : dir)
    //     cout << d << ' ';
    // cout << endl;

    for (auto d : dir) {
        px += dx[d];
        py += dy[d];
        if (!InRange(px, py)) {
            px -= dx[d];
            py -= dy[d];
            continue;
        }
        if (board[px][py].empty()) continue;
        board[px][py].clear();
        dead[px][py] = 3;
    }
}

void Update() {
    for (int i = 0; i < MAX_N; i++)
        for (int j = 0; j < MAX_N; j++)
            if (dead[i][j])
                dead[i][j]--;
}

void CopyComplete() {
    for (int i = 0; i < MAX_N; i++)
        for (int j = 0; j < MAX_N; j++) {
            if (nxt_board[i][j].empty()) continue;
            for (auto d : nxt_board[i][j])
                board[i][j].push_back(d);
        }
}

void Print() {
    cout << "===========\n";
    for (int i = 0; i < MAX_N; i++) {
        for (int j = 0; j < MAX_N; j++)
            cout << board[i][j].size() << ' ';
        cout << endl;
    }
    cout << px << ' ' << py << endl;
}

int GetMonster() {
    int cnt = 0;
    for (int i = 0; i < MAX_N; i++)
        for (int j = 0; j < MAX_N; j++)
            cnt += board[i][j].size();
    return cnt;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> m >> t;
    cin >> px >> py;
    px--; py--;
    for (int i = 0; i < m; i++) {
        int r, c, d;
        cin >> r >> c >> d;
        board[r - 1][c - 1].push_back(d - 1);
    }

    while (t--) {
        Egg();
        MonsterMove();
        PackmanMove();
        // Print();
        Update();
        CopyComplete();
    }
    cout << GetMonster();
    return 0;
}