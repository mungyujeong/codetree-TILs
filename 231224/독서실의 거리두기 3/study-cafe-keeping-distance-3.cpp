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
            if (dist < v[1] - v[0]) {
                dist = v[1] - v[0];
                s = v[0];
                e = v[1];
                // cout << s << " " << e << endl;
            }
            v.clear();
            v.push_back(v[1]);
            cnt = 1;
        }
    }
    // cout << s << " " << e << " " << dist << endl;
    str[(s + e) / 2] = '1';
    // cout << str << endl;


    v.clear();
    dist = INT_MAX;
    cnt = 0;
    for (int i = 0 ; i < str.length(); i++) {
        if (str[i] == '1') {
            cnt++;
            v.push_back(i);
            // cout << i << endl;
        }
        if (cnt == 2) {
            cnt = 0;
            if (dist > v[1] - v[0]) {
                dist = v[1] - v[0];
                // s = v[0];
                // e = v[1];
                // cout << s << " " << e << endl;
            }
            v.clear();
            v.push_back(v[1]);
            cnt = 1;
        }
    }
    cout << dist;
    return 0;
}