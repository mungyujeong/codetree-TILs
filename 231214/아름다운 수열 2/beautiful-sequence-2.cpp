#include <iostream>

#define MAX_N 100

using namespace std;

int n, m, count, answer;
int a[MAX_N];
int b[MAX_N];

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) 
        cin >> a[i];
    for (int i = 0; i < n; i++) 
        cin >> b[i];

    if (n < m) {
        cout << 0;
        return 0;
    } 

    
    
    for (int i = 0; i <= n - m; i++) {
        int visited[MAX_N] = {0, };
        count = 0;
        for (int j = i; j < i + m; j++) {
            for (int k = 0; k < m; k++) {
                if (a[j] == b[k] && visited[k] == 0) {
                    visited[k] = 1;
                    count++;
                }
            }
            // cout << "j: " << j << " count: " << count << endl;
            // for (int k = 0; k < m; k++) {
            //     cout << visited[k] << " ";
            // }
            // cout << endl;
        }
        if (count == m) answer++;
    }

    cout << answer;
    return 0;
}