#include <iostream>
#include <unordered_set>

using namespace std;

unordered_set<long long> set;
int n;

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        set.insert(x);
    }
    cout << set.size() << endl;
    return 0;
}