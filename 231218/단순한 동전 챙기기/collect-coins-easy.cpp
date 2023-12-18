#include <iostream>
#include <string>
#include <vector>
#include <tuple>
#include <climits>

using namespace std;

int n, start_x, start_y, end_x, end_y;
string input;
pair<int, int> coord[10] = {{-1, -1}, {-1, -1},{-1, -1},{-1, -1},{-1, -1},{-1, -1}, {-1, -1},{-1, -1},{-1, -1},{-1, -1},};
int answer = INT_MAX;
vector<int> v;

int Calc() {
    // for (int i = 0; i < 3; i++) {
    //     cout << v[i] << " ";
    // }
    // cout << endl;

    int x, y;
    int dist = 0;
    for (int i = 0; i < 3; i++) {
        tie(x, y) = coord[v[i] - 1];
        dist += abs(x - start_x) + abs(y - start_y);
        start_x = x;
        start_y = y;
    }

    dist += abs(start_x - end_x) + abs(start_y - end_y);
    // cout << dist << endl;
    return dist;
}

bool possible() {
    for (auto i : v) 
        if (coord[i - 1].first == -1 && coord[i - 1].second == -1)
            return false;
    
    return true;
}

void FindDistance(int depth, int cnt) {
    if (depth == 10) {
        if (possible() && cnt == 3) 
            answer = min(answer, Calc());
            // cout << v[0] << v[1] << v[2] << endl;
        
        return;
    }

    v.push_back(depth);
    FindDistance(depth + 1, cnt + 1);
    v.pop_back();
    FindDistance(depth + 1, cnt);

    return;
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> input;
        for (int j = 0; j < input.length(); j++) {
            if (input[j] == 'S') {
                start_x = i;
                start_y = j;
            } else if (input[j] == 'E') {
                end_x = i;
                end_y = j;
            } else if (input[j] != '.') {
                coord[input[j] - '1'] = make_pair(i, j);
            }
        }
    }

    // cout << "start, end: " << start_x << ", "  << start_y << " | " << end_x << ", " << end_y << endl;

    FindDistance(1, 0);

    if (answer == INT_MAX) {
        cout << -1;
    } else {
        cout << answer;
    }

    return 0;
}