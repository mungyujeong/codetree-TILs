#include <iostream>
#include <climits>

#define MAX_N 20

using namespace std;

int max_sum = INT_MIN;
int n;
int grid[MAX_N][MAX_N];

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) 
        for (int j = 0; j < n; j++)
            cin >> grid[i][j];
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - 2; j++) {
            for (int k = i + 1; k < n; k++) {
                for (int l = j + 1; l < n - 2; l++) {
                    max_sum = max(max_sum, grid[i][j] + grid[i][j + 1] + grid[i][j + 2] +
                                            grid[k][l] + grid[k][l + 1] + grid[k][l + 2]);
                }
            }
        }
    }
    cout << max_sum;
    return 0;
}