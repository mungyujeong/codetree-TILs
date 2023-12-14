#include <iostream>

using namespace std;

#define MAX_N 100
int n, answer;
int arr[MAX_N];

int main() {
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    
    for (int i = 0; i < n - 2; i++) {
        for (int j = i + 1; j < n - 1; j++) {
            for (int k = j + 1; k < n; k++) {
                if (arr[i] <= arr[j] && arr[j] <= arr[k]) {
                    answer++;
                }
            }
        }
    }
    cout << answer;
    return 0;
}