#include <iostream>

using namespace std;

#define DIR_NUM 4
#define MAX_N 100

int n, m, x, y, dir;
int arr[MAX_N][MAX_N];
// 하 우 상 좌
int dx[DIR_NUM] = {1, 0, -1, 0};
int dy[DIR_NUM] = {0, 1, 0, -1};

bool IsRange(int tx, int ty) {
    return 0 <= tx && tx < n && 0 <= ty && ty < m;
}

int main() {
    cin >> n >> m;
    int count = 1;
    arr[x][y] = count;
    while (count < n * m) {
        int nx = x + dx[dir];
        int ny = y + dy[dir];
        if (IsRange(nx, ny) && arr[nx][ny] == 0) {
            count++;
            arr[nx][ny] = count;
            x = nx; y = ny;
        } else {
            dir = (dir + 1) % 4;
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) 
            cout << arr[i][j] << " ";
        cout << endl;
    }

    return 0;
}