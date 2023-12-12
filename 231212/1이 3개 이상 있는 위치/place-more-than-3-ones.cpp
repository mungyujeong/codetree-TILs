#include <iostream>
#include <vector>

using namespace std;

#define DIR_NUM 4

int n;
int dx[DIR_NUM] = {0, 0, 1, -1};
int dy[DIR_NUM] = {1, -1, 0, 0};
int answer = {0};

int main() {
    cin >> n;
    int arr[101][101] = {0 ,};
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++ ) {
            int a;
            cin >> a;
            arr[i][j] = a;
        }
    }

    for (int x = 0; x < n; x++) {
        
        for (int y = 0; y < n; y++) {
            int count = {0};
            for (int d = 0; d < 4; d++ ) {
                int nx = x + dx[d];
                int ny = y + dy[d];
                if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
                else if (arr[nx][ny] == 1) count++;
            }
            if (count >= 3) {
            answer++;
        }
        }
        
    }
    cout << answer;

    return 0;
}