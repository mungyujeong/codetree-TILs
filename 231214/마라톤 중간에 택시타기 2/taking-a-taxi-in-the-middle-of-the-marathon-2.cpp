#include <iostream>
#include <climits>

using namespace std;

#define MAX_N 100

int n, curr_x, curr_y;
int min_dist = INT_MAX;
pair<int, int> arr[MAX_N];

int GetDist(int sx, int sy, int dx, int dy) {
    return abs(sx - dx) + abs(sy - dy);
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        arr[i] = make_pair(x, y);
        // cout << arr[i].first << arr[i].second << endl;
    }

    

    for (int i = 1; i < n; i++) {
        int dist = 0;
        curr_x = arr[0].first; 
        curr_y = arr[0].second;
        for (int j = 1; j < n; j++) {
            if (i == j) {
                continue;
            } else {
                dist += GetDist(curr_x, curr_y, arr[j].first, arr[j].second);
                curr_x = arr[j].first;
                curr_y = arr[j].second;
            }
        }
        min_dist = min(min_dist, dist);
    }
    cout << min_dist;
    return 0;
}