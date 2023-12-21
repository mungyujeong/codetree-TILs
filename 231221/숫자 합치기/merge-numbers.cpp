#include <iostream>
#include <deque>
#include <algorithm>

using namespace std;

int n;
deque<int> q;

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        q.push_back(x);
    }

    int answer = 0;
    while (q.size() != 1) {
        // cout << answer << endl;
        sort(q.begin(), q.end());

        int a, b;
        a = q[0];
        b = q[1];
        answer += a + b;
        q.pop_front();
        q.pop_front();
        q.push_back(a + b);
    }
    cout << answer;
    return 0;
}