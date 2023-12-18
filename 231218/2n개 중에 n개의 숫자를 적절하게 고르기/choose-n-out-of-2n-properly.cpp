#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int n;
int answer = INT_MAX;
vector<int> v;
vector<int> selected;

void HalfCombination(int depth,int cnt) {
    if (cnt == n) {
        answer = min(answer, abs(selected[0] - selected[1]));
        return;
    }

    if (depth == 2 * n) {   
        return;
    }

    selected.push_back(v[depth]);
    HalfCombination(depth + 1, cnt + 1);
    selected.pop_back();
    HalfCombination(depth + 1, cnt);
}

int main() {
    cin >> n;
    int sum = 0;
    for (int i = 0; i < 2 * n; i++) {
        int x;
        cin >> x;
        v.push_back(x);
        sum += x;
    }

    HalfCombination(0, 0);

    cout << answer;
    return 0;
}