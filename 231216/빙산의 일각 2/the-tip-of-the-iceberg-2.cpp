#include <iostream>

#define MAX_N 100

using namespace std;

int n, answer = 0;
int height[MAX_N];


int main() {
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> height[i];
    
    for (int i = 0; i <= 1000; i++) {

        int tmp[MAX_N];
        for (int h = 0; h < n; h++)
            tmp[h] = height[h];

        for (int j = 0; j < n; j++) {
            tmp[j] -= i;
            // cout << tmp[j] << " ";
        }
        // cout << endl;

        int cnt = 0;
        int ice = 0;
        for (int k = 0; k < n; k++) {
            if (tmp[k] > 0) cnt++;
            else if (cnt > 0) {
                ice++;
                cnt = 0;
            }
        }
        if (cnt > 0) ice++;
        // cout << ice << endl;
        answer = max(answer, ice);
    }
    cout << answer;
    return 0;
}