#include <iostream>

#define MAX_N 50
#define MAX_D 1000

using namespace std;

int n, m, d, s, answer;

class Info1 {
public:
    int p, m, t;
    Info1(int p, int m, int t) {
        this->p = p;
        this->m = m;
        this->t = t;
    }
    Info1() {}
};

class Info2 {
public:
    int p, t;
    Info2(int p, int t) {
        this->p = p;
        this->t = t;
    }
    Info2() {}
};

Info1 info1[MAX_D];
Info2 info2[MAX_N];

int main() {
    cin >> n >> m >> d >> s;

    for (int i = 0; i < d; i++)  {
        int p, m, t;
        cin >> p >> m >> t;
        info1[i] = Info1(p, m, t);
    }
    
    for (int i = 0; i < s; i++) {
        int p, t;
        cin >> p >> t;
        info2[i] = Info2(p, t);
    }

    for (int i = 1; i <= m; i++) {
        
        int time[MAX_N + 1] = {};

        // 해당 치즈를 먹은 최소 시간 구하기
        for (int j = 0; j < d; j++) {
            if(info1[j].m != i) continue;

            int person = info1[j].p;
            if (time[person] == 0) {
                time[person] = info1[j].t;
            } else if (time[person] > info1[j].t) {
                time[person] = info1[j].t;
            }
        }

        bool possible = true;

        // 먹은 적이 없으면 time == 0
        // 먹은 적은 있지만 환자가 된 시간보다 늦을 경우
        for (int k = 0; k < s; k++) {
            int persion = info2[k].p;
            int s = info2[k].t;
            if (time[persion] >= s) possible = false;
            if (time[persion] == 0) possible = false;
        }

        int count = 0;
        if (possible) {
            for (int i = 1; i <= n; i++) {
                if (time[i] != 0)
                    count++;
            }
        }
        answer = max(answer, count);
    }
    
    cout << answer;
    return 0;
}