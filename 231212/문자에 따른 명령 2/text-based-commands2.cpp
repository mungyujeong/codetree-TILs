#include <iostream>
#include <string>

#define DIR_NUM 4

using namespace std;

string cmd;
// 동 남 서 북
int dx[DIR_NUM] = {0, 1, 0, -1};
int dy[DIR_NUM] = {1, 0, -1, 0};

int main() {
    cin >> cmd;
    int x = 0;
    int y =0;
    int d = {3};
    for (int i = 0 ; i < cmd.size(); i ++ ) {
        if (cmd[i] == 'L') {
            d = (d + 3) % 4;
        } else if(cmd[i] == 'R') {
            d = (d + 1) % 4;
        } else {
            x += dx[d];
            y += dy[d];
        }
    }

    cout << y << " " << x;
    return 0;
}