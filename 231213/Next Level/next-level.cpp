#include <iostream>
#include <string>

using namespace std;

class User {
public:
    string name;
    int level;
    User (string name = "codetree", int level = 10) {
        this->name = name;
        this->level = level;
    }
};

int main() {
    string name;
    int level;
    User user = User();
    cout << "user " << user.name << " lv " << user.level << endl;

    cin >> name >> level;
    user.name = name; user.level = level;
    cout << "user " << user.name << " lv " << user.level << endl;
    return 0;
}