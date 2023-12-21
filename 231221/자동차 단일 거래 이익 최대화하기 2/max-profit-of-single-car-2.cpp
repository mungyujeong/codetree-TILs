#include <iostream>
#include <vector>

using namespace std;

int answer = 0;
vector<int> v;

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        v.push_back(x);
    }

    int buy = v[0];
    for (int i = 1; i < v.size(); i++) {
        if (buy < v[i])
            answer = max(answer, v[i] - buy);
        else {
            buy = v[i];
        }
    }
    cout << answer;
    return 0;
}