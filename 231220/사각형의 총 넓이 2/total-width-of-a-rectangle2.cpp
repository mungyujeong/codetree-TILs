#include <iostream>

#define MAX_N 10
#define OFFSET 100

using namespace std;

int n;
int grid[2 * OFFSET + 1][2 * OFFSET + 1];

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        for (int j = x1; j < x2; j++) {
            for (int k = y1; k < y2; k++) {
                grid[j][k] = 1;
            }
        }
    }

    int answer = 0;
    for (int i = 0; i < 2*OFFSET + 1; i++) {
        for (int j  =0; j < 2*OFFSET + 1; j++) {
            if(grid[i][j] == 1) answer++;
        }
    }

    cout << answer;
    return 0;
}