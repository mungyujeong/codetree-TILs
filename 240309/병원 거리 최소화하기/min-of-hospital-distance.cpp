#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <tuple>

using namespace std;

int n, m, answer = INT_MAX;
vector<pair<int, int>> person, hospital;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int x;
            cin >> x;
            if (x == 1) person.push_back({i, j});
            else if (x == 2) hospital.push_back({i, j});
        }
    }

    vector<int> comb(hospital.size(), 0);
    fill(comb.end() - m, comb.end(), 1);
    do {
        int cnt = 0;
        vector<pair<int, int>> selected;

        for (int i = 0; i < comb.size(); i++)   
            if (comb[i])    
                selected.push_back(hospital[i]);
        
        for (auto p : person) {
            int px, py;
            tie(px, py) = p;
            int dist = INT_MAX;
            for (auto h : selected) {
                int hx, hy;
                tie(hx, hy) = h;
                dist = min(dist, abs(hx - px) + abs(hy - py));
            }
            cnt += dist;
        }

        answer = min(answer, cnt);
    } while (next_permutation(comb.begin(), comb.end()));
    
    cout << answer;

    return 0;
}