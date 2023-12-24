#include <iostream>
#include <queue>

#define MAX_N 100

using namespace std;

priority_queue<int> pq;
int n;
int origin[MAX_N];

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        origin[i] = x;
        pq.push(-x);
    }

    int smallest = -pq.top();
    pq.pop();
    // cout << smallest << endl;
    // while (-pq.top() == smallest) {
    //     pq.pop();
    // }

    for (int i = 0; i < n - 1; i++) {
        if (-pq.top() == smallest) pq.pop();
        else break;
    }

    if (pq.empty()) {
        cout << -1;
        return 0;
    }

    int second = -pq.top();
    pq.pop();

    if (-pq.top() == second) {
        cout << -1;
        return 0;
    } else {
        for (int i = 0; i < n; i++) {
            if (origin[i] == second) {
                cout << i + 1;
                return 0;
            }
        }
    }
    return 0;
}