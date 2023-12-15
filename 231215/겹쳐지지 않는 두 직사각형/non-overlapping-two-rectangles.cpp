#include <iostream>
#include <climits>

#define MAX_N 5

using namespace std;

int n, m;
int answer = INT_MIN;
int grid[MAX_N][MAX_N];
int visited[MAX_N][MAX_N] = {0, };

int GetSum(int sx, int sy, int lx, int ly) {
    int count = 0;
    for (int x = sx; x <= lx; x++) {
        for (int y = sy; y <= ly; y++) {
            count += grid[x][y];
            visited[x][y] = 1;
        }
    }

    return count;
}

int GetSecond(int sx, int sy, int lx, int ly) {
    int count = 0;
    for (int x = sx; x <= lx; x++) {
        for (int y = sy; y <= ly; y++) {
            if (visited[x][y] == 1) return INT_MIN;
            count += grid[x][y];
        }
    }

    return count;
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++)     
        for (int j = 0; j < m; j++) 
            cin >> grid[i][j];

    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            for (int k = i; k < n; k++) {
                for (int l = j; l < m; l++) {
                    for (int a = 0; a < MAX_N; a++) {
                        for (int b = 0; b < MAX_N; b++)
                            visited[a][b] = 0;
                    }
                    int count = GetSum(i, j, k, l);

                    for (int si = 0; si < n; si++) {
                        for (int sj = 0; sj < m; sj++) {
                            for (int sk = si; sk < n; sk++) {
                                for (int sl = sj; sl < m; sl++) {
                                    int sCount = GetSecond(si, sj, sk, sl);
                                    if (sCount == INT_MIN) continue;
                                    answer = max(answer, count + sCount);
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    // for (int i = 0; i < n; i++) {
    //     for (int j = 0; j < m; j++) {
    //         cout << visited[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    cout << answer;
    return 0;
}