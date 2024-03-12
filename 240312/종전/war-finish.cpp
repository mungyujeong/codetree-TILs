#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

#define MAX_N 22

using namespace std;

int n, board[MAX_N][MAX_N], group[MAX_N][MAX_N], answer = INT_MAX;
int dx[] = {1, 1, -1, -1};
int dy[] = {-1, 1, 1, -1};

bool in_range(int x, int y) {
    return 0 <= x && x < n && 0 <= y && y < n;
}

int simulate(int x, int y, int k, int l) {
    int move_dir[] = {k, l, k, l};
    vector<int> max_v = {0, 0, 0, 0, 0};
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            group[i][j] = 0;

    int nx = x;
    int ny = y;

    // 1번 그룹
    group[nx][ny] = 1;
    for (int d = 0; d < 4; d++) {
        for (int t = 0; t < move_dir[d]; t++) {
            nx += dx[d];
            ny += dy[d];
            if (!in_range(nx, ny)) return INT_MAX;
            group[nx][ny] = 1;
        }
    }
    // 2번 그룹
    for (int i = 0; i < x + k; i++) {
        for (int j = 0; j <= y; j++) {
            if (group[i][j] == 1) break;
            group[i][j] = 2;
        }
    }
    // 3번 그룹
    for (int i = 0; i <= x + l; i++) {
        for (int j = n - 1; j > y; j--) {
            if (group[i][j] == 1) break;
            group[i][j] = 3;
        }
    }
    // 4번 그룹
    for (int i = x + k; i < n; i++) {
        for (int j = 0; j < y - k + l; j++) {
            if (group[i][j] == 1) break;
            group[i][j] = 4;
        }
    }
    // 5번 그룹
    for (int i = x + l + 1; i < n; i++) {
        for (int j = n - 1; j >= y - k + l; j--) {
            if (group[i][j] == 1) break;
            group[i][j] = 5;
        }
    }

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            if (group[i][j] == 0)
                group[i][j] = 1;

            max_v[group[i][j] - 1] += board[i][j];
        }

    return *max_element(max_v.begin(), max_v.end()) - *min_element(max_v.begin(), max_v.end());   
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) 
        for (int j = 0; j < n; j++)
            cin >> board[i][j];
    
    for (int i = 0; i < n; i++) 
        for (int j = 0; j < n; j++) 
            for (int k = 1; k < n; k++)
                for (int l = 1; l < n; l++)
                    answer = min(answer, simulate(i, j, k, l));

    cout << answer;
    return 0;
}