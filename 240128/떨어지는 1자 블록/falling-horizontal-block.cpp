#include <iostream>

#define MAX_N 100

using namespace std;

int n, m, k, board[MAX_N + 1][MAX_N + 1];

void simulate() {
    for (int i = 1; i <= n; i++) {
        for (int j = k; j <= k + m - 1; j++) {
            if (board[i][j]) {
                for (int t = k; t <= k + m - 1; t++) 
                    board[i - 1][t] = 1;
                
                return;
            }
        }
    }

    for (int t = k; t <= k + m - 1; t++) 
        board[n][t] = 1;
    
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            cin >> board[i][j];
    
    simulate();

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) 
            cout << board[i][j] << ' ';
        cout << endl;
    }
}