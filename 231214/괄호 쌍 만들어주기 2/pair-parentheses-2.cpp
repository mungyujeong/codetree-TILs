#include <iostream>
#include <string>

using namespace std;

string a;
int count;

int main() {
    cin >> a;

    for (int i = 0; i < a.size() - 1; i++) {
        if (a[i] == '(' && a[i + 1] == '(') {
            for (int j = i + 1; j < a.size() - 1; j++) {
                if (a[j] == ')' && a[j + 1] == ')') {
                    count++;
                }
            }
        }
    }
    cout << count;
    return 0;
}