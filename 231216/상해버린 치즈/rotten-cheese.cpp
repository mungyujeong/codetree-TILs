#include <iostream>

#define MAX_N 50

using namespace std;

int n, m, d, s;
int dArr[MAX_N][3];
int sArr[MAX_N][2];
int cheeze[MAX_N] = {0, };
int candidate[MAX_N] = {0, };


// 아픈 사람들 중 dm을 먹은 사람들을 찾고
// 먹었던 시간이 st보다 작으면 true
int findWhoEat() {
    for (int i = 0; i < s; i++) {
        // 환자 선택
        int sp = sArr[i][0]; 
        int st = sArr[i][1];

        // sp가 먹었던 치즈 찾기
        for (int j = 0; j < d; j++) {
            int dp = dArr[j][0];
            int dm = dArr[j][1];
            int dt = dArr[j][2];

            if (sp != dp) continue;
            
            // 먹었던 시간이 아팠던 시간 전이라면
            if (dt < st) {
                if (candidate[dm] == 1) {
                    return dm;
                }
                candidate[dm] = 1;
            }
        }
    }
}

int main() {
    cin >> n >> m >> d >> s;
    for (int i = 0; i < d; i++) 
        cin >> dArr[i][0] >> dArr[i][1] >> dArr[i][2];
    for (int i = 0; i < s; i++)
        cin >> sArr[i][0] >> sArr[i][1];

    int apple = findWhoEat();
    // cout << apple << endl;

    int answer = 0;
    int p[MAX_N] = {0, };
    for (int i = 0; i < d; i++) {
        int dp = dArr[i][0];
        int dm = dArr[i][1];
        if (dm == apple) {
            p[dp] = 1;
        }
    }
    for (int i = 0; i < MAX_N; i++)
        answer += p[i];
    cout << answer;
    return 0;
}