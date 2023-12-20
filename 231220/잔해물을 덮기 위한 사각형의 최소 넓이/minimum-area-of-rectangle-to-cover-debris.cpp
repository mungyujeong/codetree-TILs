#include <iostream>
#include <climits>

#define MAX_R 2000
#define OFFSET 1000

using namespace std;

int grid[MAX_R + 1][MAX_R + 1];

int main() {
    for (int i = 1; i <= 2; i++) {
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

    int max_x = INT_MIN;
    int min_x = INT_MAX;
    int max_y = INT_MIN;
    int min_y = INT_MAX;
    for (int i = 0; i <= MAX_R; i++) {
        for (int j = 0; j <= MAX_R; j++) {
            if (grid[i][j] == 1) {
                max_x = max(max_x, i);
                min_x = min(min_x, i);

                max_y = max(max_y, j);
                min_y = min(min_y, j);
            }
        }
    }
    // cout << max_x << " " << min_x << " | " << max_y << " " << min_y << endl;
    cout << (max_x - min_x + 1) * (max_y - min_y + 1);
    return 0;
}