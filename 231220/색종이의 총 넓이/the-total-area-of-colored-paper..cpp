#include <iostream>

#define OFFSET 100
#define MAX_R 200

using namespace std;

int n;
int grid[MAX_R + 1][MAX_R + 1];

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        x += OFFSET;
        y += OFFSET;
        for (int j = x; j < x + 8; j++) {
            for (int k = y; k < y + 8; k++) {
                grid[j][k] = 1;
            }
        }
    }

    int answer = 0;

    for (int i = 0; i <= MAX_R; i++) {
        for (int j = 0; j <= MAX_R; j++) {
            if (grid[i][j]) answer++;
        }
    }

    cout << answer;
    return 0;
}