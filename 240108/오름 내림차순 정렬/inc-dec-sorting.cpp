#include <iostream>
#include <algorithm>
#include <functional>

#define MAX_N 100

using namespace std;

int n;
int arr[MAX_N];

int main() {
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    sort(arr, arr + n);
    for (int i = 0; i < n; i++)
        cout << arr[i] << ' ';
    cout << '\n';
    sort(arr, arr + n, greater<int>());
    for (int i = 0; i < n; i++)
        cout << arr[i] << ' ';
    cout << '\n';
    return 0;
}