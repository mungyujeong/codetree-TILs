#include <iostream>
#include <vector>
#include <climits>
#include <tuple>
#include <algorithm>

#define MAX_M 15
#define MAX_N 10

using namespace std;

int n, m, answer = INT_MAX;
vector<pair<int, int>> rows;
vector<pair<int, int>> input;
vector<int> input_result;


vector<int> GetResult(vector<pair<int, int>> v) {
    vector<int> result;
    for (int i = 0; i <= n; i++) 
        result.push_back(0);

    int a, b;
    int grid[MAX_M + 1][MAX_N + 1] = {0, };

    for (auto i : v) {
        tie(a, b) = i;
        // cout << "a, b: " << a << " " << b << endl;
        grid[b][a] = 1;
        grid[b][a + 1] = 2;
    }

    // for (int i = 0; i <= 7; i++) {
    //     for (int j = 0; j <= 6; j++)
    //         cout << grid[i][j] << " ";
    //     cout << endl;
    // }

    // 하 우 좌
    int dx[3] = {1, 0, 0};
    int dy[3] = {0, 1, -1};

    // 가로줄에 따른 결과값 저장
    for (int start = 1; start <= n; start++) {
        int x = 1; int y = start;
        // cout << "start: " << start << endl;
        while (x != MAX_M + 1) {
            // cout << x << " " << y <<endl;1
            if (grid[x][y] == 1) {
                x += dx[0];
                y += dy[1];
            } else if (grid[x][y] == 2) {
                x += dx[0];
                y += dy[2];
            } else {
                x += dx[0];
            }
        }

        // cout << "result: " << x << " " << y << endl;

        result[y] = start;
        // for (auto i : result)
        //     cout << i << " ";
        // cout << endl;
    }
    
    return result;
}

bool IsSameResult() {
    if (GetResult(rows) == input_result) return true;
    else return false;
}

void RecursiveRow(int depth) {
    if (depth == m) {
        if (IsSameResult()) 
            answer = min(answer, (int)rows.size());
        
        return;
    }

    for (int i = depth; i < m; i++) {
        // cout << i << endl;
        rows.push_back(input[i]);
        RecursiveRow(i + 1);
        rows.pop_back();
        RecursiveRow(i + 1);
    }

    return;
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        input.push_back({a, b});
    }
    input_result = GetResult(input);
    // vector<int> zero_result;
    // zero_result = GetResult(rows);
    // for (auto i : zero_result)
    //     cout << i << endl;
    // cout << endl;
    // for (auto i : input_result)
    //     cout << i << endl;
    // cout << endl;
    // if (input_result == zero_result) cout <<"true" << endl;

    RecursiveRow(0);

    cout << answer;

    return 0;
}