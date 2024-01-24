#include <iostream>
#include <climits>
#include <string>

using namespace std;

string str;
int answer = INT_MAX;
int n;

void shift() {
    int tmp = str[n - 1];
    for (int i = n - 1; i > 0; i--)
        str[i] = str[i - 1];
    str[0] = tmp;
}

int RLE() {
    string result;
    char tmp = str[0];
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (tmp == str[i]) cnt++;
        else {
            result += tmp;
            result += to_string(cnt);
            tmp = str[i];
            cnt = 1;
        }
    }
    result += tmp;
    result += to_string(cnt);

    return result.length();
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> str;
    n = str.length();
    for (int i = 0; i < n; i++) {
        shift();
        answer = min(answer, RLE());
    }

    cout << answer;
}