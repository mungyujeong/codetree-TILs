#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>

using namespace std;

int m1, m2, d1, d2;
vector<pair<int, int>> v;
string day[7] = {"Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"};
int num_of_days[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int GetDays(int m, int d) {
    int sum = 0;
    for (int i = 1; i < m; i++) 
        sum += num_of_days[i];
    sum += d;
    return sum;
}

int main() {
    cin >> m1 >> d1 >> m2 >> d2;
    v.push_back({m1, d1});
    v.push_back({m2, d2});
    // sort(v.begin(), v.end());
    // tie(m1, d1) = v[0];
    // tie(m2, d2) = v[1];

    int diff = (GetDays(m2, d2) - GetDays(m1, d1));
    // if (diff < 0) cout << (1 + diff) % 7;
    // else cout << (1 + diff) % 7;

    // cout << (1 + diff) % 7;
    cout << day[(1 + diff) % 7];
    return 0;
}