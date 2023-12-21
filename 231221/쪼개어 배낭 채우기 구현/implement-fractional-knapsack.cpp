#include <iostream>
#include <algorithm>
#include <vector>
#include <tuple>

using namespace std;

int n, m;
vector<tuple<double, int, int>> jewel;

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        int w, v;
        cin >> w >> v;
        jewel.push_back({(double)v / (double)w, w, v});
    }

    sort(jewel.begin(), jewel.end(), greater<>());
    
    double answer = 0;
    int cnt = 0;
    for (auto i : jewel) {
        // cout << get<0>(i) << " " << get<1>(i) << " " << get<2>(i) << endl;
        if (cnt + get<1>(i) <= m) {
            cnt += get<1>(i);
            answer += get<2>(i);
        } else {
            answer += get<0>(i) * (m - cnt);
            break;
        }
    }

    cout << fixed;
    cout.precision(3);
    cout << answer;

    return 0;
}