#include <iostream>

#define MAX_R 200
#define OFFSET 100

using namespace std;

int n;
int grid[MAX_R + 1][MAX_R + 1];

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        x1 += OFFSET;
        y1 += OFFSET;
        x2 += OFFSET;
        y2 += OFFSET;

        for (int j = x1; j < x2; j++) {
            for (int k = y1; k < y2; k++) {
                grid[j][k] = i % 2 ? 2 : 1;
            }
        }
    }

    int answer = 0;

    for (int i = 0; i <= MAX_R; i++) {
        for (int j = 0; j <= MAX_R; j++) {
            if (grid[i][j] == 2) answer++;
        }
    }
    cout << answer;
    return 0;
}