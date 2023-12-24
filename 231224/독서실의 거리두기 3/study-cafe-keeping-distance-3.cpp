#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int n;
string str;
vector<int> v;

int main() {
    cin >> n;
    cin >> str;

    int cnt = 0;
    int dist = 0;
    int s, e;
    for (int i = 0 ; i < str.length(); i++) {
        if (str[i] == '1') {
            cnt++;
            v.push_back(i);
        }
        if (cnt == 2) {
            cnt = 0;
            s = v[0];
            e = v[1];
            dist = max(dist, v[1] - v[0] - 1);
            v.clear();
        }
    }
    // cout << s << " " << e << " " << dist << endl;
    str[(s + e) / 2] = '1';
    dist = INT_MAX;
    for (int i = 0 ; i < str.length(); i++) {
        if (str[i] == '1') {
            cnt++;
            v.push_back(i);
        }
        if (cnt == 2) {
            cnt = 0;
            s = v[0];
            e = v[1];
            dist = min(dist, v[1] - v[0]);
            v.clear();
        }
    }
    cout << dist;
    return 0;
}