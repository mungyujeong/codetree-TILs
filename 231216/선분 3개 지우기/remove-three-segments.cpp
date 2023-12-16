#include <iostream>

#define MAX_N 10

using namespace std;

int n, answer = 0;
int x[MAX_N];
int y[MAX_N];

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) 
        cin >> x[i] >> y[i];
    
    for (int i = 0; i < n - 2; i++) {
        for (int j = i + 1; j < n - 1; j++) {
            for (int k = j + 1; k < n; k++) {
                
                int tmp[101] = {0, };
                bool nested = false;
                for (int t = 0; t < n; t++) {
                    if (t == i || t == j || t == k) continue;

                    int a = x[t];
                    int b = y[t];
                    for (int u = a; u <= b; u++) {
                        if (tmp[u] == 1) {
                            nested = true;
                            break;
                        } else {
                            tmp[u] = 1;
                        }
                    }
                    if (nested) break;
                }
                if (!nested) answer++;
                
            }
        }
    }
    cout << answer;
    return 0;
}