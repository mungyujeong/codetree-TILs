#include <iostream>
#include <vector>

#define MAX_N 100

using namespace std;

int n;
int arr[MAX_N];

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) 
        cin >> arr[i];
    
    for (int i = 0; i < 2; i++) {
        int s, e;
        cin >> s >> e;
        s--; e--;

        int tmp[MAX_N] = {};  
        int tmp_idx = 0;
        for (int i = 0; i < n; i++) {
            if (s <= i && i <= e) continue;
            tmp[tmp_idx++] = arr[i];
        }

        for (int i = 0; i < tmp_idx; i++)
            arr[i] = tmp[i];
        
        n = tmp_idx;
    }

    cout << n << '\n';
    for (int i = 0; i < n; i++)
        cout << arr[i] << '\n';
}