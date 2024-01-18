#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, k, sz;
string t;
vector<string> v;

int main() {
    cin >> n >> k >> t;
    sz = t.size();
    for (int i = 0; i < n; i++) {
        string str;
        cin >> str;
        if (t.compare(str.substr(0, sz)) == 0) 
            v.push_back(str);
    }

    sort(v.begin(), v.end());
    cout << v[k - 1];
    return 0;
}