#include <iostream>
#include <algorithm>
#include <vector>
#include <tuple>

#define MAX_T 250
#define MAX_N 100

using namespace std;

int n, k, p, t;
vector<vector<int>> v;
int shake_time[MAX_N + 1];
int infected[MAX_N + 1];

int main() {
    cin >> n >> k >> p >> t;
    infected[p] = true;
    shake_time[p] = k;
    for (int i = 0; i < t; i++) {
        vector<int> tmp;
        int ti, x, y;
        cin >> ti >> x >> y;
        tmp.push_back(ti);
        tmp.push_back(x);
        tmp.push_back(y);
        v.push_back(tmp);
    }

    sort(v.begin(), v.end());

    for (int i = 0; i < t; i++) {
        int ti, x, y;
        x = v[i][1];
        y = v[i][2];

        // 둘다 감염일 경우
        if (infected[x] && infected[y]) {
            shake_time[x]--;
            shake_time[y]--;
        } else if (infected[x] && shake_time[x] > 0) {
            shake_time[x]--;
            infected[y] = 1;
        } else if (infected[y] && shake_time[y] > 0) {
            shake_time[y]--;
            infected[x] = 1;
        } 
    }

    for (int i = 1; i <= n; i++) {
        cout << infected[i];
    }
    cout << endl;
    return 0;
}