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
        int count = start;
        int sum = 0;
        int time = m;

        int tmp[MAX_N];
        for (int i = 1; i <= n; i++)
            tmp[i] = arr[i];

        while (time--) {
            int value = tmp[start];
            // cout << value << endl;
            sum += value;
            swap(tmp[start], tmp[value]);
        }
        answer = max(answer, sum);
        // cout << "end" << endl;
    } 
    cout << answer;
    return 0;
}