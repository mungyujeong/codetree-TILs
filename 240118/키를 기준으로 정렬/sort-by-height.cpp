#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Human {
public:
    string name;
    int height;
    int weight;

    Human(string name, int height, int weight) {
        this->name = name;
        this->height = height;
        this->weight = weight;
    };
    Human(){};
};

int n;

bool cmp(const Human& a, const Human& b) {
    return a.height < b.height;
}

int main() {
    cin >> n;
    vector<Human> v(n);
    for (int i = 0; i < n; i++) 
        cin >> v[i].name >> v[i].height >> v[i].weight;
    
    sort(v.begin(), v.end(), cmp);

    for (int i = 0; i < n; i++)
        cout << v[i].name << ' ' << v[i].height << ' ' << v[i].weight << '\n';
    return 0;
}