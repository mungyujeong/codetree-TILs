#include <iostream>

#define MAX_N 20
#define DIR_NUM 4

using namespace std;

int n, answer;
int grid[MAX_N][MAX_N];
int dx[DIR_NUM] = {-1, -1, 1, 1};
int dy[DIR_NUM] = {1, -1, -1, 1};

bool InRange(int x, int y){
    return 0 <= x && x < n && 0 <= y && y < n;
}

int GetSum(int x, int y, int k, int l) {
    int count = 0;
    int move_num[DIR_NUM] = {k, l, k, l};
    int nx = x;
    int ny = y;
    
    for (int d = 0; d < DIR_NUM; d++) {
        for (int i = 0; i < move_num[d]; i++) {
            x += dx[d];
            y += dy[d];
            if (!InRange(x, y)) return 0;

            count += grid[x][y];
        }
    }

    return count;
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) 
        for (int j = 0; j < n; j++) 
            cin >> grid[i][j];
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 1; k < n; k++) {
                for (int l = 1; l < n; l++) {
                    int count = GetSum(i, j, k, l);
                    answer = max(answer, count);
                }
            }
        }
    }

    cout << answer;
    return 0;
}