#include <iostream>
#include <climits>

using namespace std;

#define MAX_N 100

int n;
int arr[MAX_N];

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) 
        cin >> arr[i];
    
    int min_dist = INT_MAX;

    for (int p = 0; p < n; p++) {
        int dist = 0;
        for (int j = 0; j < n; j++) {
            if (p != j) {
                dist += arr[j] * abs(p - j);
            }
        }
        if (min_dist > dist) {
            min_dist = dist;
        }
    }

    cout << min_dist;

    return 0;
}