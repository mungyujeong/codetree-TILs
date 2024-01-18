#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Human {
public:
    string name;
    int h;
    double w;
    Human(string name, int h, double w) {
        this->name = name;
        this-> h = h;
        this->w = w;
    }
    Human(){}
};

bool cmp_name(const Human& a, const Human& b) {
    return a.name < b.name;
}

bool cmp_h(const Human& a, const Human& b) {
    return a.h > b.h;
}

int main() {
    vector<Human> v(5);
    for (int i = 0; i < 5; i++)
        cin >> v[i].name >> v[i].h >> v[i].w;
    
    cout << "name\n";
    sort(v.begin(), v.end(), cmp_name);
    for (int i = 0; i < 5; i++)
        cout << v[i].name << ' ' << v[i].h << ' ' << v[i].w << '\n';

    cout << "\nheight\n";
    sort(v.begin(), v.end(), cmp_h);
    for (int i = 0; i < 5; i++)
        cout << v[i].name << ' ' << v[i].h << ' ' << v[i].w << '\n';
    return 0;
}