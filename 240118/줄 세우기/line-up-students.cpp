#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Student {
public:
    int h, w, num;
    Student(int h, int w, int num) {
        this->h = h;
        this->w = w;
        this->num = num;
    }
    Student(){}
};

int n;

bool cmp(const Student& a, const Student& b) {
    if (a.h != b.h) return a.h > b.h;
    if (a.w != b.w) return a.w > b.w;
    return a.num < b.num;
}

int main() {
    cin >> n;
    vector<Student> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i].h >> v[i].w;
        v[i].num = i + 1;
    }
    sort(v.begin(), v.end(), cmp);
    for (int i = 0; i < n; i++)
        cout << v[i].h << ' ' << v[i].w << ' ' << v[i].num << '\n';
    return 0;
}