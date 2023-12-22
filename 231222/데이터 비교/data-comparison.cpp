#include <iostream>
#include <unordered_set>

#define MAX_N 100000

using namespace std;

unordered_set<long long> set1;
unordered_set<long long> set2;
long long arr[MAX_N];
int n, m;

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        set1.insert(x);
    }
    cin >> m;
    for (int i = 0; i < m; i++) {
        cin >> arr[i];
        set2.insert(arr[i]);
    }

    for (int i = 0; i < m; i++) {
        if (set1.find(arr[i]) == set1.end()) {
            cout << 0 << " ";
        } else {
            cout << 1 << " ";
        }
    }
    return 0;
}