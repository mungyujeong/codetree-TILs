#include <iostream>

using namespace std;

int n, t, p, dp[21];
int work_time[16];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> t >> p;
        work_time[i] = t;

        // 만약 외주기간이 휴가기간을 넘어가면 continue
        if (t + i - 1 > n) continue;

        // 만약 dp[i]에 아무값도 없다면? 
        // dp[i] = dp[i - 1] + p 
        if (dp[i] == 0) {
            for (int j = i; j < i + t; j++) {
                dp[j] = dp[i - 1] + p;
            }
        }

        // 만약 dp[i] 값이 있다면?
        // 이전 날들의 끝날(i_x + t_x)이 자신(i)보다 작을 때까지 찾기
        // 그 날짜의 외주값(dp[i_x]) + p 값이 dp[i]보다 크면 갱신
        // 그 날짜가 없으면 p 값만 dp[i]와 비교
        else {
            int idx = 0;
            for (int j = i - 1; j >= 1; j--) {
                // cout << i << ' ' << work_time[j] + j - 1 << ' ' << j << endl;
                // 끝나는 날짜가 현재 날짜보다 작으면 idx 저장
                if (work_time[j] + j - 1 < i) {
                    idx = j;
                    break;
                }
            }
            // cout << "idx: " << idx << endl;

            // 현재 날짜부터 현재 외주작업이 끝날때까지 update
            // 기존 dp값과 현재 외주작업 가격 + 이전 외주작업 dp값 비교
            if (dp[i] >= p + dp[idx])
                for (int j = i; j < i + t; j++) 
                    dp[j] = dp[i];
            else
                for (int j = i; j < i + t; j++)
                    dp[j] = p + dp[idx];
        }
        // for (int i = 0; i <= n; i++)
        //     cout << dp[i] << ' ';
        // cout << endl;
    }


    cout << dp[n];
    return 0;
}