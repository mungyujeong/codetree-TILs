#include <iostream>

#define MAX_N 1000
#define OFFSET 10000

using namespace std;

int n;
int arr[2 * OFFSET + 1] = {};
int curr_x = OFFSET; 

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x; char cmd;
        cin >> x >> cmd;

        if (cmd == 'L') {
            while (x--) {
                arr[curr_x--] = 1;
            }
            curr_x += 1;
        } else {
            while (x--) {
                arr[curr_x++] = 2;
            }
            curr_x -= 1;
        }
    //     cout << curr_x << " ";

    //         for (int i = OFFSET - 10; i < OFFSET + 10; i++) {
    //             cout << arr[i] << " ";
    // }   
    }
    // cout << endl;
    int w = 0;
    int b = 0;
    for (int i = 0; i < 2 * OFFSET + 1; i++) {
        if (arr[i] == 1) w++;
        else if (arr[i] == 2) b++;
    }
    cout << w << " " << b;
    return 0;
}