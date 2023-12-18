#include <iostream>
#include <vector>
#include <climits>
#include <tuple>

#define MAX_N 10

using namespace std;

vector<int> v;
vector<pair<int, int>> selected_point;
int n, m, c;
int grid[MAX_N][MAX_N];
int answer = INT_MIN;

int GetCount() {
    int sum = 0;
    for (auto i : selected_point) {
        int count = 0;
        int x, y;
        tie(x, y) = i;
        // cout << "x, y: " << x << " " << y << endl;
        for (int j = y; j < y + m; j++) {
            // cout << "j: " << j << " ";
            if (grid[x][j] + count > c) break;
            count += grid[x][j];
            sum += grid[x][j] * grid[x][j];
        }
        // cout << endl;
    }
    // cout << sum << endl;

    return sum;
}

bool possible() {
    int x1, y1, x2, y2;
    tie(x1, y1) = selected_point[0];
    tie(x2, y2) = selected_point[1];

    if (x1 == x2 && abs(y2 - y1) < m) 
        return false;
    // cout << "possible: " << x1 << " " << y1 << " x2, y2: " << x2 << " " << y2 << endl;
    return true;
}

void Recursive(int depth) {
    if (depth == 2) {
        if (possible())
            answer = max(answer, GetCount());
        return;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - m + 1; j++) {
            // cout << "depth : " << depth << " i, j: " << i << " " << j << endl;
            selected_point.push_back({i, j});
            Recursive(depth + 1);
            selected_point.pop_back();
        }
    }

    return;
}

int main() {
    cin >> n >> m >> c;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> grid[i][j];

    Recursive(0);
    cout << answer;
    return 0;
}