#include <iostream>

using namespace std;

int a,b,c,d;
int hour, minute;
int e_time = 0;

int main() {
    cin >> a >> b >> c >> d;
    hour = a;
    minute = b;

    while (true) {
        if (hour == c && minute == d)
            break;

        e_time++;
        minute++;

        if (minute == 60) {
            minute = 0;
            hour++;
        }
    }

    cout << e_time;
    return 0;
}