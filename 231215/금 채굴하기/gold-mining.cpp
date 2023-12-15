#include <iostream>
#include <queue>

#define MAX_N 20

using namespace std;

int n, m, answer;
int grid[MAX_N][MAX_N];

int GetCost(int k) {
    return k * k + (k + 1) * (k + 1);
}

int GetGold(int x, int y, int klimit) {
    int count = 0;
    if (klimit == 0) 
        return grid[x][y];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (abs(i - x) + abs(j - y) <= klimit) {
                count += grid[i][j];
            }
        }
    }

    return count;
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) 
        for (int j = 0; j < n; j++)
            cin >> grid[i][j];
    
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int count = 0;
            for (int k = 0; k <= 2 * (n - 1); k++) {
                count = GetGold(i, j, k);

                if (count * m >= GetCost(k))
                    answer = max(answer, count);
            }
        }
    }

    cout << answer;
    return 0;
}