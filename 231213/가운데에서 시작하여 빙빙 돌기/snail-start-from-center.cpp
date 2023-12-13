#include <iostream>

using namespace std;

#define MAX_N 100
#define DIR_NUM 4

int n, x, y, dir, dist, cycle, count;
int dx[DIR_NUM] = {0, -1, 0, 1};
int dy[DIR_NUM] = {1, 0, -1, 0};
int arr[MAX_N][MAX_N];

bool IsRange(int x, int y){
    return 0 <= x && x < n && 0 <= y && y < n;
}

int main() {
    cin >> n;
    x = y = int(n / 2);
    count = 2;
    arr[x][y] = 1;
    dist = cycle = 1;
    while(count <= n * n) {
        int nx = x + dx[dir];
        int ny = y + dy[dir];
        if (IsRange(nx, ny) && arr[nx][ny] == 0 && dist != 0) {
            x = nx; y = ny;
            arr[nx][ny] = count++;
            dist -= 1;
        } else {
            dir = (dir + 1) % 4;
            if (dir == 0 || dir == 2) {
                cycle++;
            }
            dist = cycle;
        }
    }    

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) 
            cout << arr[i][j] << " ";
        cout << endl;
    }
    return 0;
}