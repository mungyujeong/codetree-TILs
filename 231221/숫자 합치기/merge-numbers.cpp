#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int n;
priority_queue<int> pq;

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        pq.push(-x);
    }

    int answer = 0;
    while (pq.size() != 1) {
        // cout << answer << endl;

        int a, b;
        a = -pq.top();
        pq.pop();
        b = -pq.top();
        pq.pop();

        answer += a + b;
        pq.push(-(a + b));
    }
    cout << answer;
    return 0;
}