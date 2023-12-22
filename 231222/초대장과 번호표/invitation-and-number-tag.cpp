#include <iostream>
#include <unordered_set>
#include <vector>

#define MAX_N 100000
#define MAX_G 250000

using namespace std;

int n, g;
vector<int> group[MAX_G];
unordered_set<int> set;

int main() {
    set.insert(1);
    cin >> n >> g;
    for (int i = 0; i < g; i++) {
        int len;
        cin >> len;
        for (int j = 0; j < len; j++) {
            int x;
            cin >> x;
            group[i].push_back(x);
        }
    }

    for (int i = 0; i < g; i++) {

        int cnt = 0;
        int tmp = 0;

        for (auto j : group[i]) {
            if (set.find(j) != set.end()) {
                cnt++;
            } else {
                tmp = j;
            }
        }

        if (group[i].size() - 1 == cnt) {
            set.insert(tmp);
        }
    }

    cout << set.size();
    return 0;
}