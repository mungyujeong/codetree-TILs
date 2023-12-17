#include <iostream>
#include <string>

using namespace std;

string input[3];
int grid[3][3];
int answer;

int main() {
    for (int i = 0; i < 3; i++)
        cin >> input[i];

    for (int i = 0; i < 3; i++) 
        for (int j = 0; j < 3; j++) 
            grid[i][j] = int(input[i][j] - '0');
    
    for (int i = 1; i <= 9; i++) {
        for (int j = 1; j <= 9; j++) {
            if (i == j) continue;
            
            // 가로
            int i_cnt = 0;
            int j_cnt = 0;
            for (int k = 0; k < 3; k++) {    
                i_cnt = 0;
                j_cnt = 0;
                for (int l = 0; l < 3; l++) {
                    if (grid[k][l] == i) i_cnt++;
                    else if (grid[k][l] == j) j_cnt++;
                }
            }
            if (i_cnt != 0 && j_cnt != 0 && i_cnt + j_cnt == 3) {
                // cout << "가로: " << i << " " << j << endl;
                answer++;
                break;
            }


            
            // 세로
            for (int l = 0; l < 3; l++) {
                i_cnt = 0;
                j_cnt = 0;
                for (int k = 0; k < 3; k++) {
                    if (grid[k][l] == i) i_cnt++;
                    else if (grid[k][l] == j) j_cnt++;
                }
            }
            if (i_cnt != 0 && j_cnt != 0 && i_cnt + j_cnt == 3) {
                // cout << "세로: " << i << " " << j << endl;
                answer++;
                break;
            }

            // 대각선
            i_cnt = 0;
            j_cnt = 0;
            for (int k = 0; k < 3; k++) {
                if (grid[k][k] == i) i_cnt++;
                else if (grid[k][k] == j) j_cnt++;
            }
            if (i_cnt != 0 && j_cnt != 0 && i_cnt + j_cnt == 3) {
                // cout << "대각선: " << i << " " << j << endl;
                answer++;
                break;
            }
        }
    }

    cout << answer;
    return 0;
}