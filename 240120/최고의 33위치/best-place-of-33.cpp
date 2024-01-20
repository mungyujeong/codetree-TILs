#include <iostream>

#define MAX_N 20

using namespace std;

int n;
int board[MAX_N][MAX_N];

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> board[i][j];
        }
    }
    int answer = 0;
    for (int i = 0; i <= n - 3; i++) {
        for (int j = 0; j <= n - 3; j++) {
            int cnt = 0;
            for (int x = i; x < i + 3; x++) {
                for (int y = j; y < j + 3; y++) {
                    if (board[x][y] == 1) cnt++;
                }
            }
            answer = max(answer, cnt);
        }
    }
    cout << answer;
    return 0;
}