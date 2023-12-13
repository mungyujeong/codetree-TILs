#include <iostream>

using namespace std;

#define MAX_N 100
#define DIR_NUM 4

int n, x, y, dir, dist, cycle, count;
int dx[DIR_NUM] = {0, -1, 0, 1};
int dy[DIR_NUM] = {1, 0, -1, 0};
int arr[MAX_N][MAX_N];

bool InRange(int x, int y){
    return 0 <= x && x < n && 0 <= y && y < n;
}

int main() {
    cin >> n;
    x = y = int(n / 2);
    count = 1;
    dist = 1;

    while(InRange(x, y)) {
        for (int i = 0; i < dist; i++) {
            arr[x][y] = count++;
            x += dx[dir]; y += dy[dir];

            if(!InRange(x, y)) 
                break;
        }
        dir = (dir + 1) % 4;
        if (dir == 0 || dir == 2) 
            dist++;
    }
    

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) 
            cout << arr[i][j] << " ";
        cout << endl;
    }
    return 0;
}