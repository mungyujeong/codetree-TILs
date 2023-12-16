#include <iostream>
#include <string>

using namespace std;

int x, y, answer;

int GetPalindrome(int num) {
    string str = to_string(num);
    int size = str.size();
    for (int i = 0; i < size / 2; i++) 
        if (str[i] != str[size - i - 1])
            return 0;
    
    return 1;
}

int main() {
    cin >> x >> y;
    for (int i = x; i <= y; i++) {
        answer += GetPalindrome(i);
    }
    cout << answer;
    return 0;
}