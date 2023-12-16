#include <iostream>

#define MAX_N 1000

using namespace std;

int n, c, g, h;
int answer = 0;
int ta[MAX_N];
int tb[MAX_N];

int GetWork(int start, int end, int temp) {
    if (start > temp) return c;
    else if (start <= temp && temp <= end) return g;
    else return h;
}

int main() {
    cin >> n >> c >> g >> h;
    for (int i = 0; i < n; i++)
        cin >> ta[i] >> tb[i];
    
    for (int t = 0; t <= 1000; t++) {
        int sum = 0;
        for (int i = 0; i < n; i++) {
            int a = ta[i];
            int b = tb[i];
            sum += GetWork(a, b, t);
        }
        answer = max(answer, sum);
    }

    cout << answer;
    return 0;
}