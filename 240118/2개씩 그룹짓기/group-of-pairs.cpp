#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n;

int main() {
    cin >> n;
    vector<int> arr(2 * n);
    for (int i = 0; i < 2 * n; i++)
        cin >> arr[i];
    
    sort(arr.begin(), arr.end());
    cout << arr[2 * n - 1] + arr[2 * n - 2];
    return 0;
}