#include <iostream>

using namespace std;

#define DIR_NUM 4

int n, t, r, c, dir;
char d;

// 위 오른쪽 아래 왼쪽
int dx[DIR_NUM] = {-1, 0, 1, 0};
int dy[DIR_NUM] = {0, 1, 0, -1};

int GetDir(char a) {
    if (a == 'U') {
        return 0;
    } else if (a == 'D') {
        return 2;
    } else if (a == 'R') {
        return 1;
    } else {    
        return 3;
    }
}

bool InRange(int x, int y) {
    return 0 <= x && x < n && 0 <= y && y < n;
}

int main() {
    cin >> n >> t;
    cin >> r >> c >> d;
    dir = GetDir(d);
    int x = r - 1;
    int y = c - 1;

    while(t--) {
        int nx = x + dx[dir]; int ny = y + dy[dir];
        if(!InRange(nx, ny)) {
            dir = (dir + 2) % 4;
            continue;
        } else {
            x = nx;
            y = ny;
        }
    }

    cout << x + 1 << " " << y + 1;
    return 0;
}