#include <iostream>

#define MAX_N 20

using namespace std;

int k, n, answer = 0;
int arr[MAX_N][MAX_N];

int main() {
    cin >> k >> n;
    for (int i = 0; i < k; i++)
        for (int j = 0; j < n; j++)
            cin >> arr[i][j];
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {

            if (i == j) continue;

            bool isTrue = true;

            for (int t = 0; t < k; t++) {
                int index_j = 0;
                int index_i = 0;

                for (int q = 0; q < n; q++) {
                    if (i == arr[t][q]) {
                        index_i = q;
                    } else if (j == arr[t][q]) {
                        index_j = q;
                    }
                }

                if (index_i > index_j)
                    isTrue = false;
            }

            if (isTrue)
                answer++;
        }
    }

    cout << answer;
    return 0;
}