#include <iostream>

using namespace std;

#define DIR_NUM 4
#define MAX_NUM 100

int n, m, r, c;
int arr[MAX_NUM][MAX_NUM];
int dx[DIR_NUM] = {0, 0, 1, -1};
int dy[DIR_NUM] = {1, -1, 0, 0};

int IsRange(int tx, int ty) {
    return 0 <= tx && tx < n && 0 <= ty && ty < n;
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> r >> c;
        int x = r - 1; int y = c - 1;
        arr[x][y] = 1;
        int count = 0;
        for (int d = 0; d < 4; d++) {
            int nx = x + dx[d]; int ny = y + dy[d];
            if (IsRange(nx, ny) && arr[nx][ny] > 0) {
                count++;
            } else {
                continue;
            }
        }
        if (count == 3) {
            cout << 1 << endl;
        } else {
            cout << 0 << endl;
        }
    }
    return 0;
}