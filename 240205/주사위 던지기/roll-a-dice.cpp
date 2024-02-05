#include <iostream>
#include <deque>

#define MAX_N 100

using namespace std;

int n, m, r, c, x, y, answer, board[MAX_N][MAX_N];
deque<int> r_dice = {4, 1, 3, 6};
deque<int> c_dice = {5, 1, 2, 6};
// L R U D
int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};

void rotate_dice(int d) {
    if (d == 0) {
        r_dice.push_back(r_dice.front());
        r_dice.pop_front();
        c_dice[1] = r_dice[1];
        c_dice[3] = r_dice[3];
    }
    else if (d == 1) {
        r_dice.push_front(r_dice.back());
        r_dice.pop_back();
        c_dice[1] = r_dice[1];
        c_dice[3] = r_dice[3];
    }
    else if (d == 2) {
        c_dice.push_back(c_dice.front());
        c_dice.pop_front();
        r_dice[1] = c_dice[1];
        r_dice[3] = c_dice[3];
    }
    else if (d == 3) {
        c_dice.push_front(c_dice.back());
        c_dice.pop_back();
        r_dice[1] = c_dice[1];
        r_dice[3] = c_dice[3];
    }
}

bool InRange(int nx, int ny) {
    return 0 <= nx && nx < n && 0 <= ny && ny < n;
}

void move(int d) {
    int nx = x + dx[d];
    int ny = y + dy[d];
    if (!InRange(nx, ny)) return;
    x = nx;
    y = ny;
    rotate_dice(d);
    board[x][y] = r_dice[3];
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m >> r >> c;
    x = r - 1;
    y = c - 1;
    board[r - 1][c - 1] = 6;

    while (m--) {
        char cmd;
        cin >> cmd;
        if (cmd == 'L') move(0);
        else if (cmd == 'R') move(1);
        else if (cmd == 'U') move(2);
        else if (cmd == 'D') move(3);
    }

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            answer += board[i][j];
    
    cout << answer;
}