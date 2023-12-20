#include <iostream>

#define MAX_T 1000000

using namespace std;

int n, m;
int pos_a[MAX_T + 1];
int pos_b[MAX_T + 1];

int main() {
    cin >> n >> m;

    int time_a = 1;
    for (int i = 0; i < n; i++) {
        int t;
        char d;
        cin >> t >> d;

        while(t--) {
            if (d == 'R')
                pos_a[time_a] = pos_a[time_a - 1] + 1;
            else 
                pos_a[time_a] = pos_a[time_a - 1] - 1;
            time_a++;
        }
    }

    for (int i = time_a; i < MAX_T; i++)
        pos_a[i] = pos_a[i - 1];

    int time_b = 1;
    for (int i = 0; i < m; i++) {
        int t;
        char d;
        cin >> t >> d;

        while(t--) {
            if (d == 'R') 
                pos_b[time_b] = pos_b[time_b - 1] + 1;
            else
                pos_b[time_b] = pos_b[time_b - 1] - 1;
            time_b++;
        }
    }

    for (int i = time_b; i < MAX_T; i++)
        pos_b[i] = pos_b[i - 1];


    int answer = 0;
    int limit = max(time_a, time_b);
    // for (int i = 2; i < limit; i++) {
    //     cout << pos_a[i] << "  ";
    //     // if (pos_a[i] == pos_b[i] && pos_a[i - 1] != pos_b[i - 1]){
    //     //     cout << i << endl;
    //     //     answer++;
    //     // }
    // }
    // cout << endl;
    // for (int i = 2; i < limit; i++) {
    //     cout << pos_b[i] << "   ";
    // }
    // cout << endl;

    for (int i = 2; i < limit; i++) {
        if (pos_a[i] == pos_b[i] && pos_a[i - 1] != pos_b[i - 1]){
            // cout << i << endl;

            answer++;
        }
    }
    // cout << endl;
    cout << answer;
    return 0;
}