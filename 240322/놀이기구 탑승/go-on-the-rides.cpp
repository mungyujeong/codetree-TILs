#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
#include <cmath>

#define MAX_N 20

using namespace std;

int n, board[MAX_N][MAX_N], favor[401][4];
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

bool InRange(int x, int y) {
    return 0 <= x && x < n && 0 <= y && y < n;
}

tuple<int, int, int, int> FindPosition(int x, int y, int student) {
    int like = 0;
    int empty = 0;

    for (int d = 0; d < 4; d++) {
        int nx = x + dx[d];
        int ny = y + dy[d];
        if (!InRange(nx, ny)) continue;
        if (board[nx][ny] == 0) empty++;
        for (int i = 0; i < 4; i++) {
            if (favor[student][i] == board[nx][ny]) {
                like++;
                break;
            }
        }
    }

    return make_tuple(like, empty, x, y);
}

bool cmp(tuple<int, int, int, int> a, tuple<int, int, int, int> b) {
    int al, ae, ax, ay, bl, be, bx, by;
    tie(al, ae, ax, ay) = a;
    tie(bl, be, bx, by) = b;

    if (al == bl) {
        if (ae == be) {
            if (ax == bx) return ay < by;
            else return ax < bx;
        }
        else return ae > be;
    }
    else return al > bl;
}

void Simulate(int student) {
    vector<tuple<int, int, int, int>> v;

    for (int i = 0; i < n; i++) 
        for (int j = 0; j < n; j++) {
            if (board[i][j]) continue;
            v.push_back(FindPosition(i, j, student));
        }

    sort(v.begin(), v.end(), cmp);
    
    int x, y;
    tie(ignore, ignore, x, y) = v[0];
    board[x][y] = student;
}

int Calc() {
    int result = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int cnt = 0;
            int student = board[i][j];
            for (int d = 0; d < 4; d++) {
                int nx = i + dx[d];
                int ny = j + dy[d];
                if (!InRange(nx, ny)) continue;
                for (int k = 0; k < 4; k++)
                    if (favor[student][k] == board[nx][ny]) 
                        cnt++;
            }
            
            if (cnt != 0) result += pow(10, cnt - 1);
        }
    }

    return result;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n * n; i++) {
        int student;
        cin >> student;

        for (int j = 0; j < 4; j++)
            cin >> favor[student][j];
        
        Simulate(student);
    }

    cout << Calc();

    return 0;
}