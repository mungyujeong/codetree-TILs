#include <iostream>
#include <queue>

#define MAX_N 20

using namespace std;

int n, m, count, answer;
int grid[MAX_N][MAX_N];

int GetGold(int x, int y, int klimit) {
    int cost = klimit * klimit + (klimit + 1) * (klimit + 1);
    int max_cnt = 0;
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};
    bool visited[MAX_N][MAX_N] = {false, };
    pair<int, int> elements;

    // for count gold
    for (int i = 0; i < klimit; i++) {
        queue<pair<int, int>> q;
        q.push({x, y});
        while (!q.empty()) {
            cout << i << endl;
            int qx = q.front().first;
            int qy = q.front().second;
            q.pop();
            cout << qx << " " << qy << endl;
        }
    }
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) 
        for (int j = 0; j < n; j++)
            cin >> grid[i][j];
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < 1; k++) {
                count = GetGold(i, j, k);
                answer = max(answer, count);
            }
        }
    }

    cout << answer;
    return 0;
}