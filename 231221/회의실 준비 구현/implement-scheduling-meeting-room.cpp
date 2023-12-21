#include <iostream>
#include <queue>
#include <algorithm>
#include <tuple>

using namespace std;

int n;
priority_queue<pair<int, int>> pq;

int main() {
    cin >> n;
    for (int i = 0 ; i < n; i ++) {
        int s, e;
        cin >> s >> e;
        pq.push({-e, -s});
    }

    int answer = 1;
    int end = -pq.top().first;
    pq.pop();
    for (int i = 1; i < n; i++) {
        int e, s;
        tie(e, s) = pq.top();
        e = -e; s = -s;
        pq.pop();
        if (s >= end) {
            answer += 1;
            end = e;
        }       
    }   

    cout << answer;
    return 0;
}