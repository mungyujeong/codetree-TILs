#include <iostream>

#define MAX_N 20

using namespace std;

int n, m;
int grid[MAX_N][MAX_N];
int answer = -1;

int GetSum(int x1, int y1, int x2, int y2) {
    int sum = 0;
    for (int i = x1; i <= x2; i++) {
        for (int j = y1; j <= y2; j++) {
            if (grid[i][j] <= 0) return -1;
        }
    }

    return (x2 - x1 + 1) * (y2 - y1 + 1);
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) 
        for (int j = 0; j < m; j++)
            cin >> grid[i][j];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            for (int k = i; k < n; k++) {
                for (int l = j; l < m; l++) {
                    answer = max(answer, GetSum(i, j, k, l));
                }
            }
        }
    }

    cout << answer;
    return 0;
}