#include <iostream>
#include <climits>

#define MAX_N 1000

using namespace std;

int n, b, sum = 0;
int price[MAX_N];
int answer = INT_MIN;

int main() {
    cin >> n >> b;
    for (int i = 0; i < n; i++) {
        cin >> price[i];
        sum += price[i];
    }

    for (int i = 0; i < n; i++) {
        int count = price[i] / 2;
        int num = 1;
        for (int j = 0; j < n; j++) {
            if(i == j) continue;
            
            count += price[j];
            num++;
            if (count <= b)
                answer = max(answer, num);
            else {
                num--;
                count -= price[j];
            }
        }
    }
    
    cout << answer;
    return 0;
}