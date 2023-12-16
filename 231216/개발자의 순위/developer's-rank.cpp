#include <iostream>

#define MAX_K 10
#define MAX_N 20

using namespace std;

int k, n, answer = 0;
int grid[MAX_N + 1][MAX_N + 1];
int arr[MAX_N][MAX_N];

int main() {
    cin >> k >> n;
    for (int i = 0; i < k; i++) 
        for (int j = 0; j < n; j++)
            cin >> arr[i][j];

    for (int i = 0; i < k; i++) {
        for (int j = 0; j < n - 1; j++) {
            for (int k = j + 1; k < n; k++) {
                int a = arr[i][j];
                int b = arr[i][k];

                if (grid[a][b] == 2) continue;

                // 반대편이 없다면
                if (grid[b][a] != 1) {
                    grid[a][b] = 1;
                } else {
                    grid[a][b] = 2;
                    grid[b][a] = 2;
                }
            }
        }
        // for (int t = 1; t < n; t++) {
        //     for (int u = 1; u <= n; u++) 
        //         cout << grid[t][u] << " ";
        //     cout << endl;
        // }
    }

    for (int i = 0; i < MAX_N + 1; i++) 
        for (int j = 0; j < MAX_N + 1; j++) 
            if (grid[i][j] == 1)
                answer++;

    cout << answer;

    return 0;
}