#include <iostream>
#include <queue>

#define MAX_N 20

using namespace std;

int n, m, count, answer;
int grid[MAX_N][MAX_N];

int GetCost(int k) {
    return k * k * (k + 1) * (k + 1);
}

int GetGold(int x, int y, int klimit) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (abs(i - x) + abs(j - y) == klimit) {
                count += grid[i][j];
            }
        }
    }

    if (count * GetCost(klimit) > m) {
        return count;
    }
    return 0;
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) 
        for (int j = 0; j < n; j++)
            cin >> grid[i][j];
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k <= 2 * (n - 1); k++) {
                count = GetGold(i, j, k);
                answer = max(answer, count);
            }
        }
    }

    cout << answer;
    return 0;
}