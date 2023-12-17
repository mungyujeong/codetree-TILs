#include <iostream>
#include <climits>

using namespace std;

int a, b, c;
int answer = INT_MIN;

int main() {
    cin >> a >> b >> c;
    
    for (int i = 0; i <= 1000; i++) {
        for (int j = 0; j <= 1000; j++) {
            int sum = a * i + b * j;
            if (sum <= c) {
                answer = max(answer, sum);
            }
        }
    }

    cout << answer;
    return 0;
}