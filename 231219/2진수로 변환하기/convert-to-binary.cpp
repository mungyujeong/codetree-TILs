#include <iostream>

using namespace std;

int n;

int main() {
    cin >> n;
    int lst[20] = {};
    int cnt = 0;
    while(true) {
        if (n < 2) {
            lst[cnt] = n;
            break;
        }

        lst[cnt++] = n % 2;
        n /= 2;
    }
    for (int i = cnt; i >= 0; i--) {
        cout << lst[i];
    }
    return 0;
}