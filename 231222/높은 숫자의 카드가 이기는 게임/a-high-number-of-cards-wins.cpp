#include <iostream>
#include <climits>
#include <vector>
#include <algorithm>

#define MAX_N 50000

using namespace std;

int n;
int answer = 0;
vector<int> a;
vector<int> b;
int arr[50001] = {};

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        b.push_back(x);
        arr[x] = 1;
    }
    sort(b.begin(), b.end());
    for (int i = 1; i <= 2 * n; i++) {
        if (arr[i] == 0) a.push_back(i);
    }

    sort(a.begin(), a.end());

    // for (int i = 0; i < n; i++) {
    //     cout << b[i] << " ";
    // }
    // cout << endl;
    for (int i = 0; i < n; i++) {
        if (a[i] < b[i]) {
            int origin = a[i];
            for (int j = i; j < n; j++) {
                if (j == i) continue;
                if (a[j] > b[i]) {
                    swap(a[i], a[j]);
                    break;
                }
            }
            if (origin == a[i]) break;
        }
        answer++;
    }

    // int idx = 0;
    // while (idx != n) {
    //     if (a[idx] < b[idx]) {
    //         swap(a[idx], a[idx + 1]);
    //         continue;
    //     } else {
    //         answer++;
    //         idx++;
    //     }
    // }
    // cout << endl;

    cout << answer;
    return 0;
}