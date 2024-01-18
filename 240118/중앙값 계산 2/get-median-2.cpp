#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n;
vector<int> v;

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        v.push_back(x);
        
        if (i % 2 != 0) {
            sort(v.begin(), v.end());
            cout << v[v.size() / 2] << ' ';    
        }
    }
    return 0;
}