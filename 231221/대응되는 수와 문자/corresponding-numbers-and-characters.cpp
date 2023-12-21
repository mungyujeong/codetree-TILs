#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

int n, m;
unordered_map<string, int> str;
unordered_map<int, string> num;

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        string input;
        cin >> input;
        str[input] = i + 1;
        num[i + 1] = input;
    }

    for (int i = 0; i < m; i++) {
        string a;
        cin >> a;
        // cout << (int)a[0] - '0' << endl;
        if (0 <= (int)a[0] - '0' && (int)a[0] - '0' <= 9) {
            cout << num[stoi(a)] << endl;
        } else {
            cout << str[a] << endl;
        }
    }
    return 0;
}