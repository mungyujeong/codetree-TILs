#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int n;

int main() {
    cin >> n;
    vector<string> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < v.size(); i++)
        cout << v[i] << '\n';
    return 0;
}