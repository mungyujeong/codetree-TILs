#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int r, c, k, row, col, board[100][100], answer;

int simulate() {
    if (row >= col) {
        // 행 정렬, 출현 빈도 오름차순
        int max_idx = 0;
        for (int i = 0; i < 100; i++) {
            vector<pair<int, int>> v;
            vector<int> map(101, 0);

            for (int j = 0; j < 100; j++) {
                if (board[i][j] == 0) continue;
                map[board[i][j]]++;
            }

            for (int j = 0; j <= 100; j++)
                if (map[j]) 
                    v.push_back({map[j], j});
            
            sort(v.begin(), v.end());
            int idx = 0;
            
            for (auto p : v) {
                if (idx >= 100) break;
                board[i][idx++] = p.second;
                if (idx >= 100) break;
                board[i][idx++] = p.first;
                if (idx >= 100) break;
            }

            max_idx = max(max_idx, idx);

            for (int j = idx; j < 100; j++)
                board[i][j] = 0;
        }

        col = max_idx - 1;
    }
    else {
        int max_idx = 0;
        for (int i = 0; i < 100; i++) {
            vector<pair<int, int>> v;
            vector<int> map(101, 0);

            for (int j = 0; j < 100; j++) {
                if (board[j][i] == 0) continue;
                map[board[j][i]]++;
            }

            for (int j = 0; j <= 100; j++)
                if (map[j]) 
                    v.push_back({map[j], j});
            
            sort(v.begin(), v.end());
            int idx = 0;
            for (auto p : v) {
                if (idx >= 100) break;
                board[idx++][i] = p.second;
                if (idx >= 100) break;
                board[idx++][i] = p.first;
                if (idx >= 100) break;
            }
            
            max_idx = max(max_idx, idx);

            for (int j = idx; j < 100; j++)
                board[j][i] = 0;
        }
        row = max_idx - 1;
    }
    return board[r][c];
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> r >> c >> k;
    r--; c--;
    row = col = 2;
    for (int i = 0; i < 3; i++) 
        for (int j = 0; j < 3; j++)
            cin >> board[i][j];
   
    while (true) {
        answer++;
        if (answer > 100) {
            cout << -1;
            return 0;
        }

        if (simulate() == k) break;
    }
    cout << answer;
    return 0;
}