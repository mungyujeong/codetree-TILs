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
    int answer = 0;
    for (int i = 0; i < n; i++) 
        answer = max(answer, arr[i] + arr[2*n - i - 1]);
    cout << answer;
    return 0;
}