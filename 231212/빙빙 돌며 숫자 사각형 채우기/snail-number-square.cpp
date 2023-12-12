#include <iostream>

using namespace std;

#define DIR_NUM 4
#define MAX_NUM 100

int n, m; int x = 0; int y = 0; int count = 1; int d = 0;
int arr[MAX_NUM][MAX_NUM] = {0, };


// 동 남 서 북
int dx[DIR_NUM] = {0, 1, 0, -1};
int dy[DIR_NUM] = {1, 0, -1, 0};

bool IsRange(int tx, int ty) {
    return 0 <= tx && tx < n && 0 <= ty && ty < m;
}

int main() {
    cin >> n >> m;
    arr[x][y] = count;
    while (count < n * m) {
        int nx = x + dx[d];
        int ny = y + dy[d];
        if (IsRange(nx, ny) && arr[nx][ny] == 0) {
            count++;
            arr[nx][ny] += count;
            x = nx; y = ny;
        } else {
            d = (d + 1) % 4;
        }
    }
    for (int i= 0; i < n; i++ ) {
        for (int j = 0; j < m; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}