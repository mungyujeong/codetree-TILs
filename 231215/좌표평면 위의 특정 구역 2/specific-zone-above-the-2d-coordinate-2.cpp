#include <iostream>
#include <climits>

#define MAX_N 100

using namespace std;

int n, answer = INT_MAX;
pair<int, int> arr[MAX_N];

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        arr[i] = {x, y};
    }

    for (int i = 0; i < n; i++) {
        int max_x = INT_MIN;
        int max_y = INT_MIN;
        int min_x = INT_MAX;
        int min_y = INT_MAX;
        for (int j = 0; j < n; j++) {
            if (i == j) continue;
            int x = arr[j].first;
            int y = arr[j].second;
            max_x = max(max_x, x);
            min_x = min(min_x, x);
            max_y = max(max_y, y);
            min_y = min(min_y, y);
        }
        int value = (max_x - min_x) * (max_y - min_y);
        answer = min(answer, value);
    }

    cout << answer;
    return 0;
}