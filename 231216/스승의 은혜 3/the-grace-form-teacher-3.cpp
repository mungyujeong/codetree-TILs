#include <iostream>
#include <vector>

#define MAX_N 1000

using namespace std;

int n, b, answer = 0;
int price[MAX_N];
int send[MAX_N];
vector<int> v;

int main() {
    cin >> n >> b;
    for (int i = 0; i < n; i++)
        cin >> price[i] >> send[i];
    
    for (int i = 0; i < n; i++) {

        int count = 0;
        int sum = price[i] / 2 + send[i];
        if (sum > b) continue;
        else count++;
        v.clear();

        for (int j = 0; j < n; j++) {
            if (i == j) continue;

            v.push_back(price[j] + send[j]);
        }

        for (auto i : v) {
            // cout << i << " ";
            if (sum + i > b) break;
            sum += i;
            count++;
        }
        // cout << endl;

        answer = max(answer, count);
    }

    cout << answer;
    return 0;
}