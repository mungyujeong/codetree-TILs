#include <iostream>

using namespace std;

int n;
int cnt_a = 0;
int cnt_b = 0;

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        if (a == b) continue;
        else if ((a + 1) % 3 + 1 == b) cnt_a++;
        else cnt_b++;
    }
    cout << max(cnt_a, cnt_b);
    return 0;
}