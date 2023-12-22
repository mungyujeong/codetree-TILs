#include <iostream>
#include <unordered_set>
#include <vector>
#include <tuple>

#define MAX_N 100000

using namespace std;

int n, k;
unordered_set<int> set[MAX_N + 1];
vector<pair<int, int>> v;
int arr[MAX_N + 1];

int main() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        arr[i] = i;
        set[i].insert(i);
    }

    for (int i = 0; i < k; i++) {
        int a, b;
        cin >> a >> b;
        v.push_back({a, b});
    }
    int count = 3;
    while (count--) {
        for (int i = 0; i < k; i++) {
            int a, b;
            tie(a, b) = v[i];
            set[arr[a]].insert(b);
            set[arr[b]].insert(a);
            swap(arr[a], arr[b]);
        }
    }

    for (int i = 1; i <= n; i++) {
        cout << set[i].size() << endl;
    }
    return 0;
}