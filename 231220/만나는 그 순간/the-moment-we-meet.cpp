#include <iostream>

#define MAX_T 1000

using namespace std;

int n, m;
int t;
char d;
int a[MAX_T + 2];
int b[MAX_T + 2];
int a_curr_x = 0;
int b_curr_x = 0;
int tmp_time = 0;

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> d >> t;

        if (d == 'R') {
            for (int j = tmp_time; j < tmp_time + t; j++) {
                a[j + 1] = ++a_curr_x;
            }
        } else {
            for (int j = tmp_time; j < tmp_time + t; j++) {
                a[j + 1] = --a_curr_x;
            }
        }
        tmp_time += t;
    }
    // for (int i = 0; i < MAX_T; i++) {
    //     cout << a[i] << " ";
    // }
    // cout << endl;
    tmp_time = 0;
    for (int i = 0; i < m; i++) {
        cin >> d >> t;  
        if (d == 'R') {
            for (int j = tmp_time; j < tmp_time + t; j++) {
                b[j + 1] = ++b_curr_x;
            }
        } else {
            for (int j = tmp_time; j < tmp_time + t; j++) {
                b[j + 1] = --b_curr_x;
            }
        }
        tmp_time += t;
    }

    int answer = -1;
    for (int i = 0; i < MAX_T; i++) {
        // cout << b[i] << " ";
        if (a[i] == b[i] && a[i] != 0) {
            answer = i + 1;
            break;
        }
    }
    if (answer == -1) cout << answer;
    else cout << answer - 1;
    return 0;
}