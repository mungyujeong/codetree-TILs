#include <iostream>
#include <vector>
#include <climits>

#define MAX_N 10

using namespace std;

int n;
bool visited[MAX_N + 1];
int grid[MAX_N][MAX_N];
int answer = INT_MAX;
vector<pair<int, int>> v;

void Cycle(int depth, int row, int cost, int cnt) {
    if (cnt == n - 1) {
        
        if (grid[row][0] != 0)
            answer = min(answer, cost + grid[row][0]);  


        // for (auto i : v)
        //     cout << i.first << " " << i.second << endl;
        // cout << "====================" << endl;
        // cout << row << " " << cost + grid[row][0] << endl;
        return;
    }

    if (depth == n - 1)
        return;

    for (int col = 1; col < n; col++) {
        if (visited[col]) continue;
        if (col == row) continue;
        if (grid[row][col] == 0) continue;
        visited[col] = true;
        v.push_back({row, col});
        Cycle(depth + 1, col, cost + grid[row][col], cnt + 1);
        visited[col] = false;
        v.pop_back();
        Cycle(depth + 1, col, cost + grid[row][col], cnt);
    }

    return;
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> grid[i][j];

    Cycle(0, 0, 0, 0);
    cout << answer;
    return 0;
}