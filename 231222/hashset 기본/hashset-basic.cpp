#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

int n;
unordered_set<int> s;
string str;
int num;

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> str >> num;
        if (str == "find") {
            if (s.find(num) == s.end()) cout << "false" << endl;
            else cout << "true" << endl;
        } else if (str == "add") {
            s.insert(num);
        } else if (str == "remove") {
            s.erase(num);
        }
    }
    return 0;
}