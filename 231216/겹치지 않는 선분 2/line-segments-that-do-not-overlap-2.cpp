#include <iostream>

#define MAX_N 100

using namespace std;

int n;
int x[MAX_N];
int y[MAX_N];

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) 
        cin >> x[i] >> y[i];

    int answer;

    for (int i = 0; i < n; i++) {
        bool cross = false;
        for (int j = 0; j < n; j++) {
            if (i == j) continue;
            
            if ((x[i] < x[j] && y[j] < y[i]) ||
                (x[j] < x[i] && y[i] < y[j])) {
                    cross = true;
                    break;
            }
        }
        if (!cross)
            answer++;
    }

    cout << answer;
    return 0;
}