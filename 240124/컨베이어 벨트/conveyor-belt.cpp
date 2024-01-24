#include <iostream>
#include <deque>

#define MAX_N 200

using namespace std;

int n, t;
deque<int> belt[2];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> t;
    int x;
    for (int i = 0; i < n; i++) {
        cin >> x;
        belt[0].push_back(x);
    }   
    for (int i = 0; i < n; i++) {
        cin >> x;
        belt[1].push_back(x);
    }

    while (t--) {
        belt[0].push_front(belt[1].back());
        belt[1].pop_back();
        belt[1].push_front(belt[0].back());
        belt[0].pop_back();
    }

    for (int i = 0; i < n; i++)
        cout << belt[0][i] << ' ';
    cout << endl;
    for (int i = 0; i < n; i++)
        cout << belt[1][i] << ' ';
}