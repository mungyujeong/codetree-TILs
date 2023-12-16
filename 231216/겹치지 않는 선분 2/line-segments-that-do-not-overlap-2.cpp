#include <iostream>

#define MAX_N 100

using namespace std;

int n, answer;
int x1[MAX_N];
int x2[MAX_N];
int crossed[MAX_N];

int main() {
    cin >> n;
    answer = n;
    for (int i = 0; i < n; i++)
        cin >> x1[i] >> x2[i];
    
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            int fx1 = x1[i];
            int fx2 = x2[i];
            int sx1 = x1[j];
            int sx2 = x2[j];

            // 기울기가 같으면 pass
            if (sx2 - sx1 == fx2 - fx1) continue;
            // 둘다 부호가 양수일 경우
            if ((sx2 - sx1 > 0) && (fx2 - fx1 > 0)) {
                if (((fx1 < sx1 && sx1 < fx2) && (fx1 < sx2 && sx2 < fx2)) ||
                    ((sx1 < fx1 && fx1 < sx2) && (sx1 < fx2 && fx2 < sx2))) {
                    crossed[i] = 1;
                    crossed[j] = 1;
                }
            } // 부호가 둘다 음수일 경우 
            else if ((sx2 - sx1 < 0) && (fx2 - fx1 < 0)){
                if (((fx2 < sx2 && sx2 < fx1) && (fx2 < sx1 && sx1 < fx1)) ||
                    ((sx2 < fx2 && fx2 < sx1) && (sx2 < fx1 && fx1 < sx1))) {
                    crossed[i] = 1;
                    crossed[j] = 1;
                }
            } // 부호가 다를 경우 
            else if ((sx2 - sx1 < 0) && (fx2 - fx1 > 0)){
                if (((fx1 < sx2 && sx2 < fx2) && (sx2 < fx2 && fx2 < sx1)) ||
                    ((fx1 < sx2 && sx2 < fx2) && (fx1 < sx1 && sx1 < fx2)) ||
                    ((sx2 < fx1 && fx1 < sx1) && (sx2 < fx2 && fx2 < sx1)) ||
                    ((sx2 < fx1 && fx1 < sx1) && (fx1 < sx1 && sx1 < fx2))) {
                        crossed[i] = 1;
                        crossed[j] = 1;
                    }
            } else if ((sx2 - sx1 > 0) && (fx2 - fx1 < 0)){
                if (((sx1 < fx2 && fx2 < sx2) && (fx2 < sx2 && sx2 < fx1)) ||
                    ((sx1 < fx2 && fx2 < sx2) && (sx1 < fx1 && fx1 < sx2)) ||
                    ((fx2 < sx1 && sx1 < fx2) && (fx2 < sx2 && sx2 < fx1)) ||
                    ((fx2 < sx1 && sx1 < fx1) && (sx1 < fx1 && fx1 < sx2))) {
                        crossed[i] = 1;
                        crossed[j] = 1;
                }
            }
        }
    }
    for (int i = 0; i < n; i++) {
        // cout << crossed[i] << " ";
        if (crossed[i]) {
            answer--;
        }
    }
    // cout << endl;
    cout << answer;
    return 0;
}