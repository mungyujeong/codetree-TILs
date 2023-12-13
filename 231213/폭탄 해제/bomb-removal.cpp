#include <iostream>
#include <string>

using namespace std;

class Bomb {
public:
    string code;
    string color;
    int time;
    
    Bomb(string code, string color, int time) {
        this->code = code;
        this->color = color;
        this->time = time;
    }
};

int main() {
    string code;
    string color;
    int time;
    cin >> code >> color >> time;
    Bomb bomb = Bomb(code, color, time);
    cout << "code : " << bomb.code << endl;
    cout << "color : " << bomb.color << endl;
    cout << "second : " << bomb.time << endl;
    return 0;
}