#include <iostream>

using namespace std;

int a, b, c;

int main() {
    cin >> a >> b >> c;

    int e_time = 0;
    int day = 11;
    int hour = 11;
    int minute = 11;

    if (a < 11)
        cout << -1;
    else if (a == 11 && b < 11)
        cout << -1;
    else if (a == 11 && b == 11 && c < 11)
        cout << -1;
    else {
        while(true) {
            if (day == a && hour == b && minute == c) 
                break;
            
            e_time++;
            minute++;
            if (minute == 60) {
                minute = 0;
                hour++;
            }
            if (hour == 24) {
                hour = 0;
                day++;
            }
        }

        cout << e_time;
    }
    return 0;
}