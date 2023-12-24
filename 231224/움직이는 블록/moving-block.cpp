#include <iostream>

#define MAX_N 10000

using namespace std;

int n;
int arr[MAX_N];
int avg;

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        avg += arr[i];
    }

    avg /= n;
    int answer = 0;
    for (int i = 0; i < n; i++) {
        if (avg - arr[i] > 0)
            answer += avg - arr[i];
    }

    cout << answer;
    return 0;
}