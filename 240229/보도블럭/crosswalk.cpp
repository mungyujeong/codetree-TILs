#include <iostream>
#include <vector>

#define MAX_N 100

using namespace std;

int n, L, board[MAX_N][MAX_N], answer;

int calculate(vector<int> v) {
    int cnt, cur, result;
    cnt = result = 0;
    cur = v[0];
    // cout << v[0] << ": ";
    for (int i = 0; i < n; i++) {
        int nxt = v[i];

        if (cur == nxt) {
            cnt++;
            continue;
        }
        // 차이가 1를 넘기면 설치 불가능
        if (abs(nxt - cur) > 1) return 0;

        // 다음이 더 높은 곳이면
        if (nxt > cur) {
            // 지금까지 세왔던 빈칸수가 L보다 작으면 불가능
            if (cnt < L) return 0;
            cnt = 1;
            cur = nxt;
            continue;
        }
        // 다음이 더 낮은 곳이면
        else {
            // L개만큼 있는 지 확인
            int tmp = 0;
            int idx = -1;
            for (int j = i; j < n; j++) {
                if (nxt == v[j]) tmp++;
                else break;

                if (tmp == L) {
                    idx = j;
                    break;
                }
            }

            if (idx >= 0) {
                cur = v[idx];
                cnt = 0;
                i = idx;
                // cout << i << endl;
            }
            else return 0;
        }
    }

    return 1;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> L;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> board[i][j];
    
    for (int i = 0; i < n; i++) {
        vector<int> row, col;
        for (int j = 0; j < n; j++)
            row.push_back(board[i][j]);
        for (int j = 0; j < n; j++)
            col.push_back(board[j][i]);
        
        // answer += calculate(col);      
        // if (calculate(col)) cout << i << endl;  
        answer += calculate(row) + calculate(col);
    }
    cout << answer;   
    return 0;
}