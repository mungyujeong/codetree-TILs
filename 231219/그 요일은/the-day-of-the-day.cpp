#include <iostream>

using namespace std;

int m1, d1, m2, d2;
string A;
string days[7] = {"Mon", "Tue", "Wed", "Thu", "Fri", "Sat", "Sun"};
int num[13] = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int GetDay(int m, int d) {
    int sum = 0;
    for (int i = 1; i < m; i++)
        sum += num[i];
    sum += d;
    return sum;
}

int main() {
    cin >> m1 >> d1 >> m2 >> d2;
    cin >> A;

    int diff = GetDay(m2, d2) - GetDay(m1, d1);
    // cout << diff << endl;

    int count = diff / 7;
    int value;

    for (int i = 0; i < 7; i++) {
        if (days[i] == A) {
            value = i;
            break;
        }
    }
    
    if (diff % 7 == value)
        count++;

    cout << count;

    return 0;
}