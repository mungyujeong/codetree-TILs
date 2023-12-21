#include <iostream>
#include <climits>

using namespace std;

int n;
int answer = INT_MAX;

int main() {
    cin >> n;

    for (int i = 0; i <= 100000; i++) {
        int tmp = n - 5  * i;
        if (tmp >= 0 && tmp % 2 == 0) 
            answer = min(answer, i + (tmp / 2));
    }


    if (answer == INT_MAX) cout << -1;
    else cout << answer;

    return 0;
}