#include <iostream>
#include <algorithm>

using namespace std;

int arr[3];

int main() {
    cin >> arr[0] >> arr[1] >> arr[2];
    sort(arr, arr + 3);
    int a = arr[0];
    int b = arr[1];
    int c = arr[2];

    if (a + 1 == b && b + 1 == c) cout << 0;
    else if (max(b - a, c - b) == 2) cout << 1;
    else {
        int diff = max(b - a - 1, c - b - 1);
        cout << diff;
    }
    return 0;
}