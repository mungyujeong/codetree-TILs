#include <iostream>

#define MAX_T 1000000

using namespace std;

int n, m;
int arr_a[MAX_T + 1];
int arr_b[MAX_T + 1];
int cnt[MAX_T + 1];
int answer;

int main() {
    cin >> n >> m;

    int time_a = 1;
    for (int i = 0; i < n; i++) {
        int v, t;
        cin >> v >> t;

        while(t--) {
            arr_a[time_a] = arr_a[time_a - 1] + v;
            time_a++;
        }
    }

    int time_b = 1;
    for (int i = 0; i < n; i++) {
        int v, t;
        cin >> v >> t;

        while(t--) {
            arr_b[time_b] = arr_b[time_b - 1] + v;
            time_b++;
        }
    }

    // for (int i = 1; i < time_a; i++) {
    //     cout << arr_a[i] << " ";
    // }
    // cout << endl;

    // for (int i = 1; i < time_b; i++) {
    //     cout << arr_b[i] << " ";
    // }
    // cout << endl;

    for (int i = 1; i < time_b; i++) {
        if (arr_a[i] > arr_b[i]) cnt[i] = 1;
        else if (arr_a[i] < arr_b[i]) cnt[i] = 2;
        else cnt[i] = 3;
        // cout << cnt[i] << " ";
    }
    // cout << endl;

    for (int i = 1; i < time_b; i++) {
        if (cnt[i] != cnt[i - 1]) answer++;
    }

    cout << answer;
    return 0;
}