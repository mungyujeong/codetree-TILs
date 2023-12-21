#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
vector<long long> v;

bool cmp(long long a, long long b) {
    return to_string(a) + to_string(b) > to_string(b) + to_string(a);
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++){
        long long input;
        cin >> input;
        v.push_back(input);
    }

    sort(v.begin(), v.end(), cmp);
    for (auto i : v)
        cout << i;
    return 0;
}