#include <iostream>

#define DIR_NUM 4
#define MAX_NUM 100

using namespace std;

int n;
// 서 남 북 동
int dx[DIR_NUM] = {0, 1, -1, 0};
int dy[DIR_NUM] = {-1, 0, 0, 1};
int x, y, dist, dir, count;
bool finish = false;
char c_dir;

int GetDir(char a) {
    if (a == 'W') {
        return 0;
    } else if (a == 'S') {
        return 1;
    } else if (a == 'N') {
        return 2;
    } else if (a == 'E') {
        return 3;
    }
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> c_dir >> dist;
        dir = GetDir(c_dir);

        for (int j = 0; j < dist; j++) {
            x += dx[dir];
            y += dy[dir];
            count++;
            if (x == 0 && y == 0) {
                finish = true;
                break;
            }
        }
        if (finish) break;
    }

    if (finish) {
        cout << count;
    } else {
        cout << -1;
    }

    return 0;
}