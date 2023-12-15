#include <iostream>

#define MAX_N 100

using namespace std;

int n, answer;
int a[MAX_N];
int b[MAX_N];

int main() {
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i] >> b[i];
    
    for (int i = 0; i < n; i++) {
        int sum = 0;
        bool visited[1001] = {true, };
        for (int j = 0; j < n; j++) {
            if (i == j) continue;
            for (int t = a[j]; t < b[j]; t++) {
                if (visited[t]) continue;
                else {
                    sum++;
                    visited[t] = true;
                }
            }
        }

        answer = max(answer, sum);
    }
    cout << answer;
    return 0;
}