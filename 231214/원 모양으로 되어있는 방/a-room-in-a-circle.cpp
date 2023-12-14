#include <iostream>
#include <climits>

using namespace std;

#define MAX_N 1003

int n;
int arr[MAX_N];
int min_dist = INT_MAX;

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) 
        cin >> arr[i];
    
    for (int start = 0; start < n; start++) {
        int dist = 0;

        for (int i = 0; i < n; i++) {
            int dest = (start + i) % n;
            dist += i * arr[dest];
        }

        min_dist = min(min_dist, dist);
    }
    
    cout << min_dist;
    return 0;
}