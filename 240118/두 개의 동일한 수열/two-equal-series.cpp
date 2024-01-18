#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n;

int main() {
    cin >> n;
    vector<int> a(n);
    vector<int> b(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        cin >> b[i];
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    for (int i = 0; i < n; i++) {
        if (a[i] != b[i]) {
            cout << "No";
            return 0;
        }
    }
    cout << "Yes";
    return 0;
}