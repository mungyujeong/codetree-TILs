#include <iostream>
#include <vector>
#include <climits>

#define MAX_N 1000000

using namespace std;

int n, m, answer = INT_MIN;
vector<int> v;
vector<int> candidate;

int GetCount() {
    int result;
    for (auto i : candidate) {
        result ^= i;
    }
    return result;
}

void FindXor(int depth, int cnt) {
    if (depth == n) {
        if (cnt == m) {
            answer = max(answer, GetCount());
        }
        return;
    }

    candidate.push_back(v[depth]);
    FindXor(depth + 1, cnt + 1);
    candidate.pop_back();
    FindXor(depth + 1, cnt);

    return;
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        v.push_back(x);
    }
    
    FindXor(0, 0);

    cout << answer;   
    return 0;
}