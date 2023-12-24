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

    if (c == b + 1 && b == a + 1) cout << 0;
    else if (a + 2 == b || b + 2 == c) cout << 1;
    else cout << 2;
    return 0;
}