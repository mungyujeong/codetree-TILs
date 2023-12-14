#include <iostream>
#include <climits>

#define MAX_P 10001

using namespace std;

int n, k, num, max_x;
char word;
int position[MAX_P];

int main() {
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> num >> word;
        if (word == 'G') {
            position[num] = 1;
        } else if (word == 'H'){
            position[num] = 2;
        }
        max_x = max(max_x, num);
    }

    int max_score = INT_MIN;
    if (k > max_x) k = max_x;
    for (int i = 1; i <= max_x - k; i++) {
        int sum = 0;
        for (int j = i; j < i + k + 1; j++) {
            if(position[j] > 0) {
                sum += position[j];
            }
        }
        max_score = max(max_score, sum);
    }

    cout << max_score;

    return 0;
}