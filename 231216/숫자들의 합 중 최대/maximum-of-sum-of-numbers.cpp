#include <iostream>

using namespace std;

int x, y, answer = 0;

int DigitSum(int x) {
    if (x < 10)
        return x;
    
    return DigitSum(x / 10) + x % 10;
}

int main() {
    cin >> x >> y;
    for (int i = x; i <= y; i++) 
        answer = max(answer, DigitSum(i));
        
    
    cout << answer;
    return 0;
}