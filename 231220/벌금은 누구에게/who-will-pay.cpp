#include <iostream>

#define MAX_N 100

using namespace std;

int n, m, k;
int arr[MAX_N];
int answer = -1;

int main() {
    cin >> n >> m >> k;
    for (int i = 0; i < m; i++) {
        int penalty;
        cin >> penalty;
        arr[penalty]++;
        if (arr[penalty] == k) {
            if (answer == -1) 
                answer = penalty;
        }
    }

    cout << answer;
    return 0;
}