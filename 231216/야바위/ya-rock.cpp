#include <iostream>

#define MAX_N 100

using namespace std;

int n;
int a[MAX_N];
int b[MAX_N];
int c[MAX_N];

int answer;

int main() {
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i] >> b[i] >> c[i];
    
    // i번 선택 시
    for (int i = 1; i <= 3; i++) {
        int score[4] = {0, };
        score[i] = 1;
        int count = 0;
        for (int j = 0; j < n; j++) {
            // a[j] b[j] 변경
            int tmp = score[a[j]];
            score[a[j]] = score[b[j]];
            score[b[j]] = tmp;

            // for (int t = 1; t <= 3; t++)
            //     cout << score[t] << " ";
            // cout << endl;
            // cout << endl;

            count += score[c[j]];
        }
        // cout << count << endl;
        
        answer = max(answer, count);
    }
    cout << answer;
    return 0;
}