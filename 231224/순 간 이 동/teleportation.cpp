#include <iostream>
#include <climits>
using namespace std;

int main() {
    int a, b, x, y;
    cin >> a >> b >> x >> y;
    int answer = INT_MAX;
    answer = min(answer, abs(b - a));
    answer = min(answer, abs(x - a) + abs(y - b));
    answer = min(answer, abs(y - a) + abs(x - b));
    cout << answer;
    return 0;
}