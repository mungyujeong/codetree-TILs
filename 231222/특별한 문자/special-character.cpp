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
    }

    for (int i = 0; i < input.size(); i++) {
        if (m[input[i]] == 1) {
            cout << input[i];
            return 0;
        }
    }
    cout << "None";
    return 0;
}