#include <iostream>
#include <algorithm>

#define MAX_N 1'000

using namespace std;

int n;
int arr[MAX_N];
int sorted[MAX_N];
int visited[MAX_N];

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        sorted[i] = arr[i];
    }
    sort(sorted, sorted + n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (visited[j]) continue;
            if (arr[i] == sorted[j]) {
                visited[j] = 1;
                cout << j + 1 << ' ';
                break;
            }
        }
    }    
    return 0;
}