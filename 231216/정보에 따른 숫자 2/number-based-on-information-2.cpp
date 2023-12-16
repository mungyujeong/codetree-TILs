#include <iostream>
#include <climits>

#define MAX_T 100

using namespace std;

int t, a, b, answer;
char alpha[MAX_T];
int dist[MAX_T];

int main() {
    cin >> t >> a >> b;
    for (int i = 0; i < t; i++) 
        cin >> alpha[i] >> dist[i];
    
    for (int x = a; x <= b; x++) {
        int minS = INT_MAX;
        int minN = INT_MAX;

        for (int i = 0; i < t; i++) {
            if (alpha[i] == 'N') {
                minN = min(minN, abs(dist[i] - x));
            } else {
                minS = min(minS, abs(dist[i] - x));
            }
        }

        if (minN >= minS) answer++;
    }
    cout << answer;
    return 0;
}