#include <iostream>

using namespace std;

string n;
int num[10];

int main() {
    cin >> n;
    int sum = 0;
    for (int i = 0; i < (int) n.size(); i++) {
        sum = sum * 2 + n[i] - '0';
        // cout << sum << endl;
    }
    sum *= 17;

    int cnt = 0;
    while (true) {
        if (sum < 2) {
            num[cnt] = sum;
            break;
        }

        num[cnt++] = sum % 2;
        sum /= 2;
    }

    for (int i = cnt; i >= 0; i--)
        cout << num[i];

    return 0;
}