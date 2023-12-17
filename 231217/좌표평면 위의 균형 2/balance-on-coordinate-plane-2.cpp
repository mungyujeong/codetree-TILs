#include <iostream>
#include <climits>

#define MAX_N 100
#define MAX_X 100

using namespace std;

int n, m = INT_MAX;
int x[MAX_N];
int y[MAX_N];

int main() {
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> x[i] >> y[i];
    
    for (int i = 2; i <= MAX_X; i+=2) {
        for (int j = 2; j <= MAX_X; j+=2) {
            int grid[4] = {0, 0, 0, 0};

            for (int k = 0; k < n; k++) {
                if (x[k] > i && y[k] > j){
                    grid[0]++;
                } else if (x[k] < i && y[k] > j) {
                    grid[1]++;
                } else if (x[k] < i && y[k] < j ){
                    grid[2]++;
                } else {
                    grid[3]++;
                }
            }
            int count = 0;
            for (int k = 0; k < 4; k++)
                count = max(count, grid[k]);
            
            m = min(m, count);
        }
    }
    cout << m;
    return 0;
}