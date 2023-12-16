#include <iostream>
#include <climits>
#include <algorithm>

#define MAX_N 1000

using namespace std;

int n, b;
int price[MAX_N];
int answer = INT_MIN;

int main() {
    cin >> n >> b;
    for (int i = 0; i < n; i++) {
        cin >> price[i];
    }
    sort(price, price + n);

    for (int i = 0; i < n; i++) {
        int sum = price[i] / 2;
        int count = 1;
        for (int j = 0; j < n; j++) {
            if(i == j) continue;
            
            sum += price[j];
            count++;
            if (sum <= b)
                answer = max(answer, count);
            else {
                count--;
                sum -= price[j];
            }
        }
    }
    
    cout << answer;
    return 0;
}