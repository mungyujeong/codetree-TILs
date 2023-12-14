#include <iostream>

using namespace std;

#define MAX_N 20

int n;
int arr[MAX_N][MAX_N];
int max_coin;

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) 
        for (int j = 0; j < n; j++)
            cin >> arr[i][j];
    
    for (int i = 0; i < n; i++) 
        for (int j = 0; j < n - 2; j++) 
            max_coin = max(max_coin, arr[i][j] + arr[i][j + 1] + arr[i][j + 2]);

    cout << max_coin;
    return 0;
}