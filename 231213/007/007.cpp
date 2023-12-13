#include <iostream>
#include <string>

using namespace std;

class Zzs {
    public:
        string code;
        char place;
        int time;
    Zzs(string code, char place, int time) {
        this->code = code;
        this->place = place;
        this->time = time;
    }
};

int main() {
    string code;
    char place;
    int time;

    cin >> code >> place >> time;
    Zzs instance = Zzs(code, place, time);

    cout << "secret code : " << instance.code << endl;
    cout << "meeting point : " << instance.place << endl;
    cout << "time : " << instance.time << endl;

    return 0;
}