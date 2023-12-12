#include <iostream>
#include <string>

using namespace std;

#define DIR_NUM 4
#define MAX_NUM 100000

int n, x, y, dir;
int answer = -1;
string cmd;

// 북 동 남 서
int dx[DIR_NUM] = {-1, 0, 1, 0};
int dy[DIR_NUM] = {0, 1, 0, -1};

int main() {
    cin >> cmd;
    for (int time = 1; time <= cmd.size(); time++) {
        char c_dir = cmd[time - 1];
        if (c_dir == 'L') {
            dir = (dir + 1) % 4;
        } else if (c_dir == 'R') {
            dir = (dir + 3) % 4;
        } else {
            x += dx[dir];
            y += dy[dir];
        }

        if (x == 0 && y == 0) {
            answer = time;
            break;
        }
    }

    cout << answer;
    return 0;
}