#include <iostream>
#include <tuple>
#include <queue>
#include <vector>

#define MAX_N 10

using namespace std;

int n, m, k, energy[MAX_N][MAX_N], board[MAX_N][MAX_N], r, c, age;
vector<int> v[MAX_N][MAX_N];
vector<tuple<int, int, int>> dead;
int dx[] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dy[] = {0, 1, 1, 1, 0, -1, -1, -1};

bool in_range(int x, int y) {
    return 0 <= x && x < n && 0 <= y && y < n;
}

void eat() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (v[i][j].empty()) continue;
            priority_queue<int> pq(v[i][j].begin(), v[i][j].end());
            vector<int> update_virus;
            
            while (!pq.empty()) {
                int e = pq.top(); pq.pop();
                e *= -1;
                if (e > board[i][j]) {
                    dead.push_back({i, j, e});
                    m--;
                }
                else {
                    board[i][j] -= e;
                    update_virus.push_back(-(e + 1));
                }
            }

            v[i][j] = update_virus;
        }
    }
}

void change() {
    int x, y, e;
    for (auto dv : dead) {
        tie(x, y, e) = dv;
        board[x][y] += e / 2;
    }

    dead.clear();
}

void spread() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (v[i][j].empty()) continue;
            for (auto virus : v[i][j]) {
                if (-virus % 5 == 0) {
                    for (int d = 0; d < 8; d++) {
                        int nx = i + dx[d];
                        int ny = j + dy[d];
                        if (!in_range(nx, ny)) continue;
                        v[nx][ny].push_back(-1);
                        m++;
                    }
                }
            }
        }
    }
}

void add_energy() {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            board[i][j] += energy[i][j];
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m >> k;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            cin >> energy[i][j];
            board[i][j] = 5;
        }
    
    for (int i = 0; i < m; i++) {
        cin >> r >> c >> age;
        v[r - 1][c - 1].push_back(-age);       
    }

    while (k-- && m > 0) {
        eat();
        change();
        spread();
        add_energy();
    }

    cout << m;
    return 0;
}