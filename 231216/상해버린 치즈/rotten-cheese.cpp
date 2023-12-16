#include <iostream>

#define MAX_N 50

using namespace std;

int n, m, d, s;
int dArr[MAX_N][3];
int sArr[MAX_N][2];
int cheeze[MAX_N];

int main() {
    cin >> n >> m >> d >> s;
    for (int i = 0; i < d; i++) 
        cin >> dArr[i][0] >> dArr[i][1] >> dArr[i][2];
    for (int i = 0; i < s; i++)
        cin >> sArr[i][0] >> sArr[i][1];
    
    for (int i = 0; i < s; i++) {
        // cout << sArr[i][0] << " " << sArr[i][1] << endl;
        int sp = sArr[i][0]; 
        int st = sArr[i][1];

        // sp가 먹었던 치즈 찾기
        for (int j = 0; j < d; j++) {
            int dp = dArr[j][0];
            int dm = dArr[j][1];
            int dt = dArr[j][2];

            if (sp != dp) continue;
            
            // 먹었던 시간이 아팠던 시간 전이라면
            if (dt <= st) {
                // dm을 먹은 사람들 찾기
                for (int k = 0; k < d; k++) {
                    if (dArr[k][1] == dm) {
                        cheeze[dArr[k][0]] = 1;
                    }
                }
            }
        }
    }

    int answer = 0;
    for (int i = 1; i <= n; i++) {
        // cout << cheeze[i] << " ";
        if (cheeze[i] == 1) 
            answer++;
    }
    // cout << endl;
    cout << answer;
    return 0;
}