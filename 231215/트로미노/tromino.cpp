#include <iostream>

#define MAX_N 200

using namespace std;

int n, m, answer, count, tmp;
int grid[MAX_N][MAX_N];

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) 
        for (int j = 0; j < m; j++) 
            cin >> grid[i][j];
    
    // 가로 막대
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= m - 3; j++) {
            count = grid[i][j] + grid[i][j + 1] + grid[i][j + 2];
            answer = max(answer, count);
        }
    }

    // 세로 막대
    for (int j = 0; j < m; j++) {
        for (int i = 0; i <= n - 3; i++) {
            count = grid[i][j] + grid[i + 1][j] + grid[i + 2][j];
            answer = max(answer, count);
        }
    }

    // 계단 블럭
    for (int i = 0; i <= n - 2; i++) {
        for (int j = 0; j <= m - 2; j++) {
            count = 0;
            for (int k = i; k < i + 2; k++) {
                for (int l = j; l < j + 2; l++) {
                    count += grid[k][l];
                }
            }

            for (int k = i; k < i + 2; k++) {
                for (int l = j; l < j + 2; l++) {
                    tmp = count;
                    tmp -= grid[k][l];
                }
                answer = max(answer, tmp);
            }
        }
    }

    cout << answer;

    return 0;
}