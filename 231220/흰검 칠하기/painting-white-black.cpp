#include <iostream>

#define MAX_N 1000
#define OFFSET 10000

using namespace std;

int n;
int x1[MAX_N];
int x2[MAX_N];
int dist[MAX_N];
char command[MAX_N];
bool grey[2 * OFFSET] = {false, };
int black[2 * OFFSET] = {};
int white[2 * OFFSET] = {};
string state[2 * OFFSET] = {};
int curr_x = OFFSET;

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> dist[i] >> command[i];
        dist[i] -= 1;
        if (command[i] == 'L') {
            x1[i] = curr_x - dist[i];
            x2[i] = curr_x;
            curr_x -= dist[i];
        } else {
            x1[i] = curr_x;
            x2[i] = curr_x + dist[i];
            curr_x += dist[i];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = x1[i]; j <= x2[i]; j++) {
            if (state[j] == "grey") continue;

            if (command[i] == 'L') {
                white[j]++;
                state[j] = "white";
            } else {
                black[j]++;
                state[j] = "black";
            }

            if (white[j] >= 2 && black[j] >= 2) {
                state[j] = "grey";
            }
        }
        // for (int i = OFFSET - 20; i < OFFSET + 20; i++) {

        //     cout << state[i] << " ";
        // }
        // cout << endl;
    }    

    int ans_white = 0;
    int ans_black = 0;
    int ans_grey = 0;
    for (int i = 0; i < 2 * OFFSET + 1; i++) {
        if (state[i] == "grey") ans_grey++;
        else if (state[i] == "black") ans_black++;
        else if (state[i] == "white") ans_white++;
    }

    

    cout << ans_white << " " << ans_black << " " << ans_grey; 

    return 0;
}