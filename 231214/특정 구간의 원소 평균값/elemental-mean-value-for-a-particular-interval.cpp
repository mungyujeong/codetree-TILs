#include <iostream>

#define MAX_N 100

using namespace std;

int n, count;
int arr[MAX_N];

int main() {
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            double average = 0;
            for (int k = i; k <= j; k++) {
                average += arr[k];
            }
            average = average / (j - i + 1);

            for (int k = i; k <= j; k++) {
                if (average == arr[k]) {
                    count++;
                    break;
                }
            }
        }
    }
    cout << count;
    return 0;
}