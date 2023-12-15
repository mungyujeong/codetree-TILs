#include <iostream>

#define MAX_NUM 100

using namespace std;

int n, m, answer;
int grid[MAX_NUM][MAX_NUM];
int seq[MAX_NUM];

bool isHappySequence() {
    int count = 1;
    int max_cnt = 1;
    for (int i = 0; i < n - 1; i++) {
        if (seq[i] == seq[i + 1]) count++;
        else {
            count = 1;
        }

        max_cnt = max(max_cnt, count);
    }

    return max_cnt >= m;
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) 
        for (int j = 0; j < n; j++)
            cin >> grid[i][j];
    
    for (int row = 0; row < n; row++) {
        for (int col = 0; col < n; col++) {
            seq[col] = grid[row][col];
        }

        if (isHappySequence())
            answer++;
    }

    for (int col = 0; col < n; col++) {
        for (int row = 0; row < n; row++) {
            seq[row] = grid[row][col];
        }

        if (isHappySequence())
            answer++;
    }

    cout << answer;
    return 0;
}