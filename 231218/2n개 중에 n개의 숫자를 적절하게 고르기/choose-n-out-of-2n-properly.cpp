#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int n;
int answer = INT_MAX;
vector<int> v;
vector<int> selected;
int sum = 0;

void HalfCombination(int depth, int cnt) {
    if (cnt == n) {
        int count = 0;
        for (auto i : selected) {
            count += i;
            // cout << i << " ";
        }
        cout << endl;
        answer = min(answer, abs(sum - 2 * count));
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