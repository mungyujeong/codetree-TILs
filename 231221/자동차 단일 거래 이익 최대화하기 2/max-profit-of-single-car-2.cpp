#include <iostream>
#include <vector>

using namespace std;

int answer = 0;
vector<int> v;

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        v.push_back(x);
    }

    for (int i = 0; i < v.size() - 1; i++) {
        for (int j = i + 1; j < v.size(); j++) {
            if (v[j] - v[i] < 0) continue;
            answer = max(answer, v[j] - v[i]);
        }
    }
    cout << answer;
    return 0;
}