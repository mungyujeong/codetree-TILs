#include <iostream>

#define MAX_P 10000

using namespace std;

int n, k, num;
char word;
int position[MAX_P + 1];

int main() {
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> num >> word;
        if (word == 'G') {
            position[num] = 1;
        } else if (word == 'H'){
            position[num] = 2;
        }
    }

    int max_score = 0;
    for (int i = 0; i <= MAX_P - k; i++) {
        int sum = 0;
        for (int j = i; j <= i + k; j++) 
            sum += position[j];
        if(sum == 72) {
            cout << i << endl;

            for (int j = i; j <= i + k; j++) {
                cout << j << " ";
                cout <<position[j] << " ";
            }
            cout << endl;
        }
        max_score = max(max_score, sum);
    }

    cout << max_score;

    return 0;
}