#include <iostream>

using namespace std;

int m1, d1, m2, d2;
int month, day;
int num_of_days[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int e_day = 1;

int main() {
    cin >> m1 >> d1 >> m2 >> d2;
    month = m1;
    day = d1;

    while (true) {
        if (month == m2 && day == d2) 
            break;
        
        e_day++;
        day++;

        if (num_of_days[month] < day) {
            day = 1;
            month++;
        }
    }

    cout << e_day;
    return 0;
}