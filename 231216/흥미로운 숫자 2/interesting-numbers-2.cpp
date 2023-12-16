#include <iostream>
#include <string>

using namespace std;

int x, y;
int count = 0;
int answer = 0;

int GetInterestingNum(int num) {
    int count[10] = {0, };
    int cnt = 0;
    string str = to_string(num);

    for (int i = 0; i < str.size(); i++) 
        count[int(str[i] - '0')]++;

    for (int i = 0; i < 10; i++) {
        if (count[i] == str.size()) return 0;
        if (count[i] > 0) {
            cnt++;
        }
    }

    if (cnt > 2) return 0;
    for (int i = 0; i < 10; i++) {
        if (count[i] == str.size() - 1) 
            return 1;
    }
    return 0;
}

int main() {
    cin >> x >> y;
    for (int i = x; i <= y; i++) {
        answer += GetInterestingNum(i);
    }

    cout << answer;
    return 0;
}