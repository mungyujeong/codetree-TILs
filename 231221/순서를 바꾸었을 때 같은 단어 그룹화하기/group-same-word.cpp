#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>

using namespace std;

int n;
vector<char> v;
vector<string> input;
unordered_map<string, int> m;

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        string str;
        cin >> str;

        input.push_back(str);
        v.clear();
        for (int j = 0; j < str.size(); j++) {
            v.push_back(str[j]);
            // cout << str[j] << " ";
        }
        // cout << endl;

        sort(v.begin(), v.end());

        string tmp;
        for (int j = 0; j < v.size(); j++) {
            tmp += v[j];
        }
        // cout << tmp << endl;
        m[tmp] += 1;
    }

    int answer = 0;
    for (auto i : input) {
        answer = max(answer, m[i]);
    }
    cout << answer;
    return 0;
}