#include <iostream>
#include <climits>

#define MAX_N 100

using namespace std;

int n;
int answer = INT_MAX;
int x[MAX_N];
int y[MAX_N];

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) 
        cin >> x[i] >> y[i];
    
    
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int dist = (x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]);
            answer = min(answer, dist);
        }
    }

    cout << answer;
    return 0;
}