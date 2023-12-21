#include <iostream>
#include <unordered_map>

using namespace std;

int n, m;
unordered_map<int, int> map;

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        map[x] += 1;
    }

    for (int i = 0; i < m; i++) {
        int x;
        cin >> x;
        cout << map[x] << " ";
    }
    return 0;
}