#include <iostream>

#define MAX_N 4

using namespace std;

int board[MAX_N][MAX_N];
char dir;

void gravity() {
    for (int i = 0; i < 4; i++) {
        int curr = -1;
        int curr_y = 0;
        for (int j = 0; j < 4; j++) {
            if (board[i][j] == 0) continue;
            if (board[i][j] == curr) {
                board[i][curr_y] = curr * 2;
                board[i][j] = 0;
                curr = -1;
            }
            else {
                curr = board[i][j];
                curr_y = j;
            }
        }
    }

    int tmp[MAX_N][MAX_N] = {};
    for (int i = 0; i < 4; i++) {
        int tmp_y = 0;
        for (int j = 0; j < 4; j++) {
            if (board[i][j] == 0) continue;
            tmp[i][tmp_y++] = board[i][j];
        }
    }
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
            board[i][j] = tmp[i][j];
}

void rotate(int times) {
    while (times--) {
        int tmp[MAX_N][MAX_N];
        for (int i = 0; i < 4; i++)
            for (int j = 0; j < 4; j++)
                tmp[i][j] = board[i][j];
        
        for (int i = 0; i < 4; i++) 
            for (int j = 0; j < 4; j++) 
                board[j][4 - i - 1] = tmp[i][j];
    }
}

int main() {
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
            cin >> board[i][j];
    
    cin >> dir;

    if (dir == 'L') {
        gravity();
    }
    else if (dir == 'R') {
        rotate(2);
        gravity();  
        rotate(2);
    }
    else if (dir == 'U') {
        rotate(3);
        gravity();
        
        rotate(1);
    }
    else {  
        rotate(1);
        gravity();
        rotate(3);
    }

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++)
            cout << board[i][j] << ' ';
        cout << endl;
    }
}