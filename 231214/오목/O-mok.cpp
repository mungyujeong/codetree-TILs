#include <iostream>

#define MAX_N 19
#define DIR_NUM 4
#define CROSS_NUM 8

using namespace std;

int arr[MAX_N][MAX_N];
int x, y, nx, ny, cx, cy;
int value = 0;
int answer = 0;
int dx[DIR_NUM] = {0, 0, -1, 1};
int dy[DIR_NUM] = {1, -1, 0, 0};
int cdx[CROSS_NUM] = {1, 1, -1, -1};
int cdy[CROSS_NUM] = {-1, 1, -1, 1};
bool isWin = false;

bool InRange(int x, int y) {
    return 0 <= x && x < MAX_N && 0 <= y && y < MAX_N;
}

int main() {
    for (int i = 0; i < MAX_N; i++) 
        for (int j = 0; j < MAX_N; j++)
            cin >> arr[i][j];
    
    for (int i = 0; i < MAX_N; i++) {
        for (int j = 0; j < MAX_N; j++) {
            value = arr[i][j];
            
            if (value) {
                // 직선
                for (int d = 0; d < 4; d++) {
                    int x = i; int y = j;
                    int count = 0;
                    for (int k = 0; k < 4; k++) {
                        nx = x + dx[d];
                        ny = y + dy[d];
                        if (!InRange(nx, ny)) continue;
                        if (arr[nx][ny] != value) break;
                        x = nx; y = ny;
                        count++;
                    }

                    if (count == 4) {
                        isWin = true;
                        cx = i + dx[d] * 2 + 1;
                        cy = j + dy[d] * 2 + 1;
                        break;
                    }
                }

                if(isWin) break;

                // 대각선   
                for (int d = 0; d < 4; d++) {
                    int x = i; int y = j;
                    int count = 0;
                    for (int k = 0; k < 4; k++) {
                        nx = x + cdx[d];
                        ny = y + cdy[d];
                        if (!InRange(nx, ny)) continue;
                        if (arr[nx][ny] != value) break;
                        x = nx; y = ny;
                        count++;
                    }

                    if (count == 4) {
                        isWin = true;
                        cx = i + cdx[d] * 2 + 1;
                        cy = j + cdy[d] * 2 + 1;
                        break;
                    }
                }

                if(isWin) break;
            }
        }
        if(isWin) break;
    }

    cout << value << endl;
    if (value) {
        cout << cx << " " << cy;
    }

    return 0;
}