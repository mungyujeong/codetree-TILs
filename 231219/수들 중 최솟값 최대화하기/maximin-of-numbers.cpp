#include <iostream>
#include <vector>
#include <climits>

#define MAX_N 10

using namespace std;

vector<int> v;
int answer = INT_MIN;
bool visited[MAX_N];
int n;
int grid[MAX_N][MAX_N];

void Choose(int row, int cnt) {
    if (cnt == n) {
        int min_value = INT_MAX;
        for (auto i : v)
            min_value = min(min_value, i);
        answer = max(answer, min_value);

        return;
    }

    for (int i = 0; i < n; i++) {
        if (visited[i]) continue;
        visited[i] = true;
        v.push_back(grid[row][i]);
        Choose(row + 1, cnt + 1);
        visited[i] = false;
        v.pop_back();
    }
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> grid[i][j];

    Choose(0, 0);
    cout << answer;
    return 0;
}