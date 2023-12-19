#include <iostream>
#include <vector>
#include <climits>

#define MAX_N 10

using namespace std;

int n;
bool visited[MAX_N + 1];
int grid[MAX_N][MAX_N];
int answer = INT_MAX;

void Cycle(int depth, int row, int cost) {
    if (depth == n - 1) {
        answer = min(answer, cost + grid[row][0]);
        return;
    }

    for (int col = 1; col < n; col++) {
        if (visited[col]) continue;
        if (col == row) continue;
        visited[col] = true;
        // cout << row << " " << col << endl;
        Cycle(depth + 1, col, cost + grid[row][col]);
        visited[col] = false;
    }

    return;
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> grid[i][j];

    Cycle(0, 0, 0);
    cout << answer;
    return 0;
}