#include <iostream>
#include <vector>

using namespace std;

vector<int> v;
int n, k;

int main() {
    cin >> n >> k;
    for (int i = 0 ; i < n; i++) {
        int x;
        cin >> x;
        v.push_back(x);
    }

    int answer = 0;

    for (int i = v.size() - 1; i >= 0; i--) {
        answer += k / v[i];
        k %= v[i];
    }

    cout << answer;
    return 0;
}