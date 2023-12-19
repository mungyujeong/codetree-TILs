#include <iostream>
#define MAX_N 9
using namespace std;

int a, b;
string n;

int main() {
    cin >> a >> b;
    cin >> n;

    int sum = 0;
    for (int i = 0; i < (int) n.length(); i++) {
        sum = sum * a + (n[i] - '0');
    }

    int digits[MAX_N];
    int cnt = 0;
    while(true) {
        if (sum < b) {
            digits[cnt] = sum;
            break;
        }

        digits[cnt++] = sum % b;
        sum /= b;
    }

    for (int i = cnt; i >= 0; i--) {
        cout << digits[i];
    }
    return 0;
}