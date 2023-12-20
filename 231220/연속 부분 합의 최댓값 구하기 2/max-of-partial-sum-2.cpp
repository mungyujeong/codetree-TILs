#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int n;
vector<int> v;

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        v.push_back(x);
    }

    int sum = 0;
    int answer = INT_MIN;
    for (auto i : v) {
        sum += i;
        answer = max(answer, sum);
        if (sum < 0) sum = 0;
    }

    cout << answer;
    return 0;
}