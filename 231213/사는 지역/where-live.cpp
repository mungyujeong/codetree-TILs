#include <iostream>
#include <string>

using namespace std;

#define MAX_N 10

int n;

class Location {
public:
    string name;
    string number;
    string loc;

    Location(string name, string number, string loc) {
        this->name = name;
        this->number = number;
        this->loc = loc;
    }

    Location() {}
};

Location location[MAX_N];

int main() {
    string name;
    string number;
    string loc;
    string slow_name = "";
    int slow_index;

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> name >> number >> loc;
        location[i].name = name;
        location[i].number = number;
        location[i].loc = loc;

        if (slow_name < name) {
            slow_index = i;
            slow_name = name;    
        }
    }

    cout << "name " << location[slow_index].name << endl;
    cout << "addr " << location[slow_index].number << endl;
    cout << "city " << location[slow_index].loc << endl;

    return 0;
}