#include <iostream>

#define OFFSET 1000
#define MAX_R 2000

using namespace std;

int grid[MAX_R + 1][MAX_R + 1] = {};

int main() {
    for (int i = 1; i <= 3; i++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        
        x1 += OFFSET;
        y1 += OFFSET;
        x2 += OFFSET;
        y2 += OFFSET;

        for (int j = x1; j < x2; j++) {
            for (int k = y1; k < y2; k++) {
                grid[j][k] = i;
            }
        }
    }
    int answer = 0;
    for (int i = 0; i <= MAX_R; i++) {
        for (int j = 0; j <= MAX_R; j++) {
            if (grid[i][j] == 1 || grid[i][j] == 2)
                answer++;
        }
    }
    cout << answer;
    return 0;
}