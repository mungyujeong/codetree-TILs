#include <iostream>
#include <unordered_map>

#define MAX_T 10000

using namespace std;

int n;
unordered_map<int, int> m;

int main() {
    cin >> n;
    for (int i = 0; i < n; i ++) {
        int score, limit;
        cin >> score >> limit;
        m[limit] = max(m[limit], score);
    }
    int answer = 0;
    for (auto i : m) {
        // cout << i.first << " " << i.second << endl;
        answer += i.second;
    }

    cout << answer;
    return 0;
}