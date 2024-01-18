#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n;

class Student {
public:
    string name;
    int sub[3];

    Student(string name, int sub[]) {
        this->name = name;
        copy(sub, sub + 3, this->sub);
    }
    Student(){}
};

bool cmp(const Student& a, const Student& b) {
    return a.sub[0] + a.sub[1] + a.sub[2] < b.sub[0] + b.sub[1] + b.sub[2];
}

int main() {
    cin >> n;
    vector<Student> v(n);
    for (int i = 0; i < n; i++) 
        cin >> v[i].name >> v[i].sub[0] >> v[i].sub[1] >> v[i].sub[2];
    sort(v.begin(), v.end(), cmp);
    for (int i = 0; i < n; i++)
        cout << v[i].name << ' ' << v[i].sub[0] << ' ' << v[i].sub[1] << ' ' << v[i].sub[2] << '\n';
    return 0;
}