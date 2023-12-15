#include <iostream>

#define MAX_NUM 100

using namespace std;

int n, m, answer;
int grid[MAX_NUM][MAX_NUM];

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) 
        for (int j = 0; j < n; j++)
            cin >> grid[i][j];
    
    for (int row = 0; row < n; row++) {
        int count = 0;
        int first = grid[row][0];
        for (int col = 0; col < n; col++) {
            if (first == grid[row][col]) count++;
            else if (count >= m) break;
            else {
                first = grid[row][col];
                // cout << row << " " << col << endl;
                count = 1;
            }
        }
        if (count >= m) answer++;
    }

    for (int col = 0; col < n; col++) {
        int count = 0;
        int first = grid[0][col];
        for (int row = 0; row < n; row++) {
            if (first == grid[row][col]) count++;
            else if (count >= m) break;
            else {
                
                first = grid[row][col];
                // cout << row << " " << col << endl;
                count = 1;
            }
        }
        if (count >= m) answer++;
    }

    cout << answer;
    return 0;
}