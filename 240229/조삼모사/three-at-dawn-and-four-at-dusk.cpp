#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>

#define MAX_N 20

using namespace std;

int n, board[MAX_N][MAX_N], answer = INT_MAX;

int calculate(vector<int> v) {
    int result = 0;
    for (int i = 0; i < v.size(); i++) 
        for (int j = 0; j < v.size(); j++) {
            if (v[i] == v[j]) continue;
            result += board[v[i]][v[j]];
        }
    return result;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> board[i][j];
    
    vector<int> comb(n, 0);
    fill(comb.end() - n / 2, comb.end(), 1);
    do {
        vector<int> a, b;
        for (int i = 0; i < n; i++) {
            if (comb[i]) a.push_back(i);
            else b.push_back(i);
        }

        answer = min(answer, abs(calculate(a) - calculate(b)));
    } while (next_permutation(comb.begin(), comb.end()));

    cout << answer;
    return 0;
}