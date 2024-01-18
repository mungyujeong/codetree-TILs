#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n;
class Human {
public:
    string name;
    int h, w;
    Human(string name, int h, int w) {
        this->name = name;
        this->h = h;
        this->w = w;
    }
    Human(){}
};

bool cmp(const Human &a , const Human& b) {
    if (a.h == b.h) return a.w > b.w;
    return a.h < b.h;
}

int main() {
    cin >> n;
    vector<Human> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i].name >> v[i].h >> v[i].w;
    sort(v.begin(), v.end(), cmp);    
    for (int i = 0; i < n; i++)
        cout << v[i].name << ' ' << v[i].h << ' ' << v[i].w << '\n';
    return 0;
}