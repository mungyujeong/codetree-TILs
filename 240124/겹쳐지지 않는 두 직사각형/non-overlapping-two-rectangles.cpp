#include <iostream>
#include <climits>

#define MAX_N 5

using namespace std;

int n, m, answer = INT_MIN;
int board[MAX_N][MAX_N];
int visited[MAX_N][MAX_N];

int get_rect() {
    int result = -2000;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {

            for (int h = i; h < n; h++) {
                for (int w = j; w < n; w++) {
                    bool possible = true;
                    int cnt = 0;
                    // 두번째 사각형
                    for (int x = i; x <= h; x++) {
                        for (int y = j; y <= w; y++) {
                            if (visited[x][y]) {
                                possible = false;
                                break;
                            }
                            cnt += board[x][y];
                        }
                        if (!possible) break;
                    }

                    if (possible)
                        result = max(result, cnt);
                }
            }
        }
    }

    return result;
}

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
                for (int w = j; w < n; w++) {
                    int cnt = 0;
                    for (int t = 0; t < MAX_N; t++)
                        fill(visited[t], visited[t] + MAX_N , 0);
                    // 첫번째 사각형
                    for (int x = i; x <= h; x++) {
                        for (int y = j; y <= w; y++) {
                            cnt += board[x][y];
                            visited[x][y] = 1;
                        }
                    }

                    int second = get_rect();
                    if (second != -2000)
                        answer = max(answer, cnt + second);
                }
            }
        }
    }

    cout << answer;
}