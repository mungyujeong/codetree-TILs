#include <iostream>

#define DIR_NUM 8
#define MAX_N 50

using namespace std;

int n, m, count, answer;
int dx[DIR_NUM] = {1, -1, 0, 0, 1, 1, -1, -1};
int dy[DIR_NUM] = {0, 0, 1, -1, 1, -1, 1, -1};
char arr[MAX_N][MAX_N];

bool InRange(int x, int y) {
    return 0 <= x && x < n && 0 <= y && y < m;
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) 
        for (int j = 0; j < m; j++) 
            cin >> arr[i][j];
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (arr[i][j] != 'L') continue;

            for (int d = 0; d < DIR_NUM; d++) {
                int x = i; int y = j;
                count = 0;
                for (int k = 0; k < 2; k++) {
                    int nx = x + dx[d]; 
                    int ny = y + dy[d];
                    if (!InRange(nx, ny)) break;
                    if (arr[nx][ny] != 'E') break;
                    count++;  
                    x = nx; y = ny;   
                }

                if (count >= 2) {
                    answer++;
                }
            }
        }
    }

    cout << answer;
    return 0;
}