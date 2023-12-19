#include <iostream>

using namespace std;

int m1, m2, d1, d2;
string day[7] = {"Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"};
int num_of_days[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int GetDays(int m, int d) {
    int sum = 0;
    for (int i = 1; i < m; i++) 
        sum += num_of_days[i];
    sum += d;
    return sum;
}

int main() {
    cin >> m1 >> d1 >> m2 >> d2;

    int diff = (GetDays(m2, d2) - GetDays(m1, d1));
    // cout << diff << endl;
    if (diff < 0) cout << day[((diff + 1) % 7 + 7) % 7];
    else cout << day[(diff + 1) % 7];

    return 0;
}