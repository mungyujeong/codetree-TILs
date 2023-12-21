#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

unordered_map<int, int> m;
int n;

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        string cmd;
        cin >> cmd;

        if (cmd == "add") {
            int key, value;
            cin >> key >> value;
            m[key] = value;
        } else if (cmd == "remove") {
            int key;
            cin >> key;
            m.erase(key);
        } else if (cmd == "find") {
            int key;
            cin >> key;
            if(m.find(key) == m.end()) {
                cout << "None" << endl;
            } else {
                cout << m[key] << endl;
            }
        }
    }
    return 0;
}