#include <iostream>
#include <climits>

using namespace std;

int a, b, c;
int answer = INT_MIN;

int main() {
    cin >> a >> b >> c;
    
    for (int i = 0; i * a <= c; i++) {
        int sum = i * a;
        int b_num = (c - sum) / b;
        sum += b * b_num;

        answer = max(answer, sum);
    }
    

    cout << answer;
    return 0;
}