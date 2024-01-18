#include <iostream>
#include <algorithm>

using namespace std;

string a, b;

int main() {
    cin >> a;
    cin >> b;
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    if (a.size() != b.size()) cout << "No";
    else {
        for (int i = 0; i < a.size(); i++)
            if (a[i] != b[i]) {
                cout << "No";
                return 0;
            }
        cout << "Yes";
    }

    return 0;
}