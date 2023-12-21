#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

int n;
unordered_map<string, int> m;
vector<string> v;

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        string key;
        cin >> key;
        m[key] += 1;
        v.push_back(key);
    }
    int answer = 0;
    for (auto k : v) {
        answer = max(answer, m[k]);
    }
    cout << answer;
    return 0;
}