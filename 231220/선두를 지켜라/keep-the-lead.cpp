#include <iostream>

#define MAX_T 1000

using namespace std;

int n, m;
int a_dist[MAX_T + 1];
int b_dist[MAX_T + 1];

int main() {
    cin >> n >> m;

    int a_time = 1;
    for (int i = 0; i < n; i++) {
        int v, t;
        cin >> v >> t;

        while(t--) {
            a_dist[a_time] = a_dist[a_time - 1] + v;

            a_time++;
        }
    }

    int b_time = 1;
    for (int i = 0; i < m; i++) {
        int v, t;
        cin >> v >> t;

        while(t--) {
            b_dist[b_time] = b_dist[b_time - 1] + v;

            b_time++;
        }
    }

    int count[MAX_T] = {};

    for (int i = 1; i < b_time; i++) {
        if (a_dist[i] > b_dist[i]) count[i] = 1;
        else if (a_dist[i] < b_dist[i]) count[i] = 2;
        else count[i] = count[i-1];
    }


    int answer = 0;
    for (int i = 1; i < b_time - 1; i++) {
        if (count[i] == 0) continue;
        if (count[i] != count[i + 1]) answer++;
    }
    cout << answer;
    return 0;
}