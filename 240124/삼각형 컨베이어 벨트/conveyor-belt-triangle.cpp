#include <iostream>

#define MAX_N 200

using namespace std;

int n, t;
int arr[MAX_N][3];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> t;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < 3; j++)
            cin >> arr[i][j];
    
    while (t--) {
        int tmp[3] = {};
        for (int i = 0; i < 3; i++) {
            tmp[i] = arr[i][n - 1];
        
            for (int j = n - 1; j >= 1; j--)
                arr[i][j] = arr[i][j - 1];
        }

        for (int i = 0; i < 3; i++)
            arr[i][0] = tmp[(i + 2) % 3];
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 3; j++)
            cout << arr[i][j] << ' ';
        cout << endl;
    }
}