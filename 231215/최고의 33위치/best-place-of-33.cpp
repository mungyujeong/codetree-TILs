#include <iostream>

#define MAX_N 20

using namespace std;

int n;
int grid[MAX_N][MAX_N];

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) 
        for (int j = 0; j < n; j++) 
            cin >> grid[i][j];
    
    int max_coin = 0;
    for (int i = 0; i <= n - 3; i++) {
        for (int j = 0; j <= n - 3; j++) {
            int sum = 0;
            for (int k = i; k < i + 3; k++) {
                for (int l = j; l < j + 3; l++) {
                    sum += grid[k][l];
                }
            }
            max_coin = max(max_coin, sum);
        }
    }

    cout << max_coin;
    return 0;
}