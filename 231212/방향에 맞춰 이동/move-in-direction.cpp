#include <iostream>

using namespace std;

int main() {
    int x = 0;
    int y = 0;

    int dx[4] = {0, -1, 1, 0};
    int dy[4] = {-1, 0, 0, 1};
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        char d;
        int distance;
        cin >> d >> distance;
        if (d == 'W') {
            x += dx[0] * distance;
            y += dy[0] * distance;
        } else if (d == 'S') {
            x += dx[1] * distance;
            y += dy[1] * distance;
        } else if (d == 'N') {
            x += dx[2] * distance;
            y += dy[2] * distance;
        } else if (d == 'E') {
            x += dx[3] * distance;
            y += dy[3] * distance;
        }
    }

    cout << y << " " << x << endl;
    return 0;
}