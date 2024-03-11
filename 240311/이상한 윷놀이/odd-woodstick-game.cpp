#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>

#define MAX_N 12
#define MAX_H 10

using namespace std;

int n, k, answer, color[MAX_N][MAX_N];
// 우 좌 상 하
int dx[] = {0, 0, -1, 1};
int dy[] = {1, -1, 0, 0};
vector<pair<int, int>> board[MAX_N][MAX_N];
pair<int, int> horse[MAX_H];

bool check() {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (board[i][j].size() >= 4) 
                return true;
    
    return false;
}

bool in_range(int x, int y) {
    return 0 <= x && x < n && 0 <= y && y < n;
}

void white(vector<pair<int, int>> move, int nx, int ny) {
    int h;
    for (auto p : move) {
        tie(h, ignore) = p;
        board[nx][ny].push_back(p);
        horse[h] = make_pair(nx, ny);
        // cout << "push: " << h << ' ' << nx << ' ' << ny << endl;
    }
}

void red(vector<pair<int, int>> move, int nx, int ny) {
    reverse(move.begin(), move.end());
    white(move, nx, ny);
}

void blue(vector<pair<int, int>> move, int x, int y) {
    int h, d;
    tie(h, d) = move[0];
    d = (d % 2 == 0) ? d + 1 : d - 1;
    move[0] = make_pair(h, d);

    int nx = x + dx[d];
    int ny = y + dy[d];
    // cout << h << ' ' << nx << ' ' << ny << endl;
    if (!in_range(nx, ny) || color[nx][ny] == 2) white(move, x, y);
    else if (color[nx][ny] == 0) white(move, nx, ny);
    else if (color[nx][ny] == 1) red(move, nx, ny);
}

bool simulate(int h) {
    int cur_x, cur_y;
    tie(cur_x, cur_y) = horse[h];
    vector<pair<int, int>> move, stay;

    for (int i = 0; i < board[cur_x][cur_y].size(); i++) {
        int num, d;
        tie(num, d) = board[cur_x][cur_y][i];

        if (num == h) {
            for (int j = i; j < board[cur_x][cur_y].size(); j++) 
                move.push_back(board[cur_x][cur_y][j]);
            board[cur_x][cur_y] = stay;

            int nx = cur_x + dx[d];
            int ny = cur_y + dy[d];
            if (!in_range(nx, ny) || color[nx][ny] == 2) blue(move, cur_x, cur_y);
            else if (color[nx][ny] == 0) white(move, nx, ny);
            else if (color[nx][ny] == 1) red(move, nx, ny);
            // for (int i = 0; i < k; i++)
            //     cout << horse[i].first << ' ' << horse[i].second << endl;
            return check();
        }
        else stay.push_back({num, d});
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> color[i][j];
    
    for (int i = 0; i < k; i++) {
        int x, y, d;
        cin >> x >> y >> d;
        x--; y--; d--;
        horse[i] = make_pair(x, y);
        board[x][y].push_back({i, d});
    }

    while (answer < 1000) {
        answer++;

        // cout << "========\n";
        for (int h = 0; h < k; h++)
            if (simulate(h)) {
                cout << answer;
                return 0;
            }
    }


    if (answer == 1000) cout << -1;
    else cout << answer;
    return 0;
}