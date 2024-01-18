#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Student {
public:
    string name;
    int kor, eng, math;

    Student(int kor, int eng, int math) {
        this->kor = kor;
        this->eng = eng;
        this->math = math;
    }
    Student(){}
};

int n;

bool cmp(const Student& a, const Student& b) {
    if (a.kor != b.kor) return a.kor > b.kor;
    if (a.eng != b.eng) return a.eng > b.eng;
    if (a.math != b.math) return a.math > b.math;
    return true;
}

int main() {
    cin >> n;
    vector<Student> v(n);
    for (int i = 0; i < n; i++) 
        cin >> v[i].name >> v[i].kor >> v[i].eng >> v[i].math;
    
    sort(v.begin(), v.end(), cmp);

    for (int i = 0; i < n; i++) 
        cout << v[i].name << ' ' << v[i].kor << ' ' << v[i].eng << ' ' << v[i].math << '\n';
    return 0;
}