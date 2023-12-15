#include <iostream>

#define MAX_N 200

using namespace std;

int n, m, answer, count, tmp;
int grid[MAX_N][MAX_N];

int shape[6][3][3] = {
    {{1, 1, 1},
     {0, 0, 0},
     {0, 0, 0}}, 
    {{1, 0, 0},
     {1, 0, 0},
     {1, 0, 0}},
    {{1, 1, 0},
     {1, 0, 0},
     {0, 0, 0}},
    {{1, 1, 0},
     {0, 1, 0},
     {0, 0, 0}},
    {{1, 0, 0},
     {1, 1, 0},
     {0, 0, 0}},
    {{0, 1, 0},
     {1, 1, 0},
     {0, 0, 0}},
};

int GetTropino(int x, int y) {
    int max_sum = 0;
    for (int i = 0; i < 6; i++) {
        int count = 0;
        bool isPossible = true;
        for (int dx = 0; dx < 3; dx++) {
            for (int dy = 0; dy < 3; dy++) {
                if (shape[i][dx][dy] == 0) continue;
                else if (x + dx >= n || y + dy >= m) isPossible = false;
                else {
                    count += grid[x + dx][y + dy];
                }
            }
        }

        if (isPossible) 
            max_sum = max(max_sum, count);
    }
    return max_sum;
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) 
        for (int j = 0; j < m; j++) 
            cin >> grid[i][j];
    
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) 
            answer = max(answer, GetTropino(i, j));

    cout << answer;

    return 0;
}