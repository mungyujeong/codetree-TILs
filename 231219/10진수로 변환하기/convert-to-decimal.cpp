#include <iostream>
#include <string>

using namespace std;

string n;
int num[8] = {};

int main() {
    cin >> n;
    for (int i = 0; i < n.size(); i++)
        num[i] = n[i] - '0';
    
    int sum = 0;
    for (int i = 0; i < n.size(); i++) {
        sum = sum * 2 + num[i];
    }
    cout << sum;
    return 0;
}