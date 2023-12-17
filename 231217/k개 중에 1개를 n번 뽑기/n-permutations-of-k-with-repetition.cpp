#include <iostream>
#include <vector>

using namespace std;

int k, n;
vector<int> v;

void combination(int choose, int iterate) {
    if (iterate == 0){
        for (auto i : v)
            cout << i << " ";
        cout << endl;
        return;
    }
    for (int i = 1; i <= k; i++) {
        v.push_back(i);
        // cout << i << " ";
        combination(i, iterate - 1);
        v.pop_back();
    }

    return;
}

int main() {
    cin >> k >> n;
    combination(1, n);

    return 0;
}