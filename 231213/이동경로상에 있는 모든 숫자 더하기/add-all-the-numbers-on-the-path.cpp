#include <iostream>
#include <string>

using namespace std;

#define DIR_NUM 4
#define MAX_N 99
#define MAX_T 100000

int n, t, answer, x, y, dir;
int arr[MAX_N][MAX_N];
string cmd;
// 북 동 남 서
int dx[DIR_NUM] = {-1, 0, 1, 0};
int dy[DIR_NUM] = {0, 1, 0, -1};

bool InRange(int x, int y) {
    return 0 <= x && x < n && 0 <= y && y < n;
}

int main() {
    cin >> n >> t;
    cin >> cmd;
    for (int i = 0; i < n; i++) 
        for (int j = 0; j < n; j++) 
            cin >> arr[i][j];

    x = y = n / 2;
    answer = arr[x][y];

    for (int i = 0; i < t; i++) {
        char command = cmd[i];
        if (command == 'R') {
            dir = (dir + 1) % 4;
        } else if (command == 'L') {
            dir = (dir + 3) % 4;
        } else {
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            if (InRange(nx, ny)) {
                x = nx; y = ny;
                answer += arr[x][y];
            }
        }
    }

    cout << answer;
    return 0;
}