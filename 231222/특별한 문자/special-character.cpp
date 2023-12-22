#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;

string input;
unordered_map<char, int> m;
vector<char> v;

int main() {
    cin >> input;
    for (int i = 0; i < input.size(); i++) {
        m[input[i]]++;
        v.push_back(input[i]);
    }
    sort(v.begin(), v.end());

    bool isAnswer = false;
    for (auto i : v) {
        if (m[i] == 1) {
            isAnswer = true;
            cout << i;
            break;
        }
    }
    if (!isAnswer) cout << "None";
    return 0;
}