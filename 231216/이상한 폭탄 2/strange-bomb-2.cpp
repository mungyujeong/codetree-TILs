#include <iostream>

#define MAX_N 100

using namespace std;

int n, k, answer = -1;
int arr[MAX_N];

int main() {
    cin >> n >> k;
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] == arr[j] && j - i <= k)
                answer = max(answer, arr[i]); 
        }
    }
    cout << answer;
    return 0;
}