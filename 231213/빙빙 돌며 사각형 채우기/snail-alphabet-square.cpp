#include <iostream>

using namespace std;

#define DIR_NUM 4
#define MAX_N 100

int n, m, dir, x, y, count;
int arr[MAX_N][MAX_N];
// 우 하 좌 상
int dx[DIR_NUM] = {0, 1, 0, -1};
int dy[DIR_NUM] = {1, 0, -1, 0};

bool IsRange(int tx, int ty) {
    return 0 <= tx && tx < n && 0 <= ty && ty < m;
}

int main() {
    cin >> n >> m;
    arr[x][y] = 65;
    // 65 ~ 90
    for (int i = 1; i < n * m; i++) {
        while(true) {
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            if (IsRange(nx, ny) && arr[nx][ny] == 0) {
                count++;
                if (count > 25) {
                    count = 0;
                }
                arr[nx][ny] = count + 65;
                x = nx; y = ny;
                break;
            } else {
                dir = (dir + 1) % 4;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            cout << char(arr[i][j]) << " ";
        cout << endl;
    }
    return 0;
}