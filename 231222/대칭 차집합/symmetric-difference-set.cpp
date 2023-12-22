#include <iostream>
#include <unordered_set>

using namespace std;

int a, b;
unordered_set<int> set;

int main() {
    cin >> a >> b;
    for (int i = 0 ; i < a; i++) {
        int x;
        cin >> x;
        set.insert(x);
    }
    for (int i = 0; i < b; i++) {
        int x;
        cin >> x;
        set.insert(x);
    }
    cout << 2 * set.size() - a - b;
    return 0;
}