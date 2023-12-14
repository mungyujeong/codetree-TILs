#include <iostream>
#include <string>
#include <cmath>

using namespace std;

string a;
int max_num;

int ChangeToNumber(string bin) {
    int result = 0;
    for (int i = 0; i < bin.size() ; i++) {
        result += int(bin[i] - 48) * pow(2, bin.size() - i - 1);
    }
    return result;
}

string BitFlip(string bin, int index) {
    char num = bin[index];
    if (num == '0') {
        bin[index] = '1';
    } else {
        bin[index] = '0';
    }
    return bin;
}

int main() {
    cin >> a;
    for (int i = 0; i < a.size(); i++) {
        string tmp = BitFlip(a, i);
        max_num = max(max_num, ChangeToNumber(tmp));
    }

    cout << max_num;
    return 0;
}