#include <iostream>

using namespace std;

int x, y, answer = 0;

int GetInterestingNum(int num) {
    int count[10] = {0};
    int allCnt = 0;

    while(num) {
        count[num % 10]++;
        allCnt++;
        num /= 10;
    }

    for (int i = 0; i < 10; i++) 
        if (count[i] == allCnt - 1)
            return 1;
    return 0;
}

int main() {
    cin >> x >> y;

    for (int i = x; i <= y; i++) 
        answer += GetInterestingNum(i);
        
    cout << answer;
    return 0;
}