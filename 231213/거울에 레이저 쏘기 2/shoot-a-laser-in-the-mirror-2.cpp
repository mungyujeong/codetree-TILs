#include <iostream>

using namespace std;

#define MAX_N 1000
#define DIR_NUM 4

int n, k, x, y, dir, answer;
char arr[MAX_N][MAX_N];
// 우 상 좌 하
int dx[DIR_NUM] = {0, -1, 0, 1};
int dy[DIR_NUM] = {1, 0, -1, 0};

void GetPositionAndDir() {
    if (k <= n) {
        x = 0; y = k - 1; 
        dir = 3;
    } else if (k <= 2 * n) {
        x = k - (n + 1); y = n - 1; 
        dir = 2;
    } else if (k <= 3 * n) {
        x = n - 1; y = 3 * n - k;
        dir = 1;
    } else {
        x = 4 * n - k; y = 0;
        dir = 0;
    }
}

bool IsRange(int tx, int ty) {
    return 0 <= tx && tx < n && 0 <= ty && ty < n;
}

int ChangeDir(int d) {
    if (arr[x][y] == '\\') {
        if (d == 0) d = 3;
        else if (d == 1) d = 2;
        else if (d == 2) d = 1;
        else d = 0;
    } else {
        if (d == 0) d = 1;
        else if (d == 1) d = 0;
        else if (d == 2) d = 3;
        else d = 2;
    }
    return d;
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
        }
    }
    cin >> k;
    GetPositionAndDir();

    while (IsRange(x, y)) {
        dir = ChangeDir(dir);
        answer++;
        x += dx[dir];
        y += dy[dir];
    }

    cout << answer;
    return 0;
}