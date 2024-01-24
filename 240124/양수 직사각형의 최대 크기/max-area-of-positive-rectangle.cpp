#include <iostream>

#define MAX_N 20

using namespace std;

int n, m, answer;
int board[MAX_N][MAX_N];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> board[i][j];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            for (int h = i; h < n; h++) {
                for (int w = j; w < m; w++) {
                    int cnt = 0;
                    bool possible = true;
                    for (int x = i; x <= h; x++) {
                        for (int y = j; y <= w; y++) {
                            if (board[x][y] <= 0) {
                                possible = false;
                                break;
                            }
                            cnt++;
                        }
                        if (!possible) break;
                    }

                    if (!possible) cnt = -1;
                    answer = max(answer, cnt);
                }
            }
        }
    }
    if (answer == 0) cout << -1;
    else cout << answer;
}