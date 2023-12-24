#include <iostream>
#include <unordered_map>

using namespace std;

int n;
unordered_map<char, int> m;

int main() {
    cin >> n;
    m['A'] = 0;
    m['B'] = 0;
    int answer = 0;
    char winner;
    char tmp;
    for (int i = 0; i < n; i++) {
        char c;
        int s;
        cin >> c >> s;
        m[c] += s;

        if (m['A'] > m['B']) {
            winner = 'A';    
        } else if (m['A'] < m['B']) {
            winner = 'B';
        } else {
            winner = 'C';
        }
        if (winner != tmp) {
            answer++;
            tmp = winner;
        }
    }
    cout << answer;
    return 0;
}