#include <iostream>
#include <algorithm>

using namespace std;

string a, b;

int main() {
    cin >> a;
    cin >> b;
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    if (a.compare(b) == 0) cout << "Yes";
    else cout << "No";

    return 0;
}