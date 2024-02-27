#include <iostream>
#include <vector>

#define MAX_N 20

using namespace std;

int n, board[MAX_N][MAX_N], answer;
vector<int> cmd;

void rotate(int d) {
    // 0 1 2 3
    // 좌 우 상 하
    if (d == 0) return;
    int tmp[MAX_N][MAX_N];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            tmp[i][j] = board[i][j];

    if (d == 1) {
        
    }
    if (d == 2) {

    }
    if (d == 3) {

    }
}

void move(int d) {
    rotate(d);

    int grid[MAX_N][MAX_N];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            grid[i][j] = board[i][j];
    
    // 왼쪽 기준으로 작성
    for (int i = 0; i < n; i++) {
        int idx = 0;
        int tmp = 0;
        for (int j = 0; j < n; j++) {
            if (board[i][j] == 0) continue;
            if (board[i][j] == tmp) {
                grid[i][idx - 1] = 2 * tmp;
                tmp = 0;
            }
            else {
                tmp = board[i][j];
                grid[i][idx++] = tmp;
            }
        }
    }

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            board[i][j] = grid[i][j];
}

void get_max() {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            answer = max(answer, board[i][j]);
}

void backtracking(int depth) {
    if (depth == 5) {
        for (auto i : cmd)
            move(i);
        
        get_max();
        return;
    }

    for (int d = 0; d < 4; d++) {
        cmd.push_back(d);
        backtracking(depth + 1);
        cmd.pop_back();
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> board[i][j];

    backtracking(0);

    cout << answer;
    return 0;
}