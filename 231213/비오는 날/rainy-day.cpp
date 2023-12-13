#include <iostream>

using namespace std;

#define MAX_N 100

int n, min_index;

class Data {
public:
    string date;
    string day;
    string weather;

    int year;
    int month;
    int d;

    Data(string date, string day, string weather) {
        this->date = date;
        this->day = day;
        this->weather = weather;
    }

    Data() {}
};

Data data[MAX_N];

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        string date, day, weather;
        cin >> date >> day >> weather;
        data[i] = Data(date, day, weather);
    }
    string min_date = "2100-12-31";

    for (int i = 0; i < n; i++) {
        if (data[i].weather == "Rain") {
            if (data[i].date < min_date) {
                min_index = i;
                min_date = data[i].date;
            }
        }
    }

    cout << data[min_index].date << " " << data[min_index].day << " " << data[min_index].weather;

    return 0;
}