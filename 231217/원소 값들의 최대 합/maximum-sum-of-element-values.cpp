#include <iostream>
#include <climits>

#define MAX_N 100

using namespace std;

int n, m, answer = INT_MIN;
int arr[MAX_N + 1];

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) 
        cin >> arr[i];
        
    
    for (int start = 1; start <= n; start++) {
        int index = start;
        int sum = 0;
        int time = m;

        while (time--) {
            int value = arr[index];
            sum += value;
            index = value;
        }
        answer = max(answer, sum);
    } 
    cout << answer;
    return 0;
}