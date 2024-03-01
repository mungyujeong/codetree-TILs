#include <iostream>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;

char chair[4][8];
int k, n, d, answer;

void rotate(pair<int, int> p) {
    tie(n, d) = p;
    int tmp;
    if (d == 1) {
        tmp = chair[n][7];
        for (int i = 7; i >= 1; i--)
            chair[n][i] = chair[n][i - 1];
        chair[n][0] = tmp;
    }
    else {
        tmp = chair[n][0];
        for (int i = 0; i < 7; i++)
            chair[n][i] = chair[n][i + 1];
        chair[n][7] = tmp;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 8; j++)
            cin >> chair[i][j];
    
    cin >> k;
    while (k--) {
        cin >> n >> d;
        n--;
        vector<pair<int, int>> v;
        queue<pair<int, int>> Q;
        bool visited[4] = {};
        v.push_back({n, d});
        Q.push({n, d});   
        visited[n] = true;

        while (!Q.empty()) {
            tie(n, d) = Q.front(); Q.pop();
            for (auto nxt : {n + 1, n - 1}) {
                if (nxt < 0 || nxt >= 4) continue;
                if (visited[nxt]) continue;
                visited[nxt] = true;
                if (nxt > n && chair[n][2] == chair[nxt][6]) continue;
                if (nxt < n && chair[n][6] == chair[nxt][2]) continue;
                Q.push({nxt, -d});
                v.push_back({nxt, -d});
            }
        }

        for (auto i : v)
            rotate(i);
    }

    int tmp = 1;
    for (int i = 0; i < 4; i++) {
        if (chair[i][0] == '1')
            answer += tmp;
        tmp *= 2;
    }

    cout << answer;
    return 0;
}