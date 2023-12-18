#include <iostream>
#include <vector>

using namespace std;

int m, n;
vector<int> v;

void PrintCombination() {
    for (auto i : v)
        cout << i << " ";
    cout << endl;
}

void combination(int depth, int cnt) {
    if (depth == n + 1) {
        if (cnt == m) 
            PrintCombination();
        return;
    }

    v.push_back(depth);
    combination(depth + 1, cnt + 1);
    v.pop_back();
    combination(depth + 1, cnt);

  return;
}

int main() {
    cin >> n >> m;
    
    combination(1, 0);

    return 0;
}