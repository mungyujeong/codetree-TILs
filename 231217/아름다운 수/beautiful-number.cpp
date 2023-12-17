#include <iostream>
#include <string>

using namespace std;

int n, answer = 0;
string num;
string numbers[4] = {"1", "22", "333", "4444"};

void GetBeautiful(string str) {
    if (str.length() == n) {
        answer++;
        return;
    } else if (str.length() > n) {
        return;
    }

    for (int i = 0; i < 4; i++) {
        str += numbers[i];
        GetBeautiful(str);
        str = str.substr(0, str.length() - numbers[i].length());
    }
}

int main() {
    cin >> n;
    GetBeautiful(num);
    // num += numbers[2];
    // num = num.substr(0, num.length() - numbers[2].length());
    // cout << num + "1" << endl;

    cout << answer;
    return 0;
}