#include <iostream>

#define MAX_N 100

using namespace std;

int n, max_size;
char arr[MAX_N + 1];

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x; char alpha;
        cin >> x >> alpha;
        arr[x] = alpha;
    }

    for (int i = 0; i < MAX_N; i++) {
        for (int j = i; j < MAX_N + 1; j++) {
            int g_cnt = 0, h_cnt = 0, min_index = MAX_N, max_index = 0;
            for (int k = i; k <= j; k++) {
                if (arr[k] == 'G') g_cnt++;
                else if (arr[k] == 'H') h_cnt++;

                if (arr[k] == 'G' || arr[k] == 'H') {
                    min_index = min(min_index, k);
                    max_index = max(max_index, k);
                }
            }
            if (g_cnt + h_cnt <= 1) continue;
            if (g_cnt == h_cnt || g_cnt == 0 || h_cnt == 0) {
                max_size = max(max_size, max_index - min_index);
            }
        }
    }
    
    cout << max_size;
    return 0;
}