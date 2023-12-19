#include <iostream>
#include <vector>

#define MAX_N 10

using namespace std;

bool row_visited[MAX_N + 1];
bool col_visited[MAX_N + 1];
int answer = 0;
int n;
int grid[MAX_N][MAX_N];

void GetSum(int depth, int count) {
    if (depth == n + 1) {
        answer = max(answer, count);
        return;
    }

    for (int i = 0; i < n; i++) {
        if (row_visited[i]) continue;
        row_visited[i] = true;
        for (int j = 0; j < n; j++) {
            if (col_visited[j]) continue;
            col_visited[j] = true;
            // cout << "depth: " << depth << " " << i << " " << j << endl;
            GetSum(depth + 1, count + grid[i][j]);

            col_visited[j] = false;
        }
        row_visited[i] = false;
    }
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> grid[i][j];
    
    GetSum(1, 0);

    cout << answer;
    return 0;
}