#include <iostream>

#define MAX_N 201

using namespace std;

int n, m;
int board[MAX_N][MAX_N];
int block[6][3][3] = {
    {{1, 0, 0},
    {1, 1, 0},
    {0, 0, 0}},

    {{0, 1, 0},
    {1, 1, 0},
    {0, 0, 0}},

    {{1, 1, 0},
    {0, 1, 0},
    {0, 0, 0}},

    {{1, 1, 0},
    {1, 0, 0},
    {0, 0, 0}},

    {{1, 1, 1},
    {0, 0, 0},
    {0, 0, 0}},

    {{1, 0, 0},
    {1, 0, 0},
    {1, 0, 0}},
};

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> board[i][j];
        }
    }
    
    int answer = 0;
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < m; k++) {

                int cnt = 0;
                for (int x = 0; x < 3; x++) {
                    for (int y = 0; y < 3; y++) {
                        if (block[i][x][y] == 0) continue;
                        if (x + j >= n || y + k >= m) continue;
                        cnt += board[x + j][y + k];
                    }
                }

                answer = max(answer, cnt);
            }
        }
    }
    cout << answer;
    return 0;
}