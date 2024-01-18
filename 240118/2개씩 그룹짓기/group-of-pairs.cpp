#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n;

int main() {
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    
    sort(arr.begin(), arr.end());
    cout << arr[n - 1] + arr[n - 2];
    return 0;
}