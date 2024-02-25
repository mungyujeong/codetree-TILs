#include <iostream>
#include <vector>
#include <tuple>

using namespace std;

int n, t, p, answer;
pair<int, int> work[16];
vector<int> selected;

int calculate() {
    int sum = 0;
    int last = -1;
    // for (auto v : selected) cout << v << ' ';
    // cout << endl;
    for (auto v : selected) {
        tie(t, p) = work[v];
        int finish = v + t - 1;
        if (finish >= n) return -1;
        if (last >= v) return -1;  
        last = finish;
        sum += p;
    }
    // cout << "sum: " << sum << endl;
    return sum;
}

void backtracking(int depth) {
    if (depth == n) {
        answer = max(answer, calculate());
        return;
    }

    backtracking(depth + 1);
    selected.push_back(depth);
    backtracking(depth + 1);
    selected.pop_back();
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> t >> p;
        work[i] = make_pair(t, p);
    }

    backtracking(0);

    cout << answer;
    return 0;
}