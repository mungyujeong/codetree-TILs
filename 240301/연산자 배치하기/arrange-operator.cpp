#include <iostream>
#include <vector>
#include <climits>

#define MAX_N 11

using namespace std;

int n, numbers[MAX_N], operators[3], min_val{INT_MAX}, max_val{INT_MIN};
vector<int> v;

int calculate() {
    int result = numbers[0];
    for (int i = 0; i < v.size(); i++) {
        int oper = v[i];
        
        if (oper == 0) result += numbers[i + 1];
        else if (oper == 1) result -= numbers[i + 1];
        else result *= numbers[i + 1];
    }
    return result;
}

void backtracking(int depth) {
    if (depth == n - 1) {
        min_val = min(min_val, calculate());
        max_val = max(max_val, calculate());
        return;
    }

    for (int i = 0; i < 3; i++) {
        if (operators[i] == 0) continue;
        operators[i]--;
        v.push_back(i);
        backtracking(depth + 1);
        v.pop_back();
        operators[i]++;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> numbers[i];
    
    for (int i = 0; i < 3; i++)
        cin >> operators[i];
    
    backtracking(0);

    cout << min_val << ' ' << max_val;

    return 0;
}