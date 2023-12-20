#include <iostream>

#define MAX_N 100

using namespace std;

int n, k;
int answer = 0;
int sum[MAX_N];

int main() {
    cin >> n >> k;
    for (int i = 0; i < k; i++) {
        int start, end;
        cin >> start >> end;
        for (int j = start; j <= end; j++) {
            sum[j]++;
            answer = max(answer, sum[j]);
        }
    }

    cout << answer;
    return 0;
}