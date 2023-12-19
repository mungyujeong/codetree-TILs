#include <iostream>

using namespace std;

int n;
int b;

int main() {
    cin >> n >> b;
    int lst[20] = {};
    int cnt = 0;
    while(true) {
        if (n < b) {
            lst[cnt] = n;
            break;
        }

        lst[cnt++] = n % b;
        n /= b;
    }
    for (int i = cnt; i >= 0; i--)
        cout << lst[i];
    return 0;
}