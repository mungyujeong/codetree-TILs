#include <iostream>

#define MAX_N 100

using namespace std;

int n, m;
int board[MAX_N][MAX_N];

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> board[i][j];
        }
    }

    int answer = 0;

    for (int i = 0; i < n; i++) {
        int before = board[i][0];
        int cnt = 0;
        for (int j = 0; j < n; j++) {
            if (before == board[i][j]) cnt++;
            else {
                cnt = 1;
                before = board[i][j];
            }
            if (cnt >= m) {
                answer++;
                break;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        int before = board[0][i];
        int cnt = 0;
        for (int j = 0; j < n; j++) {
            if (before == board[j][i]) cnt++;
            else {
                cnt = 1;
                before = board[j][i];
            }
            if (cnt >= m) {
                answer++;
                break;
            }
        }
    }

    cout << answer;

    return 0;
}