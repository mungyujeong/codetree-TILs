#include <iostream>

#define MAX_N 100

using namespace std;

int n, answer = 0;
int arr[MAX_N];

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) 
        cin >> arr[i];

    for (int k = 0; k <= 100; k++) {
        int count = 0;
        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                int ai = arr[i];
                int aj = arr[j];
                if (aj - k == k - ai) {
                    count++;
                }
            }
        }
        answer = max(answer, count);
    }
    cout << answer;
    return 0;
}